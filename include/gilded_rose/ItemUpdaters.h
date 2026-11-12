#pragma once
#include "IItemUpdater.h"

// 1. Звичайні товари
class NormalItemUpdater : public BaseItemUpdater {
public:
    void update(Item& item) const override {
        decreaseQuality(item, 1);
        decrementSellIn(item);
        if (item.sellIn < 0) {
            decreaseQuality(item, 1);
        }
    }
};

// 2. Товар "Aged Brie"
class AgedBrieUpdater : public BaseItemUpdater {
public:
    void update(Item& item) const override {
        increaseQuality(item, 1);
        decrementSellIn(item);
        if (item.sellIn < 0) {
            increaseQuality(item, 1);
        }
    }
};

// 3. Легендарний товар "Sulfuras, Hand of Ragnaros"
class SulfurasUpdater : public BaseItemUpdater {
public:
    void update(Item& /*item*/) const override {
        // Легендарний товар не змінює ні SellIn, ні Quality (завжди 80)
    }
};

// 4. Квитки "Backstage passes to a TAFKAL80ETC concert"
class BackstagePassUpdater : public BaseItemUpdater {
public:
    void update(Item& item) const override {
        if (item.sellIn <= 5) {
            increaseQuality(item, 3);
        } else if (item.sellIn <= 10) {
            increaseQuality(item, 2);
        } else {
            increaseQuality(item, 1);
        }

        decrementSellIn(item);

        if (item.sellIn < 0) {
            item.quality = 0;
        }
    }
};

// 5. Індивідуальне розширення: товари категорії "Conjured"
class ConjuredItemUpdater : public BaseItemUpdater {
public:
    void update(Item& item) const override {
        int dailyDegradation = (item.quality >= 40 && item.sellIn > 0) ? 1 : 2;
        decreaseQuality(item, dailyDegradation);

        decrementSellIn(item);

        if (item.sellIn < 0) {
            decreaseQuality(item, 2);
        }
    }
};
