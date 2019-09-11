#include <stdio.h>
#include <stdlib.h>

#define MAXN 100 + 10

int ans[MAXN][MAXN];

typedef struct Node {
    struct Node *ch, *next;
    struct Node *fa;
    int weight, sum;
} Node;

Node nodes[MAXN];

void addChild(Node *fa, Node *ch) {
    ch->fa = fa;
    ch->next = fa->ch;
    fa->ch = ch;

    // ch->fa = fa;
    // Node *c = fa->ch;
    // while (c->next && c->next->weight > ch->weight) c = c->next;

    // ch->next = c->next;
    // c->next = ch;
}

void dfs(Node *x) {
    if (x->fa) x->sum += x->fa->sum;
    for (Node *c = x->ch; c; c = c->next) {
        dfs(c);
    }
}

int t;
void solve(Node *x, int cnt) {
    if (x->fa) solve(x->fa, cnt);
    ans[cnt][++t] = x->weight;
}

int main() {
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);

    for (int i = 0; i < n; i++) {
        scanf("%d", &nodes[i].weight);
        nodes[i].sum = nodes[i].weight;
    }

    for (int i = 0; i < m; i++) {
        int fa;
        scanf("%d", &fa);

        int num;
        scanf("%d", &num);
        for (int i = 0; i < num; i++) {
            int ch;
            scanf("%d", &ch);

            addChild(nodes + fa, nodes + ch);
        }
    }

    for (int i = 0; i < n; i++) {
        if (!nodes[i].fa) {
            dfs(nodes + i);
            break;
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!nodes[i].ch && nodes[i].sum == s) {
            t = 0;
            solve(nodes + i, cnt);
            ans[cnt++][0] = t;
        }
    }

    for (int i = 0; i < cnt; i++) {
        for (int j = 1; j <= ans[i][0]; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}
