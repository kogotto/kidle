#pragma once

#include <chrono>

#include <model/defs.h>
#include <model/generators.h>

namespace model
{

class World
{
public:
    void tick(std::chrono::milliseconds delta);
private:
    Generators _generators;
    Number _points{0};
};

} // namespace model
