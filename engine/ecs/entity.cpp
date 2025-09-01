#include "ecs/entity.hpp"
#include <ecs/entity.hpp>

Entity::Entity(entt::registry &registry, entt::entity entity)
{
    mRegistry = &registry;
    mEntity = entity;
}