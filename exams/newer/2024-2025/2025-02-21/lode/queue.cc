#include <iostream>
#include "queue.h"

using namespace std;

static QHT Q;

/* ---------------------------------------------------------------------------------------------------- */

void qInit() {
	Q.head = NULL;
};


bool qEmpty() {
	return (Q.head == NULL);
};


int qLength() {
	int result = 0;
	QHTNode node = Q.head;
	while (node!=NULL) { result++; node=node->next; };
	return result;
};


bool qEnqueue(int n) {
    bool result;
    QHTNode node = new (nothrow) QHT_Node;
    if (node==NULL) {
        result = false;
    } else {
        node->value = n;
        node->next  = NULL;
        if (qEmpty()) {
            Q.head = node;
        } else {
            Q.tail->next = node;
        };
        Q.tail = node;
        result = true;
    };
    return result;
};


bool qFirst(int &n) {
    bool result;
    if (qEmpty()) {
        result = false;
    } else {
        n      = Q.head->value;
        result = true;
    };
    return result;
};

bool qDequeue() {
	int tmp; return qDequeue(tmp);
};
bool qDequeue(int &n) {
    bool result;
    if (qEmpty()) {
        result = false;
    } else {
        QHTNode node = Q.head;
		n      = Q.head->value;
        Q.head = Q.head->next;
        delete node;
        result = true;
    };
    return result;
};

void qDrop() {
	int tmp;
	while(qDequeue(tmp));
};

void qPrint() {
	return qPrint("\n");
};
void qPrint(string endline="\n") {
	int len = qLength();
	cout << "(" << len << ")";
	if (len>0) {
		cout << ": " << '"';
		QHTNode node = Q.head;
		do {
			cout << char(node->value);
			node = node->next;
		} while (node != NULL);
		cout << '"';
	};
	cout << endline;
};

bool qStore(string expr="") {
	bool result = true;
	int    p     = 0;
    char   c     = '\0';
	qDrop();
	while (p < expr.length()) {
        c = expr[p++];
        result = result & qEnqueue(c);
    };
	return result;
};

int qCount(int key=' ') {
    int n = 0;
	QHTNode node = Q.head;
	while (node!=NULL) {
        if (node->value==key) n++;
        node=node->next;
    };
	return n;
};

string qExpr(int key=0) {
    string expr="";
    int n = 0;
	QHTNode node = Q.head;
	while (node!=NULL) {
        if (node->value!=key) expr += char(node->value);
        node=node->next;
    };
	return expr;
};

/* ---------------------------------------------------------------------------------------------------- */
