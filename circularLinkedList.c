// circular Linked List in C
# include <stdio.h>
# include <stdlib.h>


struct node {
	int data;
	struct node *next;
};

typedef struct node node;

// node *head = NULL;

node * createNode(int);
void createList(node **head);
int size(node **head);	// O(n)
void insertLast(node **head,int data);
void insertFirst(node **head, int data);
void insertAtPosition(node **head, int data, int pos);
void deleteFirst(node **head);
void deleteLast(node **head);
void deleteAtPosition(node **head, int pos);
node * search(node **head, int data);	//if data present then return node address else return NULL
void sort(node **head);
void print(node **head);


// int size = 0;
int main()
{
	//Initialize Crcular linked list with NULL head
	node *head = NULL;
	int data = 10;
	// printf("Enter: ");
	// scanf("%d",&data);
	insertLast(&head, data);
	insertFirst(&head, 5);
	print(&head);
	printf("Size: %d\n", size(&head));

	printf("Insert at position 1\n");
	insertAtPosition(&head, 1,1);
	print(&head);
	printf("Size: %d\n", size(&head));

	printf("Insert at position 4\n");
	insertAtPosition(&head, 15,4);
	print(&head);
	printf("Size: %d\n", size(&head));

	deleteFirst(&head);
	print(&head);
	printf("Size: %d\n", size(&head));	

	deleteLast(&head);
	print(&head);
	printf("Size: %d\n", size(&head));	

	deleteAtPosition(&head,2);
	print(&head);
	printf("Size: %d\n", size(&head));	

	deleteAtPosition(&head,1);
	print(&head);
	printf("Size: %d\n", size(&head));	

	printf("New Circular linked list\n");
	node *head1 = NULL;
	createList(&head1);
	print(&head1);

	printf("Enter data want to search: ");
	scanf("%d", &data);
	search(&head1,data);

	printf("Sort a circular linked list\n");
	sort(&head1);
	print(&head1);

}


node * createNode(int data)
{
	node *newNode = (node *) malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void createList(node **head)
{
	int data, c;

	printf("Enter a data: ");
	scanf("%d",&data);

	node *newNode = createNode(data);
	*head = newNode;

	printf("cont = 1, exit = 0: ");
	scanf("%d", &c);

	node *curr = *head;
	while(c != 0)
	{
		printf("Enter a data: ");
		scanf("%d",&data);

		node *newNode = createNode(data);
		curr->next = newNode;
		curr = curr->next;
	
		printf("cont = 1, exit = 0: ");
		scanf("%d", &c);

	}


	curr->next = *head;
}

int size(node **head)
{
	if(*head == NULL)
	{
		return 0;
	}
	node *curr = *head;
	int size = 0;
	while (curr->next != *head)
	{
		size++;
		curr = curr->next;
	}
	size++;
	return size;

}

void insertLast(node **head, int data)
{
	node *newNode = createNode(data);	// node *new will give error in g++ compiler 
										// since it is reserved work in C++

	if(*head == NULL)
	{
		*head = newNode;
		(*head)->next = *head;	// point to first node
	}
	else
	{
		node *curr = *head;
		while (curr->next != *head)
		{
			curr = curr->next;
		}
		curr->next = newNode;
		curr = newNode;		// new last node
		curr->next = *head;		// point to first 
	}
	// size ++;
}


void insertFirst(node **head, int data)
{
	node *newNode = createNode(data);
	if(*head == NULL)
	{
		*head = newNode;
		(*head)->next = *head;
	}
	else
	{
		node *curr = *head;
		while (curr->next != *head)
		{
			curr = curr->next;
		}
		newNode->next = *head;
		*head = newNode;	//new head
		curr->next = *head;
	}
	// size++;
}

void insertAtPosition(node **head, int data, int pos)
{
	int len = size(head);
	if (pos <= 0 || pos > (len + 1))
	{
		printf("Position is not Valid\n");
		return;
	}
	if(pos == 1)
	{
		insertFirst(head,data);
	}
	else if(pos == (len +1))
	{
		insertLast(head, data);
	}
	else
	{
		// execution reach in this location if position is between 2 and len
		node *newNode = createNode(data);
		node *curr = (*head)->next;
		node *prev = *head;
		int i = 2;	// start from 2nd node
		while(i != pos)
		{
			i ++;
			prev = curr;
			curr = curr->next;
		}
		newNode->next = curr;
		prev->next = newNode;
	}
	// size++;
}

void deleteFirst(node **head)
{
	if(*head == NULL)
	{
		printf("Circular linked list is empty\n");
	}
	else if ((*head)->next == *head)
	{
		node *temp = *head;
		*head = NULL;
		free(temp);
		
	}
	else
	{
		node *curr = *head;
		while(curr->next != *head)
		{
			curr = curr->next;
		}
		node *temp = (*head)->next;
		free(*head);
		*head = temp;
		curr->next = *head;
	}
	// size--;
}

void deleteLast(node **head)
{
	if(*head == NULL)
	{
		printf("Circular linked list is empty\n");
	}
	else if ((*head)->next == *head)
	{
		deleteFirst(head);
	}
	else
	{
		node *curr = *head;
		node *prev = NULL;
		while(curr->next != *head)
		{
			prev = curr;
			curr = curr->next;
		}
		prev->next = *head;
		free(curr);
	}
	// size--;
}

void deleteAtPosition(node **head, int pos)
{
	int len = size(head);
	if (pos <= 0 || pos > (len))
	{
		printf("Position is not Valid\n");
		return;
	}
	if(pos == 1)
	{
		deleteFirst(head);
	}
	else if(pos == (len))
	{
		deleteLast(head);
	}
	else
	{
		// execution reach in this location if position is between 2 and len - 1
		node *curr = (*head)->next;
		node *prev = *head;
		int i = 2;	// start from 2nd node
		while(i != pos)
		{
			i ++;
			prev = curr;
			curr = curr->next;
		}
		prev->next = curr->next;	// curr points to old node at pos
		free(curr);
	}
	// size--;	
}

node * search(node **head, int data)
{
	if(*head == NULL)
	{
		printf("Circular linked list is empty\n");
		return NULL;

	}
	node *curr = *head;
	int pos = 0;
	while(curr->next != *head)
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


void sort(node **head)
{
	if(*head == NULL)
	{
		printf("Circular linked List is empty\n");
		return;
	}
	
	node *curr = *head, *temp, *tempHead = *head;

	while(curr->next != *head)
	{
		temp = *head;
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

void print(node **head)
{
	if (*head == NULL)
	{
		printf("Circular linked list is EMpty\n");
		return;
	}
	node *curr = *head;
	printf("%d -> ",curr->data);
	curr = curr->next;
	while (curr != *head)
	{
		printf("%d -> ",curr->data);
		curr = curr->next;
	}

	printf("%d\n",curr->data);
}
