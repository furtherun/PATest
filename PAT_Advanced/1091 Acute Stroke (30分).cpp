/*
1091 Acute Stroke (30分)
就因为少写了一个条件，找了1小时bug
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <unordered_set>
using namespace std;
struct Node{
    int x, y, z;
    Node() = default;
    Node(int a, int b, int c): x(a), y(b), z(c) { };
    Node Add(Node tmp) {
        return Node(x+tmp.x, y+tmp.y, z+tmp.z);
    }
};
const int MAXM = 1286, MAXN = 128, MAXL = 60;
int volume[MAXM][MAXN][MAXL];
vector<Node> vi{
    Node(0, 0, 1),Node(0, 0, -1), Node(0, 1, 0),
    Node(0, -1, 0), Node(1, 0, 0), Node(-1, 0, 0)
};
int M, N, L, T;
bool isValid(Node idx) {
    if(idx.x >= M || idx.y >= N || idx.z >= L || min({idx.x, idx.y, idx.z}) < 0) {
        return false;
    }
    return true;
}
bool isVisited(Node tmp) {
    if(volume[tmp.x][tmp.y][tmp.z] == -1) {
        return true;
    }
    return false;
}
bool isSick(Node tmp) {
    if(volume[tmp.x][tmp.y][tmp.z] == 1) {
        return true;
    }
    return false;
}
void visitTo(Node tmp) {
    volume[tmp.x][tmp.y][tmp.z] = -1;
}
int bfs(Node idx) {
    int cnt = 0;
    queue<Node> q;
    q.push(idx);
    visitTo(idx);
    while(!q.empty()) {
        int len = (int)q.size();
        for(int i = 0; i < len; ++ i) {
            Node f = q.front(); q.pop(); cnt ++;
            for(const Node& item: vi) {
                Node tmp = f.Add(item);
                if(isValid(tmp) && (isVisited(tmp) == false) && isSick(tmp)) {
//                    cout << "bfs visit" << tmp.x <<", " << tmp.y << ", "<< tmp.z << endl;
                    q.push(tmp);
                    visitTo(tmp);
                }
            }
        }
    }
//    cout << "now time size = " << cnt << endl;
    return cnt;
}
void bfsTraversal() {
    int total = 0;
    for(int i = 0; i < L; ++ i) {
        for(int j = 0; j < M; ++ j) {
            for(int k = 0; k < N; ++ k) {
                Node tmp = Node(j, k, i);
                if(isVisited(tmp) == false && isSick(tmp)) { //这里进入之前需要判断是否为病变点
//                    cout << "this time visit" << tmp.x <<", " << tmp.y << ", "<< tmp.z << endl;
                    int ans = bfs(tmp);
                    if(ans >= T) total += ans;
                }
            }
        }
    }
    printf("%d\n", total);
}
int main() {
    int tmp;
    scanf("%d %d %d %d", &M, &N, &L, &T);
    for(int i = 0; i < L; ++ i) {
        for(int j = 0; j < M; ++ j) {
            for(int k = 0; k < N; ++ k) {
                scanf("%d", &tmp);
                volume[j][k][i]= tmp;
            }
        }
    }
    bfsTraversal();
    return 0;
}
