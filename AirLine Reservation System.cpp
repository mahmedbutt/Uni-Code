#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <Windows.h>
#include <cwchar>
#include <conio.h>
#include <iomanip>
#include <random>
#include <ctime>
using namespace std;

//Functions
void SeatReservation(int numofcity, string Ccode[], int numfli, string CName[], string FName[], string FNum[], string DCCode[], string ACCode[], string DTime[], string ATime[], int economy[], int buss[], int priceecono[], int pricebuss[], ofstream& fout);
void FlightSchedule(int numofcity, string Ccode[], int numfli, string CName[], string FName[], string FNum[], string DCCode[], string ACCode[], string DTime[], string ATime[], int economy[], int buss[]);
void PassengerInfo(string tikid[], string name[], string age[], string pass[], string DandA[], string date[], string fcode[], string fclass[], string fname[], string dtime[], string atime[], string price[], ofstream& fout1);
void printFlights(int numofcity, string Ccode[], int numfli, string CName[], string FName[], string FNum[], string DCCode[], string ACCode[], string DTime[], string ATime[], int economy[], int buss[], int priceecono[], int pricebuss[]);
void FlightCancellation(string tikid[], string name[], string age[], string pass[], string DandA[], string date[],string fcode[], string fclass[], string fname[], string dtime[], string atime[], string price[],ofstream& fin);
void flightDetails(int &numofcity, string Ccode[], int &numfli, string CName[], string FName[], string FNum[], string DCCode[], string ACCode[], string DTime[], string ATime[], int economy[], int buss[], int priceecono[], int pricebuss[]);
int randomvalue(int a, int b);
void concatenate(char a[], char b);
void adminlogin(int numofcity, string Ccode[], int numfli, string CName[], string FName[], string FNum[], string DCCode[], string ACCode[], string DTime[], string ATime[], int economy[], int buss[], int priceecono[], int pricebuss[]);
//Functions End

void main()				///Main Function///
{
	char exit = '\0';
	int choice = 0;
	int numofcity = 0;
	ofstream fout;
	fout.open("reservation.txt");
	string Ccode[20]; int numfli = 0; string CName[20]; string FName[20]; string FNum[20]; string DCCode[20]; string ACCode[20]; string DTime[20]; string ATime[20]; int economy[20]; int buss[20]; int priceecono[20];int pricebuss[20];
	string tikid[20]; string name[20]; string age[20]; string pass[20]; string DandA[20]; string date[20]; string fcode[20]; string fclass[20]; string fname[20]; string dtime[20]; string atime[20]; string price[20];
	string n[20]; string a[20]; string p[20]; string tiknum[20];
	flightDetails(numofcity, Ccode, numfli, CName, FName, FNum, DCCode, ACCode, DTime, ATime, economy, buss, priceecono, pricebuss);

	//TEXT COLOR///
	system("COLOR FC");
	system("COLOR 74");

	////TEXT SIZE /////
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                  
	cfi.dwFontSize.Y = 28;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"Consolas"); 
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	/////// Took help from Internet ///////

	cout << "WELCOME TO AIRLINE RESERVATION SYSTEM";
	cout << endl << endl;

	cout << "Airline Reservation System Menu";
	cout << endl;

	while (true)
	{
		cout << "__  _" << endl;
		cout << "\ `/ |" << endl;
		cout << " \__`!" << endl;
		cout << " / ,' `-.__________________ " << endl;
		cout << "'-'\_____                 LI`-." << endl;
		cout << "   <____()-=O=O=O=O=O=[]====--)" << endl;
		cout << "     `.___ ,-----,_______...-'" << endl;
		cout << "          /    .'" << endl;
		cout << "         /   .'" << endl;
		cout << "        /  .' " << endl;
		cout << "        `-'" << endl;
		cout << "" << endl << "1. Reserve Seat." << endl << "2. Flight Schedule." << endl << "3. Passenger and Ticket Information." << endl << "4. Flight Cancellation. "<<endl<<"5. Admin Login."<<endl<<"6. Exit Program." << endl;
		cout << "Choose One: ";
		cin >> choice;



		if (choice == 1)
		{
			system("cls");
			SeatReservation(numofcity, Ccode, numfli, CName, FName, FNum, DCCode, ACCode, DTime, ATime, economy, buss, priceecono, pricebuss, fout);
			system("pause");
		}
		if (choice == 2)
		{
			system("cls");
			FlightSchedule(numofcity, Ccode, numfli, CName, FName, FNum, DCCode, ACCode, DTime, ATime, economy, buss);
			system("pause");
		}
		if (choice == 3)
		{
			system("cls");
			PassengerInfo(tikid, name, age, pass, DandA, date, fcode, fclass, fname, dtime, atime, price, fout);
			system("pause");
		}
		if (choice == 4)
		{
			system("cls");
			FlightCancellation(tikid, name, age, pass,DandA, date, fcode, fclass, fname, dtime, atime, price, fout);
		}
		if (choice == 5)
		{
			system("cls");
			adminlogin(numofcity, Ccode, numfli, CName, FName, FNum, DCCode, ACCode, DTime, ATime, economy, buss, priceecono, pricebuss);
		}
		if (choice == 6)
		{

			cout << "Are you sure you want to exit?" << endl;
			cout << "Press Y for YES and N for NO." << endl;
			cin >> exit;

			if (exit == 'Y' || exit == 'y')
			{
				fout.close();
				cout << "Thank You for Visiting Airlines Reservation System." << endl << "Good Bye." << endl;
				break;
			}
			else if (exit == 'N' || exit == 'n')
			{
				cout << "Back to Main Menu." << endl;
			}
		}
		system("cls");
	}
	system("pause");
}

