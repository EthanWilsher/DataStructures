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
#include "CrimeData.hpp"

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
    
    cout << "What is left in the stack" << endl;
    
    LinkedList<int> * listVersion = &numberStack;
    int stackSize = listVersion->getSize();
    cout << "Stack size is: " << stackSize << endl;
    for (int index = 0; index < stackSize; index++)
    {
        cout << numberList.getFromIndex(index) << "\t";
    }
}

void TestingStacksAndQueues :: stackVersusQueue()
{
    vector<CrimeData> data = FileController :: readCrimeDataToVector("path to file");
    
    Stack<CrimeData> crimeStack;
    Queue<CrimeData> crimeQueue;
    
    for (int index = 0; index < 100; index ++)
    {
        CrimeData temp = data.at(index);
        crimeStack.push(temp);
        crimeQueue.enqueue(temp);
    }
    
    Queue<int> queue;
    Stack<int> stack;
    Queue<int> queueFromStack;
    Stack<int> stackFromQueue;
    
    for(int index = 0; index < 10; index++)
    {
        queue.enqueue(index);
        stack.push(index);
    }
    
    for (int index = 0; index < 10; index++)
    {
        cout << index << endl;
        cout << "Queue result: " << queue.dequeue() << endl;
        cout << "Stack result: " << stack.pop() << endl;
    }
    
    for (int index = 0; index < 10; index++)
    {
        queue.enqueue(index);
        stack.push(index);
    }
    
    for (int index = 0; index < 10; index++)
    {
        stackFromQueue.push(queue.dequeue());
        queueFromStack.enqueue(stack.pop());
    }
    
    for (int index = 0; index < 10; index++)
    {
        cout << index << endl;
        cout << "Stack result: " << stackFromQueue.pop() << endl;
        cout << "Queue result: " << queueFromStack.dequeue() << endl;
    }
 
    
}

void TestingStacksAndQueues :: queueVersusList()
{
    
}
