//https://www.youtube.com/watch?v=pBbVRIjy3VY&list=PLBlnK6fEyqRj9lld8sWIUNwlKfdUoPd1Y&index=48

#include<stdio.h>

void add_at_pos(int arr[],int arr2[],int n,int data,int pos);

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int pos=5,data=567,i;
    int size=sizeof(arr)/sizeof(arr[0]);
    int arr2[size+1];
    add_at_pos(arr,arr2,size,data,pos);
    for(i=0;i<size+1;i++){
        printf("%d ",arr2[i]);
    }
}
void add_at_pos(int arr[],int arr2[],int n,int data,int pos){
    int i;
    int index=pos-1;
    for(i=0;i<index;i++){
        arr2[i]=arr[i];
    }
    arr2[index]=data;
    int j;
    for(i=index+1,j=index;i<n+1,j<n;i++,j++){
    arr2[i]=arr[j];
    }
}