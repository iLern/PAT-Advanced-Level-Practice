#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

const int MAXN = 100000 + 10;
const int MAXLOG = 20;

struct Node {
    int id;
    Node* lc, *rc;

    Node *fa;

    int depth;

    Node(int id) : id(id) {
        lc = rc = fa = nullptr;
        depth = 0;
    }
} *nodes[MAXN], *f[MAXN][MAXLOG + 10];

std::vector<int> prd, inrd;
//l1 r1->prd l2 r2->inrd
Node* build(int l1, int r1, int l2, int r2) {
    if (l1 > r1) return nullptr;

    Node *root = new Node(prd[l1]);

    int tmp = l2;
    while (inrd[tmp] != root->id) tmp++;

    int num = tmp - l2;
    root->lc = build(l1 + 1, l1 + num, l2, tmp - 1);
    root->rc = build(l1 + num + 1, r1, tmp + 1, r2);

    if (root->lc) root->lc->fa = root;
    if (root->rc) root->rc->fa = root;

    return root;
}

void dfs(Node *root, bool isRoot) {
    nodes[root->id] = root;

    if (isRoot) root->depth = 1;
    if (root->lc) {
        root->lc->depth = root->depth + 1;
        dfs(root->lc, false);
    }
    if (root->rc) {
        root->rc->depth = root->depth + 1;
        dfs(root->rc, false); 
    }

    f[root->id][0] = root->fa;
}

void init(int n) {
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i <= n; i++) {
            if (f[i][j - 1]) f[i][j] = f[f[i][j - 1]->id][j - 1];
        }
    }
}

int lca(int u, int v) {
    Node *x = nodes[u], *y = nodes[v];
    if (x->depth < y->depth) std::swap(x, y);

    if (x->depth > y->depth) {
        for (int i = MAXLOG; i >= 0; i--) {
            if (f[x->id][i] && f[x->id][i]->depth >= y->depth) {
                x = f[x->id][i];
            }
        }
    }

    if (x != y) {
        for (int i = MAXLOG; i >= 0; i--) {
            if (f[x->id][i] != f[y->id][i]) {
                x = f[x->id][i];
                y = f[y->id][i];
            }
        }

        x = f[x->id][0];
        y = f[y->id][0];
    }
    
    return x->id;
}

int main() {
    int m, n;
    scanf("%d%d", &m, &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        inrd.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        prd.push_back(x);
    }

    Node *root = build(0, n - 1, 0, n - 1);

    dfs(root, true);

    // printf("root: %d\n", root->id);
    // for (int i = 1; i <= n; i++) {
    //     // printf("%d: depth = %d\n", nodes[i]->id, nodes[i]->depth);
    //     printf("%d: ", nodes[i]->id);
    //     if (nodes[i]->fa) printf("fa: %d\n", nodes[i]->fa->id);
    //     // if (nodes[i]->lc) printf("  %d\n", nodes[i]->lc->id);
    //     // if (nodes[i]->rc) printf("  %d\n", nodes[i]->rc->id);
    // }

    init(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);

        if ((u > n || u <= 0) && (v > 0 && v <= n)) printf("ERROR: %d is not found.\n", u);
        else if ((v > n || v <= 0) && (u > 0 && u <= n)) printf("ERROR: %d is not found.\n", v);
        else if ((v > n || v <= 0) && (u <= 0 || u > n)) printf("ERROR: %d and %d are not found.\n", u, v);
        else {
            int ans = lca(u, v);

            if (ans == u) printf("%d is an ancestor of %d.\n", u, v);
            else if (ans == v) printf("%d is an ancestor of %d.\n", v, u);
            else printf("LCA of %d and %d is %d.\n", u, v, ans);
        }
    }
    return 0;
}
