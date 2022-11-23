#include <model/world.h>

namespace model
{

void World::tick(std::chrono::milliseconds delta) {
    _points += _generators.tick(delta);
}

} // namespace model
