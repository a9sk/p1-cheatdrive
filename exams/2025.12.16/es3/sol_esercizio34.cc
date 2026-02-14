#include <iostream>
#include <cstdlib>

struct nodo {
    int valore;
    nodo* nodoPrecedente;
    nodo* nodoSuccessivo;
};
typedef nodo* lista;

using namespace std;


void inizializza (int arrayDiInteri [], int dimensioneArray);
void stampaLista (lista nodoCorrente);

nodo* creaNodo (int cartaDaInserire);
lista creaLista (int arrayDiInteri [], int dimensioneArray);
lista rimuoviNodiAlternati (nodo* nodoIniziale);
void deallocaLista(lista nodoIniziale);

int main() { 

    int dimensioneArray = 8;
    int arrayDiInteri[dimensioneArray];
    inizializza(arrayDiInteri, dimensioneArray);

    lista nodoIniziale = creaLista(arrayDiInteri, dimensioneArray);

    cout << "Lista iniziale: ";
    stampaLista(nodoIniziale);

    nodoIniziale = rimuoviNodiAlternati(nodoIniziale);

    cout << "Risultato: ";
    stampaLista(nodoIniziale);
    deallocaLista(nodoIniziale);

    return 0;
}


void inizializza (int arrayDiInteri [], int dimensioneArray) {
    
    srand(time(NULL));

    for (int i = 0 ; i < dimensioneArray ; i++) {
        arrayDiInteri[i] = i % 3;
    }

    int contatore = dimensioneArray;
    while (contatore > 1) {
       int indice = rand() % contatore;
       contatore--;
       int temp = arrayDiInteri[contatore];
       arrayDiInteri[contatore] = arrayDiInteri[indice];
       arrayDiInteri[indice] = temp;
    }
}

nodo* creaNodo (int nodoDaInserire) {
    nodo* nodoAttuale = new nodo;
    nodoAttuale->valore = nodoDaInserire;
    nodoAttuale->nodoPrecedente = NULL;
    nodoAttuale->nodoSuccessivo = NULL;
    return nodoAttuale;
}

lista creaLista (int arrayDiInteri [], int dimensioneArray) {

    nodo* nodoIniziale;

    if (dimensioneArray > 0) {
        nodoIniziale = creaNodo(arrayDiInteri[0]);
        nodo* nodoPredecente = nodoIniziale;
        nodo* nodoCorrente = NULL;

        for (int i = 1 ; i < dimensioneArray ; i++) {
            nodoCorrente = creaNodo(arrayDiInteri[i]);
            nodoCorrente->nodoPrecedente = nodoPredecente;
            nodoPredecente->nodoSuccessivo = nodoCorrente;
            nodoPredecente = nodoCorrente;
        }
    }

    return nodoIniziale;
}

void stampaLista(nodo* nodoCorrente) {
    while (nodoCorrente != NULL) {
        cout << nodoCorrente->valore << " ";
        nodoCorrente = nodoCorrente->nodoSuccessivo;
    }
    cout << endl;
}

void deallocaLista(lista nodoCorrente) {
    while (nodoCorrente != NULL) {
        nodo* temp = nodoCorrente;
        nodoCorrente = nodoCorrente->nodoSuccessivo;
        delete temp;
    }
}



lista rimuoviNodiAlternati(nodo* nodoCorrente) {

    nodo* nodoIniziale = nodoCorrente;
    
    while (nodoCorrente != NULL) {

        nodo* nodoSuccessivo = nodoCorrente->nodoSuccessivo;
        nodo* nodoDaConfrontare = nodoSuccessivo == NULL ? NULL : nodoSuccessivo->nodoSuccessivo;
        nodo* nodoPrecedente = nodoCorrente->nodoPrecedente;

        if (nodoDaConfrontare != NULL && nodoCorrente->valore < nodoDaConfrontare->valore) {

            nodo* nodoDaRicollegare = nodoDaConfrontare->nodoSuccessivo;
            delete nodoDaConfrontare;
            delete nodoCorrente;

            if (nodoPrecedente != NULL) {  
                nodoPrecedente->nodoSuccessivo = nodoSuccessivo;
                nodoCorrente = nodoPrecedente->nodoPrecedente == NULL ? nodoPrecedente : nodoPrecedente->nodoPrecedente;
            }
            else {
                nodoCorrente = nodoSuccessivo;
                nodoIniziale = nodoCorrente;
            }

            nodoSuccessivo->nodoPrecedente = nodoPrecedente;
            nodoSuccessivo->nodoSuccessivo = nodoDaRicollegare;

            if (nodoDaRicollegare != NULL) {
                nodoDaRicollegare->nodoPrecedente = nodoSuccessivo;
            }
        }
        else {
            nodoCorrente = nodoSuccessivo;
        }
    }

    return nodoIniziale;
}
