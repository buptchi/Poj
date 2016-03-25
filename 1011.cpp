//测试了几个数据通过了，代码能运行了
//刚开始的问题在于，要返回两层，一个是长度，一个木棒
// return的使用可以多值。
//但是超时了。。剪枝

//11.30周日下午3点来调,提交第一次wa，然后对照着参考代码，调了会变量。。。。AC了，，，，，之前哪里出问题了啊

#include<iostream>
#include <algorithm>
using namespace std;

int part_num;
int stickpart[64];											//全局变量设置要精简，不要和dfs里面的重复了

int original_totletime;
int orig;

int marked[64];


int   dfs(int origial_time,int original,int cur)		//特别注意dfs的形成，不同情况，不同迭代，返回值可以不同，
{
	if (original==0)
	{
		if (origial_time==original_totletime-2)				//已经整除，最后一轮不用匹配了
			return 2;
		
		for(cur = 0; marked[cur]==1; cur++)  
			;  
		marked[cur] = 1;  
		if(dfs(origial_time+1, orig-stickpart[cur],cur+1)==2)			//剪枝，从第一个最大的没使用的变量开始
			return 2;  
		marked[cur] = 0;  
		return 0;							//回溯失败

	}
	else
{
	
	if (cur>=part_num-1)
		return 0;

	for (int i=cur;i<part_num;i++)
	{
		if (marked[i]==1)
			continue;
		if ((stickpart[i]==stickpart[i-1])&&(!marked[i-1]))			//剪枝，前面相同的长度没使用，则这次也不使用
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