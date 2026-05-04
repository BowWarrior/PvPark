#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <string>
using namespace std;
#include "..\tests\testHelloWorld\helloWorld.h"
#include "../ecs/ECS.h"
#include "../factory/EntityFactory.h"
#include "../systems/RenderSystem.h"


class World{
    public:
        World(ECS& ecs);
        int renderDistance;
        float spawn;
        bool isGenerated;

        void generate();
        void update();
        void render();
        void save();
        void load(string filename);
        void testMyPrint();

    private:
        ECS& ecs;
        EntityFactory factory;
        RenderSystem renderSystem;
        Entity circle; //example circle with OpenGL
        Entity triangle; //code to draw a triangle in OpenGL


};

#endif