#include <iostream>
#include <iomanip>

using namespace std;

// Inserire qui sotto la dichiarazione della funzione checkmatrix

// Inserire qui sopra la dichiarazione della funzione checkmatrix

void stampaMatrice(int** A, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << setw(2) << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 1) {
        cerr << "Usage: " << argv[0] << endl;
        return 1;
    }

    int N = 4;
    int ** A = new int * [N];
    for (int i = 0; i < N; ++i) {
        A[i] = new int[N];
    }
    int tempA[4][4] = {
        {1, 2, 3, 4},
        {5, 1, 2, 3},
        {6, 5, 1, 2},
        {7, 6, 5, 1}
    };
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            A[i][j] = tempA[i][j];
        }
    }

    cout << endl;
    stampaMatrice(A, N);
    
    if (checkmatrix(A, N)) {
        cout << "La matrice e' Toeplitz." << endl;
    } else {
        cout << "La matrice non e' Toeplitz." << endl;
    }

    A[1][2] = 9; // Modifica un elemento per rendere la matrice non Toeplitz
    cout << endl;
    stampaMatrice(A, N);
    
    if (checkmatrix(A, N)) {
        cout << "La matrice e' Toeplitz." << endl;
    } else {
        cout << "La matrice non e' Toeplitz." << endl;
    }

    N = 7;
    int ** B = new int * [N];
    for (int i = 0; i < N; ++i) {
        B[i] = new int[N];
    }
    int temB[7][7] = {
        {1, 2, 3, 4, 5, 6, 7},
        {8, 1, 2, 3, 4, 5, 6},
        {9, 8, 1, 2, 3, 4, 5},
        {0, 9, 8, 1, 2, 3, 4},
        {1, 0, 9, 8, 1, 2, 3},
        {2, 1, 0, 9, 8, 1, 2},
        {3, 2, 1, 0, 9, 8, 1}
    };

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            B[i][j] = temB[i][j];
        }
    }
    cout << endl;
    stampaMatrice(B, N);

    if (checkmatrix(B, N)) {
        cout << "La matrice e' Toeplitz." << endl;
    } else {
        cout << "La matrice non e' Toeplitz." << endl;
    }

    B[3][4] = 10; 
    cout << endl;
    stampaMatrice(B, N);
    
    if (checkmatrix(B, N)) {
        cout << "La matrice e' Toeplitz." << endl;
    } else {
        cout << "La matrice non e' Toeplitz." << endl;
    }

    for (int i = 0; i < 4; ++i) {
        delete[] A[i];
    }
    delete[] A;
    for (int i = 0; i < 4; ++i) {
        delete[] B[i];
    }
    delete[] B;

    return 0;
}


// Inserire qui sotto la definizione della funzione checkmatrix

// Inserire qui sopra la definizione della funzione checkmatrix