//生成随机数的小工具
//V1.0：未完成功能——不知如何找重复
//V2.0：完成找重复功能，下一步：增加排序功能。（2020/10/5 23:20）
//V2.1：排序未完成，定义了个函数，但不work。	（2020/10/22/14:01）
//V3.0：排序功能完成！！！问题出在sizeof(指针)上。	（2020/10/24/9:46）
//V3.1：修复了一些bug....	（2020/10/24/9:58）
#include<iostream>
#include<cstdlib>
#include<ctime>
#include"标头.h"
using namespace std;
int main()
{
	unsigned seed;
	seed=time(0);
	srand(seed);
	int Max=7, Min=3,Times;
	char Rep='Y';
	cout << "请输入随机数的最小值" << endl;	//输入值的范围
	cin >> Min;
	cout << "请输入随机数的最大值" << endl;	
	cin >> Max;
	cout << "需要几个随机数" << endl;
	cin >> Times;
	cout << "是否重复(Y/N)" << endl;	//选择是否要重复的随机数
	cin >> Rep;
	int *Gets=new(int[Times]);
	//是否重复的实现
	if (Rep=='Y' or Rep=='y')
	{
		for (int i = 0; i < Times; i++)
		{
			Gets[i] = rand() % (Max - Min + 1) + Min;	//获取随机数
			//cout << Get << " ";	//输出
		}
	}
	else if (Rep=='N' or Rep=='n')
	{
		if (Times <= (Max - Min + 1))
		{
			bool repeted = false;
			do
			{
				repeted = false;
				for (int i = 0; i < Times; i++)
				{
					Gets[i] = rand() % (Max - Min + 1) + Min;	//获取随机数
				}
				for (int i = 0; i < Times; i++)
				{
					if (repeted == true)break;
					for (int j = i + 1; j < Times; j++)
					{
						if (Gets[i] == Gets[j])
						{
							repeted = true;
							break;
						}
					}
				}
			} while (repeted);
			}
		else
		{
			cout << "随机数多于总数啦" << endl;
		}
	}
	else
	{
		cout << "格式错误，请输入Y/N" << endl;
	}
	//是否排序的实现
	cout << "是否排序？(Y/N)" << endl;
	char rankif;
	cin >> rankif;
	if (rankif == 'Y' || rankif == 'y')rankG(Gets, Times);
	//输出
	cout << "得到的随机数为：" << endl;
	for (int i = 0; i < Times; i++)
		cout << Gets[i] << " ";	
	delete[]Gets;
	Gets = NULL;
	system("pause");

	return 0;	
}