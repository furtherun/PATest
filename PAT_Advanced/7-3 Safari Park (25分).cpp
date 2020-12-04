/*
7-3 Safari Park (25分)
这题我感觉之前的思路都是用"点"做，这次选择存储"边"来遍历
有点项之前那个染色的题目。
*/

#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <set>
#include <string>
using namespace std;

const int MAXN = 505;
struct Edge{
    int x, y;
    Edge(int a, int b): x(a), y(b) { };
    Edge() {};
};
vector<int> regions(MAXN, 0);
int main() {
    int a, b, n, r, k;
    scanf("%d %d %d", &n, &r, &k);
    vector<Edge> edgeList;
    for(int i = 0; i < r; ++ i) {
        scanf("%d %d", &a, &b);
        edgeList.emplace_back(a, b);
    }
    int t;
    scanf("%d", &t);
    set<int> st;
    bool isFeasible;
    while(t --) {
        st.clear();
        for(int i = 1; i <= n; ++ i) {
            scanf("%d", &a);
            regions[i] = a;
            st.insert(a);
        }
        int len = (int)st.size();
        if(len == k) {
            isFeasible = true;
            for(const auto& e: edgeList) {
                if(regions[e.x] == regions[e.y]) {
                    isFeasible = false;
                    break;
                }
            }
            puts(isFeasible? "Yes": "No");
        } else {
            puts(len < k? "Error: Too few species.": "Error: Too many species.");
        }
    }
    return 0;
}

