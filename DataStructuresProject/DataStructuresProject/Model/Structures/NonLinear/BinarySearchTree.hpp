//
//  BinarySearchTree.hpp
//  DataStructuresProject
//
//  Created by Wilsher, Ethan on 3/29/18.
//  Copyright © 2018 Wilsher, Ethan. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include "BinaryTree.hpp"
#include "Tree.hpp"
#include <iostream>

using namespace std;

template <class Type>
class BinarySearchTree : public Tree<Type>
{
protected:
    
    int calculateSize(BinaryTree<Type> * startNode);
    int calculateHeight(BinaryTree<Type> * startNode);
    bool isBalanced(BinaryTree<Type> * startNode);
    bool isComplete(BinaryTree<Type> * startNode, int index, int size);
    
    void inOrderTraversal(BinaryTree<Type> * inStart);
    void preOrderTraversal(BinaryTree<Type> * preStart);
    void postOrderTraversal(BinaryTree<Type> * postStart);
    
    BinaryTree<Type> * getRightMostChild(BinaryTree<Type> * current);
    BinaryTree<Type> * getLeftMostChild(BinaryTree<Type> * current);
    
    void removeNode(BinaryTree<Type> * removeMe);
    
public:
    
    BinarySearchTree();
    ~BinarySearchTree();
    
    BinaryTree<Type> * getRoot();
    void setRoot(BinaryTree<Type> * root);
    
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    void demoTraversalSteps(BinaryTree<Type> * node);
    
    int getSize();
    int getHeight();
    bool isComplete();
    bool isBalanced();
    
    bool contains(Type value);
    void insert(Type itemToInsert);
    void remove(Type value);
    
    Type findMinimum();
    Type findMaximum();
};

template <class Type>
BinarySearchTree<Type> :: BinarySearchTree()
{
    this->root = nullptr;
}

