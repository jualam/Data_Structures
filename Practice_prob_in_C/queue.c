#include <stdio.h>
int main ()
{

    //take queue size from the user as input
    int n,push,rear,front;
    scanf("%d",&n);
    //declare the queue of that specified size
    int queue[n];
    //declare a variable named as rear,front initially the value of top will be -1
    rear=-1;
    front=-1;
    while(1)
    {
        int option;
        printf("\n\nType..\n1 to push\n2 to pop\n3 to check if the Queue is Empty\n4 to check the Queue is Full\n0 to exit\n");
        scanf("%d", &option);
        if(option==1)
        {
            //If rear = maximum size of the queue then Print: Overflow and Return.
            if(rear==n-1)
            {
                printf("Sorry! Overflow\n");

            }
            else 
            {
                rear++;
                printf("Enter a value: ");
                scanf("%d",&push);
                queue[rear] = push;
            }
            printf("\n");
            for(int i=rear;i>=0;i--) printf("%d\n",queue[i]);

            //else ask user what value to push, name it as “push”
            //increment the value of top by 1


            //insert the specified number of “push” in the “top”-th index of the stack


            //After the if else loop print the stack
        }
        else if(option==2)
        {
            //front++


            front++;
            queue[front] = '\0';
            printf("\n");
            for(int i=rear;i>front;i--) printf("%d\n",queue[i]);






        }
        else if(option==3)
        {
            //return true(1) if stack is empty, false(0) otherwise
            if(rear==-1)
            {
                printf("Queue is Empty\n");
            }
            else
            {
                printf("Queue is not Empty\n");
            }

        }
        else if(option==4)
        {
            //return true(1) if stack is Full, false(0) otherwise
            if(rear==n-1)
            {
                printf("Queue is Full\n");
            }
            else
            {
                printf("Queue is not Full\n");
            }
        }
        else if(option==0)
        {
            return 0;
        }
        else printf("Invalid input.\n");
    }
    return 0;
}