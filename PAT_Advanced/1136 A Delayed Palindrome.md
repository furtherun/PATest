## 1136 A Delayed Palindrome (20分)

Consider a positive integer *N* written in standard notation with *k*+1 digits $a_i$ as  $a_k$ $\cdots$ $a_1$, $a_0$with 0≤$a_i$<10  or all *i* and $a_k$>0. Then *N* is **palindromic** if and only if $a_i = a_{k - i}$  for all *i*. Zero is written 0 and is also palindromic by definition.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. First, the non-palindromic number is reversed and the result is added to the original number. If the result is not a palindromic number, this is repeated until it gives a palindromic number. Such number is called **a delayed palindrome**. (Quoted from https://en.wikipedia.org/wiki/Palindromic_number )

Given any positive integer, you are supposed to find its paired palindromic number.

### Input Specification:

Each input file contains one test case which gives a positive integer no more than 1000 digits.

### Output Specification:

For each test case, print line by line the process of finding the palindromic number. The format of each line is the following:

```
A + B = C
```

where `A` is the original number, `B` is the reversed `A`, and `C` is their sum. `A` starts being the input number, and this process ends until `C` becomes a palindromic number -- in this case we print in the last line `C is a palindromic number.`; or if a palindromic number cannot be found in 10 iterations, print `Not found in 10 iterations.` instead.

### Sample Input 1:

```in
97152  
```

### Sample Output 1:

```out
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.
```

### Sample Input 2:

```in
196   
```

### Sample Output 2:

```out
196 + 691 = 887
887 + 788 = 1675
1675 + 5761 = 7436
7436 + 6347 = 13783
13783 + 38731 = 52514
52514 + 41525 = 94039
94039 + 93049 = 187088
187088 + 880781 = 1067869
1067869 + 9687601 = 10755470
10755470 + 07455701 = 18211171
Not found in 10 iterations.
```



### My Code

```cpp
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 1005;
class BigNum {
public:
	int len;
	int d[MAXN];
	BigNum() {
		len = 0;
	}
};
bool isPalindrome(BigNum& b) {
	bool flag = true;
	int len = b.len;
	for (int i = 0; i < len / 2; ++ i) {
		if (b.d[i] != b.d[len-i-1]) {
			flag = false;
			break;
		}
	}
	return flag;
}
void bnReverse(BigNum& a, BigNum& b) {
	b.len = a.len;
	for(int i = 0; i < a.len; ++ i) {
		b.d[i] = a.d[a.len-i-1];
	}
}
void bnAdd(BigNum& a, BigNum& b) {
	int len = a.len;
	int carry = 0;
	for (int i = 0; i < len; ++ i) {
		int tmp = a.d[i] + b.d[i] + carry;
		a.d[i] = tmp % 10;
		carry = tmp / 10;
	}
	if (carry != 0) {
		a.d[len] = carry;
		a.len ++;
	}
}
void bnPrint(BigNum& a) {
	for (int i = a.len - 1; i >= 0; -- i) {
		printf("%d", a.d[i]);
	}
}
int main() {
	BigNum bna, bnb;
	char tmp[MAXN];
	scanf("%s", tmp);
	bna.len = strlen(tmp);
	for(int i = 0; i < bna.len; ++ i) {
		bna.d[i] = tmp[bna.len-i-1] - '0';
	}
	if(isPalindrome(bna)) {
		printf("%s is a palindromic number.\n", tmp);
	} else {
		bool flag = false;
		for (int i = 0; i < 10; ++ i) {
			bnPrint(bna);
			printf(" + ");
			bnReverse(bna, bnb);
			bnPrint(bnb);
			printf(" = ");
			bnAdd(bna, bnb);
			bnPrint(bna);
			printf("\n");
			if(isPalindrome(bna)) {
				bnPrint(bna);
				printf(" is a palindromic number.\n");
				flag = true;
				break;
			}
		}
		if(flag == false) {
			printf("Not found in 10 iterations.\n");
		}
	}
	return 0;
}
```



### 总结

本题是模板式的大数加法，顺带着还考察了字符串对称，但是数据量比较小，所以最基本的判断就可以通过。需要对大数处理比较熟练才能快速写出正确代码。