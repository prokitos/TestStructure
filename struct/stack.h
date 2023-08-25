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


// использование одного одномерного массива для реализации трех стеков

class threeStack
{
public:
    threeStack(int size)
    {
        // определение размера массива (стеков)
        stackSize = size * 3;
        dataMass = new int[stackSize]{};

        // сколько частей будет в массиве
        massPieces = 4;
        if(stackSize >= 12)
            massPieces = 6;
        if(stackSize >= 50)
            massPieces = 10;

        // если размер массива не делится нацело
        if(stackSize % massPieces == 0)
        {
            isSizeOdd = false;
        }
        else
        {
            isSizeOdd = true;
            pieceCustom = stackSize % massPieces;
            massPieces ++;
        }
            

        // количество элементов в одной части
        pieceWide = stackSize / massPieces;

        // 10 частей в массиве если больше 50 элементов         макс потеря 20%
        // 6 частей в массиве если больше 12 элементов          макс потеря 28%
        // 4 части если меньше 12 элементов..                   макс потеря 30%
        // макс потеря если в двух стеках будет только по одному элементу.

    };

    // вычисление позиций для добавления в стек
    void pushOne(int data);
    void pushTwo(int data);
    void pushThree(int data);

    // вычисление позиций для удаления из стека
    void popOne();
    void popTwo();
    void popThree();

    // удаление и добавление элементов из конкретных позиций
    void popAt(int pos);
    void pushAt(int pos, int data);

    // показать элементы стеков
    void showAll();

    //проверки
    int massPieceAddCheck(int stackNumber);
    void massPieceDelCheck(int stackNumber);
    bool deleteAviable(int stackNumber);
    bool insertAviable(int stackNumber);

private:
    int* dataMass;
    int stackSize = 20;

    int pieceOwner[10] {};
    int pieceElements[10]{};
    int massPieces;
    int pieceWide;

    bool isSizeOdd;
    int pieceCustom = 0;
};