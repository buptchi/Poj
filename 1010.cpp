// ���ѡ����� 2016.3.25


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
	for (int j=1;j<5;j++)															//Ҫ���5��ͬ��tmp_combin����Ȼ�����˰� ��
	{
		best_combin[j]=tmp_combin[j];
	}
	return 0;
}

void dfs(int need,int diff_type,int num,int marked)
{
	if (num>4)
	{
		return;																							//��֦
	}

	if (need==0)
	{
		if (diff_type>best_diff_type)
		{
			flag_tie=0;																			//�ҵ��½⣬��0		
			best_diff_type=diff_type;
			best_type_num=num;
			copy_combin();
		}
		else if (diff_type==best_diff_type)
		{
			if (num<best_type_num)
			{
				flag_tie=0;																			//�ҵ��½⣬��0		
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
					flag_tie=1;																	//tie�ĳ����������ܡ���
				}
			}
		}
		return;
	}


	for (int i=marked;i<totletype;i++)										//marked �Ѿ��߹���·�̽��б�ǣ���֦
	{
		if (need>=type[i])															//bug2 �Ⱥ������ˡ�����
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
			return;																	//��֦��type[i]�Ѿ��Ǵ�С�����˳���ˣ�û��Ҫ�ٽ���forѭ���ˡ�
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

	totletype=0;								//i���˳�ʼ����
																
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
	//	{																	��֦
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
