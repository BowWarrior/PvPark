#ifndef GAME_H
#define GAME_H

#include "../world/world.h"
#include "../myFrame/myFrame.h"


class Game{
    public:
        Game();
        void init();
        void run();
        void shutdown();
    private:
        World world;
        MyFrame frame;
        //Player player;
        //Renderer renderer;
        bool isRunning;
};

#endif