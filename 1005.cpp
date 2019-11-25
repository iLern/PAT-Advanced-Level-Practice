#include <cstdio>
#include <string>
#include <iostream>

std::string name[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main() {
    std::string s;
    std::cin >> s;

    int sum = 0;
    for (auto c : s) {
        sum += (c - '0');
    }

    std::string tmp = std::to_string(sum);

    for (int i = 0; i < tmp.length(); i++) {
        std::cout << name[tmp[i] - '0'] << (i == tmp.length() - 1 ? '\n' : ' ');
    }
    return 0;
}
