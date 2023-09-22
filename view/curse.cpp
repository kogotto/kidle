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
    ::printw("%s", str);
}

void Curse::mvprint(int row, int col, const char* str) {
    ::mvprintw(row, col, "%s", str);
}

void Curse::refresh() {
    ::refresh();
}

int Curse::getchar() {
    return ::getch();
}

} // namespace view
