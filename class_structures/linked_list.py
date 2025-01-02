#Creating a node(Contains the value and next)
class node:
    def __init__(self, value):
        self.value=value
        self.next=None
class LinkedList:
    def __init__(self,value):
        new_node=node(value)
        self.head=new_node
        self.tail=new_node
        self.length=1

my_linked_list=LinkedList(4)
print('Head:', my_linked_list.head.value)
print('Tail:', my_linked_list.tail.value)
print('Value',my_linked_list.head.value)
