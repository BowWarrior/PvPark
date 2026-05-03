#include "ECS.h"
#include "../components/RenderComponent.h"

Entity ECS::createEntity(){
    return nextEntity++;
}

void ECS::destroyEntity(Entity entity){
    transforms.erase(entity);
    healths.erase(entity);
}

void ECS::addTransform(Entity entity, TransformComponent transform){
    transforms[entity] = transform;
}

void ECS::addHealth(Entity entity, HealthComponent health){
    healths[entity] = health;
}

TransformComponent& ECS::getTransform(Entity entity){
    return transforms[entity];
}

HealthComponent& ECS::getHealth(Entity entity){
    return healths[entity];
}

void ECS::addRender(Entity entity, RenderComponent render){
    renders[entity] = render;
}

RenderComponent& ECS::getRender(Entity entity){ //helps render the entity
    return renders[entity];
}

std::unordered_map<Entity, RenderComponent>& ECS::getRenders(){ //helps render the triangle
    return renders;
}