#include "linkList.h"

void lList::insert(int d)
{
    lListNode* tmp = new lListNode;
    tmp->field = d;
    tmp->next = NULL;

    if(firstNode == NULL)
    {
        firstNode = tmp;
        lastNode = tmp;
    }
    else
    {
        lastNode->next = tmp;
        lastNode = tmp;
    }
    elementCount ++;

};

void lList::show(lListNode* nod)
{
    if(nod != NULL)
    {
        cout << nod->field << " ";
    }
};

void lList::showAll()
{

    lListNode* temp = firstNode;
    for (size_t i = 0; i < elementCount; i++)
    {
        show(temp);
        temp = temp->next;
    }
    
};

void lList::deleteFirst()
{
    lListNode* temp = firstNode;
    if(temp->next != NULL)
    {
        firstNode = temp->next;
        delete temp;
    }
    else
    {
        firstNode = NULL;
        delete temp;
    }

    if(elementCount > 0)
        elementCount --;
    
};

void lList::deleteLast()
{
    lListNode* temp = firstNode;

    if(lastNode != NULL && firstNode != NULL)
    while (temp->next != lastNode)
    {
        temp = temp->next;
    }
    
    delete lastNode;
    lastNode = temp;
    lastNode->next = NULL;

    if(elementCount > 0)
    elementCount --;
};

// удаление элемента по ссылке
void lList::deletePtr(lListNode* ptrs, lListNode* prev)
{
    prev->next = ptrs->next;
    delete ptrs;
};

// удаление в середине
void lList::deleteAtMiddle()
{
    if(elementCount > 2)
    {
        lListNode* temp = firstNode;
        for (size_t i = 1; i < elementCount / 2; i++)
        {
            temp = temp->next;
        }
        deletePtr(temp->next, temp);
    }
};

void lList::polyndromCheck()
{
    lListNode* temp = firstNode;
    int mass[elementCount] = {};
    bool polyFlag = true;
    int j = 0;

    // нахождение середины массива, с которого начинается проверка
    if(elementCount % 2)
        j = (elementCount / 2);
    else
        j = (elementCount / 2) - 1;

    // перебор всех элементов списка
    for (size_t i = 0; i < elementCount; i++)
    {
        mass[i] = temp->field;

        // начинается проверка на полиндром
        if(i >= elementCount / 2 && polyFlag == true)
        {
            if(mass[j] != mass[i])
                polyFlag = false;
            
            j --;
        }

        temp = temp->next;
    }

    // вывод результата
    if(polyFlag == true)
        std::cout << "! is polyndrom " << std::endl;
    else
        std::cout << "! not polyndrom " << std::endl;
    
};

// добавление ссылки для кольцевого связного списка.
void lList::lastElemCreateBound(int num)
{
    if(num > 0 && num < elementCount)
    {
        lListNode* temp = firstNode;

        for (size_t i = 0; i < num; i++)
        {
            temp = temp->next;
        }
        
        lastNode->next = temp;

    }
};

void lList::searchCycleStart()
{
    if(elementCount > 0)
    {
        lListNode* slow = firstNode;

        for (size_t i = 0; i < elementCount; i++)
        {
            lListNode* fast = slow->next;
            for (size_t j = 0; j < elementCount; j++)
            {
                if(fast == slow)
                {
                    std::cout << std::endl << "Кольцо начинается на значении " << slow->field << " и на позиции " << i;
                    return;
                }
                fast = fast->next;
            }
            slow = slow->next;
        }
        

    }
};