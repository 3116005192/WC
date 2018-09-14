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
	std::ifstream file_stream;                    //文件流
	char* ch;
	int lines = 1;
	for (c -= 1; c > 1; c--)
	{
		file_stream.open(v[c], std::ios::in);
		file_stream.read(ch, 1);
		if (*ch == '\n') lines++;
		file_stream.close();
	}
	std::cout << "The amount of line: " << lines << std::endl;
}

void Word_Count_Out(int c, char* v[])            //计算单词数并输出
{
	std::ifstream file_stream;
	char* ch;
	int words = 0;
	bool flag = false;
	for (c -= 1; c > 1; c--)
	{
		file_stream.open(v[c], std::ios::in);
		file_stream.read(ch, 1);
		if (*ch > 'A' && *ch < 'Z' || *ch > 'a' && *ch < 'z')
		{
			if (flag == false)
			{
				words++;
				flag = true;
			}
		}
		else flag = false;
		file_stream.close();
	}
	std::cout << "The amount of word: " << words << std::endl;
}

void Char_Count_Out(int c, char* v[])            //计算字符数并输出
{
	std::ifstream file_stream;
	char* ch;
	int chars = 0;
	for (c -= 1; c > 1; c--)
	{
		file_stream.open(v[c], std::ios::in);
		file_stream.read(ch, 1);
		if (*ch) chars++;
		file_stream.close();
	}
	std::cout << "The amount of char: " << chars << std::endl;
}