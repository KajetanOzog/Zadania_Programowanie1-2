//Kajetan Ozog
#include <cstddef>
class FRUIT_CLASS;
class BRANCH_CLASS;
class GARDEN_CLASS;

class TREE_CLASS {
private:

    unsigned int idT;
    unsigned int height;
    unsigned int nrBranches;
    unsigned int nrFruits;
    unsigned int weightSum;
    BRANCH_CLASS* first;
    BRANCH_CLASS* last;
    TREE_CLASS* prev;
    TREE_CLASS* next;
    GARDEN_CLASS* garden;

public:
    TREE_CLASS(GARDEN_CLASS *og, unsigned int x);

    TREE_CLASS();

    TREE_CLASS(TREE_CLASS& other);

    unsigned int getBranchesTotal();

    unsigned int getWeightsTotal();

    unsigned int getFruitsTotal();

    unsigned int getHeight();

    unsigned int getNumber();

    void growthTree();

    void fadeTree();

    ~TREE_CLASS();

    void harvestTree(unsigned int wag);

    void cutTree(unsigned int len);

    GARDEN_CLASS *getGardenPointer();

    BRANCH_CLASS *getBranchPointer(unsigned int p);

    void cloneBranch(BRANCH_CLASS *pointer);

    void setId(unsigned int id);

    TREE_CLASS *getPrev();

    TREE_CLASS *getNext();

    void setPrev(TREE_CLASS *id);

    void setNext(TREE_CLASS *id);

    void setGarden(GARDEN_CLASS *gardenID);

    BRANCH_CLASS * getFirst();

    void reduceWeight(unsigned int x, unsigned int y);

    void reduceNrFruits(unsigned int x);

    void display();
};
