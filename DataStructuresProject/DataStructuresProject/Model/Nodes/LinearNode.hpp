//
//  LinearNode.hpp
//  DataStructuresProject
//
//  Created by Wilsher, Ethan on 2/8/18.
//  Copyright © 2018 Wilsher, Ethan. All rights reserved.
//

#ifndef LinearNode_hpp
#define LinearNode_hpp

#include <iostream>
#include "Node.hpp"

template <class Type>
class LinearNode : public Node<Type>
{
protected:
    LinearNode<Type> * next;
public:
    //Constructors
    LinearNode();
    LinearNode(Type data);
    LinearNode(Type data, LinearNode<Type> * next);
    //Methods
    void setNextNode(LinearNode<Type> * next);
    LinearNode<Type> * getNextNode();
    
};

template<class Type>
LinearNode<Type> :: LinearNode() : Node<Type>()
{
    this->next = nullptr;
}

template <class Type>
LinearNode<Type> :: LinearNode(Type data) : Node<Type>(data)
{
    this->next = nullptr;
}

template <class Type>
LinearNode<Type> :: LinearNode(Type data, LinearNode<Type> * next) : Node<Type>(data)
{
    this->next = next;
}

template <class Type>
void LinearNode<Type> :: setNextNode(LinearNode<Type> * nextNodePointer)
{
    this->next = nextNodePointer;
}

template <class Type>
LinearNode<Type> * LinearNode<Type> :: getNextNode()
{
    return next;
}
#endif /* LinearNode_hpp */
