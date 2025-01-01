//https://www.youtube.com/watch?v=80gNiLhyr7A&list=PLBlnK6fEyqRi3-lvwLGzcaquOs5OBTCww&index=10
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*link;
};
struct node* add_at_end(struct node*ptr,int data){
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=data;
    temp->link=NULL;

    ptr->link=temp;
    return temp;
}
int main(){
    struct node*head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node*ptr=head;
    ptr=add_at_end(ptr,98);
    ptr=add_at_end(ptr,3);
    ptr=add_at_end(ptr,23);

    ptr=head;
    while(ptr !=NULL){
        printf("%d ",ptr->data);
        printf("\n");
        ptr=ptr->link;
    }
    return 0;
}