#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>  // Thêm thư viện để dùng kiểu bool

// Định nghĩa cấu trúc cho danh sách liên kết đôi
typedef struct Node {
    int data;               // Dữ liệu của Node
    struct Node* next;      // Con trỏ đến phần tử tiếp theo
    struct Node* prev;      // Con trỏ đến phần tử trước đó
} Node;

// Hàm tạo 1 Node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Cấp phát bộ nhớ
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Hàm in ra danh sách liên kết đôi
void printList(Node* head) {
    Node* temp = head;
    int index = 1;
    printf("Danh sach lien ket doi:\n");
    while (temp != NULL) {
        printf("Node %d: %d\n", index++, temp->data);
        temp = temp->next;
    }
}

// Hàm tìm kiếm một giá trị trong danh sách
bool searchNode(Node* head, int target) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == target) {
            return true; // Tìm thấy
        }
        current = current->next;
    }
    return false; // Không tìm thấy
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
    // Tạo các node
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

    printList(head);

    int valueToSearch;
    printf("Nhap gia tri can tim kiem: ");
    scanf("%d", &valueToSearch);

    // Gọi hàm tìm kiếm
    bool found = searchNode(head, valueToSearch);
    if (found) {
        printf("True.\n", valueToSearch);
    } else {
        printf("False.\n", valueToSearch);
    }

    freeList(head);

    return 0;
}