// intlist.cpp
// Implements class IntList
// Emily Rodrigues, 10/16/2026

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    if ( source.head == nullptr ) {
        head = nullptr;
        tail = nullptr;
        return;
    }

    head = new Node{source.head->info, nullptr};
    tail = head;

    Node* cNew = head;
    Node* cOld = source.head->next;

    while (cOld != nullptr) {
            cNew->next = new Node{cOld->info, nullptr};

        cNew = cNew->next;
        tail = cNew;
        cOld = cOld->next;
        }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }

        head = nullptr;
        tail = nullptr;
}


// return sum of values in list
int IntList::sum() const {
    int total = 0;
    Node* current = head;
    while (current != nullptr){
        total += current->info;
        current = current->next;
    }
    return total; 
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* current = head;
    while (current != nullptr){ 
        if (current->info == value){
            return true;
        }
    current = current->next;  
    }
    return false; 
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (head == nullptr) 
    return 0;
    int maxVal = head->info;
    Node* current = head->next;
    while (current != nullptr) {
        if (current->info > maxVal) {
            maxVal = current->info;
        }
        current = current->next;
    }
    return maxVal;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (head == nullptr) {
        return 0.0;
    }
    double total = 0;
    int count = 0;
    Node* current = head;
    while (current !=nullptr) {
        total += current->info;
        count++;
        current = current->next;
    }
    return total / count;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = head;
    head = newNode;
    if (tail == nullptr) tail = head;
}

// append value at end of list
void IntList::push_back(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = nullptr;
    if (tail == nullptr) {
        head = newNode;
    } else {
        tail->next = newNode;
    }
    tail = newNode;
}

// return count of values
int IntList::count() const {
    int total = 0;
    Node* current = head;
    
    while ( current != nullptr) {
        total++;
        current = current->next;

    }

   return total;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source) return *this;   

    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;

    for (Node* p = source.head; p != nullptr; p = p->next) {
        push_back(p->info);
    }
    return *this;
}


// constructor sets up empty list
IntList::IntList(){
    head = nullptr;
    tail = nullptr;

}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

