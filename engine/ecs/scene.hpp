#pragma once
#include <entt/entt.hpp>
#include <ecs/entity.hpp>
#include <ecs/component.hpp>

class Scene
{
  public:
    Entity CreateEntity(const char *name);
    Entity GetEntityFromEntt(entt::entity entity);
    entt::registry &GetRegistry();

  private:

    entt::registry mRegistry;
};