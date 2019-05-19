/*************************************************************************
	> File Name: 201809-2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月08日 星期五 23时52分10秒
 ************************************************************************/

#include<iostream>
#define max_n 2000
using namespace std;

struct Node {
    int a,b;
};
Node arr[max_n + 5];

int count (Node &x, Node &y) {
    int a = (x.a > y.a ? x.a : y.a);
    int b = (x.b < y.b ? x.b : y.b);
    if(a > b) return 0;
    return b - a;
}

int main () {
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i].a >> arr[i].b;
    }
    Node temp;
    for(int i = 0; i < n; i++) {
        cin >> temp.a >> temp.b;
        for(int j = 0; j < n; j++) {
            ans += count(arr[j], temp);
        }
    }
    cout << ans << endl;
    return 0;
}
