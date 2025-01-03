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
    
    #Popping a node from the beginning of the linked list
    def pop_first(self):
        #if there's no node present in the linked list
        if(self.length==0):
            return None
        #if there's one or more nodes present in the linked list
        temp=self.head
        self.head=self.head.next
        temp.next=None#the first node now doesnt point towards any other node
        self.length-=1
        #No we write the code if there was only one node in the linked list,the previous part would make the length count go to 0
        if(self.length==0):
            self.tail=None
        return temp
    
    #to get a node from the linked list at specific index
    def get (self, index):
        if index<0 or index >=self.length:
            return None
        temp=self.head
        for _ in range(index):
            temp=temp.next
        return temp
    
    #to set a node in the linked list at specific index
    def set_value(self,index,value):
        temp=self.get(index)#this is either gonna return None or a node
        if temp is not None: #if the node is not None,this can also be written a (if temp is not None)
            temp.value=value
            return True
        return False
    
    #insert a node which a particular value to a specific index in the linked list
    def insert(self,index,value):
        if index<0 or index > self.length:
            return False
        #if we need to insert at the beginning of the linked list at index 0
        elif index==0:
            return self.prepend(value)
        #if we need to insert at the end of the linked list at index length
        elif index == self.length:
            return self.append(value)
        new_node=Node(value)
        temp=self.get(index-1)#this is gonna return the node before the index where we need to insert the node
        new_node.next=temp.next
        temp.next=new_node
        self.length+=1
        return True
    
    #remove a node at a specific index in the linked list
    def remove(self,index):
        if index<0 or index >=self.length:
            return None
        #if we need to remove the first node at index 0
        if index==0:
            return self.pop_first()
        #if we remobe a node from the end of the linked list
        if index==self.length-1:
            return self.pop()
        #removing a node from the middle somewhere of the linked list
        prev=self.get(index-1)
        temp=prev.next #we can also use tem=self.get(index) but this is O(n) really inefficient
        prev.next=temp.next
        temp.next=None 
        self.length -=1
        return temp   

    #reversing the linked list
    def reverse(self):
        temp=self.head
        self.head=self.tail
        self.tail=temp
        after=temp.next
        before=None
        for _ in range(self.length):
            #this follows a funny way use of (after,before,before,after) accordingly
            after=temp.next
            temp.next=before
            before=temp
            temp=after


#Creating a linked list and printing it's value
print("\nCreating the Linked list")
my_linked_list=LinkedList(4)
print('Head:', my_linked_list.head.value)
print('Tail:', my_linked_list.tail.value)
print('Value',my_linked_list.head.value)

#Appending a value to the linked list and printing it's values
print("\nAppending a node to the linked list")
my_linked_list.append(5)
my_linked_list.print_list()

#popping the last node from the linked list
print("\nPopping the last node from the linked list")
my_linked_list.pop()
my_linked_list.print_list()

#prepending a node to the linked list
print("\nPrepending a node to the linked list")
my_linked_list.prepend(3)
my_linked_list.print_list()

#popping the first node from the linked list
print("\nPopping the first node from the linked list")
my_linked_list.pop_first()
my_linked_list.print_list()

#getting a node from the linked list
print("\nGetting a node from the linked list")
my_linked_list.append(9)
my_linked_list.append(15)
my_linked_list.append(25)
my_linked_list.print_list()
print(my_linked_list.get(2))#to print the node adress
print(my_linked_list.get(2).value)#to print the node value at index 2

#setting a value to a specific node present in the given index
print("\nSetting a value to a specific node present in the given index")
my_linked_list.set_value(2, 100)
my_linked_list.print_list()

#inserting a node at a specific index in the linked list
print("\nInserting a node at a specific index in the linked list")
my_linked_list.insert(2, 50)
my_linked_list.print_list()

#removing a node at a specific index from the linked list
print("\nRemoving a node at a specific index from the linked list")
print("Removing",my_linked_list.remove(2).value)#printing the value of the node that it's removing
my_linked_list.print_list()#printing the linked list after removing the noe

#reversing the linked list
print("\nReversing the linked list")
my_linked_list.reverse()
my_linked_list.print_list()
