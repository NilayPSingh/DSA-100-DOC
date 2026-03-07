#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* append(struct Node* head, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    if (!head) return newNode;
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

int countOccurrences(struct Node* head, int key) {
    int count = 0;
    while (head) {
        if (head->data == key) count++;
        head = head->next;
    }
    return count;
}

int main() {
    int n, val, key;
    struct Node* head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        head = append(head, val);
    }
    scanf("%d", &key);
    printf("%d\n", countOccurrences(head, key));
    return 0;
}