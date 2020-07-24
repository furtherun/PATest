/*
1126 Eulerian Path (25分)
需要是连通图，不连通的情况占了5分（测试点3）
看似简单，但是容易让人放松警惕
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;
const int MAXN = 505;
vector<vector<int>> graph(MAXN, vector<int>(MAXN, -1));
vector<bool> visited(MAXN, false);
bool bfs(int idx, int n) {
    int cnt = 0;
    queue<int> q;
    q.push(idx);
    visited[idx] = true;
    while(!q.empty()) {
        int len = (int)q.size();
        for(int i = 0; i < len; ++ i) {
            int f = q.front(); q.pop(); cnt ++;
            for(int i = 1; i <= n; ++ i) {
                if(!visited[i] && graph[f][i] != -1) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    return cnt == n;
}
int main() {
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    vector<int> degree(MAXN, 0);
    for(int i = 0; i < m; ++ i) {
        scanf("%d %d", &a, &b);
        graph[a][b] = graph[b][a] = 1;
        degree[a] ++;
        degree[b] ++;
    }
    int oddNum = 0;
    for(int i = 1; i <= n; ++ i) {
        printf("%d", degree[i]);
        printf(i == n?"\n": " ");
        if (degree[i] % 2 == 1) {
            oddNum ++;
        }
    }
    if(bfs(1, n)) {
        if(oddNum == 0) {
            puts("Eulerian");
        } else {
            puts(oddNum == 2? "Semi-Eulerian": "Non-Eulerian");
        }
    } else {
        puts("Non-Eulerian");
    }
    return 0;
}
