#pragma once
#include <vendor/entt/entt.hpp>

struct Entity
{
    template <typename T> T &GetComponent()
    {
        return mRegistry->get<T>(mEntity);
    }
    template <typename T> T &AddComponent()
    {
        mRegistry->emplace<T>(mEntity);
        return mRegistry->get<T>(mEntity);
    }
    template <typename T> bool HasComponent()
    {
        return mRegistry->all_of<T>(mEntity);
    }

    Entity(entt::registry &registry, entt::entity entity);

    entt::registry *mRegistry;
    entt::entity mEntity;
};