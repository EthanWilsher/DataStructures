//
//  TestingStacksAndQueues.hpp
//  DataStructuresProject
//
//  Created by Wilsher, Ethan on 2/28/18.
//  Copyright © 2018 Wilsher, Ethan. All rights reserved.
//

#ifndef TestingStacksAndQueues_hpp
#define TestingStacksAndQueues_hpp

#include <iostream>
#include "../Controller/Tools/Timer.hpp"
#include "../Controller/FileController.hpp"
#include "../Model/Structures/Linear/Stack.hpp"
#include "../Model/Structures/Linear/AbstractBase.hpp"
#include "../Model/Structures/Linear/Queue.hpp"

class TestingStacksAndQueues
{
public:
    void stackVersusList();
    void stackVersusQueue();
    void queueVersusList();
};

#endif /* TestingStacksAndQueues_hpp */

