#include <cstdio>
#include <cctype>
#include <algorithm>
#include <vector>
#include <queue>

const int MAXN = 10 + 5;

struct Node {
    int id;
    Node *fa;
    Node *lc, *rc;

    Node() {
        id = 0;
        fa = lc = rc = nullptr;
    }

    void addChild(int type, Node *ch) {
        ch->fa = this;
        if (type == 1) lc = ch;
        else if (type == 2) rc = ch;
    }

    void reverse() {
        std::swap(lc, rc);
        if (lc) lc->reverse();
        if (rc) rc->reverse();
    }

    void inOrder(std::vector<int> &v) {
        if (lc) lc->inOrder(v);
        v.push_back(id);
        if (rc) rc->inOrder(v);
    }
} nodes[MAXN];

void bfs(Node *root, std::vector<int> &v) {
    std::queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *tmp = q.front();
        q.pop();

        v.push_back(tmp->id);
        if (tmp->lc) q.push(tmp->lc);
        if (tmp->rc) q.push(tmp->rc);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) nodes[i].id = i;

    getchar();
    for (int i = 0; i < n; i++) {
        char lc, rc;
        scanf("%c %c", &lc, &rc);

        getchar();
        if (isdigit(lc)) nodes[i].addChild(1, nodes + (lc - '0'));
        if (isdigit(rc)) nodes[i].addChild(2, nodes + (rc - '0'));
    }

    Node *root = nullptr;
    for (int i = 0; i < n; i++) {
        if (!nodes[i].fa) {
            root = &nodes[i];
            break;
        }
    }

    root->reverse();

    std::vector<int> inord;
    root->inOrder(inord);

    std::vector<int> leord;
    bfs(root, leord);

    for (int i = 0; i < leord.size(); i++) {
        if (i != leord.size() - 1) printf("%d ", leord[i]);
        else printf("%d\n", leord[i]);
    }

    for (int i = 0; i < inord.size(); i++) {
        if (i != inord.size() - 1) printf("%d ", inord[i]);
        else printf("%d\n", inord[i]);
    }
    return 0;
}
