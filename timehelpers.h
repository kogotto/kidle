#include <chrono>

namespace ktime {

using TimePoint = std::chrono::high_resolution_clock::time_point;

inline auto now() {
    return std::chrono::high_resolution_clock::now();
}

template <typename Duration = std::chrono::microseconds>
inline auto elapsed(TimePoint started) {
    return std::chrono::duration_cast<Duration>(now() - started);
}

} // namespace time
