#pragma once
#include <iostream>

using std::cout;
using std::string;

// односвязный список
struct lListNode 
{
    int field;           // поле данных
    struct lListNode* next;  // следующй элемент
};

class lList
{
    lListNode* firstNode;
    lListNode* lastNode;
public:
    lList()
    {
        firstNode = NULL;
        lastNode = NULL;
    };
    ~lList()
    {
        while(firstNode != NULL)
        {
            lListNode* temp = firstNode;
            firstNode = firstNode->next;
            delete temp;
        }
    }
    void insert(int d);
    void show(lListNode* nod);
    void showAll();

    void deleteFirst();
    void deleteLast(); // Долгий, возможны утечки
    void deletePtr(lListNode* ptrs, lListNode* prev); // метод для удаления узла
    void deleteAtMiddle();  // удалить элемент в середине списка
    void polyndromCheck();  // проверка списка на полиндром

private:
    int elementCount = 0;
};

