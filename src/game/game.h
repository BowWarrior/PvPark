#ifndef GAME_H
#define GAME_H

#include "glad/glad.h"
#include "../world/world.h"
#include "../myFrame/myFrame.h"
#include "../ecs/ECS.h"
#include "../systems/RenderSystem.h"


class Game{
    public:
        Game();
        void init();
        void run();
        void shutdown();
    private:
        World world;
        MyFrame frame;
        ECS ecs;
        //Player player;
        //Renderer renderer;
        bool isRunning;
        RenderSystem renderSystem;
};

#endif