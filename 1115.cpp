#include <cstdio>
#include <climits>
#include <algorithm>

int maxDepth = 0;
struct BST {
    int data;
    BST *lc, *rc;

    int depth;

    BST(int data) : data(data) {
        depth = 0;
        lc = rc = nullptr;
    }

    void insert(BST *newNode) {
        if (newNode->data <= this->data) {
            if (!lc) {
                lc = newNode;
                lc->depth = this->depth + 1;
                maxDepth = std::max(maxDepth, lc->depth);
            }
            else lc->insert(newNode);
        } else {
            if (!rc) {
                rc = newNode;
                rc->depth = this->depth + 1;
                maxDepth = std::max(maxDepth, rc->depth);
            }
            else rc->insert(newNode);
        }
    }
};

int a, b;
void dfs(BST *root) {
    if (root->depth == maxDepth) a++;
    else if (root->depth == maxDepth - 1 && root->depth != 0) b++;

    if (root->lc) dfs(root->lc);
    if (root->rc) dfs(root->rc); 
}

int main() {
    int n;
    scanf("%d", &n);

    BST *root = new BST(INT_MIN);
    root->depth = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        root->insert(new BST(x));
    }

    // printf("%d\n", maxDepth);
    dfs(root);
    printf("%d + %d = %d\n", a, b, a + b);
    return 0;
}
