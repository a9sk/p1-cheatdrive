#include <iostream>
#include "queue.h"
#include "randexpr.h"
#include "calc.h"

using namespace std;

/* ---------------------------------------------------------------------------------------------------- */

// DUMP:
// - riceve un'espressione (string) e il suo effettivo valore (int)
// - memorizza l'espressione nella coda
// - stampa la coda (corrisponde all'espressione ricevuta)
// - VALUTA L'ESPRESSIONE (FUNZIONE "calc") <---
// - ristampa la coda (dovrebbe corrispondere all'espressione ripulita degli spazi)
// - stampa un riscontro sugli spazi e tra il valore calcolato e quello fornito come effettivo
void dump(string expr="", int check=0) {
    int result = 0;
    string r1, r2, e1, e2;
    //
    qStore(expr); qPrint();        // memorizza l'espressione nella coda e stampa quest'ultima
    e1 = qExpr(' ');               // coda originale come stringa, ma senza spazi
    result = calc(); qPrint();     // elabora l'espressione e ristampa la coda (che dovrebbe essere ripulita degli spazi)
    e2 = qExpr(0);                 // coda rielaborata
    r1 = (result==check)?"T":"F";  // confronta il valore calcolato con quello atteso
    r2 = (e1==e2)?"T":"F";         // confronta la coda "come stringa" (e quindi con 0 spazi)
    cout << "[" << r1 << r2 << "]" << " " << result << " == " << check << endl << endl; // stampa responso
};

// MAIN:
// - NON riceve argomenti aggiuntivi
// - inizializza la coda
// - chiama DUMP con alcuni esempi predefiniti
// - chiama DUMP con alcuni esempi generati dinamicamente in modo pseudo-casuale
int main(int argc, char **argv) {
    cout << endl;
    //
    if (argc != 1) {
        cerr << "Usage: " << argv[0] << endl;
        exit(1);
    };
    qInit();

    // ------------------------------ //

    // Static sample(s):
    cout << endl << "STATIC SAMPLES:" << endl << "---------------" << endl;
    dump(""                   ,   0);
    dump("74"                 ,  74);
    dump("1  2 3 + 4 * 5    " , 635);
    dump("   20 + 7- 3/   2 " ,  12);
    dump("    1   0  /  0   " ,  10);

    // Dynamic sample(s)
    cout << endl << "DYNAMIC SAMPLES:" << endl << "-----------------" << endl;
    int n, num = 5, tot = 0; string expr;
    for (n=0; n<num; n++) {
        expr = randExpression(tot);
        dump(expr, tot);
    };

    // ------------------------------ //

    qDrop();
    return 0;
};

/* ---------------------------------------------------------------------------------------------------- */
