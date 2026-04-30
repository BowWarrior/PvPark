#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <string>
using namespace std;
#include "..\tests\testHelloWorld\helloWorld.h"


class World{
    public:
        int renderDistance;
        float spawn;
        bool isGenerated;

        World();
        void generate();
        void update();
        void render();
        void save();
        void load(string filename);
        void testMyPrint();

};



//World generateWorld();





#endif