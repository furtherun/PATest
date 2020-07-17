/*
7-3 Telefraud Detection (25分)
这题逻辑上有点绕弯，如果只是写谁可能是嫌疑人可能会简单很多
但是一开始提到了是否属于同一个团伙，1034 Head of a Gang (30分)一下就联想到这个感觉
这个题肯定是多年前做的了，也就是估计当年自己写不出来，所以才印象深刻。
所以一开始就想按照人来进行构建，之后写了一半（其实相对于这题来说，比重很少了）
发现打电话的应该是先构造矩阵！之后推了重写。
虽然一遍AC但是感觉代码还是很混乱，之后再看看别人的吧。
顺便一提，这题我AC的时候，发现前几名AC的是30分的最后一题；我也没觉得麻烦，就先写的这个25分
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <algorithm>
#include <unordered_set>
using namespace std;
struct Person{
    int calls, receive;
    bool isSuspect;
    Person() :calls(0), receive(0), isSuspect(false) { };
};
const int MAXN = 1005;
int k, n, m;
vector<Person> person(MAXN, Person());
vector<vector<int>> matrix(MAXN, vector<int> (MAXN, 0));
vector<int> father(MAXN, -1);
int findSet(int x) {
    if(father[x] < 0) {
        return x;
    }
    return father[x] = findSet(father[x]);
}
void unionSet(int a, int b) {
    int aRoot = findSet(a);
    int bRoot = findSet(b);
    if(aRoot != bRoot) {
        if(aRoot < bRoot) {
            father[aRoot] += father[bRoot];
            father[bRoot] = aRoot;
        } else {
            father[bRoot] += father[aRoot];
            father[aRoot] = bRoot;
        }
    }
}
int main() {
    scanf("%d %d %d", &k, &n, &m);
    int caller, receiver, duration;
    vector<int> ans;
    for(int i = 0; i < m; ++ i) {
        scanf("%d %d %d", &caller, &receiver, &duration);
        matrix[caller][receiver] += duration;
    }
    for(int i = 1; i <= n; ++ i) {
        Person& p = person[i];
        for(int j = 1; j <= n; ++ j) { //一开始这里漏了一个等号，找bug找了10min
            if(j == i) continue;
            if(matrix[i][j] > 0 && matrix[i][j] <= 5) {
                p.calls ++;
                if(matrix[j][i] > 0) { //被回复了
                    p.receive ++;
                }
            }
        }
        if(p.calls > k && (1.0*p.receive <= 0.2*p.calls)) {
            p.isSuspect = true;
            ans.emplace_back(i);
        }
    }
    if(ans.empty()) {
        puts("None");
    } else {
        int len = (int) ans.size();
        for(int i = 0; i < len; ++ i) {
            for(int j = i+1; j < len; ++ j) {
                if(matrix[ans[i]][ans[j]] > 0 && matrix[ans[j]][ans[i]] > 0) {
                    unionSet(ans[i], ans[j]);
                }
            }
        }
        vector<vector<int>> gangs(MAXN, vector<int>());
        for(int i = 0; i < len; ++ i) {
            gangs[findSet(ans[i])].emplace_back(ans[i]);
        }
        for(int i = 0; i <= n; ++ i) {
            if(!gangs[i].empty()) {
                for(int j = 0; j < (int)gangs[i].size(); ++ j) {
                    printf("%d", gangs[i][j]);
                    printf(j == (int)gangs[i].size()-1? "\n": " ");
                }
            }
        }
    }
    return 0;
}
