#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

const int MAXN = 100 + 10;

struct Node {
    int data;
    Node *lc, *rc;

    Node () {
        data = 0;
        lc = rc = nullptr;
    }

    void inOrder(int &cnt, std::vector<int> &a) {
        if (lc) lc->inOrder(cnt, a);
        this->data = a[cnt++];
        if (rc) rc->inOrder(cnt, a);
    }
} nodes[MAXN];

void bfs(Node *root, std::vector<int> &a) {
    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *v = q.front();
        q.pop();

        a.push_back(v->data);

        if (v->lc) q.push(v->lc);
        if (v->rc) q.push(v->rc);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int lc, rc;
        scanf("%d%d", &lc, &rc);

        if (lc == -1) nodes[i].lc = nullptr;
        else nodes[i].lc = nodes + lc;

        if (rc == -1) nodes[i].rc = nullptr;
        else nodes[i].rc = nodes + rc;
    }

    std::vector<int> data;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        data.push_back(x);
    }

    std::sort(data.begin(), data.end());
    int cnt = 0;

    nodes[0].inOrder(cnt, data);

    std::vector<int> ans;
    bfs(&nodes[0], ans);

    for (int i = 0; i < ans.size(); i++) {
        if (i != ans.size() - 1) printf("%d ", ans[i]);
        else printf("%d\n", ans[i]);
    }
    return 0;
}
