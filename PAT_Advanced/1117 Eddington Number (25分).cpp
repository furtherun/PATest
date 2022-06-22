/*
1117 Eddington Number (25分)
被套路的一个逻辑问题，题目的唯一逻辑条件：求满足大于E总数有E个的数字
对于排序后的第i个数字（从0开始）x，可以知道大于x-1的数字，一共有i+1个，因为x和x前面的数字都大于
x-1，可以根据下标统计总数i-0+1个；
当x-1为E，此时下标i满足i+1也为E的时候为边界值
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
int main() {
    int n, tmp;
    scanf("%d", &n);
    vector<int> arr;
    for(int i = 0; i < n; ++ i) {
        scanf("%d", &tmp);
        arr.emplace_back(tmp);
    }
    int ans = 0;
    sort(arr.begin(), arr.end(), greater<int>());
    for(int i = 0; i < (int)arr.size(); ++ i) {
        if(arr[i]-1 >= i+1) {
            ans ++;
        }
    }
    printf("%d", ans);
    return 0;
}

