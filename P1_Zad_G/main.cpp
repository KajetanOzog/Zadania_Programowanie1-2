//Kajetan Ozog

#include <iostream>

using namespace std;
typedef int OBJECT_TYPE;

typedef unsigned char BYTE;

BYTE SIZE = 8;

struct NODE_STRUCT {
    OBJECT_TYPE* object;
    BYTE use;
    NODE_STRUCT* next;
};

//Kajetan Ozog
NODE_STRUCT* NewNode (void)
{
    NODE_STRUCT* new_node = new NODE_STRUCT;
    new_node->object = new OBJECT_TYPE[SIZE];
    new_node->use = 0;
    new_node->next = NULL;
    return new_node;
}

void DeleteNode (NODE_STRUCT* node)
{
    delete[] node->object;
    delete node;
}

void Clear (NODE_STRUCT** list)
{
    if(*list != NULL)
    {
        NODE_STRUCT* new_list = *list;
        while(new_list->next != NULL)
        {
            NODE_STRUCT* pom = new_list;
            new_list = new_list->next;
            DeleteNode(pom);
        }
        DeleteNode(new_list);
        *list = NULL;
    }
}

void AddFirst (NODE_STRUCT** list, OBJECT_TYPE* object)
{
    if(*list != NULL)
    {
        NODE_STRUCT* first = *list;
        if(first->use < SIZE)
        {
            for (BYTE i = first->use; i > 0; i--)
            {
                *(first->object + i) = *(first->object + i - 1);
            }
            *first->object = *object;
            first->use++;
        }
        else
        {
            NODE_STRUCT* new_node = NewNode();
            new_node->use = 1;
            *(new_node->object) = *object;
            new_node->next = first;
            *list = new_node;
        }
    }
    else
    {
        NODE_STRUCT* new_node = NewNode();
        new_node->use = 1;
        *(new_node->object) = *object;
        new_node->next = NULL;
        *list = new_node;
    }
}

void AddLast (NODE_STRUCT** list, OBJECT_TYPE* object)
{
    if(*list != NULL)
    {
        NODE_STRUCT* first = *list;
        while(first->next != NULL)
        {
            first = first->next;
        }
        if(first->use < SIZE)
        {
            *(first->object + first->use) = *object;
            first->use++;
        }
        else
        {
            NODE_STRUCT* new_node = NewNode();
            new_node->use = 1;
            *(new_node->object) = *(object);
            first->next = new_node;
        }
    }
    else
    {
        NODE_STRUCT* new_node = NewNode();
        new_node->use = 1;
        *(new_node->object) = *object;
        *list = new_node;
    }
}

void RemoveCurrent(NODE_STRUCT** list, NODE_STRUCT* wez, BYTE numer)
{
    if (*list != NULL)
    {
        if (*list != wez)
        {
            NODE_STRUCT* pom = *list;
            while (pom->next != wez)
            {
                pom = pom->next;
            }
            if (wez->use == 1)
            {
                pom->next = wez->next;
                DeleteNode(wez);
            }
            else
            {
                for (BYTE i = numer; i < wez->use - 1; i++)
                {
                    *(wez->object + i) = *(wez->object + i + 1);
                }
                wez->use--;
            }
        }
        else
        {
            if (wez->use == 1)
            {
                NODE_STRUCT* pom = *list;
                *list = (*list)->next;
                DeleteNode(pom);
            }
            else
            {
                for (BYTE i = numer; i < wez->use - 1; i++)
                {
                    *(wez->object + i) = *(wez->object + i + 1);
                }
                wez->use--;
            }
        }
    }
}

void GetFirst (NODE_STRUCT* wez, NODE_STRUCT** list, BYTE* el)
{
    if (wez == NULL)
    {
        *list = NULL;
    }
    else
    {
        *list = wez;
        *el = 0;
    }
}

void RemoveFirst(NODE_STRUCT** list)
{
    if (*list != NULL)
    {
        NODE_STRUCT* pom = *list;
        if (pom->use == 1)
        {
            *list = pom->next;
            DeleteNode(pom);
        }
        else
        {
            for (BYTE i = 0; i < pom->use - 1; i++)
            {
                *(pom->object + i) = *(pom->object + i + 1);
            }
            pom->use--;
        }
    }
}

