#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
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
    printf("%d", head->link->link->data);
    return 0;
}