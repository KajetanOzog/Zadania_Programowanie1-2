//Kajetan Ozog
#include <iostream>
#include <string>

using namespace std;
class PLAYER_CLASS
{
protected:
    unsigned maxHealth;
    unsigned curHealth;
    unsigned attack;
    unsigned agility;
    PLAYER_CLASS* prev;
    PLAYER_CLASS* next;
public:
    string name;
    PLAYER_CLASS()
    {

    }

    PLAYER_CLASS(unsigned int mH, unsigned int cH, unsigned int at, unsigned int ag)
    {
        maxHealth = mH;
        curHealth = cH;
        attack = at;
        agility = ag;
        prev = NULL;
        next = NULL;
    }

    virtual string getName()
    {
        return name;
    }

    friend class CAESAR_CLASS;
    friend class SQUAD_CLASS;

    virtual unsigned getRemainingHealth ()
    {
        return (curHealth * 100 ) / maxHealth;
    }

    virtual unsigned getDamage() =0;

    virtual unsigned getAgility() =0;

    virtual void takeDamage (unsigned dmg) =0;

    virtual void applyWinnerReward()
    {
        attack += 2;
        agility += 2;
    }

    virtual void cure()
    {
        curHealth = maxHealth;
    }

    virtual void printParams ()=0;


private:
    virtual void die()
    {
        curHealth = 0;
    }
};

class CAESAR_CLASS
{
public:
    int number;
    int attacks;

/*    CAESAR_CLASS()
    {
        number = 0;
        attacks = 0;
    }*/

    void judgeDeathOrLife(PLAYER_CLASS* player)
    {
        number++;
        if(number % 3 == 0)
        {
            if(attacks % 2 == 0)
            {
                player->die();
            }
        }
    }
};

class ARENA_CLASS
{
private:
    CAESAR_CLASS cezar;
public:

    ARENA_CLASS(CAESAR_CLASS* cz)
    {
        cezar = *cz;
        //cezar.number = 0;
    }


