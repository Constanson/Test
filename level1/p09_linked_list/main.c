#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createList(int* values, int size) {
    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < size; ++i) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (!newNode) {
            perror("Failed to create");
            exit(EXIT_FAILURE);
        }
        newNode->value = values[i];
        newNode->next = NULL;

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    while (current) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}


int findValue(Node* head, int target) {
    int index = 0;
    Node* current = head;
    while (current) {
        if (current->value == target) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}


void deleteList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int values[] = {1, 2, 3, 5, 4, 5, 6};
    int size = sizeof(values) / sizeof(values[0]);

    Node* list = createList(values, size);
    printf("Original list: ");
    printList(list);

    list = reverseList(list);
    printf("Reversed list: ");
    printList(list);

    int firstFiveNode = findValue(list, 5);
    printf("Locate first 5 node: %d\n", firstFiveNode);

    if (firstFiveNode != -1) {
        Node* current = list;
        for (int i = 0; i <= firstFiveNode; ++i) {
            current = current->next;
        }
        int nextFiveIndex = findValue(current, 5);
        if (nextFiveIndex != -1) {
            nextFiveIndex += firstFiveNode + 1; // 累计索引
        }
        printf("Index of next 5: %d\n", nextFiveIndex);
    }
    deleteList(list);

    return 0;
}