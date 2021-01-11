#include "Tarom_Airlines.hpp"
#include<ctime>
#include<stdlib.h>
using namespace std;

const int MAX_VALID_YR = 9999;
const int MIN_VALID_YR = 1800;

bool isLeap(int year)
{
	
	return (((year % 4 == 0) &&
		(year % 100 != 0)) ||
		(year % 400 == 0));
}
bool isValidDate(int d, int m, int y)
{
if (y > MAX_VALID_YR ||
		y < MIN_VALID_YR)
		return false;
	if (m < 1 || m > 12)
		return false;
	if (d < 1 || d > 31)
		return false;

	
	if (m == 2)
	{
		if (isLeap(y))
			return (d <= 29);
		else
			return (d <= 28);
	}
   if (m == 4 || m == 6 ||
		m == 9 || m == 11)
		return (d <= 30);

	return true;
}


bool isChar(char c)
{
	return ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'));
}
bool isDigit(const char c)
{
	return (c >= '0' && c <= '9');
}
bool is_valid_email(string email)
{
if (!isChar(email[0])) {
		return 0;
	}
	int At = -1, Dot = -1;
	for (int i = 0; i <= email.length() - 1; i++)
	{
		if (email[i] == '@') {
			At = i;
		}
		else if (email[i] == '.') {
			Dot = i;
		}
	}
	if (At == -1 || Dot == -1)
		return 0;
	if (At > Dot)
		return 0;
	return !(Dot >= (email.length() - 1));
}

