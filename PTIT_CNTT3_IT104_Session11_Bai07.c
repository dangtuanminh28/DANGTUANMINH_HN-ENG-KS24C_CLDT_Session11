#include <stdio.h>
#include <stdlib.h>

// Cấu trúc Node danh sách liên kết đôi
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Tạo node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// In danh sách
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf("<->");
        else
            printf("->NULL");
        temp = temp->next;
    }
    printf("\n");
}

// Thêm node vào vị trí ất kỳ
void addRandomPos(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (position <= 0 || *head == NULL) {
        // Chèn đầu danh sách
        newNode->next = *head;
        if (*head != NULL)
            (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    int index = 0;

    // Duyệt đến node trước vị trí cần chèn
    while (temp->next != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

// Giải phóng danh sách
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {

    Node* head = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    head->next = node2;
    node2->prev = head;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;

    printf("Danh sach ban dau:\n");
    printList(head);

    int value, position;
    printf("vaule: ");
    scanf("%d", &value);
    printf("position: ");
    scanf("%d", &position);

    addRandomPos(&head, value, position);

    printf("Danh sach sau khi chen:\n");
    printList(head);

    freeList(head);
    return 0;
}