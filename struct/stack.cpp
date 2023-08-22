#include "stack.h"

void stack::push(int item)
{
    stackNode* newElement = new stackNode;
    newElement->data = item;

    if (lastElement != NULL)
    {
        newElement->prev = lastElement;
        
        if(lastElement->data < item)
            newElement->curMin = lastElement->data;
        else
            newElement->curMin = item;
    }
    else
    {
        newElement->prev = NULL;
        newElement->curMin = item;
    }
        
    lastElement = newElement;
    elementCount ++;
};

void stack::isEmpty()
{
    if(lastElement == NULL)
        cout << "stack is empty";
    else
        cout << "stack no empty";
};

int stack::peek()
{
    if(lastElement == NULL)
    {
        cout << "empty stack";
        return 0;
    }
    else
    {
        return lastElement->data;
    }
};

int stack::pop()
{
    int output = {};
    if(lastElement != NULL)
    {
        output = lastElement->data;
        stackNode* temp = lastElement;
        lastElement = lastElement->prev;
        delete temp;
        elementCount --;
    }
    return output;
};

int stack::minimum()
{
    return lastElement->curMin;
};

void stack::popAt(int num)
{
    num ++;
    auto temp = lastElement;
    stackNode* lastIter = lastElement;
    for (size_t i = elementCount; i >= num; i--)
    {
        temp = temp->prev;

        if(i == num)
        {
            lastIter->prev = temp->prev;
            delete temp;
            elementCount --;
        }
        else
        {
            lastIter = temp;
        }
    
    }

};

void stack::showAll()
{
    auto temp = lastElement;
    while(temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->prev;
    }
};