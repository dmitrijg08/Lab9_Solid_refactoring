#pragma once
#include "Book.h"

class IBookDisplay {
public:
    virtual ~IBookDisplay() = default;
    virtual void show(const Book& book) const = 0;
};
