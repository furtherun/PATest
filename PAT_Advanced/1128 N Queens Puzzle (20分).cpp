/*
1128 N Queens Puzzle (20分)
又是一个被插图弄崩溃的孩子
这里姑且说一下，给的配图不是常规的行和列
pic1 逆时针旋转90度，pic2顺时针旋转90度变成我们常说的行和列
主要是读题，题目也说了，就不要自己瞎猜题意。
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;
const int MAXN = 505;
struct Node{
    int x, y;
    Node( ) = default;
    Node(int a, int b) : x(a), y(b) { };
};
bool isDangerous(Node& a, Node& b) {
    if( a.x == b.x || a.y == b.y || (abs(a.x - b.x) == abs(a.y - b.y)) ) {
        return true;
    }
    return false;
}
bool check(vector<Node>& vi) {
    int n = (int)vi.size();
    for(int i = 0; i < n; ++ i) {
        for(int j = i+1; j < n; ++ j) {
            if(isDangerous(vi[i], vi[j])) {
                return false;
            }
        }
    }
    return true;
}
int main() {
    int k, n, tmp;
    scanf("%d", &k);
    vector<Node> ans;
    while(k --) {
        scanf("%d", &n);
        ans.clear();
        for(int i = 1; i <= n; ++ i) {
            scanf("%d", &tmp);
            ans.emplace_back(Node(i, tmp));
        }
        puts(check(ans)? "YES": "NO");
    }
    return 0;
}