void SeatReservation(int numofcity, string Ccode[], int numfli, string CName[], string FName[], string FNum[], string DCCode[], string ACCode[], string DTime[], string ATime[], int economy[], int buss[], int priceecono[], int pricebuss[], ofstream& fout)  				///Seat Reservation Function///
{
	int cocat;
	string a;
	string b;
	int dep1, dep2, dep3;
	string seat;
	char seatclass;
	string username;
	string name;
	string passport;
	int seatno;
	int age;
	char tiknum[50] = " ";
	srand(time(0));
	char tnum;
	tnum = randomvalue(65, 90);
	concatenate(tiknum, tnum);
	tnum = randomvalue(65, 90);
	concatenate(tiknum, tnum);

	for (int x = 0; x < 3; x++)
	{
		tnum = randomvalue(48, 57);
		concatenate(tiknum, tnum);
	}

	string flicode;

	cout << "AIRLINE RESERVATION SYSTEM";
	cout << endl << endl;

	cout << "Reservation Menu.";
	cout << endl << endl;

	printFlights(numofcity, Ccode, numfli, CName, FName, FNum, DCCode, ACCode, DTime, ATime, economy, buss, priceecono, pricebuss);

	fout << "Ticket:" << tiknum << endl;
	fout << endl;
	cout << "Enter Name: ";
	cin.ignore();
	getline(cin, name);
	fout << name;
	cout << "Enter Username: ";
	cin.ignore();
	getline(cin, username);
	fout << endl;
	cout << "Enter Age: ";
	cin >> age;
	fout << "Age: " << age << endl;
	cout << "Enter Passport Number: ";
	getline(cin, passport);
	fout << "Passport Number: " << passport << endl;
	cout << "From (Enter Code): ";
	getline(cin, a);
	while (a != "LHE" && a != "ISB" && a != "KHI")
	{
		cout << "Please Enter in all Caps." << endl;
		cout << "Enter Code: ";
		getline(cin, a);
	}
	fout << a;
	cout << "To (Enter Code): ";
	getline(cin, b);
	while (b != "NYC" && b != "LGW" && b != "LAX")
	{
		cout << "Please Enter in all Caps." << endl;
		cout << "Enter Code: ";
		getline(cin, b);
	}
	fout << " To ";
	fout << b;
	fout << endl;

	cout << "Departure Date (MM/DD/YYYY): ";
	fout << "Date: ";
	cin >> dep1;
	while (dep1 == 0 || dep1 > 12)
	{
		cout << "Ivalid Number." << endl;
		cout << "Enter again: ";
		cin >> dep1;
	}
	fout << dep1;
	cout << "/";
	fout << "/";
	cin >> dep2;
	while (dep2 == 0 || dep2 > 31)
	{
		cout << "Ivalid Number." << endl;
		cout << "Enter again: ";
		cin >> dep2;
	}
	fout << dep2;
	cout << "/";
	fout << "/";
	cin >> dep3;
	while (dep3 < 2017 || dep3 > 3000)
	{
		cout << "Ivalid Number." << endl;
		cout << "Enter again: ";
		cin >> dep3;
	}

	fout << dep3 << " ";
	fout << endl;

	cout << endl << "Flights Available: " << endl;
	cout << left << setw(15) << "Flight Name" << setw(15) << "Flight Code" << setw(15) << "Departure" << setw(15) << "Arrival" << setw(15) << "D Time" << setw(15) << "A Time" << setw(15) << "E Price" << setw(15) << "B Price" << endl;
	for (int x = 0;x < numfli;x++)
	{
		if (DCCode[x] == a && ACCode[x] == b && (economy[x] > 0 || buss[x] > 0))
		{
			cout << left << setw(15) << FName[x] << setw(15) << FNum[x] << setw(15) << DCCode[x] << setw(15) << ACCode[x] << setw(15) << DTime[x] << setw(15) << ATime[x] << setw(15) << priceecono[x] << setw(15) << pricebuss[x] << endl;
		}
	}
	ifstream filein;
	filein.open("flights1.txt");

	for (int x = 0;x < numfli;x++)
	{
		if (DCCode[x] == a && ACCode[x] == b && (economy[x] > 0 || buss[x] > 0))
		{
			cout << left << setw(15) << FName[x] << setw(15) << FNum[x] << setw(15) << DCCode[x] << setw(15) << ACCode[x] << setw(15) << DTime[x] << setw(15) << ATime[x] << setw(15) << priceecono[x] << setw(15) << pricebuss[x] << endl;
		}
	}
	
	bool flag = false;
	cout << "Enter Flight Code: ";
	fout << "Flight Code: ";
	cin.ignore();
	getline(cin, flicode);
	fout << flicode << endl;
	cout << "Enter Class Type: ";
	fout << "CLass: ";

	int fcodeindex;
	while (!flag)
	{
		cout << "Type E for Economy and B for Buisness Class : ";
		cin >> seatclass;
		for (int i = 0; i < numfli; i++)
		{
			if (FNum[i] == flicode)
			{
				fcodeindex = i;
				if (seatclass == 'e' || seatclass == 'E')
				{
					if (economy[i] > 0)
					{
						economy[i]--;
						flag = true;
						break;
					}
					else
						cout << "No Seat Available In Economy.";
				}
				else if (seatclass == 'b' || seatclass == 'B')
				{
					if (buss[i] > 0)
					{
						buss[i]--;
						flag = true;
						break;
					}
					else
						cout << "No Seat Available In Buisness.";
				}

			}
		}
	}

	fout << seatclass << endl;
	fout << "Flight Name: " << FName[fcodeindex] << endl << "Departure Time: " << DTime[fcodeindex] << endl << "Arrival Time: " << ATime[fcodeindex] << endl;
	if (seatclass == 'B')
	{
		if (age > 60)
		{
			fout << "Due to Senior Citizen you recieve 25% Discount." << endl << endl;
			fout << "Ticket Price: ";
			fout << pricebuss[fcodeindex] * (75.0 / 100) << endl;
		}
		else
		{
			fout << pricebuss[fcodeindex] << endl;
		}

	}
	else if (seatclass == 'E')
	{
		cout << "Economy Price: ";
		if (age > 60)
		{
			fout << "Due to Senior Citizen you recieve 25% Discount." << endl << endl;
			fout << "Ticket Price: ";
			fout << priceecono[fcodeindex] * (75.0 / 100) << endl;
		}
		else
		{
			fout << priceecono[fcodeindex] << endl;
		}
		system("cls");
	}

	char line[100];
	system("cls");


	ifstream fin;
	fin.open("reservation.txt");

	while (!fin.eof())
	{
		fin.getline(line, 100);
		cout << line << endl;
	}


	fin.close();


}

