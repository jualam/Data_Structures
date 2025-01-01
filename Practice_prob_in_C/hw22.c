#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct treenode {
    int data; 
    struct treenode *left; 
    struct treenode *right; 
} node;

// Create a new tree node
node* NewNode(int data) {
    node *n = (node*)malloc(sizeof(node));
    if (n == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// Insert a new value into the BST
node* InsertIntoBST(node* root, int newValue) {
    if (root == NULL) {
        return NewNode(newValue);
    }
    if (newValue < root->data) {
        root->left = InsertIntoBST(root->left, newValue);
    } else {
        root->right = InsertIntoBST(root->right, newValue);
    }
    return root;
}

// Find the leftmost node in the BST
node* FindLeftmostNode(node* root) {
    node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Search for a value in the BST
bool SearchBST(node* root, int targetValue) {
    while (root != NULL) {
        if (targetValue == root->data) return true;
        else if (targetValue < root->data) root = root->left;
        else root = root->right;
    }
    return false;
}

// Compute the height of the BST
int HeightOfBST(node* root) {
    if (root == NULL) return 0;
    int leftHeight = HeightOfBST(root->left);
    int rightHeight = HeightOfBST(root->right);
    return fmax(leftHeight, rightHeight) + 1;
}

// Check if the BST is balanced
bool IsBSTBalanced(node* root) {
    if (root == NULL) return true;
    int leftHeight = HeightOfBST(root->left);
    int rightHeight = HeightOfBST(root->right);
    return abs(leftHeight - rightHeight) <= 1 && IsBSTBalanced(root->left) && IsBSTBalanced(root->right);
}

void FreeTree(node* root) {
    if (root != NULL) {
        FreeTree(root->left);
        FreeTree(root->right);
        free(root);
    }
}

int main() {
    node* root = NULL;
    int numberOfValues, value;

    printf("Enter the number of values to insert: ");
    scanf("%d", &numberOfValues);

    printf("Enter %d values for the BST: ", numberOfValues);
    for (int i = 0; i < numberOfValues; i++) {
        scanf("%d", &value);
        root = InsertIntoBST(root, value);
    }

    node* leftmost = FindLeftmostNode(root);
    if (leftmost != NULL) {
        printf("Leftmost node after insertion: %d\n", leftmost->data);
    } else {
        printf("The tree is empty.\n");
    }

    printf("Enter a value to search in the BST: ");
    scanf("%d", &value);
    if (SearchBST(root, value)) {
        printf("Value found in the BST.\n");
    } else {
        printf("Value not found in the BST.\n");
    }

    if (IsBSTBalanced(root)) {
        printf("The BST is balanced.\n");
    } else {
        printf("The BST is not balanced.\n");
    }

    FreeTree(root);
    return 0;
}

