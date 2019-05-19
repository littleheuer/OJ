/*************************************************************************
	> File Name: 20181201.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月08日 星期五 00时03分18秒
 ************************************************************************/

#include<stdio.h>

#ifdef _DEBUG
#define DBG(fmt, args...) printf(fmt, ##args);
#else
#define DBG(fmt, args...)
#endif


int r, y, g;

int count(int k, int t) {
    switch(k) {
        case 0 : return t;
        case 1 : return t;
        case 2 : return t + r;
        case 3 : return 0;
        default : return 0;
    }
}

int main() {
    int  n, k, t;
    int sum = 0;
    scanf("%d %d %d", &r, &y, &g);
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) {
        scanf("%d %d", &k, &t);
        sum += count(k, t);
        DBG("sum%d\n", sum);
    }
    printf("%d\n", sum);
    return 0;
}
