#pragma once
#include <iostream>

using std::cout;
using std::string;

// лучше потом сделать через темплейт, чтобы был не только стринг
struct stackNode
{
    //string data;
    int data;
    stackNode* prev;
    int curMin; 
};

class stack
{
public:
    stack(){};
    ~stack()
    {
        // delete all node
    };

    int pop(); // забрать и удалить последний элемент
    void push(int item); // закинуть элемент в конец
    int peek(); // посмотреть последний элемент
    void isEmpty(); // проверка пустой ли стек

    int minimum(); // получить минимальное значение в стеке за O(1), не работает в PopAt
    void popAt(int num); // удалить элемент на N позиции, работает долго
    void showAll();  // показать все элементы

protected:
    int elementCount = 0;
    stackNode* lastElement = NULL;
};