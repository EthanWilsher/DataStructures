//
//  Controller.hpp
//  DataStructuresProject
//
//  Created by Wilsher, Ethan on 1/31/18.
//  Copyright © 2018 Wilsher, Ethan. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include "FileController.hpp"

#include "Tools/Timer.hpp"

#include <iostream>
#include <vector>

#include "../Testers/ArrayTester.hpp"
#include "../Model/Structures/Linear/Array.hpp"
#include "../Testers/LinkedListTester.hpp"
#include "../Testers/TestingStacksAndQueues.hpp"
#include "../Testers/RecursionTester.hpp"

class Controller
{
private:
    void findMaxAndMin();
public:
    void start();
};

#endif /* Controller_hpp */
