#pragma once

#include <model/defs.h>

namespace model
{

class Generator
{
public:

    void manualUpgrage();


private:
    Number manual{0};
    Number produced{0};
    Number multiplier{1};
};

} // namespace model
