#ifndef RXP_H
#define RXP_H

#include <random>

using namespace std;

int random(int min, int max);
int randOperand();
char randOperator();
string randBlank();
string padded(int val);
string randExpression(int& tot);

#endif
