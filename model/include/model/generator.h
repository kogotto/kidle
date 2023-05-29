#pragma once

#include <chrono>

#include <model/defs.h>

namespace model
{

class Generator
{
public:
    void add(Number amount);
    Number tick(std::chrono::milliseconds delta) const;

    void manualUpgrage();

    Number total() const;

private:
    Number _manual{1};
    Number _produced{0};
    Number _multiplier{1};
};

} // namespace model
