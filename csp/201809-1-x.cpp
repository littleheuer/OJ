/*************************************************************************
	> File Name: 201809-1-x.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月08日 星期五 23时25分40秒
 ************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#define MAX_N 1000
int arr[MAX_N + 5] = {0};

int main() {
        int n;
        cin >> n;
    for (int i = 1; i <= n; i++) {
                cin >> arr[i];
            
    }
    for (int i = 1; i <= n; i++) {
                i == 1 || cout << " ";
                cout << (arr[i - 1] + arr[i] + arr[i + 1]) / (i == 1 || i == n ? 2 : 3);
            
    }
        return 0;

}
