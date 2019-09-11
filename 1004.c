#include <stdio.h>

#define MAXN 100 + 10

typedef struct Node {
    int id;
    struct Node *fa;
    struct Node *ch, *next;

    int depth;
} Node;

Node nodes[MAXN];

void addChild(Node *fa, Node *ch) {
    ch->fa = fa;
    ch->next = fa->ch;
    fa->ch = ch;
}

void dfs(Node *x) {
    for (Node *ch = x->ch; ch; ch = ch->next) {
        ch->depth = x->depth + 1;
        dfs(ch);
    }
}

int ans[MAXN];
int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF && n != 0) {
        for (int i = 0; i < m; i++) {
            int fa;
            scanf("%d", &fa);
            int k;
            scanf("%d", &k);

            for (int i = 0; i < k; i++) {
                int id;
                scanf("%d", &id);

                addChild(nodes + fa, nodes + id);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (nodes[i].fa == NULL) {
                nodes[i].depth = 0;
                dfs(nodes + i);
                break;
            }
        }

        int maxDepth = 0;
        for (int i = 1; i <= n; i++) {
            if (nodes[i].ch == NULL) ans[nodes[i].depth]++;
            
            maxDepth = (nodes[i].depth > maxDepth ? nodes[i].depth : maxDepth);
        }

        for (int i = 0; i <= maxDepth; i++) {
            if (i == maxDepth) printf("%d\n", ans[i]);
            else printf("%d ", ans[i]);
        }
    }
    return 0;
}
