#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createNode(int value);
double calculateHitRate(int total_references, int total_hits);
double measureHitRate(char* trace_file, int cache_size);

int main() {
    // trace: tr.2c39
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.2c39.txt", 100));
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.2c39.txt", 500));
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.2c39.txt", 1000));
    printf("\n");

    // trace: tr.db2
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.db2.txt", 100));
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.db2.txt", 500));
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.db2.txt", 1000));
    printf("\n");

    // trace: tr.sort
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.sort.txt", 100));
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.sort.txt", 500));
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.sort.txt", 1000));
    printf("\n");

    // trace: tr.zipf_20_80
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.zipf_20_80.txt", 100));
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.zipf_20_80.txt", 500));
    printf("Hit Rate: %.2lf%%\n", measureHitRate("tr.zipf_20_80.txt", 1000));

    return 0;
}

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

double calculateHitRate(int total_references, int total_hits) {
    if (total_references == 0) {
        return 0;
    }
    return (double)total_hits / total_references * 100.0;
}

double measureHitRate(char* trace_file, int cache_size) {
    Node* cache = NULL; // Linked list to store the cache
    int total_references = 0; // Total memory references
    int total_hits = 0; // Total cache hits

    FILE* file = fopen(trace_file, "r"); // Open the trace file

    int value;
    while (fscanf(file, "%d", &value) != EOF) {
        total_references++;

        // Check if the page number already exists in the cache
        int is_hit = 0;
        Node* current = cache;
        Node* prev = NULL;
        while (current != NULL) {
            if (current->value == value) {
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
            Node* newNode = createNode(value);
            if (prev != NULL) {
                prev->next = newNode;
            } else {
                cache = newNode;
            }
        }
    }

    fclose(file);
    return calculateHitRate(total_references, total_hits);
}
