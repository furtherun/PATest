/*
1121 Damn Single (25分)
感觉之前剩下的没写的题目，有的也太简单了吧
*/
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    int n, m, a, b;
    unordered_map<int, int> couples;
    vector<int> ans;
    scanf("%d", &n);
    for(int i = 0; i <n; ++ i) {
        scanf("%d %d", &a, &b);
        couples[a] = b;
        couples[b] = a;
    }
    scanf("%d", &m);
    unordered_set<int> visited;
    for(int i = 0; i < m; ++ i) {
        scanf("%d", &a);
        visited.insert(a);
    }
    for(const int& item: visited) {
        if(visited.find(couples[item]) == visited.end()) {
            ans.emplace_back(item);
        }
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for(auto it = ans.begin(); it!= ans.end(); ++ it) {
        if(it != ans.begin()) printf(" ");
        printf("%05d", *it);
    }
    return 0;
}
