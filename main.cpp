#include<iostream>
#include<cstring>
#include<fstream>
void Line_Count_Out(int, char*[]);
void Word_Count_Out(int, char*[]);
void Char_Count_Out(int, char*[]);

int main(int argc, char* argv[])
{
	if (argc == 1 || argc == 2)            //无文件名称
		std::cout << "Not found the file_name";
	if (argc > 3)
	{
		if (argv[1] == "l")
			Line_Count_Out(argc, argv);
		if (argv[1] == "w")
			Word_Count_Out(argc, argv);
		if (argv[1] == "c")
			Char_Count_Out(argc, argv);
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}

void Line_Count_Out(int c, char* v[])            //计算行数并输出
{
}

void Word_Count_Out(int c, char* v[])            //计算单词数并输出
{
}

void Char_Count_Out(int c, char* v[])            //计算字符数并输出
{
}
