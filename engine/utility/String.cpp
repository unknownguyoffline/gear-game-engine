#include "String.hpp"
#include <string.h>

void BasicString::set(const char *string)
{
    uint64_t totalSize = getLength(string);
    resizeIfNecessary(totalSize);
    putString(string, totalSize);
}

uint64_t BasicString::getSize() const
{
    return mSize;
}

uint64_t BasicString::getCapacity() const
{
    return mCapacity;
}

const char *BasicString::getString() const
{
    return mBuffer;
}

void BasicString::resizeIfNecessary(uint64_t size, bool retainString)
{
    if (size > mCapacity)
    {
        resize(size, retainString);
    }
}

void BasicString::putString(const char *string, uint64_t size)
{
    mSize = size;
    memcpy(mBuffer, string, size);
    mBuffer[size] = '0';
}

uint64_t BasicString::getLength(const char *string)
{
    return strlen(string);
}

void BasicString::resize(uint64_t size, bool retainString)
{
    if (!retainString)
    {
        if (mBuffer == nullptr)
            delete mBuffer;
        mBuffer = new char[size + 1];
        mCapacity = size;
        mSize = 0;
    }
    else
    {
        char *temporary = mBuffer;
        mBuffer = nullptr;
        mBuffer = new char[size + 1];
        mCapacity = size;
        putString(temporary, mSize);
    }
}
