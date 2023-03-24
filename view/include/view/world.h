#pragma once

#include <view/score.h>
#include <view/generators.h>

namespace model
{
class World;
} // namespace model

namespace view
{

class World {
public:
    void draw(const model::World& worldModel);
private:
    Score _score;
    Generators _generators;
};

} // namespace view
