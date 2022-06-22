## 1137 Final Grading (25分)

For a student taking the online course "Data Structures" on China University MOOC (http://www.icourse163.org/), to be qualified for a certificate, he/she must first obtain no less than 200 points from the online programming assignments, and then receive a final grade no less than 60 out of 100. The final grade is calculated by $G = (G_{min-term} \times 40 \% + G_{final} \times 60 \%)$ if $G_{min-tern} > G_{final}$, or $G_{final}$  will be taken as the final grade *G*. Here $G_{mid-term}$ and $G_{final}$ are the student's scores of the mid-term and the final exams, respectively.

The problem is that different exams have different grading sheets. Your job is to write a program to merge all the grading sheets into one.

### Input Specification:

Each input file contains one test case. For each case, the first line gives three positive integers: P , the number of students having done the online programming assignments; M, the number of students on the mid-term list; and N, the number of students on the final exam list. All the numbers are no more than 10,000.

Then three blocks follow. The first block contains P online programming scores $G_p$'s; the second one contains M mid-term scores $G_{mid-term}$'s; and the last one contains N final exam scores $G_{final}$'s. Each score occupies a line with the format: `StudentID Score`, where `StudentID` is a string of no more than 20 English letters and digits, and `Score` is a nonnegative integer (the maximum score of the online programming is 900, and that of the mid-term and final exams is 100).

### Output Specification:

For each case, print the list of students who are qualified for certificates. Each student occupies a line with the format:

`StudentID` $G_p$ $G_{mid-term}$ $G_{final}$ *G*

If some score does not exist, output "−1" instead. The output must be sorted in descending order of their final grades (*G* must be rounded up to an integer). If there is a tie, output in ascending order of their `StudentID`'s. It is guaranteed that the `StudentID`'s are all distinct, and there is at least one qullified student.

### Sample Input:

```in
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
```

### Sample Output:

```out
missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84
```



### My Code

```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
const int MAXN = 10005;

class Student {
public:
	string name;
	int ojG, midTermG, finalG, G;
	Student() {
		midTermG = finalG = G = -1;
	}
};
int cmp(Student a,Student b) {
	if(a.G != b.G) {
		return a.G > b.G;
	} else if(a.name != b.name) {
		return a.name < b.name;
	}
}
int main() {
	Student stu[MAXN];
	int p, m, n; //oj list, mid-term list and final list
	scanf("%d %d %d", &p, &m, &n);
	int len = 0, tmpG;
	string tmpName;
	map <string, int> nameToID;
	vector <string> idToName;
	for(int i = 0; i < p; ++ i) {
		cin >> tmpName >> tmpG;
		if(tmpG >= 200) {
			stu[len].name = tmpName;
			stu[len].ojG = tmpG;
			nameToID[tmpName] = len;
			idToName.push_back(tmpName);
			len ++;
		}
	}
	for(int i = 0; i < m; ++ i) {
		cin >> tmpName >> tmpG;
		auto it = nameToID.find(tmpName);
		if(it != nameToID.end()) {
			int id = it->second;
			stu[id].midTermG = tmpG;
		}
	}
	for(int i = 0; i < n; ++ i) {
		cin >> tmpName >> tmpG;
		auto it = nameToID.find(tmpName);
		if(it != nameToID.end()) {
			int id = it->second;
			stu[id].finalG = tmpG;
			if(stu[id].midTermG > stu[id].finalG) {
				stu[id].G = round(stu[id].midTermG*0.4 + stu[id].finalG*0.6);
			} else {
				stu[id].G = stu[id].finalG;
			}
		}
	}
	sort(stu, stu + len, cmp);
//	cout << "len = " << len << endl;
	for(int i = 0; i < len; ++ i) {
//		cout << stu[i].name << " " << stu[i].ojG << " " \
//		    << stu[i].midTermG << " " << stu[i].G << endl;
		if(stu[i].G >= 60) {
			Student& s = stu[i];
			cout << s.name << " " << s.ojG << " " << s.midTermG << " "\
			 << s.finalG << " " << s.G << endl;
		} else {
			break;
		}
	}
	return 0;
}


```



### 总结

结构体排序题，是比较规范的一类题目。好久没有写这类题，写到一半的时候才推倒重来。里面还涉及了名字到ID的映射，方便排序标号。

