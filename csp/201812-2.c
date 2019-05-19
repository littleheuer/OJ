/*************************************************************************
	> File Name: 201812-2.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月08日 星期五 11时17分02秒
 ************************************************************************/

#include<stdio.h>
int r, y, g, m, ans;

int bump(int temp) {
    if((temp + ans) % m > (r + y)) {
        return 0;
    } else {
        return y + r - (temp + ans) % m;
    }
}

int main (){
    int n,k,t;
    ans = 0;
    scanf("%d %d %d", &r, &y, &g);
    m = r + y + g;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &k, &t);
        if (k == 0){
            ans += t;
        }
        else if (k == 1){
            int temp = r - t;
            ans += bump(temp);
        }
        else if(k == 2) {
            int temp = r + y - t;
            ans += bump(temp); 
        } else if(k == 3) {
            int temp = r + y + g - t;
            ans += bump(temp);
        }
    }
    printf("%d\n", ans);
    return 0;
}
