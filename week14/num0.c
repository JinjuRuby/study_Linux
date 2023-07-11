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
	char* file_name = "tr.2c39.txt";
	FILE* file = fopen(file_name, "r");
	int cache = 100;
	int value;
	int count = 0;
	while(fscanf(file, "%d", &value) != EOF) {
		count++;
		if(search(list, value) != NULL) {
			delete(&list, value);
		}
		if(cache < count) {
			Node* a = list;
			delete(&list, list->block_number);
		}
			insert_rear(&list, value);
			Node* a = list;
			while(a != NULL) {
				printf("%d ",a->block_number);
				a = a->next;
			}
			printf("\n");
	}

		


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
	Node *search_node = (Node *)malloc(sizeof(Node));
	search_node = search(*pointer, value);
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

