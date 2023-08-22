#include "hash.h"

int hashMap::hashFun(string* key)
{
    unsigned int hash = 213;
    unsigned int temp = 0;

    for (short i = 0; i < (*key).length(); i++)
    {
        temp += 3 * (*key)[i] + i + 1;
    }
    
    hash += temp;
    hash = hash % (array->size * 50);
    return hash;

};

void hashMap::insertKey(string key, string value)
{
    int index = hashFun(&key);

    if(array->item[index]->key == "")
    {
        array->item[index]->key = key;
        array->item[index]->value = value;
    }
    else
    {
        // collision

    }

};

void hashMap::deleteKey(string key)
{
    int index = hashFun(&key);
    struct hashNode curNode = *array->item[index];
    array->item[index]->key = "";
};

string hashMap::search(string key)
{
    int index = hashFun(&key);
    struct hashNode bucket = *array->item[index];
    
    if(array->item[index]->key!= "")
    {
        if(bucket.key == key)
        {
            cout << bucket.value << std::endl;
            return bucket.value;
        }
    }
    else
    {
        cout << "no key!?^" << std::endl;
        
    }
    
    return "nothing";
};