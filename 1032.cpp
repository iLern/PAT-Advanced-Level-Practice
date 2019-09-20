#include <cstdio>

const int MAXN = 100000;

struct Node {
    char data;
    Node *next;

    bool vis;

    Node() {
        data = '\0';
        next = nullptr;
        vis = false;
    }
} nodes[MAXN];

int main() {
    int w1, w2, n;
    scanf("%d%d%d", &w1, &w2, &n);

    for (int i = 0; i < n; i++) {
        int address, next;
        char data;
        scanf("%d %c%d", &address, &data, &next);

        nodes[address].data = data;

        if (next != -1) nodes[address].next = &nodes[next];
        else nodes[address].next = nullptr;
    }

    for (Node *node = &nodes[w1]; node; node = node->next) {
        node->vis = true;
    }

    bool flag = false;
    for (Node *node = &nodes[w2]; node; node = node->next) {
        if (node->vis) {
            printf("%05d\n", node - nodes);
            flag = true;
            break;
        }
    }

    if (!flag) printf("-1\n");
    return 0;
}
