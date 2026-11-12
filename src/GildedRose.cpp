#include "gilded_rose/GildedRose.h"
#include "gilded_rose/ItemUpdaterFactory.h"

GildedRose::GildedRose(std::vector<Item>& items) : items(items) {}

void GildedRose::updateQuality() {
    for (auto& item : items) {
        auto updater = ItemUpdaterFactory::createUpdater(item);
        updater->update(item);
    }
}
