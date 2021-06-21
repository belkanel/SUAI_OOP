#include <iostream>
#include <limits>
#include <cmath>

class equation
{
private:
    double _k = 0;
    double _b = 0;

public:
    void set_k(double k);
    double get_k();
    void set_b(double b);
    double get_b();
    double Root(double x, int variation);
    void graph();
};

void equation::set_k(double k)
{
    _k = k;
}

double equation::get_k()
{
    return _k;
}

void equation::set_b(double b)
{
    _b = b;
}

double equation::get_b()
{
    return _b;
}

double equation::Root(double x, int variation)
{
    if (_k == 0 && _b == 0)
    {
        return std::numeric_limits<double>::quiet_NaN();
    }
    if (variation == 0)
    {
        return (_k * x) + _b;
    }
    else if (variation == 1)
    {
        return (_b - x) / _k;
    }
}

void equation::graph()
{
    if (_k > 0 && _b != 0)
    {
        std::cout << "График имеет наклон направо." << std::endl;
    }
    else if (_k < 0 && _b != 0)
    {
        std::cout << "График имеет наклон влево." << std::endl;
    }
    else if (_k == 0 && _b != 0)
    {
        std::cout << "Уравнение имеет вид y=b, график параллелен оси X." << std::endl;
    }
    else if (_k > 0 && _b == 0)
    {
        std::cout << "График имеет наклон направо и проходит через начало координат." << std::endl;
    }
    else if (_k < 0 && _b == 0)
    {
        std::cout << "График имеет наклон влево и проходит через начало координат." << std::endl;
    }
    else if (_k == 0 && _b == 0)
    {
        std::cout << "Уравнение не имеет решения." << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    double coef_k, coef_b;

    equation zero;

    std::cout << "Введите коэффицент k = ";
    std::cin >> coef_k;
    zero.set_k(coef_k);

    std::cout << "Введите коэффицент b = ";
    std::cin >> coef_b;
    zero.set_b(coef_b);

    bool exit = false;
    char command;
    int variation;
    double x_or_y;

    while (!exit)
    {
        std::cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
        std::cout << "Что вы хотите сделать?:\n";
        std::cout << "\t1. Узнать вид графика.\n";
        std::cout << "\t2. Вычислить значение y при известном x.\n";
        std::cout << "\t3. Вычислить значение x при известном y.\n";
        std::cout << "\t4. Выход из программы\n";
        std::cout << "Команда: ";
        std::cin >> command;
        switch (command)
        {
        case '1':
            zero.graph();
            break;

        case '2':
            if (zero.get_k() == 0 && zero.get_b() != 0)
            {
                std::cout << "Уравнение имеет вид y=b, на любом x значение y равно b= " << zero.get_b();
                break;
            }
            variation = 0;
            std::cout << "Введите значение X = ";
            std::cin >> x_or_y;
            if (std::isnan(zero.Root(x_or_y, variation)))
            {
                std::cout << "Уравнение не имеет решений." << std::endl;
                break;
            }
            std::cout << "Y равен " << zero.Root(x_or_y, variation) << std::endl;
            break;

        case '3':
            if (zero.get_k() == 0 && zero.get_b() != 0)
            {
                std::cout << "В данном уравнении значение y всегда равно b, а x = 0.";
                break;
            }
            variation = 1;
            std::cout << "Введите значение Y = ";
            std::cin >> x_or_y;
            if (std::isnan(zero.Root(x_or_y, variation)))
            {
                std::cout << "Уравнение не имеет решений." << std::endl;
                break;
            }
            std::cout << "X равен " << zero.Root(x_or_y, variation) << std::endl;
            break;

        case '4':
            exit = true;
            break;

        default:
            std::cout << "Вы ввели некорректную команду. Введите от 1 до 4." << std::endl;
            break;
        }
    }
    return 0;
}