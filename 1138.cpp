#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

const int MAXN = 30 + 10;

struct Node {
    int id;
    Node* lc, *rc;

    Node(int id) : id(id) {
        lc = rc = nullptr;
    }

    void postOrder(bool &flag) {
        if (lc) lc->postOrder(flag);
        if (rc) rc->postOrder(flag);

        if (flag) {
            // ans.push_back(this->id);
            printf("%d\n", this->id);
            flag = false;
        }
    }
};

vector<int> prd, inrd;
//l1 r1->prd l2 r2->inrd
Node* build(int l1, int r1, int l2, int r2) {
    if (l1 > r1) return nullptr;

    Node *root = new Node(prd[l1]);

    int tmp = l2;
    while (inrd[tmp] != root->id) tmp++;

    int num = tmp - l2;
    root->lc = build(l1 + 1, l1 + num, l2, tmp - 1);
    root->rc = build(l1 + num + 1, r1, tmp + 1, r2);

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        prd.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        inrd.push_back(x);
    }

    Node *root = build(0, n - 1, 0, n - 1);

    bool flag = true;
    root->postOrder(flag);
    return 0;
}

