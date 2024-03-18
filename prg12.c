#include<stdio.h>
#include<stdlib.h>
#define MAX_EMPLOYEES 100
#define MAX_MEMORY_LOCATIONS 50
int hash_table[MAX_MEMORY_LOCATIONS]; 
int count = 0; 
int hash_function(int key, int m) {
    return key % m;
}
void insert(int key, int m) {
    int index = hash_function(key, m);
    while (hash_table[index] != -1) {
        index = (index + 1) % m; 
    }
    hash_table[index] = key;
    count++;
}
void display(int m) {
    printf("\nHash Table contents are:\n");
    for (int i = 0; i < m; i++) {
        if (hash_table[i] != -1) {
            printf("T[%d] --> %d\n", i, hash_table[i]);
        }
    }
}
int main() {
    int n; 
    int m; 
    printf("Enter the number of employee records (N): ");
    scanf("%d", &n);
    printf("Enter the number of memory locations (m) for the hash table: ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        hash_table[i] = -1;
    }
    printf("Enter the four-digit key values (K) for %d employee records:\n", n);
    for (int i = 0; i < n; i++) {
        int key;
        scanf("%d", &key);
        insert(key, m);
    }
    display(m);
    return 0;
}
