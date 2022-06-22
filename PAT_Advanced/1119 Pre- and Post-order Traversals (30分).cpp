/*
1119 Pre- and Post-order Traversals (30分)
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;
//int root;
bool isUnique = true;
vector<int> pre, post, ans;
void buildTree(int preL, int preR,int postL,int postR) {
    if(preL == preR) { //当区间只有一个结点的时候，直接返回
        ans.emplace_back(pre[preL]);
        return;
    }
    if(pre[preL] == post[postR]) { //合理序列，前序第一个和后序最后一个是根节点
        /*
        为了寻找一下组子序列，需要保证子序列的前序后序匹配
        */
        int i = preL + 1;
        for(; i <= preR; ++ i) {
            if(pre[i] == post[postR-1]) break;
        }
        /*
        分成的2段都满足前序的首项等于后序的末项
        [preL+1, i-1] 与 [postL, postL+numL-1] 左子树节点数：numL = i - (preL+1);
        [i, preR] 与 [postL + numL, postR-1]
        可能存在一种情况，左（右）子树不存在，就不能确定这剩下的区间应该划分给哪一个子树
        */
        int numL = i - (preL+1);
        if(numL > 0) {
            buildTree(preL+1, i-1, postL, postL+numL-1);
        } else {
            isUnique = false;
        }
        ans.emplace_back(post[postR]);
        buildTree(i, preR, postL+numL, postR-1);
    }
}
int main()
{
    int n, tmp;
    scanf("%d", &n);

    for(int i = 0; i < n; ++ i) {
        scanf("%d", &tmp);
        pre.emplace_back(tmp);
    }
    for(int i = 0; i < n; ++ i) {
        scanf("%d", &tmp);
        post.emplace_back(tmp);
    }
//    for(int i = 0; i < n; ++ i) {
//        cout << pre[i]  << ", = " << post[i] << endl;
//    }
    buildTree(0, n-1, 0, n-1);
    puts(isUnique? "Yes": "No");
    for(int i = 0; i < n; ++ i) {
        printf("%d", ans[i]);
        printf(i == n-1? "\n": " ");
    }
    return 0;
}
