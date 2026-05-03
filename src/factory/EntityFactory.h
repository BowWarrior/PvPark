// EntityFactory.h
#ifndef ENTITY_FACTORY_H
#define ENTITY_FACTORY_H

#include "../ecs/ECS.h"

class EntityFactory{
public:
    EntityFactory(ECS& ecs);
    
    Entity createTriangle(float x1, float y1, float x2, float y2, float x3, float y3); //code to draw a triangle in OpenGL
    Entity createCircle(float centerX, float centerY, float radius, int segments); //example circle with OpenGL

    

private:
    ECS& ecs;
};

#endif