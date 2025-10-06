#include <iostream>
#include "DoublyLinkedList.h"
#include <conio.h>

using namespace std;

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    while (head != nullptr) {
        pop_front();
    }
}

void DoublyLinkedList::push_front(int value) {
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    cout << "������� " << value << " �������� � ������ ������.\n";
    _getch();
    system("cls");
}

void DoublyLinkedList::push_back(int value) {
    Node* newNode = new Node(value);

    if (tail == nullptr) {
        head = tail = newNode;
    }
    else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    cout << "������� " << value << " �������� � ����� ������.\n";
    _getch();
    system("cls");
}

void DoublyLinkedList::pop_front() {
    if (head == nullptr) {
        cout << "������ ����! ������ �������.\n";
        _getch();
        system("cls");
        return;
    }

    Node* temp = head;

    if (head == tail) {
        head = tail = nullptr;
    }
    else {
        head = head->next;
        head->prev = nullptr;
    }

    cout << "������� " << temp->data << " ������ �� ������ ������.\n";
    _getch();
    system("cls");
    delete temp;
}

void DoublyLinkedList::pop_back() {
    if (tail == nullptr) {
        cout << "������ ����! ������ �������.\n";
        _getch();
        system("cls");
        return;
    }

    Node* temp = tail;

    if (head == tail) {
        head = tail = nullptr;
    }
    else {
        tail = tail->prev;
        tail->next = nullptr;
    }

    cout << "������� " << temp->data << " ������ � ����� ������.\n";
    _getch();
    system("cls");
    delete temp;
}

void DoublyLinkedList::display() {
    if (head == nullptr) {
        cout << "������ ����!\n";
        _getch();
        system("cls");
        return;
    }

    Node* current = head;
    cout << "�������� ������: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    _getch();
    system("cls");
}

int DoublyLinkedList::size() {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

bool DoublyLinkedList::isEmpty() {
    return head == nullptr;
}

void DoublyLinkedList::sort() {
    if (head == nullptr || head == tail) {
        cout << "������ ���� ��� �������� ���� �������. ���������� �� ���������.\n";
        _getch();
        system("cls");
        return;
    }

    bool swapped;
    cout << "�������� ���������� ���������...\n";

    do {
        swapped = false;
        Node* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->data > current->next->data) {
                swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);

    cout << "������ ������������!\n";
    _getch();
    system("cls");
}

void DoublyLinkedList::remove_duplicates() {
    if (head == nullptr) {
        cout << "������ ����! ������ �������.\n";
        _getch();
        system("cls");
        return;
    }

    cout << "������� ���������...\n";
    int removedCount = 0;

    Node* current = head;

    while (current != nullptr && current->next != nullptr) {
        Node* runner = current;

        while (runner->next != nullptr) {
            if (runner->next->data == current->data) {
                Node* duplicate = runner->next;
                runner->next = runner->next->next;

                if (runner->next != nullptr) {
                    runner->next->prev = runner;
                }
                else {
                    tail = runner;
                }

                delete duplicate;
                removedCount++;
            }
            else {
                runner = runner->next;
            }
        }
        current = current->next;
    }

    cout << "������� " << removedCount << " ����������.\n";
    _getch();
    system("cls");
}