#include <iostream>
#include <vector>
#include <fstream>
#include<Windows.h>
#include <map>
#include <ctime>
using namespace std;

void Task1()
{
	double start = clock(); 
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
				double duration = (clock() - start) / (double)CLOCKS_PER_SEC;
				cout << duration << '\n';
				return;
			}
		}
}

void Task1_new()
{
	double start = clock();
	ifstream file("Input task1.txt");
	if (file.fail())
	{
		cout << "Ошибка при работе с файлом" << endl;
		return;
	}
	int i, j = 0;
	vector<int> obj;
	map<int, int> num;
	while (file >> i)
	{
		obj.push_back(i);
		num.emplace(i, j);
		j++;
	}
	for (int i = 0; obj.size(); i++)
	{
		int search = 2023 - obj[i];
		if (num.find(search) != num.end())
		{
			cout << obj[i] << " " << search << endl;
			double duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			cout << duration << '\n';
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
	int fst = 0, scnd = 0;
	while (fst != first.size() && scnd != second.size())
	{
		if (first[fst] > second[scnd])
		{
			common.push_back(second[scnd]);
			scnd++;
		}
		else
		{
			common.push_back(first[fst]);
			fst++;
		}
	}
	if (fst == first.size())
	{
		while (scnd != second.size())
		{
			common.push_back(second[scnd]);
			scnd++;
		}
	}
	else if (scnd == second.size())
	{

		while (fst != first.size())
		{
			common.push_back(first[fst]);
			fst++;
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
	Task1_new();
	cout << "Задание 2:" << endl;
	Task2();
}