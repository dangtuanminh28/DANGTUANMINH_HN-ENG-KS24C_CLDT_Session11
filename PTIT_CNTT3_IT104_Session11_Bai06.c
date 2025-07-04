#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc cho danh sách liên kết đôi
typedef struct Node {
    int data;               // Dữ liệu của Node
    struct Node* next;      // Con trỏ đến phần tử tiếp theo
    struct Node* prev;      // Con trỏ đến phần tử trước đó
} Node;

// Hàm tạo 1 Node mới
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Cấp phát bộ nhớ
    newNode->data = value;       // Gán giá trị
    newNode->next = NULL;        // Chưa có node tiếp theo
    newNode->prev = NULL;        // Chưa có node trước
    return newNode;
}

// Hàm in ra danh sách liên kết đôi từ đầu đến cuối
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf("<->");
        } else {
            printf("->NULL");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Hàm xóa phần tử
// Hàm xóa phần tử đầu danh sách
void deleteHead(Node** head) {
    // Kiểm tra nếu danh sách rỗng
    if (*head == NULL) {
        return;
    }

    Node* temp = *head;         // Lấy node đầu tiên
    *head = (*head)->next;      // Di chuyển head sang node kế tiếp

    if (*head != NULL) {
        (*head)->prev = NULL;   // Gỡ liên kết ngược nếu còn phần tử sau
    }

    free(temp); // Giải phóng bộ nhớ node đầu
}
// Giải phóng bộ nhớ của toàn bộ danh sách
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp); // Giải phóng từng node
    }
}

int main() {
    // Tạo các node
    Node* node1 = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);

    // Liên kết các node với nhau
    node1->next = node2;

    node2->prev = node1;
    node2->next = node3;

    node3->prev = node2;
    node3->next = node4;

    node4->prev = node3;
    node4->next = node5;

    node5->prev = node4;

    Node* head = node1;

    printf("Danh sach lien ket doi:\n");
    printList(head);
    printf("Sau khi xoa phan tu dau cua danh sach:\n");
    deleteHead(&head);
    printList(head);

    freeList(head);

    return 0;
}