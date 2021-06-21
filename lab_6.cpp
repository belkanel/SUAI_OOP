#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>

class Random_numbers
{
private:
	std::vector<int> _random_numbers;

public:
	Random_numbers();
	Random_numbers(int m1, int m2, int count);
	~Random_numbers();

	void set_random_values(int m1, int m2, int count);
	int get_value(int index);
	std::vector<int> get_vector();
	int find_count_number(int number);
	void display_info();
	double average_value();
};

Random_numbers::Random_numbers()
{

}

Random_numbers::Random_numbers(int m1, int m2, int vec_size)
{
	_random_numbers.resize(vec_size);
	int i;
	for (i = 0; i < vec_size; i++)
	{
		_random_numbers[i] = ((m1) + rand() % (m2 - m1));
	}
}

Random_numbers::~Random_numbers()
{

}

void Random_numbers::set_random_values(int m1, int m2, int vec_size)
{
	_random_numbers.resize(vec_size);
	int i;
	for (i = 0; i < vec_size; i++)
	{ 
		_random_numbers[i] =((m1) + rand() % (m2 - m1));
	}
}

int Random_numbers::get_value(int index)
{
	int value = _random_numbers[index];
	return value;
}

std::vector<int> Random_numbers::get_vector()
{
	return _random_numbers;
}

int Random_numbers::find_count_number(int numb)
{
	std::vector<int>::iterator number;		//объявляем итератор
	int count = 0;
	for (number = _random_numbers.begin(); number != _random_numbers.end(); ++number)
	{
		if (abs(*number) == numb)		//проверяем, равен ли элемент абсолютному значению
		{
			count++;
		}
	}
	return count;
}

void Random_numbers::display_info()
{
	std::vector<int>::iterator number;		//объявляем итератор
	int count = 1;
	for (number = _random_numbers.begin(); number != _random_numbers.end(); ++number)
	{
		std::cout << *number << " ";
		if (count % 10 == 0)		//раз в 10 значений переводим строку для удобства чтения
		{
			std::cout << std::endl;
		}
	}
	std::cout << std::endl;
}

double Random_numbers::average_value()
{
	std::vector<int>::iterator number;		//объявляем итератор
	int count = 0;
	int summ = 0;
	double avg_value = 0;
	for (number = _random_numbers.begin(); number != _random_numbers.end(); ++number)
	{
		summ = summ + *number;
		count++;
	}
	avg_value = summ / count;
	return avg_value;
}

int main()
{
	system("color f1");
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::vector<Random_numbers> numbers_entry;		//вводим массив элементов класса
	std::vector<int> massiv_1;
	std::vector<int> massiv_2;
	int m1, m2, vec_size, i, numb, vec_index;
	char command;
	bool exit = false;
	while (!exit)
	{
		std::cout << "\nЧто вы хотите сделать? \n";
		std::cout << "\t1. Создать массив с рандомными символами.\n";
		std::cout << "\t2. Вычислить среднее значение всех элементов массива.\n";
		std::cout << "\t3. Сложить два массива поэлементно.\n";
		std::cout << "\t4. Найти количество элементов, абсолютное значение которых равно заданному.\n";
		std::cout << "\t5. Отобразить все массивы.\n";
		std::cout << "\t6. Выход из программы.\n";
		std::cout << "Команда: ";
		std::cin >> command;
		std::cin.ignore();
		switch (command)
		{
		case '1':
			std::cout << "Введите число m1 начала диапазона: ";
			std::cin >> m1;
			std::cout << "Введите число m2 конца диапазона: ";
			std::cin >> m2;
			std::cout << "Введите размер вектора: ";
			std::cin >> vec_size;
			numbers_entry.push_back(Random_numbers(m1, m2, vec_size));
			std::cout << "Массив создан." << std::endl;
			numbers_entry[numbers_entry.size() - 1].display_info();
			break;
		case '2':
			std::cout << "Все имеющиеся массивы: " << std::endl;
			for (i = 0; i < size(numbers_entry); i++)
			{
				std::cout << "Массив №" << i << " ";
				numbers_entry[i].display_info();
			}
			std::cout << "В котором массиве вы хотите узнать среднее значение элементов? Введите номер: ";
			std::cin >> vec_index;
			if (vec_index < 0 || vec_index >= numbers_entry.size())
			{
				std::cout << "Введен неверный номер массива!" << std::endl;
				break;
			}
			std::cout << "Среднее значение элементов массива равно " << numbers_entry[vec_index].average_value() << std::endl;
			break;
		case '3':
			int mass_1, mass_2;
			std::cout << "Все имеющиеся массивы: " << std::endl;
			for (i = 0; i < size(numbers_entry); i++)
			{
				std::cout << "Массив №" << i << " ";
				numbers_entry[i].display_info();
			}
			std::cout << "Выберите первый массив для сложения: ";
			std::cin >> mass_1;
			if (mass_1 < 0 || mass_1 >= numbers_entry.size())
			{
				std::cout << "Введен неверный номер массива!" << std::endl;
				break;
			}
			std::cout << "Выберите второй массив для сложения: ";
			std::cin >> mass_2;
			if (mass_2 < 0 || mass_2 >= numbers_entry.size())
			{
				std::cout << "Введен неверный номер массива!" << std::endl;
				break;
			}
			
			massiv_1 = numbers_entry[mass_1].get_vector();
		
			massiv_2 = numbers_entry[mass_2].get_vector();
			if (massiv_1.size() != massiv_2.size())
			{
				std::cout << "Массивы не равны." << std::endl;
				break;
			}
			std::cout << "Массив, полученный из сложенных массивов поэлементно, будет выглядеть: " << std::endl;
			for (i = 0; i < massiv_1.size(); i++)
			{
				std::cout << massiv_1[i] + massiv_2[i] << " ";
				if ((i % 10 == 0) && (i != 0))
				{
					std::cout << std::endl;
				}
			}
			break;
		case '4':
			std::cout << "Все имеющиеся массивы: " << std::endl;
			for (i = 0; i < size(numbers_entry); i++)
			{
				std::cout << "Массив №" << i << " ";
				numbers_entry[i].display_info();
			}
			std::cout << "В котором массиве вы хотите проверить элементы? Введите номер: ";
			std::cin >> vec_index;
			if (vec_index < 0 || vec_index >= numbers_entry.size())
			{
				std::cout << "Введен неверный номер массива!" << std::endl;
				break;
			}
			std::cout << "Введите число, на равенство абсолютному значению которого надо проверить элементы: ";
			std::cin >> numb;
			std::cout << "Число " << numb << " встречается в массиве " << numbers_entry[vec_index].find_count_number(numb) << " раз(а)." << std::endl;
			break;
		case '5':
			for (i = 0; i < size(numbers_entry); i++)
			{
				std::cout << "Массив №" << i << " ";
				numbers_entry[i].display_info();
			}
			break;
		case '6':
			exit = true;
			break;
		default:
			std::cout << "Вы ввели некорректную команду. Введите от 1 до 6." << std::endl;
			break;
		}
	}
	return 0;
}