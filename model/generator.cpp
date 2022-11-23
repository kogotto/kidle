#include <model/generator.h>

namespace model
{

void Generator::add(Number amount) {
    _produced += amount;
}

Number Generator::tick(std::chrono::milliseconds delta) const {
    return (_manual + _produced) * _multiplier * (delta / std::chrono::seconds{1});
}

void Generator::manualUpgrage() {
}

} // namespace model
