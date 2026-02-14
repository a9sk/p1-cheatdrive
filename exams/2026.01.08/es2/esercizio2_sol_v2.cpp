#include <iostream>
#include <cstdlib>

using namespace std;

enum Colore { ROSSO, VERDE, BLU, GIALLO };

struct Lista {
    Colore tile;
    Lista* next;
};

struct Pavimento {
    double lunghezza;
    double larghezza;
    Lista ** area;
};


void PrintPavimento(const Pavimento & p, double tile_size) {
    int rows = int(p.lunghezza / tile_size);
    
    for (int i = 0; i < rows; ++i) {
        double v = p.larghezza;
        Lista* current = p.area[i];
        while (current != nullptr) {
            v = v - tile_size;
            switch (current->tile) {
                case ROSSO: cout << "R"; break;
                case VERDE: cout << "G"; break;
                case BLU: cout << "B"; break;
                case GIALLO: cout << "Y"; break;
            }
            current = current->next;
        }
        cout << " " << v << endl;
    }
    cout << (p.lunghezza - rows * tile_size) << endl;
}

// Inserire qui sotto la dichiarazione della funzione ricorsiva CalcolaPavimento

void CalcolaPavimento(Pavimento & p, double tile_size);

// Inserire qui sopra la dichiarazione della funzione ricorsiva CalcolaPavimento

int main(int argc, char* argv[]) {
    Pavimento pavimento;
    pavimento.lunghezza = 15.0;
    pavimento.larghezza = 15.0;

    if (argc != 4) {
        cerr << "Usage: " << argv[0] << " <length> <width> <tile_size>" << endl;
        return 1;
    }

    double length = atof(argv[1]);
    double width = atof(argv[2]);
    double tile_size = atof(argv[3]);

    if (tile_size <= 0.0) {
        cerr << "Tile size must be a positive number." << endl;
        return 1;
    }

    if (length <= 0.0 || width <= 0.0) {
        cerr << "Length and width must be positive numbers." << endl;
        return 1;
    }

    pavimento.lunghezza = length;
    pavimento.larghezza = width;

    if (tile_size <= 0.0) {
        cerr << "Tile size must be a positive number." << endl;
        return 1;
    }

    CalcolaPavimento(pavimento, tile_size);

    PrintPavimento(pavimento, tile_size);

    // Clean up memory
    int rows = int(pavimento.lunghezza / tile_size);
    for (int i = 0; i < rows; ++i) {
        Lista* current = pavimento.area[i];
        while (current != nullptr) {
            Lista* to_delete = current;
            current = current->next;
            delete to_delete;
        }
    }
    delete[] pavimento.area;
    return 0;
}

// Inserire qui sotto la definizione della funzione ricorsiva CalcolaPavimento

void FillRow(Lista* & row_head, double width, double tile_size) {
    if (width < 0.0) {
        return;
    }
    if (3 * tile_size <= width) {
        Lista* new_tile = new Lista{VERDE, new Lista{GIALLO, new Lista{BLU, row_head}}};
        row_head = new_tile;
        FillRow(new_tile->next->next->next, width - 3 * tile_size, tile_size);
        return;
    }
}
void CalcolaPavimentoRecur(Pavimento & p, double tile_size, int row, int total_rows) {
    if (row >= total_rows) return;
    p.area[row] = nullptr;
    if (p.larghezza > tile_size) {
        p.area[row] = new Lista{BLU, nullptr};
        FillRow(p.area[row]->next, p.larghezza-tile_size, tile_size);
        CalcolaPavimentoRecur(p, tile_size, row + 1, total_rows);
    }
}

void CalcolaPavimento(Pavimento & p, double tile_size) {
    int rows = int(p.lunghezza / tile_size);
    p.area = new Lista*[rows];
    CalcolaPavimentoRecur(p, tile_size, 0, rows);
}
// Inserire qui sopra la definizione della funzione ricorsiva CalcolaPavimento