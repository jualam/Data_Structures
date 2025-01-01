//https://www.youtube.com/watch?v=0hGxILnKvJk&list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y&index=46

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

struct node* add_at_end(struct node*ptr,int data){
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    ptr->link=temp;
    return temp;
}
void add_at_pos(struct node*head,int data,int pos){
    struct node*ptr=head;
    struct node*ptr2=(struct node*)malloc(sizeof(struct node));
    ptr2->data=data;
    ptr2->link=NULL;

    pos--;
    while(pos !=1){
        ptr=ptr->link;
        pos--;
    }
    ptr2->link=ptr->link;
    ptr->link=ptr2;
}

int main(){
    struct node*head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node*ptr=head;
    ptr=add_at_end(ptr,98);
    ptr=add_at_end(ptr,78);

    int data=67,position=3;
    add_at_pos(head,data,position);
    
    ptr=head;
    while(ptr !=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
return 0;
}