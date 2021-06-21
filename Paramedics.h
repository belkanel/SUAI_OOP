#pragma once
#include <string>
#include <iostream>

class Paramedic
{
protected:
	std::string _name;
	int _year_of_birth = 0;
	std::string _address;
	std::string _education;

public:
	Paramedic();
	Paramedic(std::string name);
	Paramedic(std::string name, int year, std::string address, std::string education);
	~Paramedic();

	void set_name(std::string name);
	void set_year(int year);
	void set_address(std::string address);
	void set_education(std::string education);

	void display_info();
};

class Nurse : public Paramedic
{
private:
	double _amount_hours = 0;

public:
	Nurse(std::string name_n);
	Nurse();

	void add_hours(double hours);
	double get_hours();
	double nurse_salary();
};

class Surgeon : public Paramedic
{
private:
	int _amount_patient = 0;

public:
	Surgeon(std::string name_s);
	Surgeon();

	void add_patient(int new_patient);
	int get_patient();
	double surgeon_salary();
};

