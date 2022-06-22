## **1132** **Cut Integer** (20分)

Cutting an integer means to cut a K digits lone integer Z into two integers of (K/2) digits long integers A and B. For example, after cutting Z = 167334, we have A = 167 and B = 334. It is interesting to see that Z can be divided by the product of A and B, as 167334 / (167 × 334) = 3. Given an integer Z, you are supposed to test if it is such an integer.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (≤ 20). Then N lines follow, each gives an integer Z (10 ≤ Z <${2}^{31}$). It is guaranteed that the number of digits of Z is an even number.

### Output Specification:

For each case, print a single line `Yes` if it is such a number, or `No` if not.

### Sample Input:

```in
3
167334
2333
12345678   
```

### Sample Output:

```out
Yes
No
No
```



### My Code

```cpp
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int toNum(string str, int begin, int end) {
	int n = 0;
	for (int i = begin; i < end; ++ i) {
		n = n * 10 + str[i] - '0';
	}
	return n;
}
bool isDivided(string& originStr) {
	int len = originStr.length();
	int originNum = toNum(originStr, 0, len);
//	cout << originNum << endl;
	bool flag = false;
//	for (int i = 1; i < len; ++ i) {
//		int leftNum =  toNum(originStr, 0, i);
//		int rightNum =  toNum(originStr, i, len);
//		int tmp = leftNum * rightNum;
//		if (tmp != 0 && originNum % tmp == 0) {
//			flag = true;
//			break;
//		}
//	}
	int leftNum =  toNum(originStr, 0, len/2);
	int rightNum =  toNum(originStr, len/2, len);
	int tmp = leftNum * rightNum;
	if (tmp != 0 && originNum % tmp == 0) {
		flag = true;
	}
	return flag;
}
int main() {
	int n;
	string strNum;
	scanf("%d", &n);
	while (n --) {
		cin >> strNum;
		puts(isDivided(strNum)? "Yes": "No");
	}
	return 0;
} 
```



### 总结

又开始刷题了，好久不写OJ，有写不太习惯。第一题一般都是热身题，**注意读题**，这次一开始又读错了题目，理解错误，浪费了时间。考察内容是字符串的处理，包括提取子串和字符串转化为数字。算是一个简单的热身题目了。