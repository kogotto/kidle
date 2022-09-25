#include <string>
#include <thread>

#include "curse.h"
#include "harmonicloophelpers.h"

std::string message(std::chrono::milliseconds elapsed) {
    return std::string("Elapsed: ") + std::to_string(elapsed.count()) + "ms\n";
}

int main() {
    Curse curse;

    kloop::mainLoop(
        std::chrono::milliseconds(30),
        [&curse, prev = ktime::now(), counter = 100] () mutable {
            const auto current = ktime::now();
            curse.print(message(ktime::elapsed<std::chrono::milliseconds>(prev)).c_str());
            curse.refresh();
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            prev = current;

            if (--counter < 0) {
                return kloop::LoopControl::Break;
            }
            return kloop::LoopControl::Continue;
        }
    );


    curse.print("Print text through curse");
    curse.refresh();
    curse.getchar();

    return 0;
}
