/*
1085 PAT单位排行 (25分)
*/
#include<iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <cmath>
#include <vector>

using namespace std;
struct School{
    string name;
    double weightTotal;
    int cnt;
    School(string n, double w, int c) : name(n), weightTotal(w), cnt(c) { }
    School( ) { };
};
void getLower(string& str) {
    for(auto& item: str) {
        item = tolower(item);
    }
}
int cmp(const School& a, const School& b) {
    if((int)a.weightTotal != (int)b.weightTotal) { //分数需要先取整再比较，最后一个测试点
        return a.weightTotal > b.weightTotal;
    } else if(a.cnt != b.cnt) {
        return a.cnt < b.cnt;
    } else {
        return a.name < b.name;
    }
}
int main() {
    vector<School> schoolList;
    unordered_map<string, int> nameToIdx;
    int n, score, m = 0;
    string id, name;
    scanf("%d", &n);
    for(int i = 0; i < n; ++ i) {
        cin >> id >> score >> name;
        getLower(name);
        if(nameToIdx.find(name) == nameToIdx.end()) {
            schoolList.emplace_back(School(name, 0, 0));
            nameToIdx[name] = m;
            m ++;
        }
        int idx = nameToIdx[name];
        schoolList[idx].cnt ++;
        if(id[0] == 'T') {
            schoolList[idx].weightTotal += 1.5*score;
        } else if(id[0] == 'A') {
            schoolList[idx].weightTotal += 1.0*score;
        } else {
            schoolList[idx].weightTotal += score / 1.5;
        }
    }
    sort(schoolList.begin(), schoolList.end(), cmp);
    int prevRanking = 1;
    printf("%d\n", m);
    if(m > 0) {
        printf("%d %s %d %d\n", 1, schoolList[0].name.c_str(), (int)schoolList[0].weightTotal, schoolList[0].cnt);
    }
    for(int i = 1; i < m; ++ i) {
        if((int)schoolList[i].weightTotal != (int)schoolList[i-1].weightTotal) {
            prevRanking = i + 1;
        }
        printf("%d %s %d %d\n", prevRanking, schoolList[i].name.c_str(), (int)schoolList[i].weightTotal, schoolList[i].cnt);
    }
    return 0;
}

