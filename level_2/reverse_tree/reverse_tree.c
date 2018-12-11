struct s_node {
	int				value;
	struct s_node 	*right;
	struct s_node	*left;
};

void reverse_tree(struct s_node *root) {
	struct s_node *tmp;

	if (root) {
		tmp = root->right;
		root->right = root->left;
		root->left = tmp;
		if (root->left) reverse_tree(root->left);
		if (root->right) reverse_tree(root->right);
	}
}

#ifdef TESTING
#include <stdio.h>
#include <stdlib.h>
int	main(void) {
	struct s_node *tree;


	tree = (struct s_node*)malloc(sizeof(struct s_node));
	tree->value = 94;

	tree->left = (struct s_node*)malloc(sizeof(struct s_node));
	tree->left->value = 6;

	tree->left->left = (struct s_node*)malloc(sizeof(struct s_node));
	tree->left->left->value = 1;
	tree->left->left->left = NULL;
	tree->left->left->right = NULL;

	tree->left->right = (struct s_node*)malloc(sizeof(struct s_node));
	tree->left->right->value = 4;
	tree->left->right->left = NULL;
	tree->left->right->right = NULL;

	tree->right = (struct s_node*)malloc(sizeof(struct s_node));
	tree->right->value = -15;
	tree->right->left = NULL;
	tree->right->right = NULL;

	printf("%d -- %d\n", tree->left->left->value, tree->left->right->value);
	reverse_tree(tree);
	printf("%d -- %d\n", tree->right->right->value, tree->right->left->value);

	return (0);
}
#endif
