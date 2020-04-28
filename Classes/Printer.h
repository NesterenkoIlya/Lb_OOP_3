#pragma once

#include "Software.h"

class Printer {
    friend void Software::ToPrint();

public:
    void printing(Software*);
};
