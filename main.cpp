#include <chrono>
#include <string>
#include <thread>

#include "curse.h"
#include "harmonicloophelpers.h"
#include "sharedvariable.h"

std::string message(int tick) {
    return std::string("Tick: ") + std::to_string(tick) + "\n";
}

int next(concurrent::Variable<int>& data) {
    auto dataAccessor = data.uniqueLock();
    return ++*dataAccessor;
}

int main() {

    concurrent::Variable<int> data{0};

    std::jthread processThread{
        [&data] {
            kloop::mainLoop(
                std::chrono::milliseconds{30},
                [&data] () mutable {
                    const auto currentData = next(data);
                    return currentData > 100 ?
                       kloop::LoopControl::Break:
                       kloop::LoopControl::Continue;
                }
            );
        }
    };

    Curse curse;

    kloop::mainLoop(
        std::chrono::milliseconds{50},
        [&curse, &data] () mutable {
            const auto currentData = [&data] {
                const auto dataAccessor = data.uniqueLock();
                return *dataAccessor;
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
