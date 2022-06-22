/*
1082 Read Number in Chinese (25分)
虽然只是25分，但是逻辑很复杂 
*/
#include <iostream>
#include <stack>
#include <cstdio>
#include <vector> 
using namespace std;
void readNumber(int x, vector<string>& units, vector<string>& numbers, stack<string>& ans) {
	for(int i = 0; x > 0; ++ i, x /= 10) {
		if(x % 10 != 0) { //最后一位为0 
			if(i != 0) { //个位无需单位 
				ans.push(units[i]);
			}
			ans.push(numbers[x%10]);
		} else { //判断当前位为0的情况 
			if(i == 4 && x % 10000 != 0) {//处理到了万位，且数值大于万 
				ans.push(units[i]); //补充万 
			}
			if(ans.empty() || ans.top() == units[0] || ans.top() == units[4]) { //已经有万或者0了 
				continue; //跳过 
			}
			ans.push(units[0]); //读0  
		} 
	}
}
void output(stack<string>& st) {
	while(!st.empty()) {
		cout << st.top();
		if(st.size() > 1) {
			printf(" ");
		}
		st.pop();
	}
}
int main(){
	vector<string> units { "ling", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi" };
	vector<string> numbers { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };
    int n;
    scanf("%d", &n);
    if(n < 0) {
    	printf("Fu ");
    	n = -n;
    }
    if(n == 0) {
    	cout << units[0] << endl;
    } else if(n > 0) {
    	stack <string> ans;
		readNumber(n, units, numbers, ans);	
		output(ans);
    }
    return 0;
}


