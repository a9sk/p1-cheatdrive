#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;



int main(int argc, char * argv []) {

  // Controllo che gli argomenti ci siano tutti
  if (argc != 2) {
    cout << "Usage: exercise1.out <input>" << endl;
    exit(1);
  }

  // Apro gli stream di lettura e scrittura
  fstream input;
  input.open(argv[1], ios::in);

  // Controllo che gli stream siano stati aperti correttamente
  if ( input.fail() ) {
    cout << "Errore nell'apertura degli stream!" << endl;
  }

  // Chiedo la stringa da ricercare
  char find[256];
  cout << "Inserire la sequenza di caratteri da ricercare: ";
  cin >> find;

  // Chiedo il valore di shifting
  int shift;
  cout << "Inserire il valore di shifting: ";
  cin >> shift;

  // Trasformo in minuscolo
  for (int i=0; i<strlen(find); i++) {
    char current = find[i];
    if ( current >='A' && current <= 'Z' ) {
      find[i] = current - 'A' + 'a';
    }
  }

  // Applico shifting sx
  for (int v=0; v<shift; ++v) {
    char tmp = find[0];
    int i;
    for (i=0; i<strlen(find)-1; ++i) {
      find[i] = find[i+1];
    }
    find[i] = tmp;
  }

  // Cerco
  int count = 0;
  char buffer[256];
  while(input >> buffer) {
    
    for ( int j=0; j<strlen(buffer); ++j ) {
      bool missmatch = false;
      for ( int i=0; i<strlen(find) && !missmatch; ++i ) {
        if ( buffer[j+i] != find[i] ) {
          // not matching
          missmatch = true;
        }
      }
      if ( ! missmatch ) {
        // found
        count++;
      }
    }
    
  }

  cout << "found " << count << " occurrences of " << find << endl; 

  input.close();

  return 0;

}
