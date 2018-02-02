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
    cout << "Testing the timer class" << endl;
    Timer codeTimer;
    codeTimer.startTimer();
    cout << "print to screen" << endl;
    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/ewil1026/Documents/DataStructures/DataStructuresProject/DataStructuresProject/Data/CrimeData.cpp");
    for ( int loop = 0; loop < 30; loop++)
    {
        cout << "spot #" << loop << ": " << myData[loop] << endl;
    }
    
    codeTimer.stopTimer();
    codeTimer.displayInformation();
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

