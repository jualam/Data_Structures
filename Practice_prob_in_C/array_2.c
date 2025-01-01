//https://www.youtube.com/watch?v=egUHjERGf88&list=PLBlnK6fEyqRi3-lvwLGzcaquOs5OBTCww&index=11
#include<stdio.h>
int add_at_end(int a[],int b[],int n,int freepos,int data){
    int i;
    for(i=0;i<n;i++)
    b[i]=a[i];
    b[freepos]=data;
    freepos++;
    return freepos;
}
int main(){
    int a[3];
    int i,n,freepos;
    printf("enter the number of elements: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);

    int size=sizeof(a)/sizeof(a[0]);
    freepos=n;
    if(n==size){
        int b[size+1];
        freepos=add_at_end(a,b,size,freepos,65);
        for(i=0;i<freepos;i++)
        printf("%d\n",b[i]);
    }
    return 0;
}