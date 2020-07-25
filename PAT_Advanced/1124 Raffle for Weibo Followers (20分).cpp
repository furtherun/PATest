/*
1124 Raffle for Weibo Followers (20分)
完结，感慨万千，勉强刷完一遍。加油！
注意理解题意，不明白的多读题。
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <unordered_set>
using namespace std;
int main() {
    int m, n, s;
    scanf("%d %d %d", &m, &n, &s);
    unordered_set<string> box;
    string name;
    bool flag = false; //是否有人获奖
    for(int i = 1; i <= m; ++ i) {
        cin >> name;
         if(box.find(name) != box.end()) { //如果这人已经获奖，就跳过他
            s += 1; //下一个获奖的人
        }
        if(i == s) {
            box.insert(name);
            printf("%s\n", name.c_str());
//            printf("test -- %s\n", name.c_str());
            flag = true;
            s += n;
        }
    }
    if(!flag) puts("Keep going...");
    return 0;
}

