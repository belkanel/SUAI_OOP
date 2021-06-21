#include <iostream>
#include <vector> 
#include <cstdlib>
#include <stdlib.h>
#include <Windows.h>
#include <array>

class Triangle
{
private:
	double _apex_a_x;
	double _apex_a_y;
	double _apex_b_x;
	double _apex_b_y;
	double _apex_c_x;
	double _apex_c_y;
	double _area;

public:

	Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
	~Triangle();
	void set_apex_a(double x, double y);
	void set_apex_b(double x, double y);
	void set_apex_c(double x, double y);

	std::vector <double> get_coord();
	double area_of_triangle();
	void display_info();

	bool operator==(std::array<double, 2> xy);
	bool operator==(std::vector <double> coord);
	friend bool operator==(const Triangle &a, const Triangle &b);
};

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	_apex_a_x = x1;
	_apex_a_y = y1;
	_apex_b_x = x2;
	_apex_b_y = y2;
	_apex_c_x = x3;
	_apex_c_y = y3;
}

Triangle::~Triangle()
{

}

void Triangle::set_apex_a(double x, double y)
{
	_apex_a_x = x;
	_apex_a_y = y;
}

void Triangle::set_apex_b(double x, double y)
{
	_apex_b_x = x;
	_apex_b_y = y;
}

void Triangle::set_apex_c(double x, double y)
{
	_apex_c_x = x;
	_apex_c_y = y;
}

std::vector <double> Triangle::get_coord()
{
	std::vector <double> coord_triangle;
	coord_triangle[0] = _apex_a_x;
	coord_triangle[1] = _apex_a_y;
	coord_triangle[2] = _apex_b_x;
	coord_triangle[3] = _apex_b_y;
	coord_triangle[4] = _apex_c_x;
	coord_triangle[5] = _apex_c_y;

	return coord_triangle;
}

double Triangle::area_of_triangle()
{
	double S;
	S = 0.5 * (abs((_apex_b_x - _apex_a_x) * (_apex_c_y - _apex_a_y) - 
		(_apex_c_x - _apex_a_x) * (_apex_b_y - _apex_a_y)));
	_area = S;
	return S;
}

void Triangle::display_info()
{
	std::cout << "Вершина A имеет координаты: (" << _apex_a_x << ";" << _apex_a_y << ")" << std::endl;
	std::cout << "Вершина B имеет координаты: (" << _apex_b_x << ";" << _apex_b_y << ")" << std::endl;
	std::cout << "Вершина C имеет координаты: (" << _apex_c_x << ";" << _apex_c_y << ")" << std::endl;
}

