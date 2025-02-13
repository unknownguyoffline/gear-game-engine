#pragma once
#include <stdint.h>
#include <string>

using String = std::string;

class BasicString
{
  public:
    void set(const char *string);
    void append();

    uint64_t getSize() const;
    uint64_t getCapacity() const;
    const char *getString() const;

  private:
    char *mBuffer = nullptr;
    uint64_t mSize = 0;
    uint64_t mCapacity = 0;

  private:
    void resizeIfNecessary(uint64_t size, bool retainString = false);
    void putString(const char *string, uint64_t size);
    uint64_t getLength(const char *string);
    void resize(uint64_t size, bool retainString = false);
};