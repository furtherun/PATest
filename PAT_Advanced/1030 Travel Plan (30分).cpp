/*
1030 Travel Plan (30分)
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
using namespace std;
const int MAXN = 505;
const int INF = 0x7f7f7f7f;
int n, m, st, ed;
vector<vector<int>> graph(MAXN, vector<int>(MAXN, INF)); //边的长度
vector<vector<int>> cost(MAXN, vector<int>(MAXN, INF)); //边的代价（花费）
vector<int> dist(MAXN, INF);
vector<bool> visited(MAXN, false);
vector<vector<int>> pre(MAXN, vector<int>());
vector<int> ansPath, tmpPath;
int ansCost = INF;
void output(const vector<int>& vi);
void dfs(int idx) {
    if(idx == st) {
        tmpPath.emplace_back(idx);
        int len = (int)tmpPath.size();
        int tmpCost = 0;
//        cout << "test tmp path " << endl;
//        output(tmpPath);
        for(int j = len-1; j > 0; -- j) {
            int u = tmpPath[j], v = tmpPath[j-1];
            tmpCost += cost[u][v];
        }
//        cout << "test tmp cost " << tmpCost << endl;
        if(tmpCost < ansCost) {
            ansCost = tmpCost;
            ansPath = tmpPath;
        }
        tmpPath.pop_back();
        return;
    }
    tmpPath.emplace_back(idx);
    for(auto item: pre[idx]) {
        dfs(item);
    }
    tmpPath.pop_back();
}
void Dijkstra(int st) {
    dist[st] = 0;
    for(int i = 0; i < n; ++ i) {
        int u = -1, tmpDist = INF;
        for(int j = 0; j < n; ++ j) {
            if(!visited[j] && dist[j] < tmpDist) {
                tmpDist = dist[j];
                u = j;
            }
        }
        if(u == -1) return;
        visited[u] = true;
        for(int v = 0; v < n; ++ v) {
            if(!visited[v] && graph[u][v] != INF) {
                if(dist[v] > dist[u] + graph[u][v]) {
                    dist[v] = dist[u] + graph[u][v];
                    pre[v].clear();
                    pre[v].emplace_back(u);
                } else if(dist[v] == dist[u] + graph[u][v]) {
                    pre[v].emplace_back(u);
                }
            }
        }
    }
}
void output(const vector<int>& vi) {
    int len = (int)vi.size();
    for(int i = len-1; i >=0; -- i) {
        printf("%d ", vi[i]);
    }
}
int main() {
    int a, b, d, c;
    scanf("%d %d %d %d", &n, &m, &st, &ed);
    for(int i = 0; i < m; ++ i) {
        scanf("%d %d %d %d", &a, &b, &d, &c);
        graph[a][b] = graph[b][a] = d;
        cost[a][b] = cost[b][a] = c; //这个打反了，路径是双向的
    }
    Dijkstra(st);
    dfs(ed);
    output(ansPath);
    printf("%d %d\n", dist[ed], ansCost);
    return 0;
}
