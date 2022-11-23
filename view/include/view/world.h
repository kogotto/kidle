#pragma once

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
};

} // namespace view
