// 21.09.18.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<fstream>
#include<bitset>
#include<iomanip>
using namespace std;
ifstream my_file;
//bool flag;
union example
{
	int a;
	char c[4];
};

union example1
{
	int a;
	unsigned int b;
};

union example2
{
	int a;
	bool b[4];
};
struct car
{
	string color;
	string model;
	bool flag;

	union
	{
		int numeric;
		char string_num[9];
	}car_number;


	void enter()
	{
		//cout << "Enter color and model for car" << endl;
		my_file >> color >> model;
		//cout << "Enter 1 to choose numeric number, 0 - to choose string number." << endl;
		my_file >> flag;
		if (flag == 0)
			my_file >> car_number.string_num;
		else
			my_file >> car_number.numeric;
	}
	void enter1()
	{
		cout << "Enter color and model for car" << endl;
		cin >> color >> model;
		cout << "Enter 1 to choose numeric number, 0 - to choose string number." << endl;
		cin >> flag;
		if (flag == 0)
			cin >> car_number.string_num;
		else
			cin >> car_number.numeric;
	}

	void print()
	{
		cout << setw(10) << color << setw(10) << model;
		if (flag == 0)
			cout << setw(10) << car_number.string_num << endl;
		else
			cout << setw(10) << car_number.numeric << endl;
	}

};
void edit(car* a)
{
	car x;

	string poisk;
	bool flag;
	int poisk1;

	cout << "Enter 1 to choose numeric number, 0 - to choose string number: ";
	cin >> flag;
	cout << "Enter car number for edit: ";
	if (flag == 0)
		cin >> poisk;
	else
		cin >> poisk1;
	if (flag == 0)
		for (int i = 0; i < 10; i++)
		{
			if (a[i].car_number.string_num == poisk)
			{
				cout << "Enter new inf: " << endl;
				a[i].enter1();
				break;
			}
		}
	else
		for (int i = 0; i < 10; i++)
		{
			if (a[i].car_number.numeric == poisk1)
			{
				cout << "Enter new inf: " << endl;
				a[i].enter1();
				break;
			}
		}


}
int main()
{
	setlocale(LC_ALL, "Rus");
	my_file.open("in.txt", ios::in);
	int t;
	my_file >> t;

	car* c;
	c = new car[10];
	cout << left << setw(10) << "Color" << left << setw(10) << "Model" << left << setw(10) << "Car number" << endl;
	for (int i = 0; i < 10; i++)
	{
		c[i].enter();
		c[i].print();
	}
	cout << endl;
	while (true)
	{
		edit(c);
		cout << left << setw(10) << "Color" << left << setw(10) << "Model" << left << setw(10) << "Car number" << endl;
		for (int i = 0; i < 10; i++)
		{
			c[i].print();
		}
		cout << endl;
		cout << "Enter additional changes ( 1 - yes, 0 - no): ";
		int n;
		cin >> n;
		if (n == 0)break;

	}
	delete[] c;

	/*example2 e2;
	int sum = 0;
	cin >> e2.a;
	for (int i = 0; i < 4; i++)
	{
		if (e2.b[i] == 0) sum++;
	}
	cout << sum << endl;*/
	/*example1 e1;
	cin >> e1.a >> e1.b;
	cout << e1.a << endl<< e1.b << endl;
*/

/*example e;
cin >> e.a;
cout << hex<<int(e.c[0])<< endl;
cout << bitset<8>(e.c[1]) << endl;
cout << bitset<8>(e.c[2]) << endl;
cout << bitset<8>(e.c[3]) << endl;*/
	system("pause");
	return 0;
}

