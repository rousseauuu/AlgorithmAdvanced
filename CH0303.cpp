#include <iostream>

int order[20];
bool chosen[20];
int n;

void calc(int k) {
    if (k == n + 1) {
        for (int i = 1; i <= n; i++)
            std::cout << order[i] << " ";
        std::cout << std::endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (chosen[i]) continue;
        order[k] = i;
        chosen[i] = true;
        calc(k + 1);
        chosen[i] = false;
        
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    calc(1);
    
    return 0;
}