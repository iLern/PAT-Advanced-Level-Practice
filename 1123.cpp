#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>

struct Node {
    int data;
    int h;

    Node *lc, *rc;

    Node(int x) : data(x) {
        h = 0;
        lc = rc = nullptr;
    }
};

struct AVLTree {
    Node *root;

    AVLTree() {
        this->root = nullptr;
    }

    int height(Node *x) {
        if (x) return x->h;
        else return -1;
    }

    Node *ll_Rotate(Node *r) {
        // printf("**ll %d**\n", r->data);

        Node *tmp = r->lc;
        r->lc = tmp->rc;
        tmp->rc = r;

        r->h = std::max(height(r->lc), height(r->rc)) + 1;
        tmp->h = std::max(height(tmp->lc), height(tmp->rc)) + 1;
        return tmp;
    }

    Node *rr_Rotate(Node *r) {
        // printf("**rr %d**\n", r->data);

        Node *tmp = r->rc;
        r->rc = tmp->lc;
        tmp->lc = r;

        r->h = std::max(height(r->lc), height(r->rc)) + 1;
        tmp->h = std::max(height(tmp->lc), height(tmp->rc)) + 1;
        return tmp;
    }

    Node *lr_Rotate(Node *r) {
        // printf("**lr %d**\n", r->data);
        
        r->lc = rr_Rotate(r->lc);
        r = ll_Rotate(r);

        return r;
    }

    Node *rl_Rotate(Node *r) {
        // printf("**rl %d**\n", r->data);

        r->rc = ll_Rotate(r->rc);
        r = rr_Rotate(r);

        return r;
    }

    Node* insertNode(int data, Node *root) {
        if (!root) root = new Node(data);
        else {
            // printf("hihi\n");
            if (data < root->data) {
                // printf("haha\n");
                root->lc = insertNode(data, root->lc);

                // printf("*%d*\n", height(root->lc) - height(root->rc));
                if (height(root->lc) - height(root->rc) == 2) {
                    if (data < root->lc->data) {
                        root = ll_Rotate(root);
                    } else {
                        root = lr_Rotate(root);
                    }
                }
            } else if (data > root->data) {
                // printf("hoho\n");
                root->rc = insertNode(data, root->rc);

                // printf(".%d.\n", height(root->rc) - height(root->lc));
                if (height(root->rc) - height(root->lc) == 2) {
                    if (data > root->rc->data) {
                        root = rr_Rotate(root);
                    } else {
                        root = rl_Rotate(root);
                    }
                }
            }

        }

        root->h = std::max(height(root->lc), height(root->rc)) + 1;
        // printf("%d -> %d\n", root->data, root->h);
        return root;
    }

    void insert(int data) {
        this->root = insertNode(data, this->root);
    }
};

bool bfs(AVLTree *avl, std::vector<int> &ans) {
    std::queue<Node*> q;
    q.push(avl->root);

    bool flag = true, flag1 = true;
    while (!q.empty()) {
        Node *v = q.front();

        // printf("[%d]->lc[%d] rc[%d]\n", v->data, v->lc ? v->lc->data : -1, v->rc ? v->rc->data : -1);

        q.pop();

        ans.push_back(v->data);

        if (!v->lc && v->rc) flag = false;
        if (!flag1 && (v->lc || v->rc)) flag = false;
        if ((!v->lc && !v->rc) || (v->lc && !v->rc)) flag1 = false;

        if (v->lc) q.push(v->lc);
        if (v->rc) q.push(v->rc);
    }

    return flag;
}

int main() {
    int n;
    scanf("%d", &n);

    AVLTree *avl = new AVLTree();
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        avl->insert(x);
    }

    std::vector<int> ans;
    bool flag = bfs(avl, ans);
    for (int i = 0; i < ans.size(); i++) {
        printf("%d%s", ans[i], i == ans.size() - 1 ? "\n" : " ");
    }

    printf("%s", flag ? "YES\n" : "NO\n");
    return 0;
}
