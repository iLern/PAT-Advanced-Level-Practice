#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = (1000 + 10) * 2;

int g[MAXN][MAXN];
bool vis[MAXN];
int callSum[MAXN], call[MAXN];
string name[MAXN];

std::vector<int> vec[MAXN];
void dfs(int x, int n, int num) {
    vis[x] = true;
    vec[num].push_back(x);
    for (int i = 0; i < n; i++) {
        if (g[x][i] != 0 && !vis[i]) {
            dfs(i, n, num);
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    map<string, int> hash;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        string s1, s2;
        int x;
        cin >> s1 >> s2 >> x;

        if (!hash.count(s1)) {
            name[cnt] = s1;
            hash[s1] = cnt++;
        }
        if (!hash.count(s2)) {
            name[cnt] = s2;
            hash[s2] = cnt++;
        }

        g[hash[s1]][hash[s2]] += x;

        call[hash[s1]] += x;

        callSum[hash[s1]] += x;
        callSum[hash[s2]] += x;
    }

    int num = 0;
    for (int i = 0; i < cnt; i++) {
        if (!vis[i]) {
            dfs(i, cnt, num++);
        }
    }

    vector<pair<string, int>> ans;
    for (int i = 0; i < num; i++) {
        int sum = 0, maxx = 0, maxId = 0;
        for (auto x : vec[i]) {
            sum += call[x];
            if (maxx < callSum[x]) {
                maxx = callSum[x];
                maxId = x;
            }
        }

        if (vec[i].size() >= 3 && sum > k) {
            ans.push_back(make_pair(name[maxId], vec[i].size()));
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (auto &x : ans) {
        cout << x.first << ' ' << x.second << endl;
    }
    return 0;
}
