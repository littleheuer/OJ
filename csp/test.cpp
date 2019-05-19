/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月08日 星期五 20时13分35秒
 ************************************************************************/

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

bool cmp(int a, int b) {
    if(a < b) return 0;
    return 1;
}
 
int main () {
    int arr[4] = {1, 6, 3, 5};
    sort(arr, arr + 4, cmp);
    for(int i = 0; i < 4; i++) {
        cout << arr[i] <<endl;
    }
    return 0;
}
