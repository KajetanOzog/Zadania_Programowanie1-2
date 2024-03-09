//Kajetan Ozog
#include <cstddef>
class FRUIT_CLASS;
class TREE_CLASS;

class BRANCH_CLASS{
private:

    unsigned int idB;
    unsigned int length;
    FRUIT_CLASS* first;
    FRUIT_CLASS* last;
    TREE_CLASS* tree;
    BRANCH_CLASS* prev;
    BRANCH_CLASS* next;
    unsigned int nrFruits;
    unsigned int weightSum;

public:

    BRANCH_CLASS();

    BRANCH_CLASS(BRANCH_CLASS& other);

    void growthBranch();

    unsigned int getLength();

    unsigned int getHeight();

    unsigned int getWeightsTotal();

    unsigned int getFruitsTotal();

    void fadeBranch();

    ~BRANCH_CLASS();

    void harvestBranch(unsigned int wag);

    void cutBranch(unsigned int len);

    FRUIT_CLASS *getFruitPointer(unsigned int len);

    TREE_CLASS *getTreePointer();

    void setTreePointer(TREE_CLASS *pointer);

    BRANCH_CLASS *getPrev();

    BRANCH_CLASS *getNext();

    void setPrev(BRANCH_CLASS *pointer);

    void setNext(BRANCH_CLASS *pointer);

    void setId(unsigned int id);

    FRUIT_CLASS *getFirst();

    //void display();

    unsigned int getID();

    void reduceWeight(unsigned int x, unsigned int y);

    void display();
};