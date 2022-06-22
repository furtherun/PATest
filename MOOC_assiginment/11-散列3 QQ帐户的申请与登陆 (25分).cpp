/*
11-散列3 QQ帐户的申请与登陆 (25分)
存在号码为0开头的情况，因此不要使用int来存储QQid
*/
#include<iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    string type, qqId, qqPassword;
    unordered_map<string, string> box;
    scanf("%d", &n);
    for(int i = 0; i < n; ++ i) {
        cin >> type >> qqId >> qqPassword;
        if(type == "N") {
            if(box.find(qqId) == box.end()) {
                box[qqId] = qqPassword;
                printf("New: OK\n");
            } else {
                printf("ERROR: Exist\n");
            }
        } else if(type == "L") {
            if(box.find(qqId) == box.end()) {
                printf("ERROR: Not Exist\n");
            } else if(box[qqId] == qqPassword) {
                printf("Login: OK\n");
            } else {
                printf("ERROR: Wrong PW\n");
            }
        }
    }
    return 0;
}
