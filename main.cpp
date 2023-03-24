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

int main() {

    concurrent::Variable<int> dataHolder{0};

    std::jthread processThread{
        [&dataHolder] {
            kloop::mainLoop(
                std::chrono::milliseconds{30},
                [&dataHolder] () mutable {
                    const auto currentData = next(dataHolder);
                    return currentData > 100 ?
                       kloop::LoopControl::Break:
                       kloop::LoopControl::Continue;
                }
            );
        }
    };

    view::Curse curse;

    kloop::mainLoop(
        std::chrono::milliseconds{50},
        [&curse, &dataHolder] () mutable {
            const auto currentData = [&dataHolder] {
                const auto data = dataHolder.uniqueLock();
                return *data;
            } ();
            curse.print(message(currentData).c_str());
            curse.refresh();
            return currentData > 100 ?
               kloop::LoopControl::Break:
               kloop::LoopControl::Continue;
        }
    );

    curse.print("Print text through curse");
    curse.refresh();
    curse.getchar();

    return 0;
}
