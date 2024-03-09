//Kajetan Ozog
#include <cstddef>
class TREE_CLASS;

class GARDEN_CLASS {
private:
    unsigned int totalTrees;
    unsigned int totalFruits;
    unsigned int totalBranches;
    unsigned int totalWeight;
    TREE_CLASS* first;
    TREE_CLASS* last;

public:
    GARDEN_CLASS();

    ~GARDEN_CLASS();

    unsigned int getTreesTotal();

    unsigned int getBranchesTotal();

    unsigned int getFruitsTotal();

    unsigned int getWeightsTotal();

    void plantTree();

    void extractTree(unsigned int num);

    void growthGarden();

    void fadeGarden();

    void harvestGarden(unsigned int wag);

    TREE_CLASS *getTreePointer(unsigned int num);

    void cloneTree(unsigned int num);

    void reduceWeight(unsigned int x, unsigned int y);

    void reduceNrFruits(unsigned int x, unsigned int y);

    TREE_CLASS * getFirst();

    void reduceBranches(unsigned int x);

    TREE_CLASS *getLast();

    void display();
};