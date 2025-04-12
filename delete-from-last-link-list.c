# delete-from-last-link-list-
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void delete_from_end(struct Node** head) {
    if (*head == NULL) {
        printf("The linked list is empty, nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;


    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        return;
    }


    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void linklistTraversal(struct Node* ptr) {
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;


    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    if (head == NULL || second == NULL || third == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    printf("\nOriginal linked list:\n");
    linklistTraversal(head);


    at_beginning(&head, 5);
    printf("\nLinked list after insertion at the beginning:\n");
    linklistTraversal(head);


    delete_from_beginning(&head);
    printf("\nLinked list after deletion from the beginning:\n");
    linklistTraversal(head);

    delete_from_end(&head);
    printf("\nLinked list after deletion from the end:\n");
    linklistTraversal(head);

    return 0;
}
