#include <iostream>
#include <Windows.h>
#include <exception>

const int MAXSIZE = 100; // max размер массива
void pos_multiplication(signed int* arr, int as);
void sum_between_zero(signed int* arr, int as);
void sort_pos_neg(signed int* arr, int as);

class Zero_error
{
private:
    std::string _my_err;

public:
    Zero_error(std::string my_error);
    const char* getError();
};

Zero_error::Zero_error(std::string my_error)
{
    _my_err = my_error;
}

const char* Zero_error::getError()
{
    return _my_err.c_str();
}

int main(void)
{

    setlocale(LC_ALL, "rus");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    system("color f1");

    std::cout << "Введите размер массива, от 1 до 100: ";
    int arrsize;
    std::cin >> arrsize;
    // цикл проверки ввода значения размера массива
    while (arrsize < 1 || arrsize > MAXSIZE)
    {
        std::cout << "\nРазмер массива должен быть в диапазоне от 1 до 100, введите значение еще раз." << std::endl;
        std::cin >> arrsize;
    }
    
    // создание массива под инициализацию
    signed int* arr = new signed int[arrsize];

    char command;
    bool create_arr = false;
    std::cout << "Каким способом вы хотите создать массив? \n";
    std::cout << "\t1. Заполнить его случайными числами.\n";
    std::cout << "\t2. Ввести числа в массив вручную.\n";
    std::cin >> command;
    std::cin.ignore();
    while (!create_arr)
    {
        if (command == '1')
        {
            // заполнение массива случайными числами заданного диапазона (от -99 до 99)
            //srand(time(NULL) || clock());
            for (int i = 0; i < arrsize; i++)
            {
                arr[i] = ((-99) + rand()%198);
            }
            create_arr = true;
        }
        else if (command == '2')
        {
            // заполнение массива с клавиатурного ввода
            std::cout << "\nВведите значения в массив, положительные и отрицательные:" << std::endl;
            for (int i = 0; i < arrsize; i++)
            {
                std::cin >> arr[i];
            }
            create_arr = true;
        }
        else
        {
            std::cout << "\nВы ввели неверную команду, введите 1 или 2." << std::endl;
            std::cin >> command;
        }
    }

    // отображение созданного массива
    std::cout << std::endl;
    std::cout << "Элементы массива:\n";
    for (int i = 0; i < arrsize; i++)
    {
        std::cout << " #" << i << ": " << arr[i];
            if (i % 10 == 0)
            {
                std::cout << std::endl;
            }

    }

    bool exit = false;
    while (!exit)
    {
        std::cout << "\nКак вы хотите обработать массив? \n";
        std::cout << "\t1. Найти прозведение элементов с четными номерами.\n";
        std::cout << "\t2. Найти сумму элементов между первым и последним нулевым элементом.\n";
        std::cout << "\t3. Преобразовать массив, выведя вперед положительные элементы.\n";
        std::cout << "\t4. Выход из программы.\n";
        std::cout << "Команда: ";
        std::cin >> command;
        std::cin.ignore();
        switch (command)
        {
        case '1':
            try
            {
                pos_multiplication(arr, arrsize);
            }
            catch (...)
            {
                std::cout << "Значение произведения слишком большое, переполнение памяти!" << std::endl;
            }
            break;
        case '2':
            try
            {
                sum_between_zero(arr, arrsize);
            }
            catch (Zero_error& error)
            {
                std::cout << "Ошибка выполнения расчетов!" << std::endl;
                std::cerr <<  error.getError() << std::endl;
            }
            break;
        case '3':
            sort_pos_neg(arr, arrsize);
            break;
        case '4':
            exit = true;
            break;
        default:
            std::cout << "Вы ввели некорректную команду. Введите от 1 до 8." << std::endl;
            break;
        }
    }

    delete[] arr;
    return 0;
}

void pos_multiplication(signed int* arr, int as)
{
    // произведение элементов массива с четными номерами
    long long product = 1;
    for (int i = 0; i < as; i += 2)
    {
        product *= arr[i];
        if (product > 9223372036854775807)
        {
            throw "Переполнение памяти!";
        }
    }
    std::cout << "\nПроизведение четных элементов массива равно: " << product << std::endl;
}

void sum_between_zero(signed int* arr, int as)
{
    // ищем первый нулевой элемент
    int first_zero = 0;
    while ((arr[first_zero] != 0) && (first_zero < as))
    {
        first_zero++;
    }

    // ищем последний нулевой элемент
    int last_zero = as;
    while ((arr[last_zero] != 0) && (last_zero > 0))
    {
        last_zero--;
    }

    // проверяем, найдено ли два нуля в массиве
    if ((arr[first_zero] == 0) && (arr[last_zero] == 0) && (first_zero != last_zero))
    {
        int sum = 0;
        while (first_zero != last_zero)
        {
            sum += arr[first_zero];
            first_zero++;
        }
        std::cout << "Сумма чисел между первым и последним 0 равна " << sum << std::endl;
    }
    else if (((arr[first_zero] != 0) && (arr[last_zero] == 0)) || ((arr[first_zero] == 0) && (arr[last_zero] != 0)) || (first_zero == last_zero))
    {
        throw Zero_error("Найдено только одно нулевое значени.");
    }
    else
    {
        throw Zero_error("Не найдено двух нулевых значений!");
    }
}

void sort_pos_neg(signed int* arr, int as)
{
    // создание массива под сортировку
    signed int* postv_negtv = new signed int[as];
    // обнуление массива 
    for (int i = 0; i < as; i++)
    {
        postv_negtv[i] = 0;
    }

    // разбиение значений массива arr на отриц. и положит. числа
    int k = 0;
    int j = (as - 1);
    for (int i = 0; i < as; i++)
    {
        if (arr[i] >= 0)
        {
            postv_negtv[k] = arr[i];
            k++;
        }
        else if (arr[i] < 0)
        {
            postv_negtv[j] = arr[i];
            j--;
        }
    }

    // вывод значений массива 
    std::cout << "\nОтсортированный массив: " << std::endl;
    std::cout << "\nПоложительные числа: \n";

    for (int i = 0; i < as; i++)
    {
        if (postv_negtv[i] >= 0)
        {
            std::cout << postv_negtv[i] << " | ";
            if (i % 10 == 0)
            {
                std::cout << std::endl;
            }
        }
    }
    std::cout << "\nОтрицательные числа: \n";
    for (int i = 0; i < as; i++)
    {
        if (postv_negtv[i] < 0)
        {
            std::cout << postv_negtv[i] << " | ";
            if (i % 10 == 0)
            {
                std::cout << std::endl;
            }
        }
    }
    delete[] postv_negtv;
}
 