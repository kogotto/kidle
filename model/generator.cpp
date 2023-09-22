#include <chrono>
#include <model/generator.h>

namespace
{

double timeCoefficient([[maybe_unused]] std::chrono::milliseconds delta) {
    // TODO use delta
    return 0.03;
}

} // namespace

namespace model
{

void Generator::add(Number amount) {
    _produced += amount;
}

Number Generator::tick([[maybe_unused]] std::chrono::milliseconds delta) const {
    // TODO use delta
    return (_manual + _produced) * _multiplier * timeCoefficient(delta);
}

void Generator::manualUpgrage() {
}

Number Generator::total() const {
    return _manual + _produced;
}

} // namespace model
