#pragma once

#include <model/defs.h>

namespace view
{
class Curse;
}

namespace view
{

class Score {
public:
    Score(Curse& curse, int row);
    void draw(const Number& score);
private:
    Curse& _curse;
    int _row;
};

}
