#pragma once
#include "core/Macro.hpp"
#include <cstdint>
#include <stddef.h>
#include <stdint.h>

class MemoryManager
{
  public:
    static void allocate(size_t size);
    static void deallocate();
    template <typename T> static T *getMemory(int count);

  private:
    static uint8_t *mArena;
    static uint64_t mCapacity;
    static uint64_t mPosition;
};

template <typename T> inline T *MemoryManager::getMemory(int count)
{
    auto totalSize = sizeof(T) * count;
    if ((mPosition + totalSize) > mCapacity)
    {
        CORE_FATAL("MemoryManager: Out of memory");
        return nullptr;
    }
    T *result = (T *)&mArena[mPosition];
    mPosition += totalSize;
    return result;
}
