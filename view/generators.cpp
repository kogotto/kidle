#include <view/generators.h>

#include <model/generators.h>

namespace view
{

void Generators::draw(const model::Generators& generatorsModel) {
    for (size_t i{0}; i < GeneratorsCount; ++i) {
        _generators[i].draw(generatorsModel.generators()[i]);
    }
}

} // namespace view
