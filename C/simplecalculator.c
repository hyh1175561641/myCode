/*
*   简易计算器  + - * / %
*   2019.4.25
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ownstring(const char * str,int * a,int * b,char * bl)
{
    const char * p;
    ptrdiff_t cha;
    char temp[10];

    p = strpbrk(str,"+-*/%");
    cha = p-str;
    *a=atoi(strncpy(temp,str,cha));
    *bl=p[0];
    *b=atoi(strcpy(temp,p+1));
    return 0;
}

int calcu(int a,int b,char bl )
{
    int r;
    
    switch (bl) {
        case '+':
            r = a+b;
            break;
        case '-':
            r = a-b;
            break;
        case '*':
            r = a*b;
            break;
        case '/':
            r = a/b;
            break;
        case '%':
            r = a%b;
            break;
        default:
            r = 0;
            break;
    }
    
    return r;
}

int main() {
  
    char str[100]="  45 +  54  ";
    //scanf("%s",str);

    int a=0;
    int b=0;
    int r=0;
    char bl=' ';
    
    ownstring(str,&a,&b,&bl);
    r = calcu(a,b,bl);
    if(bl=='%'){
        printf("%d%c%d=%d...%d\n",a,bl,b,calcu(a,b,'/'),r);
    }
    else
    {
        printf("%d%c%d=%d\n",a,bl,b,r);
    }
    return 0;
}
