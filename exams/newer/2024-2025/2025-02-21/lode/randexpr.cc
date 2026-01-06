#ifndef RXP_H
#define RXP_H

#include <random>

using namespace std;

int random(int min, int max) {
   static bool init = false;
   int result;
   if (!init) { srand(time(NULL)); init = true; };
   result = (min+rand()%((max+1)-min));
   return result;
};

int randOperand() {
    int num = random(0, 999);
    return num;
};
char randOperator() {
    char op;
    int num = random(0, 3);
    switch (num) {
        case 0: op = '+'; break;
        case 1: op = '-'; break;
        case 2: op = '*'; break;
        case 3: op = '/'; break;
    };
    return op;
};
string randBlank() {
    int num = random(0, 5);
    string result="";
    return result.append(num, ' ');
};
string padded(int val) {
    string src=to_string(val);
    string tgt="";
    int l=src.length(), p, c;
    for (p=0; p<l; p++) {
        c=src[p];
        tgt.append(1, c);
        tgt.append(randBlank());
    };
    return tgt;
};

string randExpression(int& tot) {
    int num = random(3, 9), e;
    int val, sub = 0;
    char op;
    //
    val         = randOperand();
    string expr = padded(val);
    sub         = val;
    //
    for (e=0; e<num; e++) {
        expr.append(randBlank());
        //
        op = randOperator();
        expr.append(1, op);
        expr.append(randBlank());
        //
        val = randOperand();
        expr.append(padded(val));
        //
        if (op=='/' && val==0) val=1;
        switch (op) {
            case '+': sub += val; break;
            case '-': sub -= val; break;
            case '*': sub *= val; break;
            case '/': sub /= val; break;
        };
    };
    tot = sub;
    return expr;
};

#endif
