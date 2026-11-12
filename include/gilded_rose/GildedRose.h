#pragma once
#include <vector>
#include "Item.h"

class GildedRose {
public:
    std::vector<Item>& items;
    explicit GildedRose(std::vector<Item>& items);
    void updateQuality();
};
