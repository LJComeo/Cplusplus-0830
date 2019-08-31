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
д���������ú������صķ�ʽ��д����ͳ�Ƴ�һ���������ṹΪ��׼�Ľṹ�������У�
1������ΪX�ĳ����˶��ٴ�
2������ΪX�ĳ����˶��ٴ�
3���༶ΪX�ĳ����˶��ٴ�
4���Ա��X�ĳ����˶��ٴ�
���磺����ΪX�Ŀ�����������������
int countName(student * src, int n, char * name);
tip:���Կ�����ȱʡ�����ķ�ʽ�����߻ص������ķ�ʽʵ�֡�
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