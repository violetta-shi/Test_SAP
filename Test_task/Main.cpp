#include <iostream>
#include <vector>
#include <fstream>
#include<Windows.h>
using namespace std;

void Task1()
{
	ifstream file("Input task1.txt");
	if (file.fail())
	{
		cout << "Ошибка при работе с файлом" << endl;
		return;
	}
	int i;
	vector<int> obj;
	while (file >> i)
		obj.push_back(i);
	for(int i = 0; i < obj.size(); i++)
		for (int j = i + 1; j < obj.size(); j++)
		{
			if (obj[i] + obj[j] == 2023)
			{
				cout << obj[i]<<endl << obj[j]<<endl;
				file.close();
				return;
			}
		}
}

void showArray(vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;
}

void Task2() 
{
	vector<int> first = { 1,1,3,7,9 };
	vector <int> ::iterator it_f = first.begin();
	showArray(first);
	vector<int> second = { 1,4,12,12,76 };
	vector <int> ::iterator it_s = second.begin();
	showArray(second);
	vector<int> common;
	while (it_f != first.end() && it_s != second.end())
	{
		if (*it_f > *it_s)
		{
			common.push_back(*it_s);
			it_s++;
		}
		else
		{
			common.push_back(*it_f);
			it_f++;
		}
	}
	if (it_f == first.end())
	{
		while (it_s != second.end()) 
		{
			common.push_back(*it_s);
			it_s++;
		}
	}
	else if (it_s != second.end())
	{
		
		while (it_f != first.end())
		{
			common.push_back(*it_f);
			it_f++;
		}
	}
	showArray(common);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Задание 1:" << endl;
	Task1();
	cout << "Задание 2:" << endl;
	Task2();
}