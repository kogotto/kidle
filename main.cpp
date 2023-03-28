#include <chrono>
#include <string>
#include <thread>

#include <view/curse.h>
#include "harmonicloophelpers.h"
#include "sharedvariable.h"

std::string message(int tick) {
    return std::string("Tick: ") + std::to_string(tick) + "\n";
}

int next(concurrent::Variable<int>& dataHolder) {
    auto data = dataHolder.uniqueLock();
    return ++*data;
}

constexpr std::chrono::milliseconds processPeriod{30};

using ModelHolder = concurrent::Variable<int>;

kloop::LoopControl processIteration(ModelHolder& modelHolder) {
    const auto currentData = next(modelHolder);
    return currentData > 100 ?
        kloop::LoopControl::Break:
        kloop::LoopControl::Continue;
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
        view::Curse& curse,
        ModelHolder& modelHolder) {
    const auto currentData = [&modelHolder] {
        const auto data = modelHolder.uniqueLock();
        return *data;
    } ();
    curse.print(message(currentData).c_str());
    curse.refresh();
    return currentData > 100 ?
        kloop::LoopControl::Break:
        kloop::LoopControl::Continue;
}

void drawLoop(view::Curse& curse, ModelHolder& modelHolder) {
    kloop::mainLoop(
        drawPeriod,
        [&curse, &modelHolder] () {
            return drawIteration(curse, modelHolder);
        }
    );
}

int main() {

    concurrent::Variable<int> dataHolder{0};

    std::jthread processThread{
        processLoop,
        std::ref(dataHolder)
    };

    view::Curse curse;

    drawLoop(curse, dataHolder);

    curse.print("Print text through curse");
    curse.refresh();
    curse.getchar();

    return 0;
}
