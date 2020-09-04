/*
1098 Insertion or Heap Sort (25分)
*/
#include<iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <cmath>
#include <vector>

using namespace std;
const int MAXN = 505;
void output(const vector<int>& vi) {
    int len = (int)vi.size();
    for(int i = 0; i < len; ++ i) {
        printf("%d", vi[i]);
        printf(i == len-1?"\n": " ");
    }
}
void postTraverse(vector<int>& nums, int n, int idx, vector<int>& ans) {
    if(idx >= n) return;
    postTraverse(nums, n, (idx+1)*2 - 1, ans);
    postTraverse(nums, n, (idx+1)*2, ans);
    ans.emplace_back(nums[idx]);
}
int main() {
    int k, n, tmp;
    scanf("%d %d", &k, &n);
    vector<int> arr, ans;
    while(k --) {
        arr.clear();
        for(int i = 0; i < n; ++ i) {
            scanf("%d", &tmp);
            arr.emplace_back(tmp);
        }
        if(is_heap(arr.begin(), arr.end())) {
            puts("Max Heap");
        } else if(is_heap(arr.begin(), arr.end(), greater<int>())) {
            puts("Min Heap");
        } else {
            puts("Not Heap");
        }
        postTraverse(arr, n, 0, ans);
        output(ans);
        ans.clear();
    }
    return 0;
}
