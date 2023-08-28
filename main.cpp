#include <memory>
#include <span>
#include <vector>
#include <any>
#include <algorithm>
#include <cstring>
#include <iostream>
#include "struct/linkList.h"
#include "struct/bTree.h"
#include "struct/hash.h"
#include "struct/stack.h"
#include "struct/queue.h"
#include "struct/graph.h"

#include <chrono>

using std::cout;
using std::string;

void consoleClear()
{

    for (short i = 0; i < 10; i++)
    {
        cout << "\t\n"; 
    }
    
}


void tempHash()
{
    hashMap hash(100);

    hash.insertKey("profi","professional grandmaster");
    hash.insertKey("leo","leo galante, mafia booss");
    hash.insertKey("vito","kotleta vitaliy");
    
    hash.search("leo");
    hash.deleteKey("vito");
    hash.search("vito");
}

void tempStack()
{
    //stack deb;
    //deb.push(5);
    //deb.push(6);
    //deb.push(1);
    //deb.push(4);
    //deb.push(2);
    
    //deb.pop();

    //deb.popAt(3);
    //deb.showAll();

    //deb.pop();
    //cout << deb.minimum();
    //deb.pop();

    //cout << deb.peek();

    
    // 3 стека из одного массива
    threeStack* stck = new threeStack(5);

    stck->pushOne(11);
    stck->pushOne(12);
    stck->pushOne(13);
    stck->pushOne(14);

    stck->pushTwo(21);
    stck->pushTwo(22);
    stck->pushTwo(23);
    stck->pushTwo(24);
    stck->pushTwo(25);
    stck->pushTwo(27);

    stck->pushThree(31);
    stck->pushThree(32);
    stck->pushThree(33);
    stck->pushThree(34);
    stck->pushThree(35);
    stck->pushThree(36);

    stck->showAll();


}

void tempQueue()
{
    queue deb;
    deb.add("qwer");
    deb.add("qqqq");
    deb.add("www");
    
    //deb.remove();
    //deb.remove();
    //deb.remove();

    cout << deb.peek();
}

void tempGraph()
{
    auto start = std::chrono::steady_clock::now();
    
    graph gr;
    gr.addNode("A");
    gr.addNode("B");
    gr.addNode("C");
    gr.addNode("D");
    gr.addNode("E");
    gr.addNode("F");

    gr.addBond("A","B");
    gr.addBond("A","F");
    gr.addBond("B","D");
    gr.addBond("D","C");
    gr.addBond("F","E");
    gr.addBond("E","C");

    //gr.deleteBond("E","C");

    
    
    //gr.printGraph();
    cout << std::endl;

    cout << gr.searchWidth("A","E") << std::endl;
    gr.clearVisited();
    cout << gr.searchDepth("A","D") << std::endl;
    gr.clearVisited();
    // можно просто добавить клеарВизитед в конец поиска, и запускать его автоматом

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    cout << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;
    
    // depth = 0.3647
    // width = 0.3053
}

void templList()
{
    //lList deb;

    // deb.insert(1);
    // deb.insert(5);
    // deb.insert(3);
    // deb.insert(3);
    // deb.insert(5);
    // deb.insert(1);

    //deb.deleteLast();
    //deb.deleteFirst();
    //deb.deleteAtMiddle();
    // deb.polyndromCheck();

    // deb.showAll();

    

    // КОЛЬЦЕВОЙ связный список

    lList deb;

    deb.insert(1);
    deb.insert(5);
    deb.insert(8);
    deb.insert(3);
    deb.insert(7);
    deb.insert(5);
    deb.insert(1);
    deb.insert(4);
    deb.insert(2);
    deb.insert(9);
    deb.lastElemCreateBound(3);

    deb.showAll();
    deb.searchCycleStart();

    // 1 5 3 3 7
    //     9   5
    //     2 4 1


}

void tempBtree()
{
    tree btr;

    btr.insert(1);
    btr.insert(7);
    btr.insert(4);
    btr.insert(9);
    btr.insert(14);
    btr.insert(7);
    btr.insert(3);
    btr.insert(7);

    btr.standartdisplayBinTree();

};

int main()
{
    consoleClear();

    //int* q = new int;
    //cout << q << std::endl;
    //int* w = q;
    //cout << w << std::endl;
    //int* k = w;
    //cout << k << std::endl;

    //tempGraph();
    
    
    //tempHash();

    //system("pause");

    //tempStack();
    //templList();
    tempBtree();
        

    return 0;
}

