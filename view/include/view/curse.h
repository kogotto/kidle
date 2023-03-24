#pragma once

namespace view
{

class Curse {
public:
    Curse();
    ~Curse();

    void print(const char* str);
    void refresh();
    int getchar();
private:
};

} // namespace view
