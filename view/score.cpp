#include <view/score.h>

namespace view
{

Score::Score(Curse& curse, int row):
    _curse(curse),
    _row(row)
{}

void Score::draw(const Number& score) {
    (void) score;

}

}
