#include <iostream>
#include <string>

using namespace std;

const int MAXN = 1000 + 10;

struct user {
    string name, pwd;
    bool isBad;
} us[MAXN];

bool check(string &s) {
    for (auto &c : s) {
        if (c == '1' || c == 'l' || c == '0' || c == 'O') return true;
    }
    return false;
}

bool shift(string &s) {
    for (auto &c : s) {
        if (c == '1') c = '@';
        if (c == '0') c = '%';
        if (c == 'l') c = 'L';
        if (c == 'O') c = 'o';
    }
}

int main() {
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> us[i].name >> us[i].pwd;
        if (check(us[i].pwd)) {
            us[i].isBad = true;
            shift(us[i].pwd);
            ans++;
        }
    }

    if (ans == 0) {
        if (n == 1) cout << "There is " << n << " account and no account is modified" << endl;
        else cout << "There are " << n << " accounts and no account is modified" << endl;
    } else {
        cout << ans << endl;
        for (int i = 0; i < n; i++) {
            if (us[i].isBad) cout << us[i].name << " " << us[i].pwd << endl;
        }
    }
    return 0;
}
