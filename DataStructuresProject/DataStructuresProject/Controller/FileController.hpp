//
//  FileController.hpp
//  DataStructuresProject
//
//  Created by Wilsher, Ethan on 1/31/18.
//  Copyright © 2018 Wilsher, Ethan. All rights reserved.
//

#ifndef FileController_hpp
#define FileController_hpp

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

#include "../Data/CrimeData.hpp"
#include "Array.hpp"
#include "LinkedList.hpp"


using namespace std;

class FileController
{

public:
    static vector<CrimeData> readCrimeDataToVector(string filename);
};

static LinkedList<CrimeData> readDataToList(string filename);

LinkedList<CrimeData> FileController :: readDataToList(string filename)
{
    LinkedList<CrimeData> crimes;
    
    string currentCSVLine;
    int rowCount = 0;
    
    ifstream dataFile(fileName);
    
    if (dataFile.is_open())
    {
      while (!dataFile.eof())
      {
          
          getLine(dataFile, currentCSVLine, '\n');
          
          if (rowCount != 0)
          {
            if(currentCSVLine.length() != 0)
            {
                CrimeData row(currentCSVLine);
                crimes.add(row);
            }
          }
          rowCount++
      }
        dataFile.close();
    }
    else
    {
        cerr << "No File" << endl;
    }
    return crimes;
}
#endif /* FileController_hpp */
