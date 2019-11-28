#include <cstdio>
#include <vector>
#include <algorithm>

int main() {
    int n;
    scanf("%d", &n);

    std::vector<int> v;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
    }

    int now = 0, ans = 0;
    for (auto x : v) {
        if (x == now) ans += 5;
        else {
            if (x > now) ans += (x - now) * 6 + 5;
            else ans += (now - x) * 4 + 5;
        }
        now = x;
    }

    printf("%d\n", ans);

    return 0;
}