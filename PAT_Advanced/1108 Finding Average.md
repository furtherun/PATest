## 1108 Finding Average (20分)

The basic task is simple: given *N* real numbers, you are supposed to calculate their average. But what makes it complicated is that some of the input numbers might not be legal. A **legal** input is a real number in [−1000,1000] and is accurate up to no more than 2 decimal places. When you calculate the average, those illegal numbers must not be counted in.

### Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer *N* (≤100). Then *N* numbers are given in the next line, separated by one space.

### Output Specification:

For each illegal input number, print in a line `ERROR: X is not a legal number`where `X` is the input. Then finally print in a line the result: `The average of K numbers is Y` where `K` is the number of legal inputs and `Y` is their average, accurate to 2 decimal places. In case the average cannot be calculated, output `Undefined` instead of `Y`. In case `K` is only 1, output `The average of 1 number is Y` instead.

### Sample Input 1:

```in
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35 
```

### Sample Output 1:

```out
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
```

### Sample Input 2:

```in
2
aaa -9999  
```

### Sample Output 2:

```out
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined
```



### My Code

```cpp
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath> //use the fabs function in PAT
#include <cstring>

using namespace std;
const int MAXN = 100;

int main() {
	char originStr[MAXN], motifiedStr[MAXN];
	double tmp, total = 0;
	int n, cnt = 0;
	scanf("%d", &n);
	while (n --) {
		scanf("%s", originStr);
		sscanf(originStr, "%lf", &tmp);
		sprintf(motifiedStr, "%.2f", tmp);
		bool flag = true; //compare the number in originStr and motifiedStr
		int len = strlen(originStr);
		//consider 2 situations, if originStr is longer than 
		//motifiedStr(2 decimal places), so it's illegal, else orginStr
		//is shorter than motifiedStr(consider the 0 at the end), so it
		//is legal.
		for (int i = 0; i < len; ++ i) {
			if (originStr[i] != motifiedStr[i]) {
				flag = false;
				break;
			}
		}
//		cout << "originStr = " << originStr << endl;
//		cout << "motifiedStr = " << motifiedStr << endl;
		if (flag == false || fabs(tmp) > 1000) {
			//orginStr does't equal motifiedStr or float out of range 
			printf("ERROR: %s is not a legal number\n", originStr);
		} else {
			total += tmp;
			cnt ++;
		}
	}
	if (cnt == 0) {
		printf("The average of 0 numbers is Undefined\n");
	} else if (cnt == 1) {
		printf("The average of 1 number is %.2f\n", total / cnt);
	} else {
		printf("The average of %d numbers is %.2f\n", cnt, total / cnt);
	}
	return 0;
}
```



### 总结

`sscanf`和`sprintf`这两个之前没有接触过的处理字符串的函数，可以在数字和字符串之间形成好的转化。这道题最后的输出很容易想到，但是判断两位小数的合法性比较复杂，是值得留意的一道数值转换类题目。