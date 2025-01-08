class Node:
    def __init__(self,value):
        self.value = value
        self.next=None

class Stack:
    def __init__(self,value):
        new_node=Node(value)
        self.top = new_node
        self.height=1
    
    def print_stack(self):
        temp=self.top
        while temp is not None:
            print(temp.value)
            temp=temp.next

    #pushing a new node to the stack(a lot like prepend method of the linked list)
    def push(self,value):
        new_node=Node(value)
        if self.height==0:
            self.top=new_node
        else:
            new_node.next=self.top
            self.top=new_node
        self.height+=1

    #popping a node from the top of the stack(like the pop_first of the linked list)
    def pop(self):
        if self.height==0:
            return None
        temp=self.top
        self.top=self.top.next
        temp.next=None
        self.height-=1
        return temp

#Initializing a stack
print("Initializing a stack")
my_stack=Stack(4)
my_stack.print_stack()

#pushing a new_node to the top of the stack
print("\nPushing a new node to the top of the stack")
my_stack.push(5)
my_stack.push(3)
my_stack.print_stack()

#popping a node from the top of the stack
print("\nPopping a node from the top of the stack")
my_stack.pop()
my_stack.print_stack()