bool Triangle::operator==(std::vector <double> coord)
{
	if ((_apex_a_x == coord[0] && _apex_a_y == coord[1]) && 
		(_apex_b_x == coord[2] && _apex_b_y == coord[3]) &&
		(_apex_c_x == coord[4] && _apex_c_y == coord[5]))
	{
		return true;
	}
	else if ((_apex_a_x == coord[2] && _apex_a_y == coord[3]) &&
		(_apex_b_x == coord[4] && _apex_b_y == coord[4]) &&
		(_apex_c_x == coord[0] && _apex_c_y == coord[1]))
	{
		return true;
	}
	else if ((_apex_a_x == coord[4] && _apex_a_y == coord[5]) &&
		(_apex_b_x == coord[0] && _apex_b_y == coord[1]) &&
		(_apex_c_x == coord[2] && _apex_c_y == coord[3]))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Triangle::operator==(std::array<double, 2> xy)
{
	double x0 = xy[0];
	double y0 = xy[1];

	double equation_1, equation_2, equation_3;

	equation_1 = (_apex_a_x - x0) * (_apex_b_y - _apex_a_y) - (_apex_b_x - _apex_a_x) * (_apex_a_y - y0);
	equation_2 = (_apex_b_x - x0) * (_apex_c_y - _apex_b_y) - (_apex_c_x - _apex_b_x) * (_apex_b_y - y0);
	equation_3 = (_apex_c_x - x0) * (_apex_a_y - _apex_c_y) - (_apex_a_x - _apex_c_x) * (_apex_c_y - y0);
	
	if (equation_1 == 0 || equation_2 == 0 || equation_3 == 0)
	{
		return true;
	}
	else if (equation_1 > 0 && equation_2 > 0 && equation_3 > 0)
	{
		return true;
	}
	else if (equation_1 < 0 && equation_2 < 0 && equation_3 < 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator==(const Triangle &a, const Triangle &b)
{
	return a._area == b._area;
}

std::vector <double> input_coord()
{
	std::vector <double> in_coord;
	double temp;

	std::cout << "Введите координату X вершины A: ";
	std::cin >> temp;
	in_coord.insert(in_coord.end(), temp);
	std::cout << "Введите координату Y вершины A: ";
	std::cin >> temp;
	in_coord.insert(in_coord.end(), temp);
	std::cout << "Введите координату X вершины B: ";
	std::cin >> temp;
	in_coord.insert(in_coord.end(), temp);
	std::cout << "Введите координату Y вершины B: ";
	std::cin >> temp;
	in_coord.insert(in_coord.end(), temp);
	std::cout << "Введите координату X вершины C: ";
	std::cin >> temp;
	in_coord.insert(in_coord.end(), temp);
	std::cout << "Введите координату Y вершины C: ";
	std::cin >> temp;
	in_coord.insert(in_coord.end(), temp);

	return in_coord;
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::vector<Triangle> triangle_entry;
	std::vector <double> input_coordinates;
	std::vector <double> cheking_coordinates;
	int i;
	char command;
	bool exit = false;
	while (!exit)
	{
		std::cout << "\nКомандное меню приветствует вас. Вы можете: \n";
		std::cout << "\t1. Создать запись о треугольнике.\n";
		std::cout << "\t2. Проверить существование треугольника по заданным координатам.\n";
		std::cout << "\t3. Проверить, попадает ли заданная точка в треугольник.\n";
		std::cout << "\t4. Сравнить площадь двух треугольников.\n";
		std::cout << "\t5. Посмотреть записи о треугольниках.\n";
		std::cout << "\t6. Выход из программы.\n";
		std::cout << "Команда: ";
		std::cin >> command;
		std::cin.ignore();
		switch (command)
		{
		case '1':
			input_coordinates = input_coord();
			triangle_entry.push_back(Triangle(input_coordinates[0], input_coordinates[1], input_coordinates[2], input_coordinates[3], input_coordinates[4], input_coordinates[5])); 
			break;
		case '2':
			std::cout << "Введите координаты искомого треугольника: " << std::endl;
			cheking_coordinates = input_coord();
			for (i = 0; i < size(triangle_entry); i++)
			{
				if (triangle_entry[i] == cheking_coordinates)
				{
					std::cout << "Треугольник с такими координатами записан под номером " << i << std::endl;
					break;
				}
			}
			std::cout << "Треугольник с такими координатами не найден." << std::endl;
			break;
		case '3':
			std::cout << "Все имеющиеся в базе треугольники:" << std::endl;
			for (i = 0; i < size(triangle_entry); i++)
			{
				std::cout << "Запись номер " << i << std::endl;
				triangle_entry[i].display_info();
			}
			int triangle_check;
			std::cout << "Попадание точки в который треугольник вы хотите узнать? Введите номера записи." << std::endl;
			std::cout << "Номер треугольника: ";
			std::cin >> triangle_check;

			std::array<double, 2> coord_xy;
			std::cout << "Введите координаты точки, которую вы хотите проверить:" << std::endl;
			std::cout << "Координата X: ";
			std::cin >> coord_xy[0];
			std::cout << std::endl;
			std::cout << "Координата Y: ";
			std::cin >> coord_xy[1];
			std::cout << std::endl;

			if (triangle_entry[triangle_check] == coord_xy)
			{
				std::cout << "Точка попадает в выбранный треугольник или лежит на одной из его граней." << std::endl;
			}
			else
			{
				std::cout << "Точка не попадает в выбранный треугольник." << std::endl;
			}
			break;
		case '4':
			std::cout << "Все имеющиеся в базе треугольники:" << std::endl;
			for (i = 0; i < size(triangle_entry); i++)
			{
				std::cout << "Запись номер " << i << std::endl;
				triangle_entry[i].display_info();
			}
			int triangle_a, triangle_b;
			double triangle_a_S, triangle_b_S;
			std::cout << "Какие два треугольника вы хотите сравнить? Введите номера записи." << std::endl;
			std::cout << "Номер первого треугольника: ";
			std::cin >> triangle_a;
			if (triangle_a >= 0 && triangle_a < size(triangle_entry))
			{
				triangle_a_S = triangle_entry[triangle_a].area_of_triangle();
				std::cout << "Площадь первого треугольника равна " << triangle_a_S << std::endl;
			}
			else
			{
				std::cout << "Введен недопустимый порядковый номер записи!" << std::endl;
				break;
			}
			std::cout << "Номер второго треугольника: ";
			std::cin >> triangle_b;
			if (triangle_b >= 0 && triangle_b < size(triangle_entry))
			{
				triangle_b_S = triangle_entry[triangle_b].area_of_triangle();
				std::cout << "Площадь второго треугольника равна " << triangle_b_S << std::endl;
			}
			else
			{
				std::cout << "Введен недопустимый порядковый номер записи!" << std::endl;
				break;
			}
			if (triangle_entry[triangle_a] == triangle_entry[triangle_b])
			{
				std::cout << "Площади трегольников равны." << std::endl;
			}
			else
			{
				std::cout << "Площади треугольников не равны." << std::endl;
			}
			break;
		case '5':
			for (i = 0; i < size(triangle_entry); i++)
			{
				std::cout << "Запись номер " << i << std::endl;
				triangle_entry[i].display_info();
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
}