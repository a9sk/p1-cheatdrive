#include <iostream>
#include "pila_3.h"

using namespace std;

static double *p;
static int dimensione;
static int indiceP1;
static int indiceP2;



void init(int n) {
    dimensione = n;
    p = new double[n];
    indiceP1 = -1;
    indiceP2 = dimensione;
}


bool pushP1(double valore) {
    if (indiceP1 + 1 == indiceP2) {
        return false;
    } else {
        indiceP1++;
        p[indiceP1] = valore;
        return true;
    }
}


bool pushP2(double valore) {
    if (indiceP1 + 1 == indiceP2) {
        return false;
    } else {
        indiceP2--;
        p[indiceP2] = valore;
        return true;
    }
}


bool topP1(double& n) {
    if (indiceP1 == -1) {
        return false;
    } else {
        n = p[indiceP1];
        return true;
    }
}


bool topP2(double& n) {
    if (indiceP2 == dimensione) {
        return false;
    } else {
        n = p[indiceP2];
        return true;
    }
}


bool popP1() {
    if (indiceP1 == -1) {
        return false;
    } else {
        indiceP1--;
        return true;
    }
}


bool popP2() {
    if (indiceP2 == dimensione) {
        return false;
    } else {
        indiceP2++;
        return true;
    }
}


void deinit() {
    delete [] p;
}


void print() {
    if (indiceP1 == -1) {
        cout << "P1: vuota!" << endl;
    } else {
        cout << "P1: ";
        for (int i = 0; i <= indiceP1 ; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    
    if (indiceP2 == dimensione) {
        cout << "P2: vuota!" << endl;
    } else {
        cout << "P2: ";
        for (int i = dimensione-1; i >= indiceP2 ; i--) {
            cout << p[i] << " ";
        }
        cout << endl;
    }
}
