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




//
//
//      ноВЫЙ стеК
//
//


void threeStack::pushOne(int data)
{
    int pos = massPieceAddCheck(1);
    if(pos >= 0)
    {
        pushAt(pos,data);
    }
};
void threeStack::pushTwo(int data)
{
    int pos = massPieceAddCheck(2);
    if(pos >= 0)
    {
        pushAt(pos,data);
    }
};
void threeStack::pushThree(int data)
{
    int pos = massPieceAddCheck(3);
    if(pos >= 0)
    {
        pushAt(pos,data);
    }
};
void threeStack::pushAt(int pos, int data)
{
    dataMass[pos] = data;
};


void threeStack::popOne()
{

};
void threeStack::popTwo()
{

};
void threeStack::popThree()
{

};
void threeStack::popAt(int pos)
{
    dataMass[pos] = 0;
};


// вывод всех стеков
void threeStack::showAll()
{

    std::cout << "Первый стек: ";
    for (size_t i = 0; i < 10; i++)
    {
        if(pieceOwner[i] == 1)
        {
            int bonusPos = i * pieceWide;
            for (size_t j = 0; j < pieceWide; j++)
            {
                std::cout << dataMass[j + bonusPos] << " ";
            }
        }
    }
    std::cout << std::endl;

    std::cout << "Второй стек: ";
    for (size_t i = 0; i < 10; i++)
    {
        if(pieceOwner[i] == 2)
        {
            int bonusPos = i * pieceWide;
            for (size_t j = 0; j < pieceWide; j++)
            {
                std::cout << dataMass[j + bonusPos] << " ";
            }
        }
    }
    std::cout << std::endl;

    std::cout << "Третий стек: ";
    for (size_t i = 0; i < 10; i++)
    {
        if(pieceOwner[i] == 3)
        {
            int bonusPos = i * pieceWide;
            for (size_t j = 0; j < pieceWide; j++)
            {
                std::cout << dataMass[j + bonusPos] << " ";
            }
        }
    }
    std::cout << std::endl;

};


// можно ли удалять элемент
bool threeStack::deleteAviable(int stackNumber)
{

    return false;
};

// можно ли добавлять элемент
bool threeStack::insertAviable(int stackNumber)
{


    return false;
};

// проверка и выделение областей перед добавлением
int threeStack::massPieceAddCheck(int stackNumber)
{
    // проверка владельцев частей массива, и вывод элемента для записи
    for (size_t i = 0; i < 10; i++)
    {
        // если уже есть область этого стека, и там есть место
        if (pieceOwner[i] == stackNumber && pieceElements[i] < pieceWide)
        {
            int pos = (i * pieceWide) +  pieceElements[i];
            pieceElements[i] ++;
            return pos;
        }
        
        // если нет мест в области = выделение новой
        if(pieceOwner[i] == 0)
        {
            pieceOwner[i] = stackNumber;
            int pos = (i * pieceWide) +  pieceElements[i];
            pieceElements[i] ++;
            return pos;
        }

        if(i == 9)
        {
            std::cout << "массив заполнен!!!, освободите стеки " << std::endl;
        }
    }
    return -1;

};

// проверка и вывод места для удаления
void threeStack::massPieceDelCheck(int stackNumber)
{

};

