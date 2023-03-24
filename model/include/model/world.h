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

    const Number& score() const {
        return _score;
    }

    const Generators& generators() const {
        return _generators;
    }

private:
    Number _score{0};
    Generators _generators;
};

} // namespace model
