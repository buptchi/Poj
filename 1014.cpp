
#include <iostream>

using namespace  std;

int mb[7];
int flag;

void dfs(int rest,int pre)
{
	if (flag)
	{
		return;
	}
	if (!rest)
	{
		flag=1;
		return;
	}
	
	for (int i=pre;i>0;i--)
	{
		if (mb[i])
		{
			if (i<=rest)
			{
				mb[i]--;
				dfs(rest-i,i);
			
				if (flag)
				{
					break;
				}
//				mb[i]++;
			}
		}
	}
	return;

}

int main1014()
{
	int k=1;
	while (cin>>mb[1]>>mb[2]>>mb[3]>>mb[4]>>mb[5]>>mb[6])
{
	
	int totlevalue=0;
	int half=0;
	int even=0;

	for (int i=1;i<7;i++)
	{
		totlevalue+=mb[i]*i;
		even+=mb[i]%2;
	}
	half=totlevalue/2;

	if (totlevalue==0)
	{
		break;
	}

	cout<<"Collection #"<<k<<":"<<endl;
	k++;
	if (totlevalue%2)
	{
		cout<<"Can't be divided."<<endl;
		cout<<endl;
		continue;
	}
	if (even==0)
	{
		cout<<"Can be divided."<<endl;
		cout<<endl;
		continue;
	}

	for (int i=1;i<7;i++)
	{
//		mb[i]=mb[i]%50;
	}
	flag=0;
	dfs(half,6);
	if (flag)
	{
		cout<<"Can be divided."<<endl;
		cout<<endl;
	}
	else
	{
		cout<<"Can't be divided."<<endl;
		cout<<endl;
	}
}


	return 0;
}