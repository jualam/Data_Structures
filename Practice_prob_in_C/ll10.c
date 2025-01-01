//https://www.youtube.com/watch?v=-rcIWx-JTxw&list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y&index=49

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

struct node* del_first(struct node*head){
    if(head==NULL){
        printf("List is already empty! ");
    }
    else{
        struct node*temp=head;
        head=head->link;
        free(temp);
        temp=NULL;
    }
    return head;
}

int main(){
    struct node*head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node*ptr=head;
    ptr=add_at_end(ptr,98);
    ptr=add_at_end(ptr,78);

    head=del_first(head);
    ptr=head;
    while(ptr !=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}