//�����������С����
//V1.0��δ��ɹ��ܡ�����֪������ظ�
//V2.0��������ظ����ܣ���һ�������������ܡ���2020/10/5 23:20��
//V2.1������δ��ɣ������˸�����������work��	��2020/10/22/14:01��
//V3.0����������ɣ������������sizeof(ָ��)�ϡ�	��2020/10/24/9:46��
//V3.1���޸���һЩbug....	��2020/10/24/9:58��
#include<iostream>
#include<cstdlib>
#include<ctime>
#include"��ͷ.h"
using namespace std;
int main()
{
	unsigned seed;
	seed=time(0);
	srand(seed);
	int Max=7, Min=3,Times;
	char Rep='Y';
	cout << "���������������Сֵ" << endl;	//����ֵ�ķ�Χ
	cin >> Min;
	cout << "����������������ֵ" << endl;	
	cin >> Max;
	cout << "��Ҫ���������" << endl;
	cin >> Times;
	cout << "�Ƿ��ظ�(Y/N)" << endl;	//ѡ���Ƿ�Ҫ�ظ��������
	cin >> Rep;
	int *Gets=new(int[Times]);
	//�Ƿ��ظ���ʵ��
	if (Rep=='Y' or Rep=='y')
	{
		for (int i = 0; i < Times; i++)
		{
			Gets[i] = rand() % (Max - Min + 1) + Min;	//��ȡ�����
			//cout << Get << " ";	//���
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
					Gets[i] = rand() % (Max - Min + 1) + Min;	//��ȡ�����
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
			cout << "���������������" << endl;
		}
	}
	else
	{
		cout << "��ʽ����������Y/N" << endl;
	}
	//�Ƿ������ʵ��
	cout << "�Ƿ�����(Y/N)" << endl;
	char rankif;
	cin >> rankif;
	if (rankif == 'Y' || rankif == 'y')rankG(Gets, Times);
	//���
	cout << "�õ��������Ϊ��" << endl;
	for (int i = 0; i < Times; i++)
		cout << Gets[i] << " ";	
	delete[]Gets;
	Gets = NULL;
	system("pause");

	return 0;	
}