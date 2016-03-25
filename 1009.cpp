//����һ�죬
//�տ�ʼ��֪���������У�����ô����������ǰ���һ�������ó�����һ���㣬����ɹ��ˣ���ֻ����������С�Ĳ������ݣ�
//�������������ϵ�˼·����������иĽ����ɹ��ˡ�
//�ύʱ�������⣬�Һúܿ���ҵ��ٶ��Ŀ���һƪ���ϣ�˵���һ��Ҫ���б߽紦�����������accepted
//����ĵط������ڣ��ռ䷽��û�н�����ϸʹ�ã������������ʼ���ȱȽ��ҡ�


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
};									//��׼�����һ�У�����ֵ���������ĸ���
struct  markpixel
{
	int pos;
	int maxvalue;
};									//�������  ���ص�λ�ã��Լ�������ֵ

int aroudpix[8];

bool comp(markpixel mp1,markpixel mp2)
{
	return mp1.pos < mp2.pos;
}									//�Ա�ǵ����ص����򣬰�λ����������

void getAroudpix(int pos,int width,int sum)				//�õ�һ������Χ�İ˸��㣬�Բ��ϸ�ĵ�����
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
	vector<samepixel> PIXElTABEL;						//���������������Ϣ
	vector<markpixel> MARKPIXELS;					//���� ������ص� ���
	list<int> markpos;												//������ص�λ��
	int max_around;

	int width;
	samepixel sp;
	int sum;
	int samenum;

	int j;				//ĳ����Χ������
	int k;			//���ĸ���ͬ���ص�������
	int ik;			//�������ص�����

	//////////////////////��ȡ���룬����PIXELTABAL
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

	///////////////////��ÿ���������صĵ���б�ǣ��Լ���Χ��8������
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

	//////////////////////////����������������һ�е���ͷ����βҲҪ���б�ǣ�����Ȼ���ܻ��������
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

	////////////////////////////////////��ÿһ����ǵ����ؽ�����ֵ
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

	/////////////////////�����������صĽ�����ϣ��������У��ϲ������
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

}//��while����

	cout<<"0";
	return 0;
}
