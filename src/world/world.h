#include <iostream>
#include <string>
using namespace std;

#include "..\tests\testHelloWorld\helloWorld.h"

#ifndef WORLD_H //never have this accidentally the same name as function name 
#define WORLD_H //never have this accidentally the same name as function name

class World{
public:
    int renderDistance;
    float spawn;
    void testMyPrint();
};



World generateWorld();





#endif