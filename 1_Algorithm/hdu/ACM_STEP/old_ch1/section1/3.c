#include<stdio.h>

int main(void){
	int a,b;
	while(EOF!=scanf("%d%d",&a,&b)
				&&((a!=0)||(b!=0))){
		printf("%d\n",a+b);
	}
	return 0;
}
