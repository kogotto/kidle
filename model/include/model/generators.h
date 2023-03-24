#pragma once

#include <array>
#include <chrono>

#include <model/generator.h>

namespace model
{

class Generators
{
public:
    using RawGenerators = std::array<Generator, 8>;

    Number tick(std::chrono::milliseconds delta);

    const RawGenerators& generators() const {
        return _generators;
    }

private:
    RawGenerators _generators;
    size_t _size{2u};
};

} // namespace model
