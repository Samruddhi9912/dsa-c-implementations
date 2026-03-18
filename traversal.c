#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* queue[100];
int front = -1, rear = -1;

void enqueue(struct Node* node) {
    if (rear == 99) return;
    if (front == -1) front = 0;
    queue[++rear] = node;
}

struct Node* dequeue() {
    if (front == -1 || front > rear) return NULL;
    return queue[front++];
}

struct Node* buildTree() {
    int data;
    scanf("%d", &data);

    if (data == -1) return NULL;

    struct Node* root = createNode(data);
    enqueue(root);

    while (front <= rear) {
        struct Node* temp = dequeue();

        int leftData, rightData;

        scanf("%d", &leftData);
        if (leftData != -1) {
            temp->left = createNode(leftData);
            enqueue(temp->left);
        }

        scanf("%d", &rightData);
        if (rightData != -1) {
            temp->right = createNode(rightData);
            enqueue(temp->right);
        }
    }

    return root;
}

void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

void levelOrder(struct Node* root) {
    if (root == NULL) return;

    front = rear = -1;

    enqueue(root);

    while (front <= rear) {
        struct Node* temp = dequeue();
        printf("%d ", temp->data);

        if (temp->left) enqueue(temp->left);
        if (temp->right) enqueue(temp->right);
    }
}

int main() {
    struct Node* root = buildTree();

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    levelOrder(root);

    return 0;
}