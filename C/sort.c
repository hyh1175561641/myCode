/*
*	选择排序
*/
#include <stdio.h>


int * sort(int * arr,int a){
	int index,temp,i,j;
	
	for(i=0;i<(a-1);i++){
		index=i;
		for(j=i+1;j<a;j++){
			if(arr[j]<arr[index])index=j;
		}
		temp=arr[index];
		arr[index]=arr[i];
		arr[i]=temp;
	}
	return 0;
}

int main()
{
	int arr[5]={3,4,2,5,1};
	int i;

	sort(arr,5);
	for(i=0;i<5;i++){printf("  %d",arr[i]);}
   
	return 0;
}
