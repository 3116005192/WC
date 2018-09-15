#include<iostream>
#include<cstring>
#include<fstream>
void Line_Count_Out(int, char*[]);
void Word_Count_Out(int, char*[]);
void Char_Count_Out(int, char*[]);
void Function(char, int []);

int main(int argc, char* argv[])
{
	char function_set[10];
	char file_name[30];
	std::ifstream file_stream;
	char *ch = new char[100];
	int i = 0;
	bool flag = false;
	int count[3]{ 0, 0, 1 };       //count[0]:字节数, count[1]:单词数, count[2]:行数
	
	std::cout << "Please enter your file_path: ";
	std::cin >> function_set;
	std::cin >> file_name;
	file_stream.open(file_name, std::ios::in);
	
	if (!file_stream)
		std::cout << "\nError.\n";
	std::cout << "\nThe info of the file:\n";
	do
	{
		file_stream.read(ch, 1);
		std::cout << *ch;

		if (*ch == '\n')
			count[2]++;

		if (*ch > 'A' && *ch < 'Z' || *ch > 'a' && *ch < 'z')
		{
			if (flag == false)
			{
				count[1]++;
				flag = true;
			}
		}
		else flag = false;
  
		count[0]++;

	} while (!file_stream.eof());   
	
	std::cout << std::endl << std::endl;
	Function(function_set[1], count);

	if (argc == 1)
		std::cout << "\nNot found the count_function.\n";
	if (argc == 2)            //无文件名称
		std::cout << "\nNot found the file_name.\n";
	if (argc > 2)
	{
		if (argv[1][1] == 'l')
			Line_Count_Out(argc, argv);
		if (argv[1][1] == 'w')
			Word_Count_Out(argc, argv);
		if (argv[1][1] == 'c')
			Char_Count_Out(argc, argv);
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}

void Function(char ch, int count[])
{
	if (ch == 'c')
		std::cout << "The amount of the char: " << count[0] << std::endl;
	else if (ch == 'l')
		std::cout << "The amount of the line: " << count[2] << std::endl;
	else if (ch == 'w')
		std::cout << "The amount of the word: " << count[1] << std::endl;
	else
	{
		std::cout << "The amount of the char: " << count[0] << std::endl;
		std::cout << "The amount of the line: " << count[2] << std::endl;
		std::cout << "The amount of the word: " << count[1] << std::endl;
	}
}
void Line_Count_Out(int c, char* v[])            //计算行数并输出
{
	std::ifstream file_stream;                   //文件流
	char* ch = NULL;                             //read函数中的参数需要赋值
	int lines = 1;
	for (c -= 1; c > 1; c--)
	{
		file_stream.open(v[c], std::ios::in);    //打开文件
		do
		{
			file_stream.read(ch, 1);             //以字符数组读取每一个字符,每循环一次,指针向下一个字符地址移动一次
			if (*ch == '\n') lines++;
		} while (ch == NULL);
		file_stream.close();                     //关闭文件
	}
	std::cout << std::endl << "The amount of line: " << lines << std::endl;
}

void Word_Count_Out(int c, char* v[])            //计算单词数并输出
{
	std::ifstream file_stream;
	char* ch = NULL;
	int words = 0;
	bool flag = false;
	for (c -= 1; c > 1; c--)
	{
		file_stream.open(v[c], std::ios::in);
		do
		{
			file_stream.read(ch, 1);

			//当字符串中含有的一个字符为字母时,flag = true, 反之, flag = false, 每次由false变为true时, words加一.

			if (*ch > 'A' && *ch < 'Z' || *ch > 'a' && *ch < 'z')
			{
				if (flag == false)
				{
					words++;
					flag = true;
				}
			}
			else flag = false;
		} while (ch == NULL);
		file_stream.close();
	}
	std::cout << std::endl << "The amount of word: " << words << std::endl;
}

void Char_Count_Out(int c, char* v[])            //计算字符数并输出
{
	std::ifstream file_stream;
	char* ch = NULL;
	int chars = 0;
	for (c -= 1; c > 1; c--)
	{
		file_stream.open(v[c], std::ios::in);
		do
		{
			file_stream.read(ch, 1);
			if (ch != NULL) chars++;
			file_stream.close();
		} while (ch == NULL);
	}
	std::cout << std::endl << "The amount of char: " << chars << std::endl;
}
