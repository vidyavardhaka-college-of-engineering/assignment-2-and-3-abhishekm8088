#include <stdio.h>

#define M 11

int h1(int key) {
    int x = (key + 7) * (key + 7);
    x = x / 16;
    x = x + key;
    x = x % M;
    return x;
}

int reverse(int key) {
    int rev = 0;
    while (key > 0) {
        rev = rev * 10 + key % 10;
        key = key / 10;
    }
    return rev;
}

void doubleHashing(int keys[], int size) {
    int hashTable[M];
    for (int i = 0; i < M; i++) hashTable[i] = -1;

    for (int i = 0; i < size; i++) {
        int key = keys[i];
        int home = h1(key);
        int step = reverse(key) % M;
        int slot = home;
        while (hashTable[slot] != -1) {
            slot = (slot + step) % M;
        }
        hashTable[slot] = key;
    }

    printf("Final Hash Table (Double Hashing):\n");
    for (int i = 0; i < M; i++) {
        if (hashTable[i] != -1)
            printf("Slot %d: %d\n", i, hashTable[i]);
        else
            printf("Slot %d: \n", i);
    }
}

int main() {
    int keys[] = {43, 23, 1, 0, 15, 31, 4, 7, 11, 3};
    int size = sizeof(keys) / sizeof(keys[0]);
    doubleHashing(keys, size);
    return 0;
}
