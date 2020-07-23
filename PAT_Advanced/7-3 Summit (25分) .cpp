/*
7-3 Summit (25分) 
get 21分
没AC，感觉和之前考的某道题目类似，但是感觉写法一致，但就是没AC
感觉上我写的逻辑判断没啥问题，我看网上的都是暴力求解，我一开始没打算试，
感觉这类题目还是按照题目写几个逻辑，然后一点一点模拟吧。
我把每条边的关系转化成了最后有几个边相连，就忽略了一些细节判断吧，
感觉可能需要再判断每一组之前是否相连？
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <unordered_set>
#include <cmath>
using namespace std;
const int MAXN = 205;
vector<vector<int>> graph(MAXN, vector<int>(MAXN, -1));
int main() {
    int n, m, k, len, a, b;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++ i) {
        scanf("%d %d", &a, &b);
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    scanf("%d", &k);
    vector<int> visited(MAXN);
    unordered_set<int> heads;
    for(int t = 1; t <= k; ++ t) {
        fill(visited.begin(), visited.end(), 0);
        heads.clear(); //一开始忘了清空
        scanf("%d", &len);
        for(int i = 0; i < len; ++ i) {
            scanf("%d", &a);
            heads.insert(a);
            visited[a] ++;
            for(int j = 1; j <= n; ++ j) {
                if(j != a && graph[a][j] != -1) {
                    visited[j] ++;
                }
            }
        }
        int cnt = 0;
        int minOther = n;
        for(int i = n; i >= 1; -- i) { //倒着来取最小
            if(visited[i] == len) {
                cnt ++;
                if(heads.find(i) == heads.end()) {
                    minOther = i;
                }
//                cout << "visited " << i << " = " << visited[i] << endl;
            }
        }
        if(cnt == len) {
            printf("Area %d is OK.\n", t);
        } else if(cnt > len) {
            printf("Area %d may invite more people, such as %d.\n", t, minOther);
        } else {
            printf("Area %d needs help.\n", t);
        }
    }
    return 0;
}
