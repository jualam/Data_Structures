//We will be adding a node at the end

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
void add_at_end(struct node*head,int data);//function call void add_at_end 
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
    printf("Last data before adding new node: %d\n", head->link->link->data);//last data before adding new node

    add_at_end(head,67);
    printf("Last data after adding new node: %d\n", head->link->link->link->data);
    struct node *ptr;
    ptr=head;
    int i=1;
    while(ptr !=NULL){
        printf("Node %d: %d\n", i, ptr->data); // Print current node number and its data
        ptr = ptr->link;
        i++; // Increment node number
    }
    return 0;
}
void add_at_end(struct node*head,int data){
    struct node *ptr,*temp;
    ptr=head;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;
    while(ptr->link !=NULL){
        ptr=ptr->link;
    }
    ptr->link=temp;
}
