#include <iostream>
#include <fstream>

using namespace std;

struct nodo {
    int value;
    nodo* left;
    nodo* right;
};
typedef nodo* albero;


albero creaAlberoBilanciato(int array[], int dim);
void inserisciNodoBilanciato(albero & radice, int array[], int indiceBasso, int indiceAlto);
int leggiArray(int array[], char * file);
void ordinaArray(int array[], int dim);
void deallocaAlbero(albero radice);

void stampaAlbero(albero radice, int spazio=0);


int main() {

    /** Acquisizione del file */
    char file [31]; 
    cout << "Inserisci il percorso del file: ";
    cin >> file;

    /** Lettura del file */
    int array[100];
    int dim = leggiArray(array, file);
    cout << "L'array contiene " << dim << " elementi" << endl;

    /** Se non ci sono stati errori in lettura e il file non è vuoto */
    if (dim > 0) {

        /** Ordina l'array. La radice sarà l'elemento al centro dell'array */
        ordinaArray(array, dim);
        cout << "L'array ordinato è il seguente: ";
        for (int i = 0 ; i < dim ; i++) {
            cout << array[i] << " ";
        }
        cout << endl;

        /** Crea e dealloca l'albero bilanciato */
        albero radice = creaAlberoBilanciato(array, dim);
        cout << "Stampa albero: " << endl;
        stampaAlbero(radice);
        deallocaAlbero(radice);
    }

    return 0;
}

/** Ritorna -1 se errore, la dimensione dell'array altrimenti */
int leggiArray(int array[], char * file) {

    int dim = 0;
    fstream input;
    input.open(file, ios::in);
    if (input.fail()) {
        cout << "Errore in lettura" << endl;
        dim = -1;
    }
    else {
        int numero;
        while(input >> numero) {
            array[dim] = numero;
            dim++;
        }
    }

    return dim;
}

/** Ordina l'array in ordine crescente */
void ordinaArray(int array[], int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (array[i] < array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

/** Funzione base per la creazione dell'albero */
albero creaAlberoBilanciato(int array[], int dim) {
    albero radice = NULL;
    inserisciNodoBilanciato(radice, array, 0, dim-1);
    return radice;
}

/** Funzione ricorsive per la creazione dell'albero */
void inserisciNodoBilanciato(albero& radice, int array[], int indiceBasso, int indiceAlto) {
    if (indiceBasso <= indiceAlto) {
        int indiceMezzo = (indiceBasso + indiceAlto) / 2;
        radice = new nodo {array[indiceMezzo], NULL, NULL};
        inserisciNodoBilanciato(radice->left, array, indiceBasso, indiceMezzo - 1);
        inserisciNodoBilanciato(radice->right, array, indiceMezzo + 1, indiceAlto);
    }
}

/** Deallocazione dell'albero */
void deallocaAlbero(albero radice) {
    if (radice != NULL)  {
        deallocaAlbero(radice->left);
        deallocaAlbero(radice->right);
        delete radice;
    }
}

/** Stampa dell'albero */
void stampaAlbero(albero radice, int spazio){
    if (radice != NULL) {
        spazio ++;

        stampaAlbero(radice->right, spazio);

        for (int i = 1; i < spazio; i++) {
            cout<<"\t";
        }
        cout<<radice->value<<"\n";

        stampaAlbero(radice->left, spazio);
    }
}