void FlightSchedule(int numofcity, string Ccode[], int numfli, string CName[], string FName[], string FNum[], string DCCode[], string ACCode[], string DTime[], string ATime[], int economy[], int buss[])				///Flight Schedule Function///
{
	cout << "AIRLINE RESERVATION SYSTEM";
	cout << endl << endl;

	string a;
	string b;
	cout << "From (Enter Code): ";
	cin.ignore();
	getline(cin, a);
	while (a != "LHE" && a != "ISB" && a != "KHI")
	{
		cout << "Please Enter in all Caps." << endl;
		cout << "Enter Code: ";
		getline(cin, a);
	}
	cout << "To (Enter Code): ";
	getline(cin, b);
	while (b != "NYC" && b != "LGW" && b != "LAX")
	{
		cout << "Please Enter in all Caps." << endl;
		cout << "Enter Code: ";
		getline(cin, b);
	}

	ifstream fin;
	fin.open("flights.txt");

	cout << left << setw(15) << "Flight Name" << setw(15) << "Flight Code" << setw(15) << "Departure" << setw(15) << "Arrival" << setw(15) << "D Time" << setw(15) << "A Time" << endl;
	for (int x = 0;x < numfli;x++)
	{
		if (DCCode[x] == a && ACCode[x] == b && (economy[x] > 0 || buss[x] > 0))
		{
			cout << left << setw(15) << FName[x] << setw(15) << FNum[x] << setw(15) << DCCode[x] << setw(15) << ACCode[x] << setw(15) << DTime[x] << setw(15) << ATime[x] << endl;
		}
	}
	fin.close();
	ifstream filein;
	int data;
	filein.open("flights1.txt");
	while (!filein.eof());
	{
		fin >> data;
		cout << data << endl;
	}
	filein.close();

}

