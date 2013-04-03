/* 
 * this file is for discrete math homework.
 */
#include <stdio.h>
#include <stdlib.h>

/*
    f(p) =(24p + 11) mod 29
    abcdefghijklmnopqrstuvwxyz,.!
*/

int main(int argc, char const *argv[])
{
    int cnt[26] = {0};
    FILE *in = fopen("sec.txt","r");
    int i = 0;
    int ch;
    //count the most two used char
   /* 
    while((ch = fgetc(in)) != EOF)
    {
        if(ch > 96 && ch < 123)
            cnt[ch-97]++;
    }
    close(in);
    int max_1 = 0, max_2 = 1;
    // for (i = 0; i < 26; ++i)
    // {
    //     printf("%c---%d\n",'a'+i, cnt[i]);
    // }
    for (i = 2; i < 26; ++i)
    {
        if(cnt[i] > cnt[max_1])
        {
            if(cnt[max_1] > cnt[max_2])
                max_2 = i;
            else
                max_1 = i;
        }
        else
        {
            if(cnt[i] > cnt[max_2])
                max_2 = i;
        }
    }*/
    // printf("%c %c\n", max_1+97, max_2 + 97);

    // decription
    int encription = 0;
    char alph [] = "abcdefghijklmnopqrstuvwxyz,.!";
    while((ch = fgetc(in)) != EOF)
    {
        if(ch > 96 && ch < 123)
        {
            encription = ch - 'a';
        }
        else if (ch == ',')
        {
            encription = 26;
        }
        else if (ch == '.')
        {
            encription = 27;
        }
        else if (ch == '!')
        {
            encription = 28;
        }
        else
        {
            printf("%c", ch);
            continue;
        }
        for (i = 0; i < 29; ++i)
        {
            int res = 7*i + 3 - encription;
            // int res = 22*i + 19 - encription;
            if (res % 29 == 0)
            {
                printf("%c", alph[i]);
                break;
            }
        }
    }
    printf("\n");
    return 0;
}
