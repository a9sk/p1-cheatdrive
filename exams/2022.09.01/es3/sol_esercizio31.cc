#include <iostream>
#include <string.h> // definisce la funzione "int strlen (const char * array);"
#include <math.h>   // definisce la funzione "int pow (base, esponente);"
#include "pila.h"   // fare riferimento al file "pila.h" per le funzioni esposte

using namespace std;

int decodificaNumero(char numeroCodificato []);

int main() { 
    int dimensioneMassima = 9;
    char numeroCodificato [dimensioneMassima];
    cout << "Inserisci l'array: ";
    cin >> numeroCodificato;
    int decodifica = decodificaNumero(numeroCodificato);
    cout << "Decodifica: " << decodifica << endl;
}


int decodificaNumero(char numeroCodificato []) {
    init();

    int decodifica = 0;
    int lunghezzaNumeroCodificato = strlen(numeroCodificato);
    int esponente = lunghezzaNumeroCodificato;
 
    for (int i = 0; i <= lunghezzaNumeroCodificato; i++) {
        push(i + 1);
 
        if (i == lunghezzaNumeroCodificato || numeroCodificato[i] == 'I') {
            while (!vuota()) {
                int temp;
                top(temp);
                decodifica = decodifica + temp * pow(10, esponente);
                esponente--;
                pop();
            }
        }
    }
 
    deinit();
    return decodifica;
}