template <class Type>
void BinarySearchTree<Type> :: insert(Type itemToInsert)
{
    BinaryTree<Type> * insertMe = new BinaryTree<Type>(itemToInsert);
    BinaryTree<Type> * previous = nullptr;
    BinaryTree<Type> * current = this->root;
    
    if(current == nullptr)
    {
        this->root = insertMe;
    }
    else
    {
        while(current != nullptr)
        {
            previous = current;
            if(itemToInsert < current->getData())
            {
                current = current->getLeftNode();
            }
            else if(itemToInsert > current->getData())
            {
                current = current->getRightNode();
            }
            else
            {
                cerr << "Item exists already - Exiting insert" << endl;;
                delete insertMe;
                return;
            }
        }
        if (previous->getData() > itemToInsert)
        {
            previous->setLeftNode(insertMe);
        }
        else
        {
            previous->setRightNode(insertMe);
        }
        insertMe->setRootNode(previous);
    }
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal()
{
    preOrderTraversal(this->root);
    
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal()
{
    postOrderTraversal(this->root);
}

template <class Type>
bool BinarySearchTree<Type> :: contains(Type itemToFind)
{
    BinaryTree<Type> * current = this->root;
    if(current == nullptr)
    {
        return false;
    }
    else
    {
        while(current != nullptr)
        {
            if(itemToFind == current->getData())
            {
                return true;
            }
            else if (itemToFind < current->getData())
            {
                current = current->getLeftNode();
            }
            else
            {
                current = current->getRightNode();
            }
        }
        return false;
        
    }
    
}



template <class Type>
void BinarySearchTree<Type> :: remove(Type getRidOfMe)
{
    if(this->root == nullptr)
    {
        cout << "Empty tree so removal is not possible" << endl;
    }
    else
    {
        BinaryTree<Type> * current = this->root;
        BinaryTree<Type> * previous = nullptr;
        bool hasBeenFound = false;
        
        while(current != nullptr && !hasBeenFound)
        {
            if(current->getData() == getRidOfMe)
            {
                hasBeenFound = true;
            }
            else
            {
                previous = current;
                if(getRidOfMe < current->getData())
                {
                    current = current->getLeftNode();
                }
                else
                {
                    current = current->getRightNode();
                }
            }
        }
    }
    
    if(current == nullptr)
    {
        cerr << "Item not found, removal unsuccessful" << endl;
    }
    else if(hasBeenFound)
    {
        if(current == this->root)
        {
            removeNode(this->root);
        }
        else if(getRidOfMe < previous->getData())
        {
            removeNode(previous->getLeftNode());
        }
        else
        {
            removeNode(previous->getRightNode());
        }
    }
    
}

template <class Type>
void BinarySearchTree<Type> :: removeNode(BinaryTree<Type> * removeMe)
{
    BinaryTree<Type> * current;
    BinaryTree<Type> * previous;
    BinaryTree<Type> * temp;
    
    previous = removeMe->getRootNode();
    
    if(removeMe->getRightNode() == nullptr && removeMe->getLeftNode() == nullptr)
    {
        temp = removeMe;
        removeMe = nullptr;
        
        if(previous != nullptr && removeMe->getData() < previous->getData())
        {
            previous->setLeftNode(removeMe);
        }
        else if(previous != nullptr && removeMe->getData() > previous->getData())
        {
            previous->setRightNode(removeMe);
            delete temp;
        }
        else if(removeMe->getRightNode() == nullptr)
        {
            temp = removeMe;
            removeMe = removeMe->getLeftNode();
            
            if(previous != nullptr && temp->getData() < previous->getData())
            {
                previous->setLeftNode(removeMe);
            }
            else if(previous != nullptr && temp->getData() > previous->getData())
            {
                previous->setRightNode(removeMe);
                
                removeMe->setRootNode(previous);
                
                delete temp;
            }
        }
        else if(removeMe->getLeftNode() == nullptr)
        {
            temp = removeMe;
            removeMe = removeMe->getRightNode();
            if(previous != nullptr && removeMe->getData() < previous->getData())
            {
                previous->setLeftNode(removeMe);
            }
            else if(previous != nullptr && removeMe->getData() > previous->getData())
            {
                previous->setRightNode(removeMe);
                removeMe->setRootNode(previous);
                delete temp;
            }
        }
        else
        {
            current = getRightMostChild(removeMe->getLeftNode());
            
            previous = current->getRootNode();
            removeMe->setData(current->getData());
            
            if(previous == nullptr)
            {
                removeMe->setLeftNode(current->getLeftNode());
            }
            else
            {
                previous->setRightNode(current->getLeftNode());
            }
            if(current->getLeftNode() != nullptr)
            {
                current->getLeftNode()->setRootNode(removeMe);
            }
            
            delete current;
            
            if(removeMe == nullptr || removeMe->getRootNode() == nullptr)
            {
                this->root = removeMe;
            }
        }
}


template<class Type>
BinaryTree<Type> * BinaryTree<Type> :: getLeftMostChild(BinaryTree<Type> * startingNode)
{
    BinaryTreeNode<Type> * currentNode = startingNode;
    BinaryTreeNode<Type> * previous = nullptr;
    while (currentNode != nullptr)
    {
        previous = currentNode;
        currentNode = currentNode->getLeftNode();
    }
    
    return previous;
}
            
template<class Type>
BinaryTreeNode<Type> * BinarySearchTree<Type> :: getRightMostChild(BinaryTreeNode<Type> * startingNode)
{
    BinaryTreeNode<Type> * currentNode = startingNode;
    BinaryTreeNode<Type> * previous = nullptr;
    while (currentNode != nullptr)
    {
        previous = currentNode;
        currentNode = currentNode->getRightNode();
    }
    return previous;
}
            
template <class Type>
Type BinarySearchTree<Type> :: findMaximum()
{
    assert(this->root != nullptr);
    return getRightMostChild(this->root)->getData();
                
}
            
template <class Type>
Type BinarySearchTree<Type> :: findMinimum()
{
    assert(this->root != nullptr);
    return getLeftMostChild(this->root)->getData();
                
}
            
void destroyTree(BinaryTreeNode<Type>* node)
            
template <class Type>
BinarySearchTree<Type> :: ~BinarySearchTree()
{
    destroyTree(this->root);
}
            
template <class Type>
void BinarySearchTree<Type> :: destroyTree(BinaryTreeNode<Type> * node)
{
    if(node != nullptr)
    {
        destroyTree(node->getLeftNode());
        destroyTree(node->getRightNode());
        delete node;
    }
}


template <class Type>
int BinarySearchTree<Type> :: getHeight()
{
    return calculateHeight(this->root);
}

template <class Type>
int BinarySearchTree<Type> :: calculateHeight(BinaryTreeNode<Type> * current)
{
    if (current != nullptr)
    {
        return max(calculateHeight(current->getLeftNode()), calculateHeight(current->getRightNode())) + 1;
    }
    return 0;
}

template <class Type>
int BinarySearchTree<Type> :: getSize()
{
    int size = 0;
    
    size += calculateSize(this-root);
    
    return size;
}

template <class Type>
int BinarySearchTree<Type> :: calculateSize(BinaryTreeNode<Type> * current)
{
    if(current != nullptr)
    {
        return calculateSize(current->getLeftNode()) + calculateSize(current->getRightNode()) +1;
    }
    
    return 0;
}

template <class Type>
bool BinarySearchTree<Type> :: isComplete()
{
    
    int index = 0;
    int size = getSize();
    
    return isComplete(this->root, index, size);
    
}

template <class Type>
bool BinarySearchTree<Type> :: isComplete(BinaryTreeNode<Type> * startNode, int index, int size)
{
    if(startNode == nullptr)
    {
        return true;
    }
    
    if(index >= size)
    {
        return false;
    }
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced()
{
    return isBalanced(this->root);
}

template <class Type>
bool BinarySearchTree<Type> :: isBalanced(BinaryTreeNode<Type> * current)
{
    int leftHeight = 0;
    int rightHeight = 0;
    
    if(current = nullptr)
    {
        return true;
    }
    
    leftHeight = calculateHeight(current->getLeftNode());
    rightHeight = calculateHeight(current->getRightNode());
    
    int heightDifference = abs(leftHeight - rightHeight);
    bool leftBalanced = isBalanced(current->getLeftNode());
    bool rightBalanced = isBalanced(current->getRightNode());
    
    
    if(heightDifference <= 1 && leftBalanced && rightBalanced)
    {
        return true;
    }
    
    return false;
    
    
}

template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal()
{
    inOrderTraversal(this->root);
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal()
{
    preOrderTraversal(this-root);
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal()
{
    postOrderTraversal(this->root);
    
}

template <class Type>
BinarySearchTree<Type> :: ~BinarySearchTree()
{
    
}

template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal(BinaryTreeNode<Type> * inStart)
{
    if(inStart != nullptr)
    {
        cout << "going left" << endl;
        inOrderTraversal(inStart->getLeftNode());
        cout << "Node Contents: " << inStart->getData() << endl;
        cout << "going right" << endl;
        inOrderTraversal(inStart->getRightNode());
    }
}

template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal(BinaryTreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        cout << currentNode->getData() << endl;
        preOrderTraversal(currentNode->getLeftNode());
        preOrderTraversal(currentNode->getLeftNode());
    }
}

template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal(BinaryTreeNode<Type> * currentNode)
{
    if(currentNode != nullptr)
    {
        postOrderTraversal(currentNode->getLeftNode());
        postOrderTraversal(currentNode->getRightNode());
        cout << currentNode->getData() <<  endl;
    }
}

#endif /* BinarySearchTree_hpp */
