/*************************************************************************
	> File Name: vector.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年03月08日 星期五 20时38分40秒
 ************************************************************************/

#include<iostream>
#include<set>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <ctime>
using namespace std;



int main() {
    set<int> ss;
    int n;
    while((cin >> n) && n) {
        ss.insert(n);
    }
    for(set<int>::iterator iter = ss.begin(); iter != ss.end();iter++) {
        cout << *iter << endl;
    }
    for(auto x : ss) {
        cout << x << endl;
    }
    return 0;
}
