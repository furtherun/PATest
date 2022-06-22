/*
07-图6 旅游规划 (25分)
果真是好久不写dijkstra就一大把错误
*/
#define INT_MAX 0x7fffffff
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <unordered_set>
#include <vector>

using namespace std;
const int MAXN = 505;
vector<vector<int>> distances(MAXN, vector<int>(MAXN, INT_MAX));
vector<vector<int>> costs(MAXN, vector<int>(MAXN, INT_MAX));
int n, m, s, d;
vector<int> dist(MAXN, INT_MAX);
vector<vector<int>> prePath(MAXN, vector<int>());
vector<int> tmpPath, ansPath;
int minCost = INT_MAX;
void dijkstra(int s, int n) {
     vector<bool> visited(n, false);
     dist[s] = 0;
     for(int i = 0; i < n; ++ i) {
        int u = -1, tmpDist = INT_MAX;
        for(int j = 0; j < n; ++ j) {
            if(!visited[j] && dist[j] < tmpDist) {
                u = j;
                tmpDist = dist[j];
            }
        }
        if(u == -1) return;
        visited[u] = true; //漏了这句
        for(int v = 0; v < n; ++ v) {
            if(!visited[v] && distances[u][v] != INT_MAX) { //忘了判断条件
                if(dist[u] + distances[u][v] < dist[v]) {
                    dist[v] = dist[u] + distances[u][v];
                    prePath[v].clear();
                    prePath[v].emplace_back(u);
                } else if(dist[u] + distances[u][v] == dist[v]) {
                    prePath[v].emplace_back(u);
                }
            }
        }
     }
}
int getTheCost(vector<int>& path) {
    int len = (int)path.size();
    int ans = 0;
    for(int i = len-1; i > 0; -- i) {
        ans += costs[path[i]][path[i-1]]; //忘记带入路径
    }
    return ans;
}
void dfs(int idx) { //begin from d
    if(idx == s) {
        tmpPath.emplace_back(idx);
        int tmpCost = getTheCost(tmpPath);
        if(tmpCost < minCost) {
            minCost = tmpCost;
            ansPath = tmpPath;
        };
        tmpPath.pop_back();
        return;
    }
    tmpPath.emplace_back(idx);
    for(int i = 0; i < (int)prePath[idx].size(); ++ i) {
        dfs(prePath[idx][i]);
    }
    tmpPath.pop_back();
}
int main() {
    scanf("%d %d %d %d", &n, &m, &s, &d);
    int a, b, tmpDist, tmpCost;
    for(int i = 0; i < m; ++ i) {
        scanf("%d %d %d %d", &a, &b, &tmpDist, &tmpCost);
        distances[a][b] = distances[b][a] = tmpDist;
        costs[a][b] = costs[b][a] = tmpCost;
    }
    dijkstra(s, n); //忘记调用
    dfs(d);
    printf("%d %d\n", dist[d], minCost);
    return 0;
}

/*
以下为之前写的代码
old code
*/
#include <iostream>
#include <array>
#include <queue>
#define INF 0x3fffffff

using namespace std;

const int MAXN = 500;
int n, m, s, e;
array <int, MAXN> dist;
array <int, MAXN> expe;
array < array<pair<int, int>, MAXN>, MAXN> adjMatrix;
array <bool, MAXN> collected;

void Init( );
void Dijkstra(int s);
int FindMin(int s);
void Print( );

int main()
{
    Init();
    Dijkstra(s);
    Print( );
    return 0;
}

void Init( )
{
      cin >>  n >> m >> s >> e;
    int city1, city2, distance, expense;

    fill(dist.begin(), dist.end(), INF);
    fill(expe.begin(), expe.end(), INF);
    fill(collected.begin(), collected.end(), false);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j ) {
            adjMatrix[i][j].first = INF;
            adjMatrix[i][j].second = INF;
        }
    }
    for (int i = 0; i < m; ++ i) {
        cin >> city1 >> city2;
        cin >> distance >> expense;
        adjMatrix[city1][city2].first = adjMatrix[city2][city1].first = distance;
        adjMatrix[city1][city2].second = adjMatrix[city2][city1].second = expense;
    }
    for (int i = 0; i < n; ++ i) {
        dist[i] = adjMatrix[s][i].first;
        expe[i] = adjMatrix[s][i].second;
    }
//    for (int i = 0; i < n; ++ i) {
//        for (int j = 0; j < n; ++ j) {
//            printf("%d ", adjMatrix[i][j].first);
//        }
//        cout << endl;
//    }
}
void Dijkstra(int s)
{
    queue <int> q;
    q.push(s);
    collected[s] = true;
    dist[s] = 0, expe[s] = 0;
    while (!q.empty()) {
        int tmp = FindMin(s);
        if (tmp == -1 ) break;
        collected[tmp] = true;
        for (int i = 0; i < n; ++ i) {
            if (!collected[i] && adjMatrix[tmp][i].first != INF ) {
                if(dist[tmp] + adjMatrix[tmp][i].first < dist[i]) {
                    dist[i] = dist[tmp] + adjMatrix[tmp][i].first;
                    expe[i] = expe[tmp] + adjMatrix[tmp][i].second;
                }
                else if ( (dist[tmp] + adjMatrix[tmp][i].first == dist[i]) && (expe[tmp] + adjMatrix[tmp][i].second < expe[i]) ) {
                    expe[i] = expe[tmp] + adjMatrix[tmp][i].second;
                }
            }
        }
    }
}

int FindMin(int s)
{
    int minDist {INF};
    int minV {-1};
    for (int i = 0; i < n; ++ i) {
        if (!collected[i] && dist[i] < minDist) {
            minDist = dist[i];
            minV = i;
        }
    }
    return minV;
}
void Print( )
{
    printf("%d %d\n",dist[e], expe[e]);
}
