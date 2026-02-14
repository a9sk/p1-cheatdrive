#include <iostream>
#include <fstream>

using namespace std;

const int ngiorni = 28;
const int ncamere = 12;

const double costo_singola = 120.00;
const double costo_doppia = 150.00;
const double costo_famiglia = 230.00;

const int inizio_olimpiadi = 6;
const int fine_olimpiadi = 22;

struct Camera {
    int id;
    char tipologia;
    int nletti;
};

void calcola_tasso_occupazione(Camera[ncamere], int[ngiorni][ncamere], double[ngiorni]);
void calcola_ricavo_giornaliero(Camera[ncamere], int[ngiorni][ncamere], double[ngiorni]);
double calcola_incremento(Camera[ncamere], int[ngiorni][ncamere], double[ngiorni]);


int main() {

    Camera struttura_alberghiera[ncamere];
    int occupazione_camere[ngiorni][ncamere] = {0};


    fstream fin;
    fin.open("albergo.txt", ios::in);
    if (!fin) {
        cout << "Attenzione: il file albergo.txt non esiste" << endl;
        return -1;
    }
    // sappiamo dal testo che il file contiene tutti i dati e non ha errori
    for (int k = 0; k < ncamere; k++)
        fin >> struttura_alberghiera[k].id >> struttura_alberghiera[k].tipologia >> struttura_alberghiera[k].nletti;
    fin.close();

    fin.open("Febbraio.txt", ios::in);
    if (!fin) {
        cout << "Attenzione: il file occupazione.txt non esiste" << endl;
        return -1;
    }
    // sappiamo dal testo che il file contiene tutti i dati e non ha errori
    for (int i = 0; i < ngiorni; i++)
        for (int j = 0; j < ncamere; j++)
            fin >> occupazione_camere[i][j];
    fin.close();

    double tassi[ngiorni] = {0.0};
    double ricavig[ngiorni] = {0.0};

    calcola_tasso_occupazione(struttura_alberghiera, occupazione_camere, tassi);
    calcola_ricavo_giornaliero(struttura_alberghiera, occupazione_camere, ricavig);
    double incremento = calcola_incremento(struttura_alberghiera, occupazione_camere, ricavig);

    cout << "Tassi di occupazione: " << endl;
    for (int h = 0; h < ngiorni; h++)
        cout << "Giorno: " << h + 1 << ": " << tassi[h] << " "<< ricavig[h]<< endl;
    cout << "Incremento percentuale per Olimpiadi: " << incremento << endl;

    return 0;
}

void calcola_tasso_occupazione(Camera struttura[ncamere], int occupazione[ngiorni][ncamere], double tassi[ngiorni]) {
    int denominatore = 0;
    for (int k = 0; k < ncamere; k++)
        denominatore += struttura[k].nletti;

    for (int i = 0; i < ngiorni; i++) {
        int numeratore = 0;
        for (int j = 0; j < ncamere; j++)
            numeratore += occupazione[i][j];
        tassi[i] = double(numeratore) / double(denominatore);
    }
}

void calcola_ricavo_giornaliero(Camera struttura[ncamere], int occupazione[ngiorni][ncamere], double ricavig[ngiorni]) {
   
    for (int i = 0; i < ngiorni; i++){
        double ricavo = 0.0;
        for (int j = 0; j < ncamere; j++) {
            if (occupazione[i][j] > 0) {
                if (struttura[j].tipologia == 's')
                    ricavo += costo_singola;
                else if (struttura[j].tipologia == 'd')
                    ricavo += costo_doppia;
                else 
                    ricavo += costo_famiglia;
            }
    
    }
    ricavig[i] = ricavo;}
    
}

double calcola_incremento(Camera struttura[ncamere], int occupazione[ngiorni][ncamere], double ricavig[ngiorni]) {
    double ricavo_durante_olimpiadi = 0.0;
    double ricavo_altri_giorni = 0.0;
    for (int i = 0; i < ngiorni; i++) {
        
        if (i >= inizio_olimpiadi - 1 && i <= fine_olimpiadi - 1)
            ricavo_durante_olimpiadi += ricavig[i];
        else
            ricavo_altri_giorni += ricavig[i];
    }
    
    double incremento = -1.0;
    if (ricavo_altri_giorni > 0.0)
        incremento = (ricavo_durante_olimpiadi / ricavo_altri_giorni) * 100.0;
    return incremento;
}

