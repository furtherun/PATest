/*
7-4 Dijkstra Sequence (30分)
这题应该算是手动模拟Dijkstra，就像某些期末考试题一样
之前一直吐槽KMP手动模拟和写代码完全是两回事，这个Dijkstra的模拟验证题
主要考察每一步选择的边是否为最优。我有2个问题，一是visited数组一开始没给大小
导致我前几次读数据老是出错误，我在循环体中检查了挺长时间。
另一个是在代码能跑了之后，发现有行理解错误，就是选完一条边之后不用更新
因为要么这条边是最优，要么不该选它。
*/
#define INT_MAX 0x7fffffff
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int MAXN = 1E3+5;
vector<vector<int>> graph(MAXN, vector<int>(MAXN, INT_MAX));
int main() {
    int nv, ne, k, a, b, w;
    scanf("%d %d", &nv, &ne);
    for(int i = 0; i < ne; ++ i) {
        scanf("%d %d %d", &a, &b, &w);
        graph[a][b] = graph[b][a] = w;
    }
    scanf("%d", &k);
    vector<int> dist(MAXN, INT_MAX);
    vector<bool> visited(MAXN);
    int u, v;
    bool flag;
    while(k --) {
        scanf("%d", &u);
        flag = true;
        for(int i = 1; i <= nv; ++ i) {
            dist[i] = graph[u][i];
            visited[i] = false;
        }
        visited[u] = true; //起点初始化
        dist[u] = 0;
        for(int i = 2; i <= nv; ++ i) {
            scanf("%d", &v);
            if(flag) {
//                dist[v] = (graph[u][v] == INT_MAX)? INT_MAX: (dist[u] + graph[u][v]); 无用的一行
                visited[v] = true;
                for(int i = 1; i <= nv; ++ i) {
                    if(!visited[i]) {
                        if(dist[i] < dist[v]) { //选择的不是最短的边
                            flag = false;
                            break;
                        } else if(graph[v][i] != INT_MAX && dist[v] + graph[v][i] < dist[i]){
                            dist[i] = dist[v] + graph[v][i];
                        }
                    }
                }
                u = v;
            }
        }
        puts(flag?"Yes": "No");
    }
    return 0;
}
