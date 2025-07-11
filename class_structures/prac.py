class Node:
    def __init__(self,value):
        self.value=value
        self.next=None

class LinkedList:
    def __init__(self,value):
        new_node=Node(value)
        self.head=new_node
        self.tail=new_node
        self.length=1

    def print_list(self):
        temp=self.head
        while temp is not None:
            print(temp.value)
            temp=temp.next

    def append(self, value):
        new_node=Node(value)
        if self.head is None:
            self.head=new_node
            self.tail=new_node
        else:
            self.tail.next=new_node
            self.tail=new_node
        self.length+=1
        return True
        
    def pop(self):
        if self.head is None:
            return None
        temp=self.head
        pre=self.head
        while temp.next is not None:
            pre=temp
            temp=temp.next
        self.tail=pre
        self.tail.next=None
        self.length-=1
        if self.length==0:
            self.head=None
            self.tail=None
        return temp
    
    def prepend(self,value):
        new_node=Node(value)
        if self.head is None:
            self.head=new_node
            self.tail=new_node
        else:
            new_node.next=self.head
            self.head=new_node
        self.length+=1
        return True
    
    def pop_first(self):
        if self.head is None:
            return None
        temp=self.head
        self.head=self.head.next
        temp.next=None
        self.length-=1
        if self.length==0:
            self.tail=None
        return temp
    
    def get(self, index):
        if index<0 or index>=self.length:
            return None
        temp=self.head
        for i in range(index):
            temp=temp.next
        return temp
    def set_value(self,index,value):
        if index<0 or index>=self.length:
            return False
        temp=self.head
        for i in range(index):
            temp=temp.next
        if temp:
            temp.value=value
            return True
        
    def insert(self,index,value):
        if index<0 or index>self.length:
            return False
        elif index==0:
            return self.prepend(value)
        elif index==self.length:
            return self.append(value)
        new_node=Node(value)
        temp=self.get(index-1)
        new_node.next=temp.next
        temp.next=new_node
        self.length+=1
        return True
    
    def remove(self,index):
        if index<0 or index>=self.length:
            return None
        if index==0:
            return self.pop_first()
        if index==self.length-1:
            return self.pop()
        prev=self.get(index-1)
        temp=prev.next
        prev.next=temp.next
        temp.next=None
        self.length-=1
        return temp
    def reverse(self):
        temp=self.head
        self.head=self.tail
        self.tail=temp
        after=temp.next
        before=None
        for _ in range(self.length):
            after=temp.next
            temp.next=before
            before=temp
            temp=after

list1=LinkedList(5)
list1.append(50)
list1.append(45)
# list1.pop()
# list1.pop()
list1.prepend(23)
# print(list1.pop_first())
# print(list1.pop_first())
# print(list1.pop_first())
list1.print_list()
print("After setting the value")
list1.set_value(2,10)
list1.print_list()
print("After inserting")
list1.insert(3,33)
list1.print_list()
print("After Removing")
list1.remove(0)
list1.print_list()
print("After Reversing")
list1.reverse()
list1.print_list()