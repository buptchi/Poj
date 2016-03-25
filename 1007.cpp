//用结构体，捆绑，排序，
//用CPP方便好多

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct dna 
{
	int weight;
	string str;
}DNA[100];


int inversionNum(string str,int n)
{
	int i,j;
	int inver_sum=0;

	for (i=0;i<n;i++)
	{
		for (j=i;j<n;j++)
		{
			if (str[i]>str[j])
			{
				inver_sum++;
			}
		}
	}
	return inver_sum;
}

bool compare(dna a,dna b)
{
	return a.weight<b.weight; //升序排列
}

int  main1007()
{
	int i;
	int n,m;

	cin>>n>>m;
	for (i=0;i<m;i++)
	{
		cin>>DNA[i].str;
		DNA[i].weight=inversionNum(DNA[i].str,n);
	}
	stable_sort(DNA,DNA+m,compare);
	for (i=0;i<m;i++)
	{
		cout<<DNA[i].str<<endl;
	}
	return 0;
}