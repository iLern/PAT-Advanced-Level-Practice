#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

map<char, string>mp;
void init() {
    mp['A'] = "MON";mp['B'] = "TUE";
    mp['C'] = "WED";mp['D'] = "THU";
    mp['E'] = "FRI";mp['F'] = "SAT";
    mp['G'] = "SUN";
}

int main() {
    string s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;

    init();
    int minn = min(s1.length(),s2.length());
    
    int i = 0;
    for(i = 0; i < minn ;i++) {
        if(s1[i] == s2[i] && s1[i] >='A' && s1[i] <= 'G') {
            cout << mp[s1[i]];
            break;
        }
    }
    for (++i; i < minn; i++) {
        if (s1[i] == s2[i]) {
            if (s1[i] >= 'A' && s1[i] <= 'N') {
                printf(" %02d:",(10 + s1[i] - 'A'));
                break;
            } else if (isdigit(s1[i])) {
                printf(" %02d:", s1[i] - '0');
                break;
            }
        }
    }

    minn = min(s3.length(), s4.length());
    for (int i = 0; i < minn; i++) {
        if (s3[i] == s4[i] && isalpha(s3[i])) {
            printf("%02d\n", i);
            return 0;
        }
    }

    return 0;
}
