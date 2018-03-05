//
//  Controller.cpp
//  DataStructuresProject
//
//  Created by Wilsher, Ethan on 1/31/18.
//  Copyright © 2018 Wilsher, Ethan. All rights reserved.
//

#include "Controller.hpp"

using namespace std;

void Controller :: start()
{

    
    RecursionTester test;
    test.testRecursionNumbers();
}


void Controller :: findMaxAndMin()
{
    Timer codeTimer;
    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/ewil1026/Documents/DataStructures/DataStructuresProject/DataStructuresProject/Data/CrimeData.cpp");
    
    int minIndex = 0;
    int maxIndex = 0;
    
    for(int index = 1; index < myData.size(); index++)
    {
        if(myData [minIndex] > myData [index])
        {
            minIndex = index;
        }
        
        if(myData[maxIndex] < myData[index])
        {
            maxIndex = index;
        }
        
        
    }
    codeTimer.stopTimer();
    cout << "The smallest Crime stat is at " << minIndex << "and it is:" << myData[minIndex] << endl;
    cout << "The bigest Crime stat is at " << maxIndex << "and it is:" << myData[maxIndex] << endl;
    codeTimer.displayInformation();
}

