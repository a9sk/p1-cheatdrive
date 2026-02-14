#include "stack.h"
#include <cstdlib>
#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione calcola 
int calcola(Stack * & s);
// Inserire qui sopra la dichiarazione della funzione calcola 

int main() {
    Stack * s = init();
    // Esempio di utilizzo delle funzioni della pila
    push(s, 12);
    push(s, 23);
    push(s, 34);
    push(s, 10);
    printStack(s);
    int result = calcola(s);
    cout << "Risultato calcola: " << result << endl;
    printStack(s);
    freeStack(s);

    s = init();
    // Esempio di utilizzo delle funzioni della pila
    printStack(s);
    result = calcola(s);
    cout << "Risultato calcola: " << result << endl;
    printStack(s);
    freeStack(s);

    return 0;
}

// Inserire qui sotto la definizione della funzione calcola 
int prodOfDigits(int n) {
    if (n < 10) return n;
    return (n % 10) * prodOfDigits(n / 10);
}

int calcolaRecur(Stack * & s) {
    if (isEmpty(s)) {
        return 1;
    }
    int value = pop(s);
    int prod = prodOfDigits(value) * calcolaRecur(s);
    push(s, value);
    return prod;
}

int calcola(Stack * & s) {
    if (isEmpty(s)) {
        return 0;
    }
    return calcolaRecur(s);
}

// Inserire qui sopra la definizione della funzione calcola 
