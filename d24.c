#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

// Function to append node at end
struct Node* append(struct Node* head, int val) {
    struct Node* newNode = createNode(val);
    if (!head) return newNode;
    struct Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

// Function to delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {
    if (!head) return NULL;

    // If head itself holds the key
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* temp = head;
    while (temp->next && temp->next->data != key)
        temp = temp->next;

    if (temp->next) {
        struct Node* del = temp->next;
        temp->next = temp->next->next;
        free(del);
    }

    return head;
}

// Function to print list
void printList(struct Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
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

    head = deleteKey(head, key);
    printList(head);

    return 0;
}