#include "queue.h"

void queue::add(string item)
{
    queNode* newElement = new queNode;
    newElement->data = item;
    newElement->next = NULL;

    if(firstElement == NULL)
    {
        lastElement = newElement;
        firstElement = newElement;
    }
    else
    {
        lastElement->next = newElement;
        lastElement = newElement;
    }
    
};

void queue::isEmpty()
{
    if(firstElement == NULL)
        cout << "queue is empty";
    else
        cout << "queue no empty";
};

string queue::peek()
{
    if(firstElement == NULL)
    {
        cout << "empty queue";
        return "";
    }
    else
        return firstElement->data;
};

string queue::remove()
{
    string output = "";
    if(firstElement != NULL)
    {
        output = firstElement->data;
        queNode* temp = firstElement;
        firstElement = firstElement->next;
        delete temp;
    }
    return output;
};