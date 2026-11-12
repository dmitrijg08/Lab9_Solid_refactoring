#pragma once
#include <string>
#include <utility>

class Item {
public:
    std::string name;
    int sellIn;
    int quality;

    Item(std::string name, int sellIn, int quality)
        : name(std::move(name)), sellIn(sellIn), quality(quality) {}
};
