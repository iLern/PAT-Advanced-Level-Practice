#include <cstdio>
#include <vector>

const int MAXN = 1000 + 10;

int a[MAXN];

std::vector<int> ans;
void dfs(int root, int size) {
    if (root * 2 > size && root * 2 + 1 > size) {
        if (root <= size) {
            for (int i = 0; i < ans.size(); i++) {
                printf("%d%s", ans[i], i == ans.size() - 1 ? "\n" : " ");
            }
        }
    } else {
        ans.push_back(a[root * 2 + 1]);
        dfs(root * 2 + 1, size);
        ans.pop_back();

        ans.push_back(a[root * 2]);
        dfs(root * 2, size);
        ans.pop_back();
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    ans.push_back(a[1]);
    dfs(1, n);

    bool isMax = (a[1] > a[2]), notHeap = false;
    for (int i = 1; i <= n / 2; i++) {
        int l = i * 2, r = i * 2 + 1;
        if (!isMax && (a[l] < a[i] || (r <= n && a[r] < a[i]))) notHeap = true;
        if (isMax && (a[l] > a[i] || (r <= n && a[r] > a[i]))) notHeap = true;
    }

    if (notHeap) printf("Not Heap");
    else printf("%s\n", isMax ? "Max Heap" : "Min Heap");
    return 0;
}
