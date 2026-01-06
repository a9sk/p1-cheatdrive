#ifndef QHT_H
#define QHT_H

#include <string>

using namespace std;

struct QHT_Node {
	int       value;
	QHT_Node* next;
};
typedef QHT_Node* QHTNode;

struct QHT {
    QHTNode tail;
    QHTNode head;
};

/* ---------------------------------------------------------------------------------------------------- */

// METODI CON RITORNO "void" (solo side-effects):
void qInit();         // INIZIALIZZA LA CODA
void qDrop();         // SVUOTA LA CODA
void qPrint();        // STAMPA LA CODA
void qPrint(string);  // STAMPA LA CODA seguita dalla stringa passata come argomento

// METODI CON RITORNO "bool" (true: ok, false: error/no)
// - "qEnqueue" è l'unico che prende un argomento considerato "input"
// - "qFirst" e "qDequeue" sono gli unici che prendono un argomento da usare come output
bool qEnqueue(int);   // AGGIUNGE IL VALORE PASSATO COME ARGOMENTO (IN INPUT) ALLA CODA
bool qFirst(int &);   // RESTITUISCE IL VALORE DEL PRIMO ELEMENTO DELLA CODA (SENZA RIMUOVERLO)
bool qDequeue();      // RIMUOVE IL PRIMO ELEMENTO DELLA CODA (SENZA RESTITUIRLO)
bool qDequeue(int &); // RIMUOVE IL PRIMO ELEMENTO DELLA CODA (RESTITUENDOLO IN OUTPUT NELL'ARGOMENTO)
bool qEmpty();        // VERIFICA SE LA CODA E' VUOTA
bool qStore(string);  // MEMORIZZA LA STRINGA "UN CARATTERE ALLA VOLTA" NELLA CODA

// METODI CON RITORNO "int" o "string"
int  qLength();       // RESTITUISCE LA LUNGHEZZA DELLA CODA
int  qCount(int);     // CONTA IL NUMERO DI OCCORRENZE NELLA CODA DELL'ARGOMENTO
string qExpr(int);    // RESTITUISCE LA RAPPRESENTAZIONE DELLA CODA COME STRINGA ELIMINANDO I DATI UGUALI ALL'ARGOMENTO

/* ---------------------------------------------------------------------------------------------------- */

#endif
