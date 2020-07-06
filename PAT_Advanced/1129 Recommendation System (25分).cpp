/*
1129 Recommendation System (25分)
这一题使用sort暴力求解是要超时的，几个set stl的操作时间复杂度
erase  amortized constant
insert log(N)
clear  N
count  log(N)

还要学会使用 重载，
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 50005;
vector<int> frequences(MAXN, 0);
struct Node{
    int value, freq;
    Node(int v, int f) : value(v), freq(f) { };
    bool operator < (const Node& a) const{
        if(freq != a.freq) {
            return freq > a.freq;
        } else {
            return value < a.value;
        }
    }
};
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int tmp;
    set<Node> arr;
    for(int i = 0; i < n; ++ i) {
        scanf("%d", &tmp);
        if(i > 0) {
            printf("%d:", tmp);
            int j = 0;
            for(auto it = arr.begin(); it != arr.end() && j < k;++ it) {
                printf(" %d", it->value);
                ++ j;
            }
            printf("\n");
        }
        if(arr.find(Node(tmp, frequences[tmp])) != arr.end()) {
            arr.erase(Node(tmp, frequences[tmp]));
        }
        frequences[tmp] ++;
        arr.insert(Node(tmp, frequences[tmp]));
    }
    return 0;
}
