#include <stdio.h>

#define TABLE_SIZE 10

int hash(int key, int size) {
    return key % size;
}

int doubleHash(int key, int size) {
    return 1 + (key % (size - 1));
}

void insert(int table[], int size, int key, int value) {
    int index = hash(key, size);
    int step = doubleHash(key, size);

    while (table[index] != -1) {
        index = (index + step) % size;
    }

    table[index] = value;
}

int search(int table[], int size, int key) {
    int index = hash(key, size);
    int step = doubleHash(key, size);

    while (table[index] != key && table[index] != -1) {
        index = (index + step) % size;
    }

    return (table[index] == key) ? index : -1;
}

void display(int table[], int size) {
    printf("Array:\n");
    for (int i = 0; i < size; ++i) {
        printf("[%d] -> ", i);
        if (table[i] != -1) {
            printf("%d", table[i]);
        }
        printf("\n");
    }
}

void printTable(int table[], int size) {
    display(table, size);
}

void searchKey(int table[], int size) {
    int keyToSearch;
    printf("Enter key to search: ");
    scanf("%d", &keyToSearch);

    int result = search(table, size, keyToSearch);

    if (result != -1) {
        printf("Key %d found at index %d\n", keyToSearch, result);
    } else {
        printf("Key %d not found in the array.\n", keyToSearch);
    }
}

int main() {
    int array[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; ++i) {
        array[i] = -1;
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

    return 0;
}
