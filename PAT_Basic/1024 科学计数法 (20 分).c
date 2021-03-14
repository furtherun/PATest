/*
备考深大cs机试，听说只能用C，联系了如此复杂的字符串题目
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 10005
int toDigit(char num[], int len, int pos) {
    int ans = 0;
    for(int i = pos; i < len; ++ i) {
        ans =ans*10 + (num[i] - '0');
//        printf("temp ans = %d\n", ans);
    }
    return ans;
}
int main() {
    char num[MAXN];
    scanf("%s", num);
    int len = strlen(num);
//    printf("%s\n", num);
    int ePos = 0;
    while(num[ePos] != 'E') ePos ++;
    int leftShift = (num[ePos+1] == '-');
    int index = toDigit(num, len, ePos+2);
//    printf("index = %d\n", index);
    if(num[0] == '-') {
        printf("-");
    }
    if(index == 0) {
        for(int i = 1; i < ePos; ++ i) {
            printf("%c", num[i]);
        }
        printf("\n");
    } else {
        if(leftShift == 1) {
            for(int i = 0; i < index; ++ i) {
                printf("0");
                if(i == 0) printf(".");
            }
            for(int i = 1; i < ePos; ++ i) {
                if(num[i] != '.') {
                    printf("%c", num[i]);
                }
            }
            printf("\n");
        } else { //-1.2E+10 -12000000000 -1.234E+2 -1.234E+3
            printf("%c", num[1]);
            int len = ePos - 3;
            if(len > index) {
                for(int i = 3; i < ePos; ++ i) {
                    if(i-3 == index) printf(".");
                    printf("%c", num[i]);
                }
            } else {
                for(int i = 3; i < ePos; ++ i) {
                    printf("%c", num[i]);
                }
                while(index>len) {
                    printf("0");
                    index --;
                }
            }
            printf("\n");
        }
    }
    return 0;
}
