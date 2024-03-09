//Kajetan Ozog
#include <cstdio>
#include "branch.hpp"
#include "fruit.hpp"
#include "tree.hpp"
#include "garden.hpp"


TREE_CLASS::TREE_CLASS()
{
    idT = 0;
    height = 0;
    nrBranches = 0;
    nrFruits = 0;
    weightSum = 0;
    prev = NULL;
    next = NULL;
    first = NULL;
    last = NULL;
    garden = NULL;
}

TREE_CLASS::TREE_CLASS(GARDEN_CLASS* og, unsigned int x)
{
    idT = x;
    height = 0;
    nrBranches = 0;
    nrFruits = 0;
    weightSum = 0;
    prev = NULL;
    next = NULL;
    first = NULL;
    last = NULL;
    garden = og;
}

void TREE_CLASS::setId(unsigned  int id)
{
    idT = id;
}



unsigned int TREE_CLASS::getBranchesTotal()
{
    return nrBranches;
}

void TREE_CLASS::reduceNrFruits(unsigned int x)
{
    if(x == 0)
    {
        nrFruits--;
        GARDEN_CLASS* gr2 = getGardenPointer();
        if(gr2 != NULL)
        {
            gr2->reduceNrFruits(0,0);
        }
    }
    else if(x == 1)
    {
        nrFruits++;
        GARDEN_CLASS* gr2 = getGardenPointer();
        if(gr2 != NULL)
        {
            gr2->reduceNrFruits(1,0);
        }
    }
}

unsigned int TREE_CLASS::getFruitsTotal()
{
    return nrFruits;
}

unsigned int TREE_CLASS::getWeightsTotal()
{
    return weightSum;
}

void TREE_CLASS::reduceWeight(unsigned int x, unsigned int y)
{
    if(x == 0)
    {
        weightSum--;
        GARDEN_CLASS* gr = getGardenPointer();
        if(gr != NULL)
        {
            gr->reduceWeight(0,0);
        }
    }
    else if(x == 1)
    {
        weightSum++;
        GARDEN_CLASS* gr = getGardenPointer();
        if(gr != NULL)
        {
            gr->reduceWeight(1,0);
        }
    }
    else if(x == 2)
    {
        weightSum -= y;
        GARDEN_CLASS* gr = getGardenPointer();
        if(gr != NULL)
        {
            gr->reduceWeight(2,y);
        }
    }
}

unsigned int TREE_CLASS::getNumber()
{
    return idT;
}

unsigned int TREE_CLASS::getHeight()
{
    return height;
}

void TREE_CLASS::growthTree()
{
    height++;
    BRANCH_CLASS* temp = first;
    while (temp != NULL)
    {
        temp->growthBranch();
        temp = temp->getNext();
    }
    if(height % 3 == 0)
    {
        if(first == NULL)
        {
            BRANCH_CLASS* nowy = new BRANCH_CLASS();
            first = nowy;
            last = nowy;
            nowy->setId(height);
            nowy->setTreePointer(this);
        }
        else
        {

            BRANCH_CLASS* nowy = new BRANCH_CLASS();
            last->setNext(nowy);
            nowy->setPrev(last);
            last = nowy;
            nowy->setId(height);
            nowy->setTreePointer(this);
        }
        GARDEN_CLASS* gr3 = getGardenPointer();
        if(gr3 != NULL)
        {
            gr3->reduceBranches(1);
        }
        nrBranches++;
    }
}

void TREE_CLASS::fadeTree()
{
    if(height > 0)
    {
        height--;
        BRANCH_CLASS* temp = first;
        while (temp != NULL)
        {
            temp->fadeBranch();
            temp = temp->getNext();
        }

        if(height == 0 && first != NULL)
        {
            delete first;
            first = NULL;
            last = NULL;
            GARDEN_CLASS* gr3 = getGardenPointer();
            if(gr3 != NULL)
            {
                gr3->reduceBranches(0);
            }
            nrBranches--;
        }
        else if(first == NULL)
        {
            return;
        }
        else
        {
            if(last->getHeight() - 1 == height)
            {
                if(first->getNext() == NULL)
                {
                    delete first;
                    first = NULL;
                    last = NULL;
                    GARDEN_CLASS* gr3 = getGardenPointer();
                    if(gr3 != NULL)
                    {
                        gr3->reduceBranches(0);
                    }
                    nrBranches--;
                }
                else
                {
                    BRANCH_CLASS* ost = last->getPrev();
                    delete last;
                    ost->setNext(NULL);
                    last = ost;
                    GARDEN_CLASS* gr3 = getGardenPointer();
                    if(gr3 != NULL)
                    {
                        gr3->reduceBranches(0);
                    }
                    nrBranches--;
                }
            }
        }
    }
}

