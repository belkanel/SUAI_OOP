#include <iostream>
#include <Windows.h>
#include <vector>
#include "Paramedics.h"

std::string enter_name()
{
	std::string name_of;
	std::cout << "Введите имя сотрудника:" << std::endl;
	getline(std::cin, name_of);
	return name_of;
}

std::string enter_address()
{
	std::string address;
	std::cout << "Введите адрес сотрудника:" << std::endl;
	getline(std::cin, address);
	return address;
}

int enter_year()
{
	int year;
	std::cout << "Введите год рождения сотрудника:" << std::endl;
	std::cin >> year;
	std::cin.ignore();
	return year;
}

std::string enter_education()
{
	std::string education;
	std::cout << "Введите образование сотрудника:" << std::endl;
	getline(std::cin, education);
	return education;
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::vector<Paramedic> paramedic_entry;
	std::vector<Nurse> nurse_entry;
	std::vector<Surgeon> surgeon_entry;

	std::string name_is, address, education;
	int registry_index, i, year = 0;

	bool exit = false;
	char command1, command2, command3;
	while (!exit)
	{
		std::cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
		std::cout << "Что вы хотите сделать?:\n";
		std::cout << "\t1. Создать запись о медицинском работнике.\n";
		std::cout << "\t2. Внести или изменить данные сотрудника.\n";
		std::cout << "\t3. Добавить отработанные часы медицинской сестры.\n";
		std::cout << "\t4. Добавить принятых пациентов хирурга.\n";
		std::cout << "\t5. Рассчитать зарплату медицинской сестры.\n";
		std::cout << "\t6. Рассчитать зарплату хирурга.\n";
		std::cout << "\t7. Посмотреть данные о сотрудниках.\n";
		std::cout << "\t8. Выход из программы.\n";
		std::cout << "Команда: ";
		std::cin >> command1;
		std::cin.ignore();
		switch (command1)
		{
		case '1':
			std::cout << "Вы хотите добавить:\n";
			std::cout << "\t1. Сотрудника больницы.\n";
			std::cout << "\t2. Медицинскую сестру.\n";
			std::cout << "\t3. Хирурга.\n";
			std::cin >> command2;
			std::cin.ignore();
			if (command2 == '1')
			{
				std::cout << "Вы хотите добавить:\n";
				std::cout << "\t1. Только имя сотрудника.\n";
				std::cout << "\t2. Полные данные сотрудника.\n";
				std::cin >> command3;
				std::cin.ignore();
				if (command3 == '1')
				{
					name_is = enter_name();
					paramedic_entry.push_back(Paramedic(name_is));
				}
				else if (command3 == '2')
				{
					name_is = enter_name();
					year = enter_year();
					address = enter_address();
					education = enter_education();
					paramedic_entry.push_back(Paramedic(name_is, year, address, education));
				}
				else
				{
					std::cout << "Вы ввели неверную командую" << std::endl;
				}
			}
			else if (command2 == '2')
			{
				name_is = enter_name();
				nurse_entry.push_back(Nurse(name_is));
			}
			else if (command2 == '3')
			{
				name_is = enter_name();
				surgeon_entry.push_back(Surgeon(name_is));
			}
			else
			{
				std::cout << "Вы ввели неверную командую" << std::endl;
			}
			break;
		case '2':

			std::cout << "Вы хотите добавить или изменить:\n";
			std::cout << "\t1. Имя сотрудника.\n";
			std::cout << "\t2. Год рождения сотрудника.\n";
			std::cout << "\t3. Адрес сотрудника.\n";
			std::cout << "\t4. Образование сотрудника.\n";
			std::cin >> command2;
			std::cin.ignore();
			if (command2 == '1')
			{
				std::cout << "Вы хотите добавить или изменить:\n";
				std::cout << "\t1. Запись о рядовом сотруднике.\n";
				std::cout << "\t2. Запись о медицинской сестре.\n";
				std::cout << "\t3. Запись о хирурге.\n";
				std::cin >> command3;
				std::cin.ignore();
				if (command3 == '1')
				{
					for (i = 0; i < size(paramedic_entry); i++)
					{
						std::cout << i << " ";
						paramedic_entry[i].display_info();
					}
					std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
					std::cin >> registry_index;
					std::cin.ignore();
					if (registry_index >= 0 && registry_index < size(paramedic_entry))
					{
						name_is = enter_name();
						paramedic_entry[registry_index].set_name(name_is);
					}
					else
					{
						std::cout << "Введен неверный номер записи." << std::endl;
					}
				}
				else if (command3 == '2')
				{
					for (i = 0; i < size(nurse_entry); i++)
					{
						std::cout << i << " ";
						nurse_entry[i].display_info();
					}
					std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
					std::cin >> registry_index;
					std::cin.ignore();
					if (registry_index >= 0 && registry_index < size(nurse_entry))
					{
						name_is = enter_name();
						nurse_entry[registry_index].set_name(name_is);
					}
					else
					{
						std::cout << "Введен неверный номер записи." << std::endl;
					}
				}
				else if (command3 == '3')
				{
					for (i = 0; i < size(surgeon_entry); i++)
					{
						std::cout << i << " ";
						surgeon_entry[i].display_info();
					}
					std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
					std::cin >> registry_index;
					std::cin.ignore();
					if (registry_index >= 0 && registry_index < size(surgeon_entry))
					{
						name_is = enter_name();
						surgeon_entry[registry_index].set_name(name_is);
					}
					else
					{
						std::cout << "Введен неверный номер записи." << std::endl;
					}
				}
				else
				{
					std::cout << "Введен неверный номер записи." << std::endl;
				}
			}
			else if (command2 == '2')
			{
				std::cout << "Вы хотите добавить или изменить:\n";
				std::cout << "\t1. Запись о рядовом сотруднике.\n";
				std::cout << "\t2. Запись о медицинской сестре.\n";
				std::cout << "\t3. Запись о хирурге.\n";
				std::cin >> command3;
				std::cin.ignore();
				if (command3 == '1')
				{
					for (i = 0; i < size(paramedic_entry); i++)
					{
						std::cout << i << " ";
						paramedic_entry[i].display_info();
					}
					std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
					std::cin >> registry_index;
					std::cin.ignore();
					if (registry_index >= 0 && registry_index < size(paramedic_entry))
					{
						year = enter_year();
						paramedic_entry[registry_index].set_year(year);
					}
					else
					{
						std::cout << "Введен неверный номер записи." << std::endl;
					}
				}
				else if (command3 == '2')
				{
					for (i = 0; i < size(nurse_entry); i++)
					{
						std::cout << i << " ";
						nurse_entry[i].display_info();
					}
					std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
					std::cin >> registry_index;
					std::cin.ignore();
					if (registry_index >= 0 && registry_index < size(nurse_entry))
					{
						year = enter_year();
						nurse_entry[registry_index].set_year(year);
					}
					else
					{
						std::cout << "Введен неверный номер записи." << std::endl;
					}
				}
				else if (command3 == '3')
				{
					for (i = 0; i < size(surgeon_entry); i++)
					{
						std::cout << i << " ";
						surgeon_entry[i].display_info();
					}
					std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
					std::cin >> registry_index;
					std::cin.ignore();
					if (registry_index >= 0 && registry_index < size(surgeon_entry))
					{
						year = enter_year();
						surgeon_entry[registry_index].set_year(year);
					}
					else
					{
						std::cout << "Введен неверный номер записи." << std::endl;
					}
				}
				else
				{
					std::cout << "Введен неверный номер записи." << std::endl;
				}
			}
			else if (command2 == '3')
			{
			std::cout << "Вы хотите добавить или изменить:\n";
			std::cout << "\t1. Запись о рядовом сотруднике.\n";
			std::cout << "\t2. Запись о медицинской сестре.\n";
			std::cout << "\t3. Запись о хирурге.\n";
			std::cin >> command3;
			std::cin.ignore();
				if (command3 == '1')
				{
					for (i = 0; i < size(paramedic_entry); i++)
					{
						std::cout << i << " ";
						paramedic_entry[i].display_info();
					}
					std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
					std::cin >> registry_index;
					std::cin.ignore();
					if (registry_index >= 0 && registry_index < size(paramedic_entry))
					{
						address = enter_address();
						paramedic_entry[registry_index].set_address(address);
					}
					else
					{
						std::cout << "Введен неверный номер записи." << std::endl;
					}
				}
				else if (command3 == '2')
				{
					for (i = 0; i < size(nurse_entry); i++)
					{
						std::cout << i << " ";
						nurse_entry[i].display_info();
					}
					std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
					std::cin >> registry_index;
					std::cin.ignore();
					if (registry_index >= 0 && registry_index < size(nurse_entry))
					{
						address = enter_address();
						nurse_entry[registry_index].set_address(address);
					}
					else
					{
						std::cout << "Введен неверный номер записи." << std::endl;
					}
				}
				else if (command3 == '3')
				{
					for (i = 0; i < size(surgeon_entry); i++)
					{
						std::cout << i << " ";
						surgeon_entry[i].display_info();
					}
					std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
					std::cin >> registry_index;
					std::cin.ignore();
					if (registry_index >= 0 && registry_index < size(surgeon_entry))
					{
						address = enter_address();
						surgeon_entry[registry_index].set_address(address);
					}
					else
					{
						std::cout << "Введен неверный номер записи." << std::endl;
					}
				}
				else
				{
					std::cout << "Введен неверный номер записи." << std::endl;
				}
			}
			else if (command2 == '4')
			{
			std::cout << "Вы хотите добавить или изменить:\n";
			std::cout << "\t1. Запись о рядовом сотруднике.\n";
			std::cout << "\t2. Запись о медицинской сестре.\n";
			std::cout << "\t3. Запись о хирурге.\n";
			std::cin >> command3;
			std::cin.ignore();
				if (command3 == '1')
				{
					if (size(paramedic_entry) == 0)
					{
						std::cout << "Отсутствуют записи о сотрудниках." << std::endl;
						break;
					}
					for (i = 0; i < size(paramedic_entry); i++)
					{
						std::cout << i << " ";
						paramedic_entry[i].display_info();
					}
					std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
					std::cin >> registry_index;
					std::cin.ignore();
					if (registry_index >= 0 && registry_index < size(paramedic_entry))
					{
						education = enter_education();
						paramedic_entry[registry_index].set_education(education);
					}
					else
					{
						std::cout << "Введен неверный номер записи." << std::endl;
					}
				}
				else if (command3 == '2')
				{
					if (size(nurse_entry) == 0)
					{
						std::cout << "Отсутствуют записи о сотрудниках." << std::endl;
						break;
					}
					for (i = 0; i < size(nurse_entry); i++)
					{
						std::cout << i << " ";
						nurse_entry[i].display_info();
					}
					std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
					std::cin >> registry_index;
					std::cin.ignore();
					if (registry_index >= 0 && registry_index < size(nurse_entry))
					{
						education = enter_education();
						nurse_entry[registry_index].set_education(education);
					}
					else
					{
						std::cout << "Введен неверный номер записи." << std::endl;
					}
				}
				else if (command3 == '3')
				{
					if (size(surgeon_entry) == 0)
					{
						std::cout << "Отсутствуют записи о сотрудниках." << std::endl;
						break;
					}
					for (i = 0; i < size(surgeon_entry); i++)
					{
						std::cout << i << " ";
						surgeon_entry[i].display_info();
					}
					std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
					std::cin >> registry_index;
					std::cin.ignore();
					if (registry_index >= 0 && registry_index < size(surgeon_entry))
					{
						education = enter_education();
						surgeon_entry[registry_index].set_education(education);
					}
					else
					{
						std::cout << "Введен неверный номер записи." << std::endl;
					}
				}
				else
				{
					std::cout << "Введен неверный номер записи." << std::endl;
				}
			}
			else
			{
				std::cout << "Введен неверный номер записи." << std::endl;
			}
			break;
		case '3':
			if (size(nurse_entry) == 0)
			{
				std::cout << "Отсутствуют записи о сотрудниках." << std::endl;
				break;
			}
			for (i = 0; i < size(nurse_entry); i++)
			{
				std::cout << i << " ";
				nurse_entry[i].display_info();
			}
			std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
			std::cin >> registry_index;
			std::cin.ignore();
			if (registry_index >= 0 && registry_index < size(nurse_entry))
			{
				double new_hours;
				std::cout << "Введите количество добавляемых часов: ";
				std::cin >> new_hours;
				std::cin.ignore();

				nurse_entry[registry_index].add_hours(new_hours);
				std::cout << "Часы добавлены, теперь часов: " << 
					nurse_entry[registry_index].get_hours() << std::endl;
			}
			else
			{
				std::cout << "Введен неверный номер записи." << std::endl;
			}
			break;
		case '4':
			if (size(surgeon_entry) == 0)
			{
				std::cout << "Отсутствуют записи о сотрудниках." << std::endl;
				break;
			}
			for (i = 0; i < size(surgeon_entry); i++)
			{
				std::cout << i << " ";
				surgeon_entry[i].display_info();
			}
			std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
			std::cin >> registry_index;
			std::cin.ignore();
			if (registry_index >= 0 && registry_index < size(surgeon_entry))
			{
				int new_patient;
				std::cout << "Введите количество добавляемых пациентов: ";
				std::cin >> new_patient;
				std::cin.ignore();

				surgeon_entry[registry_index].add_patient(new_patient);
				std::cout << "Пациенты добавлены, теперь пациентов: : " << 
					surgeon_entry[registry_index].get_patient() << std::endl;
			}
			else
			{
				std::cout << "Введен неверный номер записи." << std::endl;
			}
			break;
		case '5':
			if (size(nurse_entry) == 0)
			{
				std::cout << "Отсутствуют записи о сотрудниках." << std::endl;
				break;
			}
			for (i = 0; i < size(nurse_entry); i++)
			{
				std::cout << i << " ";
				nurse_entry[i].display_info();
			}
			std::cout << "Для которой по номеру записи вы хотите посмотреть данные?\n";
			std::cin >> registry_index;
			std::cin.ignore();
			if (registry_index >= 0 && registry_index < size(nurse_entry))
			{
				std::cout << "При количестве часов: " << nurse_entry[registry_index].get_hours() << 
					" зарплата составляет: " << nurse_entry[registry_index].nurse_salary() << std::endl;
			}
			else
			{
				std::cout << "Введен неверный номер записи." << std::endl;
			}
			break;
		case '6':
			if (size(surgeon_entry) == 0)
			{
				std::cout << "Отсутствуют записи о сотрудниках." << std::endl;
				break;
			}
			for (i = 0; i < size(surgeon_entry); i++)
			{
				std::cout << i << " ";
				surgeon_entry[i].display_info();
			}
			std::cout << "Для которой по номеру записи вы хотите посмотреть данные?\n";
			std::cin >> registry_index;
			std::cin.ignore();
			if (registry_index >= 0 && registry_index < size(surgeon_entry))
			{
				std::cout << "При количестве пациентов: " << surgeon_entry[registry_index].get_patient() <<
					" зарплата составляет: " << surgeon_entry[registry_index].surgeon_salary() << std::endl;
			}
			else
			{
				std::cout << "Введен неверный номер записи." << std::endl;
			}
			break;
		case '7':
			if (size(paramedic_entry) > 0)
			{
				std::cout << "Сотрудники больницы:" << std::endl;
				for (i = 0; i < size(paramedic_entry); i++)
				{
					std::cout << i << " ";
					paramedic_entry[i].display_info();
				}
			}
			if (size(nurse_entry) > 0)
			{
				std::cout << "Медицинские сестры больницы:" << std::endl;
				for (i = 0; i < size(nurse_entry); i++)
				{
					std::cout << i << " ";
					nurse_entry[i].display_info();
				}
			}
			if (size(surgeon_entry) > 0)
			{
				std::cout << "Хирурги больницы:" << std::endl;
				for (i = 0; i < size(surgeon_entry); i++)
				{
					std::cout << i << " ";
					surgeon_entry[i].display_info();
				}
			}
			break;
		case '8':
			exit = true;
			break;
		default:
			std::cout << "Вы ввели некорректную команду. Введите от 1 до 8." << std::endl;
			break;
		}
	}
	return 0;
}