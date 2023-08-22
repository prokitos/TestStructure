#pragma once
#include <iostream>

using std::cout;
using std::string;


struct queNode
{
    string data;
    queNode* next;
};

class queue
{
public:
    queue(){};
    ~queue()
    {
        while(lastElement != NULL && firstElement != NULL)
        {
            queNode* temp = firstElement;
            firstElement = firstElement->next;
            delete temp;
        }
    };

    string remove(); // забрать и удалить первый
    void add(string item); // добавить элемент
    string peek(); // посмотреть первый элемент
    void isEmpty(); // проверка пустая ли очередь

    queNode* lastElement = NULL;
    queNode* firstElement = NULL;
};