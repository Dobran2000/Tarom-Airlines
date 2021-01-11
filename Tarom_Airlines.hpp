#pragma once
#define TAROM_AIRLINES
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<stdlib.h>
using namespace std;
//clasa de utlizatori
class Users
{
	vector<vector<string>> date_users;
	vector<string> v;
	int lines = 0;
	string username;
	string password;
	string email;
	string age;

public:
	Users();
	~Users();
	void read_csv(string file);
	void show_users();
	void create_account(string, string, string, string, string, string);
	int login_user(string, string);
	string getusername();
	string getpassword();
	string getemail();
	string getage();
};
Users::Users()
{
}
Users::~Users()
{
	cout << "Obiectul a fost distrus";
}
void Users::read_csv(string file)
{
	ifstream in(file);
	string line, field;
	this->lines = 0;

	while (getline(in, line))
	{
		this->v.clear();
		stringstream ss(line);
		++this->lines;
		while (getline(ss, field, ','))
		{
			this->v.push_back(field);
		}
		this->date_users.push_back(this->v);
	}
	in.close();

}
void Users::create_account(string file, string username, string email, string age, string contact_number, string password)
{
	for (int i = 0; i < this->lines; ++i)
		if ((date_users[i][0] == username && date_users[i][1] == email
			&& date_users[i][2] == age && date_users[i][3] == contact_number
			&& date_users[i][4] == password))
			return;
	this->v.clear();
	this->v.push_back(username);
	this->v.push_back(email);
	this->v.push_back(age);
	this->v.push_back(contact_number);
	this->v.push_back(password);
	this->date_users.push_back(this->v);
	++this->lines;
	this->username = username;
	this->email = email;
	ofstream out(file);
	for (int i = 0; i < this->lines; ++i)
		out << this->date_users[i][0] << ',' << this->date_users[i][1] 
		<< ',' << this->date_users[i][2]
		<< ',' << this->date_users[i][3] << ',' << this->date_users[i][4] << "\n";
	out.close();
}
int Users::login_user(string email, string password)
{
	for (int i = 0; i < this->lines; i++)
		if (email == this->date_users[i][1] && password == this->date_users[i][4])
		{
			this->email = email;
			this->password = password;
			cout << "Logare Reusita:)" << endl;
			return 1;
		}
		else 
		{
	     	return 0;
		}
}
void Users::show_users()
{
	cout << lines;
	for (int i = 0; i < this->lines; ++i)
  cout << this->date_users[i][0] << ',' << this->date_users[i][1] << '\n';
}
string Users::getusername()
{
	return this->username;
}
string Users::getpassword()
{
	return this->password;
}
string Users::getage()
{
	return this->age;
}
string Users::getemail()
{
	return this->email;
}





class Zboruri
{
	vector<vector<string>> date_zboruri;
	vector<string> v;
	int lines = 0;
	string Airline_Fly;
	string departure;
	string destination;
	string hour_departure;
	string hour_destination;
	string date_Fly;

public:
	Zboruri();
	void read_csv(string file);
	void show_flight();
	void Find_Flying(string, string, string, string);
	void adauga_Zboruri(string, string, string, string, string, string, string);
	void sterge_Zboruri(string, string, string, string, string, string, string);
	string getAirline_Company();
	string getdeparture();
	string getdestination();
	string gethour_departure();
	string gethour_destination();
	string getdate_Fly();
};

Zboruri::Zboruri()
{
}
void Zboruri::read_csv(string file)
{
	ifstream in(file);
	string line, field;
	this->lines = 0;
	while (getline(in, line))
	{
     	this->v.clear();
		stringstream ss(line);
		++this->lines;
		while (getline(ss, field, ','))
		{
			this->v.push_back(field);
		}
		this->date_zboruri.push_back(this->v);
		cout << this->lines;
	}
	in.close();

}

void Zboruri::show_flight()
{
	cout << this->lines;
	for (int i = 0; i < this->lines; ++i)
		cout << ' ' << date_zboruri[i][0] << ' ' << date_zboruri[i][1] <<
		'-' << date_zboruri[i][2] << ' ' << date_zboruri[i][3] << ' '
		<< date_zboruri[i][4] << ' ' << date_zboruri[i][5] << "\n";
}

void Zboruri::Find_Flying(string Airline_Fly, string departure, string destination, string date_Fly)
{
	this->v.clear();
	this->Airline_Fly = this->departure = this->destination = "";
	this->hour_departure = this->hour_destination = this->date_Fly = "";
	cout << this->lines;
	for (int i = 0; i < this->lines; ++i)
		if (this->date_zboruri[i][0] == Airline_Fly && this->date_zboruri[i][1] == departure
			&& this->date_zboruri[i][2] == destination && this->date_zboruri[i][5] == date_Fly)
		{
			this->Airline_Fly = Airline_Fly;
			this->departure = departure;
			this->destination = destination;
     		this->date_Fly = date_Fly;
			cout << "Zbor gasit" << endl;
		}
}
void Zboruri::adauga_Zboruri(string file, string Airline_Fly,
	string departure, string destination, string hour_departure, string hour_destination, string date_Fly)
{
	for (int i = 0; i < this->lines; ++i)
		if ( this->date_zboruri[i][1] == Airline_Fly
			&& this->date_zboruri[i][2] == departure && this->date_zboruri[i][3] == destination
			&& this->date_zboruri[i][4] == hour_departure
			&& this->date_zboruri[i][5] == hour_destination
			&& this->date_zboruri[i][6] == date_Fly)
			return;
	this->v.clear();
	this->v.push_back(Airline_Fly);
	this->v.push_back(departure);
	this->v.push_back(destination);
	this->v.push_back(hour_departure);
	this->v.push_back(hour_destination);
	this->v.push_back(date_Fly);
	this->date_zboruri.push_back(this->v);
	++this->lines;
	ofstream out(file);
	for (int i = 0; i < this->lines; ++i)
		out << this->date_zboruri[i][0] << ',' << this->date_zboruri[i][1] << ','
		<< this->date_zboruri[i][2] << ',' <<this-> date_zboruri[i][3] << ','
		<< this->date_zboruri[i][4] << ',' << this->date_zboruri[i][5] << endl;
		out.close();
}

