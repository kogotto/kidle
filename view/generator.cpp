#include <view/generator.h>

#include <string>

#include <model/generator.h>

#include <view/curse.h>

namespace
{

std::string message(const model::Generator& generator) {
    return "total = " + std::to_string(generator.total());
}

} // namespace

namespace view
{

Generator::Generator(Curse& curse, int row):
    _curse(curse),
    _row(row)
{}

void Generator::draw(const model::Generator& generatorModel) {
    _curse.mvprint(_row, 0, message(generatorModel).c_str());
}

} // namespace view
