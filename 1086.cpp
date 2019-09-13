#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

const int MAXN = 30 + 5;

vector<int> ans;
struct Node {
    int id;
    Node *lc, *rc;

    Node() {
        lc = rc = nullptr;
    }

    void postOrder() {
        if (lc) lc->postOrder();
        if (rc) rc->postOrder();
        ans.push_back(this->id);
    }
} nodes[MAXN];


int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        nodes[i].id = i;
    }

    // int cnt = 1;
    stack<int> st;
    Node *root = nullptr;
    for (int i = 0; i < n * 2; i++) {
        string op;
        cin >> op;
        // cout << op << " " << id << endl;
        if (op == "Push") {
            int id;
            cin >> id;

            if (st.empty()) root = nodes + id;
            else {
                Node* fa = nodes + st.top();
                if (fa->lc) fa->rc = nodes + id;
                else fa->lc = nodes + id;
            }

            st.push(id);
            // cnt++;
        } else if (op == "Pop") {
            st.pop();
        }
    }

    root->postOrder();

    for (int i = 0; i < ans.size(); i++) {
        if (i != ans.size() - 1) cout << ans[i] << " ";
        else cout << ans[i] << endl;
    }
    return 0;
}
