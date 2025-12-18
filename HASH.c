#include <stdio.h>

#define SIZE 100

struct Employee {
    int key;
    int used;
};

struct Employee HT[SIZE];
int m;


int hashFunction(int key) {
    return key % m;
}

void insert(int key) {
    int index = hashFunction(key);
    int startIndex = index;

    while (HT[index].used == 1) {
        index = (index + 1) % m;
        if (index == startIndex) {
            printf("Hash table is full. Cannot insert key %d\n", key);
            return;
        }
    }

    HT[index].key = key;
    HT[index].used = 1;
    printf("Key %d inserted at address %d\n", key, index);
}

void display() {
    int i;
    printf("\nHash Table Contents:\n");
    printf("Address\tKey\n");
    for (i = 0; i < m; i++) {
        if (HT[i].used)
            printf("%d\t%d\n", i, HT[i].key);
        else
            printf("%d\t--\n", i);
    }
}

int main() {
    int n, i, key;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    for (i = 0; i < m; i++)
        HT[i].used = 0;

    printf("Enter number of employee records: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter 4-digit employee key: ");
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}
