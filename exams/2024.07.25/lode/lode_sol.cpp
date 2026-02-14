#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>

typedef struct node {
    char var;
    struct node * Then;
    struct node * Else;
} node;

node * makeTrue() {
    node * res = new node;
    res->var = '1';
    res->Then = res->Else = nullptr;
    return res;
}

node * makeFalse() {
    node * res = new node;
    res->var = '0';
    res->Then = res->Else = nullptr;
    return res;
 }

 bool isTrue(const node * n) {
    return n != nullptr && n->var == '1' && n->Then == nullptr && n->Else == nullptr;
 }

bool isFalse(const node * n) {
    return n != nullptr && n->var == '0' && n->Then == nullptr && n->Else == nullptr;
}

node * makeVar(char v) {
    node * res = new node;
    res->var = v;
    res->Then = makeTrue();
    res->Else = makeFalse();
    return res;
}

node * makeNode(char v, node * t, node * e) {
    node * res = new node;
    res->var = v;
    res->Then = t;
    res->Else = e;
    return res;
}

char getVar(const node * n) {
    return n->var;
}

node * getThen(const node * n) {
    return n->Then;
}

node * getElse(const node * n) {
    return n->Else;
}

node * makeNot(node * n) {
    if (isTrue(n)) {
        return makeFalse();
    } else if (isFalse(n)) {
        return makeTrue();
    } else {
        return makeNode(n->var, makeNot(n->Then), makeNot(n->Else));
    }
}

void deleteNode(node * n) {
    if (n != nullptr) {
        deleteNode(n->Then);
        deleteNode(n->Else);
        delete n;
    }
}

void printNode(const node * n) {
    if (isTrue(n)) {
        std::cout << "1";
    } else if (isFalse(n)) {
        std::cout << "0";
    } else {
        std::cout << n->var << "(";
        printNode(n->Then);
        std::cout << ",";
        printNode(n->Else);
        std::cout << ")";
    }
}

node * makeCopy(const node * n) {
    if (isTrue(n)) {
        return makeTrue();
    } else if (isFalse(n)) {
        return makeFalse();
    } else {
        return makeNode(n->var, makeCopy(n->Then), makeCopy(n->Else));
    }
}

bool areEquivalent(const node * n, const node * m) {
    if (isTrue(n)) {
        return isTrue(m);
    } else if (isFalse(n)) {
        return isFalse(m);
    } else if (isTrue(m)) {
        return false;
    } else if (isFalse(m)) {
        return false;
    } else {
        return getVar(n) == getVar(m) && 
        areEquivalent(getThen(n), getThen(m)) && 
        areEquivalent(getElse(n), getElse(m));
    }
}

node * makeOperation(node * n, node * m) {
    // Base cases: n o m are true or false
    if (isFalse(n)) { // If n is false, return a copy of m
        return makeCopy(m);
    }
    if (isFalse(m)) { // If m is false, return a copy of n
        return makeCopy(n);
    }
    if (isTrue(m) || isTrue(n)) { // If m or n is false, return false
        return makeTrue();
    }
    // Inductive cases
    if (getVar(n) == getVar(m)) { // If n and m are the same, recursively call makeOperation on their Then and Else
        node * t = makeOperation(getThen(n), getThen(m));
        node * e = makeOperation(getElse(n), getElse(m));
        if (areEquivalent(t, e)) { // If the Then and Else are equivalent, return the Then
            deleteNode(e);
            return t;
        } else { // Otherwise, return makeNode on n's var and the Then and Else
            return makeNode(getVar(n), t, e);
        }
    }
    if (getVar(n) < getVar(m)) { // If n is less than m, return makeOperation on n and m's Else
        return makeNode(getVar(n), makeOperation(getThen(n), m), makeOperation(getElse(n), m));
    }
    // If n is greater than m, return makeOperation on n's Else and m
    return makeNode(getVar(m), makeOperation(n, getThen(m)), makeOperation(n, getElse(m)));
}

