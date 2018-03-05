//
//  TestingStacksAndQueues.cpp
//  DataStructuresProject
//
//  Created by Wilsher, Ethan on 2/28/18.
//  Copyright © 2018 Wilsher, Ethan. All rights reserved.
//

#include "LinkedList.hpp"
#include "Timer.hpp"
#include "TestingStacksAndQueues.hpp"

using namespace std;

void TestingStacksAndQueues :: stackVersusList()
{
    Stack<int> numberStack;
    LinkedList<int> numberList;
    Timer stackTimer, listTimer;
    
    for(int index = 0; index < 10; index++)
    {
        numberStack.add(index);
        numberList.add(index);
    }
    
    cout << "Get the third from the last item from the structure" << endl;
    
    int index = 0;
    int value = -99;
    stackTimer.startTimer();
    
    while (index < 7)
    {
        cout << numberStack.pop() << endl;
        
        index++;
    }
    
    stackTimer.stopTimer();
    index = 0;
    listTimer.startTimer();
    value = numberList.getFromIndex(7);
    listTimer.stopTimer();
    
    cout << "The time it took to work with Stack" << endl;
    stackTimer.displayInformation();
    cout << "The time it took to work with List" << endl;
    listTimer.displayInformation();
}

void TestingStacksAndQueues :: stackVersusQueue()
{
    
    
}

void TestingStacksAndQueues :: queueVersusList()
{
    
}
