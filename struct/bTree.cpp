#include "bTree.h"
#include <iterator>    
#include <sstream>
#include <vector>


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
    std::string result = {};
    standartprintBinTree(root,result);
    printTreeStr(result);
}
void tree::firstdisplayBinTree()
{
    firstprintBinTree(root);
}
void tree::lastdisplayBinTree()
{
    lastprintBinTree(root);
}

void tree::printTreeStr(string input)
{
    // из строки в вектор, для удобства
    std::vector<std::string> output;     
    std::istringstream iss(input);
    std::copy(std::istream_iterator<string>(iss), std::istream_iterator<string>(), std::back_inserter(output));
    
    // перебор и нормальны форматированный вывод
    int iterator = 0;
    int maxIterator = 1;
    for(auto x : output)
    {
        if(iterator == maxIterator)
        {
            maxIterator = maxIterator * 2;
            iterator = 0;
            cout << std::endl;
        }
            cout << x << " ";
        iterator ++;
    }
        
    
}

void tree::standartprintBinTree(tnode* nodes, string& result)
{
    if(nodes != NULL)
    {
        standartprintBinTree(nodes->left, result);
        result += std::to_string(nodes->field) + " ";
        standartprintBinTree(nodes->right, result);
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