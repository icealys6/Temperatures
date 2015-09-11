//the program compiled but im getting runtime errors, I can't get the first line of the file//
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;


int numofcities = 0;
int numofmonths = 0;
std::vector<std::string> v = { "January", "February","March","April","May","June","July","August","September","October","November","December" };
struct TemperatureInfo
{
	char scale;
	double low;
	double high;
	string monthname;
};

struct Citytempinfo
	{
		string cityname;
	    TemperatureInfo tempinfo[12];

	};


void sort(Citytempinfo* tempArray, Citytempinfo *temporArray)
{
	tempArray = 0;
	memcpy(temporArray, tempArray, sizeof(Citytempinfo)*numofcities);
	for (int i = 0; i < numofmonths; i++)
	{
		int j;
		double minvalue = 0;
		int minoffset = 0;
		for (j = i + 1; j < numofmonths - 1; j++)
		{
			if (temporArray->tempinfo[i].high > temporArray->tempinfo[j].high)
			{
				minvalue = temporArray->tempinfo[j].high;
				minoffset = j;
			}
		}
		string tempmonthbuff;
		tempmonthbuff = temporArray->tempinfo[j].monthname;
		tempArray->tempinfo[j].monthname = temporArray->tempinfo[i].monthname;
		temporArray->tempinfo[i].monthname = tempmonthbuff;
		temporArray->tempinfo[j].high = temporArray->tempinfo[i].high;
		temporArray->tempinfo[i].high = minvalue;

	}



}
int main()
{
	bool row;
	string line;
	streampos fileptr;
	ifstream myfile;
	myfile.open("example.txt",ios::in);
	getline(myfile, line);
	try
	{
		numofcities = stoi(line);
	}
	catch (int e)
	{
		std::cout << "stoi failed" << endl;
	}
	
	getline(myfile, line);
	numofmonths = stoi(line);


	Citytempinfo* tempArray = new Citytempinfo[(numofcities)];
	Citytempinfo* temporArray = new Citytempinfo[(numofcities)];
	while (getline(myfile, line, ','))
	{
		if (!row)
			tempArray->cityname = line;
		for (int i = 07; i < numofmonths * 2, getline(myfile, line, ',') || getline(myfile, line); i++)
		{

			tempArray->tempinfo[i].scale = 'F';
			tempArray->tempinfo[i].monthname = v[i %numofmonths];
			if (!row)
				tempArray->tempinfo[i].low = stod(line);
			else
				tempArray->tempinfo[i].high = stod(line);
		}

		row %= 2;
	}






	int citynum;
	int degrees;
	int lastchoice;
	cin >> citynum;
	string citynamein;
	string degreesstr;
	string last;
	do{
		do{

			do{

				cout << "Welcome to COP 2335 Temperature Wizard Program. Please select one of the following cities:"
					<< endl;
				cout << "1. Miami" << endl;
				cout << "2.Key West" << endl;
				cout << "3. Jacksonville" << endl;
				cout << "4. Pensacola" << endl;
				cout << "5. Exit" << endl;



				switch (citynum)
				{
				case 1: citynamein = "Miami";
					break;
				case 2: citynamein = "Key West";
					break;
				case 3: citynamein = "Jacksonville";
					break;
				case 4: citynamein = "Pensacola";
					break;
				case 5: citynamein = "Exit";

				};

				if (!citynamein.compare("Exit"))
				{
					return 0;
				}

			} while (!citynamein.compare("Exit") && (citynum < 1 && citynum > 5));

			cout << "Please choose one of the following options:" << endl;
			cout << "1. Degrees Celsius" << endl;
			cout << "2. Degrees Fahrenheit" << endl;
			cout << "3. Exit this menu" << endl;


			cin >> degrees;

			switch (degrees)
			{
			case 1: degreesstr = "Degrees Celsius";
				break;
			case 2: degreesstr = "Degrees Fahrenheit";
				break;
			case 3: degreesstr = "Exit this menu";

			};

		} while (!degreesstr.compare("Exit this menu") && (citynum < 1 && citynum > 3));




		cout << "What would you like to do?" << endl;
		cout << "1. View low and high temperatures" << endl;
		cout << "2. Find out what is the warmest month" << endl;
		cout << "3. Find out what is the coldest month" << endl;
		cout << "4. Exit this menu" << endl;


		cin >> lastchoice;


		switch (lastchoice)
		{
		case 1: last = "View low and high temperatures";
			break;
		case 2: last = "Find out what is the warmest month";
			break;
		case 3: last = "Find out what is the coldest month";
			break;
		case 4: last = "Exit this menu";

		};

	} while (!last.compare("Exit this menu") && (citynum < 1 && citynum > 4));

		tempArray = 0;
		for (int i = 0; i < numofcities; i++, tempArray++)
		{


			if (!tempArray->cityname.compare(citynamein) && !degreesstr.compare("Degrees Fahrenheit") && !last.compare("View low and high temperatures"))
			{
				cout << citynamein << endl;
				cout << "month" << setw(10) << "Low" << setw(10) << "High" << endl;
				for (int j = 0; j < 12; j++)
				{
					tempArray++;
					cout << tempArray->tempinfo[j].monthname << setw(10) << tempArray->tempinfo[j].low <<
						setw(10) << tempArray->tempinfo[j].high << setw(3) << tempArray->tempinfo[j].scale << endl;
				}

			}
			else if (!degreesstr.compare("Degrees Celcius"))
			{
				cout << citynamein << endl;
				cout << "month" << setw(10) << "Low" << setw(10) << "High" << endl;
				for (int j = 0; j < 12; j++)
				{
					tempArray++;
					double lowC = 5 / 9 * (tempArray->tempinfo[j].low - 32);
					double highC = 5 / 9 * (tempArray->tempinfo[j].high - 32);
					cout << tempArray->tempinfo[j].monthname << setw(10) << lowC << setw(10) << highC << setw(3) << 'C' << endl;
					lowC = 0;
					highC = 0;
				}

			}

			else if (last.compare("Find out what is the warmest month"))
			{

				sort(tempArray, temporArray);
				string warmestmonth = temporArray->tempinfo[numofmonths - 1].monthname;
				cout << "The warmest month is " << warmestmonth << endl;
			}
			else if (last.compare("Find out what is the coolest month"))
			{
				sort(tempArray, temporArray);
				string coolestmonth = temporArray->tempinfo[0].monthname;
				cout << "The coldest month is " << coolestmonth << endl;
			}

		}
		delete tempArray;
		delete temporArray;
		myfile.close();
		return 0;
}





