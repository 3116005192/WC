#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
void WC_count(int[], char);
extern bool flag = true;

int main()
{
	fstream iofile;                        //流
	int file_count = --argc;               //减去程序本身的名称
	int arg_index = 1;
	int current[3];                        //current:单个文件的计数.
	int total[3];                          //total:所有文件的总计. 
	//[0]:字符数数目, [1]:单词的数目, [2]:行的数目;
	int array[3]{ 0, 0, 0 };
	char c;
	return 0;
}

void WC_counter(int, char)     //计数操作
{
	bool flag;
	count[0]++;
	if (c == '\n') count[2]++;
	if (c == '\t' || c == ' ' || c == '\n')
	{
		if (flag == false)
		{
			count[1]++;
			flag = true;
		}
	}
	else flag = false;
}