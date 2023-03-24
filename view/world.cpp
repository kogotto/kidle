#include <view/world.h>

#include <model/world.h>

namespace view
{

void World::draw(const model::World& worldModel) {
    _score.draw(worldModel.score());
    _generators.draw(worldModel.generators());
}

} // namespace view