void TREE_CLASS::harvestTree(unsigned int wag)
{
    BRANCH_CLASS* temp = first;
    while (temp != NULL)
    {
        temp->harvestBranch(wag);
        temp = temp->getNext();
    }
}

void TREE_CLASS::cutTree(unsigned int len)
{
    if(len < height)
    {
        height = len;
        BRANCH_CLASS* temp = last;
        while (temp != NULL && temp->getHeight() > height)
        {
            if(first->getNext() == NULL)
            {
                weightSum -= first->getWeightsTotal();
                GARDEN_CLASS* gr = getGardenPointer();
                if(gr != NULL)
                {
                    gr->reduceWeight(0,first->getWeightsTotal());
                }
                nrFruits -= first->getFruitsTotal();
                GARDEN_CLASS* gr2 = getGardenPointer();
                if(gr2 != NULL)
                {
                    gr2->reduceNrFruits(0,first->getFruitsTotal());
                }
                delete first;
                first = NULL;
                last = NULL;
                temp = NULL;
                GARDEN_CLASS* gr3 = getGardenPointer();
                if(gr3 != NULL)
                {
                    gr3->reduceBranches(1);
                }
                nrBranches--;
            }
            else
            {
                weightSum -= temp->getWeightsTotal();
                GARDEN_CLASS* gr = getGardenPointer();
                if(gr != NULL)
                {
                    gr->reduceWeight(0,first->getWeightsTotal());
                }
                nrFruits -= temp->getFruitsTotal();
                GARDEN_CLASS* gr2 = getGardenPointer();
                if(gr2 != NULL)
                {
                    gr2->reduceNrFruits(0,temp->getFruitsTotal());
                }
                temp = last->getPrev();
                temp->setNext(NULL);
                delete last;
                last = temp;
                GARDEN_CLASS* gr3 = getGardenPointer();
                if(gr3 != NULL)
                {
                    gr3->reduceBranches(1);
                }
                nrBranches--;
            }
        }

    }
}

void TREE_CLASS::cloneBranch(BRANCH_CLASS* pointer)
{
    BRANCH_CLASS* temp = first;
    while (temp != NULL)
    {
        if(temp->getLength() == 0)
        {
            nrFruits += pointer->getFruitsTotal();
            GARDEN_CLASS* gr2 = getGardenPointer();
            if(gr2 != NULL)
            {
                gr2->reduceNrFruits(3,pointer->getFruitsTotal());
            }
            weightSum += pointer->getWeightsTotal();
            GARDEN_CLASS* gr = getGardenPointer();
            if(gr != NULL)
            {
                gr->reduceWeight(3,pointer->getWeightsTotal());
            }
            BRANCH_CLASS* tempP = temp->getPrev();
            BRANCH_CLASS* tempN = temp->getNext();
            unsigned int h = temp->getHeight();
            if(temp == first)
            {
                if(temp == last)
                {
                    delete temp;
                    BRANCH_CLASS* nowy = new BRANCH_CLASS(*pointer);
                    first = nowy;
                    last = nowy;
                    nowy->setNext(NULL);
                    nowy->setPrev(NULL);
                    nowy->setTreePointer(this);
                    nowy->setId(h);
                    return;
                }
                else
                {
                    delete temp;
                    BRANCH_CLASS* nowy = new BRANCH_CLASS(*pointer);
                    first = nowy;
                    nowy->setPrev(NULL);
                    nowy->setNext(tempN);
                    nowy->setTreePointer(this);
                    tempN->setPrev(nowy);
                    nowy->setId(h);
                    return;
                }

            }
            else
            {
                if(temp == last)
                {
                    delete temp;
                    BRANCH_CLASS* nowy = new BRANCH_CLASS(*pointer);
                    last = nowy;
                    nowy->setPrev(tempP);
                    nowy->setNext(NULL);
                    nowy->setTreePointer(this);
                    tempP->setNext(nowy);
                    nowy->setId(h);
                    return;
                }
                else
                {
                    delete temp;
                    BRANCH_CLASS* nowy = new BRANCH_CLASS(*pointer);
                    nowy->setTreePointer(this);
                    nowy->setPrev(tempP);
                    nowy->setNext(tempN);
                    tempP->setNext(nowy);
                    tempN->setPrev(nowy);
                    nowy->setId(h);
                    return;
                }
            }
        }
        temp = temp->getNext();
    }
}

