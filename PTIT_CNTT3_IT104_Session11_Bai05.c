#include <stdio.h>
#include <stdlib.h>

// Struct node
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

// In danh sách liên kết đôi
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

// Hàm thêm phần tử đầu danh sách (void)
void insertHead(Node** head, int data) {
    Node* node = createNode(data);
    node->next = *head;
    if (*head != NULL) {
        (*head)->prev = node;
    }
    *head = node; // Cập nhật head mới
}

// Giải phóng bộ nhớ
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // Tạo danh sách
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    // Liên kết các node
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;

    Node* head = node1;

    int n;
    printf("Nhap so nguyen duong bat ky: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("So khong hop le!\n");
    } else {
        printf("Danh sach lien ket doi:\n");
        printList(head);
        insertHead(&head, n);  // Gọi hàm theo kiểu con trỏ kép
        printf("Sau khi them phan tu dau vao danh sach:\n");
        printList(head);
    }

    freeList(head);
    return 0;
}