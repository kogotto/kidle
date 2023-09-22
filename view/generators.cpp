#include <view/generators.h>

#include <model/generators.h>

namespace
{

view::Generators::Raw createRawGenerators(
        view::Curse& curse,
        const view::Generators::Rows& rows) {
    using Generator = view::Generator;
    return {
        Generator{curse, rows[0]},
        Generator{curse, rows[1]},
        Generator{curse, rows[2]},
        Generator{curse, rows[3]},
        Generator{curse, rows[4]},
        Generator{curse, rows[5]},
        Generator{curse, rows[6]},
        Generator{curse, rows[7]},
    };
}

} // namespace

namespace view
{

Generators::Generators(Curse& curse, const Rows& rows):
    _generators{createRawGenerators(curse, rows)}
{}

void Generators::draw(const model::Generators& generatorsModel) {
    for (size_t i{0}; i < GeneratorsCount; ++i) {
        _generators[i].draw(generatorsModel.generators()[i]);
    }
}

} // namespace view
