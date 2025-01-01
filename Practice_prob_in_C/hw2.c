#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treenode {
    int data; /* integer field */
    struct treenode *left; /* pointer to the left child */
    struct treenode *right; /* pointer to the right child */
} node;

node *newNode(int data) {
    node *n = (node *)malloc(sizeof(node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

void findLeafSequence(node *root, int *sequence, int *size) {
    if (!root) return;
    if (!root->left && !root->right) {
        sequence[(*size)++] = root->data;
    }
    findLeafSequence(root->left, sequence, size);
    findLeafSequence(root->right, sequence, size);
}

bool areLeafSequencesEqual(node *root1, node *root2) {
    int sequence1[100], sequence2[100];
    int size1 = 0, size2 = 0;

    findLeafSequence(root1, sequence1, &size1);
    findLeafSequence(root2, sequence2, &size2);

    if (size1 != size2) return false;
    for (int i = 0; i < size1; i++) {
        if (sequence1[i] != sequence2[i]) return false;
    }
    return true;
}

void freeTree(node *root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    // Example 1 
    node *root1 = newNode(3);
    root1->left = newNode(5);
    root1->right = newNode(1);
    root1->left->left = newNode(6);
    root1->left->right = newNode(2);
    root1->right->left = newNode(9);
    root1->right->right = newNode(8);
    root1->left->right->left = newNode(7);
    root1->left->right->right = newNode(4);

    node *root2 = newNode(3);
    root2->left = newNode(5);
    root2->right = newNode(1);
    root2->left->left = newNode(6);
    root2->left->right = newNode(7);
    root2->right->left = newNode(4);
    root2->right->right = newNode(2);
    root2->right->right->left = newNode(9);
    root2->right->right->right = newNode(8);

    if (areLeafSequencesEqual(root1, root2)) {
        printf("Example 1: True\n");
    } else {
        printf("Example 1: False\n");
    }

    freeTree(root1);
    freeTree(root2);

    // Example 2 Trees Construction
    node *root3 = newNode(1);
    root3->left = newNode(2);
    root3->right = newNode(3);

    node *root4 = newNode(1);
    root4->left = newNode(3);
    root4->right = newNode(2);

    if (areLeafSequencesEqual(root3, root4)) {
        printf("Example 2: True\n");
    } else {
        printf("Example 2: False\n");
    }

    freeTree(root3);
    freeTree(root4);

    return 0;
}
