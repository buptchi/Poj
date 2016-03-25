
#include <iostream>

using namespace std;

int  main1012()
{
	int M;
	int KK;
	int K;

	int joseph[14]={0};
	while (1)
	{
		cin>>K;

		if (K==0)
		{
			break;
		}
		if (joseph[K])										//1 打表记录
		{
			cout<<joseph[K]<<endl;
			continue;
		}

		KK=2*K;
		M=1;

			int ans[15]={0};
			for (int i=1;i<=K;i++)
			{
				ans[i]=(ans[i-1]+M-1)%(KK-i+1);		//2 递推公式
				if (ans[i]<K)
				{
					M++;
					i=0;										//3	从头开始循环
				}
			}

		cout<<M<<endl;
		joseph[K]=M;
	}
		return 0;
}