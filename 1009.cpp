//做了一天，
//刚开始，知道暴力不行，想怎么化简，想利用前面的一个点来得出后面一个点，，编成功了，但只处理了两个小的测试数据，
//后来，看了网上的思路，将代码进行改进。成功了。
//提交时出现问题，幸好很快就找到百度文库上一篇资料，说最后一行要进行边界处理。。。。最后accepted
//不足的地方，在于，空间方面没有进行仔细使用，变量命名与初始化等比较乱。


#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct  samepixel
{
	int min;
	int max;
	int pixel_value;
};									//标准输入的一行，像素值，与连续的个数
struct  markpixel
{
	int pos;
	int maxvalue;
};									//标记特殊  像素的位置，以及最大绝对值

int aroudpix[8];

bool comp(markpixel mp1,markpixel mp2)
{
	return mp1.pos < mp2.pos;
}									//对标记的像素的排序，按位置升序排列

void getAroudpix(int pos,int width,int sum)				//得到一个点周围的八个点，对不合格的点置零
{
	aroudpix[0]=pos-width-1;
	aroudpix[1]=pos-width;
	aroudpix[2]=pos-width+1;
	aroudpix[3]=pos-1;
	aroudpix[4]=pos+1;
	aroudpix[5]=pos+width-1;
	aroudpix[6]=pos+width;
	aroudpix[7]=pos+width+1;
	if (pos<=width)
	{
		aroudpix[0]=aroudpix[1]=aroudpix[2]=0;
	}
	if (pos>=sum-width+1)
	{
		aroudpix[5]=aroudpix[6]=aroudpix[7]=0;
	}
	if (pos%width==0)
	{
		aroudpix[2]=aroudpix[4]=aroudpix[7]=0;
	}
	if (pos%width==1)
	{
		aroudpix[0]=aroudpix[3]=aroudpix[5]=0;
	}
}											

int  main1009()
{

while (1)
{
	vector<samepixel> PIXElTABEL;						//储存输入的像素信息
	vector<markpixel> MARKPIXELS;					//所有 标记像素的 结果
	list<int> markpos;												//标记像素的位置
	int max_around;

	int width;
	samepixel sp;
	int sum;
	int samenum;

	int j;				//某点周围的坐标
	int k;			//在哪个相同像素的区段内
	int ik;			//中心像素的区段

	//////////////////////读取输入，创建PIXELTABAL
	cin>>width;
	if (width==0)
	{
		break;
	}
	sum=0;
	while (1)
	{
		cin>>sp.pixel_value>>samenum;
		if (samenum==0)
		{
			break;
		}
		sp.min=sum;
		sum+=samenum;
		sp.max=sum;
		PIXElTABEL.push_back(sp);
	}

	///////////////////将每段连续像素的点进行标记，以及周围的8个像素
	for (int t=0;t<PIXElTABEL.size();t++)
	{
		markpos.push_back(PIXElTABEL[t].min+1);
		getAroudpix(PIXElTABEL[t].min+1,width,sum);
		for (j=0;j<8;j++)
		{
			if (aroudpix[j]!=0)
			{
				markpos.push_back(aroudpix[j]);
			}
		}
	}

	//////////////////////////打个补丁，，，最后一行的行头与行尾也要进行标记，，不然不能会出错。。。
	markpos.push_back(sum);
	getAroudpix(sum,width,sum);
	for (j=0;j<8;j++)
	{
		if (aroudpix[j]!=0)
		{
			markpos.push_back(aroudpix[j]);
		}
	}
	markpos.push_back(sum-width+1);
	getAroudpix(sum-width+1,width,sum);
	for (j=0;j<8;j++)
	{
		if (aroudpix[j]!=0)
		{
			markpos.push_back(aroudpix[j]);
		}
	}

	markpos.unique();
	markpos.sort();

	////////////////////////////////////对每一个标记的像素进行求值
	std::list<int>::iterator it;
	for (it= markpos.begin(); it != markpos.end(); it++)
	{
		max_around=0;
		ik=0;
		while (!(*it>PIXElTABEL[ik].min && *it<=PIXElTABEL[ik].max)){ik++;}
		getAroudpix(*it,width,sum);

		for (j=0;j<8;j++)
		{
			if (aroudpix[j]!=0)
			{
				k=0;
				while (!(aroudpix[j]>PIXElTABEL[k].min &&aroudpix[j]<=PIXElTABEL[k].max)){k++;}
				int temp=abs(PIXElTABEL[ik].pixel_value-PIXElTABEL[k].pixel_value);
				if (temp>max_around)
				{
					max_around=temp;
				}
			}
		}
		markpixel tempmp;
		tempmp.pos=*it;
		tempmp.maxvalue=max_around;
		MARKPIXELS.push_back(tempmp);
	}

	/////////////////////对特殊标记像素的结果集合，进行排列，合并，输出
	sort(MARKPIXELS.begin(),MARKPIXELS.end(),comp); 
	
	int t;
	int recordlast=MARKPIXELS[0].pos;
	cout<<width<<endl;
	for (t=0;t<MARKPIXELS.size()-1;t++)
	{
		if (MARKPIXELS[t].maxvalue!=MARKPIXELS[t+1].maxvalue)
		{
			cout<<MARKPIXELS[t].maxvalue<<" "<<MARKPIXELS[t+1].pos-recordlast<<endl;
			recordlast=MARKPIXELS[t+1].pos;
		}
	}
	cout<<MARKPIXELS[t].maxvalue<<" "<<sum-recordlast+1<<endl;
	cout<<"0"<<" "<<"0"<<endl;

}//大while结束

	cout<<"0";
	return 0;
}