bool is_Valide_Password(string password)
{
	if (password.length() < 10) return 0;
	else return 1;
}
int main()
{
	Users users;
	Zboruri ceva;
	Rezervari rezervari;
	bool open = true;
	string username;
	string password;
	string age;
	char options;
	string aux;
	int  zi, luna, an;
	int data;
	string email;
	string contact_number;
	string Airline_Fly, departure, destination, admin, adminPassword;
	string hour_destination, hour_departure, date_Fly;
	char choice;
	users.read_csv("utilizatori.csv");
	ceva.read_csv("zbor.csv");
	rezervari.read_csv("rezervari.csv");
	bool done = true;
	while (open)
	{
		cout << "*$*$*$*$*$*$*$*$*$**$*$$*$*$**$$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*" << endl;
		cout << "\t\tWelcome To Airplines_Lines CarpatAir_System" << endl;
		cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><>\n";
		cout << "\t   Book your Flight tickets at affordable prices!" << endl;
		cout << "\t   <><><><><><><><><><><><><><><><><><><><><><><>" << endl << endl;
		cout << "*$*$*$*$*$*$*$*$*$**$*$$*$*$**$$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*$*" << endl;
		cout << "1~Create Account\n";
		cout << "2~Login \n";
	    cout << "3~Admin_Manager" << "\n";
		cout << "4->Exit\n\n";
		cout << "Choice= ";
		cin >> choice;
		switch (choice)
		{
		case '1':
			cout << "\n Username= ";
			cin >> username;
		  Email:
			cout << "\n Email= ";
			cin >> email;
			try
			{
				if (!is_valid_email(email))
					throw email;
			}
			catch (string email)
			{
				cout << "Email GRESIT!\n";
				goto Email;
			}
			cout << "\n Age= ";
			cin >> age;
			cout << "\nContact_Number= ";
			cin >> contact_number;
		   Password:
			cout << "Password: ";
			cin >> password;
			try
			{
				if (password.length() < 8)
					throw password;
			}
			catch (string password)
			{
				cout << "Parola SLABA!\n";
				goto Password;
			}
			users.create_account("utilizatori.csv", username, email, age, contact_number, password);
			break;
		 case '2':
			cout << "Email: ";
			cin >> email;
			try
			{
				if (!is_valid_email(email))
					throw email;
			}
			catch (string email)
			{
				goto Email;
			}
			cout << "Password: ";
			cin >> password;
			if (users.login_user(email, password) != 0)
			{
				aux = users.getusername();
			}
			if (aux.compare("") == 0)
			{
				cout << "Cautati ceva zbor" << endl;
				cout << "Airlines: ";
				cin >> Airline_Fly;
				cout << "Departure: ";
				cin >> departure;
				cout << "Destination: ";
				cin >> destination;
			    cout << "Date_Fly(DDMMYY): ";
				cin >> date_Fly;
				
				ceva.Find_Flying(Airline_Fly, departure, destination,date_Fly);
				Booking:
				try
				{
					if (ceva.getAirline_Company() == "" && ceva.getdeparture() == "" && ceva.getdestination() == "")
						throw Airline_Fly;
				}
				catch (string Airline_FLy)
				{
					cout << "Zbor NEGASIT!\n";
					goto Booking;
				}
			}
		    rezervari.adauga_Rezervari("rezervari.csv", users.getusername(), Airline_Fly, departure, destination, hour_departure, hour_destination, date_Fly);
			cin >> aux;
			cin.get();
			cin.get();
			break;
		    case '3':
			cout << "Admin's name: ";
			cin >> admin;
			cout << "Password: ";
			cin >> adminPassword;
			try
			{
				if (admin != "admin" || adminPassword != "admin")
					throw admin;
				else
				{
					system("@cls||clear");
					cout << "1->Adauga Zboruri\n";
					cout << "2->Sterge Zboruri\n";
					cout << "3-Afisare_Utilizatori\n";
					cout << "4-Afisare_Zboruri\n";
					cout << "5-Afisare_Rezervari\n";
					cout << "Default key->Exit\n\n";
					cout << "Option: ";
					cin >> options;
					if (options == '1')
					{
						cout << "Airlines: ";
						cin >> Airline_Fly;
						cout << "Departure: ";
						cin >> departure;
						cout << "Destination: ";
						cin >> destination;
						cout << "Hour_departure= ";
						cin >> hour_departure;
						cout << "Hour_destination= ";
						cin >> hour_destination;
						Data:
						cout << "Date_Fly(DDMMYY)= ";
						cin >> date_Fly;
						/*try
						{
							
							int data = stoi(date_Fly);
							zi = data / 10000;
							luna = data / 100 % 100;
							an = data % 100;

							if (((2020 > an) && (12 >= luna) && (6 >= zi))
								|| ((2020 > an) && (12 < luna) && (6 < zi))
								|| ((2020 == an) && (12 > luna) && (6 >= zi))
								|| ((2020 == an) && (12 > luna) && (6 <= zi)))
							{
								throw date_Fly;
							}

						}
						catch (string date_Fly)
						{
							goto Data;
							cout << "Data in trecut" << endl;
						}
						*/
						ceva.adauga_Zboruri("zbor.csv",Airline_Fly, departure, 
							destination, hour_departure, hour_destination, date_Fly);
					}
					else if (options == '2')
					{
					    cout << "Airlines: ";
						cin >> Airline_Fly;
						cout << "Departure: ";
						cin >> departure;
						cout << "Destination: ";
						cin >> destination;
						cout << "Hour_departure= ";
						cin >> hour_departure;
						cout << "Hour_destination= ";
						cin >> hour_destination;
						cout << "Date_Fly= ";
						cin >> date_Fly;
					  ceva.sterge_Zboruri("zboruri.csv", Airline_Fly, departure, destination,
							hour_departure, hour_destination, date_Fly);
					}
					else if (options == '3')
					{
						cout << "Afisare utlizatori= " << "\n";
						users.show_users();
						cin.get();
						cin.get();
				
					}
		           else if (options == '4')
					{
						cout << "Zboruri:\n\n";
						ceva.show_flight();
						cin >> aux;
					}
					else if (options == '5')
					{
						cout << "Airlines:\n\n";
						rezervari.show();
						cin >> aux;

					}
				}
			}
			catch (string admin)
			{
				break;
			}
			break;
		  case '8':
			open = false;
			break;
		default:
			break;
		}
		system("@cls||clear");
	}
	return 0;
}