void GetPrev(NODE_STRUCT* list, NODE_STRUCT* wez1, BYTE nr1, NODE_STRUCT** wez2, BYTE* nr2)
{
    if(list != NULL)
    {
        if(list == wez1)
        {
            if(nr1 == 0)
            {
                *wez2 = NULL;
            }
            else
            {
                *wez2 = wez1;
                *nr2 = nr1 - 1;
            }
        }
        else
        {
            NODE_STRUCT* pom = list;
            while(pom->next != wez1)
            {
                pom = pom->next;
            }
            if(nr1 == 0)
            {
                *wez2 = pom;
                *nr2 = pom->use - 1;
            }
            else
            {
                *wez2 = wez1;
                *nr2 = nr1 - 1;
            }
        }
    }
    else
    {
        *wez2 = NULL;
    }
}

void GetNext (NODE_STRUCT* list, NODE_STRUCT* wez1, BYTE nr1, NODE_STRUCT** wez2, BYTE* nr2)
{
    if(list != NULL)
    {
        if (nr1 == wez1->use - 1)
        {
            NODE_STRUCT* pom = wez1->next;
            if (pom != NULL)
            {
                *wez2 = pom;
                *nr2 = 0;
            }
            else
            {
                *wez2 = NULL;
            }
        }
        else
        {
            *wez2 = wez1;
            *nr2 = nr1 + 1;
        }
    }
    else
    {
        *wez2 = NULL;
    }
}

void Find(NODE_STRUCT* list, OBJECT_TYPE* obj, NODE_STRUCT** wez, BYTE* nr)
{
    NODE_STRUCT* pom = list;
    while (pom != NULL)
    {
        for (BYTE i = 0; i < pom->use; i++)
        {
            if (*(pom->object + i ) == *obj)
            {
                *wez = pom;
                *nr = i;
                return;
            }
        }
        pom = pom->next;
    }
    *wez = NULL;
}

void Compress ( NODE_STRUCT* list )
{
    if (list != NULL)
    {
        NODE_STRUCT* pom = list;
        while (pom->next != NULL)
        {
            if (pom->use < SIZE)
            {
                if (pom->next->use > 1)
                {
                    *(pom->object + pom->use) = *(pom->next->object);
                    pom->use++;
                    pom->next->use--;
                    for (int i = 0; i < pom->next->use; i++)
                    {
                        *(pom->next->object + i) =*(pom->next->object + 1 + i);
                    }
                }
                else
                {
                    *(pom->object + pom->use) = *(pom->next->object);
                    pom->use++;
                    NODE_STRUCT* pom2 = pom->next;
                    pom->next = pom2->next;
                    DeleteNode(pom2);
                }
            }
            else
            {
                pom = pom->next;
            }
        }
    }
}

void GetLast(NODE_STRUCT* list, NODE_STRUCT** wez, BYTE* nr)
{
    if (list != NULL)
    {
        NODE_STRUCT* pom = list;
        while (pom->next != NULL)
        {
            pom = pom->next;
        }
        *nr = pom->use-1;
        *wez = pom;
    }
    else
    {
        *wez = NULL;
    }
}


void RemovePrev(NODE_STRUCT** list, NODE_STRUCT* wez, BYTE numer)
{
    if(list != NULL)
    {
        NODE_STRUCT* prev = NULL;
        BYTE nr2 = 0;
        GetPrev(*list, wez, numer, &prev, &nr2);
        if(prev != NULL)
        {
            if(prev->use == 1)
            {
                if(*list == prev)
                {
                    *list = prev->next;
                    DeleteNode(prev);
                }
                else
                {
                    NODE_STRUCT* pom = *list;
                    while(pom->next != prev)
                    {
                        pom = pom->next;
                    }
                    pom->next = prev->next;
                    DeleteNode(prev);
                }
            }
            else
            {
                for(BYTE i = nr2; i < (prev->use - 1); i++)
                {
                    *(prev->object + i) = *(prev->object + i + 1);
                }
                prev->use--;
            }
        }
    }
}

void RemoveLast(NODE_STRUCT** list)
{
    if (*list != NULL)
    {
        NODE_STRUCT* pom = *list;
        NODE_STRUCT* prev = NULL;
        while (pom->next != NULL)
        {
            prev = pom;
            pom = pom->next;
        }
        pom->use--;
        if (pom->use == 0)
        {
            if (prev != NULL)
            {
                prev->next = NULL;
            }
            else
            {
                *list = NULL;
            }
            DeleteNode(pom);
        }
    }
}

