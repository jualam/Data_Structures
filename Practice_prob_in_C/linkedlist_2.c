#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
int main(){
    struct node *head=malloc(sizeof(struct node)); //pointer to the first node
    head->data=45;
    head->link=NULL;
    struct node *current=malloc(sizeof(struct node)); //pointer to the second node
    current->data=98;
    current->link=NULL;
    head->link=current;
    struct node *current2=malloc(sizeof(struct node)); //pointer to the second node
    current2->data=980;
    current2->link=NULL;
    current->link=current2;
    printf("%d",head->link->link->data);
    return 0;
}