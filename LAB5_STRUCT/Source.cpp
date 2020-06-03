#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
//some struct
struct SOLD_AIR_TICKET
{
	
	string FLICHT_NUMBER = " "; 
	string SNP = " ";
	string DESTINATION = " ";
};
int main()
{
	setlocale(LC_ALL, " ");
	string x;
	SOLD_AIR_TICKET s;
	ifstream fin;
	fin.open("D:\\who\\tickets_info.txt");
	int n(0);
	if (fin.is_open())
	{
		while (!fin.eof()) //узнаем, сколько книг всего
		{
			string s;
			getline(fin, s);
			n++;
		}
	}
	SOLD_AIR_TICKET* a = new SOLD_AIR_TICKET[n];
	fin.seekg(0, ios_base::beg);
	for (size_t i = 0; i < n; i++) //заносим данные в массив
	{
		getline(fin, x);
		istringstream iss(x);
		iss >> s.FLICHT_NUMBER >> s.SNP >> s.DESTINATION;
		a[i] = s;
	}
	for (size_t i = 0; i < n; i++)
	{
		cout << 
	}
	return 0;
}