#include "stack.h"
#include <cstdlib>
#include <iostream>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione calcola 

// Inserire qui sopra la dichiarazione della funzione calcola 

int main() {
    Stack * s = init();
    // Esempio di utilizzo delle funzioni della pila
    push(s, 12);
    push(s, 23);
    push(s, 34);
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

// Inserire qui sopra la definizione della funzione calcola 