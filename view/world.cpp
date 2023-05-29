#include <view/world.h>

#include <model/world.h>

namespace view
{

World::World(Curse& curse):
    _score{curse, 10},
    _generators{curse, {11, 12, 13, 14, 15, 16, 17, 18}}
{}

void World::draw(const model::World& worldModel) {
    _score.draw(worldModel.score());
    _generators.draw(worldModel.generators());
}

} // namespace view
