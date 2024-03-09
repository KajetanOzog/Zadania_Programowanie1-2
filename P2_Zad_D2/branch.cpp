//Kajetan Ozog
#include <cstdio>
#include "branch.hpp"
#include "fruit.hpp"
#include "tree.hpp"

BRANCH_CLASS::BRANCH_CLASS()
{
    idB = 0;
    length = 0;
    first = NULL;
    last = NULL;
    tree = NULL;
    prev = NULL;
    next = NULL;
    nrFruits = 0;
    weightSum = 0;
}

FRUIT_CLASS* BRANCH_CLASS::getFirst()
{
    return first;
}

BRANCH_CLASS::BRANCH_CLASS( BRANCH_CLASS& other)
{
    idB = other.idB;
    length = other.length;
    tree = other.tree;
    prev = NULL;
    next = NULL;
    first = NULL;
    last = NULL;
    nrFruits = other.nrFruits;
    weightSum = other.weightSum;

    FRUIT_CLASS* temp = other.getFirst();
    while (temp != NULL) {
        FRUIT_CLASS* newFruit = new FRUIT_CLASS(*temp);
        newFruit->setBranchPointer(this);
        //newFruit->setPrev(last);
        if (last == NULL)
        {
            first = newFruit;
            last = newFruit;
            newFruit->setNext(NULL);
            newFruit->setPrev(NULL);
        } else {
            last->setNext(newFruit);
            newFruit->setNext(NULL);
            newFruit->setPrev(last);
            last = newFruit;
        }
        temp = temp->getNext();
    }
}


unsigned int BRANCH_CLASS::getFruitsTotal()
{
    return nrFruits;
}

unsigned int BRANCH_CLASS::getWeightsTotal()
{
    return weightSum;
}

void BRANCH_CLASS::reduceWeight(unsigned int x, unsigned int y)
{
    if(x == 0)
    {
        weightSum--;
        TREE_CLASS* tr = getTreePointer();
        if(tr != NULL)
        {
            tr->reduceWeight(0, 0);
        }
    }
    else if (x == 1)
    {
        weightSum++;
        TREE_CLASS* tr = getTreePointer();
        if(tr != NULL)
        {
            tr->reduceWeight(1, 0);
        }
    }
    else if( x == 2)
    {
        TREE_CLASS* tr = getTreePointer();
        if(tr != NULL)
        {
            tr->reduceWeight(2, y);
        }
        weightSum -= y;
    }
}

unsigned int BRANCH_CLASS::getHeight()
{
    return idB;
}

unsigned int BRANCH_CLASS::getLength()
{
    return length;
}

unsigned int BRANCH_CLASS::getID()
{
    return idB;
}

void BRANCH_CLASS::growthBranch()
{
    length++;
    FRUIT_CLASS* temp = first;
    while(temp != NULL)
    {
        temp->growthFruit();
        temp = temp->getNext();
    }

    if(length % 2 == 0)
    {
        if(first == NULL)
        {
            FRUIT_CLASS* temp2 = new FRUIT_CLASS();
            first = temp2;
            last = temp2;
            temp2->setBranchPointer(this);
            temp2->setId(length);
        }
        else
        {
            FRUIT_CLASS* temp2 = new FRUIT_CLASS();
            temp2->setPrev(last);
            last->setNext(temp2);
            last = temp2;
            temp2->setBranchPointer(this);
            temp2->setId(length);
        }
        TREE_CLASS* tr = getTreePointer();
        if(tr != NULL)
        {
            tr->reduceNrFruits(1);
        }
        nrFruits++;
    }
}