void FlightCancellation(string tikid[], string name[], string age[],string pass[], string DandA[], string date[], string fcode[], string fclass[], string fname[], string dtime[], string atime[], string price[],ofstream& fout1)				///Flight Cancellation///
{
	string tiknum;
	int x = 0;
	if (fout1)
	{
		fout1.close();
	}
	ifstream fin;
	fin.open("reservation.txt");
	char ignore1[50];
	while (!fin.eof())
	{
		fin >> ignore1;
		fin >> tikid[x]; fin.ignore();getline(fin, name[x]); getline(fin, age[x]); getline(fin, pass[x]); fin.ignore(); getline(fin, DandA[x]); getline(fin, date[x]); getline(fin, fcode[x]); getline(fin, fclass[x]); getline(fin, fname[x]); getline(fin, dtime[x]); getline(fin, atime[x]); getline(fin, price[x]);
		x++;
	}
	x--;
	ofstream fout;
	fout.open("reservation.txt");
	cout << "Enter Ticket Number: ";
	cin.ignore();
	getline(cin, tiknum);

	for (int i = 0; i < x; i++)
	{
		if (tikid[i] != tiknum)
		{
			fout << "Ticket:" << tikid[i] << endl;
			fout << name[i] << endl;
			fout << age[i] << endl;
			fout << pass[i] << endl;
			fout << DandA[i] << endl;
			fout << date[i]<<endl;
			fout << fcode[i] << endl;
			fout << fclass[i] << endl;
			fout << fname[i] << endl;
			fout << dtime[i] << endl;
			fout << atime[i] << endl;
			fout << price[i] << endl;
		}
	}
	fout.close();
	system("pause");
}

