#include <iostream>
#include <algorithm>
#include <string>

const int MAXN = 1000 + 10;

using namespace std;

string str;
int f[MAXN][MAXN];

int main() {
    getline(cin, str);

    for (int i = 0; i < str.size(); i++) {
        f[i][i] = 1;
    }

    for (int len = 2; len <= str.size(); len++) {
        for (int l = 0; l + len - 1 < str.size(); l++) {
            int r = l + len - 1;
            if (str[l] == str[r]) {
                if (len != 2)  f[l][r] = f[l + 1][r - 1];
                else f[l][r] = 1;
            }
            else f[l][r] = 0;
        }
    }

    int ans = 0;
    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j < str.size(); j++) {
            if (f[i][j] == 1) ans = max(ans, j - i + 1);
            // printf("%d ", f[i][j]);
        }
        // printf("\n");
    }

    printf("%d\n", ans);
    return 0;
}
