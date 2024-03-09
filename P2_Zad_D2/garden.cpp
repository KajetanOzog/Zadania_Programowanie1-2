//Kajetan Ozog
#include <cstdio>
#include "garden.hpp"
#include "tree.hpp"


GARDEN_CLASS::GARDEN_CLASS()
{
    totalTrees = 0;
    totalFruits = 0;
    totalBranches = 0;
    totalWeight = 0;
    first = NULL;
    last = NULL;
}

TREE_CLASS* GARDEN_CLASS::getFirst()
{
    return first;
}

TREE_CLASS* GARDEN_CLASS::getLast()
{
    return last;
}

unsigned int GARDEN_CLASS::getTreesTotal()
{
    return totalTrees;
}

unsigned int GARDEN_CLASS::getBranchesTotal()
{
    return totalBranches;
}

void GARDEN_CLASS::reduceBranches(unsigned int x)
{
    if(x == 0)
    {
        totalBranches--;
    }
    else if (x == 1)
    {
        totalBranches++;
    }
}

unsigned int GARDEN_CLASS::getFruitsTotal()
{
    return totalFruits;
}

void GARDEN_CLASS::reduceNrFruits(unsigned int x, unsigned int y)
{
    if(x == 0)
    {
        totalFruits--;
    }
    else if (x == 1)
    {
        totalFruits++;
    }
    else if (x == 2)
    {
        totalFruits -= y;
    }
    else if (x == 3)
    {
        totalFruits += y;
    }
}

unsigned int GARDEN_CLASS::getWeightsTotal()
{
    return totalWeight;
}

void GARDEN_CLASS::reduceWeight(unsigned int x, unsigned int y)
{
    if(x == 0)
    {
        totalWeight--;
    }
    else if (x == 1)
    {
        totalWeight++;
    }
    else if(x == 2)
    {
        totalWeight -= y;
    }
    else if(x == 3)
    {
        totalWeight += y;
    }
}


void GARDEN_CLASS::plantTree()
{
    totalTrees++;
    if(first == NULL)
    {
        first = new TREE_CLASS(this, 0);
/*        first->setId(0);
        first->setGarden(this);*/
        first->setNext(NULL);
        first->setPrev(NULL);
        last = first;
        return;
    }
    else
    {
        if(first->getNumber() > 0)
        {
            TREE_CLASS* temp = new TREE_CLASS(this, 0);
/*            temp->setId(0);
            temp->setGarden(this);*/
            temp->setNext(first);
            first->setPrev(temp);
            first = temp;
            return;
        }

        if(last->getNumber() < totalTrees - 1)
        {
            TREE_CLASS* temp = new TREE_CLASS(this, totalTrees -1);
  /*          temp->setId(totalTrees - 1);
            temp->setGarden(this);*/
            last->setNext(temp);
            temp->setNext(NULL);
            temp->setPrev(last);
            last = temp;
            return;
        }
        TREE_CLASS* temp = first->getNext();

        while(temp != NULL)
        {
            if(temp->getNumber() - temp->getPrev()->getNumber() != 1)
            {
                temp = temp->getPrev();
                TREE_CLASS* nowy = new TREE_CLASS(this, temp->getNumber() + 1);
                temp->getNext()->setPrev(nowy);
                nowy->setNext(temp->getNext());
                nowy->setPrev(temp);
                return;
            }
            temp = temp->getNext();
        }
    }
}



void GARDEN_CLASS::extractTree(unsigned int num)
{
    if(first == NULL)
    {
        return;
    }

    if(last->getNumber() <  num )
    {
        return;
    }
    else
    {
        TREE_CLASS* temp = last;
        while (temp != NULL)
        {
            if(temp->getNumber() == num)
            {
                totalTrees--;
                totalWeight -= temp->getWeightsTotal();
                totalFruits -= temp->getFruitsTotal();
                totalBranches -= temp->getBranchesTotal();
                if(temp == first)
                {
                    first = temp->getNext();
                }
                if(temp == last)
                {
                    last = temp->getPrev();
                }
                if(temp->getPrev() != NULL)
                {
                    temp->getPrev()->setNext(temp->getNext());
                }
                if(temp->getNext() != NULL)
                {
                    temp->getNext()->setPrev(temp->getPrev());
                }
                delete temp;
                return;
            }
            temp = temp->getPrev();
        }
    }
}

void GARDEN_CLASS::growthGarden()
{
    TREE_CLASS* temp = first;
    while (temp != NULL)
    {
        temp->growthTree();
        temp = temp->getNext();
    }
}

void GARDEN_CLASS::fadeGarden()
{
    TREE_CLASS* temp = first;
    while (temp != NULL)
    {
        temp->fadeTree();
        temp = temp->getNext();
    }
}

