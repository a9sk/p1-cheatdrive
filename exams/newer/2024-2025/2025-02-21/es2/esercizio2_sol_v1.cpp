#include <iostream>
#include <cstring>


struct Key {
    int size;
    char *data;
};

const char data[][10] = {
    "0abc",
    "1def",
    "2ghi",
    "3jkl",
    "4mno",
    "5pqrs",
    "6tuv",
    "7wxyz",
    "8 .,@*=+-",
    "9"
};

// Inserire qui sotto la dichiarazione della funzione decode 
void decode(const char *str, int size, Key *keyboard) ;
// Inserire qui sopra la dichiarazione della funzione decode 


int main(int argc, char **argv){

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <string to decode>" << std::endl;
        return 1;
    }
    int size = strlen(argv[1]);
    for (int i = 0; i < size; i++)
    {
        if (argv[1][i] != ' ' && (argv[1][i] < '0' || argv[1][i] > '9')) {
            std::cerr << "Invalid character: " << argv[1][i] << std::endl;
            return 1;
        }
    }
    
    Key keyboard[10];
    // Populate the keyboard array
    for (int i = 0; i < 10; i++) {
        keyboard[i].size = strlen(data[i]);
        keyboard[i].data = new char[keyboard[i].size];
        strncpy(keyboard[i].data, data[i], keyboard[i].size);
    }

    std::cout << "Decoding string: \"" << argv[1] << "\"" << std::endl;
    std::cout << "Decoded string: \"";
    decode(argv[1], size, keyboard);
    std::cout << "\"" << std::endl;

    // Deallocate the memory
    for (int i = 0; i < 10; i++) {
        delete[] keyboard[i].data;
    }
}

// Inserire qui sotto la definizione della funzione decode
int count_keyboard(const char *str, int size, int pos, char c) {
    if (pos >= size || str[pos] == ' ' || str[pos] != c) {
        return 0;
    }
    return 1 + count_keyboard(str, size, pos + 1, c);
}

void decode_keyboard(Key keyboard, int count, int i, int pos) {
    if (i == count) {
        std::cout << keyboard.data[pos];
        return;
    }
    decode_keyboard(keyboard, count, i + 1, (pos + 1) % keyboard.size);
}

void decode_aux(const char *str, int size, Key *keyboard, int pos) {
    // We exceeded the size of the string
    if (pos >= size) {
        return;
    }
    if (str[pos] == ' ') {
        // It is a space, we can skip it
        decode_aux(str, size, keyboard, pos + 1);
    } else {
        // It is a digit, we need to decode it
        int key = str[pos] - '0';
        int count = count_keyboard(str, size, pos, str[pos]);
        decode_keyboard(keyboard[key], count, 1, 0);
        decode_aux(str, size, keyboard, pos + count);
    }
}

void decode(const char *str, int size, Key *keyboard) {
    decode_aux(str, size, keyboard, 0);
}

// Inserire qui sopra la definizione della funzione decode