GARDEN_CLASS* TREE_CLASS::getGardenPointer()
{
    return garden;
}

BRANCH_CLASS* TREE_CLASS::getBranchPointer(unsigned int len)
{
    if(len > height)
    {
        return NULL;
    }
    else
    {
        BRANCH_CLASS* temp = first;
        while (true)
        {
            if(temp->getID() == len)
            {
                return temp;
            }
            else if(temp->getNext() == NULL)
            {
                return NULL;
            }
            else
            {
                temp = temp->getNext();
            }
        }
    }
}

TREE_CLASS* TREE_CLASS::getPrev()
{
    return prev;
}


TREE_CLASS* TREE_CLASS::getNext()
{
    return next;
}

void TREE_CLASS::setPrev(TREE_CLASS* id)
{
    prev = id;
}

void TREE_CLASS::setNext(TREE_CLASS* id)
{
    next = id;
}

void TREE_CLASS::setGarden(GARDEN_CLASS* gardenID)
{
    garden = gardenID;
}

BRANCH_CLASS* TREE_CLASS::getFirst()
{
    return first;
}

TREE_CLASS::TREE_CLASS(TREE_CLASS& other)
{
/*    if(other.getBranchesTotal() > 0)
    {*/
    idT = 0;
    height = other.height;
    nrBranches = other.nrBranches;
    nrFruits = other.nrFruits;
    weightSum = other.weightSum;
    garden = other.garden;
    prev = NULL;
    next = NULL;
    first = NULL;
    last = NULL;

    BRANCH_CLASS* temp = other.getFirst();
    while (temp != NULL)
    {
        BRANCH_CLASS* newBranch = new BRANCH_CLASS(*temp);
        newBranch->setTreePointer(this);
        //newBranch->setPrev(last);
        if (last == NULL) {
            first = newBranch;
            last = newBranch;
            newBranch->setNext(NULL);
            newBranch->setPrev(NULL);
        } else {
            last->setNext(newBranch);
            newBranch->setPrev(last);
            newBranch->setNext(NULL);
            last = newBranch;
        }
        temp = temp->getNext();
    }
/*    }*/
}


TREE_CLASS::~TREE_CLASS()
{
    BRANCH_CLASS* temp = last;
    while (temp != NULL)
    {
        BRANCH_CLASS* temp2 = temp->getPrev();
        delete temp;
        temp = temp2;
    }
}

void TREE_CLASS::display() {
    GARDEN_CLASS* garden = (*this).getGardenPointer();
    BRANCH_CLASS* branch;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int quantity = (*this).getBranchesTotal();

    printf("    Tree number %u:\n", (*this).getNumber());
    printf("        Height of a Tree: %u\n", (*this).getHeight());
    printf("        Number of Branches: %u\n", quantity);
    printf("        Number of Fruits: %u\n", (*this).getFruitsTotal());
    printf("        Total Weight: %u\n", (*this).getWeightsTotal());
    printf("        All Branches:\n");

    while (i < quantity) {
        branch = (*this).getBranchPointer(3 * j);
        if (branch != NULL) {
            (*branch).display();
            i += 1;
        }
        j += 1;
    }
    printf("        Successful Display all of %u Branches\n", quantity);
}