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
    void draw(const model::Generators& generatorsModel);
private:
    std::array<Generator, GeneratorsCount> _generators;
};

} // namespace view
