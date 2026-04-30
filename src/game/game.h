#include <iostream>
#include <string>
using namespace std;

#include "..\world\world.h"
#include "..\tests\testHelloWorld\helloWorld.h"

#ifndef GAME_H
#define GAME_H

class Game{
    public:
        Game();
        void init();
        void run();
        void shutdown();
    private:
        World world;
        //Player player;
        //Renderer renderer;
        bool isRunning;
};

#endif