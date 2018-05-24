//
//  BinaryTree.hpp
//  DataStructuresProject
//
//  Created by Wilsher, Ethan on 3/27/18.
//  Copyright © 2018 Wilsher, Ethan. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <assert.h>
#include "Node.hpp"

template <class Type>
class BinaryTree
{
private:
     BinaryTree<Type> * root;
     BinaryTree<Type> * right;
     BinaryTree<Type> * left;
public:
    BinaryTree();
    ~BinaryTree();
    BinaryTree(Type data);
    
    BinaryTree<Type> * getRootNode();
    BinaryTree<Type> * getLeftNode();
    BinaryTree<Type> * getRightNode();
    
    void setRootNode(BinaryTree<Type> * root);
    void setLeftNode(BinaryTree<Type> * left);
    void setRightNode(BinaryTree<Type> * right);
    void destroyTree(BinaryTree<Type> * node);
    };

template <class Type>
BinaryTree<Type> :: BinaryTree() : Node<Type>()
{
    root = nullptr;
    left = nullptr;
    right = nullptr;
    
}

template <class Type>
BinaryTree<Type> :: BinaryTree(Type data) : Node<Type>(data)
{
    root = nullptr;
    left = nullptr;
    right = nullptr;
}

template <class Type>
BinaryTree<Type> :: ~BinaryTree()
{
    destroyTree(this-root);
}

template <class Type>
void BinaryTree<Type> :: destroyTree(BinaryTree<Type> * node)
{
    if(node != nullptr)
    {
        destroyTree(node->getLeftNode());
        destroyTree(node->getRightNode());
        delete node;
    }
}

template <class Type>
BinaryTree<Type> * BinaryTree<Type> :: getRootNode()
{
    return this->root;
}

template <class Type>
BinaryTree<Type> * BinaryTree<Type> :: getRightNode()
{
    return this->right;
}

template <class Type>
BinaryTree<Type> * BinaryTree<Type> :: getLeftNode()
{
    return this->left;
}

template <class Type>
void BinaryTree<Type> :: setRootNode(BinaryTree<Type> * newRoot)
{
    root = newRoot;
}

template <class Type>
void BinaryTree<Type> :: setRightNode(BinaryTree<Type> * right)
{
    this->right = right;
}

template <class Type>
void BinaryTree<Type> :: setLeftNode(BinaryTree<Type> * left)
{
    this->left = left;
}


#endif /* BinaryTree_hpp */
