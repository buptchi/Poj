//�����˼�������ͨ���ˣ�������������
//�տ�ʼ���������ڣ�Ҫ�������㣬һ���ǳ��ȣ�һ��ľ��
// return��ʹ�ÿ��Զ�ֵ��
//���ǳ�ʱ�ˡ�����֦

//11.30��������3������,�ύ��һ��wa��Ȼ������Ųο����룬���˻������������AC�ˣ���������֮ǰ����������˰�

#include<iostream>
#include <algorithm>
using namespace std;

int part_num;
int stickpart[64];											//ȫ�ֱ�������Ҫ���򣬲�Ҫ��dfs������ظ���

int original_totletime;
int orig;

int marked[64];


int   dfs(int origial_time,int original,int cur)		//�ر�ע��dfs���γɣ���ͬ�������ͬ����������ֵ���Բ�ͬ��
{
	if (original==0)
	{
		if (origial_time==original_totletime-2)				//�Ѿ����������һ�ֲ���ƥ����
			return 2;
		
		for(cur = 0; marked[cur]==1; cur++)  
			;  
		marked[cur] = 1;  
		if(dfs(origial_time+1, orig-stickpart[cur],cur+1)==2)			//��֦���ӵ�һ������ûʹ�õı�����ʼ
			return 2;  
		marked[cur] = 0;  
		return 0;							//����ʧ��

	}
	else
{
	
	if (cur>=part_num-1)
		return 0;

	for (int i=cur;i<part_num;i++)
	{
		if (marked[i]==1)
			continue;
		if ((stickpart[i]==stickpart[i-1])&&(!marked[i-1]))			//��֦��ǰ����ͬ�ĳ���ûʹ�ã������Ҳ��ʹ��
			continue;
	   if (original<stickpart[i])
			continue;
	
		marked[i]=1;
		if (dfs(origial_time,original-stickpart[i],i)==2)
			return 2;														
		marked[i]=0;

	}
	return 0;
}

}

	
bool cmp (int i,int j) 
{ 
	return (i>j); 
}

int main1011()
{
	int sum;
	int part_max;
	
	int ans;
	int original;

	while (cin>>part_num && part_num)
	{
		memset(stickpart,0,sizeof(stickpart));
		sum=0;

		for (int i=0;i<part_num;i++)
		{
			cin>>stickpart[i];
			sum+=stickpart[i];	
		}
		
		memset(marked,0,sizeof(marked));
		sort(stickpart,stickpart+part_num,cmp);
		part_max=stickpart[0];
		ans=0;
	for (original=part_max;original<=sum/2;original++)
	{
		if (sum%original!=0)
		{
			continue;
		}
		else
		{
			original_totletime=sum/original;
			orig=original;
		}
		
		marked[0]=1;
		if (2==dfs(0,original-stickpart[0],0))
		{
			ans=2;
			cout<<original<<endl;
			break;
		}
		marked[0]=0;
	}

	if (ans!=2)
	{
		cout<<sum<<endl;
	}
	memset(marked,0,sizeof(marked));
}


return 0;
}