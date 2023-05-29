#pragma once

#include <array>

#include <model/defs.h>

#include <view/generator.h>

namespace model
{
class Generators;
} // namespace model

namespace view
{

class Generators {
public:
    using Raw = std::array<Generator, GeneratorsCount>;
    using Rows = std::array<int, GeneratorsCount>;

    Generators(Curse& curse, const Rows& rows);

    void draw(const model::Generators& generatorsModel);
private:
    Raw _generators;
};

} // namespace view
