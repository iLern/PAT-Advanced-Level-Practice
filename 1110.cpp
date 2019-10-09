#include <cstdio>
#include <string>
#include <queue>
#include <iostream>

const int MAXN = 20 + 5;

struct Node {
    int id;
    Node *fa;
    Node *lc, *rc;

    bool isCom;

    Node() {
        id = 0;
        fa = lc = rc = nullptr;
        isCom = false;
    }

    void addChild(int type, Node *ch) {
        ch->fa = this;
        if (type == 1) lc = ch;
        else if (type == 2) rc = ch;
    }
} nodes[MAXN];

Node *ans = nullptr;
bool bfs(Node *x, int n) {
    std::queue<Node*> q;

    int cnt = 0;

    q.push(x);
    while (!q.empty()) {
        Node *v = q.front();
        q.pop();

        if (v != nullptr) {
            cnt++;
            ans = v;
        } else {
            if (cnt != n) return false;
            else return true;
        }

        q.push(v->lc);
        q.push(v->rc);
    }

    return true;
}

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::string lc, rc;
        std::cin >> lc >> rc;

        getchar();
        if (lc != "-") nodes[i].addChild(1, nodes + stoi(lc));
        if (rc != "-") nodes[i].addChild(2, nodes + stoi(rc));

        if (nodes[i].lc && nodes[i].rc) nodes[i].isCom = true;
        else if (!(nodes[i].lc || nodes[i].rc)) nodes[i].isCom = true;
    }

    for (int i = 0; i < n; i++) {
        nodes[i].id = i;
    }

    // bool flag = true;
    Node *root = nullptr;
    for (int i = 0; i < n; i++) {
        // if (!nodes[i].isCom) flag = false;
        if (!nodes[i].fa) root = &nodes[i];
    }

    bool flag = bfs(root, n);

    if (flag) std::cout << "YES " << ans->id;
    else std::cout << "NO " << root->id;
    return 0;
}
