#include <iostream>
#include <fstream>
using namespace std;
//some struct
struct SOLD_AIR_TICKET
{
	int FLICHT_NUMBER;
	char* SNP = new char[60];
	char* DESTINATION = new char[40];
	int FLIGHT_DURATION_IN_MINUTES;
	int NUMBER_STRING;
};
//some functions
SOLD_AIR_TICKET NUMBER_OF_LINES()// count the lines in a file
{
	SOLD_AIR_TICKET FILE_L;
	char* str = new char[75];
	FILE_L.NUMBER_STRING = 0;
	ifstream count("D:\\who\\tickets_info.txt");
	while (!count.eof())
	{
		count.getline(str, 75, '\n');
		FILE_L.NUMBER_STRING++;
	}
	count.close();
	delete []str;
	return FILE_L;
}

SOLD_AIR_TICKET LOAD_ALL_INFORMATION()
{
	SOLD_AIR_TICKET FILE;
	char* str = new char[75];
	FILE.NUMBER_STRING = 0;
	ifstream lines("D:\\who\\tickets_info.txt");
	/*
	for (size_t i = 0; i < length; i++)
	{
		
	}
	*/
	lines.close();
	delete[]str;
	return FILE;
}
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
	SOLD_AIR_TICKET lines_number = NUMBER_OF_LINES();
	return 0;
}