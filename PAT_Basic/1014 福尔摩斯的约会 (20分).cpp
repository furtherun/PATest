#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    string s1, s2, str1, str2;
    cin >> s1 >> s2 >> str1 >> str2;
    vector<string> day = {"MON", "TUE", "WED", "THU", "FRI", "SAT","SUN"};
    int cnt = 0;
    int len = min(s1.size(), s2.size());
    for (int i = 0; i < len; ++ i) {
        if (s1[i] == s2[i]) {
            if (cnt == 0 && s1[i] <= 'G' && s1[i] >= 'A') {
                cout << day[s1[i] - 'A'];
                cnt ++;
            }
            else if (cnt == 1) {
                if (s1[i] <= 'N' && s1[i] >= 'A') {
                    printf(" %02d:", s1[i] - 'A' + 10);
                    break;
                } else if (isdigit(s1[i])) {
                    printf(" %02d:", s1[i]-'0');
                    break;
                }
            }
        }
    }
    len = min(str1.size(), str2.size());
    for (int i = 0; i < len; ++ i) {
        if (isalpha(str1[i]) && str1[i] == str2[i]) {
            printf("%02d\n", i);
            break;
        }
    }
    return 0;
}
