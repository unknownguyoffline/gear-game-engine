#include <ecs/scene.hpp>

Entity Scene::CreateEntity(const char *name)
{
    Entity entity(mRegistry, mRegistry.create());
    entity.AddComponent<EntityMetadataComponent>().name = name;
    entity.AddComponent<TransformComponent>();
    return entity;
}

Entity Scene::GetEntityFromEntt(entt::entity entity)
{
    return Entity(mRegistry, entity);
}

entt::registry &Scene::GetRegistry()
{
    return mRegistry;
}
