
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the front of the linked list
void insertAtFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a node in ascending order
void insertInOrder(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Function to delete the first node of the linked list
void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node before a specified position
void deleteBeforePosition(struct Node** head, int position) {
    if (*head == NULL || position <= 1) {
        printf("Invalid position.\n");
        return;
    }
    struct Node* temp = *head;
    if (position == 2) {
        *head = temp->next;
        free(temp);
        return;
    }
    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL || temp == NULL) {
        printf("Position does not exist.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Function to delete a node after a specified position
void deleteAfterPosition(struct Node** head, int position) {
    if (*head == NULL || position < 1) {
        printf("Invalid position.\n");
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Position does not exist or there is no node after this position.\n");
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to drive the program
int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Insert at end\n");
        printf("3. Insert in ascending order\n");
        printf("4. Delete first node\n");
        printf("5. Delete node before specified position\n");
        printf("6. Delete node after specified position\n");
        printf("7. Print list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertAtFront(&head , data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert in ascending order: ");
                scanf("%d", &data);
                insertInOrder(&head, data);
                break;
            case 4:
                deleteFirstNode(&head);
                break;
            case 5:
                printf("Enter position to delete node before: ");
                scanf("%d", &position);
                deleteBeforePosition(&head, position);
                break;
            case 6:
                printf("Enter position to delete node after: ");
                scanf("%d", &position);
                deleteAfterPosition(&head, position);
                break;
            case 7:
                printList(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}