// Inserire qui sotto la dichiarazione della funzione getTruthValue

bool getTruthValue(const node * e, node * [], const int n);

// Inserire qui sopra la dichiarazione della funzione getTruthValue

int main()
{
    node *A = makeVar('A');
    node *B = makeVar('B');
    node *C = makeVar('C');
    node *D = makeVar('D');

    node *ass[4] = {C, B, A, D};
    for (int i = 0; i < 4; i++)
    {
        if (rand() % 2 == 0)
        {
            ass[i] = makeNot(ass[i]);
            std::cout << getVar(ass[i]) << "=" << "0";
        }
        else
        {
            ass[i] = makeCopy(ass[i]);
            std::cout << getVar(ass[i]) << "=" << "1";
        }
        if (i == 3)
            std::cout << std::endl;
        else
            std::cout << ", ";
    }

    node *notA = makeNot(A);
    node *AandB = makeNode('A', makeCopy(B), makeFalse());
    node *AorB = makeNode('A', makeTrue(), makeCopy(B));
    node *AandBorC = makeNode('A', makeNode('B', makeTrue(), makeCopy(C)), makeFalse());
    node *AorBandC = makeNode('A', makeTrue(), makeNode('B', makeCopy(C), makeFalse()));
    std::cout << "A & B := ";
    printNode(AandB);
    std::cout << " value = " << getTruthValue(AandB, ass, 4) << std::endl;
    std::cout << "A | B := ";
    printNode(AorB);
    std::cout << " value = " << getTruthValue(AorB, ass, 4) << std::endl;
    std::cout << "A & (B | C) := ";
    printNode(AandBorC);
    std::cout << " value = " << getTruthValue(AandBorC, ass, 4) << std::endl;
    std::cout << "A | (B & C) := ";
    printNode(AorBandC);
    std::cout << " value = " << getTruthValue(AandBorC, ass, 4) << std::endl;
    node *res[10] = {nullptr};
    res[0] = makeOperation(A, B);
    res[1] = makeOperation(notA, res[0]);
    res[2] = makeOperation(C, res[0]);
    res[3] = makeOperation(D, res[2]);
    res[4] = makeOperation(res[0], res[2]);
    res[5] = makeFalse();
    res[6] = makeOperation(notA, B);
    for (int i = 0; i < 10; i++)
    {
        if (res[i] == nullptr)
        {
            break;
        }
        std::cout << "res[" << i << "] := ";
        printNode(res[i]);
        std::cout << " value = " << getTruthValue(res[i], ass, 4) << std::endl;
        deleteNode(res[i]);
    }
    deleteNode(A);
    deleteNode(B);
    deleteNode(C);
    deleteNode(D);
    deleteNode(notA);
    deleteNode(AandB);
    deleteNode(AorB);
    deleteNode(AandBorC);
    deleteNode(AorBandC);
    for (int i = 0; i < 4; i++)
        deleteNode(ass[i]);
    return 0;
}

// Inserire qui sotto la definizione della funzione getTruthValue
void swap(node *&n1, node *&n2) {
    node *t = n1;
    n1 = n2;
    n2 = t;
}

void bubbleSort(node *ass[], const int n)
{
    for (int i = n-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (getVar(ass[j]) > getVar(ass[i]))
                swap(ass[i], ass[j]);
        }
    }
}

bool getTruthValueAux(const node *e, node *ass[], int i, int n)
{
    if (isTrue(e))
        return true;
    if (isFalse(e))
        return false;
    assert(getVar(e) == getVar(ass[i]));
    assert(i < n);
    if (isTrue(getThen(ass[i])))
        return getTruthValueAux(getThen(e), ass, i + 1, n);
    else
        return getTruthValueAux(getElse(e), ass, i + 1, n);
}

bool getTruthValue(const node *e, node *ass[], const int n)
{
    bool res = false;
    bubbleSort(ass, n);
    return getTruthValueAux(e, ass, 0, n);
}
// Inserire qui sopra la definizione della funzione getTruthValue

