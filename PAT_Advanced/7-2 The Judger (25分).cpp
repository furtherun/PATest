/*
7-2 The Judger (25分)
听说有一个坑，是用stl中的map和unordered_map必定超时一个测试
题目给了范围，直接用数组模拟hash表的效果更快。
*/

#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
const int MAXN = 1e5 + 5;
vector<int> nums(MAXN, 0);
vector<int> box(MAXN, 0);
const int MAX_PLAYER = 12;
const int MAX_ROUND = 1005;
vector<vector<int>> graph(MAX_ROUND, vector<int>(MAX_PLAYER, 0));
int main() {
    int p, q, n, m;
    scanf("%d %d %d %d", &p, &q, &n, &m);
    /*
    一行为一轮
    */
    nums[p] = 1;
    nums[q] = 1;
//    set<int> st;
//    st.insert(abs(p-q));
    vector<int> arr{p, q};
    box[abs(p-q)] = 1;
    int tmp;
    for(int i = 1; i <= n; ++ i) {
        for(int j = 1; j <= m; ++ j) {
            scanf("%d", &tmp);
            graph[j][i] = tmp;
        }
    }
    int u = 0, cnt = 0;
    vector<bool> loser(MAX_PLAYER, false);
    for(int i = 1; i <= m; ++ i) { //round
        for(int j = 1; j <= n; ++ j) {
            if(loser[j]) continue;
            u = graph[i][j];
            if(nums[u] == 0 && box[u] == 1) { //可行，一开始写的'box[u] == 1'扣了一分
                box[u] = 0;
                nums[u] = 1;
                for(int& item: arr) {
                    int v= abs(item-u);
                    if(nums[v] != 1) {
                        box[v] = 1;
                    }
                }
                arr.emplace_back(u);
            } else { //不可行
                printf("Round #%d: %d is out.\n", i, j);
                loser[j] = true;
                cnt ++;
            }
        }
    }
    if(cnt == n) {
        puts("No winner.");
    } else {
        printf("Winner(s):");
        for(int i = 1; i <= n; ++ i) {
            if(loser[i] == false) printf(" %d", i);
        }
        printf("\n");
    }
    return 0;
}

