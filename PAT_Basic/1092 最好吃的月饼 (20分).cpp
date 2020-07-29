/*
1092 最好吃的月饼 (20分)
*/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{

    int m, n, tmp;
    int maxSales = -1;
    bool isFirst = true;
    scanf("%d %d", &n, &m);
    vector<int> salesNum(n+1, 0);;
    for(int i = 0; i < m; ++ i) {
        for(int j = 1; j <= n; ++ j) {
            scanf("%d", &tmp);
            salesNum[j] += tmp;
            maxSales = max(salesNum[j], maxSales);
        }
    }
    printf("%d\n", maxSales);
    for(int i = 1; i <= n; ++ i) {
        if(salesNum[i] == maxSales) {
            if(isFirst) isFirst = false;
            else printf(" ");
            printf("%d", i);
        }
    }
    printf("\n");
    return 0;
}
