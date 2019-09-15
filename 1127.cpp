#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int MAXN = 30 + 10;

struct Node {
    int id;
    Node* lc, *rc;

    int depth;

    Node(int id) : id(id) {
        depth = 0;
        lc = rc = nullptr;
    }
};

vector<int> pstrd, inrd;
//l1 r1->pstrd l2 r2->inrd
Node* build(int l1, int r1, int l2, int r2) {
    if (l1 > r1) return nullptr;

    Node *root = new Node(pstrd[r1]);

    int tmp = 0;
    while (inrd[l2 + tmp] != root->id) tmp++;

    int num = tmp - l2;
    root->lc = build(l1, l1 + tmp - 1, l2, l2 + tmp - 1);
    root->rc = build(l1 + tmp, r1 - 1, l2 + tmp + 1, r2);

    return root;
}

vector<int> level[MAXN];
int maxDepth;
void bfs(Node *root) {
    queue<Node*> q;
    root->depth = 1;
    q.push(root);

    while (!q.empty()) {
        Node *v = q.front();
        q.pop();

        maxDepth = max(v->depth, maxDepth);
        level[v->depth].push_back(v->id);

        if (v->lc) v->lc->depth = v->depth + 1;
        if (v->rc) v->rc->depth = v->depth + 1;

        if (v->lc) q.push(v->lc);
        if (v->rc) q.push(v->rc);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        inrd.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        pstrd.push_back(x);
    }

    Node *root = build(0, n - 1, 0, n - 1);

    bfs(root);

    for (int i = 1; i <= maxDepth; i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < level[i].size(); j++) {
                if (j == level[i].size() - 1 && i == maxDepth) printf("%d\n", level[i][j]);
                else printf("%d ", level[i][j]);
            }
        } else {
            for (int j = level[i].size() - 1; j >= 0; j--) {
                if (j == 0 && i == maxDepth) printf("%d\n", level[i][j]);
                else printf("%d ", level[i][j]);
            }
        }
    }
    return 0;
}
