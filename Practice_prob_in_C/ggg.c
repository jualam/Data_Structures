#include <stdio.h>
#include <stdlib.h>

typedef struct listnode {
    int data;
    struct listnode *next;
} node;
// Function to create a new node
node* createNode(int data) {
    node* newNode = (node*)malloc(sizeof(node));
    if (!newNode) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Function to add a node 
void insertAtEnd(node** head, int data) {
    node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}
// Function to find and return the middle node
node* findMiddleNode(node* head) {
    node *slow = head, *fast = head;
    if (head != NULL) {
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;//fast pointer moves two steps and slow pointer one step at a time
            slow = slow->next;
        }
        return slow;
    }
    return NULL; // if empty
}
//print the list from a given node
void printList(node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
int main() {
    node* head = NULL;
    int n, data;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter node %d data: ", i + 1);
        scanf("%d", &data);// Read node data
        insertAtEnd(&head, data);
    }

    node* middle = findMiddleNode(head);
    printf("middle node and onwards: ");
    printList(middle);

    return 0;
}