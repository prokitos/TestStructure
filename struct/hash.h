#pragma once
#include <iostream>

using std::cout;
using std::string;

const int CAPPACITY = 5000;

struct hashNode
{
    string key;
    string value;
};

struct hashTable
{
    hashNode* item[CAPPACITY];
    int size;
    int elementCount;
};

class hashMap
{
public:
    hashMap(int cap)
    {
        int newCap = CAPPACITY;
        array = new hashTable;
        array->size = newCap;
        array->elementCount = 0;

        for (size_t i = 0; i < array->size; i++)
        {
            array->item[i] = new hashNode;
        }
        
    };
    ~hashMap()
    {
        for (size_t i = 0; i < array->size; i++)
        {
           delete array->item[i];
        }

        delete array;
    };

    int hashFun(string* key);
    void insertKey(string key, string value);
    void deleteKey(string key);
    string search(string key);

private:
    struct hashTable* array;

};