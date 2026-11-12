# Лабораторна робота №9 — Рефакторинг програмного коду та принципи SOLID (Варіант №2)

Репозиторій містить виконання лабораторної роботи №9 з дисципліни «Технології програмування та програмної інженерії» мовою C++20:
1. **Обов'язкове завдання:** Рефакторинг системи управління бібліотекою (`Book`, `Library`) із застосуванням принципів **SRP**, **OCP**, **LSP**, **ISP** та **DIP** (`IBookRepository`, `INotificationService`, `IBookDisplay`).
2. **Завдання Kata (Варіант №2 — Gilded Rose):** Рефакторинг успадкованого коду системи управління товарами за допомогою патернів **Strategy** та **Factory** (`IItemUpdater`, `BaseItemUpdater`, `ItemUpdaterFactory`) та реалізація індивідуального розширення для зачарованих товарів категорії `Conjured` (`ConjuredItemUpdater`).
3. **Модульне тестування:** Набір із 10 автоматизованих тестів на базі фреймворку `GoogleTest`.

## Структура проєкту

```text
SolidRefactoringLab9/
├── .gitignore
├── CMakeLists.txt
├── CMakePresets.json
├── vcpkg.json
├── include/
│   ├── library/
│   │   ├── Book.h
│   │   ├── IBookDisplay.h
│   │   ├── IBookRepository.h
│   │   ├── INotificationService.h
│   │   ├── Infrastructure.h
│   │   └── Library.h
│   └── gilded_rose/
│       ├── Item.h
│       ├── IItemUpdater.h
│       ├── ItemUpdaters.h
│       ├── ItemUpdaterFactory.h
│       └── GildedRose.h
├── src/
│   ├── GildedRose.cpp
│   └── main.cpp
└── tests/
    └── test_gilded_rose.cpp
```

## Збирання та запуск

### Через CMake + vcpkg
```bash
cmake --preset default
cmake --build build
./build/SolidRefactoringDemo
./build/GildedRoseTests
```
