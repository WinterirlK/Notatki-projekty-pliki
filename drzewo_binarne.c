#include <stdio.h>
#include <stdlib.h>

struct Tree{
	int value;
	struct Tree* left, *right, *parent;
};

int find_r (struct Tree* tree, int key);
int find_i (struct Tree* tree, int key);
struct Tree* insert_r(struct Tree* tree, int value);
struct Tree* insert_i(struct Tree* tree, int value);
void delete(struct Tree* tree, int key);
void printTree(struct Tree* tree);

int main(){
	struct Tree* tree;
	tree = insert_i(tree, 10);
	tree = insert_i(tree, 2);
	tree = insert_i(tree, 1);
	tree = insert_i(tree, 15);
	tree = insert_i(tree, 16);
	tree = insert_i(tree, 12);
	tree = insert_i(tree, 15);
	tree = insert_i(tree, 20);
	tree = insert_i(tree, 18);
	tree = insert_i(tree, 19);

	printTree(tree);

	printf("\n%d %d %d %d %d %d\n", find_r(tree, 10), find_r(tree, 2), find_r(tree, 1), find_r(tree, 15), find_r(tree, 16), find_r(tree, 0));
	printf("%d %d %d %d %d %d\n", find_i(tree, 10), find_i(tree, 2), find_i(tree, 1), find_i(tree, 15), find_i(tree, 16), find_i(tree, 0));

	delete(tree, 16);
	printTree(tree);
	putchar('\n');
	
	return 0;
}

int find_r (struct Tree* tree, int key){
	if (tree == NULL)
		return 0;

	if (tree->value == key)
		return 1;
	else {
		if (key < tree->value)
			return find_r(tree->left, key);
		else // key > tree->value
			return find_r(tree->right, key);
	}
}
int find_i (struct Tree* tree, int key){
	while (tree != NULL){
		if (tree->value == key)
			return 1;
		else {
			if (key < tree->value)
				tree = tree->left;
			else // key > tree->value
				tree = tree->right;
		}
	}
	return 0;
}

struct Tree* insert_r(struct Tree* tree, int value){
	if (tree == NULL){
		tree = (struct Tree*) calloc(1, sizeof (struct Tree));
		tree->value = value;

		return tree;
	}
	// tree != NULL
	if (value < tree->value)
		tree->left = insert_r(tree->left, value);
	else // value >= tree->value
		tree->right = insert_r(tree->right, value);

	return tree;
}
struct Tree* insert_i(struct Tree* tree, int value){
	if (tree == NULL){
		tree = (struct Tree*) calloc(1, sizeof (struct Tree));
		tree->value = value;

		return tree;
	}

	struct Tree* tmp = tree;
	struct Tree* new = (struct Tree*) calloc(1, sizeof (struct Tree));
	new->value = value;

	for (;;){
		if (value < tmp->value){
			if (tmp->left == NULL){
				tmp->left = new;
				break;
			}
			else
				tmp = tmp->left;
		}
		else { // value >= tmp->value
			if (tmp->right == NULL){
				tmp->right = new;
				break;
			}
			else
				tmp = tmp->right;
		}
	}
	new->parent = tmp;

	return tree;
}

void delete(struct Tree* tree, int key){
start:
	while (tree != NULL  &&  tree->value != key){
		if (key < tree->value)
			tree = tree->left;
		else // key >= tree->value
			tree = tree->right;
	}

	if (tree == NULL)
		return;

	if (tree->left == tree->right){ // == NULL
		if (tree->parent == NULL){
			free(tree);
			return;
		}
		tree = tree->parent;
		if (key < tree->value){
			free(tree->left);
			tree->left = NULL;
		}
		else { // key >= tree->value
			free(tree->right);
			tree->right = NULL;
		}
		
		return;
	}
	if (tree->left == NULL){
		if (tree->parent == NULL){
			tree->value = tree->right->value;
			tree->left = tree->right->left;
			tree->right = tree->right->right;
			free(tree->right);
			return;
		}
		struct Tree* tmp;
		tmp = tree->right;
		tree = tree->parent;
		if (key < tree->value){
			free(tree->left);
			tree->left = tmp;
		}
		else { // key >= tree->value
			free(tree->right);
			tree->right = tmp;
		}

		return;
	}
	if (tree->right == NULL){
		if (tree->parent == NULL){
			tree->value = tree->left->value;
			tree->left = tree->left->left;
			tree->right = tree->left->right;
			free(tree->left);
			return;
		}
		struct Tree* tmp;
		tmp = tree->left;
		tree = tree->parent;
		if (key < tree->value){
			free(tree->left);
			tree->left = tmp;
		}
		else { // key >= tree->value
			free(tree->right);
			tree->right = tmp;
		}

		return;
	}
	// tree->left != NULL  &&  tree->right != NULL
	struct Tree* tmp = tree;
	tmp = tmp->right;
	while (tmp->left != NULL)
		tmp = tmp->left;

	tree->value = tmp->value;
	
	//delete(tmp, tmp->value);
	tree = tmp;
	key = tmp->value;
	goto start;	
}

void printTree(struct Tree* tree){
	if (tree != NULL){
		printTree(tree->left);
		printf("%d ", tree->value);
		printTree(tree->right);
	}
}