    void fight(PLAYER_CLASS* first, PLAYER_CLASS* second)
    {
        cezar.attacks = 0;
        if(first->getRemainingHealth() > 0 && second->getRemainingHealth() > 0)
        {
            if(second->getAgility() > first->getAgility())
            {
                PLAYER_CLASS* pom = first;
                first = second;
                second = pom;
            }

            first->printParams();
            second->printParams();

            for(int i = 0; i < 20; i++)
            {
                if(first->getRemainingHealth() >= 10 && second->getRemainingHealth() >= 10)
                {
                    second->takeDamage(first->getDamage());
                    cezar.attacks++;
                    second->printParams();
                    if(second->getRemainingHealth() >= 10)
                    {
                        first->takeDamage(second->getDamage());
                        first->printParams();
                        cezar.attacks++;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
            if(first->getRemainingHealth() > 0)
            {
                cezar.judgeDeathOrLife(first);
                first->printParams();
                if(first->getRemainingHealth() > 0)
                {
                    first->cure();
                    first->applyWinnerReward();
                }
            }

            if(second->getRemainingHealth() > 0)
            {
                cezar.judgeDeathOrLife(second);
                second->printParams();
                if(second->getRemainingHealth() > 0)
                {
                    second->cure();
                    second->applyWinnerReward();
                }
            }

            first->printParams();
            second->printParams();

        }

    }
};

class HUMAN_CLASS: public virtual PLAYER_CLASS
{
private:
    //string id;

public:

    unsigned defence;
    HUMAN_CLASS()
    {

    }

    HUMAN_CLASS(string id_):PLAYER_CLASS(200, 200, 30, 10)
    {
        name = id_;
        defence = 10;
    }

    virtual unsigned getAgility()
    {
        return agility;
    }

    virtual unsigned getDamage()
    {
        return attack;
    }

    virtual void takeDamage (unsigned dmg)
    {
        if(dmg < agility + defence)
        {
            return;
        }
        if(dmg < curHealth + defence + agility)
        {
            curHealth = curHealth + agility + defence - dmg;
            if(getRemainingHealth() <= 0)
            {
                curHealth = 0;
            }
        }
        else
        {
            curHealth = 0;
        }
    }

    virtual void printParams()
    {
        if(this->getRemainingHealth() > 0)
        {
            cout << getName() << ":" << maxHealth  << ":" << curHealth  << ":" << getRemainingHealth() << "%:" << attack  << ":" << agility  << ":" << defence << endl;
        }
        else
        {
            cout << getName() << ":R.I.P." << endl;
        }
    }
};

class BEAST_CLASS: public virtual PLAYER_CLASS
{
private:
    //string id;
public:

    BEAST_CLASS()
    {

    }

    BEAST_CLASS(string id_): PLAYER_CLASS(150,150,40,20)
    {
        name = id_;
    }

    virtual unsigned getAgility()
    {
        return agility;
    }

    virtual unsigned getDamage()
    {
        if(getRemainingHealth() >= 25)
        {
            return attack;
        }
        else
        {
            return (2 * attack);
        }
    }

    virtual void takeDamage (unsigned dmg)
    {
        int a = agility / 2;
        if(dmg < a)
        {
            return;
        }
        if(dmg < curHealth + a)
        {
            curHealth = curHealth + a - dmg;
            if(getRemainingHealth() <= 0)
            {
                curHealth = 0;
            }
        }
        else
        {
            curHealth = 0;
        }
    }

    virtual void printParams()
    {
        if(this->getRemainingHealth() > 0)
        {
            cout << getName() << ":" << maxHealth  << ":" << curHealth  << ":" << getRemainingHealth() << "%:" << getDamage() << ":" << agility  << endl;
        }
        else
        {
            cout << getName() << ":R.I.P." << endl;
        }
    }
};

class BERSERKER_CLASS : public virtual  HUMAN_CLASS, public virtual BEAST_CLASS
{
private:
    string idH;
    string idB;

public:

    BERSERKER_CLASS(string idH_, string idB_):PLAYER_CLASS(200,200,35,5), HUMAN_CLASS(idH_), BEAST_CLASS(idB_)
    {
        idH = idH_;
        idB = idB_;
        defence = 15;
    }

    unsigned getDamage()
    {
        if(getRemainingHealth() >= 25 || getRemainingHealth() == 0)
        {
            name = idH;
            return HUMAN_CLASS::getDamage();
        }
        else
        {
            name = idB;
            return BEAST_CLASS::getDamage();
        }

    }

    void takeDamage(unsigned dmg)
    {
        if(getRemainingHealth() >= 25 || getRemainingHealth() == 0)
        {
            name = idH;
            HUMAN_CLASS::takeDamage(dmg);
        }
        else
        {
            name = idB;
            BEAST_CLASS::takeDamage(dmg);
        }
    }

    void printParams()
    {
        if(getRemainingHealth() >= 25 || getRemainingHealth() == 0)
        {
            name = idH;
            HUMAN_CLASS::printParams();
        }
        else
        {
            name = idB;
            BEAST_CLASS::printParams();
        }
    }

    string getName()
    {
        if(getRemainingHealth() >= 25 || getRemainingHealth() == 0)
        {
            name = idH;
            return HUMAN_CLASS::getName();
        }
        else
        {
            name = idB;
            return BEAST_CLASS::getName();
        }
    }

    unsigned getAgility()
    {
        if(getRemainingHealth() >= 25 || getRemainingHealth() == 0)
        {
            name = idH;
            return HUMAN_CLASS::getAgility();
        }
        else
        {
            name = idB;
            return BEAST_CLASS::getAgility();
        }
    }
};

class SQUAD_CLASS : public PLAYER_CLASS
{
public:

    int num;

    PLAYER_CLASS* first;
    PLAYER_CLASS* last;

    SQUAD_CLASS(string id_) : PLAYER_CLASS(0,0,0,0)
    {
        name = id_;
        first = NULL;
        last = NULL;
        num = 0;
    }
    void addPlayer(PLAYER_CLASS* player)
    {
        if(player->getRemainingHealth() <= 0)
        {
            return;
        }

        if(first == NULL)
        {
            first = player;
            last = player;
            first->prev = NULL;
            first->next = NULL;
            num++;
        }
        else
        {
            PLAYER_CLASS* temp = first;
            while (temp != NULL)
            {
                if(temp == player)
                {
                    return;
                }
                temp = temp->next;
            }
            last->next = player;
            player->prev = last;
            player->next = NULL;
            last = player;
            num++;
        }
    }


    unsigned int getAgility()
    {
        if(num > 0)
        {
            int min = first->getAgility();
            PLAYER_CLASS* temp;
            temp = first;
            while (temp != NULL)
            {
                if(temp->getAgility() < min)
                {
                    min = temp->getAgility();
                }
                temp = temp->next;
            }
            return min;
        }
        else
        {
            return 0;
        }
    }

    unsigned int getDamage()
    {
        int dmg = 0;
        if(num > 0)
        {
            PLAYER_CLASS* temp;
            temp = first;
            while (temp != NULL)
            {
                dmg += temp->getDamage();
                temp = temp->next;
            }
            return dmg;
        }
        else
        {
            return 0;
        }
    }

    void takeDamage(unsigned dmg)
    {
        if(num > 0)
        {

            dmg = dmg / num;

            PLAYER_CLASS* temp;
            temp = first;
            while (temp != NULL)
            {
                temp->takeDamage(dmg);
                if(temp->getRemainingHealth() <= 0)
                {
                    num--;
                    remove(temp);
                }
                temp = temp->next;

            }
            return;
        }
        else
        {
            return;
        }
    }


    unsigned getRemainingHealth()
    {
        if(num > 0)
        {
            unsigned max = first->getRemainingHealth();
            PLAYER_CLASS* temp;
            temp = first;
            while (temp != NULL)
            {
                if(temp->getRemainingHealth() > max)
                {
                    max = temp->getRemainingHealth();
                }
                temp = temp->next;
            }
            return max;
        }
        else
        {
            return 0;
        }
    }


    void applyWinnerReward()
    {
        if(num > 0)
        {
            PLAYER_CLASS* temp;
            temp = first;
            while (temp != NULL)
            {
                temp->applyWinnerReward();
                temp = temp->next;
            }
        }
        else
        {
            return;
        }
    }

    void cure()
    {
        if(num > 0)
        {
            PLAYER_CLASS* temp;
            temp = first;
            while (temp != NULL)
            {
                temp->cure();
                temp = temp->next;
            }
        }
        else
        {
            return;
        }
    }

    void die()
    {
        if(num > 0)
        {
            PLAYER_CLASS* temp;
            temp = first;
            while (temp != NULL)
            {
                temp->die();
                temp = temp->next;
            }
            num = 0;
        }
        else
        {
            return;
        }
    }

    void printParams()
    {
        if(num > 0)
        {
            sort();
            cout << getName() << ":" << num << ":" << getRemainingHealth() << "%:" << getDamage() << ":" << getAgility() << endl;
            PLAYER_CLASS* temp;
            temp = first;
            while (temp != NULL)
            {
                temp->printParams();
                temp = temp->next;
            }
        }
        else
        {
            cout << getName() << ":nemo" << endl;
        }
    }

    void remove(PLAYER_CLASS* pl)
    {
        if( pl == first && pl == last )
        {
            pl = NULL;
            first = NULL;
            last = NULL;
        }
        else if (pl == first)
        {
            first = pl->next;
            first->prev = NULL;
        }
        else if (pl == last)
        {
            last = pl->prev;
            last->next = NULL;
        }
        else
        {
            PLAYER_CLASS* pop;
            PLAYER_CLASS* nas;
            pop = pl->prev;
            nas = pl->next;
            pop->next = nas;
            nas->prev = pop;
        }
    }

    void sort()
    {
        if(num <= 1)
        {
            return;
        }
        else
        {
            for(int i = 0; i < num - 1; i++)
            {
                PLAYER_CLASS* temp = first;
                for(int j = 0; j < num - i - 1; j++)
                {
                    PLAYER_CLASS* frt = temp;
                    PLAYER_CLASS* sec = temp->next;
                    if(compare(temp,sec))
                    {
                        if(temp == first && temp->next == last)
                        {

                            sec->prev = NULL;
                            sec->next = frt;
                            frt->prev = sec;
                            frt->next = NULL;
                            first = sec;
                            last = frt;
                            temp = sec;
                        }
                        else if(temp == first)
                        {
                            PLAYER_CLASS* nast = sec->next;
                            frt->next = sec->next;
                            frt->prev = sec;
                            sec->next = frt;
                            sec->prev = NULL;
                            first = sec;
                            nast->prev = frt;
                            temp = sec;
                        }
                        else if(temp->next == last)
                        {
                            PLAYER_CLASS* pop = frt->prev;
                            sec->prev = pop;
                            sec->next = frt;
                            frt->next = NULL;
                            frt->prev = sec;
                            last = frt;
                            pop->next = sec;
                            temp = sec;
                        }
                        else
                        {
                            PLAYER_CLASS* frt = temp;
                            PLAYER_CLASS* sec = temp->next;
                            PLAYER_CLASS* pop = frt->prev;
                            PLAYER_CLASS* nast = sec->next;
                            sec->prev = frt->prev;
                            frt->next = sec->next;
                            sec->next = frt;
                            frt->prev = sec;
                            nast->prev = frt;
                            pop->next = sec;
                            temp = sec;
                        }
                    }
                    temp = temp->next;
                }
            }
        }
    }

    bool compare(PLAYER_CLASS* frt, PLAYER_CLASS* sec)
    {
        if(sec->getName() < frt->getName())
        {
            return true;
        }

        if(sec->getName() > frt->getName())
        {
            return false;
        }


        if(sec->maxHealth < frt->maxHealth)
        {
            return true;
        }

        if(sec->maxHealth > frt->maxHealth)
        {
            return false;
        }

        if(sec->curHealth < frt->curHealth)
        {
            return true;
        }

        if(sec->curHealth > frt->curHealth)
        {
            return false;
        }

        if(sec->getRemainingHealth() < frt->getRemainingHealth())
        {
            return true;
        }

        if(sec->getRemainingHealth() > frt->getRemainingHealth())
        {
            return false;
        }

        if(sec->getDamage() < frt->getDamage())
        {
            return true;
        }

        if(sec->getDamage() > frt->getDamage())
        {
            return false;
        }

        if(sec->getAgility() < frt->getAgility())
        {
            return true;
        }

        if(sec->getAgility() > frt->getAgility())
        {
            return true;
        }

        return false;
    }

};

