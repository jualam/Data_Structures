#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
void count_of_nodes(struct node *head){
    int count=0;
    if(head==NULL){
    printf("Linked list is empty\n");
    return;
    }
    struct node *ptr=NULL;
    ptr=head;
    int i=1;
    while(ptr !=NULL){
        printf("Node %d: %d\n", i, ptr->data); // Print current node number and its data
        count++;
        ptr = ptr->link;
        i++; // Increment node number
    }
    printf("\n");
    printf("Total nodes: %d\n",count);
}
int main(){
    struct node *head=(struct node*)malloc(sizeof(struct node)); //pointer to the first node
    head->data=45;
    head->link=NULL;
    struct node *current=(struct node*)malloc(sizeof(struct node)); //pointer to the second node
    current->data=98;
    current->link=NULL;
    head->link=current;
    current=(struct node*)malloc(sizeof(struct node)); //pointer to the third node
    current->data=3;
    current->link=NULL;
    head->link->link=current;
    printf("Last data: %d\n", head->link->link->data);//printing last node data
    count_of_nodes(head);
    return 0;
}