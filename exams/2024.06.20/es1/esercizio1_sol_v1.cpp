#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

const int righe = 12;
const int colonne = 31;

struct Paziente
{
    float peso;
    int anni;
    int glicemia[righe][colonne];
};

int Monitora(Paziente, int, int, int, int &, double &, double &);

int main(int argc, char *argv[])
{

    Paziente p;
    int gipo;
    double media;
    double varianza;

    // controllo argomenti in input
    if (argc != 5)
    {
        cout << "Il numero di parametri e' diverso da 4. Errore!" << endl;
        exit(-1);
    }

    // apertura file
    fstream fin;
    fin.open(argv[1], ios::in);

    if (!fin)
    {
        cout << "Il file non esiste. Errore!" << endl;
        exit(1);
    }

    int mese = atoi(argv[2]);
    int ipo = atoi(argv[3]);
    int iper = atoi(argv[4]);

    // controllo ipo e iper
    if ((ipo > iper) || (ipo < 80) || (ipo > 95) || (iper < 105) || (iper > 120))
    {
        cout << "I valori di ipoglicemia e iperglicemia non sono corretti. Errore!" << endl;
        fin.close();
        exit(1);
    }
    // controllo mese
    if (mese < 1 || mese > 12)
    {
        cout << "Il mese non e' corretto. Errore!" << endl;
        fin.close();
        exit(1);
    }

    // lettura file e riempimento struttura
    fin >> p.peso;
    fin >> p.anni;

    for (int r = 0; r < righe; r++)
        for (int c = 0; c < colonne; c++)
            fin >> p.glicemia[r][c];

    fin.close();

    // chiamata a funzione Monitora
    int giper = Monitora(p, mese, ipo, iper, gipo, media, varianza);

    // stampa risultati
    cout << "Il numero di giorni di iperglicemia e': " << giper << endl
         << "il numero di giorni di ipoglicemia e': " << gipo << endl
         << "la media e': " << media << endl
         << "la varianza e': " << varianza << endl;

    return 0;
}

// funzione Monitora
int Monitora(Paziente p, int n, int ipo, int iper, int &gipo, double &media, double &varianza)
{

    int giper = 0;
    gipo = 0;
    double somma = 0;
    media = 0;
    double n_media_quadro = 0;
    double elem = 0;
    varianza = 0;

    for (int c = 0; c < colonne; c++)
    {
        if (p.glicemia[n - 1][c] > iper)
            giper++;
        if (p.glicemia[n - 1][c] < ipo)
            gipo++;
        somma = somma + p.glicemia[n - 1][c];
    }
    media = somma / colonne;

    somma = 0;

    n_media_quadro = colonne * pow(media, 2);

    for (int c = 0; c < colonne; c++)
    {
        elem = pow(p.glicemia[n - 1][c], 2);
        somma = somma + elem;
    }

    varianza = (somma - n_media_quadro) / colonne;

    return giper;
}
