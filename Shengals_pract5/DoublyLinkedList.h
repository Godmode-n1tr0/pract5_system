#pragma once

class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* prev;
        Node* next;
        Node(int value) : data(value), next(nullptr), prev(nullptr) {} 
    };

    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void push_front(int value);
    void push_back(int value);
    void pop_front();
    void pop_back();
    void display();

    void sort();
    void remove_duplicates();
    bool isEmpty();
};