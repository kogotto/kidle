#include <thread>

#include "timehelpers.h"

namespace kloop {

enum class LoopControl {
    Continue,
    Break
};

struct LaunchResult {
    LoopControl result;
    std::chrono::microseconds elapsed;
};

template<typename Func>
LaunchResult launch(Func& func) {
    const auto started = ktime::now();
    const auto result = func();
    return {result, ktime::elapsed(started)};
}

template <typename Rep, typename Period, typename Func>
void mainLoop(std::chrono::duration<Rep, Period> duration, Func func) {
    while (true) {
        const auto [result, elapsed] = launch(func);
        if (result == LoopControl::Break) {
            return;
        }
        std::this_thread::sleep_for(duration - elapsed);
    }
}

} // namespace kloop
