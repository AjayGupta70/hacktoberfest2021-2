// A complete working C++ program to
// demonstrate all insertion methods
// on Linked List
#include <bits/stdc++.h>
using namespace std;

// A linked list node
class Node
{
	public:
	int data;
	Node *next;
};

// Given a reference (pointer to pointer)
// to the head of a list and an int, inserts
// a new node on the front of the list.
void push(Node** head_ref, int new_data)
{

	// 1. allocate node
	Node* new_node = new Node();

	// 2. put in the data
	new_node->data = new_data;

	// 3. Make next of new node as head
	new_node->next = (*head_ref);

	// 4. move the head to point
	// to the new node
	(*head_ref) = new_node;
}

void insertAfter(Node* prev_node, int new_data)
{
	// 1. check if the given prev_node
	// is NULL
	if (prev_node == NULL)
	{
		cout<<"The given previous node cannot be NULL";
		return;
	}


	Node* new_node = new Node();


	new_node->data = new_data;

	// 4. Make next of new node
	// as next of prev_node
	new_node->next = prev_node->next;

	// 5. move the next of prev_node
	// as new_node
	prev_node->next = new_node;
}


void append(Node** head_ref, int new_data)
{

	// 1. allocate node
	Node* new_node = new Node();

	//used in step 5
	Node *last = *head_ref;

	
	new_node->data = new_data;


	new_node->next = NULL;


	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
	{
		last = last->next;
	}

	
	last->next = new_node;
	return;
}

void printList(Node *node)
{
	while (node != NULL)
	{
		cout<<" "<<node->data;
		node = node->next;
	}
}

int main()
{


	Node* head = NULL;
	

	append(&head, 6);
	

	push(&head, 7);
	
	push(&head, 1);
	

	append(&head, 4);
	


	insertAfter(head->next, 8);
	
	cout<<"Created Linked list is: ";
	printList(head);
	
	return 0;
}
