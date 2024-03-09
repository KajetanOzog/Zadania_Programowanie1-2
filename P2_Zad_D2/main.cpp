
#include "fruit.hpp"
#include "branch.hpp"
#include "tree.hpp"
#include "garden.hpp"
#include <iostream>

using namespace std;

int main()
{

    {
        GARDEN_CLASS* g = new GARDEN_CLASS();
        g->plantTree();
        g->growthGarden();
        g->growthGarden();
        g->growthGarden();
        g->plantTree();
        g->growthGarden();
        g->growthGarden();
        g->growthGarden();
        g->plantTree();
        g->growthGarden();
        g->growthGarden();
        g->growthGarden();
        g->extractTree(1);
        g->growthGarden();
        g->growthGarden();
        g->growthGarden();
        g->plantTree();
        g->growthGarden();
        g->growthGarden();
        g->growthGarden();
        g->plantTree();
        g->growthGarden();
        g->growthGarden();
        g->growthGarden();
        g->plantTree();
        g->growthGarden();
        g->growthGarden();
        g->growthGarden();
        g->plantTree();
        g->growthGarden();
        g->growthGarden();
        g->growthGarden();
        g->extractTree(1);
        g->growthGarden();
        g->growthGarden();
        g->growthGarden();
        g->plantTree();
        g->growthGarden();
        g->growthGarden();
        g->growthGarden();

        cout << g->getTreesTotal() << endl;
        cout << g->getBranchesTotal() << endl;
        cout << g->getFruitsTotal() << endl;
        cout << g->getWeightsTotal() << endl;

        delete g;
    }

    {
        GARDEN_CLASS garden = GARDEN_CLASS();
        garden.plantTree();
        garden.plantTree();
        garden.plantTree();
        garden.plantTree();
        garden.plantTree();
        garden.plantTree();
        garden.plantTree();
        garden.extractTree(0);
        garden.extractTree(1);
        garden.extractTree(2);
        garden.extractTree(3);
        garden.extractTree(4);
        garden.extractTree(5);
        garden.extractTree(6);
        garden.plantTree();
        garden.plantTree();
        garden.plantTree();
        garden.plantTree();
        garden.plantTree();
        garden.plantTree();
        garden.plantTree();
        garden.extractTree(1);
        garden.extractTree(3);
        garden.extractTree(5);
        garden.plantTree();
        garden.plantTree();
        garden.plantTree();
        garden.extractTree(0);
        garden.extractTree(1);
        garden.extractTree(2);
        garden.extractTree(3);
        garden.extractTree(4);
        garden.extractTree(5);
        garden.extractTree(6);
        garden.extractTree(6);

        garden.plantTree();

        garden.extractTree(0);

        garden.plantTree();

        garden.plantTree();

        garden.extractTree(0);

        garden.plantTree();

        garden.extractTree(1);

        garden.plantTree();

        cout << garden.getTreesTotal() << endl;
    }

    {
        GARDEN_CLASS g = GARDEN_CLASS();

        g.plantTree();
        g.growthGarden();
        g.growthGarden();
        g.growthGarden();
        g.growthGarden();
        g.growthGarden();
        g.growthGarden();
        g.growthGarden();
        g.growthGarden();
        g.growthGarden();

        TREE_CLASS* w0 = g.getTreePointer(0);
        BRANCH_CLASS* a1 = w0->getBranchPointer(6); //3, 6, 9

        w0->cloneBranch(a1);

        a1->growthBranch();
        a1->growthBranch();
        a1->growthBranch();

        BRANCH_CLASS* b1 = w0->getBranchPointer(3);
        BRANCH_CLASS* b2 = w0->getBranchPointer(6);
        BRANCH_CLASS* b3 = w0->getBranchPointer(9);

        w0->cloneBranch(b1); //a1, b1, b2, b3

        BRANCH_CLASS* c1 = w0->getBranchPointer(9); //3, 6, 9

        c1->growthBranch(); //a1, b1, b2, b3, (c1)
        c1->growthBranch();

        g.plantTree();
        TREE_CLASS* x0 = g.getTreePointer(0); //0, 1

        TREE_CLASS* x1 = g.getTreePointer(0); //0, 1
        BRANCH_CLASS* d1 = x1->getBranchPointer(3);

        TREE_CLASS* y0 = g.getTreePointer(1); //0, 1
        y0->cloneBranch(d1); //a, b, c, (d)

        y0->growthTree();
        y0->growthTree();

        y0->cloneBranch(d1); //a, b, c

        w0->growthTree();
        w0->growthTree();
        w0->growthTree();

        w0->cloneBranch(b1);

        w0->growthTree();
        w0->growthTree();
        w0->growthTree();
        w0->growthTree();
        w0->growthTree();
        w0->growthTree();
        w0->growthTree();
        w0->growthTree();
        w0->growthTree();

        w0->cloneBranch(w0->getBranchPointer(18));

        w0->getBranchPointer(9);
        w0->getBranchPointer(6);
        w0->getBranchPointer(9);

        w0->getBranchPointer(12);
    }

    {
        GARDEN_CLASS jebacogrody = GARDEN_CLASS();
        jebacogrody.plantTree();
        jebacogrody.growthGarden();
        jebacogrody.growthGarden();
        jebacogrody.growthGarden();
        jebacogrody.growthGarden();
        jebacogrody.growthGarden();
        jebacogrody.growthGarden();
        jebacogrody.growthGarden();
        jebacogrody.growthGarden();
        jebacogrody.growthGarden();
        TREE_CLASS* kek = jebacogrody.getTreePointer(0);
        BRANCH_CLASS* kek2 = kek->getBranchPointer(3);
        kek->cloneBranch(kek2);
        kek2 = kek->getBranchPointer(6);
        kek->cloneBranch(kek2);
        jebacogrody.plantTree();
        kek = jebacogrody.getTreePointer(1);
        kek2 = kek->getBranchPointer(6);
        kek->cloneBranch(kek2);
        kek->growthTree();
        kek->growthTree();
        kek->cloneBranch(kek2);
        kek->growthTree();
        kek->growthTree();
        kek->growthTree();
        kek->cloneBranch(kek2);
        kek->growthTree();
        kek->growthTree();
        kek->growthTree();
        kek->growthTree();
        kek->growthTree();
        kek->growthTree();
        kek->growthTree();
        kek->growthTree();
        kek->growthTree();
        kek->cloneBranch(kek2);
    }

    {
        TREE_CLASS wood = TREE_CLASS();

        wood.growthTree();
        wood.growthTree();
        wood.growthTree();
        wood.growthTree();
        wood.growthTree();
        wood.growthTree();
        wood.growthTree();
        wood.growthTree();
        wood.growthTree();
        wood.growthTree();
        wood.growthTree();
        wood.growthTree();
        wood.getBranchPointer(6)->fadeBranch();
        wood.getBranchPointer(6)->fadeBranch();
        wood.getBranchPointer(6)->fadeBranch();
        wood.getBranchPointer(6)->fadeBranch();
        wood.getBranchPointer(6)->fadeBranch();
        wood.getBranchPointer(6)->fadeBranch();
        // Display
        BRANCH_CLASS branch = BRANCH_CLASS();
        branch.growthBranch();
        branch.growthBranch();
        branch.growthBranch();
        branch.growthBranch();
        branch.growthBranch();
        branch.growthBranch();
        wood.cloneBranch(wood.getBranchPointer(3));
        wood.cloneBranch(&branch);
    }

    {
        GARDEN_CLASS g;
        g.plantTree();
        g.plantTree();
        g.plantTree();
        g.plantTree();
        g.extractTree(0);
        g.plantTree();
        g.extractTree(0);
        g.plantTree();
        g.plantTree();
        g.extractTree(0);
        g.plantTree();
        g.plantTree();
        g.extractTree(0);
    }

    {
        GARDEN_CLASS g;
        g.plantTree();
        g.growthGarden();
        g.growthGarden();
        g.growthGarden();
        g.plantTree();
        g.growthGarden();
        g.growthGarden();
        g.growthGarden();
        g.cloneTree(0);
        g.extractTree(2);
        g.cloneTree(0);
        g.extractTree(3);
        g.extractTree(4);
        g.growthGarden();
        g.growthGarden();
        g.growthGarden();
        g.cloneTree(0);
        g.cloneTree(0);
        g.cloneTree(0);
        std::cout << g.getTreePointer(0) << endl;
        std::cout << g.getTreePointer(1) << endl;
        std::cout << g.getTreePointer(2) << endl;
    }

    return 0;
}