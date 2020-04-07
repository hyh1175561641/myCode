/*
*   字符串空间重叠
*   2019.4.24
*/
#include <string.h>
#include <stdio.h>

void * omemcpy(void *s1, const void * s2,size_t n)
{
    char *su1;
    const char *su2;
    
    //for(su1=s1,su2=s2;0<n;++su1,++su2,--n)*su1 = *su2;
    su1=s1;
    su2=s2;
    for(su1+=n,su2+=n;0<n;--n)*--su1=*--su2;
    return 0;
}

int main() {
    char a[]="1234567890";
    printf("a=%s\n",a);
    char * b=a+1;
    printf("b=%s\n",b);
    //omemcpy(a,b,9);
    memcpy(b,a,9);
    printf("a=%s\n",a);


    
    return 0;
}
