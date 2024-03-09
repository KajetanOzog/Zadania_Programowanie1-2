//Kajetan Ozog
#include "fruit.hpp"
#include "branch.hpp"
#include <cstdio>
FRUIT_CLASS::FRUIT_CLASS()
{
    idF = 0;
    weight = 0;
    branch = NULL;
    next = NULL;
    prev = NULL;
}

FRUIT_CLASS::FRUIT_CLASS(FRUIT_CLASS& other) {
    idF = other.idF;
    weight = other.weight;
    branch = other.branch;
    next = NULL;
    prev = NULL;
}

unsigned int FRUIT_CLASS::getLength()
{
    return idF;
}

unsigned int FRUIT_CLASS::getWeight()
{
    return weight;
}

void FRUIT_CLASS::growthFruit()
{
    weight++;
    BRANCH_CLASS* br = getBranchPointer();
    if(br != NULL)
    {
        br->reduceWeight(1,0);
    }
}

void FRUIT_CLASS::fadeFruit()
{
    if(weight > 0)
    {
        weight--;
        BRANCH_CLASS* br = getBranchPointer();
        if(br != NULL)
        {
            br->reduceWeight(0, 0);
        }
    }
}

void FRUIT_CLASS::pluckFruit()
{
    BRANCH_CLASS *br = getBranchPointer();
    if (br != NULL) {
        br->reduceWeight(2,weight);
    }
    weight = 0;
}

BRANCH_CLASS* FRUIT_CLASS::getBranchPointer()
{
    return branch;
}

void FRUIT_CLASS::setBranchPointer(BRANCH_CLASS * pointer)
{
    branch = pointer;
}

FRUIT_CLASS* FRUIT_CLASS::getNext()
{
    return next;
}

FRUIT_CLASS* FRUIT_CLASS::getPrev()
{
    return prev;
}

void FRUIT_CLASS::setId(unsigned int id)
{
    idF = id;
}

void FRUIT_CLASS::setNext(FRUIT_CLASS* pointer)
{
    next = pointer;
}

void FRUIT_CLASS::setPrev(FRUIT_CLASS* pointer)
{
    prev = pointer;
}
void FRUIT_CLASS::display() {
    printf("            Fruit at the length of %u\n", (*this).getLength());
    printf("                Weight: %u\n", (*this).getWeight());
}
