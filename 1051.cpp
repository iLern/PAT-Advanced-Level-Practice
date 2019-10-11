#include <cstdio>
#include <stack>

const int MAXN = 1000 + 10;

int a[MAXN];

int main() {
    int maxSize, n, k;
    scanf("%d%d%d", &maxSize, &n, &k);

    while (k--) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        std::stack<int> st;

        bool flag = true;

        int now = 0;
        for (int i = 1; i <= n; i++) {
            for (int cnt = now + 1; cnt <= a[i]; cnt++) {
                now = cnt;
                st.push(cnt);

                if (st.size() > maxSize) {
                    flag = false;
                    break;
                }
            }

            if (st.top() != a[i]) {
                flag = false;
                break;
            } else st.pop();

            if (!flag) break;
        }

        if (!flag) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
