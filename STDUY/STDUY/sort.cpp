#include<vector>
#include<istream>
#include<stdio.h>
#include<iostream>
using namespace std;
//˳������
void sort(int val[], int key) {
	int value = val[key];
	//���ֱ�־λ
	int sign = 0;
	bool isfind = false;
	for (int i = 0;i < key;i++) {
		if (value < val[i]) {

			sign = i;
			isfind = true;
			break;
		}
	}

	if (isfind) {
		int tmp = 0;
		for (int i = key; i > sign;i--) {
			val[i] = val[i - 1];
		}
		val[sign] = value;
		//������һ��
	}
}
void InsertSort(int val[], int size) 
{
	int key = 0;
	for (int i = 1; i < size ; i++) 
	{
		//��key��ǰһ�����鴮��������
		sort(val, i);
	}
}
//����˳���Ӵ��ϲ�����, 0 ~ mid mid~e_index
void merge(int varray[], int s_index, int e_index, int mid)
{
	int size = e_index - s_index + 1;
	vector<int> c(size);
	int i = 0, j = mid + 1, k = 0;
	while (i < mid && j < e_index)
	{
		if (varray[i] > varray[j]) 
		{
			c[k] = varray[j];
			j++;
		}
		else
		{
			c[k] = varray[i];
			i++;
		}
		k++;
	}
	if (i <= mid)
	{
		for (int index = i; index <= mid;index++) {
			c[k] = varray[index];
			k++;
		}
	}
	if (j <= e_index) 
	{
		for(int index = j; index <=e_index ; index++)
		{
			c[k] = varray[index];
			k++;
		}
	}
	int ii = 0;
	for each ( int re in c)
	{
		printf(" %d", re);
		varray[ii] = re;
		ii++;
	}
}
//��������
void mergesort(int varray[], int s_index, int e_index,int size) 
{
	//�����ǰ�󴮽��������㷨
	int mid = size / 2;
	if (mid == 0)
		return;
	mergesort(varray, s_index, mid, mid - s_index + 1);
	mergesort(varray, mid + 1, e_index, e_index - (mid + 1) + 1);

	//�������Ӵ�������֮�󣬺ϲ������Ӵ�
	merge(varray, s_index, e_index, mid);
}

void sort(int val[], int key);
void InsertSort(int val[], int size);
void main() 
{
	int val[] = {1,5,6,10,15,2,7,16,30,40};

	//int size = 10;
	//InsertSort(val, size);

	//for (int i = 0; i < size; i++)
	//{
	//	printf(" %d", val[i]);
	//}
	//merge(val, 0, 9, 4);
	mergesort(val, 0, 9, 10);

	cout << "end:" << endl;


	for (int i = 0; i < 10; i++) {
		cout << " " << val[i];
	}

	getchar();
}