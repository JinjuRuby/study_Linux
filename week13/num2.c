#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int page_number;
    struct Node* next;
} Node;

Node* createNode(int page_number);
double calculateHitRate(int total_references, int total_hits);
double measureHitRate(char* trace_file, int cache_size);








void insert_front(Node **pointer, int value);
void insert_rear(Node **pointer, int value);
Node *search(Node *pointer, int value);
void delete(Node **pointer, int value);




int main() {
	Node* list = NULL;
	File* file = fopen("tr.2c39.txt", r);
	int value;
	int total_hit = 0;
	int page_count;
	int hit = 0;
	int list_range = 100;
	while(fsanf(file, "%d", &value) != EOF) {
		insert_rear(&list, value);
		page_count++;
		if(
			if(list_range < page_count) {







			


    


/*	// trace: tr.2c39
    printf("trace: tr.2c39\n");
    printf("Cache Size: 100\n");
    printf("Replacement Algorithm: FIFO\n");
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.2c39.txt", 100));
    printf("Cache Size: 500\n");
    printf("Replacement Algorithm: FIFO\n");
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.2c39.txt", 500));
    printf("Cache Size: 1000\n");
    printf("Replacement Algorithm: FIFO\n");
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.2c39.txt", 1000));
    printf("\n");

    // trace: tr.db2
    printf("trace: tr.db2\n");
    printf("Cache Size: 100\n");
    printf("Replacement Algorithm: FIFO\n");
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.db2.txt", 100));
    printf("Cache Size: 500\n");
    printf("Replacement Algorithm: FIFO\n");
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.db2.txt", 500));
    printf("Cache Size: 1000\n");
    printf("Replacement Algorithm: FIFO\n");
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.db2.txt", 1000));
    printf("\n");

    // trace: tr.sort
    printf("trace: tr.sort\n");
    printf("Cache Size: 100\n");
    printf("Replacement Algorithm: FIFO\n");
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.sort.txt", 100));
    printf("Cache Size: 500\n");
    printf("Replacement Algorithm: FIFO\n");
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.sort.txt", 500));
    printf("Cache Size: 1000\n");
    printf("Replacement Algorithm: FIFO\n");
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.sort.txt", 1000));
    printf("\n");

    // trace: tr.zipf_20_80
    printf("trace: tr.zipf_20_80\n");
    printf("Cache Size: 100\n");
    printf("Replacement Algorithm: FIFO\n");
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.zipf_20_80.txt", 100));
    printf("Cache Size: 500\n");
    printf("Replacement Algorithm: FIFO\n");
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.zipf_20_80.txt", 500));
    printf("Cache Size: 1000\n");
    printf("Replacement Algorithm: FIFO\n");
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.zipf_20_80.txt", 1000));

    return 0;
*/


}

Node* createNode(int page_number) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->page_number = page_number;
    newNode->next = NULL;
    return newNode;
}

double calculateHitRate(int total_references, int total_hits) {
    if (total_references == 0) {
        return 0.0;
    }
    return (double)total_hits / total_references * 100.0;
}

double measureHitRate(char* trace_file, int cache_size) {
    Node* cache = NULL; // Linked list to store the cache
    int total_references = 0; // Total memory references
    int total_hits = 0; // Total cache hits

    FILE* file = fopen(trace_file, "r"); // Open the trace file

    if (file == NULL) {
        printf("Failed to open the trace file.\n");
        return 0.0;
    }

    int page_number;
    while (fscanf(file, "%d", &page_number) != EOF) {
        total_references++;

        // Check if the page number already exists in the cache
        int is_hit = 0;
        Node* current = cache;
        Node* prev = NULL;
        while (current != NULL) {
            if (current->page_number == page_number) {
                is_hit = 1;
                break;
            }
            prev = current;
            current = current->next;
        }

        if (is_hit) {
            total_hits++;
        } else {
            // If the cache is full, remove the oldest page
            if (total_references > cache_size) {
                Node* temp = cache;
                cache = cache->next;
                free(temp);
            }

            // Insert the new page at the end of the cache
            Node* newNode = createNode(page_number);
            if (prev != NULL) {
                prev->next = newNode;
            } else {
                cache = newNode;
            }
        }
    }

    fclose(file); // Close the trace file

    // Calculate and return the hit rate
    return calculateHitRate(total_references, total_hits);
}










void insert_front(Node **pointer, int value) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->page_number = value;
        new_node->next = *pointer;
        *pointer = new_node;
}


void insert_rear(Node **pointer, int value) {
        Node *new_node = (Node *)malloc(sizeof(Node));
        new_node->page_number = value;
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
                if(search_node->page_number == value) {
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



