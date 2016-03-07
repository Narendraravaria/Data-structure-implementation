from BSTNode import BSTNode;
from queue2stack import MyQueue;

class BSTree():
	def __init__ (self, data = None):
		self.root = BSTNode(data);
		self.__size = 0;

	def size(self):
		return self.__size;

	def isEmpty(self):
		return 1 if (self.size() == 0) else 0;

	def min(self,node = None):
		# go ahead if Binary Search is not Empty
		if (self.isEmpty()):
			return None;

		# go towards left untill leftChild of BSTNode become Null
		curr = self.root if (node == None) else node;
		while (curr.leftChild != None):
			curr = curr.leftChild;
		return curr.data, curr;


	def max(self, node = None):
		# go ahead if Binary Search is not Empty
		if (self.isEmpty()):
			return None;

		# go towards right untill rightChild of BSTNode become Null
		curr = self.root if (node == None) else node;
		while (curr.rightChild != None):
			curr = curr.rightChild;
		return curr.data, curr;

	def insert(self,data):

		# if size == 0 then fill in root node else go in left direction if data is 
		# less than current BSTNode data otherwise go in right direction 
		if(self.size() == 0):
			self.__size += 1;
			self.root.data = data;
		else:
			new =  BSTNode(data);
			curr = self.root;

			while (1):
				if (data <= curr.data ):
					if (curr.leftChild == None):
						curr.leftChild = new;
						new.parent = curr;
						break;
					else:
						curr = curr.leftChild;
				else:
					if (curr.rightChild == None):
						curr.rightChild = new;
						new.parent = curr;
						break;
					else:
						curr = curr.rightChild;
			self.__size += 1;

	def delete(self,node = None, data = None):
		# return None if both are none or if both are present
		if ((node == None and data == None) or (node != None and data != None)):
			return None;
		
		# search node containing data and proceed with that node
		if(data != None):
			curr = self.search(data);
			if (curr == None):
				return None;
		else:	# data is None hence go with node
			curr = node;

		# case 1: No Child
		if (curr.leftChild == None and curr.rightChild == None):
			parent = curr.parent;
			if (parent.leftChild == curr):
				parent.leftChild = None;
			else:
				parent.rightChild  = None;

		# case 2: Only One Child
		elif (curr.leftChild != None and curr.rightChild == None):
			if (curr == self.root): 
				self.root = self.root.leftChild;
			else:
				parent = curr.parent;
				if (parent.leftChild == curr):
					parent.leftChild = curr.leftChild;
				else:
					parent.rightChild  = curr.leftChild;
				curr.leftChild.parent = parent;
		elif (curr.leftChild == None and curr.rightChild != None):
			if (curr == self.root): 
				self.root = self.root.leftChild;
			else:
				parent = curr.parent;
				if (parent.leftChild == curr):
					parent.leftChild = curr.rightChild;
				else:
					parent.rightChild  = curr.rightChild;	
				curr.rightChild.parent = parent;
		# Two Children
		else:		
			newData,newNode = self.successor(curr);
			curr.data = newData;
			self.delete(node = newNode);





	def BFSTraversal(self, node = None):		# using Queue
		if(self.isEmpty()):
			print "Binary Search Tree is Empty";
			return;

		tempQ = MyQueue();
		root = self.root if (node == None) else node;
		tempQ.enqueue(self.root);

		while(not tempQ.isEmpty()):
			t = tempQ.dequeue();
			print t.data,;
			if(t.leftChild !=None):
				tempQ.enqueue(t.leftChild);

			if(t.rightChild !=None):
				tempQ.enqueue(t.rightChild);
		print;			


	def successor(self, node = None, data = None):
		# return if both are none or if both are present

		if ((node == None and data == None) or (node != None and data != None)):
			return None,None;
		
		# search node containing data and proceed with that node
		if(data != None):
			curr = self.search(data);
			if (curr == None):
				return None,None;
		# data is None hence go with node
		else:
			curr = node;

		succData = None;
		if (curr.rightChild != None):
			succData,curr = self.min(curr.rightChild);
		else:
			while (1):
				if (curr == self.root):
					break;
				if (curr.parent.leftChild == curr): # check node is leftChild of parent node
					succData = curr.parent.data;
					curr = curr.parent; # to match with curr value of if part
					break;
				else:
					if (curr == self.root): break; # if BST does not have successsor
					curr = curr.parent;
		return succData, curr;


	def predecessor(self, node = None, data = None):
		# return if both are none or if both are present

		if ((node == None and data == None) or (node != None and data != None)):
			return None,None;
		
		# search node containing data and proceed with that node
		if(data != None):
			curr = self.search(data);
			if (curr == None):
				return None,None;
		# data is None hence go with node
		else:
			curr = node;

		succData = None;
		if (curr.leftChild != None):
			succData,curr = self.max(curr.leftChild);
		else:
			while (1):
				if (curr == self.root):
					break;
				if (curr.parent.rightChild == curr): # check node is rightChild of parent node
					succData = curr.parent.data;
					curr = curr.parent;
					break;
				else:
					if (curr == self.root): break; # if BST does not habe predecessor
					curr = curr.parent;
		return succData, curr;




	def search(self, data, node = None):
		if (self.isEmpty()):
			return None;
		curr = self.root if (node == None) else node;
		while(1):
			if (data == curr.data ):
				return curr;
			elif (data < curr.data):
				if (curr.leftChild == None):
					return None;
				else:
					curr = curr.leftChild;
			else:
				if (curr.rightChild == None):
					return None;
				else:
					curr = curr.rightChild;



if __name__ == '__main__':
	bst = BSTree();
	# bst.BFSTraversal();
	bst.insert(6);
	bst.insert(4);
	bst.insert(10);
	bst.insert(23);
	bst.insert(1);
	bst.insert(5);
	bst.insert(19);
	bst.BFSTraversal();
	print "Minimum:",bst.min();
	print "Maximum:",bst.max();
	x = 5;
	node = bst.search(x);
	if (node != None):
		print "parent of",x,":",node.parent.data;
		print "leftChild of",x,":",node.leftChild.data if (node.leftChild != None) else None;
		print "rightChild of",x,":",node.rightChild.data if (node.rightChild != None) else None;
	else:
		print x," not present in BST";
	x = 11;
	succD,succN = bst.successor(data = x);
	print "successor of",x,":",succD,succN;
	print "predecessor of",x,":",bst.predecessor(data = x);

	bst.delete(data= x);
	bst.BFSTraversal();



# Test Cases
# successor put maximum value of BST as i/p
# predecessor put miniimum value of BST as i/p
# delete with one, two , no Child
# scccessor, predecessor, search, delete which is not present in BST
# 