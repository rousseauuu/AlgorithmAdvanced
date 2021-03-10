/** 费解的开关
 *  2021-2-25
 */

#include <iostream>
#include <cstring>
#include <algorithm>

const int INF = 1e5;

char G[10][10], backup[10][10];
int dx[5] = {0, -1, 0, 1, 0},
    dy[5] = {0, 0, 1, 0, -1};

void turn(int x, int y) {
    for (int i = 0; i < 5; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5)
            // 1 -> 0   0 -> 1
            G[nx][ny] = '0' + !(G[nx][ny] - '0');
    }
}

int work() {
    int ans = INF;
    // 用二进制枚举第一行的操作情况，k 是第一行所代表的操作，1 代表turn一下，0 代表不turn
    for (int k = 0; k < (1 << 5); k++) {
        int res = 0;
        // 备份
        memcpy(backup, G, sizeof(G));
        for (int j = 0; j < 5; j++) {
            // 碰到 1 代表枚举出的情况需要 turn 一下
            if (k >> j & 1) {
                res++;
                turn(0, j);
            }
        }
        // 如果第i行有灯是 0 那么对 i + 1 行操作
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 5; j++) {
                if (G[i][j] == '0') {
                    res++;
                    turn(i + 1, j);
                }
            }
        }
        bool successful = true;
        // 如果最后一行还有灯是 0 则说明无解
        for (int j = 0; j < 5; j++) {
            if (G[4][j] == '0') {
                successful = false;
                break;
            }
        }
        // 找最小的解
        if (successful)
            ans = std::min(ans, res);
        // 恢复现场
        memcpy(G, backup, sizeof(G));
    }
    if (ans > 6)
        return -1;
}

int main() {
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    while (n--) {
        for (int i = 0; i < 5; i++)
            std::cin >> G[i];
        std::cout << work() << std::endl;
    }

    return 0;
}