# Singly Linked List Implemetation

from SinglyLinkedListNode import Node;

##### Methods #####
# isEmpty();
# size();
# createNode(data);
# createList(); 
# insertFirst(data);
# insertLast(data);
# insertAtPosition(data, pos);
# deleteFirst();
# deleteLast();
# deleteAtPosition(pos);
# display();
# sort();
# search();
# reverse(head, tail);

class CircularSinglyLinkedList():
	def __init__(self, head = None):
		self.head = head;
		self.__size = 0;

	def isEmpty(self):
		return 1 if (self.head == None) else 0;

	def size(self):
		# size = 0;
		# if (self.isEmpty()):
		# 	return size;
		# else:
		# 	curr = self.head;
		# 	while (curr != self.head):
		# 		curr = curr.Next;
		# 		size += 1;

		# return size;
		return self.__size;

	def createNode(self, data):
		newNode = Node(data);
		return newNode;

	def createList(self):
		c = (input("want to continue (1/0)?"));

		if(c == 0 ):
			return None;

		data = input("Enter data: ");
		newNode = self.createNode(data);
		self.head = newNode;
		self.__size += 1;

		curr = self.head;
		c = (input("want to continue (1/0)?"));
		while(c != 0 ):
			
			data = input("Enter data: ");

			newNode = self.createNode(data);
			curr.next = newNode;
			curr = curr.next;
			self.__size += 1;

			c = (input("want to continue (1/0)?"));
		curr.next = self.head;
			

	def insertFirst(self, data):
		if (self.isEmpty()):
			self.head = self.createNode(data);
			self.head.next = self.head;
		else:
			newNode = self.createNode(data);
			curr = self.head;
			while (curr.next != self.head):
				curr = curr.next;
			newNode.next = self.head;
			self.head = newNode;
			curr.next = self.head;
		self.__size += 1;

	def insertLast(self, data):
		if (self.isEmpty()):
			self.head = self.createNode(data);
			self.head.next = self.head;
		else:
			newNode = self.createNode(data);
			curr = self.head;
			while (curr.next != self.head):
				curr = curr.next;
			curr.next = newNode;
			newNode.next = self.head;
		self.__size += 1;

	def insertAtPosition(self, data, pos):
		if (pos <= 0 or pos > self.size() + 1):
			print("Position is not Valid");
			return;
		if (pos == 1):
			self.insertFirst(data);
		elif (pos == self.size() + 1):
			self.insertLast(data);
		else:
			# start from 2nd element since if pos was 1 then execution stoped at if (pos == 1)
			i = 2;
			newNode = self.createNode(data);
			curr = self.head.next;
			prev = self.head;
			while(i != pos):
				prev = curr;
				curr =curr.next;
				i += 1;

			prev.next = newNode;
			newNode.next = curr;
			self.__size += 1;

	def deleteFirst(self):
		if (self.isEmpty()):
			print("Circular singly linked list is empty");
		else:
			
			curr = self.head;
			while (curr.next != self.head):
				curr = curr.next;
			self.head = self.head.next;
			curr.next = self.head;

		self.__size -= 1;

	def deleteLast(self):
		if (self.isEmpty()):
			print("Circular singly linked list is empty");
		else:
			curr = self.head;
			prev = None;
			while (curr.next != self.head):
				prev = curr;
				curr = curr.next;
			prev.next = self.head;
		self.__size -= 1;

	def deleteAtPosition(self, pos):
		if (pos <= 0 or pos > self.size() ):
			print("Position is not Valid");
			return;
		if (pos == 1):
			self.deleteFirst();
		elif (pos == self.size()):
			self.deleteLast();
		else:
			i = 2;
			curr = self.head.next;
			prev = self.head;
			while(i != pos):
				prev = curr;
				curr =curr.next;
				i += 1;

			prev.next = curr.next;
			self.__size -= 1;

	def display(self):
		if (self.isEmpty()):
			print("Singly linked list is empty");
		else:
			curr = self.head;
			print "%d ->"%curr.data,;
			curr = curr.next;
			while(curr != self.head):
				print "%d ->"%curr.data,;
				curr = curr.next;
			print("%d"%curr.data);
######## 
	def sort(self):
		if(self.isEmpty()):
			printf("Circular singly linked List is empty");
			return;
	
		curr = self.head;
		tempHead = self.head;

		while(curr.next != self.head):
			temp = self.head;

			while(temp.next != tempHead):

				if(temp.data > temp.next.data):		# Increasing Order
					temp.data = temp.data ^ temp.next.data;
					temp.next.data = temp.data ^ temp.next.data;
					temp.data = temp.data ^ temp.next.data;
				temp = temp.next;
			tempHead = temp;	# on each step we get largest at last
			curr = curr.next;

	def search (self, data):
		if (self.isEmpty()):
			printf("Singly linked List is empty");
			return ;

		pos = 0;
		curr = self.head;
		while (curr.next != self.head):
			if (curr.data == data):
				print("%d present at index %d"%(data, pos + 1));
				return;
			pos += 1;
			curr = curr.next;
		if (curr.next.data == data):
			print("%d present at index %d"%(data, pos + 1));
		else:
			print("%d not present in Singly linked list\n"%data);

	def reverse (self):
		head = self.head;
		end = head;
		
		while (end.next != head):
			end = end.next;

		next = None;
		prev = end;
		curr = head;
		while (curr != end):
			next = curr.next;
			curr.next = prev;
			prev = curr;
			curr = next;

		curr.next = prev;
		prev = curr;
		self.head = prev;
		# return prev; new head




if __name__ == '__main__':

	list1 = CircularSinglyLinkedList();
	list1.insertFirst(1);
	list1.insertLast(10);

	list1.display();
	print (list1.size());

	list1.insertAtPosition(5,2);
	list1.display();
	print (list1.size());

	list1.insertAtPosition(15,4);
	list1.display();
	print (list1.size());

	list1.deleteAtPosition(1);
	list1.display();
	print (list1.size());

	list1.sort();
	list1.display();
	print (list1.size());

	list1.search(10);
	list1.reverse();
	list1.display();

	list1.createList();
	list1.display();
	list1.sort()
	list1.display();
	list1.reverse();
	list1.display();	
