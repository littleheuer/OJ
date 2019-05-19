/*************************************************************************
	> File Name: 201803-1.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月09日 星期六 11时04分54秒
 ************************************************************************/

#include<iostream>
using namespace std;

int count (int & plus, int pre, int k) {
    if(k == 1) {
        return 1;
    } else if(k == 2) {
        if(pre == 2) {
            plus += 2;
            return plus;
        } else {
            plus = 2;
            return 2;
        }
    }
}

int main () {
    int k, pre = 0, plus = 2, sum = 0;
    while((cin >> k) && k) {
        sum += count(plus, pre, k);
        cout << "plus" << plus << "sum" << sum << endl;
        pre = k;
    }
    cout << sum << endl;
    return 0;
}
