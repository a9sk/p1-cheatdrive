#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

void sort_array(int * array, int len_array) {
  for (int i=0; i<len_array; i++) {
    for (int j=i+1; j<len_array; j++) {
      if (array[i] > array[j]) {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
      }
    }
  }
}

int main(int argc, char * argv []) {

  // Controllo che gli argomenti ci siano tutti
  if (argc != 4) {
    cout << "Usage: exercise1.out <input> <DIM> <N>" << endl;
    exit(1);
  }

  // Apro gli stream di lettura e scrittura
  fstream input, output;
  input.open(argv[1], ios::in);
  output.open("output.txt", ios::out);

  // Controllo che gli stream siano stati aperti correttamente
  if (input.fail() || output.fail()) {
    cout << "Errore nell'apertura degli stream!" << endl;
  }

  // Leggo le costanti per l'esercizio
  int DIM = atoi(argv[2]);
  int N = atoi(argv[3]);

  // Creo l'array
  int * lista = new int[DIM];

  // Leggo il file
  int buffer;
  int index = 0;
  while(input >> buffer) {
    lista[index] = buffer;
    index++;
  }

  // Ordino gli elementi in ordine crescente
  sort_array(lista, DIM);

  // Ritorno gli elementi della lista nell'ordine richiesto
  for (int i=DIM-1; i>=DIM-N; i--) {
    output << lista[i] << endl;
  }

  delete [] lista;

  input.close();
  output.close();

  return 0;

}
