#include <iostream>
#include <cstdlib>
#include "coda.h"

using namespace std;

int trovaIlVincitore(int n, int k);

int main(int argc, char * argv[]) {

    if (argc != 3) {
        cerr << "Usage: a./out <numeroDiAmici> <numeroDiSalti>" << endl;
        exit(0);
    }

    cout << "Il vincitore e' l'amico numero " << trovaIlVincitore(atoi(argv[1]), atoi(argv[2])) << endl;
}


// Implementare la funzione sottostante come da consegna:
// - 'numeroDiAmici' è il numero di amici, o anche chiamato 'n'
// - 'numeroDiSalti' è il numero di salti, o anche chiamato 'k' 
int trovaIlVincitore(int numeroDiAmici, int numeroDiSalti) {

    init();

    // Inseriamo tutti gli amici nella coda
    for (int i = 0 ; i < numeroDiAmici ; i++) {
        enqueue(i);
    }

    int vincitore;
    // Finchè c'è almeno un amico nella coda (notare come
    // l'ultimo amico che rimane nella coda è il vincitore)
    while (first(vincitore)) {
        int saltiRimanenti = numeroDiSalti;
        
        // Primo salto
        dequeue();
        enqueue(vincitore);
        
        // Salti successivi 
        while (saltiRimanenti > 1) {
            first(vincitore);
            dequeue();
            enqueue(vincitore);
            saltiRimanenti--;
        }

        // Dopo aver fatto tutti i salti,
        // eliminiamo l'amico a cui siamo arrivati
        dequeue();
    }

    deinit();

    return vincitore;
}
