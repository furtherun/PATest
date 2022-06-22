/*
1122 Hamiltonian Cycle (25分)
比之前做的旅行商人TSC那题逻辑简单很多
判断既有一些技巧也可以完整模拟一遍吧
主要是题目没有具体说明simple cycle，也有可能这个需要自己知道什么是简单环
可是BST都说明了呀，可能BST关于等号怎么处理需要强调一下？
*/
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;
const int MAXN = 205;
vector<vector<int>> graph(MAXN, vector<int>(MAXN, -1));
int main()
{
    int n, m, a, b, k;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++ i) {
        scanf("%d %d", &a, &b);
        graph[a][b] = graph[b][a] = 1;
    }
    scanf("%d", &k);
    int len, starter;
    vector<int> visited(n+1);
    while(k --) {
        bool flag = true;
        fill(visited.begin(), visited.end(), 0);
        scanf("%d %d", &len, &starter);
        a = starter;
        for(int i = 1; i < len; ++ i) {
            scanf("%d", &b);
            if(!flag || graph[a][b] == -1 || visited[b] == 1) {
                flag = false;
                continue;
            }
            visited[b] ++;
            a = b;
        }
        if(flag && (starter != b|| len != n+1)) flag = false;
        puts(flag? "YES": "NO");
    }
    return 0;
}
