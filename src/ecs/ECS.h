#ifndef ECS_H
#define ECS_H

#include <vector>
#include <unordered_map>
#include "../components/RenderComponent.h"
#include "Entity.h"
#include "../components/TransformComponent.h"
#include "../components/HealthComponent.h"

class ECS{
public:
    Entity createEntity();
    void destroyEntity(Entity entity);

    // add components
    void addTransform(Entity entity, TransformComponent transform);
    void addHealth(Entity entity, HealthComponent health);

    // get components
    TransformComponent& getTransform(Entity entity);
    HealthComponent& getHealth(Entity entity);

    void addRender(Entity entity, RenderComponent render);
    RenderComponent& getRender(Entity entity);   

    //for making the triangle and rendering graphics
    std::unordered_map<Entity, RenderComponent>& getRenders();

private:
    Entity nextEntity = 0;
    std::unordered_map<Entity, TransformComponent> transforms;
    std::unordered_map<Entity, HealthComponent> healths;
    std::unordered_map<Entity, RenderComponent> renders;
};

#endif