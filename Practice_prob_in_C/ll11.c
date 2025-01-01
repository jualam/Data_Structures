//https://www.youtube.com/watch?v=TpgxJupHATQ&list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y&index=50

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

void del_last(struct node*head){
    if(head==NULL){
        printf("List is empty");
    }
    else if (head->link==NULL){
        free(head);
        head=NULL;
    }
    else {
        struct node*temp=head;
        struct node*temp2=head;
        while(temp->link!=NULL){
            temp2=temp;
            temp=temp->link;
        }
        temp2->link=NULL;
        free(temp);
        temp=NULL;
    }
}
int main(){
    struct node*head=(struct node*)malloc(sizeof(struct node));
    head->data=45;
    head->link=NULL;

    struct node*ptr=head;
    ptr=add_at_end(ptr,98);                                                                                                                       
    ptr=add_at_end(ptr,78);
    
    del_last(head);
    ptr=head;
    while(ptr !=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->link;
    }
    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   