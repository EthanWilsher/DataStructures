//
//  Controller.cpp
//  VectorProject
//
//  Created by Wilsher, Ethan on 1/29/18.
//  Copyright © 2018 Wilsher, Ethan. All rights reserved.
//

#include "Controller.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Controller :: Controller()
{
    vector <int> intVector;
    vector <string> stringVector;
    
    for (int i = 1; i<=5; i++)
    {
        intVector.push_back(i);
        cout << i << endl;
    }
    
    stringVector.push_back("apples");
    stringVector.push_back("bananas");
    stringVector.push_back("oranges");
    stringVector.push_back("watermelon");
    stringVector.push_back("grapes");
    for (auto i = stringVector.begin(); i != stringVector.end(); i++)
    {
        cout << *i << ' ';
    }
    cout << endl;
    
}

void Controller :: start()
{
    int intArray [5] = {1, 2, 3, 4, 5};
    string stringArray [4] = {"Darth" "Plagues" "The" "Wise"};
    double doubleArray [4] = {1.36, 1.776, 1.6667};
    
    cout << intArray << " <- Reference to Int array" << endl;
    cout << stringArray << " <- Reference to String array" << endl;
    cout << doubleArray << " <- Reference to Double array" << endl;
    
    
}
