/*
*	结构体的内存排列
*/
#include <stdio.h>

int main()
{
	struct AAA{
		char a[5];
		int b;
		short int c;
	};

	struct BBB{
		char * d;
		short int e;
		struct AAA f;
		char g;
	};
	union {
        struct BBB bbb;
        unsigned char u[sizeof(struct BBB)];
    } abc;
    int len=sizeof(struct BBB);
    int i;

    for(i=0;i<len;i++)abc.u[i]=0xaa;
    abc.bbb.d=(char*)(0-1);
    abc.bbb.e=0-1;
    abc.bbb.f.a[0]=0-1;
    abc.bbb.f.a[1]=0-1;
    abc.bbb.f.a[2]=0-1;
    abc.bbb.f.a[3]=0-1;
    abc.bbb.f.a[4]=0-1;
    abc.bbb.f.b=0-1;
    abc.bbb.f.c=0-1;
    abc.bbb.g=0-1;

	for(i=0;i<len;i++){
		printf("%3x  ",abc.u[i]);
		if(i%4==3)putchar('\n');
	}
	return 0;
}
