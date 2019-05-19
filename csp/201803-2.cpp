/*************************************************************************
	> File Name: 201803-2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月09日 星期六 11时25分52秒
 ************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;
#define max_n 100


struct point{
    int p, d; 
} arr[max_n + 5];

int vis[max_n + 5] = {0};

void move_one_second(int &L,int &n) {
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++) {
        arr[i].p += arr[i].d;
        if(arr[i].p == 0 || arr[i].p == L) {
            arr[i].d = -arr[i].d;
        }
        if(vis[arr[i].p]) {
            int j = vis[arr[i].p];
            arr[i].d = -arr[i].d;
            arr[j].d = -arr[j].d;
        }
        vis[arr[i].p] = i;
    }
    return ;
}

int main () {
    int n, L, t;
    cin >> n >> L >> t;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i].p;
        arr[i].d = 1;
    }

    for(int i = 1; i <= t; i++) {
        move_one_second(L, n);
    }
    for(int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        cout << arr[i].p;
    }
    cout << endl;
    return 0;
}
