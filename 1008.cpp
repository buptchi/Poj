//很简单，模除的时候，从0 开始，边界出现问题
//cin 输入格式注意


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string haab_mouth_name[19]={ "pop", "no", "zip","zotz", "tzec", "xul", "yoxkin", "mol",
									"chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
string tzo_day_name[20]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", 
									"ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"  };

int str2mouth(string str)
{
	int i;
	for (i=0;i<19;i++)
	{
		if (haab_mouth_name[i]==str)
		{
			return i;
		}
	}
}

int  main1008()
{
	int lines;
	int day_int;
	int year;
	string mouth_str;
	char doc;
	int toteldays;

	cin>>lines;
	cout<<lines<<endl;
	while (lines--)
	{
		cin>>day_int>>doc>>mouth_str>>year;
		toteldays=year*365+20*str2mouth(mouth_str)+day_int;			//从第0天开始
		cout<< toteldays%13+1<<' '<<tzo_day_name[toteldays%20]  <<' '<<  toteldays/260<<endl;
	}
	return 0;
}