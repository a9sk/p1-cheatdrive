
#include <cstdlib>
#include <iostream>

#include "stack.h"

using namespace std;

struct Stack_t {
    int value;
    Stack *next;
};


Stack * init() {
    Stack *s = nullptr;
    return s;
}

void push(Stack * & s, int value) {
    Stack *newNode = new Stack;
    newNode->value = value;
    newNode->next = s;
    s = newNode;
}

int pop(Stack * & s) {
    if (s == nullptr) {
        cerr << "ERROR: Stack vuoto" << endl;
        exit(EXIT_FAILURE);
    }
    Stack *temp = s;
    s = s->next;
    int value = temp->value;
    delete temp;
    return value;
}

int top(const Stack *s) {
    if (s == nullptr) {
        cerr << "ERROR: Stack vuoto" << endl;
        exit(EXIT_FAILURE);
    }
    return s->value;
}

int isEmpty(const Stack *s) {
    return s == nullptr;
}

void freeStack(Stack *&s) {
    if (s == nullptr) return;
    while (!isEmpty(s)) {
        pop(s);
    }
}

void printStack(Stack *s) {
    if (s == nullptr || isEmpty(s)) {
        cout << "Stack vuoto" << endl;
        return;
    }
    cout << "Contenuto della pila: ";
    while (s != nullptr) {
        cout << s->value << " ";
        s = s->next;
    }
    cout << endl;
}