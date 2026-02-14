#include<iostream>
#include<fstream>
using namespace std;

// Costanti
const int MAX_LENGTH = 256;

int main(int argc, char * argv []) {

  // Controllo che gli argomenti ci siano tutti
  if (argc != 3) {
    cout << "Usage: exercise1.out <input> <output>" << endl;
    exit(1);
  }

  // Apro gli stream di lettura e scrittura
  fstream input, output;
  input.open(argv[1], ios::in);
  output.open(argv[2], ios::out);

  // Controllo che gli stream siano stati aperti correttamente
  if (input.fail() || output.fail()) {
    cout << "Errore nell'apertura degli stream!" << endl;
  }

  // Creo il buffer e la variabile per la dimensione massima
  char buffer[MAX_LENGTH];
  char riga_massima [MAX_LENGTH];
  int dimensione_massima = -1;

  input.getline(buffer, MAX_LENGTH);
  while(!input.eof()) {

    // Calcolo la dimensione della stringa
    int dimensione = 0;
    while(buffer[dimensione] != '\0') {
      dimensione += 1;
    }

    // Aggiorna la stringa di dimensione massima
    if (dimensione > dimensione_massima) {
      for (int i=0; i<dimensione; i++) {
        riga_massima[i] = buffer[i];
      }
      // Aggiungo il carattere terminatore
      riga_massima[dimensione] = '\0';
      dimensione_massima = dimensione;
    }

    // Scrivo nell'output la dimensione corrente
    output << dimensione << endl;

    // Leggo la prossima riga
    input.getline(buffer, MAX_LENGTH);
  }

  // Come ultima cosa, scrivo nel file di output la riga massima
  // e la sua dimensione
  output << riga_massima << " " << dimensione_massima << endl;

  input.close();
  output.close();

  return 0;

}
