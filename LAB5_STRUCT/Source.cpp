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
	int DURATION_IN_MINUTES = 0;
};
//Upload information about all tickets sold and display.
void SHOW_ALL_TICKETS(int n, SOLD_AIR_TICKET* ARRAY);
//Find out on which flights passengers bought tickets by the name of Sidorov.
void SEARCH_SURNAME(int n, SOLD_AIR_TICKET* ARRAY);
/*Display information on all tickets for flights lasting more than three hours.
Data must be sorted by passenger's last name.*/
void SORT_N_MINUTES(int n, SOLD_AIR_TICKET* ARRAY);

bool cmpByAuthor(const SOLD_AIR_TICKET& r1, const SOLD_AIR_TICKET& r2) //сравнение по фамилии автора
{
	return r1.SNP < r2.SNP;
}

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
	cout << "1. Upload information about all tickets sold and display.\n"
		 << "2. Find out on which flights passengers bought tickets by the name of Sidorov.\n"
		 << "3. Display information on all tickets for flights lasting more than three hours.\n"
		 << "Data must be sorted by passenger's last name\n"
		 <<">>>";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		SHOW_ALL_TICKETS(n, ARRAY);
		break;
	case 2:
		//Find out on which flights passengers bought tickets by the name of Sidorov.
		SEARCH_SURNAME(n, ARRAY);
	case 3:
		/*Display information on all tickets for flights lasting more than three hours.
		Data must be sorted by passenger's last name.*/
		SORT_N_MINUTES(n, ARRAY);
	default:
		break;
	}
	
	
	return 0;
}

void SHOW_ALL_TICKETS(int n, SOLD_AIR_TICKET* ARRAY)
{
	{
		cout << "Flight number/Initials Of The Passenger/Destination/Duration In Minutes:\n\n";
		for (size_t i = 0; i < n; i++)
		{
			cout << " " << ARRAY[i].FLICHT_NUMBER 
				 << " "
				 << ARRAY[i].SNP
				 << " "
				 << ARRAY[i].DESTINATION
				 << " "
				 << ARRAY[i].DURATION_IN_MINUTES;
			cout << "\n\n";
		}
	}
}

void SEARCH_SURNAME(int n, SOLD_AIR_TICKET* ARRAY)
{
	for (size_t i = 0; i < n; i++)
	{
		if (!(ARRAY[i].SNP.find("SIDOROV")))
		{
			cout << " " << ARRAY[i].FLICHT_NUMBER 
				 << " "
				 << ARRAY[i].SNP
				 << " "
				 << ARRAY[i].DESTINATION
				 << " "
				 << ARRAY[i].DURATION_IN_MINUTES;
			cout << "\n\n";
		}
	}
}
void SORT_N_MINUTES(int n, SOLD_AIR_TICKET* ARRAY)
{	
	
	sort(ARRAY, ARRAY + n, cmpByAuthor);
	for (size_t i = 0; i < n; i++)
	{
		if (ARRAY[i].DURATION_IN_MINUTES > 180)
		{
			cout << " " << ARRAY[i].FLICHT_NUMBER
				 << " "
				 << ARRAY[i].SNP
				 << " "
				 << ARRAY[i].DESTINATION;
			cout << "\n\n";
		}
	}
}
