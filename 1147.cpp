#include <cstdio>
#include <vector>

const int MAXN = 1000 + 10;

int a[MAXN];

int judge(int a[], int size) {
    int flag = a[1] > a[2] ? 1 : -1;

    for (int i = 1; i <= size / 2; i++) {
        int l = i * 2, r = i * 2 + 1;
        if (flag == 1 && (a[l] > a[i] || (r <= size && a[r] > a[i]))) return 3;
        else if (flag == -1 && (a[l] < a[i] ||(r <= size && a[r] < a[i]))) return 3;
    }

    if (flag == 1) return 1;
    else if (flag == -1) return 2;
}

std::vector<int> ans;
void postOrder(int a[], int root, int size) {
    if (root > size) return;
    postOrder(a, root * 2, size);
    postOrder(a, root * 2 + 1, size);
    ans.push_back(a[root]);
}

int main() {
    int m, n;
    scanf("%d%d", &m, &n);

    while (m--) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        if (judge(a, n) == 1) printf("Max Heap\n");
        else if (judge(a, n) == 2) printf("Min Heap\n");
        else if (judge(a, n) == 3) printf("Not Heap\n");

        postOrder(a, 1, n);

        for (int i = 0; i < n; i++) {
            if (i == n - 1) printf("%d\n", ans[i]);
            else printf("%d ", ans[i]);
        }
        ans.clear();
    }
    return 0;
}
