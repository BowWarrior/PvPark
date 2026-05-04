#include <iostream>
#include <string>
using namespace std;

#include "world.h"
#include "../ecs/ECS.h"
#include "../factory/EntityFactory.h"
#include "../systems/RenderSystem.h"

World::World(ECS& ecs) : ecs(ecs), factory(ecs){
    renderDistance = 16;
    spawn = 0.0;
    isGenerated = false;

}

void World::generate(){
    isGenerated = true;



    Entity circle, triangle;
    circle = factory.createCircle(0.0f, 0.0f, 0.3f, 64);
    triangle = factory.createTriangle(-0.5f, -0.5f, 0.5f, -0.5f, 0.0f, 0.5f);
    
}

void World::update(){
    cout << "updating" << endl;
}

/*
World generateWorld(){
    World world;
    world.renderDistance = 16;
    world.spawn = 3.0;
    //world.testMyPrint(); //keep this here if I want to automatically call the function on object initialization
    return world;
}
*/

void World::testMyPrint(){
    cout << "right now, this is printing the world.cpp testMyPrint() function as well as helloWorld.cpp's printHelloWorld() functions here -> " + printHelloWorld() << endl;
}

