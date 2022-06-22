/*
这个代码没有AC
7-1 Forever (20分)
这题我有点投机了，因为好像之前听别人讨论说后几位一定是9
所以降了一些时间复杂度，多拿了最后一个测试点。
我第一次提交只过了2个点（投机和暴力一样），那个时候没注意求gcd(m,n)之后还有一个素数要求。
改完之后，过了最后一个测试。
第三个测试点应该和输出顺序有关，我的写法有些问题，等我注意到可能顺序有影响的时候，需要大改
需要加数组和排序，但是我刚改完第二题（还剩3min)，来不及了。
看了别人的通过码，应该是考察DFS+剪枝的，但是我除了模板DFS，写的并不好，所以剩下的几天要多练习这方面。
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
bool isOk(int x) {
    if(x <= 2 || x %2 == 0) return false;
    int limit = (int)sqrt(x);
    for(int i = 3; i <= limit; i += 2) {
        if(x % i == 0) return false;
    }
    return true;
}
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
int getStart(int k) {
    int ans = 1;
    for(int i = 1; i < k; ++ i) {
        ans *= 10;
    }
    return ans + 99;
}
int getAllDigit(int x) {
    int ans = 0;
    while(x) {
        ans += x%10;
        x /= 10;
    }
    return ans;
}
void check(int left, int right, int m, bool& flag) {
    for(int i = left; i < right; i += 100) {
        if(getAllDigit(i) == m) {
            int n = getAllDigit(i+1);
            if(isOk(gcd(m, n))) {
                flag = true;
                printf("%d %d\n", n, i);
            }
        }
    }
}
int main() {
    int n, k, m;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i) {
        scanf("%d %d", &k, &m);
        printf("Case %d\n", i);
        bool flag = false;
        int left = getStart(k);
        int right = (left-9)*10;
        check(left, right, m, flag);
        if(!flag) {
            puts("No Solution");
        }
    }
    return 0;
}