void GARDEN_CLASS::harvestGarden(unsigned int wag)
{
    TREE_CLASS* temp = first;
    while (temp != NULL)
    {
        temp->harvestTree(wag);
        temp = temp->getNext();
    }
}

TREE_CLASS* GARDEN_CLASS::getTreePointer(unsigned int num)
{
    if(num > last->getNumber())
    {
        return NULL;
    }
    if(num < first->getNumber())
    {
        return NULL;
    }
    TREE_CLASS* temp = last;
    while (temp != NULL)
    {
        if(temp->getNumber() == num)
        {
            return temp;
        }
        temp = temp->getPrev();
    }
    return NULL;
}

void GARDEN_CLASS::cloneTree(unsigned int num)
{
    TREE_CLASS* wklejka = getTreePointer(num);
    if(wklejka != NULL)
    {
        totalTrees++;
        if(first == last)
        {
            unsigned int ID = first->getNumber();
            if(ID > 0)
            {

                TREE_CLASS* temp = new TREE_CLASS(*wklejka);
                totalWeight += temp->getWeightsTotal();
                totalBranches += temp->getBranchesTotal();
                totalFruits += temp->getFruitsTotal();
                temp->setId(0);
                temp->setGarden(this);
                temp->setPrev(NULL);
                temp->setNext(first);
                last->setPrev(temp);
                last = first;
                first = temp;
                return;
            }
            else
            {
                TREE_CLASS* temp = new TREE_CLASS(*wklejka);
                totalWeight += temp->getWeightsTotal();
                totalBranches += temp->getBranchesTotal();
                totalFruits += temp->getFruitsTotal();
                temp->setId(1);
                temp->setGarden(this);
                temp->setPrev(first);
                temp->setNext(NULL);
                first->setNext(temp);
                last = temp;
                return;
            }
        }
        else
        {
            TREE_CLASS* temp = first;
            unsigned int prevID = 0;
            while(temp != NULL)
            {
                prevID = temp->getNumber() - prevID;
                if(prevID > 1)
                {
                    TREE_CLASS* poprzedni = temp->getPrev();
                    if(temp == first)
                    {
                        unsigned int noweID = 0;
                        TREE_CLASS* nowy = new TREE_CLASS(*wklejka);
                        totalWeight += nowy->getWeightsTotal();
                        totalBranches += nowy->getBranchesTotal();
                        totalFruits += nowy->getFruitsTotal();
                        nowy->setId(noweID);
                        nowy->setGarden(this);
                        nowy->setPrev(NULL);
                        nowy->setNext(temp);
                        temp->setPrev(nowy);
                        first = nowy;
                        return;
                    }
                    else
                    {
                        unsigned int noweID = poprzedni->getNumber() + 1;
                        TREE_CLASS* nowy = new TREE_CLASS(*wklejka);
                        totalWeight += nowy->getWeightsTotal();
                        totalBranches += nowy->getBranchesTotal();
                        totalFruits += nowy->getFruitsTotal();
                        nowy->setId(noweID);
                        nowy->setGarden(this);
                        nowy->setPrev(poprzedni);
                        nowy->setNext(temp);
                        poprzedni->setNext(nowy);
                        temp->setPrev(nowy);
                        return;

                    }
                }
                temp = temp->getNext();
            }
            unsigned int noweID = last->getNumber() + 1;
            TREE_CLASS* nowy = new TREE_CLASS(*wklejka);
            totalWeight += nowy->getWeightsTotal();
            totalBranches += nowy->getBranchesTotal();
            totalFruits += nowy->getFruitsTotal();
            nowy->setId(noweID);
            nowy->setGarden(this);
            nowy->setPrev(last);
            last->setNext(nowy);
            nowy->setNext(NULL);
            last = nowy;
        }
    }
}


GARDEN_CLASS::~GARDEN_CLASS()
{
    TREE_CLASS* temp = last;
    while (temp != NULL)
    {
        TREE_CLASS* temp2 = temp->getPrev();
        delete temp;
        temp = temp2;
    }
}
void GARDEN_CLASS::display() {
    TREE_CLASS* tree;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int quantity = (*this).getTreesTotal();

    printf("GARDEN:\n");
    printf("    Number of Trees: %u\n", quantity);
    printf("    Number of Branches: %u\n", (*this).getBranchesTotal());
    printf("    Number of Fruits: %u\n", (*this).getFruitsTotal());
    printf("    Total Weight: %u\n", (*this).getWeightsTotal());
    printf("    All Trees:\n");

    while (i < quantity) {
        tree = (*this).getTreePointer(j);
        if (tree != NULL) {
            (*tree).display();
            i += 1;
        }
        j += 1;
    }
    printf("    Successful Display all of %u Trees\n", quantity);
}