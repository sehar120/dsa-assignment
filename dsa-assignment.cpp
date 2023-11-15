#include<iostream>
#include <stdio.h>
#include <stdlib.h>
// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to search for a value in the linked list
int search(struct Node* head, int value) {
    struct Node* current = head;
    int position = 1;

    while (current != NULL) {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        position++;
    }

    return -1; // Return -1 if the value is not found
}

// Function to update a node at a specific position
void updateAtPosition(struct Node** head, int position, int newValue) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = *head;
    int currentPosition = 1;

    while (current != NULL && currentPosition < position) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL || currentPosition > position) {
        printf("Position not found in the list.\n");
        return;
    }

    current->data = newValue;
    printf("Node at position %d updated with value %d.\n", position, newValue);
}

// Function to insert a new node at a specific position
void insertAtPosition(struct Node** head, int position, int value) {
    struct Node* newNode = createNode(value);

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("Node inserted at the beginning.\n");
        return;
    }

    struct Node* current = *head;
    int currentPosition = 1;

    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL || currentPosition > position - 1) {
        printf("Position not found in the list.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
    printf("Node inserted at position %d.\n", position);
}

// Function to delete the first node
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);

    printf("Node deleted from the beginning.\n");
}

// Function to delete the last node
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Node deleted from the end.\n");
        return;
    }

    struct Node* current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;

    printf("Node deleted from the end.\n");
}

// Function to delete a node from a specific position
void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty, cannot delete.\n");
        return;
    }

    struct Node* current = *head;
    struct Node* temp;

    if (position == 1) {
        *head = current->next;
        free(current);
        printf("Node deleted from position 1.\n");
        return;
    }

    int currentPosition = 1;

    while (current != NULL && currentPosition < position - 1) {
        current = current->next;
        currentPosition++;
    }

    if (current == NULL || current->next == NULL || currentPosition > position - 1) {
        printf("Position not found in the list.\n");
        return;
    }

    temp = current->next;
    current->next = temp->next;
    free(temp);

    printf("Node deleted from position %d.\n", position);
}

// Function to search for a value and update it
void searchAndUpdate(struct Node** head, int searchValue, int newValue) {
    int position = search(*head, searchValue);

    if (position != -1) {
        updateAtPosition(head, position, newValue);
    } else {
        printf("Value not found in the list.\n");
    }
}

// Main function to test the linked list
int main() {
    struct Node* head = NULL;

    // Test the functions
    insertAtPosition(&head, 1, 10);
    insertAtPosition(&head, 2, 20);
    insertAtPosition(&head, 3, 30);
    displayList(head);

    searchAndUpdate(&head, 20, 25);
    displayList(head);

    deleteFromBeginning(&head);
    displayList(head);

    deleteFromEnd(&head);
    displayList(head);

    insertAtPosition(&head, 2, 15);
    displayList(head);

    deleteFromPosition(&head, 2);
    displayList(head);

    return 0;
}







