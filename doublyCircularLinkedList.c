# include <stdio.h>
# include <stdlib.h>


struct node {
	int data;
	struct node *next;
	struct node *prev;
};

typedef struct node node;

struct doublyCircularNode{
	node *head = NULL;
	node *end = NULL;
};
typedef struct doublyCircularNode dcnode;

// dcnode * createDCNode();
node * createNode(int);
void createList();
int size();		// O(n)
void insertLast(int data);
void insertFirst(int data);
void insertAtPosition(int data, int pos);
void deleteFirst();
void deleteLast();
void deleteAtPosition(int pos);
node * search(int data);	//if data present then return node address else return NULL
void sort();
void print();

node *head = NULL, *end = NULL;	// Littele different than circularlinkedlist
int main()
{
	// dcnode *dcnode1 = NULL;
	// dcnode1 = createDCNode();

	// insertLast(&dcnode1,10);
	// printf("head: %d, end: %d",dcnode1->head->data, dcnode1->end->data);
	// print(&dcnode1);
	int data;
	insertLast(10);
	print();
	printf("Size: %d\n", size());

	insertFirst(5);
	insertFirst(3);
	print();
	printf("Size: %d\n", size());

	insertAtPosition(15,3);
	print();
	printf("Size: %d\n", size());

	deleteFirst();
	print();
	printf("Size: %d\n", size());

	deleteAtPosition(1);
	print();
	printf("Size: %d\n", size());

	printf("Enter data want to search: ");
	scanf("%d", &data);
	search(data);

	printf("Sort a circular linked list\n");
	sort();
	print();

	// To creat list at once
	// createList();
	// print();

	// sort();
	// print();

}


// dcnode * createDCNode()
// {
// 	dcnode *newdcNode = (dcnode *) malloc(sizeof(dcnode));
// 	return newdcNode;
// }

node * createNode(int data)
{
	node *newNode = (node *) malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void createList()
{
	int data, c;

	printf("Enter a data: ");
	scanf("%d",&data);

	node *newNode = createNode(data);
	head = newNode;
	end = head;

	printf("cont = 1, exit = 0: ");
	scanf("%d", &c);

	node *curr = head;
	while(c != 0)
	{
		printf("Enter a data: ");
		scanf("%d",&data);

		node *newNode = createNode(data);
		curr->next = newNode;
		newNode->prev = curr;
		curr = curr->next;
	
		printf("cont = 1, exit = 0: ");
		scanf("%d", &c);

	}
	end = curr;
	end->next = head;
	head->prev = end;
}

int size()
{
	if(head == NULL && end == NULL)
	{
		return 0;
	}
	node *curr = head;
	int size = 0;
	while (curr->next != head)
	{
		size++;
		curr = curr->next;
	}
	size++;
	return size;

}

void insertLast(int data)
{	
	node *newNode = createNode(data);	// node *new will give error in g++ compiler 
										// since it is reserved work in C++

	if(head == NULL && end == NULL)
	{
		head = newNode;
		head->next = head;
		head->prev = head;
		end = head;

	}
	else
	{
		end->next = newNode;
		newNode->prev = end;
		end = newNode;
		end->next = head;
		head->prev = end;
	}
	// size ++;
}

void insertFirst(int data)
{	
	node *newNode = createNode(data);	// node *new will give error in g++ compiler 
										// since it is reserved work in C++

	if(head == NULL && end == NULL)
	{
		head = newNode;
		head->next = head;
		head->prev = head;
		end = head;

	}
	else
	{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
		head->prev = end;
		end->next = head;
	}
	// size ++;
}

void insertAtPosition(int data, int pos)
{
	int len = size();
	if (pos <= 0 || pos > (len + 1))
	{
		printf("Position is not Valid\n");
		return;
	}
	if(pos == 1)
	{
		insertFirst(data);
	}
	else if(pos == (len +1))
	{
		insertLast(data);
	}
	else
	{
		// execution reach in this location if position is between 2 and len
		node *newNode = createNode(data);
		node *curr = head->next;
		int i = 2;	// start from 2nd node
		while(i != pos)
		{
			i ++;
			curr = curr->next;
		}
		newNode->next = curr;
		newNode->prev = curr->prev;
		curr->prev = newNode;
		newNode->prev->next = newNode;
	}
	// size++;
}

void deleteFirst()
{
	if(head == NULL && end == NULL)
	{
		printf("Circular linked list is empty\n");
	}
	else if (head->next == head)
	{
		node *temp = head;
		head = NULL;
		end = NULL;
		free(temp);
		
	}
	else
	{
		node *temp = head->next;
		free(head);
		head = temp;
		head->prev = end;
		end->next = head;
	}
	// size--;
}

void deleteLast()
{
	if(head == NULL && end == NULL)
	{
		printf("Circular linked list is empty\n");
	}
	else if (head->next == head)
	{
		deleteFirst();
	}
	else
	{
		end->prev->next = head;
		head->prev = end->prev;
		free(end);
	}
	// size--;
}

void deleteAtPosition(int pos)
{
	int len = size();
	if (pos <= 0 || pos > (len))
	{
		printf("Position is not Valid\n");
		return;
	}
	if(pos == 1)
	{
		deleteFirst();
	}
	else if(pos == (len))
	{
		deleteLast();
	}
	else
	{
		// execution reach in this location if position is between 2 and len - 1
		node *curr = head->next;
		int i = 2;	// start from 2nd node
		while(i != pos)
		{
			i ++;
			curr = curr->next;
		}
		curr->prev->next = curr->next;	// curr points to old node at pos
		curr->next->prev = curr->prev;
		free(curr);
	}
	// size--;	
}

node * search(int data)
{
	if(head == NULL && end == NULL)
	{
		printf("Circular linked list is empty\n");
		return NULL;

	}
	node *curr = head;
	int pos = 0;
	while(curr->next != head)
	{
		if(curr->data == data)	
		{
			printf("%d present at index %d\n",data, ++pos);
			return curr;
		}
		pos++;
		curr = curr->next;
	}
	if(curr->data == data)
	{
		printf("%d present at index %d\n",data, ++pos);
		return curr;
	}
		

	printf("%d not present in Circular linked list\n", data);
	return NULL;
}

void sort()
{
	if(head == NULL && end == NULL)
	{
		printf("Circular linked List is empty\n");
		return;
	}
	
	node *curr = head, *temp, *tempHead = head;

	while(curr->next != head)
	{
		temp = head;
		while(temp->next != tempHead)
		{
			if(temp->data > temp->next->data)		// Increasing Order
			{
				temp->data = temp->data ^ temp->next->data;
				temp->next->data = temp->data ^ temp->next->data;
				temp->data = temp->data ^ temp->next->data;
			}
			temp = temp->next;
		}
		tempHead = temp;	// on each step we get largest at last
		curr = curr->next;
	}

}


void print()
{
	// node *head = (*dcn)->head;
	// node *end = (*dcn)->end;
	if (head == NULL && end == NULL)
	{
		printf("Circular linked list is empty\n");
		return;
	}

	node *curr = head;
	printf("%d <-> ",curr->data);
	curr = curr->next;
	while (curr != head)
	{
		printf("%d <-> ",curr->data);
		curr = curr->next;
	}

	printf("%d\n",curr->data);
}
