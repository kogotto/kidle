#pragma once

namespace view
{

class Curse {
public:
    Curse();
    ~Curse();

    // Absolutely no sense in copies
    Curse(const Curse&) = delete;
    Curse& operator=(const Curse&) = delete;

    Curse(Curse&&) = default;
    Curse& operator=(Curse&&) = default;

    void print(const char* str);
    void mvprint(int row, int col, const char* str);
    void refresh();
    int getchar();
private:
};

struct CurseRefresher {
    CurseRefresher(Curse& curse)
        : _curse(curse)
    {}

    ~CurseRefresher() {
        _curse.refresh();
    }
private:
    Curse& _curse;
};

} // namespace view
