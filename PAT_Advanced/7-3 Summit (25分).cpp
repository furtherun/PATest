/*
7-1 Good in C (20分)
坑爹空格占了7分
测试数据
I LOVE U
代码写的快，但是不能AC就很难受了
关于怎么分割单词感觉需要学一学，应该是有固定套路的，之后去LeetCode找一个模板
自己几次分割都是临场现构思的，耽误时间还不一定好。
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;
const int MAXN = 26;
const int row = 7;
vector<vector<string>> tables(MAXN, vector<string>());
void output(string &str) {
    int len = (int)str.size();
    for(int j = 0; j < row; ++ j) {
        for(int i = 0; i < len; ++ i) {
            printf("%s", tables[str[i]-'A'][j].c_str());
            printf(i == len-1? "\n": " ");
        }
    }
}
int main() {
    string tmp;
    for(int i = 0; i < MAXN; ++ i) {
        for(int j = 0; j < row; ++ j) {
            cin >> tmp;
            tables[i].emplace_back(tmp);
        }
    }
    getchar();
    getline(cin, tmp);
    int len = (int)tmp.size();
    vector<string> ans;

    int now = 0, start = 0;
    while(now < len) {
        while(start < len && !isupper(tmp[start])) {
            start ++;
        }
        if(start >= len) break;
        now = start;
        while(now < len && isupper(tmp[now])) {
            now ++;
        }
        string sub = string(tmp, start, now-start);
        ans.emplace_back(sub);
        start = now+1;
//        cout << "sub = " << sub << endl;
    }
    for(int i = 0; i < (int)ans.size(); ++ i) {
        if(i != 0 ) {
            printf("\n");
        }
        output(ans[i]);
    }
    return 0;
}
