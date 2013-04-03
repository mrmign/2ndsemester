/*http://www.cppblog.com/qywyh/archive/2007/08/27/30943.aspx*/
#include <stdio.h>
// #include <cmath>

#define MAXN  100
int nn;
int a[MAXN];
int n[MAXN];

int lmes();

int main() {
    /*a[0] = 33; a[1] = 8; a[2] = 9; a[3] = 89;
    n[0] = 99; n[1] = 98; n[2] = 97; n[3] = 95;
    nn = 4;*/
    printf("Input the number of modular.\n");
    scanf("%d", &nn);
    printf("Input each remainder & modular.\n");
    int temp = nn;
    while(nn--)
    {
        scanf("%d %d",&a[nn], &n[nn]);
        // printf("input:%d--> %d %d\n",nn, a[nn], n[nn]);
    }
    nn = temp;
    printf("%d\n", lmes());
    return 0;
}
int egcd(int a, int b, int *x, int *y) {
    int d;
    if (b == 0) {
        *x = 1; *y = 0;
        return a;
    } else {
        d = egcd(b, a%b, y, x);
        *y -= a/b*(*x);
        return d;
    }
}

int lmes() {
    int i, tm=1, mf, y, ret=0, m;
    for (i=0; i<nn; i++) tm *= n[i];
        for (i=0; i<nn; i++) {
            m = tm/n[i];
            egcd(m, n[i], &mf, &y);
            ret += (a[i]*m*(mf%n[i]))%tm;
        }
    return (ret+tm)%tm;
}