void BRANCH_CLASS::fadeBranch()
{
    if(length > 0)
    {
        length--;
        FRUIT_CLASS* temp = first;
        while(temp != NULL)
        {
            temp->fadeFruit();
            temp = temp->getNext();
        }

        if(length == 0 && first != NULL)
        {
            delete first;
            first = NULL;
            last = NULL;
            TREE_CLASS* tr = getTreePointer();
            if(tr != NULL)
            {
                tr->reduceNrFruits(0);
            }
            nrFruits--;
        }
        else if(first == NULL)
        {
            return;
        }
        else
        {
            if(last->getLength() - 1 == length)
            {
                if(first->getNext() == NULL)
                {
                    delete first;
                    first = NULL;
                    last = NULL;
                    TREE_CLASS* tr = getTreePointer();
                    if(tr != NULL)
                    {
                        tr->reduceNrFruits(0);
                    }
                    nrFruits--;
                }
                else
                {
                    FRUIT_CLASS* ost = last->getPrev();
                    delete last;
                    ost->setNext(NULL);
                    last = ost;
                    TREE_CLASS* tr = getTreePointer();
                    if(tr != NULL)
                    {
                        tr->reduceNrFruits(0);
                    }
                    nrFruits--;
                }
            }
        }
    }
}

void BRANCH_CLASS::harvestBranch(unsigned int wag)
{
    FRUIT_CLASS* temp = first;
    while (temp != NULL)
    {
        if(temp->getWeight() >= wag)
        {
            temp->pluckFruit();
        }
        temp = temp->getNext();
    }
}

void BRANCH_CLASS::cutBranch(unsigned int len)
{
    if(len < length)
    {
        length = len;
        FRUIT_CLASS* temp = last;
        while (temp != NULL && temp->getLength() > length)
        {
            if(first->getNext() == NULL)
            {
                first->pluckFruit();
                delete first;
                first = NULL;
                last = NULL;
                temp = NULL;
                TREE_CLASS* tr = getTreePointer();
                if(tr != NULL)
                {
                    tr->reduceNrFruits(0);
                }
                nrFruits--;
            }
            else
            {
                temp = temp->getPrev();
                last->pluckFruit();
                delete last;
                last = temp;
                temp->setNext(NULL);
                TREE_CLASS* tr = getTreePointer();
                if(tr != NULL)
                {
                    tr->reduceNrFruits(0);
                }
                nrFruits--;
            }
        }
    }
}

FRUIT_CLASS* BRANCH_CLASS::getFruitPointer(unsigned int len)
{
    if(len > length)
    {
        return NULL;
    }
    else
    {
        FRUIT_CLASS* temp = first;
        while (true)
        {
            if(temp->getLength() == len)
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

TREE_CLASS* BRANCH_CLASS::getTreePointer()
{
    return tree;
}

void BRANCH_CLASS::setTreePointer(TREE_CLASS* pointer)
{
    tree = pointer;
}

BRANCH_CLASS* BRANCH_CLASS::getPrev()
{
    return prev;
}

BRANCH_CLASS* BRANCH_CLASS::getNext()
{
    return next;
}

void BRANCH_CLASS::setPrev(BRANCH_CLASS* pointer)
{
    prev = pointer;
}

void BRANCH_CLASS::setNext(BRANCH_CLASS* pointer)
{
    next = pointer;
}

void BRANCH_CLASS::setId(unsigned int id)
{
    idB = id;
}

BRANCH_CLASS::~BRANCH_CLASS()
{
    FRUIT_CLASS* temp = last;
    while (temp != NULL)
    {
        FRUIT_CLASS* temp2 = temp->getPrev();
        delete temp;
        temp = temp2;
    }
    last = NULL;
    first = NULL;
}
void BRANCH_CLASS::display() {
    TREE_CLASS* tree = (*this).getTreePointer();
    FRUIT_CLASS* fruit;
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int quantity = (*this).getFruitsTotal();

    printf("        Branch at the height of %u\n", (*this).getHeight());
    printf("            Length of a Branch: %u\n", (*this).getLength());
    printf("            Number of Fruits: %u\n", quantity);
    printf("            Total Weight: %u\n", (*this).getWeightsTotal());
    printf("            All Fruits:\n");

    while (i < quantity) {
        fruit = (*this).getFruitPointer(j << 1);
        if (fruit != NULL) {
            (*fruit).display();
            i += 1;
        }
        j += 1;
    }
    printf("            Successful Display all of %u Fruits\n", quantity);
}