#ifndef PILA_H
#define PILA_H

// inizializza P1 e P2 con un'array o una lista 
// doppiamente concatenata con dimensione massima 
// 'dim'. Di conseguenza, la somma del numero di 
// elementi in P1 e P2 può essere al massimo uguale 
// a 'dim';
void init(int dim);

// inserisci l'elemento 'valore' in P1
bool pushP1(float valore);

// inserisci l'elemento 'valore' in P2
bool pushP2(float valore);

// assegna al parametro il valore del primo 
// elemento di P1, se presente
bool topP1(float&);

// assegna al parametro il valore del primo 
// elemento di P2, se presente
bool topP2(float&);

// rimuovi il primo elemento di P1, se presente
bool popP1();

// rimuovi il primo elemento di P2, se presente
bool popP2();

// de-inizializza la pila e dealloca la memoria dinamica
void deinit();

// stampa a video gli elementi di P1 e P2
void print();

#endif