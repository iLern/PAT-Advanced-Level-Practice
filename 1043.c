#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000 + 10

typedef struct Node {
    int data;
    struct Node *lc, *rc;
} Node;

Node *newNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->lc = newNode->rc = NULL;

    return newNode;
}

void insert(Node **root, int data) {
    if (!(*root)) *root = newNode(data);
    else {
        if (data < (*root)->data) insert(&(*root)->lc, data);
        else insert(&(*root)->rc, data);
    }
}

int cnt = 0;

int pOrd[MAXN];
void preOrder(Node *root) {
    if (root) pOrd[cnt++] = root->data;
    if (root->lc) preOrder(root->lc);
    if (root->rc) preOrder(root->rc);
}

int pOrdM[MAXN];
void preOrderMirror(Node *root) {
    if (root) pOrdM[cnt++] = root->data;
    if (root->rc) preOrderMirror(root->rc);
    if (root->lc) preOrderMirror(root->lc);
}

int pstOrd[MAXN];
void postOrder(Node *root) {
    if (root->lc) postOrder(root->lc);
    if (root->rc) postOrder(root->rc);
    if (root) pstOrd[cnt++] = root->data;
}

int pstOrdM[MAXN];
void postOrderMirror(Node *root) {
    if (root->rc) postOrderMirror(root->rc);
    if (root->lc) postOrderMirror(root->lc);
    if (root) pstOrdM[cnt++] = root->data;
}

int a[MAXN];
int main() {
    int n;
    scanf("%d", &n);

    Node *root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        insert(&root, a[i]);
    }

    cnt = 0;
    preOrder(root);

    cnt = 0;
    preOrderMirror(root);

    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] != pOrd[i]) {
            flag = 0;
            break;
        }
    }

    int flag2 = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] != pOrdM[i]) {
            flag2 = 0;
            break;
        }
    }

    if (!flag && !flag2) printf("NO\n");

    if (flag) {
        printf("YES\n");

        cnt = 0;
        postOrder(root);
        for (int i = 0; i < n; i++) {
            if (i != n - 1) printf("%d ", pstOrd[i]);
            else printf("%d\n", pstOrd[i]);
        }
    } else if (flag2) {
        printf("Yes\n");

        cnt = 0;
        postOrderMirror(root);
        for (int i = 0; i < n; i++) {
            if (i != n - 1) printf("%d ", pstOrdM[i]);
            else printf("%d\n", pstOrdM[i]);
        }
    }

    return 0;
}
