#include "Paramedics.h"


//CLASS PARAMEDIC

Paramedic::Paramedic()
{

}

Paramedic::Paramedic(std::string name)
{
	this->_name = name;
}

Paramedic::Paramedic(std::string name, int year, std::string address, std::string education)
{
	this->_name = name;
	this->_year_of_birth = year;
	this->_address = address;
	this->_education = education;
}

Paramedic::~Paramedic()
{

}

void Paramedic::set_name(std::string name)
{
	this->_name = name;
}

void Paramedic::set_year(int year)
{
	this->_year_of_birth = year;
}

void Paramedic::set_address(std::string address)
{
	this->_address = address;
}

void Paramedic::set_education(std::string education)
{
	this->_education = education;
}

void Paramedic::display_info()
{
	if (!empty(_name))
	{
		std::cout << "Имя сотрудника: " << _name << std::endl;
	}
	if (_year_of_birth != 0)
	{
		std::cout << "Год рождения сотрудника: " << _year_of_birth << std::endl;
	}
	if (!empty(_address))
	{
		std::cout << "Адрес: " << _address << std::endl;
	}
	if (!empty(_education))
	{
		std::cout << "Образование: " << _education << std::endl;
	}
	std::cout << "-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
}

//CLASS NURSE

Nurse::Nurse(std::string name_n)
{
	_name = name_n;
}


Nurse::Nurse()
{

}

void Nurse::add_hours(double hours)
{
	_amount_hours = _amount_hours + hours;
}

double Nurse::get_hours()
{
	return _amount_hours;
}

double Nurse::nurse_salary()
{
	double salary_rate = 350;
	double salary = salary_rate * _amount_hours;
	return salary;
}

//CLASS SURGEON


Surgeon::Surgeon(std::string name_s)
{
	_name = name_s;
}

Surgeon::Surgeon()
{

}

void Surgeon::add_patient(int new_patient)
{
	_amount_patient = _amount_patient + new_patient;
}

int Surgeon::get_patient()
{
	return _amount_patient;
}

double Surgeon::surgeon_salary()
{
	double salary_rate = 600;
	double salary = salary_rate * _amount_patient;
	return salary;
}