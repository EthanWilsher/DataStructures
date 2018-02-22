//
//  AbstractBase.hpp
//  DataStructuresProject
//
//  Created by Wilsher, Ethan on 2/8/18.
//  Copyright © 2018 Wilsher, Ethan. All rights reserved.
//

#ifndef AbstractBase_hpp
#define AbstractBase_hpp

#include <iostream>
#include <assert.h>
#include "../Nodes/LinearNode.hpp"

template <class Type>
class AbstractBase : public Node<Type>
{
protected:
    int size;
public:
    //Structure
    virtual void add(Type item) = 0;
    virtual void addAtIndex(int index, Type item) = 0;
    virtual Type remove(Type item) = 0;
    virtual Type getFromIndex(int index) = 0;
    //Helper
    virtual int getSize() const = 0;
    virtual LinearNode<Type> * getFront() = 0;
    virtual LinearNode<Type> * getEnd() = 0;
};

#endif /* AbstractBase_hpp */
