#include <chrono>
#include <thread>

#include "harmonicloophelpers.h"
#include "sharedvariable.h"

#include <model/world.h>

#include <view/curse.h>
#include <view/world.h>

namespace
{

constexpr std::chrono::milliseconds processPeriod{30};

using ModelHolder = concurrent::Variable<model::World>;

kloop::LoopControl processIteration(ModelHolder& modelHolder) {
    auto worldModel = modelHolder.uniqueLock();
    worldModel->tick(processPeriod);
    return kloop::LoopControl::Continue;
}

void processLoop(ModelHolder& modelHolder) {
    kloop::mainLoop(
        processPeriod,
        [&modelHolder] () mutable {
            return processIteration(modelHolder);
        }
    );
}

constexpr std::chrono::milliseconds drawPeriod{50};

kloop::LoopControl drawIteration(
        view::World& worldView,
        ModelHolder& modelHolder) {
    auto worldModel = modelHolder.uniqueLock();
    worldView.draw(*worldModel);
    return kloop::LoopControl::Continue;
}

void drawLoop(view::Curse& curse, ModelHolder& modelHolder) {
    view::World worldView{curse};
    kloop::mainLoop(
        drawPeriod,
        [&curse, &worldView, &modelHolder] () {
            view::CurseRefresher refresher(curse);
            return drawIteration(worldView, modelHolder);
        }
    );
}

} // namespace

int main() {

    ModelHolder worldModelHolder;

    std::jthread processThread{
        processLoop,
        std::ref(worldModelHolder)
    };

    view::Curse curse;

    drawLoop(curse, worldModelHolder);

    return 0;
}
