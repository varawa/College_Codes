#include <stdio.h>

#define SIZE 10

int hash(int key) {
    return key % SIZE;
}

void insert(int hashtable[], int key, int value) {
    int index = hash(key);

    while (hashtable[index] != -1) {
        index = (index + 1) % SIZE;
    }

    hashtable[index] = value;
}

void display(int hashtable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d: %d\n", i, hashtable[i]);
    }
    printf("\n");
}

int search(int hashtable[], int key) {
    int index = hash(key);

    while (hashtable[index] != -1) {
        if (hashtable[index] == key) {
            return index;
        }
        index = (index + 1) % SIZE;
    }

    return -1;
}

void deleteKey(int hashtable[], int key) {
    int index = search(hashtable, key);

    if (index != -1) {
        hashtable[index] = -1;
        printf("Key %d deleted successfully.\n", key);
    } else {
        printf("Key %d not found in the hash table.\n", key);
    }
}

int main() {
    int hashtable[SIZE];

    for (int i = 0; i < SIZE; i++) {
        hashtable[i] = -1;
    }

    int choice, key, value;

    do {
        printf("Choose an operation:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insert(hashtable, key, value);
                break;

            case 2:
                printf("Enter a key to search: ");
                scanf("%d", &key);
                int searchResult = search(hashtable, key);
                if (searchResult != -1) {
                    printf("Key %d found at index %d.\n", key, searchResult);
                } else {
                    printf("Key %d not found in the hash table.\n", key);
                }
                break;

            case 3:
                printf("Enter a key to delete: ");
                scanf("%d", &key);
                deleteKey(hashtable, key);
                break;

            case 4:
                display(hashtable);
                break;

            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }

    } while (choice != 5);

    return 0;
}
