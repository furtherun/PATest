/*
1095 Cars on Campus (30分)
好久没处理这一类记录的题目了，感觉有些陌生了；
就像之前没熟悉链表题的套路，其实感觉链表的题目很好写
逻辑清晰再动笔！
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <unordered_map>
using namespace std;
struct Record{
    string name;
    int time, state; //1: in; -1: out
    Record(string n, int t, int s) :name(n), time(t), state(s) { };
    Record() { };
    bool operator< (const Record& a)& {
        if(name != a.name){
            return name < a.name;
        } else if(time != a.time) {
            return time < a.time;
        } else {
            return state > a.state;
        }
    }
};
int cmp(const Record& a,const Record& b) {
    return a.time < b.time;
}
int transferToSecend(int hh, int mm, int ss) {
    return hh * 3600 + mm * 60 + ss;
}
vector<Record> records, cars;
map<string, int> waitTimes;
int main() {
    int n, k, hh, mm, ss;
    scanf("%d %d", &n, &k);
    string name, state;
    for(int i = 0; i < n; ++ i) {
        cin >> name;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        cin >> state;
        records.emplace_back(Record(name, transferToSecend(hh, mm, ss), state=="in"? 1:-1));
    }
    sort(records.begin(), records.end());
//    for(auto item : records) {
//        printf("%s %d %d\n", item.name.c_str(), item.time, item.state);
//    }

    int maxTime = -1;
    for(int i = 1; i < n; ++ i) {
        Record& prev = records[i-1], &curr = records[i];
        if(prev.name == curr.name && prev.state == 1 && curr.state == -1) {
            cars.emplace_back(prev); //保存有效记录加速查找
            cars.emplace_back(curr);
            waitTimes[curr.name] += (curr.time - prev.time); //已经按照字母排序
            maxTime = max(maxTime, waitTimes[curr.name]);
        }
    }
    //查询部分
    sort(cars.begin(), cars.end(), cmp); //所有有效记录按时间排序
    int len = cars.size();
    vector<int> stopNumNow(len, 0);
    for(int i = 0; i < len; ++ i) {
        if(i == 0) {
            stopNumNow[i] += cars[i].state;
        } else { //姑且说明一下，当前停车数为上一状态+目前这个车辆的状态（进+1，出-1）
            stopNumNow[i] = stopNumNow[i-1] + cars[i].state;
        }
    }
    //这段自写有点问题，需要调整，看的别人的代码
    int pre = 0;
    for(int i = 0; i < k; ++ i) {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int tmp = transferToSecend(hh, mm, ss);
        int j;
        for(j = pre; j < len; ++ j) {
            if(cars[j].time > tmp) {
                printf("%d\n", stopNumNow[j-1]);
                break;
            } else if(j == len-1) {
                printf("%d\n", stopNumNow[j]);
            }
        }
        pre = j;
    }
//    cout << " -- test --" << stopNumNow[len-1] <<endl;
    //输出最高值部分
    for(auto& item: waitTimes) {
        if(item.second == maxTime) {
            printf("%s ", item.first.c_str());
        }
    }
    printf("%02d:%02d:%02d", maxTime/3600, (maxTime%3600)/60, maxTime%60);
    return 0;
}

