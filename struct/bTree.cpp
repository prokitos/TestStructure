#include "bTree.h"



void tree::insert(int item)
{
    tnode* element = new tnode;
    tnode* parent;

    element->field = item;
    element->left = NULL;
    element->right = NULL;
    parent = NULL;

    if(isEmpty())
        root = element;
    else
    {
        tnode* tempRoot = root;
        while(tempRoot != NULL)
        {
            parent = tempRoot;
            if(item > tempRoot->field)
                tempRoot = tempRoot->right;
            else
                tempRoot = tempRoot->left;
        }

        if(item > parent->field)
            parent->right = element;
        else
            parent->left = element;
    }
}

void tree::standartdisplayBinTree()
{
    standartprintBinTree(root);
}
void tree::firstdisplayBinTree()
{
    firstprintBinTree(root);
}
void tree::lastdisplayBinTree()
{
    lastprintBinTree(root);
}

void tree::standartprintBinTree(tnode* nodes)
{
    if(nodes != NULL)
    {
        standartprintBinTree(nodes->left);
        cout << "  " << nodes->field;
        standartprintBinTree(nodes->right);
    }
}
void tree::firstprintBinTree(tnode* nodes)
{
    if(nodes != NULL)
    {
        cout << "  " << nodes->field;
        firstprintBinTree(nodes->left);
        firstprintBinTree(nodes->right);
    }
}
void tree::lastprintBinTree(tnode* nodes)
{
    if(nodes != NULL)
    {
        lastprintBinTree(nodes->left);
        lastprintBinTree(nodes->right);
        cout << "  " << nodes->field;
    }
}

void tree::deleteAllNode()
{
    deleteNode(root);
}
void tree::deleteNode(tnode* curNode)
{
    if(curNode->left != NULL)
    {
        deleteNode(curNode->left);
    }
    if(curNode->right != NULL)
    {
        deleteNode(curNode->right);
    }
    delete curNode;
}