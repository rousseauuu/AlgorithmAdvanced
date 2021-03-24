#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false); std::cin.tie(0);
    
    int n; std::cin >> n;
    std::map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int x; std::cin >> x;
        ++counts[x];
    }
    
    int m; std::cin >> m;
    std::vector<std::pair<int, int> > hb(m, std::make_pair(0, 0));
    for (int i = 0; i < m; ++i) std::cin >> hb[i].first;
    for (int i = 0; i < m; ++i) std::cin >> hb[i].second;
    
    int best = 0, scoreA = -1, scoreB = -1;
    for (int i = 0; i < m; ++i) {
        int countA = (counts.count(hb[i].first) > 0) ? counts[hb[i].first] : 0;
        int countB = (counts.count(hb[i].second) > 0) ? counts[hb[i].second] : 0;
        if (countA > scoreA || (countA == countB && countB > scoreB)) {
            scoreA = countA; scoreB = countB;
            best = i + 1;
        }
    }
    std::cout << best << std::endl;
    return 0;
}