void Zboruri::sterge_Zboruri(string file,
	string Airline_Fly, string departure, string destination,
	string hour_departure, string hour_destination, string date_Fly)
{
	bool find = false;
	for (int i = 0; i < this->lines && !find; ++i)
		if (this->date_zboruri[i][0] == Airline_Fly
			&& this->date_zboruri[i][1] == departure
			&& this->date_zboruri[i][2] == destination
			&& this->date_zboruri[i][3] == hour_destination
			&& this->date_zboruri[i][4] == hour_departure
			&& this->date_zboruri[i][5] == date_Fly)
		{
			this->date_zboruri[i].pop_back();
			find = true;
		}
	if (find)
	{
		--this->lines;
		ofstream out(file);
		for (int i = 0; i < this->lines; ++i)
			out <<this-> date_zboruri[i][0] << ',' << this->date_zboruri[i][1] <<
			',' << this->date_zboruri[i][2] << '\n';
		out.close();
	}
}
string Zboruri::getAirline_Company()
{
	return this->Airline_Fly;
}

string Zboruri::getdeparture()
{
	return this->departure;
}

string Zboruri::getdestination()
{
	return this->destination;
}
string Zboruri::gethour_departure()
{
	return this->hour_departure;
}
string Zboruri::gethour_destination()
{
	return this->hour_destination;
}
string Zboruri::getdate_Fly()
{
	return this->date_Fly;
}


class Rezervari
{
	vector<vector<string>> date_rezervari;
	vector<string> v;
	int lines = 0;
public:
	Rezervari();
	void read_csv(string);
	void show();
	void adauga_Rezervari(string, string, string, string, string, string, string, string);
    void sterge_Rezervari(string, string, string, string, string, string, string, string);
};
Rezervari::Rezervari()
{
}
void Rezervari::read_csv(string file)
{
	ifstream in(file);
	string line, field;
	this->lines = 0;

	while (getline(in, line))
	{
		this->v.clear();
		stringstream ss(line);
		++this->lines;
		while (getline(ss, field, ','))
		{
			this->v.push_back(field);
		}
		this->date_rezervari.push_back(this->v);
	}
	in.close();
}
void Rezervari::adauga_Rezervari(string file, string username, string Airline_Company,
	string departure, string destination, string hour_departure, string hour_destination, string date_Fly)
{
	for (int i = 0; i < this->lines; ++i)
		if (this->date_rezervari[i][0] == username 
			&& this->date_rezervari[i][1] == Airline_Company
			&& this->date_rezervari[i][2] == departure 
			&& this->date_rezervari[i][3] == destination
			&& this->date_rezervari[i][4] == hour_departure
			&& this->date_rezervari[i][5] == hour_destination
			&& this->date_rezervari[i][6] == date_Fly)
			return;
	this->v.clear();
	this->v.push_back(username);
	this->v.push_back(Airline_Company);
	this->v.push_back(departure);
	this->v.push_back(destination);
	this->v.push_back(hour_departure);
	this->v.push_back(hour_destination);
	this->v.push_back(date_Fly);
	this->date_rezervari.push_back(this->v);
	++this->lines;
	ofstream out(file);
	for (int i = 0; i < this->lines; ++i)
		out << this->date_rezervari[i][0] << ',' << this->date_rezervari[i][1] << ','
		<< this->date_rezervari[i][2] << ',' << this->date_rezervari[i][3] << '\n';
	out.close();
}

void Rezervari::sterge_Rezervari(string file, string username,
	string flying, string departure, string destination,
	string hour_departure, string hour_destination, string date_Fly)
{
	bool find = false;
	for (int i = 0; i < this->lines && !find; ++i)
		if (this->date_rezervari[i][0] == username
			&& this->date_rezervari[i][1] == flying
			&& this->date_rezervari[i][2] == departure
			&& this->date_rezervari[i][3] == destination
			&& this->date_rezervari[i][4] == hour_destination
			&& this->date_rezervari[i][5] == hour_departure
			&& this->date_rezervari[i][6] == date_Fly)
		{
			this->date_rezervari[i].pop_back();
			find = true;
		}
	if (find)
	{
		--this->lines;
		ofstream out(file);
		for (int i = 0; i < this->lines; ++i)
			out << this->date_rezervari[i][0] << ',' << this->date_rezervari[i][1] <<
			',' << this->date_rezervari[i][2] << '\n';
		out.close();
	}
}
void Rezervari::show()
{
	cout << this->lines;
	for (int i = 0; i < this->lines - 1; i++)
cout << this->date_rezervari[i][0] << '\t' << this->date_rezervari[i][1] 
<< '\t' << this->date_rezervari[i][2] << '\t' << this->date_rezervari[i][3] << endl;
}
