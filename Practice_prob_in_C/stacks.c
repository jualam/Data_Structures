#include <stdio.h>
int main ()
{

    //take stack size from the user as input
    int n,push;
    scanf("%d",&n);
    //declare the stack of that specified size
    int stack1[n];
    //declare a variable named as top, initially the value of top will be -1
    int top=-1;
    while(1)
    {
        int option;
        printf("\n\nType..\n1 to push\n2 to pop\n3 to check if the stack is Empty\n4 to check the stack is Full\n0 to exit\n");
        scanf("%d", &option);
        if(option==1)
        {
            //If Top = maximum size of the stack then Print: Overflow and Return.
            if(top==n-1)
            {
                printf("Sorry! Overflow\n");

            }
            else
            {
                top++;
                printf("Enter a value: ");
                scanf("%d",&push);
                stack1[top] = push;
            }
            printf("\n");
            for(int i=top;i>=0;i--) printf("%d\n",stack1[i]);

            //else ask user what value to push, name it as “push”
            //increment the value of top by 1


            //insert the specified number of “push” in the “top”-th index of the stack


            //After the if else loop print the stack
        }
        else if(option==2)
        {
            //If top = -1 then Print: Underflow and Return.
            if(top==-1)
            {
                printf("Underflow\n");
            }
            else
            {
                stack1[top] = '\0';
                top--;
            }
            printf("\n");
            for(int i=top;i>=0;i--) printf("%d\n",stack1[i]);


            // else insert a null in the “top”-th index
            // decrement the value of top by 1




            // After the if else loop print the stack



        }
        else if(option==3)
        {
            //return true(1) if stack is empty, false(0) otherwise
            if(top==-1)
            {
                printf("Stack is Empty\n");
            }
            else
            {
                printf("Stack is not Empty\n");
            }

        }
        else if(option==4)
        {
            //return true(1) if stack is Full, false(0) otherwise
            if(top==n-1)
            {
                printf("Stack is Full\n");
            }
            else
            {
                printf("Stack is not Full\n");
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