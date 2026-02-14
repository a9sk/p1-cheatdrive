#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAXVALUE 100
#define MAXSIZE 100

typedef struct tree {
		int value;
		struct tree * left;
		struct tree * right;
} tree;

void insert(tree * & result, const int num) {
		if (result == NULL) {
				result = new tree;
				*result = {num, NULL, NULL};
		} else if (result->value > num) {
				insert(result->left, num);
		} else {
				insert(result->right, num);
		}
}

tree * crea_tree(const int num) {
		tree * result = NULL;
		for(int i = 0; i < num; i++) {
				insert(result, rand()%MAXVALUE);
		}
		return result;
}

// void print_tree(tree * root, int spazio = 0);

void print_tree(tree * root, int spazio = 0){
		if (root != NULL) {
				spazio++;
				print_tree(root->right, spazio);

				for (int i = 1; i < spazio; i++) std::cout<<"  ";
				std::cout<<root->value<<"\n";
				print_tree(root->left, spazio);
		}
}

// Inserire qui sotto definizione e dichiarazione di insert_iter
void insert_iter(tree * & root, const int val);

void insert_iter(tree * & result, const int num) {
		// Uso l per attraversare l'albero e trovare posizione dove inserire
		// elemento
		tree * l = result;
		// Uso f per tenere traccia del padre ovvero del nodo al quale a
		// seconda del valore memorizzato in f devo inserire il nuovo
		// elemento (a destra o a sinistra)
		tree * f;
		while(l != NULL) {
				f = l; // Mi salvo il padre e a seconda del valore memorizzato nel
											// nodo corrente (similmente all ricorsione) scendo a
											// sinistra o a destra
				if (l->value > num) l = l->left;
				else l = l->right;
		}
		// Ho trovato il nodo dove inserire, quindi creo nuovo nodo
		tree * n = new tree{num, NULL, NULL};
		// Se l'albero era vuoto allora result deve essere il nuovo nodo
		if (l == result) result = n;
		// se il valore del padre di l (ovvero) f e' maggiore di num allora
		// inserisco a sinistra di f, altrimenti inserisco a destra
		// (implicito nella vesione ricorsiva)
		else if (f->value > num) f->left = n;
		else f->right = n;
}

// Inserire qui sopra definizione e dichiarazione di insert_iter

int main() {
		// srand(unsigned(time(0)));
		//
		// Scommentare la linea seguente per avere comportamento
		// deterministico
		//
		srand(0);
		tree * root = crea_tree(rand()%MAXSIZE);

		std::cout << "Initial tree: " << std::endl;
		print_tree(root);
		std::cout << std::endl;
		std::cout << "Inserting -1" << std::endl;
		insert_iter(root, -1);
		std::cout << "Inserting "<< MAXSIZE << std::endl;
		insert_iter(root, MAXSIZE);
		std::cout << "Inserting "<< MAXSIZE/2 << std::endl;
		insert_iter(root, MAXSIZE/2);
		std::cout << "Final tree: " << std::endl;
		print_tree(root);
		std::cout << std::endl;
		return 0;
}
