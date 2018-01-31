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
    cout << "Print to the screen text" << endl;
    codeTimer.stopTimer();
    codeTimer.displayInformation();
    
    codeTimer.resetTimer();
    codeTimer.startTimer();
    for (int index = 0; index < 1000; index++)
    {
        cout << "The index is " << index << "\t";
    }
    
    codeTimer.stopTimer();
    codeTimer.displayInformation();
}

