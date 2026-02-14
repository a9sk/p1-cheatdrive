// Allowed include 
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>

// Add your code hereafter

int Contaparole(char * testo[]) {
    int n = 0;
    for (int i = 0; i < 5000 && testo[i] != nullptr; i++,n++) {}
    return n;
}

void Generaraparole(char * testo[], int n, char word[])
{
  int i = 0;
  for (i = 0; i < 6; i++) {
    word[i] = *(testo[std::max(0,(rand() % n)-1)]);
  }
  word[i] = '\0';
}

int main (int argc, char * argv[]) {
    // Check the number of parameters
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    // Open the input
    std::ifstream input_file(argv[1], std::ios::in);

    if (input_file.fail()) {
        std::cerr << "Cannot open the input file \"" << argv[1] << "\"" << std::endl;
        return 1;
    }

    char text[5000] = {0};
    char * pword[5000] = {nullptr};

    int i = 0;
    int npwords = 0;
    char c, pc = ' ';
    while (input_file.get(c) && !input_file.eof() && i < 5000) {
        text[i] = c;
        if (pc == ' ' && ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
            pword[npwords++] = &text[i];
        }
        pc = c;
        i++;
    }

    int n = Contaparole(pword);
    char gw[7] = {0};
    Generaraparole(pword, n, gw);
    std::cout << "Text: " << text << std::endl;
    std::cout << "Number of words: " << n << std::endl;
    std::cout << "Initials: ";
    for (int k = 0; k < npwords; k++) {
        std::cout << *(pword[k]);
    }
    std::cout << std::endl;
    std::cout << "Generated word: " << gw << std::endl;
    input_file.close();
    return 0;
}