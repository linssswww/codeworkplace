#include<vector>
using namespace std;
void InsertSort(int val[], int size) 
{
	int key = 0;
	for (int i = 1; i < size ; i++) 
	{
		key = i;
		//��key��ǰһ�����鴮��������
		//sort()
		
		
	}
}
//˳������
void sort(int val[], int key) {
	int value = val[key];
	//���ֱ�־λ
	int sign = 0;
	for (int i = 0;i < key;i++) {
		if (value < val[i]) {
			
			sign = i;
			break;
		}
	}

	
	int tmp = 0;
	for (int i = key; i > sign;i--) {
		val[i] = val[i-1];
	}
	val[sign] = value;
	//������һ��


}

void main() 
{
	int val[] = {1,3,6,10,5};
	sort(val, 4);
	for (int i = 0;i < 5;i++) {
		printf(" %d", val[i]);
	}
	getchar();
}