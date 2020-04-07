/*
*   float内存表示
*/

#include <stdio.h>
int booll(unsigned int n){
    int a[32]={0};
    int i=0;
    while (n>0)
    {
        a[i]=n%2;
        i=i+1;
        n=n/2;
    }
    for(i=31;i>=0;i--){printf("%d",a[i]);if(i==31){putchar(' ');}if(i==23){putchar(' ');}}
    return 0;
}

int main(int argc, const char * argv[]) {
    
    union{
        float f;
        unsigned int c;
    } aaa;
    float i=256+128+64+32+16+8+4+2+1+0.5+0.25+0.125+0.0625+0.03125+0.015625+0.0078125+0.00390625;
    
    i=1.3456;
    for(i; i<999999;i*=2)
    {aaa.f = i;printf("%015.7f__  ",i);booll(aaa.c);putchar('\n');}
    
    aaa.c = 0x3F000000;
    //    printf("%06.7f__  ",aaa.f);booll(aaa.c);
    
    
    printf("\n");
    return 0;
}
