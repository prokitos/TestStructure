#include "graph.h"

// Добавление просто узла
void graph::addNode(string nodeName)
{
    graphNode newElement;
    newElement.name = nodeName;
    newElement.destination;
    newElement.visited = false;

    children[nodeName] = newElement;
};

// показать связи графов
void graph::printGraph()
{
    for (auto &element: children)
    {
        if(element.second.destination.empty() == false)
            for (size_t i = 0; i < element.second.destination.size(); i++)
            {
                std::cout << element.second.name << " --> " << element.second.destination.at(i).name;
                std::cout << std::endl;
            }
            
            
    }
    
};

// добавить связи двум нодам
void graph::addBond(string firstBond, string secondBond)
{
    children[firstBond].destination.push_back(children[secondBond]);
};

// поиск в глубину
string graph::searchDepth(string firstNode, string secondNode)
{
    if(searchEnd)
        return output;

    // если нода нашлась
    if(firstNode == secondNode)
    {
        searchEnd = true;
        cout << "есть пусть к данной ноде" << std::endl;
        output = children[firstNode].name;
        return children[firstNode].name;
    }

    // если у данной ноды есть куда идти, и те ноды не пустые, то идем, иначе выходим
    if(children[firstNode].destination.empty() == false && children[firstNode].visited == false)
    {   
        // заходим в первый попавшийся не посещеный путь, а внутри него в следующий
        children[firstNode].visited = true;
        for (size_t i = 0; i < children[firstNode].destination.size(); i++)
        {
            if(children[firstNode].destination.at(i).visited == false)
                searchDepth(children[firstNode].destination.at(i).name,secondNode);
            
            output += children[firstNode].name;
        }
        
    }

return output;
};

// поиск в ширину
string graph::searchWidth(string firstNode, string secondNode)
{
    if(searchEnd)
        return output;

    // если нода нашлась
    if(firstNode == secondNode)
    {
        searchEnd = true;
        cout << "есть пусть к данной ноде" << std::endl;
        output = children[firstNode].name;
        return children[firstNode].name;
    }

    // если у данной ноды есть куда идти, и те ноды не пустые, то идем, иначе выходим
    if(children[firstNode].destination.empty() == false && children[firstNode].visited == false)
    {   
        children[firstNode].visited = true;
        for (size_t i = 0; i < children[firstNode].destination.size(); i++)
        {
            if(children[firstNode].destination.at(i).visited == false)
                searchThisNode(children[firstNode].destination.at(i).name,secondNode);
        }
        for (size_t i = 0; i < children[firstNode].destination.size(); i++)
        {
            if(children[firstNode].destination.at(i).visited == false)
                searchWidth(children[firstNode].destination.at(i).name,secondNode);
            
            output += children[firstNode].name;
        }
    }

return output;
};

// дополнительная функция для широкого поиска, проверяет только текущие ноды
string graph::searchThisNode(string firstNode, string secondNode)
{
    if(searchEnd)
        return output;
        
    // если нода нашлась
    if(firstNode == secondNode)
    {
        searchEnd = true;
        cout << "есть пусть к данной ноде" << std::endl;
        output = children[firstNode].name;
        return children[firstNode].name;
    }

return output;
};

// удалить старые посещения
void graph::clearVisited()
{
    for (auto &element: children)
    {
        std::string temps = element.second.name;
        children[temps].visited = false;
    }

    output = "нет пути к ноде";
    searchEnd = false;

};

// удаление связи
void graph::deleteBond(string firstBond, string secondBond)
{
    for (size_t i = 0; i < children[firstBond].destination.size(); i++)
    {
        if(children[firstBond].destination[i].name == secondBond)
        {
            children[firstBond].destination.erase(children[firstBond].destination.begin() + i);
            break;
        }
    }
};