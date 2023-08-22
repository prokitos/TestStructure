#pragma once
#include <iostream>
using std::cout;
using std::string;

struct tnode 
{
  int field;           // поле данных
  struct tnode *left;  // левый потомок
  struct tnode *right; // правый потомок
};

class tree
{
    tnode* root;

    public:
    // пустой конструктор
    tree()
    {
        root = NULL;
    }
    ~tree()
    {
        deleteAllNode();
    }
    // проверка на пустоту
    int isEmpty()
    {
        return(root == NULL);
    }
    void insert(int item);  // вставка элемента в дерево

    void standartdisplayBinTree();  
    void standartprintBinTree(tnode*);  

    void firstdisplayBinTree();  
    void firstprintBinTree(tnode*);  

    void lastdisplayBinTree();  
    void lastprintBinTree(tnode*);  

    void deleteAllNode();
    void deleteNode(tnode*);
};