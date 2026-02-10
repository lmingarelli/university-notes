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
    struct node *new = malloc(sizeof(*new));
    new->left = new->right = NULL;
    new->val = val;

    if (root == NULL) return new;

    if (root->left && root->right) {
        printf("Add node error: root already has 2 childs");
        return 1;
    }

    if (val >= root->val) {
        if (root->right) {
            printf("Add node error: root already has a right child");
            return 1;
        }
        root->right = new;
    } else {
         if (root->left) {
            printf("Add node error: root already has a left child");
            return 1;
        }
        root->left = new;
    }

    return root;
}

int main () {
    struct node *root = NULL;

    root = add_node(root, 10);

    return 0;
}
