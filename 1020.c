#include <stdio.h>
#include <string.h>

#define MAXN 30 + 5

typedef struct Node {
    int lc, rc;
} Node;

Node nodes[MAXN];

int pOdr[MAXN], iOdr[MAXN];

int build(int l1, int r1, int l2, int r2) {
    if (l1 > r1) return 0;

    int root = pOdr[r2];

    int tmp = l1;
    while (iOdr[tmp] != root) tmp++;

    int cnt = tmp - l1;
    nodes[root].lc = build(l1, tmp - 1, l2, l2 + cnt - 1);
    nodes[root].rc = build(tmp + 1, r1, l2 + cnt, r2 - 1);

    return root;
}

typedef struct Queue {
    int a[MAXN];
    int size;

    int head, tail;
} Queue;

void push(Queue *q, int x) {
    q->a[q->tail++] = x;
    q->size++;

    q->tail %= MAXN;

    // printf("tail = %d head = %d\n", q.tail, q.head);
    // for (int i = q.tail; i < q.head; i++) {
    //     printf("%d ", q.a[i]);
    // }
    // printf("\n");
}

int pop(Queue *q) {
    q->head++;
    q->size--;

    q->head %= MAXN;

    return q->a[q->head - 1];
}

int empty(Queue *q) {
    return q->size == 0;
}

int ans[MAXN];
int cnt = 0;

void bfs(int x) {
    Queue q;
    memset(q.a, 0, sizeof(q.a));
    q.head = q.size = q.tail = 0;

    push(&q, x);
    while (!empty(&q)) {
        int tmp = pop(&q);
        // printf("%d ", tmp);
        ans[cnt++] = tmp;

        if (nodes[tmp].lc) push(&q, nodes[tmp].lc);
        if (nodes[tmp].rc) push(&q, nodes[tmp].rc);
    }
}

// void dfs(int x) {
//     printf("%d ", x);
//     if (nodes[x].lc) dfs(nodes[x].lc);
//     if (nodes[x].rc) dfs(nodes[x].rc);
// }

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &pOdr[i]);
        }
        for (int i = 1; i <= n; i++) {
            scanf("%d", &iOdr[i]);
        }

        int root = build(1, n, 1, n);
        // printf("%d\n", root);
        // dfs(root);

        bfs(root);

        for (int i = 0; i < cnt; i++) {
            if (i != cnt - 1) printf("%d ", ans[i]);
            else printf("%d\n", ans[i]);
        }
    }

    return 0;
}
