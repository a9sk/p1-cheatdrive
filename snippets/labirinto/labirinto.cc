#include <iostream>
#include "pila.h"

using namespace std;


/**
 * Ricordare che il file "pila.h" contiene la definizione 
 della struct "cella" (qui sotto riportata)
 * 
 * struct cella {
 *   int indiceRiga;
 *   int indiceColonna;
 * };
 */
void risolviLabirinto(int[][5], int, int);
cella* soluzione(int, int, int[][5],int, int, int, int);


int main(int argc, char* argv[]) {

    // Se modificate la funzione "main", ricordarsi poi di ripristinare 
    // il codice originale  

    // E' possibile modificare la matrice per effettuare dei test   
int labirinto[5][5] = {
    {1, 1, 0, 1, 1},
    {0, 1, 0, 1, 0},
    {1, 1, 1, 1, 1},
    {0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1}
};




    // E' possibile modificare la cella di arrivo per effettuare dei test 
    // (la cella di partenza invece è sempre [0,0])   
    cout<<"Percorso: ";
    risolviLabirinto(labirinto, 4, 0);
   
    return 0;
}

void risolviLabirinto(int labirinto[][5], int destR, int destC) {

    cella* percorso = soluzione(5, 5, labirinto, 0, 0, destR, destC);

    if (percorso[0].indiceRiga == -1 && percorso[0].indiceColonna == -1) {
        cout << "impossibile";
        return;
    }

    cella* ptr = percorso;
    int count = 0;

    while (ptr->indiceRiga != -1 && ptr->indiceColonna != -1 && count < 25) {
        if (count > 0) cout << ",";
        cout << "(" << ptr->indiceRiga << "," << ptr->indiceColonna << ")";
        ptr++;
        count++;
    }

    delete[] percorso;
}


//dfs con backtracking manuale dato che non si potevano usare 2 pile
cella* soluzione(int numRighe, int numColonne, int labirinto[][5],
                 int startR, int startC, int goalR, int goalC) {

    bool visitato[5][5] = {false};
    init();

    push({startR, startC});

    cella* percorso = new cella[numRighe * numColonne];
    for (int i = 0; i < numRighe * numColonne; i++)
        percorso[i] = {-1, -1};

    int lunghezzaPercorso = 0;
    int tentativiFalliti = 0;

    int deltaR[4] = {-1, 1, 0, 0};
    int deltaC[4] = {0, 0, -1, 1};

    while (!vuota()) {

        cella corrente;

        // backtracking
        if (tentativiFalliti == 4) {
            percorso[lunghezzaPercorso] = {-1, -1};
            lunghezzaPercorso--;

            corrente = {
                percorso[lunghezzaPercorso].indiceRiga,
                percorso[lunghezzaPercorso].indiceColonna
            };

            tentativiFalliti = 0;
        }
        else {
            top(corrente);
            pop();
            percorso[lunghezzaPercorso] = {corrente.indiceRiga, corrente.indiceColonna};
        }

        int r = corrente.indiceRiga;
        int c = corrente.indiceColonna;

        // fuori mappa
        if (r < 0 || r >= numRighe || c < 0 || c >= numColonne) {
            tentativiFalliti++;
            continue;
        }

        // muro o già visitato
        if (labirinto[r][c] == 0 || visitato[r][c]) {
            tentativiFalliti++;
            continue;
        }

        visitato[r][c] = true;
        lunghezzaPercorso++;
        tentativiFalliti = 0;

        // trovato
        if (r == goalR && c == goalC)
            return percorso;

        // espandi vicini
        for (int i = 0; i < 4; i++) {
            int nr = r + deltaR[i];
            int nc = c + deltaC[i];
            push({nr, nc});
        }
    }

    return new cella{-1, -1};
}
