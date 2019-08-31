#include <iostream>
using namespace std;
//使用范围for，通过输入为一个数组赋值
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