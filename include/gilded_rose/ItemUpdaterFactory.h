#pragma once
#include <memory>
#include <string>
#include "ItemUpdaters.h"

class ItemUpdaterFactory {
public:
    static std::unique_ptr<IItemUpdater> createUpdater(const Item& item) {
        if (item.name == "Aged Brie") {
            return std::make_unique<AgedBrieUpdater>();
        }
        if (item.name == "Sulfuras, Hand of Ragnaros") {
            return std::make_unique<SulfurasUpdater>();
        }
        if (item.name == "Backstage passes to a TAFKAL80ETC concert") {
            return std::make_unique<BackstagePassUpdater>();
        }
        if (item.name.rfind("Conjured", 0) == 0) {
            return std::make_unique<ConjuredItemUpdater>();
        }
        return std::make_unique<NormalItemUpdater>();
    }
};
