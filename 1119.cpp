#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> pre, post;
queue<int> in;

int tree[30][2], root, isuniq=1;

void inorder(int &index, int prel,int prer, int postl, int postr) {
    if (prel > prer) {
        isuniq = 0;return;
    }
    index = prel;
    if (prel == prer) return;
    int e = postr;
    while (pre[prel + 1] != post[e]) e--;
    inorder(tree[index][0], prel + 1, prel + e - postl + 1, postl, e);
    inorder(tree[index][1], prel + e - postl + 2, prer, e + 1, postr-1);
}

void inorder(int r) {
    if (tree[r][0] != 0) inorder(tree[r][0]);
    in.push(pre[r]);
    if (tree[r][1] != 0) inorder(tree[r][1]);
}

int main() {
    int n, i, t;
    cin >> n;
    pre.resize(n); post.resize(n);
    for (i = 0; i < n; i++) cin >> pre[i];
    for (i = 0; i < n; i++) cin >> post[i];
    inorder(root, 0, n - 1, 0, n - 1);
    cout << (isuniq == 1 ? "Yes" : "No") << endl;
    inorder(0);
    while (!in.empty()) {
        cout << in.front() << (in.size() == 1 ? "\n" : " ");
        in.pop();
    }
    return 0;
}