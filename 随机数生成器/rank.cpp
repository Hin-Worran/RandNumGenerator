#include "��ͷ.h"
void rankG(int *r,int t)	//�����������������
{
	for (int i = 0; i < t; i++)
	{
		for(int j=0;j<t-i-1;j++)
		{
			if (r[j] > r[j + 1])swap(r[j], r[j + 1]);
		}
	}
}

void swap(int&a, int&b)
{
	int t = a;
	a = b;
	b = t;
}
