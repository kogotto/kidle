#include <view/score.h>

#include <string>

#include <view/curse.h>

namespace
{

std::string message(const Number& score) {
    return "current score = " + std::to_string(score);
}

} // namespace

namespace view
{

Score::Score(Curse& curse, int row):
    _curse(curse),
    _row(row)
{}

void Score::draw(const Number& score) {
    _curse.mvprint(_row, 0, message(score).c_str());
}

}