void RemoveNext(NODE_STRUCT* list, NODE_STRUCT* wez, BYTE numer)
{
    if(list != NULL)
    {
        NODE_STRUCT* next = NULL;
        BYTE nr2 = 0;
        GetNext(list, wez, numer, &next, &nr2);
        if(next != NULL)
        {
            if(next->use == 1)
            {
                if(list == next)
                {
                    list = next->next;
                    DeleteNode(next);
                }
                else
                {
                    NODE_STRUCT* pom = list;
                    while(pom->next != next)
                    {
                        pom = pom->next;
                    }
                    pom->next = next->next;
                    DeleteNode(next);
                }
            }
            else
            {
                for(BYTE i = nr2; i < (next->use - 1); i++) {
                    *(next->object + i) = *(next->object + i + 1);
                }
                next->use--;
            }
        }
    }
}

void InsertNext ( NODE_STRUCT* list, NODE_STRUCT* wez, BYTE nr, OBJECT_TYPE* obj)
{
    if(list != NULL && wez != NULL)
    {
        if(nr >= wez->use)
        {
            return;
        }
        if(wez->use == SIZE)
        {
            if(nr == (wez->use - 1))
            {
                AddFirst(&(wez->next),obj);
            }
            if(nr < (wez->use - 1))
            {
                AddFirst(&(wez->next),wez->object + wez->use - 1);
                for(BYTE i = wez->use - 1; i > (nr + 1); i--)
                {
                    *(wez->object + i) = *(wez->object + i - 1);
                }
                *(wez->object + nr + 1) = *obj;
            }
        }
        else
        {
            for(BYTE i = wez->use; i > (nr + 1); i--)
            {
                *(wez->object + i) = *(wez->object + i - 1);
            }
            *(wez->object + 1 + nr) = *obj;
            wez->use++;
        }
    }
}

void InsertPrev( NODE_STRUCT** list, NODE_STRUCT* wez, BYTE nr, OBJECT_TYPE* obj)
{
    if(*list != NULL && wez != NULL)
    {
        if(nr >= wez->use)
        {
            return;
        }
        if(wez->use < SIZE)
        {
            for(BYTE i = wez->use; i > nr; i--)
            {
                *(wez->object + i) = *(wez->object + i -1);
            }
            *(wez->object + nr) = *obj;
            wez->use++;
            return;
        }
        else
        {
            NODE_STRUCT* pom = *list;
            if (pom == wez)
            {
                if(nr == 0)
                {
                    AddFirst(list,obj);
                }
                else
                {
                    AddFirst(list, wez->object);
                    for(BYTE i = 0; i < nr -1; i++)
                    {
                        *(wez->object + i) = *(wez->object + i + 1);
                    }
                    *(wez->object + nr -1) = *obj;
                }
            }
            else
            {
                while (pom->next != wez)
                {
                    pom = pom->next;
                }
                if(nr == 0)
                {
                    InsertNext(*list,pom,pom->use - 1, obj);
                }
                else
                {
                    InsertNext(*list,pom, pom->use -1,wez->object);
                    for(BYTE i = 0; i < (nr-1); i++)
                    {
                        *(wez->object + i) = *(wez->object + i + 1);
                    }
                    *(wez->object + nr - 1) = *obj;
                }
            }
        }
    }
}


void Reverse(NODE_STRUCT* list)
{
    if(list != NULL)
    {
        NODE_STRUCT* pom = list;
        int ilosc = 0;
        while(pom != NULL)
        {
            OBJECT_TYPE obj;
            for (BYTE i = 0; i < pom->use / 2; i++)
            {
                obj = *(pom->object + i);
                *(pom->object + i) = *(pom->object + pom->use - 1 - i);
                *(pom->object + pom->use - i - 1) = obj;
            }
            pom = pom->next;
            ilosc++;
        }

        NODE_STRUCT* first = list;
        NODE_STRUCT* last = list;
        while (last->next != NULL)
        {
            last = last->next;
        }
        for(int i = 0; i < ilosc / 2; i++)
        {
            NODE_STRUCT* pom2;

            pom2->use = first->use;
            pom2->object = first->object;

            first->use = last->use;
            first->object = last->object;

            last->use = pom2->use;
            last->object = pom2->object;

            first = first->next;

            NODE_STRUCT* nowy = list;
            while (nowy->next != last)
            {
                nowy = nowy->next;
            }
            last = nowy;
        }
        Compress(list);
    }
}



