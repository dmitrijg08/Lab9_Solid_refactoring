#include <iostream>
#include <vector>
#include "library/Infrastructure.h"
#include "library/Library.h"
#include "gilded_rose/GildedRose.h"

void runLibraryDemo() {
    DatabaseBookRepository dbRepo;
    EmailNotificationService emailNotifier;
    ConsoleBookDisplay consoleDisplay;

    std::cout << "=== 1. Library System (Standard Email Notification) ===\n";
    Library library(dbRepo, emailNotifier, consoleDisplay);

    Book book1("The Catcher in the Rye", "J.D. Salinger");
    Book book2("To Kill a Mockingbird", "Harper Lee");

    library.addBook(book1);
    library.addBook(book2);
    library.displayBooks();

    std::cout << "\n=== 2. Library System (Swapped to SMS via DIP) ===\n";
    SmsNotificationService smsNotifier;
    Library smsLibrary(dbRepo, smsNotifier, consoleDisplay);
    smsLibrary.addBook(Book("1984", "George Orwell"));
    smsLibrary.displayBooks();
}

void runGildedRoseDemo() {
    std::cout << "\n=== Gilded Rose Inventory Simulation ===\n";
    std::vector<Item> items = {
        Item("+5 Dexterity Vest", 10, 20),
        Item("Aged Brie", 2, 0),
        Item("Sulfuras, Hand of Ragnaros", 0, 80),
        Item("Backstage passes to a TAFKAL80ETC concert", 5, 45),
        Item("Conjured Mana Cake", 3, 10)
    };

    GildedRose app(items);

    std::cout << "--- Day 0 ---\n";
    for (const auto& item : items) {
        std::cout << item.name << ", sellIn: " << item.sellIn
                  << ", quality: " << item.quality << '\n';
    }

    app.updateQuality();

    std::cout << "--- Day 1 (after updateQuality) ---\n";
    for (const auto& item : items) {
        std::cout << item.name << ", sellIn: " << item.sellIn
                  << ", quality: " << item.quality << '\n';
    }
}

int main() {
    runLibraryDemo();
    runGildedRoseDemo();
    return 0;
}
