#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long int64;
int64 a[15],b[15];

int64 Extend_Euclid(int64 a, int64 b, int64&x, int64& y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    int64 d = Extend_Euclid(b,a%b,x,y);
    int64 t = x;
    x = y;
    y = t - a/b*y;
    return d;
}
//求解模线性方程组x=ai(mod ni)
int64 China_Reminder(int len, int64* a, int64* n)
{
    int i;
    int64 N = 1;
    int64 result = 0;
    for(i = 0; i < len; i++)
        N = N*n[i];
    for(i = 0; i < len; i++)
    {
        int64 m = N/n[i];
        int64 x,y;
        Extend_Euclid(m,n[i],x,y);
        x = (x%n[i]+n[i])%n[i];
        result = (result + m*a[i]*x%N)%N;
    }
    return result;
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i = 0; i < n; i++)
            scanf("%lld %lld",&a[i],&b[i]);
        printf("%lld\n",China_Reminder(n,b,a));
    }
    return 0;
}