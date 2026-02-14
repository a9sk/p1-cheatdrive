#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

// Massimo numero di caratteri per parola + carattere terminatore
const int MAX_CHAR = 101;

int main(int argc, char * argv []) {

  // Controllo che gli argomenti ci siano tutti
  if (argc != 4) {
    cout << "Usage: exercise1.out <input> <order> <output>" << endl;
    exit(1);
  }

  // Apro gli stream di lettura e scrittura
  fstream in, out, order;
  in.open(argv[1], ios::in);
  order.open(argv[2], ios::in);
  out.open(argv[3], ios::out);

  // Controllo che gli stream siano stati aperti correttamente
  if (in.fail() || out.fail()) {
    cout << "Errore nell'apertura degli stream!" << endl;
  }

  // Inizializzo il buffer di lettura e il contatore
  char buffer[MAX_CHAR];

  // Leggo il numero di parole presenti nel file
  in >> buffer;
  int max_words = atoi(buffer);

  // Alloco il vocabolario dinamicamente
  char ** words = new char*[max_words];
  for (int i=0; i<max_words; i++) {
    words[i] = new char[MAX_CHAR];
  }

  // Leggo il file con le parole
  int counter = 0;
  while(in >> buffer) {
    strcpy(words[counter], buffer);
    counter++;
  }

  // Scrivo le parole nel file in output nell'ordine che ci viene presentato
  // dal secondo file preso in input
  while(order >> buffer) {
    int index = atoi(buffer);
    if (index >= max_words || index < 0) {
      out << "MANCANTE" << " ";
    } else {
      out << words[index] << " ";
    }
  }

  // Dealloco il vocabolario e termino l'esecuzione
  for (int i=0; i<max_words; i++) {
    delete words[i];
  }
  delete [] words;

  return 0;

}