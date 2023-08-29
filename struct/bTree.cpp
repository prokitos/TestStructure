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
    cout << "узел = " << root->field << std::endl;

    cout << "Левая ветка = ";
    firstprintBinTree(root->left);

    cout << std::endl << "Правая ветка = ";
    firstprintBinTree(root->right);
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


// удаление ноды по числу
void tree::deleteNodeNum(int numb)
{
    tnode** temp = new tnode*;
    nodeStartSearch(root, numb, temp);
    tnode* tempers = *temp;

    if(tempers->left != NULL || tempers->right != NULL)
    deleteSpecNode(tempers);

    delete temp;
}

// поиск указателя на число
void tree::nodeStartSearch(tnode* node, int numb, tnode** output)
{
    if(node->field == numb)
    {
        *output = node;
    }

    if(node->left != NULL)
        nodeStartSearch(node->left,numb,output);
    if(node->right != NULL)
        nodeStartSearch(node->right,numb,output);

}

// удаление элемента по указателю
void tree::deleteSpecNode(tnode* curNode)
{

    // просто удаление если нет наследников.
    if(curNode->left == NULL && curNode->right == NULL)
    {
        delete curNode;
        return;
    }

    // находим самый больший элемент. и записываем его родителя
    tnode* temp = curNode;
    tnode* tempOwner;
    while (temp->right != NULL || temp->left != NULL)
    {
        tempOwner = temp;
        if(temp->right != NULL)
        {
            temp = temp->right;
        }
        else if(temp->left != NULL)
        {
            temp = temp->left;
        }
    }


    // для теста по новому алгоритму
    temp = curNode;
    if(temp->right != NULL)
        temp = temp->right;
    
    while (temp->left != NULL)
    {
        tempOwner = temp;
        temp = temp->left;
    }
    
    
    // ставим последний элемент в начало
    curNode->field = temp->field;

    // удаляем последний элемент, и ссылки на него.
    if(tempOwner->left == temp)
        tempOwner->left = NULL;
    else 
        tempOwner->right = NULL;
    delete temp;

    // прогон большого значения вниз.
    tnode* swapper = curNode;
    while (swapper->right != NULL || swapper->left != NULL)
    {
        if(swapper->left != NULL)
        {
            if(swapper->field >= swapper->left->field)
            {
                std::swap(swapper->field,swapper->left->field);
                swapper = swapper->left;
            }
            else if(swapper->right != NULL)
            {
                swapper = swapper->right;
            }
            else
                break;
        }
        else if(swapper->right != NULL)
        {
            if(swapper->field >= swapper->right->field)
            {
                std::swap(swapper->field,swapper->right->field);
                swapper = swapper->right;
            }
            else if(swapper->left != NULL)
            {
                swapper = swapper->left;
            }
            else
                break;
        }
        else 
            break;
    }

}