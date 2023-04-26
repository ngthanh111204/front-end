#include <bits/stdc++.h>

struct Node {
    int data;
    struct Node *next;
};

// hàm thêm m?t ph?n t? vào cu?i danh sách
void InsertLast(Node *&head, int ele) {
    Node *new_node = new Node;
    new_node->data = ele;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// hàm chèn m?t ph?n t? vào danh sách tru?c v? trí pos
void InsertBeforePos(Node *&head, int ele, int pos) {
    Node *new_node = new Node;
    new_node->data = ele;
    if (pos == 1 || head == NULL) {
        new_node->next = head;
        head = new_node;
    } else {
        Node *temp = head;
        for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }
}

// hàm xóa ph?n t? ? v? trí pos
void Delete(Node *&head, int pos) {
    if (head == NULL) {
        return;
    }
    Node *temp = head;
    if (pos == 1) {
        head = head->next;
        delete temp;
    } else {
        for (int i = 1; i < pos - 1 && temp->next != NULL; i++) {
            temp = temp->next;
        }
        if (temp->next != NULL) {
            Node *del_node = temp->next;
            temp->next = del_node->next;
            delete del_node;
        }
    }
}

// hàm tính trung bình c?ng các ph?n t? trong danh sách
float Average(Node *head) {
    if (head == NULL) {
        return 0;
    }
    float sum = 0;
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        sum += temp->data;
        count++;
        temp = temp->next;
    }
    return sum / count;
}

int main() {
    Node *head = NULL;
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        int ele;
        scanf("%d",&ele);
        InsertLast(head, ele);
    }
    while (true) {
        char kt;
        scanf("%s",&kt);
        if (kt == 'i') {
            int ele, pos;
            scanf("%d %d",&ele ,&pos);
            InsertBeforePos(head, ele, pos);
        } else if (kt == 'd') {
            int pos;
            scanf("%d",&pos);
            Delete(head, pos);
        } else if (kt == 'a') {
            float avg = Average(head);
			printf("%.4f",avg);
			printf("\n");
        } else if (kt == '0') {
            break;
        }
    }
    return 0;
}
