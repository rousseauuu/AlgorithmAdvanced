#include <bits/stdc++.h>

int n;
std::vector<int> chosen;

void calc(int x) {
    if (x == n + 1) {
        for (auto v : chosen)
            std::cout << v << " ";
        std::cout << std::endl;
        return;
    }
    calc(x + 1);
    chosen.push_back(x);
    calc(x + 1);
    chosen.pop_back();
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    calc(1);

    return 0;
}
