#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>		//SetConsoleCP и SetConsoleOutputCP

class Book
{
private:
	std::string _author_name;
	std::string _book_name;
	int _year_of_creation = 0;
	char _letter = 0;

public:
	Book();
	Book(std::string author, std::string book, int year);
	Book(std::string author, std::string book);
	Book(std::string book, int year);
	Book(char first_letter, std::string book);
	~Book();

	void set_author(std::string author);
	void set_book(std::string book);
	void set_year(int year);

	void display_info();
};

Book::Book()
{
	_year_of_creation = 0;
	_letter = 0;
}

Book::Book(std::string author, std::string book, int year)
{
	this->_author_name = author;
	this->_book_name = book;
	this->_year_of_creation = year;
	_letter = 0;
}

Book::Book(std::string author, std::string book)
{
	this->_author_name = author;
	this->_book_name = book;
	_year_of_creation = 0;
	_letter = 0;
}

Book::Book(std::string book, int year)
{
	this->_book_name = book;
	this->_year_of_creation = year;
	_letter = 0;
}

Book::Book(char first_letter, std::string book)
{
	this->_letter = first_letter;
	this->_book_name = book;
	_year_of_creation = 0;
}

Book::~Book()
{

}

void Book::set_author(std::string author)
{
	if (_letter !=0)
	{
		char first_letter = author[0];
		if (_letter == first_letter)
		{
			this->_author_name = author;
		}
		else
		{
			std::cout << "Введено неверное имя автора." << std::endl;
		}
	}
	else if (_letter == 0)
	{
		this->_author_name = author;
	}
}

void Book::set_book(std::string book)
{
	this->_book_name = book;
}

void Book::set_year(int year)
{
	this->_year_of_creation = year;
}

void Book::display_info()
{
	if (!empty(_author_name))
	{
		std::cout << "Автор книги: " << _author_name << std::endl;
	}
	if (!empty(_book_name))
	{
		std::cout << "Название книги: " << _book_name << std::endl;
	}
	if (_year_of_creation != 0)
	{
		std::cout << "Год выпуска книги: " << _year_of_creation << std::endl;
	}

	std::cout << "-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
}

std::string enter_author()
{
	std::string name;
	std::cout << "Введите имя автора:" << std::endl;
	getline(std::cin, name);
	return name;
}

std::string enter_book()
{
	std::string name;
	std::cout << "Введите название книги:" << std::endl;
	getline(std::cin, name);
	return name;
}

int enter_year()
{
	int year;
	std::cout << "Введите год выпуска книги:" << std::endl;
	std::cin >> year;
	return year;
}

char first_letter()
{
	char letter;
	std::cout << "Введите первую букву имени автора:" << std::endl;
	std::cin >> letter;
	std::cin.ignore();
	return letter;
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	std::vector<Book> books_entry;
	std::string author, name;
	int year, book_index, i;
	char letter;

	bool exit = false;
	char command;
	while (!exit)
	{
		std::cout << "\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n";
		std::cout << "Что вы хотите сделать?:\n";
		std::cout << "\t1. Создать запись о книге.\n";
		std::cout << "\t2. Создать запись о книге с полными данными - автор, название, год выпуска.\n";
		std::cout << "\t3. Создать запись о книге с частичными данными - имя автора и название книги.\n";
		std::cout << "\t4. Создать запись о книге с частичными данными - название книги и год выпуска.\n";
		std::cout << "\t5. Создать запись о книге с частичными данными - первая буква имени автора и название книги.\n";
		std::cout << "\t6. Редактировать запись о книге - изменить или ввести автора книги.\n";
		std::cout << "\t7. Редактировать запись о книге - изменить или ввести название книги.\n";
		std::cout << "\t8. Редактировать запись о книге - изменить или ввести год выпуска книги.\n";
		std::cout << "\t9. Посмотреть данные о записанных книгах.\n";
		std::cout << "\t0. Выход из программы\n";
		std::cout << "Команда: ";
		std::cin >> command;
		std::cin.ignore();
		switch (command)
		{
		case '1':
			books_entry.push_back(Book());
			break;

		case '2':
			author = enter_author();
			name = enter_book();
			year = enter_year();
			books_entry.push_back(Book(author, name, year));
			break;

		case '3':
			author = enter_author();
			name = enter_book();
			books_entry.push_back(Book(author, name));
			break;

		case '4':
			name = enter_book();
			year = enter_year();
			books_entry.push_back(Book(name, year));
			break;

		case '5':
			letter = first_letter();
			name = enter_book();
			books_entry.push_back(Book(letter, name));
			break;

		case '6':
			for (i = 0; i < size(books_entry); i++)
			{
				std::cout << i << " ";
				books_entry[i].display_info();
			}
			std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
			std::cin >> book_index;
			std::cin.ignore();
			if (book_index >= 0 && book_index < size(books_entry))
			{
				author = enter_author();
				books_entry[book_index].set_author(author);
			}
			else
			{
				std::cout << "Введен неверный номер записи." << std::endl;
			}
			break;

		case '7':
			for (i = 0; i < size(books_entry); i++)
			{
				std::cout << i << " ";
				books_entry[i].display_info();
			}
			std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
			std::cin >> book_index;
			std::cin.ignore();
			if (book_index >= 0 && book_index < size(books_entry))
			{
				name = enter_book();
				books_entry[book_index].set_book(name);
			}
			else
			{
				std::cout << "Введен неверный номер записи." << std::endl;
			}
			break;

		case '8':
			for (i = 0; i < size(books_entry); i++)
			{
				std::cout << i << " ";
				books_entry[i].display_info();
			}
			std::cout << "Для которой по номеру записи вы хотите изменить данные?\n";
			std::cin >> book_index;
			std::cin.ignore();
			if (book_index >= 0 && book_index < size(books_entry))
			{
				year = enter_year();
				books_entry[book_index].set_year(year);
			}
			else
			{
				std::cout << "Введен неверный номер записи." << std::endl;
			}
			break;

		case '9':
			for (i = 0; i < size(books_entry); i++)
			{
				books_entry[i].display_info();
			}
			break;

		case '0':
			exit = true;
			break;

		default:
			std::cout << "Вы ввели некорректную команду. Введите от 0 до 9." << std::endl;
			break;
		}
	}
	return 0;
}