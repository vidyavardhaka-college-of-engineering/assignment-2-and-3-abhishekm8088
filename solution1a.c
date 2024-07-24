#include <stdio.h>

#define TABLE_SIZE 11

// Hash function
int h1(int key) {
    int x = (key + 7) * (key + 7);
    x = x / 16;
    x = x + key;
    x = x % TABLE_SIZE;
    return x;
}

// Function to insert a key using linear probing
void insert(int hashTable[], int key) {
    int homeSlot = h1(key);
    int slot = homeSlot;
    while (hashTable[slot] != -1) {
        slot = (slot + 1) % TABLE_SIZE;
    }
    hashTable[slot] = key;
}

int main() {
    // Initialize the hash table with -1 to indicate empty slots
    int hashTable[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

    // List of keys to insert
    int keys[] = {43, 23, 1, 0, 15, 31, 4, 7, 11, 3};
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    // Insert each key into the hash table
    for (int i = 0; i < numKeys; i++) {
        insert(hashTable, keys[i]);
    }

    // Print the final contents of the hash table
    printf("Final Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Slot %d: %d\n", i, hashTable[i]);
    }

    return 0;
}
