#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAXVALUE 100
#define MAXSIZE 100

typedef struct tree {
  int data;
  struct tree * left;
  struct tree * right;
} tree;

void insert(tree * & result, const int num) {
		if (result == NULL) {
				result = new tree;
				*result = {num, NULL, NULL};
		} else if (result->data > num) {
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

void print_tree(tree * root, int spazio = 0){
		if (root != NULL) {
				spazio++;
				print_tree(root->right, spazio);

				for (int i = 1; i < spazio; i++) std::cout<<"  ";
				std::cout<<root->data<<"\n";
				print_tree(root->left, spazio);
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

// Add hereafter the declaration of remove_element
tree * remove_element(tree * root, const int value);
// Add here above the declaration of remove_element

int main() {
		srand(unsigned(time(0)));
		//
		// Scommentare la linea seguente per avere comportamento
		// deterministico
		//
		srand(0);
		tree * root = crea_tree(rand()%MAXSIZE);

		std::cout << "Initial tree: " << std::endl;
		print_tree(root);
		std::cout << std::endl;
  int key = 84;
		std::cout << "removing: " << key << std::endl;
		root = remove_element(root, key);
  key = 77;
		std::cout << "removing: " << key << std::endl;
		root = remove_element(root, key);
  key = rand()%MAXVALUE;
		std::cout << "removing: " << key << std::endl;
		root = remove_element(root, key);
  key = rand()%MAXVALUE;
		std::cout << "removing: " << key << std::endl;
		root = remove_element(root, key);
  key = rand()%MAXVALUE;
		std::cout << "removing: " << key << std::endl;
		root = remove_element(root, key);
		std::cout << "removing: " << key << std::endl;
		root = remove_element(root, key);
		std::cout << "Final tree: " << std::endl;
		print_tree(root);
		std::cout << std::endl;
  delete_tree(root);
		return 0;
}


// Add hereafter the definition of compute_sum

// Compute the max successor value, i.e. the min on the right subtree
int successor(tree * root) {
  root = root->right;
  while (root->left != NULL) root = root->left;
  return root->data;
}

// Compute the min predecessor value, i.e. the max of the left subtree
int predecessor(tree * root) {
  root = root->left;
  while (root->right != NULL) root = root->right;
  return root->data;
}

                      // Removes the element with value
tree * remove_element(tree * root, const int value) {
  if (NULL != root) {
    if (root->data > value)
      root->left = remove_element(root->left, value);
    else if (root->data < value)
      root->right = remove_element(root->right, value);
    else { // root->data == value
      if (root->left == NULL && root->right == NULL) {
        delete root;
        root = NULL;
      } else if (root->right != NULL) {
        // current data is the min on the right subtree
        root->data = successor(root);
        // We remove the the min on the right subtree
        root->right = remove_element(root->right, root->data);
      } else { // root->left != NULL
        // current data is the max on the left subtree
        root->data = predecessor(root);
        // We remove the the max on the left subtree
        root->left = remove_element(root->left, root->data);
      }
    }
  }
  return root;
}

// Add here above the definition of compute_sum
