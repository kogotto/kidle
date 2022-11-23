#pragma once

#include <array>
#include <chrono>

#include <model/generator.h>

namespace model
{

class Generators
{
public:
    Number tick(std::chrono::milliseconds delta);
private:
    std::array<Generator, 8> _generators;
    size_t _size{2u};
};

} // namespace model
