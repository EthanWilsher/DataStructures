//
//  BinaryTree.hpp
//  DataStructuresProject
//
//  Created by Wilsher, Ethan on 3/27/18.
//  Copyright © 2018 Wilsher, Ethan. All rights reserved.
//

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <assert>
#include "../model/Nodes/Node.hpp"

template <class Type>
class BinaryTree
{
private:
     BinaryTreeNode<Type> * root;
     BinaryTreeNode<Type> * right;
     BinaryTreeNode<Type> * left;
public:
    BinaryTreeNode();
    BinaryTreeNode(Type data);
    
    BinaryTreeNode<Type> * getRootNode();
    BinaryTreeNode<Type> * getLeftNode();
    BinaryTreeNode<Type> * getRightNode();
    
    void setRootNode(BinaryTreeNode<Type> * root);
    void setLeftNode(BinaryTreeNode<Type> * left);
    void setRightNode(BinaryTreeNode<Type> * right);
    };

template <class Type>
BinaryTreeNode<Type> :: BinaryTreeNode() : Node<Type>()
{
    root = nullptr;
    left = nullptr;
    right = nullptr;
    
}

template <class Type>
BinaryTreeNode<Type> * BinaryTreeNode<Type> :: getRootNode()
{
    return this->root;
}

template <class Type>
BinaryTreeNode<Type> * BinaryTreeNode<Type> :: getRightNode()
{
    return this->right;
}

template <class Type>
BinaryTreeNode<Type> * BinaryTreeNode<Type> :: getLeftNode()
{
    return this->left;
}

template <class Type>
void BinaryTreeNode<Type< :: setRootNode(BinaryTreeNode<Type> * newRoot)
{
    root = newRoot;
}

template <class Type>
void BinaryTreeNode<Type> :: setRightNode(BinaryTreeNode<Type> * right)
{
    this->right = right;
}

template <class Type>


#endif /* BinaryTree_hpp */
