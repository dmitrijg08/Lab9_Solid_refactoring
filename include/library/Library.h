#pragma once
#include <vector>
#include "Book.h"
#include "IBookRepository.h"
#include "INotificationService.h"
#include "IBookDisplay.h"

class Library {
public:
    Library(IBookRepository& repository,
            INotificationService& notificationService,
            const IBookDisplay& bookDisplay)
        : repository_(repository),
          notificationService_(notificationService),
          bookDisplay_(bookDisplay) {}

    void addBook(const Book& book) {
        books_.push_back(book);
        repository_.save(book);
        notificationService_.notify(book);
    }

    void displayBooks() const {
        for (const auto& book : books_) {
            bookDisplay_.show(book);
        }
    }

    const std::vector<Book>& getBooks() const noexcept {
        return books_;
    }

private:
    std::vector<Book> books_;
    IBookRepository& repository_;
    INotificationService& notificationService_;
    const IBookDisplay& bookDisplay_;
};
