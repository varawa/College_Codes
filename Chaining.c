#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

void insert(Node* table[], int size, int key, int value) {
    int index = key % size;

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    if (table[index] == NULL) {
        table[index] = newNode;
    } else {
        Node* current = table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int search(Node* table[], int size, int key) {
    int index = key % size;

    Node* current = table[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    return -1; // Key not found
}

void display(Node* table[], int size) {
    printf("Hash Table:\n");
    for (int i = 0; i < size; ++i) {
        printf("[%d] -> ", i);
        Node* current = table[i];
        while (current != NULL) {
            printf("(%d, %d) ", current->key, current->value);
            current = current->next;
        }
        printf("\n");
    }
}

void printTable(Node* table[], int size) {
    display(table, size);
}

void searchKey(Node* table[], int size) {
    int keyToSearch;
    printf("Enter key to search: ");
    scanf("%d", &keyToSearch);

    int result = search(table, size, keyToSearch);

    if (result != -1) {
        printf("Value for key %d: %d\n", keyToSearch, result);
    } else {
        printf("Key %d not found in the hash table.\n", keyToSearch);
    }
}

int main() {
    Node* array[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; ++i) {
        array[i] = NULL;
    }

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Print Table\n");
        printf("3. Search\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    int key, value;
                    printf("Enter key and value to insert: ");
                    scanf("%d %d", &key, &value);
                    insert(array, TABLE_SIZE, key, value);
                    break;
                }
            case 2:
                printTable(array, TABLE_SIZE);
                break;
            case 3:
                searchKey(array, TABLE_SIZE);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    // Free allocated memory
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Node* current = array[i];
        while (current != NULL) {
            Node* next = current->next;
            free(current);
            current = next;
        }
    }

    return 0;
}
