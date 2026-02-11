// Binary Search Tree (BST)

#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *left, *right;
};

/* Add a new node, if root is NULL returns the new root
   (the first inserted node) otherwise it just returns
   the root passed by the user */
struct node *add_node(struct node *root, int val) {
    struct node *saved_root = root;
    struct node *new = malloc(sizeof(*new));
    new->left = new->right = NULL;
    new->val = val;

    if (root == NULL) return new;

    while (1) {
        if (val > root->val) {
            if (root->right == NULL) {
                root->right = new;
                return saved_root;
            }
            root = root->right;
        } else {
            if (root->left == NULL) {
                root->left = new;
                return saved_root;
            }
            root = root->left;
        }
    }
}

void print_sorted(struct node *root) {
    if (root == NULL) return;
    print_sorted(root->left);
    printf("%d\n", root->val);
    print_sorted(root->right);
}

void free_tree(struct node *root) {
    if (root == NULL) return;
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}

int main () {
    struct node *root = NULL;

    root = add_node(root, 10);
    root = add_node(root, 20);
    root = add_node(root, 30);
    root = add_node(root, 20);
    root = add_node(root, 15);
    root = add_node(root, 22);
    root = add_node(root, 20);

    print_sorted(root);

    free_tree(root);

    /* It will probably print the same thing as the previous print_sorted
       because the memory has been deallocated but it probably still
       resides in the memory as before.
       root has become a "dangling pointer".*/
    print_sorted(root);

    /* To be sure to not have a pointer pointing to a de-allocated
       memory portion we have to set root to NULL */
    root = NULL;
    print_sorted(root);

    return 0;
}
