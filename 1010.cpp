// 真难。。。 2016.3.25


#include <iostream>
#include <algorithm>
using namespace std;

int type[25]={0};
int totletype=0;
int need=0;
int best_diff_type=0;
int best_type_num=5;
int best_combin[5]={0};
int tmp_combin[5]={0};
int same_type[25]={0};
int flag_tie=0;


int copy_combin()
{
	for (int j=1;j<5;j++)															//要设成5，同步tmp_combin，不然出错了啊 啊
	{
		best_combin[j]=tmp_combin[j];
	}
	return 0;
}

void dfs(int need,int diff_type,int num,int marked)
{
	if (num>4)
	{
		return;																							//剪枝
	}

	if (need==0)
	{
		if (diff_type>best_diff_type)
		{
			flag_tie=0;																			//找到新解，置0		
			best_diff_type=diff_type;
			best_type_num=num;
			copy_combin();
		}
		else if (diff_type==best_diff_type)
		{
			if (num<best_type_num)
			{
				flag_tie=0;																			//找到新解，置0		
				best_type_num=num;
				copy_combin();
			}
			else if (num==best_type_num)
			{
				if (tmp_combin[num]>best_combin[num])
				{
					flag_tie=0;	
					copy_combin();
				}
				else if (tmp_combin[num]==best_combin[num])
				{
					flag_tie=1;																	//tie的出来不够严密。。
				}
			}
		}
		return;
	}


	for (int i=marked;i<totletype;i++)										//marked 已经走过的路程进行标记，剪枝
	{
		if (need>=type[i])															//bug2 等号忘记了。。。
		{

			tmp_combin[num+1]=type[i];
			same_type[i]++;
			if (same_type[i]==1)
			{
				dfs(need-type[i],diff_type+1,num+1,i);
			}
			else
			{
				dfs(need-type[i],diff_type,num+1,i);
			}
			
			tmp_combin[num+1]=0;
			same_type[i]--;
		}
		else
		{
			return;																	//剪枝，type[i]已经是从小到大的顺序了，没必要再进行for循环了。
		}
	}
}



int main1010()
{
	int i;
	int input;
	int same_value_time=0;
	//int sameinput[26];
while(1)
{
	memset(type,0,sizeof(type));  
//	memset(sameinput,0,sizeof(sameinput));  

	totletype=0;								//i忘了初始化，
																
	while (true)
	{	
		if (!(cin>>input))
		{
			return 0;
		}
		if (input==0)
		{
			break;
		}
	//	if (sameinput[input]<5)
	//	{																	剪枝
		//	sameinput[input]++;
			type[totletype++]=input;
		//}			
	}
	// sort(type,type+totletype);

	while (cin>>input&&input)
	{
		need=input;

		best_diff_type=0;
		best_type_num=5;
		flag_tie=0;
		
		memset(tmp_combin,0,sizeof(tmp_combin));  
		memset(best_combin,0,sizeof(best_combin));  
		memset(same_type,0,sizeof(same_type)); 


		dfs(need,0,0,0);


		cout<<need<<" ";
		if (best_diff_type==0)
		{
			cout<<"---- none"<<endl;
		}
		else
		{
			cout<<"("<<best_diff_type<<"):";
			if (flag_tie)
			{
				cout<<" tie"<<endl;
			}
			else
			{
				for (int jj=1;jj<best_type_num+1;jj++)
				{
					cout<<" "<<best_combin[jj];
				}
				cout<<endl;
			}
		}
	}
}

int cqz =0;
return 0;
}
