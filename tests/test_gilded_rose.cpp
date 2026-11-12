#include <gtest/gtest.h>
#include <vector>
#include "gilded_rose/GildedRose.h"

TEST(GildedRoseTest, NormalItemDecreasesByOne) {
    std::vector<Item> items = { Item("+5 Dexterity Vest", 10, 20) };
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(items[0].sellIn, 9);
    EXPECT_EQ(items[0].quality, 19);
}

TEST(GildedRoseTest, NormalDegradesTwiceAfterDate) {
    std::vector<Item> items = { Item("Elixir of the Mongoose", 0, 10) };
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(items[0].sellIn, -1);
    EXPECT_EQ(items[0].quality, 8);
}

TEST(GildedRoseTest, QualityIsNeverNegative) {
    std::vector<Item> items = { Item("Elixir of the Mongoose", 0, 1) };
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(items[0].quality, 0);
}

TEST(GildedRoseTest, AgedBrieIncreasesInQuality) {
    std::vector<Item> items = {
        Item("Aged Brie", 2, 10),
        Item("Aged Brie", 0, 10)
    };
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(items[0].sellIn, 1);
    EXPECT_EQ(items[0].quality, 11);
    EXPECT_EQ(items[1].sellIn, -1);
    EXPECT_EQ(items[1].quality, 12);
}

TEST(GildedRoseTest, QualityNeverExceedsFifty) {
    std::vector<Item> items = {
        Item("Aged Brie", 5, 50),
        Item("Backstage passes to a TAFKAL80ETC concert", 5, 49)
    };
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(items[0].quality, 50);
    EXPECT_EQ(items[1].quality, 50);
}

TEST(GildedRoseTest, SulfurasNeverChanges) {
    std::vector<Item> items = { Item("Sulfuras, Hand of Ragnaros", 0, 80) };
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(items[0].sellIn, 0);
    EXPECT_EQ(items[0].quality, 80);
}

TEST(GildedRoseTest, BackstagePassesRules) {
    std::vector<Item> items = {
        Item("Backstage passes to a TAFKAL80ETC concert", 15, 20),
        Item("Backstage passes to a TAFKAL80ETC concert", 10, 20),
        Item("Backstage passes to a TAFKAL80ETC concert", 5, 20),
        Item("Backstage passes to a TAFKAL80ETC concert", 0, 20)
    };
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(items[0].quality, 21);
    EXPECT_EQ(items[1].quality, 22);
    EXPECT_EQ(items[2].quality, 23);
    EXPECT_EQ(items[3].quality, 0);
}

TEST(GildedRoseTest, ConjuredStandardDegradation) {
    std::vector<Item> items = {
        Item("Conjured Mana Cake", 3, 10),
        Item("Conjured Mana Cake", 0, 10)
    };
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(items[0].sellIn, 2);
    EXPECT_EQ(items[0].quality, 8);
    EXPECT_EQ(items[1].sellIn, -1);
    EXPECT_EQ(items[1].quality, 6);
}

TEST(GildedRoseTest, ConjuredHighChargeStable) {
    std::vector<Item> items = {
        Item("Conjured Arcane Staff", 5, 42),
        Item("Conjured Mana Potion", 5, 39)
    };
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(items[0].quality, 41);
    EXPECT_EQ(items[1].quality, 37);
}

TEST(GildedRoseTest, ConjuredQualityNeverNegative) {
    std::vector<Item> items = { Item("Conjured Mana Cake", 0, 3) };
    GildedRose app(items);
    app.updateQuality();
    EXPECT_EQ(items[0].quality, 0);
}
