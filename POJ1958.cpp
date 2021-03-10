#include <iostream>
#include <cstring>
#include <algorithm>

const int N = 20;
int d[N], f[N];

int main() {
    std::ios::sync_with_stdio(false);
    memset(f, 0x3f, sizeof(f));
    d[1] = 1;
    f[1] = 1;
    for (int i = 2; i <= 12; i++) {
        d[i] = 2 * d[i - 1] + 1;
    }
    for (int i = 2; i <= 12; i++) {
        for (int j = 1; j < i; j++)
            f[i] = std::min(f[i], 2 * f[j] + d[i - j]);
    }
    for (int i = 1; i <= 12; i++)
        std::cout << f[i] << std::endl;

    return 0;
}   