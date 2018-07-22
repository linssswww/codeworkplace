#include<vector>
#include<istream>
#include<stdio.h>
#include<iostream>
using namespace std;
//顺序排序
void sort(int val[], int key) {
	int value = val[key];
	//发现标志位
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
		//往后退一格
	}
}
void InsertSort(int val[], int size) 
{
	int key = 0;
	for (int i = 1; i < size ; i++) 
	{
		//对key的前一个数组串进行排序
		sort(val, i);
	}
}
//两个顺序子串合并排序, 0 ~ mid mid~e_index
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
//分治排序
void mergesort(int varray[], int s_index, int e_index,int size) 
{
	//排序对前后串进行排序算法
	int mid = size / 2;
	if (mid == 0)
		return;
	mergesort(varray, s_index, mid, mid - s_index + 1);
	mergesort(varray, mid + 1, e_index, e_index - (mid + 1) + 1);

	//对两个子串排序完之后，合并两个子串
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