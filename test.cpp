#include <iostream>
using namespace std;
//ʹ�÷�Χfor��ͨ������Ϊһ�����鸳ֵ
int test1()
{
	int arr[5];
	for (auto &i: arr)
	{
		cin >> i;
	}
	for (auto i : arr)
	{
		cout << i << endl;
	}
	return 0;
}