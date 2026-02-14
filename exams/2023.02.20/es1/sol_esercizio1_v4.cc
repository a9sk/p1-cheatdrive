#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
using namespace std;



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

  // Chiedo il valore di shifting
  int value;
  cout << "Inserire il valore di shifting: ";
  cin >> value;

  // Leggo
  char buffer[256];
  while(input >> buffer) {

    int start = 0;
    int end = strlen(buffer) - 1;

    char current = buffer[ start ];
    while ( ! ( current>='a' && current<='z' ) && ! ( current>='A' && current<='Z' ) && start < end ) {
      current = buffer[ ++start ];
    }
    current = buffer[ end ];
    while ( ! ( current>='a' && current<='z' ) && ! ( current>='A' && current<='Z' ) && start < end ) {
      current = buffer[ --end ];
    }
    
    for (int v=0; v<value; ++v) {
      char tmp = buffer[end];
      int i;
      for (i=end; i>start; --i) {
        buffer[i] = buffer[i-1];
      }
      buffer[i] = tmp;
    }
    
    for (int i=start; i<=end; ++i) {
      current = buffer[i];
      buffer[i] = ( ( current>='a' && current<='z' ) ? current - 'a' + 'A' : current );
    }

    output << buffer << " ";

  }

  input.close();
  output.close();

  return 0;

}
