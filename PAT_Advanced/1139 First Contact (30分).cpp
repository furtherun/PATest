/*
1139 First Contact (30分)
这一题逻辑思考正确后，还是出现了几个问题
0. vector<vector<int>> relations(MAXN, vector<int>｛MAXN, 0｝); 可能是不太熟悉编辑器的缘故，
   写错了也没太注意到，这一句好长时间才发现错误
1. 一开始排序的过程：是不带符号的过程，那个时候就应该取绝对值了，调整后只通过了0测试，18分
2. 发现输出需要调整为4位数，可能一直再刷LeetCode，平时不太注重输出格式的原因，修正后24分
3. 调整让a与b不能直接联系，即i取b,j取a, 这时i与j是好朋友，也分别是a和b的好朋友，
   但是事实上缺少了中间联系人，这一点逻辑修正后30分
*/
#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;
int MAXN = 310;
int main() {
    int n, m;
    scanf("%d %d",&n, &m);
    int a, b;
    int aId, bId;
    unordered_map<int, int> nameToId;
    unordered_map<int, int> idToName; //with sign of the number
    vector<vector<int>> relations(MAXN, vector<int>(MAXN, 0));
    /*
    vector<vector<int>> relations(MAXN, vector<int>｛MAXN, 0｝);
    一开始没注意写错了括号，一直运行中出错，里面用成了列表初始化
    */
    int idx = 0;
    for(int i = 0; i < m; ++ i) {
        scanf("%d %d", &a, &b);
        if(nameToId.find(a) == nameToId.end()) {
            nameToId[a] = idx;
            idToName[idx] = a;
            idx ++;
        }
        aId = nameToId[a];
        if(nameToId.find(b) == nameToId.end()) {
            nameToId[b] = idx;
            idToName[idx] = b;
            idx ++;
        }
        bId = nameToId[b];
//        cout << "aId = " << aId << ", bId = " << bId << endl;
        relations[aId][bId] = 1;
        relations[bId][aId] = 1;
    }
//    cout << idx << endl;
    int k;
    scanf("%d", &k);
    vector<pair<int,int>> ans;
    while(k--) {
        scanf("%d %d", &a, &b);
        if(nameToId.find(a) == nameToId.end() || nameToId.find(b) == nameToId.end()) {
            printf("0\n");
            continue;
        }
        aId = nameToId[a];
        bId = nameToId[b];
        for(int i = 0; i < idx; ++ i) {
            if(relations[aId][i]==0 || i == bId|| a * idToName[i] < 0) {
                continue;
                /*
                需要排除i就是bId的情况
                */
            }
            for(int j = 0; j < idx; ++ j) {
                if(relations[bId][j]==0 || j == aId || b * idToName[j] < 0) {
                    continue;
                }
                /*
                i contact with aId, and they are in same gender, as the same time,
                j contact with bId in the same gender;
                */
                if(relations[i][j] == 1) {
                    ans.emplace_back(pair<int,int>{abs(idToName[i]), abs(idToName[j])});
                    /*
                    这时候输出的就和符号无关了
                    */
                }
            }
        }
        printf("%d\n", (int)ans.size());
        sort(ans.begin(), ans.end());
        for(const auto& u: ans) {
            printf("%04d %04d\n", u.first, u.second);
            /*
            输出格式保证为4位
            */
        }
        ans.clear();
    }
    return 0;
}

