#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

struct student{
char name[32];
int age;
int classnid;
bool sex;
};
/*
写出函数，用函数重载的方式编写程序，统计出一个以上述结构为基准的结构体数组中：
1、名字为X的出现了多少次
2、年龄为X的出现了多少次
3、班级为X的出现了多少次
4、性别的X的出现了多少次
例如：名字为X的可以是这样的声明：
int countName(student * src, int n, char * name);
tip:可以考虑用缺省参数的方式，或者回调函数的方式实现。
*/

bool cmpEql(student a, student b)
{
	return a.age == b.age;
}

bool cmpEqlname(student a, student b)
{
	return strcmp(a.name, b.name) ? false : true;
}

bool cmpEqlsex(student a, student b)
{
	return !(a.sex ^ b.sex);
}
int countS(student *st, int n,student value,bool(*cmp)(student,student)=cmpEql)
{
	int i;
	int count = 0;
	for (i = 0; i < n; i++)
	{
		if (cmp(st[i], value))
		{
			count++;
		}
	}
	return count;
}
int test2()
{
	student st[] = { { "caixikun", 18, 1, true },
					{ "qiaobiluo", 18, 1, false },
					{ "wuyifan", 20, 2, false },
					{ "luhan", 22, 2, true },
					{ "lubenwei", 22, 2, true },
					{ "yangchaoyue", 20, 1, false },
					{ "caixikun", 18, 1, true } 
	};
		

	student test = { "caixikun", 18, 1, true };
	cout << countS(st, 7, test, cmpEqlname) << endl;
	return 0;
}