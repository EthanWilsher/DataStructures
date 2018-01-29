//
//  Controller.cpp
//  ConsoleOutputProject
//
//  Created by Wilsher, Ethan on 1/25/18.
//  Copyright © 2018 Wilsher, Ethan. All rights reserved.
//

#include "Controller.hpp"

using namespace std;

int looped = 13;

string * sPtr;

string name = "Ethan Wilsher";







Controller :: Controller()
{
    
}

void Controller :: start()
{
    for(int index = 13; index < 31; index++)
    {
        cout << "this loop has looped a loopy loop" << index + 1 << "times" << endl;
    }
}
