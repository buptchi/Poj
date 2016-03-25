//反推法，这题没什么要求时间限制
//最后提交的时候，输出少了个  标点  也错。。。。


#include <iostream>
#include <string>
using namespace std;

int coin[12]={0};

int judge(string str1,string str2,string str3)
{
	int left=0;
	int right=0;
	for (int i=0;i<str1.length();i++)
	{
		left+=coin[str1.at(i)-65];
	}
	for (int i=0;i<str2.length();i++)
	{
		right+=coin[str2.at(i)-65];
	}
	if (str3=="even")
	{
		if (left==right)
		{
			return 1;
		}
	}
	if (str3=="up")
	{
		if (left>right)
		{
			return 1;
		}
	}
	if (str3=="down")
	{
		if (left<right)
		{
			return 1;
		}
	}

	return 0;
}


int main1013()
{
	int weight[2]={-1,1};
	string strwei[2]={"light","heavy"};
	string str1,str2,str3,str4,str5,str6,str7,str8,str9;

	int n=0;
	cin>>n;
	while (n--)
	{
		cin>>str1>>str2>>str3;
		cin>>str4>>str5>>str6;
		cin>>str7>>str8>>str9;

		for (int i=0;i<12;i++)
		{
			for (int j=0;j<2;j++)
			{
				coin[i]=weight[j];
				if (judge(str1,str2,str3))
				{
					if (judge(str4,str5,str6))
					{
						if (judge(str7,str8,str9))
						{
							//K is the counterfeit coin and it is light.
							cout<<(char)(65+i)<<" is the counterfeit coin and it is "<<strwei[j]<<"."<<endl;
							break;
						}
					}
				}
			}
			coin[i]=0;
		}
	}


	return 0;
}