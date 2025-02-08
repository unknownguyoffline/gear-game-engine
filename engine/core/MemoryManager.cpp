#include "core/MemoryManager.hpp"
#include <cstdint>
#include <cstdlib>
#include <stdlib.h>

uint64_t MemoryManager::mPosition = 0;
uint64_t MemoryManager::mCapacity = 0;
uint8_t *MemoryManager::mArena = 0;

void MemoryManager::allocate(size_t size)
{
    mArena = (uint8_t *)malloc(size);
    mCapacity = size;
    if (mArena == nullptr)
    {
        CORE_ERROR("Memory Arena Allocation failed");
    }
}

void MemoryManager::deallocate()
{
    free(mArena);
}

// void *MemoryManager::getMemory(size_t size)
// {
//     if (mPosition + size > mCapacity)
//     {
//         CORE_ERROR("MemoryManager: Out of memory");
//         return 0;
//     }
//     uint8_t *result = &mArena[mPosition];
//     mPosition += size;
//     return result;
// }
