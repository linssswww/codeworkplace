#include<vector>
using namespace std;
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
//˳������

void sort(int val[], int key);
void InsertSort(int val[], int size);
void main() 
{
	int val[] = {1,5,6,10,2,100,9,20,21,15};

	int size = 10;
	InsertSort(val, size);

	for (int i = 0; i < size; i++)
	{
		printf(" %d", val[i]);
	}
	getchar();
}