#pragma once
#include <iostream>
#include "IBookRepository.h"
#include "INotificationService.h"
#include "IBookDisplay.h"

class DatabaseBookRepository : public IBookRepository {
public:
    void save(const Book& book) override {
        std::cout << "Saving book to database... [" << book.getTitle() << "]\n";
    }
};

class EmailNotificationService : public INotificationService {
public:
    void notify(const Book& book) override {
        std::cout << "Sending email notification about the new book...\n";
    }
};

class SmsNotificationService : public INotificationService {
public:
    void notify(const Book& book) override {
        std::cout << "Sending SMS notification about the new book... ["
                  << book.getTitle() << "]\n";
    }
};

class ConsoleBookDisplay : public IBookDisplay {
public:
    void show(const Book& book) const override {
        std::cout << "Title: " << book.getTitle()
                  << ", Author: " << book.getAuthor() << '\n';
    }
};
