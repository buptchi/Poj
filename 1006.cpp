//因为最大范围没限制好，提交出错了几次

#include <stdlib.h>
#include <stdio.h>
#define MAX 21252 
void main1006()
{
	int j=1;
	int num=1;
	int days=0;
	int p,e,i,d;
	
	while (4==	scanf("%d %d %d %d",&p,&e,&i,&d))
	{
		if ((p==-1)&&(e==-1)&&(i==-1)&&(d==-1))
		{
			break;
		}

		while (!((j%23==p%23)&& (j%28==e%28) &&(j%33==i%33)) )
		{
			j++;
		}
		days=(j-d)%MAX;
		if( days <= 0 )   
		{  
			days += 21252;  
		}  
		printf("Case %d: the next triple peak occurs in %d days.\n",num,days);

		num++;
		j=1;
	}
}