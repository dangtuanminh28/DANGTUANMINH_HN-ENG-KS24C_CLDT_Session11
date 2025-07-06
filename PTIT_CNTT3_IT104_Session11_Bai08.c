#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc cho danh sách liên kết đôi
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
    printf("Danh sach lien ket doi:\n");
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

// Giải phóng bộ nhớ
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Hàm xóa node tại vị trí bất kỳ
Node* targetDelete(Node* head, int position) {
    if (head == NULL || position < 0) {
        printf("Vi tri khong hop le.\n");
        return head;
    }

    Node* current = head;
    int index = 0;

    // Xóa node đầu
    if (position == 0) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(current);
        return head;
    }

    // Duyệt đến vị trí
    while (current != NULL && index < position) {
        current = current->next;
        index++;
    }

    if (current == NULL) {
        printf("Vi tri khong ton tai.\n");
        return head;
    }

    if (current->prev != NULL)
        current->prev->next = current->next;
    if (current->next != NULL)
        current->next->prev = current->prev;

    free(current);
    return head;
}

int main() {
    // Tạo danh sách
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    node1->next = node2;
    node2->prev = node1; node2->next = node3;
    node3->prev = node2; node3->next = node4;
    node4->prev = node3; node4->next = node5;
    node5->prev = node4;

    Node* head = node1;

    printList(head);

    int pos;
    printf("Nhap vi tri muon xoa: ");
    scanf("%d", &pos);

    head = targetDelete(head, pos);
    printList(head);
    printf("Sau khi xoa:\n");

    freeList(head);
    return 0;
}