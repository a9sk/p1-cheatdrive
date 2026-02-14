#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAXVALUE 100
#define MAXSIZE 30

// NON MODIFICARE IL CODICE SOTTO FINO A "NON MODIFICARE IL CODICE SOPRA"
struct list {
  double info;
  list * next;
};

struct tree {
  int info;
  tree * left;
  tree * right;
};

void insert(tree * & result, const int num) {
  if (result == NULL) {
    result = new tree;
    *result = {num, NULL, NULL};
  } else if (result->info < num) {
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

void print_tree_l(const tree * root){
  if (root != NULL) {
    print_tree_l(root->right);
    std::cout << " " << root->info;
    print_tree_l(root->left);
  }
}

void print_tree_t(tree * root, int spazio = 0){
  if (root != NULL) {
    spazio++;
    print_tree_t(root->right, spazio);

    for (int i = 1; i < spazio; i++) std::cout<<"  ";
    std::cout<<root->info<<"\n";
    print_tree_t(root->left, spazio);
  }
}

void delete_tree(tree * & root) {
  if (root != NULL) {
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
    root = NULL;
  }
}

void print_list(list * l) {
  for(; l != nullptr; l = l->next)
    std::cout << " " << l->info;
  std::cout << std::endl;
}

void delete_list(list * l) {
  for(; l != nullptr; ) {
    list * tmp = l;
    l = l->next;
    delete tmp;
  }
}

// NON MODIFICARE IL CODICE SOPRA

// Add hereafter the declaration of estrai
void calcola_lista_medie(const tree * root, list * & result);
// Add here above the declaration of estrai

// NON MODIFICARE IL MAIN
int main(int argc, char ** argv) {
  srand(unsigned(time(0)));
  //
  // Commentare la linea seguente per avere comportamento
  // non-deterministico
  //
  srand(0);
  tree * root = crea_tree(rand()%MAXSIZE);
  std::cout << "tree = " << std::endl;
  print_tree_t(root); std::cout << std::endl;
  list * result;
  calcola_lista_medie(root, result);
  delete_tree(root);
  std::cout << "result =";
  print_list(result);
  delete_list(result);
  std::cout << "-----------------------------------------------------------" << std::endl;
  root = nullptr;
  insert(root, 50);
  insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 10);
  std::cout << "tree = " << std::endl;
  print_tree_t(root); std::cout << std::endl;
  calcola_lista_medie(root, result);
  std::cout << "result =";
  print_list(result);
  delete_list(result);
  std::cout << "-----------------------------------------------------------" << std::endl;
  insert(root, 60);
  std::cout << "tree = " << std::endl;
  print_tree_t(root); std::cout << std::endl;
  calcola_lista_medie(root, result);
  std::cout << "result =";
  print_list(result);
  delete_list(result);
  delete_tree(root);
  std::cout << "-----------------------------------------------------------" << std::endl;
  root = nullptr;
  std::cout << "tree = " << std::endl;
  print_tree_t(root); std::cout << std::endl;
  calcola_lista_medie(root, result);
  std::cout << "result =";
  print_list(result);
  delete_list(result);
  delete_tree(root);
}
// NON MODIFICARE IL MAIN

// Add hereafter the definition of estrai

void calcola_lista_medie_aux(const tree * root, list * & result, double sum, int num) {
  if (root != nullptr) {
    if (root->info % 2 == 0) {
      num++;
      sum += root->info;
    }
    if (root->left == nullptr && root->right == nullptr) {
      // Caso base
      if (num != 0) {
        result = new list{sum/num, result};
      }
    } else if (root->left == nullptr) {
      // Caso base in cui left null e right != NULL, calcolo per nodo, e ricorro su right
      if (num != 0) {
        result = new list{sum/num, result};
      }
      calcola_lista_medie_aux(root->right, result, sum, num);
    } else if (root->right == nullptr) {
      // Caso base in cui right null e left != NULL, calcolo per nodo, e ricorro su left
      if (num != 0) {
        result = new list{sum/num, result};
      }
      calcola_lista_medie_aux(root->left, result, sum, num);
    } else {
      // Caso in cui entrambi != null, ricorro su entrambi
      calcola_lista_medie_aux(root->left, result, sum, num);
      calcola_lista_medie_aux(root->right, result, sum, num);
    }
  }
}

void calcola_lista_medie(const tree * root, list * & result) {
  result = nullptr;
  calcola_lista_medie_aux(root, result, 0.0, 0);
}

// Add here above the definition of estrai
