#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int block_number;
	struct node *next;
}Node;

void insert_front(Node **pointer, int value);
void insert_rear(Node **pointer, int value);
Node* search(Node *pointer, int value);
void delete(Node **pointer, int value);
void print_list(Node *pointer);

int main(void){
	Node *list =NULL;
	insert_front(&list, 10);
	
	insert_rear(&list, 20);
	insert_front(&list, 30);
	insert_rear(&list, 40);

	//delete(&list, 30);
	delete(&list, list->block_number);

	print_list(list);


	free(list);

	return 0;
}

void insert_front(Node **pointer, int value) {
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->block_number = value;
	new_node->next = *pointer;
	*pointer = new_node;
}

void insert_rear(Node **pointer, int value) {
	Node *new_node = (Node *)malloc(sizeof(Node));
	new_node->block_number = value;
	new_node->next = NULL;

	if (*pointer == NULL) {
		*pointer = new_node;
	} else {
		Node *search_node = *pointer;
		while(search_node->next != NULL) {
			search_node = search_node->next;
		}
		search_node->next = new_node;
	}
}

Node *search(Node *pointer, int value) {
	Node *search_node = pointer;

	while(search_node != NULL) {
		if(search_node->block_number == value) {
			return search_node;
		}
		search_node = search_node->next;
	}
	return NULL;
}

void delete(Node **pointer, int value) {
	if(*pointer == NULL)
		return;
	Node *search_node = search(*pointer, value);
	if(search_node == NULL) {
		return;
	}
	*pointer = (*pointer)->next;
	free(search_node);
}


void print_list(Node *pointer) {
	if (pointer == NULL) {
		return;
	} else {
		Node *search_node = pointer;
		while(search_node->next!=NULL) {
			printf("%d ",search_node->block_number);
			search_node = search_node->next;
			}
		printf("%d\n",search_node->block_number);
		}
}

