## 1112 Stucked Keyboard (20分)

On a broken keyboard, some of the keys are always stucked. So when you type some sentences, the characters corresponding to those keys will appear repeatedly on screen for *k* times.

Now given a resulting string on screen, you are supposed to list all the possible stucked keys, and the original string.

Notice that there might be some characters that are typed repeatedly. The stucked key will always repeat output for a fixed *k* times whenever it is pressed. For example, when *k*=3, from the string `thiiis iiisss a teeeeeest` we know that the keys `i` and `e` might be stucked, but `s` is not even though it appears repeatedly sometimes. The original string could be `this isss a teest`.

### Input Specification:

Each input file contains one test case. For each case, the 1st line gives a positive integer *k* (1<*k*≤100) which is the output repeating times of a stucked key. The 2nd line contains the resulting string on screen, which consists of no more than 1000 characters from {a-z}, {0-9} and `_`. It is guaranteed that the string is non-empty.

### Output Specification:

For each test case, print in one line the possible stucked keys, in the order of being detected. Make sure that each key is printed once only. Then in the next line print the original string. It is guaranteed that there is at least one stucked key.

### Sample Input:

```in
3
caseee1__thiiis_iiisss_a_teeeeeest  
```

### Sample Output:

```out
ei
case1__this_isss_a_teest
```

### My Code

```cpp
#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;
const int MAXN = 255;
bool isStuck[MAXN];
bool havePrinted[MAXN];

int main() {
	int k;
	scanf("%d", &k);
	fill(isStuck, isStuck+MAXN, true); //which key get stuck
	string str;
	cin >> str;
	str = str + "#"; //simplify slove all chars
	int p = 1, len = str.size(), cnt = 1;
	while(p < str.size()) {
		if(str[p] == str[p-1]) {
			cnt ++;
		} else {
			if(cnt % k != 0) {
				isStuck[str[p-1]] = false;
			}
			cnt = 1;
		}
		p ++;
	}
	fill(havePrinted, havePrinted, false); //whick key has been printed
	p = 0; //print the stuck keys in order
	while(p < len - 1) { //the last char is "#" we've added before
		if(isStuck[str[p]] && havePrinted[str[p]] == false) {
			printf("%c", str[p]);
			havePrinted[str[p]] = true;
			p = p + k;
		} else {
			p ++;
		}
	}
	printf("\n");
	p = 0; //print the orginal string
	while(p < len - 1) {
		printf("%c", str[p]);
		if(isStuck[str[p]]) {
			p = p + k;
		} else {
			p ++;
		}
	}
	return 0;
} 
```



### 总结

本题是string + hash，思路比较重要。逆向思维，采用排除法，排除一定不是stuck keys的字符。这样第二次遍历的时候就能确认谁需要被输出（也就是它**可能**为stuck key）。这里有些人采用map来进行char到bool的映射，因为总体的字母比较少，也没有什么超时的危险。

