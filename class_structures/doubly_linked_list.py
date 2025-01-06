class Node:
    def __init__(self, value):
        self.value=value
        self.next=None
        self.prev=None
class DoublyLinkedList:
    def __init__(self,value):
        new_node=Node(value)
        self.head=new_node
        self.tail=new_node
        self.length=1

    #Printing the doubly linked list
    def print_list(self):
        temp=self.head
        while temp is not None:
            print(temp.value)
            temp=temp.next

    #appending a node to the end of the list
    def append(self, value):
        new_node = Node(value)
        #if it's an empty linked list
        if self.head is None:
            self.head=new_node
            self.tail=new_node
        #Not an empty linked list
        else:
            self.tail.next=new_node
            new_node.prev=self.tail
            self.tail=new_node
        self.length+=1
        return True
    
    #popping a node from the end of the list
    def pop(self):
        #if there is no node i the list
        if self.length==0:
            return None
        #the popped node will be kept in temp
        temp=self.tail
        #if there is only one node in the list
        if self.length==1:
            self.head=None
            self.tail=None
        #more than one node in the list
        else:
            self.tail=self.tail.prev
            self.tail.next=None
            temp.prev=None
        self.length-=1
        return temp
    
    #appennding a node to the start of the list
    def prepend(self,value):
        new_node=Node(value)
        #if the list is empty
        if self.head is None:
            self.head=new_node
            self.tail=new_node
        #not an empty list
        else:
            new_node.next=self.head
            self.head.prev=new_node
            self.head=new_node
        self.length+=1
        return True
    
    #popping a node from the beginning of the list
    def pop_first(self):
        #Empty list
        if (self.length==0):
            return None
        temp=self.head
        #if there is only one node in the list
        if (self.length==1):
            self.head=None
            self.tail=None
        else:
            self.head=self.head.next
            self.head.prev=None
            temp.next=None
        self.length-=1
        return temp
    
    #get an item in a particular index
    def get(self,index):
        if index<0 or index>=self.length:
            return None
        #if it's in the first half,then iterating from head is more efficient
        if index<self.length/2:
            temp=self.head
            for _ in range(index):
                temp=temp.next
        else:
            #if it's in the second half,then iterating from tail is more efficient
            temp=self.tail
            for _ in range(self.length-1,index,-1):
                temp=temp.prev
        return temp
    
    #set a value at a particular index for that node
    def set_value(self,index,value):
        temp=self.get(index)
        #if temp is not out of index
        if temp:
            temp.value=value
            return True
        return False
      
    
#Creating a doubly linked list using the constructor
print("Creating the doubly linked list")
my_dll=DoublyLinkedList(6)
print('Head:', my_dll.head.value)
print('Tail:', my_dll.tail.value)
print('Length:', my_dll.length)
my_dll.print_list()

#appending a node to the end of the list
print("\nAppending a node to the end of the list")
my_dll.append(7)
my_dll.append(8)
my_dll.append(81)
my_dll.append(23)
my_dll.print_list()

#popping a node from the end of the list
print("\nPopping a node from the end of the list")
print(my_dll.pop())#returning the popped node adress
my_dll.print_list()

#appendig a node to the start of the list
print("\nAppending a node to the start of the list")
my_dll.prepend(5)
my_dll.print_list()

#poppinjg anode from the beginnng of the list
print("\nPopping a node from the beginning of the list")
print(my_dll.pop_first())#returning the popped node adress
my_dll.print_list()

#getting a node from a particular index from the list
print("\nGetting a node from a particular index from the list")
print(my_dll.get(1).value)
print(my_dll.get(2).value)

#set a value at a particular index for that node
print("\nSetting a value at a particular index for that node")
my_dll.print_list()
my_dll.set_value(2,25)
print("\nAfter changing the value of the node at index 2")
my_dll.print_list()




