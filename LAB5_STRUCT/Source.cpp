#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
//some struct
struct SOLD_AIR_TICKET
{
	int FLICHT_NUMBER;
	char* SNP = new char[60];
	char* DESTINATION = new char[40];
	int FLIGHT_DURATION_IN_MINUTES;
};
//some functions

/*
SOLD_AIR_TICKET SEARCH_BY_SURNAME()
{

}
SOLD_AIR_TICKET LOAD_INFORMATION_LAST_THREE_HOURS()
{

}
*/
int main()
{
	setlocale(LC_ALL, "Russian");
	string x;
	SOLD_AIR_TICKET s;
	ifstream fin;
	fin.open("D:\\who\\books.txt");
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
		iss >> s.number >> s.surname >> s.price;
		a[i] = s;
	}
	return 0;
}