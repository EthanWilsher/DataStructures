//
//  Runner.cpp
//  VectorProject
//
//  Created by Wilsher, Ethan on 1/29/18.
//  Copyright © 2018 Wilsher, Ethan. All rights reserved.
//

#include <stdio.h>
#include "Controller.hpp"

int main()
{
    Controller * app = new Controller();
    
    (*app).start();
    app->start();
    
    return 0;
}
