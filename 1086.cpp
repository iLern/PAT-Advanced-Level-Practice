#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

const int MAXN = 30 + 10;

vector<int> ans;
struct Node {
    int id;
    Node* lc, *rc;

    Node(int id) : id(id) {
        lc = rc = nullptr;
    }

    void postOrder() {
        if (lc) lc->postOrder();
        if (rc) rc->postOrder();

        ans.push_back(this->id);
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
    cin >> n;

    stack<int> st;
    for (int i = 0; i < n * 2; i++) {
        string op;
        cin >> op;

        if (op == "Push") {
            int id;
            cin >> id;
            st.push(id);
            prd.push_back(id);
        } else {
            int tmp = st.top();
            inrd.push_back(tmp);

            st.pop();
        }
    }

#ifdef DBG
    for (auto x : prd) cout << x << " ";
    cout << endl;
    for (auto x : inrd) cout << x << " ";
    cout << endl;
#endif

    Node* root = build(0, n - 1, 0, n - 1);
    root->postOrder();
    
    for (int i = 0; i < ans.size(); i++) {
        if (i != ans.size() - 1) cout << ans[i] << " ";
        else cout << ans[i] << endl;
    }
    return 0;
}
