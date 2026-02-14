#include <iostream>
#include "coda.h"

using namespace std;

const int MAX_DIM = 15;
static int q[MAX_DIM];
static int indiceS1;
static int indiceS2;



/** La coda, appena inizializzata, è vuota */
void init() {
    indiceS1 = -1;
    indiceS2 = MAX_DIM;
}



/** 
 * Inseriamo il nuovo elemento nella
 * sottocoda con meno elementi 
 */
bool enqueue(int n) {
    bool risultatoOperazione = true;

    /** 
     * Calcoliamo il numero di elementi al 
     * momento presenti nelle due sottocode
     */
    int numeroElementiS1 = indiceS1 + 1;
    int numeroElementiS2 = MAX_DIM - indiceS2;

    if (numeroElementiS1 + numeroElementiS2 == MAX_DIM) {
        cout << "Entrambe le sottocode sono piene!" << endl;
        risultatoOperazione = false;
    } else {
        if (numeroElementiS1 <= numeroElementiS2) {
            indiceS1++;
            q[indiceS1] = n;
        } else {
            indiceS2--;
            q[indiceS2] = n;
        }
    }
    return risultatoOperazione;
}



/** 
 * Ritorna il primo elemento della 
 * sottocoda S1, se presente 
 */
bool firstS1(int& n) {
    bool risultatoOperazione = true;
    if (indiceS1 == -1) {
        risultatoOperazione = false;
    } else {
        n = q[0];
    }
    return risultatoOperazione;
}



/** 
 * Ritorna il primo elemento della 
 * sottocoda S2, se presente 
 */
bool firstS2(int& n) {
    bool risultatoOperazione = true;
    if (indiceS2 == MAX_DIM) {
        risultatoOperazione = false;
    } else {
        n = q[MAX_DIM-1];
    }
    return risultatoOperazione;
}



/** 
 * Rimuoviamo il primo elemento della sottocoda S1, 
 * e facciamo scorrere gli altri, riducendo poi di
 * 1 il numero di elementi nella sottocoda S1 
 */
bool dequeueS1() { 
    bool risultatoOperazione = true;
    if (indiceS1 == -1) {
        risultatoOperazione = false;
    }
    else {
        for (int i = 0; i < indiceS1; i++) {
            q[i] = q[i+1];
        }
        indiceS1--;
    }
    return risultatoOperazione;
}



/** 
 * Rimuoviamo il primo elemento della sottocoda S2, 
 * e facciamo scorrere gli altri, riducendo poi di
 * 1 il numero di elementi nella sottocoda S2
 */
bool dequeueS2() { 
    bool risultatoOperazione = true;
    if (indiceS2 == MAX_DIM) {
        risultatoOperazione = false;
    }
    else {
        for (int i = MAX_DIM-1; i > indiceS2; i--) {
            q[i] = q[i-1];
        }
        indiceS2++;
    }
    return risultatoOperazione;
}



/** 
 * Rimuoviamo ogni elemento presente 
 * nelle due sottocode S1 e S2 
 */
void deinit() {
    // In questa implementazione, la funzione 'deinit()' è vuota
}



/** 
 * Stampa le due sottocode mostrando 
 * anche gli spazi vuoti ancora disponibili
 */
void print() {
    if (indiceS1 == -1) {
        cout << "La sottocoda S1 è vuota!" << endl;
    } else {
        cout << "S1: ";
        for (int i = 0; i <= indiceS1 ; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
    
    if (indiceS2 == MAX_DIM) {
        cout << "La sottocoda S2 è vuota!" << endl;
    } else {
        cout << "S2: ";
        for (int i = MAX_DIM-1; i >= indiceS2 ; i--) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
}