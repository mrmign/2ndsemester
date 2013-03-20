#include <stdio.h>
#include <string.h>
#include <ctype.h>
/* input a digit between 0 ~ 9999, then convert it to chinese uppercase.*/

int digits[4];
int has_zero;
void to_upper(int digit);
void process(int num);

int main(int argc, char const *argv[])
{
    int num;
    char in[100]="\0";
    while(1)
    {
        scanf("%s",in);
        if(strlen(in) > 4)
        {
            printf("%s\n", in);
            continue;
        }
        int i = 0, j = strlen(in);
        int flag=0;
        while(i < j)
        {
            if (!isdigit(in[i++]))
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            printf("%s\n", in);
            continue;
        }
        num = atoi(in);
        if(num < 0)
            break;
        memset(digits,0,4);
        has_zero = 0;
        process(num);
    }
    return 0;
}
void process(int num)
{
    if(num == 0)
    {
        to_upper(0);
        return;
    }   

    int temp = num; // thousand
    if (temp/1000)
    {
        to_upper(temp/1000);
        printf("千");
        digits[0] = 1;
    }
    else
    {
        digits[0] = 0;
    }
    temp %=1000; // hundrad

    if(temp/100)
    {
        to_upper(temp/100);
        printf("百");
        digits[1] = 1;
    }
    else
    {
        if(digits[0] && temp % 100)
        {
            to_upper(0);// 1024
            has_zero = 1;
        }   
        digits[1] = 0;
    }
    temp %=100; // decade
    if (temp/10)  
    {
        to_upper(temp/10);
        printf("十");
        digits[2] = 1;
    }
    else
    {
        if(!has_zero)
            if(digits[0] && temp % 10 || digits[1] && temp % 10)
                to_upper(0);
        digits[2] = 0;
    }
    temp %=10;
    if (temp)
    {
        to_upper(temp);
    }
    printf("\n");

}
void to_upper(int digit)
{
    switch(digit)
    {
        case 0:
            printf("零");
            break;
        case 1:
            printf("一");
            break;
        case 2:
            printf("二");
            break;
        case 3:
            printf("三");
            break;
        case 4:
            printf("四");
            break;
        case 5:
            printf("五");
            break;
        case 6:
            printf("六");
            break;
        case 7:
            printf("七");
            break;
        case 8:
            printf("八");
            break;
        case 9:
            printf("九");
            break;
    }
}
