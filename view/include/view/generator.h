#pragma once

namespace model
{
class Generator;
} // namespace model

namespace view
{
class Curse;
}

namespace view
{

class Generator {
public:
    Generator(Curse& curse, int row);

    void draw(const model::Generator& generatorModel);
private:
    Curse& _curse;
    int _row;
};

} // namespace view
