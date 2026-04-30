#include "..\world\world.h"

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