#include <model/generators.h>

namespace model
{

Number Generators::tick(std::chrono::milliseconds delta) {
    for (size_t i = _size - 1; i >= 1; --i) {
        const auto& producer = _generators[i];
        auto& recepient = _generators[i-1];

        recepient.add(producer.tick(delta));
    }
    return _generators.front().tick(delta);
}

} // namespace model
