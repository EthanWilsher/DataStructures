//
//  BinaryTreeTester.hpp
//  DataStructuresProject
//
//  Created by Wilsher, Ethan on 3/29/18.
//  Copyright © 2018 Wilsher, Ethan. All rights reserved.
//

#ifndef BinaryTreeTester_hpp
#define BinaryTreeTester_hpp

#include "../Model/Structures/NonLinear/BinaryTree.hpp"
#include "../Model/Structures/NonLinear/BinarySearchTree.hpp"
#include <iostream>

class BinaryTreeTester
{
private:
    BinarySearchTree<int> testTree;
    BinaryTreeNode<int> testNode;
public:
    void doTreeStuff();
};




#endif /* BinaryTreeTester_hpp */
