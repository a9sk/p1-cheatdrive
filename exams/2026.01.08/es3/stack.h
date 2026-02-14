typedef struct Stack_t Stack;

int pop(Stack * & s);
Stack * init();
void push(Stack * & s, int value);
void freeStack(Stack * & s);
int top(const Stack * s);
int isEmpty(const Stack * s);
void printStack(Stack *s); // Funzione per stampare la pila (opzionale)