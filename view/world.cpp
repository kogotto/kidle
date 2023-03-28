#include <view/world.h>

#include <model/world.h>

namespace view
{

World::World(Curse& curse):
    _score(curse, 10)
{}

void World::draw(const model::World& worldModel) {
    _score.draw(worldModel.score());
    _generators.draw(worldModel.generators());
}

} // namespace view
