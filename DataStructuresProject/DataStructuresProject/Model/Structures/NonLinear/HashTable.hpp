//
//  HashTable.hpp
//  DataStructuresProject
//
//  Created by Wilsher, Ethan on 4/27/18.
//  Copyright © 2018 Wilsher, Ethan. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include "HashNode.hpp"

template <class Type>
class Hashtable
{
private:
    HashNode<Type> ** internalStorage;
    long size;
    double loadFactor;
    long getNextPrime();
    bool isPrime(long current);
    void resize();
    long findPosition(HashNode<Type> * insertedNode);
    long capacity;
    long handleCollision(HashNode<Type> * insertedNode, long index);
public:
    
    
    Hashtable();
    ~Hashtable();
    
    void insert(Type data);
    long getSize();
};

template <class Type>
Hashtable<Type> :: Hashtable()
{
    capacity = 101;
    internalStorage = new HashNode<Type>[101];
    size = 0;
    loadFactor = .80;
}

template <class Type>
Hashtable<Type> :: ~Hashtable()
{
    delete [] internalStorage;
}

template <class Type>
bool Hashtable<Type> :: isPrime(long current)
{
    return false;
}

template <class Type>
long Hashtable<Type> :: findPosition(HashNode<Type> * insert)
{
    return -1;
}

template <class Type>
long Hashtable<Type> :: handleCollision(HashNode<Type> *, long index)
{
    return -1;
}

template <class Type>
long Hashtable<Type> :: getSize()
{
    return -1;
}

template <class Type>
long Hashtable<Type> :: getNextPrime()
{
    return -1;
}

template <class Type>
void Hashtable<Type> :: resize()
{
    
}


#endif /* HashTable_hpp */
