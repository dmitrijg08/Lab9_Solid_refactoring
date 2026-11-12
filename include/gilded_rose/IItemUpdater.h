#pragma once
#include <algorithm>
#include "Item.h"

class IItemUpdater {
public:
    virtual ~IItemUpdater() = default;
    virtual void update(Item& item) const = 0;
};

class BaseItemUpdater : public IItemUpdater {
protected:
    static constexpr int MIN_QUALITY = 0;
    static constexpr int MAX_QUALITY = 50;

    static void increaseQuality(Item& item, int amount = 1) {
        item.quality = std::min(MAX_QUALITY, item.quality + amount);
    }

    static void decreaseQuality(Item& item, int amount = 1) {
        item.quality = std::max(MIN_QUALITY, item.quality - amount);
    }

    static void decrementSellIn(Item& item) {
        --item.sellIn;
    }
};
