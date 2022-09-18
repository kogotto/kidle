#include "curse.h"

#include <ncurses.h>

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
