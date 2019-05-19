/*************************************************************************
	> File Name: 201809-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月08日 星期五 21时32分21秒
 ************************************************************************/

#include<iostream>
#include<vector>
#define max_n 1000
using namespace std;

int main () {
    int n, k;
    cin >> n;
    int arr[max_n + 5] = {0};
    int arr2[max_n + 5] = {0};
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    arr2[0] = (arr[0] + arr[1]) / 2;
    for(int i = 1; i < n - 1; i++) {
        arr2[i] = (arr[i - 1] + arr[i] + arr[i + 1]) / 3;
    }
    arr2[n - 1] = (arr[n - 2] + arr[n - 1]) / 2;
    for(int i = 0; i < n - 1; i++) {
        cout << arr2[i] << " ";
    }
    cout << arr2[n - 1] << endl;
    return 0;
}
