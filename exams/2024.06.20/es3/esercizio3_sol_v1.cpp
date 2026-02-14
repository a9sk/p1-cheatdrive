#include <iostream>
#include <cstdlib>
#include <cassert>

// Non modificare questa parte sotto del codice
typedef struct Stack {
    int data;
    struct Stack * next;
} Stack;

struct Stack * initStack() {
    return nullptr;
}

bool isEmpty(struct Stack * s) {
    return (s == nullptr);
}

void push(struct Stack * &s, int value) {
    struct Stack * newElement = new Stack;
    newElement->data = value;
    newElement->next = s;
    s = newElement;
}

int top(struct Stack * s) {
    if (isEmpty(s)) {
        std::cerr << "Error: stack is empty" << std::endl;
        exit(1);
    }
    return s->data;
}

int pop(struct Stack * &s) {
    if (isEmpty(s)) {
        std::cerr << "Error: stack is empty" << std::endl;
        exit(1);
    }
    int value = s->data;
    struct Stack * temp = s;
    s = s->next;
    delete temp;
    return value;
}

void deleteStack(struct Stack * &s) {
    while (!isEmpty(s)) {
        pop(s);
    }
}

void printStack(struct Stack * s, const char * message = "Stack: ") {
    if (isEmpty(s)) {
        std::cout << "Stack is empty" << std::endl;
    } else {
        std::cout << message;
        struct Stack * temp = s;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
}
// Non modificare questa parte sopra del codice

// Inserire qui sotto la dichiarazione della funzione calcola
Stack * calcola(Stack *&s);
// Inserire qui sopra la dichiarazione della funzione calcola


int main() {
    struct Stack *s, *result;
    unsigned int seed = (unsigned int)time(NULL);
    // seed = 60000
    seed = 1697033220;
    srand(seed);

    s = initStack();
    for (int i = 0; i < 5; i++) {
        if (i != 2) push(s, 5-i);
    }
    printStack(s, "Original before: ");
    result = calcola(s);
    printStack(result, "Result of calcola: ");
    printStack(s, "Original after: ");
    deleteStack(s);
    deleteStack(result);

    s = initStack();
    for (int i = 0; i < 10; i++) {
        push(s, rand() % 10);
    }
    printStack(s, "Original before: ");
    result = calcola(s);
    printStack(result, "Result of calcola: ");
    printStack(s, "Original after: ");
    deleteStack(s);
    deleteStack(result);

    s = initStack();
    result = calcola(s);
    printStack(result, "Result of calcola: ");
    printStack(s, "Original after: ");
    deleteStack(s);
    deleteStack(result);

    return 0;
}

// Inserire qui sotto la definizione della funzione calcola
void calcolaRecur(Stack * & s, Stack * & result, int count[]) {
    if (isEmpty(s)) {
        return;
    }
    int value = pop(s);
    assert(value >= 0 && value <= 9);
    count[value]++;
    calcolaRecur(s, result, count);
    push(s, value);
    push(result, count[value]);
    count[value]--;
    push(result, value);
}

Stack * calcola(Stack * & s) {
    Stack * result = initStack();
    // Inizializzo il counter per ogni cifra a 0
    int count[10] = {0};
    calcolaRecur(s, result, count);
    return result;
}
// Inserire qui sopra la definizione della funzione stackOperator
