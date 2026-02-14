#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// Inserire la dichiarazione qui sotto
int genera_k_mer(int k);
// Inserire la dichiarazione qui sopra

int main(int argc, char * argv[]) {
  if (argc != 2) {
    cout << "Formato accettato: " << argv[0] << " <numero_positivo> " << endl;
    exit(1);
  }
  int k = atoi(argv[1]);
  if (k <= 0) {
    cout << "Formato accettato: " << argv[0] << " <numero_positivo> " << endl;
  }
  cout << "Start" << endl;
  int count = genera_k_mer(k);
  cout << "Numero di k-mer generati: " << count << endl;
  cout << "Finish!" << endl;
  return 0;
}

// Inserire la definizione qui sotto


char convert(char c)
{
    if (c == 'A') return 'C';
    if (c == 'C') return 'G';
    if (c == 'G') return 'T';
    if (c == 'T') return 'A';
    return ' ';
}

int genera_k_mer(int k) {
  int len_str = 4;
  char s[k+1];
  char s_last[k+1];

  // Inizializzo s ad essere composto di sole A
  for (int i=0; i<k; i++) {
    s[i] = 'A';
  }
  s[k] = '\0';

  for (int i=0; i<k; i++) {
    s_last[i] = 'T';
  }
  s_last[k] = '\0';

  int counter = 1;
  while (strcmp(s, s_last) != 0) {
    counter ++;
    // You can uncomment the next line to see all k-mers.
    cout << s << endl;
    for (int i=0; i<k; i++) {
      if (s[i] == 'T') {
	s[i] = convert(s[i]);
      }
      else {
	s[i] = convert(s[i]);
	break;
      }
    }
  }

  // Stampa di ultimo k-mers (tutte T)
  cout << s << endl;
  return counter;
}

// Inserire la definizione qui sopra
