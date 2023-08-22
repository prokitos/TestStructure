#pragma once
#include <iostream>
#include <vector>
#include <map>

using std::cout;
using std::string;

struct graphNode
{
    string name;
    std::vector <graphNode> destination;
    bool visited; // нужен для некоторых видов поиска
};

// графы чтото странное, между ними всегда одинаковое расстояние, дичь
class graph
{
public:
    graph(){};
    ~graph(){};

    void addNode(string nodeName);
    void addBond(string firstBond, string secondBond);
    void deleteBond(string firstBond, string secondBond);
    void printGraph();
    string searchWidth(string firstNode, string secondNode);
    string searchDepth(string firstNode, string secondNode);
    void clearVisited(); // вызывается после поиска, чтобы стереть флаг посещений
    string searchThisNode(string firstNode, string secondNode);

private:
    // мап, чтобы легче было обращаться к узлу по названию
    bool searchEnd = false;
    string output = "нет пути к ноде";
    std::map <string, graphNode> children;
};
