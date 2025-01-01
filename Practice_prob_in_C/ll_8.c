//https://www.youtube.com/watch?v=90zyJ1eVeUw&list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y&index=44

#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
void add_beg(struct node**head,int a);

int main(){
    struct node*head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node*ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=98;
    ptr->link=NULL;

    head->link=ptr;
    int data=5;

    add_beg(&head,data);
    ptr=head;
    while(ptr !=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->link;
    }
    return 0;

}
void add_beg(struct node**head,int a){
    struct node*tr=(struct node*)malloc(sizeof(struct node));
    tr->data=a;
    tr->link=NULL;

    tr->link=*head;
    *head=tr;
}
