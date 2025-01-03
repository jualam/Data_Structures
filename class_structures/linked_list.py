#Creating a node(Contains the value and next)
class Node:
    def __init__(self, value):
        self.value=value
        self.next=None
class LinkedList:
    #Creating the linkedlist
    def __init__(self,value):
        new_node=Node(value)
        self.head=new_node
        self.tail=new_node
        self.length=1

    #Printing the linked list
    def print_list(self):
        temp=self.head
        while temp is not None:
            print(temp.value)
            temp=temp.next

    #Appending a value to the end of the linked list
    def append(self,value):
        new_node=Node(value)
        #if it's an empty linked list
        if self.head is None: 
            self.head=new_node
            self.tail=new_node
        #Not an empty linked list
        else:
            self.tail.next=new_node
            self.tail=new_node
        self.length+=1
        return True

    #Popping the end node from the linked list
    def pop(self):
        #if the linked list is empty
        if self.length==0:
            return None
        #Now writing the code if there's one or multiple nodes in the linked list
        temp=self.head
        pre=self.head
        while(temp.next):#this can also be written as (While temp.next is not None)
            pre=temp
            temp=temp.next
        self.tail=pre
        self.tail.next=None
        self.length -=1
        #No we write the code if there was only one node in the linked list,the previous part would make the length count go to 0
        if self.length==0:
            self.head=None
            self.tail=None
        return temp
    
    #Appending a node to the beginning of the linked list
    def prepend(self,value):
        new_node=Node(value)
        #if the linked list is empty
        if(self.length==0):
            self.head=new_node
            self.tail=new_node
        #if there is one or more nodes present in the linked list
        else:
            new_node.next=self.head
            self.head=new_node
        self.length+=1
        return True
        

#Creating a linked list and printing it's value
print("Creating the Linked list")
my_linked_list=LinkedList(4)
print('Head:', my_linked_list.head.value)
print('Tail:', my_linked_list.tail.value)
print('Value',my_linked_list.head.value)

#Appending a value to the linked list and printing it's values
print("Appending a node to the linked list")
my_linked_list.append(5)
my_linked_list.print_list()

#popping the last node from the linked list
print("Popping the last node from the linked list")
my_linked_list.pop()
my_linked_list.print_list()

#prepending a node to the linked list
print("Prepending a node to the linked list")
my_linked_list.prepend(3)
my_linked_list.print_list()

