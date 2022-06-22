/*
1067 Sort with Swap(0, i) (25分)
我这样写是对题目描述进行模拟，
事实上，我们还有许多解法，比如它并不关注过程，也就是说。
我们只需要寻找环路，一共能分成几个环，考虑0从一个环跳跃到另一个环路。
甚至是，每次只考虑于pos[0]进行交换，也就是说，每次不是操作0（题目是每次操作0，让0回到pos[0]）
可以转化为一直操作pos[0]处的元素，让它调整为0
*/
#include<iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
void changePos(vector<int>& arr, vector<int>& pos, int p, int q) {
    //p and q is element
    int idxOfPInArr = pos[p], idxOfQInArr = pos[q];
    pos[p] = idxOfQInArr;
    pos[q] = idxOfPInArr;
//    cout << "pos[p] = " << pos[p] << ", pos[q] = " << pos[q] << endl;
    swap(arr[idxOfPInArr], arr[idxOfQInArr]);
}
int main() {
    int n, tmp;
    scanf("%d", &n);
    vector<int> arr(n), pos(n);
    /*
    pos[i]: 确定元素i在pos[i]上
    arr[i]: 给定序列
    */
    int cnt = 0;
    for(int i = 0; i < n; ++ i) {
        scanf("%d", &tmp);
        arr[i] = tmp;
        pos[tmp] = i;
    }
    for(int i = 0; i < n; ++ i) {
        if(i > 0 && arr[i] == i) {
            continue;
        }
        if(i > 0 && arr[0] == 0) { //新的环路，i一定没归位
            changePos(arr, pos, 0, i);
            cnt ++;
        }
        while(arr[0] != 0) {
            int posOfZero = pos[0];
            changePos(arr, pos, 0, posOfZero);
            cnt ++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
