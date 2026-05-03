#ifndef GAME_H
#define GAME_H

#include "..\world\world.h"
#include "..\myFrame\myFrame.h"
#include "../ecs/ECS.h"
#include "../systems/RenderSystem.h"
#include "../factory/EntityFactory.h"


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
        EntityFactory factory;
        RenderSystem renderSystem;
        Entity triangle; //code to draw a triangle in OpenGL
        Entity circle; //example circle with OpenGL
};

#endif