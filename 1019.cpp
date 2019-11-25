#include <cstdio>
#include <vector>

int main() {
    int n, b;
    scanf("%d%d", &n, &b);

    std::vector<int> v;
    while (n) {
        v.push_back(n % b);
        n /= b;
    }

    int i = 0, j = v.size() - 1;
    bool flag = true;
    while (i < j) {
        if(v[i] != v[j]) {
            flag = false;
            break;
        }
        i++; j--;
    }

    printf("%s", flag ? "Yes\n" : "No\n");
    for (int i = v.size() - 1; i >= 0; i--) {
        printf("%d%s", v[i], i == 0 ? "\n" : " ");
    }
    return 0;
}
