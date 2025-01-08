class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class Queue:
    def __init__(self,value):
        new_node=Node(value)
        self.first=new_node
        self.last=new_node
        self.length=1
    
    def print_queue(self):
        temp=self.first
        while temp is not None:
            print(temp.value)
            temp=temp.next

    #adding a new node to the queue(just like append of linked list)
    def enqueue(self,value):
        new_node=Node(value)
        if self.first is None:
            self.first=new_node
            self.last=new_node
        else:
            self.last.next=new_node
            self.last=new_node
        self.length+=1

    #Removing a node from the first since queue is FIFO
    def dequeue(self):
        if self.first is None:
            return None
        temp=self.first
        if self.length==1:
            self.first=None
            self.last=None
        else:
            self.first=self.first.next
            temp.next=None
        self.length-=1
        return temp

#initializing the queue with a value
print("Initializing the queue with a value")
my_q=Queue(1)
my_q.print_queue()

#adding a new_node to the queue
print("\nAdding a new node to the queue")
my_q.enqueue(2)
my_q.enqueue(3)
my_q.print_queue()

##Removing a node from the first since queue is FIFO
print("\nRemoving a node from the first since queue is FIFO")
my_q.dequeue()
my_q.print_queue()

