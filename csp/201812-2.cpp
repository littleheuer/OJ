/*************************************************************************
	> File Name: 201812-2-x.c
	> Author: 
	> Mail: 
	> Created Time: 2019年03月08日 星期五 17时46分55秒
 ************************************************************************/

#include<stdio.h>
int r, y, g;


void judge (int T, int &k, int &t) {
    if(k == 0) return ;
    switch(k) {
        case 1 : T += r - t;break;
        case 2 : T += r + g + y - t;break;
        case 3 : T += r + g - t;break;
    }
    t = T % (r + y + g);
    if(t <= r) {
        k = 1;
        t = r - t;
    } else if(t <= r + g){
        k = 3;
        printf("jt%d\n", t);
        t = r + g - t;
    } else {
        k = 2;
        t = r + y + g - t;
    }
    return ;
}

int main() {
    int n;
    scanf("%d %d %d", &r, &y, &g);
    scanf("%d", &n);
    int k, t;
    for(int i = 0; i < n; i++) {
        cin >> r >> y >> g;
        cin >> n;
        judge(sum, k, t);
        switch(k) {
            case 0 : sum += t;break; 
            case 1 : sum += t;break;
            case 2 : sum = sum + t + r;break;
            case 3 : break;
        }
    }
    cout << sum <<endl;
    return 0;
}
