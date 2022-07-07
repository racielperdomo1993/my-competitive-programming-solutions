#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d %d %d", &a,&b,&c);
    while(a!=0&&b!=0&&c!=0)
    {
        if(c*c==a*a+b*b||a*a==b*b+c*c||b*b==c*c+a*a)
            printf("right\n");
        else printf("wrong\n");
        scanf("%d %d %d", &a,&b,&c);
    }
    return 0;
}