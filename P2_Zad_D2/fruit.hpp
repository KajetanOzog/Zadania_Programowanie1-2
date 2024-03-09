//Kajetan Ozog
#include <cstddef>
class BRANCH_CLASS;

class FRUIT_CLASS {
private:
    unsigned int idF;
    unsigned int weight;
    BRANCH_CLASS* branch;
    FRUIT_CLASS* next;
    FRUIT_CLASS* prev;

public:

    FRUIT_CLASS();

    FRUIT_CLASS(FRUIT_CLASS &other);

    unsigned int getLength();

    unsigned int getWeight();

    void growthFruit();

    void fadeFruit();

    void pluckFruit();

    BRANCH_CLASS *getBranchPointer();

    void setBranchPointer(BRANCH_CLASS* pointer);

    FRUIT_CLASS* getNext();

    void setId(unsigned int id);

    void setNext(FRUIT_CLASS* pointer);

    FRUIT_CLASS *getPrev();

    void setPrev(FRUIT_CLASS *pointer);

    void display();
};