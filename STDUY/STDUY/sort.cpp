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
	int i = s_index, j = mid + 1, k = 0;

	while (i <= mid && j <= e_index)
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
		for(int index = j; index <= e_index ; index++)
		{
			c[k] = varray[index];
			k++;
		}
	}
	int ii = s_index;
	for each ( int re in c)
	{
		printf(" %d", re);
		varray[ii] = re;
		ii++;
	}
}
//分治排序
void mergesort(int varray[], int s_index, int e_index) 
{
	//排序对前后串进行排序算法
	int mid = 0;
	if (s_index < e_index) {
		mid = (s_index + e_index) / 2;
	}
	else
		return;

	mergesort(varray, s_index, mid);
	mergesort(varray, mid + 1, e_index);

	//对两个子串排序完之后，合并两个子串
	merge(varray, s_index, e_index, mid);
}

void sort(int val[], int key);
void InsertSort(int val[], int size);
void main() 
{
	int val[] = {1,5,16,6,30,40,22,44,33};

	//int size = 10;
	//InsertSort(val, size);

	//for (int i = 0; i < size; i++)
	//{
	//	printf(" %d", val[i]);
	//}
	//merge(val, 1, 3, 2);
	mergesort(val, 0, 8);

	cout << "end:" << endl;


	for (int i = 0; i < 9; i++) {
		cout << " " << val[i];
	}

	getchar();
}