void PassengerInfo(string tikid[], string name[], string age[], string pass[], string DandA[], string date[], string fcode[], string fclass[], string fname[], string dtime[], string atime[], string price[], ofstream& fout1)				///Passenger Info Function///
{
	string usern;
	cout << "AIRLINE RESERVATION SYSTEM";
	cout << endl << endl;

	cout << "Passenger Information.";
	cout << endl << endl;
	ofstream fileout;
	fileout.open("passengers.txt");
	int i = 0;
	char ignore2[50];
	ifstream fin;
	fin.open("reservation.txt");

	while (!fin.eof())
	{
		fin >> ignore2;
		fin >> tikid[i]; fin.ignore();getline(fin, name[i]); getline(fin, age[i]); getline(fin, pass[i]); fin.ignore(); getline(fin, DandA[i]); getline(fin, date[i]); getline(fin, fcode[i]); getline(fin, fclass[i]); getline(fin, fname[i]); getline(fin, dtime[i]); getline(fin, atime[i]); getline(fin, price[i]);
		i++;
	}
	i--;
	fin.close();

	string tiknum;
	ofstream fout;
	fout.open("reservation.txt");
	cout << "Enter Ticket Number: ";
	cin.ignore();
	getline(cin, tiknum);

	for (int j = 0; j < i; j++)
	{
		if (tikid[i] != tiknum)
		{
			cout << "Ticket:" << tikid[j] << endl;
			fileout << "Ticket:" << tikid[j] << endl;
			cout << name[j] << endl;
			cout << age[j] << endl;
			cout << pass[j] << endl;
			cout << DandA[j] << endl;
			cout << date[j] << endl;
			cout << fcode[j] << endl;
			cout << fclass[j] << endl;
			cout << fname[j] << endl;
			cout << dtime[j] << endl;
			cout << atime[j] << endl;
			cout << price[j] << endl;
			fileout << name[j] << endl;
			fileout << age[j] << endl;
			fileout << pass[j] << endl;
			fileout << DandA[j] << endl;
			fileout << date[j] << endl;
			fileout << fcode[j] << endl;
			fileout << fclass[j] << endl;
			fileout << fname[j] << endl;
			fileout << dtime[j] << endl;
			fileout << atime[j] << endl;
			fileout << price[j] << endl;
		}
	}
	fout.close();

	fileout.close();
}

void flightDetails(int &numofcity, string Ccode[], int &numfli, string CName[], string FName[], string FNum[], string DCCode[], string ACCode[], string DTime[], string ATime[], int economy[], int buss[], int priceecono[], int pricebuss[])
{
	ifstream fin("flights.txt");
	if (fin)
	{
		fin >> numofcity;

		for (int i = 0; i < numofcity; i++)
		{
			fin >> Ccode[i];
			fin >> CName[i];
		}

		fin >> numfli;

		for (int i = 0; i < numfli; i++)
		{
			fin >> FName[i] >> FNum[i] >> DCCode[i] >> ACCode[i] >> DTime[i] >> ATime[i] >> economy[i] >> buss[i] >> priceecono[i] >> pricebuss[i];
		}
	}
}

void printFlights(int numofcity, string Ccode[], int numfli, string CName[], string FName[], string FNum[], string DCCode[], string ACCode[], string DTime[], string ATime[], int economy[], int buss[], int priceecono[], int pricebuss[])
{
	cout << left << setw(15) << "City Codes" << setw(15) << "City Name" << endl;
	for (int x = 0;x < numofcity;x++)
	{
		cout << left << setw(15) << Ccode[x] << setw(15) << CName[x] << endl;
	}

}

int randomvalue(int a, int b)
{
	int tnum;
	while (true)
	{
		tnum = rand() % (b+1);
		if (tnum > a)
		{
			return tnum;
		}
	}
}

void concatenate(char a[], char b)
{
	int lena = strlen(a);

		a[lena] = b;
}

void adminlogin(int numofcity, string Ccode[], int numfli, string CName[], string FName[], string FNum[], string DCCode[], string ACCode[], string DTime[], string ATime[], int economy[], int buss[], int priceecono[], int pricebuss[])
{
	ifstream in;
	in.open("reservation.txt");
	string temp;
	char username[50] = "admin";
	char password[50] = "adminadmin";
	char user[50] = {};
	char pass[50] = {};
	cout << "Enter Username:  ";
	cin.ignore();
	gets_s(user);
	cout << endl;
	cout << "Enter Password: ";
	gets_s(pass);
	cout << endl;
	if (strcmp(username, user) == 0 && strcmp(password, pass) == 0)
	{

		cout << "Login successful." << endl;
		while (!in.eof())
		{
			getline(in, temp);
			cout << temp << endl;
		}
		system("pause");
	}
	else 
	{
		cout << "Username or Password Incorrect. Please try again." << endl;
	}
	system("pause");


}