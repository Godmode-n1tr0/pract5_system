#include <iostream>
#include "DoublyLinkedList.h"
#include <conio.h>

using namespace std;

void displayMenu() {
    cout << "1. Добавить элемент в начало\n";
    cout << "2. Добавить элемент в конец\n";
    cout << "3. Удалить элемент с начала\n";
    cout << "4. Удалить элемент с конца\n";
    cout << "5. Отобразить список\n";
    cout << "6. Сортировать список\n";
    cout << "7. Удалить дубликаты\n";
    cout << "8. Размер списка\n";
    cout << "0. Выйти\n";
    cout << "Выберите опцию: ";
}

int main() {
    setlocale(0, "rus");
    DoublyLinkedList list;
    int choice, value;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            cout << "Введите значение для добавления в начало: ";
            cin >> value;
            system("cls");
            list.push_front(value);
            break;

        case 2:
            system("cls");
            cout << "Введите значение для добавления в конец: ";
            cin >> value;
            system("cls");
            list.push_back(value);
            break;

        case 3:
            system("cls");
            list.pop_front();
            break;

        case 4:
            system("cls");
            list.pop_back();
            break;

        case 5:
            system("cls");
            list.display();
            break;

        case 6:
            system("cls");
            list.sort();
            break;

        case 7:
            system("cls");
            list.remove_duplicates();
            break;

        case 8:
            system("cls");
            cout << "Размер списка: " << list.size() << " элементов\n";
            _getch();
            system("cls");
            break;

        case 0:
            system("cls");
            cout << "Выход из программы...\n";
            break;

        default:
            system("cls");
            cout << "Неверный выбор! Пожалуйста, попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}