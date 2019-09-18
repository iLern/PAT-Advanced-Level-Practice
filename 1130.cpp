#include <iostream>
#include <string>

using namespace std;

const int MAXN = 20 + 10;

struct Node {
    string data;
    Node *lc, *rc;

    Node *fa;

    Node() {
        data = "";
        lc = rc = fa = nullptr;
    }

    void inOrder() {
        if ((lc || rc) && fa) cout << '(';
        if (lc) lc->inOrder();
        cout << data;
        if (rc) rc->inOrder();
        if ((rc || rc) && fa) cout << ')';
    }
} nodes[MAXN];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        string data;
        int lc, rc;

        cin >> data >> lc >> rc;

        nodes[i].data = data;
        if (lc != -1) nodes[i].lc = nodes + lc;
        if (rc != -1) nodes[i].rc = nodes + rc;
        
        nodes[lc].fa = nodes[rc].fa = nodes + i;
    }

    for (int i = 1; i <= n; i++) {
        if (!nodes[i].fa) {
            nodes[i].inOrder();
            break;
        }
    }
    return 0;
}
