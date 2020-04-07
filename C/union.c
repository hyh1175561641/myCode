/*
*   利用union共用空间特点，用两种格式输出空间内容
*/

#include <stdio.h>

int main()
{
    union {
        float aaa;
        unsigned char bbb[sizeof(float)];
    } abc;
    int a=sizeof(float),i;
    
    
    abc.aaa=0.5;
    for(i=a-1;i>-1;i--) {
        printf("%02X",(unsigned char)abc.bbb[i]);}
    putchar('\n');
    
    abc.aaa=0.25;
    for(i=a-1;i>-1;i--) {
        printf("%02X",(unsigned char)abc.bbb[i]);}
    putchar('\n');
    
    abc.aaa=0.75;
    for(i=a-1;i>-1;i--) {
        printf("%02X",(unsigned char)abc.bbb[i]);}
    putchar('\n');
    
    
    abc.bbb[0]=0x00;
    abc.bbb[1]=0x00;
    abc.bbb[2]=0x00;
    abc.bbb[3]=0x00;


    printf("%f\n",abc.aaa);
    
    return 0;
}