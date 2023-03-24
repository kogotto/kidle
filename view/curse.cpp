#include <view/curse.h>

#include <ncurses.h>

namespace view
{

Curse::Curse() {
    initscr();
}

Curse::~Curse() {
    endwin();
}

void Curse::print(const char* str) {
    ::printw(str);
}

void Curse::refresh() {
    ::refresh();
}

int Curse::getchar() {
    return ::getch();
}

} // namespace view
