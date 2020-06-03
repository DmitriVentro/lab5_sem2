#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
struct SOLD_AIR_TICKET
{
	
	string FLICHT_NUMBER = " "; 
	string SNP = " ";
	string DESTINATION = " ";
	string DURATION_IN_MINUTES = " ";
};
void SHOW_ALL_TICKETS(int n, SOLD_AIR_TICKET* ARRAY);//show all tickets in your file
int main()
{
	setlocale(LC_ALL, " ");
	string x;
	SOLD_AIR_TICKET PART;
	ifstream fin;
	fin.open("D:\\who\\tickets_info.txt");
	int n(0);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			string s;
			getline(fin, s);
			n++;
		}
	}
	SOLD_AIR_TICKET* ARRAY = new SOLD_AIR_TICKET[n];
	fin.seekg(0, ios_base::beg);
	for (size_t i = 0; i < n; i++) 
	{
		getline(fin, x);
		istringstream iss(x);
		iss >> PART.FLICHT_NUMBER >> PART.SNP >> PART.DESTINATION >> PART.DURATION_IN_MINUTES;
		ARRAY[i] = PART;
	}

	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		SHOW_ALL_TICKETS(n, ARRAY);
		break;
	case 2:
		cout << "suck:)";
	default:
		break;
	}
	
	
	return 0;
}

void SHOW_ALL_TICKETS(int n, SOLD_AIR_TICKET* ARRAY)
{
	{
		cout << "Flight number/Initials Of The Passenger/Destination/Duration In Minutes\n\n";
		for (size_t i = 0; i < n; i++)
		{
			cout << " " << ARRAY[i].FLICHT_NUMBER << " "
				 << ARRAY[i].SNP << " "
				 << ARRAY[i].DESTINATION << " "
				 << ARRAY[i].DURATION_IN_MINUTES;
			cout << "\n\n";
		}
	}
}
