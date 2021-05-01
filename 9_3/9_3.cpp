//	Звітна відомість результатів екзаменаційної сесії студентської групи для кожного
//	студента містить прізвище, ініціали і оцінки з п’яти предметів.
//	Скласти програму, за допомогою якої можна корегувати список(добавляти, вилучати, редагувати інформацію) і отримувати :
//	 список всіх студентів;
//	 список студентів, що склали іспити тільки на «5»;
//	 список студентів, що мають трійки;
//	 список студентів, що мають двійки. При цьому студент, що має більш ніж одну двійку, виключається із списку.

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

struct Rep // Звіт 
{
	char surname[100]; // прізвище
	char init[100]; // ініціали
	double fiz; // оцінки з 5 предметів
	double math;  
	double prog;
	double web;
	double elect;
};

void Create(Rep* p, int N);
void Print(Rep* p, const int N);
void EditRep(Rep* &p, int &N);
void AddStud(Rep* &p, int &N);
void EditStudent(Rep*& p, int& N);
void DelStudent(Rep*& p, int& N, int numb);
void StudMax(Rep* p, const int N);
bool StudThree(Rep* p, const int N);
void StudTwo(Rep* p, const int N);

int main()
{
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
	int N;
	cout << "Введіть загальну кількість студентів: "; cin >> N;
	Rep* p = new Rep[N]; // створення посилання на об'єкт типу Rep
	Create(p, N);
	char ch;
	string store;
	do
	{
		cout << endl;
		cout << "Зробіть вибір:" << endl;
		cout << "[1] - перезаписати дані" << endl;
		cout << "[2] - зміна даних" << endl;
		cout << "[3] - список всіх студентів;" << endl;
		cout << "[4] - список студентів, що склали іспити тільки на «5»;" << endl;
		cout << "[5] - список студентів, що мають трійки;" << endl;
		cout << "[6] - список студентів, що мають одну двійку;" << endl << endl;

		cout << "[0] - завершення роботи." << endl << endl;
		cout << "Ваш вибір: "; cin >> ch;
		switch (ch)
		{
		case '0':
			break;
		case '1':
			cout << "Введіть загальну кількість студентів: "; cin >> N;
			Create(p, N);
			break;
		case '2':
			EditRep(p, N);
			break;
		case '3':
			Print(p, N);
			break;
		case '4':
			cout << endl;
			cout << "Студенти, що склали всі екзамени на макс. бал: " << endl;
			StudMax(p, N);
			break;
		case '5':
			cout << endl;
			cout << "Студенти, що мають хоча б одну трійку: " << endl;
			StudThree(p, N);
			break;
		case '6':
			cout << endl;
			cout << "Студенти, що мають одну двійку: " << endl;
			StudTwo(p, N);
			break;
		default:
			cout << "Помилка вводу! ";
		}
	} while (ch != '0');
	return 0;
}

void Create(Rep* p, int N) // створення файлу з введених рядків
{
	for (int i = 0; i < N; i++) {
		cout << endl;
		cout << "Студент № " << i + 1 << ":" << endl;
		cout << "Прізвище студента: "; cin >> p[i].surname;
		cout << "Ініціали: "; cin >> p[i].init;
		cout << "Оцінка з Фізики: "; cin >> p[i].fiz;
		if (p[i].fiz > 5) {
			cout << "Оцінка розпізнана, як максимальна" << endl << endl;
			p[i].fiz = 5;
		}
		if (p[i].fiz < 0) {
			cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
			p[i].fiz = 0;
		}
		cout << "Оцінка з Математики: "; cin >> p[i].math;
		if (p[i].math > 5) {
			cout << "Оцінка розпізнана, як максимальна" << endl << endl;
			p[i].math = 5;
		}
		if (p[i].math < 0) {
			cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
			p[i].math = 0;
		}
		cout << "Оцінка з Програмування: "; cin >> p[i].prog;
		if (p[i].prog > 5) {
			cout << "Оцінка розпізнана, як максимальна" << endl << endl;
			p[i].prog = 5;
		}
		if (p[i].prog < 0) {
			cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
			p[i].prog = 0;
		}
		cout << "Оцінка з Веб - дизайну: "; cin >> p[i].web;
		if (p[i].web > 5) {
			cout << "Оцінка розпізнана, як максимальна" << endl << endl;
			p[i].web = 5;
		}
		if (p[i].web < 0) {
			cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
			p[i].web = 0;
		}
		cout << "Оцінка з Електромеханіки: "; cin >> p[i].elect; 
		if (p[i].elect > 5) {
			cout << "Оцінка розпізнана, як максимальна" << endl << endl;
			p[i].elect = 5;
		}
		if (p[i].elect < 0) {
			cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
			p[i].elect = 0;
		}
		cout << endl;
	}
	cout << endl;
}

void Print(Rep* p, const int N) // виведення файлу на екран
{
	cout << "=================================================================================================================="
		<< endl;
	cout << "|  №  |  Прізвище  |  Ініціали  |  Фізика  |  Математика  |  Програмування  |  Веб - дизайн  |  Електромеханіка  |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "|" << setw(3) << i + 1 << setw(3) << "|";
		cout << setw(6) << p[i].surname << setw(7) << "|";
		cout << setw(6) << p[i].init << setw(7) << "|";
		cout << setw(5) << p[i].fiz << setw(6) <<  "|";
		cout << setw(7) << p[i].math << setw(8) << "|";
		cout << setw(9) << p[i].prog << setw(9) << "|";
		cout << setw(8) << p[i].web << setw(9) << "|";
		cout << setw(10) << p[i].elect << setw(10) << "|";
		cout << endl;
	}
	cout << "=================================================================================================================="
		<< endl;
	cout << endl;
}

void EditRep(Rep* &p, int &N) {
	char ch;
	cout << endl << endl;
	cout << "[1] - добавити нового студента" << endl;
	cout << "[2] - редагувати інформацію про студента" << endl;
	cout << "[3] - вилучити інформацію про студента" << endl << endl;

	cout << "[0] - повернутись назад" << endl << endl;
	cout << "Ваш вибір: "; cin >> ch;
	switch (ch) {
	case '0':
		return;
		break;
	case '1':
		AddStud(p, N);
		break;
	case '2':
		EditStudent(p, N);
		break;
	case '3':
		int numb;
		cout << "Введіть номер студента, якого потрібно видалити: "; cin >> numb;
		numb--;
		DelStudent(p, N, numb);
		cout << "Інформація про студента видалена!" << endl;
		break;
	default:
		cout << "Помилка вводу! " << endl;
	}
}

void AddStud(Rep* &p, int &N) {
	Rep* temp = new Rep[N]; // оголошується тимчасова допоміжна структура
	for (int i = 0; i < N; i++) {
		temp[i] = p[i]; // всі данні копіюються в нову структуру
	}
	delete[] p; // видаляється стара структура
	N++; // збільшення змінної, яка відповідає за кількість студентів 
	Rep* s = new Rep[N]; // ще одна допоміжна структура 
	p = s; // копіювання розширеної структури в основну
	for (int i = 0; i < N; i++) { 
		p[i] = temp[i]; // копіювання данних в розширену структуру
	}
	int i = N - 1; // визначення місця, куди слід записувати 
	cout << endl; // далі запис про нового студента
	cout << endl;
	cout << "Студент № " << i + 1 << ":" << endl;
	cout << "Прізвище студента: "; cin >> p[i].surname;
	cout << "Ініціали: "; cin >> p[i].init;
	cout << "Оцінка з Фізики: "; cin >> p[i].fiz;
	if (p[i].fiz > 5) {
		cout << "Оцінка розпізнана, як максимальна" << endl << endl;
		p[i].fiz = 5;
	}
	if (p[i].fiz < 0) {
		cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
		p[i].fiz = 0;
	}
	cout << "Оцінка з Математики: "; cin >> p[i].math;
	if (p[i].math > 5) {
		cout << "Оцінка розпізнана, як максимальна" << endl << endl;
		p[i].math = 5;
	}
	if (p[i].math < 0) {
		cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
		p[i].math = 0;
	}
	cout << "Оцінка з Програмування: "; cin >> p[i].prog;
	if (p[i].prog > 5) {
		cout << "Оцінка розпізнана, як максимальна" << endl << endl;
		p[i].prog = 5;
	}
	if (p[i].prog < 0) {
		cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
		p[i].prog = 0;
	}
	cout << "Оцінка з Веб - дизайну: "; cin >> p[i].web;
	if (p[i].web > 5) {
		cout << "Оцінка розпізнана, як максимальна" << endl << endl;
		p[i].web = 5;
	}
	if (p[i].web < 0) {
		cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
		p[i].web = 0;
	}
	cout << "Оцінка з Електромеханіки: "; cin >> p[i].elect;
	if (p[i].elect > 5) {
		cout << "Оцінка розпізнана, як максимальна" << endl << endl;
		p[i].elect = 5;
	}
	if (p[i].elect < 0) {
		cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
		p[i].elect = 0;
	}
	cout << endl;
}

void EditStudent(Rep*& p, int& N) {
	int numb;
	cout << "Введіть номер студента для редагування: "; cin >> numb;
	int i = numb - 1; // номер студента, оскільки в списку все починається з 0 
	cout << endl;
	cout << "Студент № " << i + 1 << ":" << endl;
	cout << "Прізвище студента: "; cin >> p[i].surname;
	cout << "Ініціали: "; cin >> p[i].init;
	cout << "Оцінка з Фізики: "; cin >> p[i].fiz;
	if (p[i].fiz > 5) {
		cout << "Оцінка розпізнана, як максимальна" << endl << endl;
		p[i].fiz = 5;
	}
	if (p[i].fiz < 0) {
		cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
		p[i].fiz = 0;
	}
	cout << "Оцінка з Математики: "; cin >> p[i].math;
	if (p[i].math > 5) {
		cout << "Оцінка розпізнана, як максимальна" << endl << endl;
		p[i].math = 5;
	}
	if (p[i].math < 0) {
		cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
		p[i].math = 0;
	}
	cout << "Оцінка з Програмування: "; cin >> p[i].prog;
	if (p[i].prog > 5) {
		cout << "Оцінка розпізнана, як максимальна" << endl << endl;
		p[i].prog = 5;
	}
	if (p[i].prog < 0) {
		cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
		p[i].prog = 0;
	}
	cout << "Оцінка з Веб - дизайну: "; cin >> p[i].web;
	if (p[i].web > 5) {
		cout << "Оцінка розпізнана, як максимальна" << endl << endl;
		p[i].web = 5;
	}
	if (p[i].web < 0) {
		cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
		p[i].web = 0;
	}
	cout << "Оцінка з Електромеханіки: "; cin >> p[i].elect;
	if (p[i].elect > 5) {
		cout << "Оцінка розпізнана, як максимальна" << endl << endl;
		p[i].elect = 5;
	}
	if (p[i].elect < 0) {
		cout << "Оцінка розпізнана, як мінімальна" << endl << endl;
		p[i].elect = 0;
	}
	cout << endl;
}

void DelStudent(Rep*& p, int& N, int numb) {
	Rep* temp = new Rep[N]; // оголошується тимчасова допоміжна структура
	for (int i = 0; i < N; i++) {
		temp[i] = p[i]; // всі данні копіюються в нову структуру
	}
	
	delete[] p;

	Rep* s = new Rep[N - 1]; // допоміжна зменьшена структура данних оголошується
	p = s; // основна структу стає зменьшеною структурою
	int j = 0; // оголошується хід зменьшеної структури
	for (int i = 0; i < N; i++) {
		if (i != numb) { // перевірка на номер студента, якого потрібно видалити
			p[j] = temp[i]; // копіювання данних в зменьшену структуру
			j++; // хід зменьшеної структури данних
		} 
	}
	N--; // Зменьшення змінної, оскільки кількість студентів зменьшилась
}

void StudMax(Rep* p, const int N) 
{
	cout << "=================================================================================================================="
		<< endl;
	cout << "|  №  |  Прізвище  |  Ініціали  |  Фізика  |  Математика  |  Програмування  |  Веб - дизайн  |  Електромеханіка  |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------------"
		<< endl;
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].math == 5.0 &&
			p[i].fiz == 5.0 &&
			p[i].prog == 5.0 &&
			p[i].web == 5.0 &&
			p[i].elect == 5.0) { // первірка на студента, який здав все на макс. бал
			cout << "|" << setw(3) << i + 1 << setw(3) << "|";
			cout << setw(6) << p[i].surname << setw(7) << "|";
			cout << setw(6) << p[i].init << setw(7) << "|";
			cout << setw(5) << p[i].fiz << setw(6) << "|";
			cout << setw(7) << p[i].math << setw(8) << "|";
			cout << setw(9) << p[i].prog << setw(9) << "|";
			cout << setw(8) << p[i].web << setw(9) << "|";
			cout << setw(10) << p[i].elect << setw(10) << "|";
			cout << endl;
			k++;
		}
	}
	if (k == 0) {
		cout << endl;
		cout << "Схоже, що по заданому фільтру студентів не було знайдено." << endl << endl;
	}
	cout << "=================================================================================================================="
		<< endl;
	cout << endl;
}

bool StudThree(Rep* p, const int N) {
	cout << "=================================================================================================================="
		<< endl;
	cout << "|  №  |  Прізвище  |  Ініціали  |  Фізика  |  Математика  |  Програмування  |  Веб - дизайн  |  Електромеханіка  |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------------"
		<< endl;
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].math == 3.0 ||
			p[i].fiz == 3.0 ||
			p[i].prog == 3.0 ||
			p[i].web == 3.0 ||
			p[i].elect == 3.0) { // первірка на студента, який має хоча б одну 3
			cout << "|" << setw(3) << i + 1 << setw(3) << "|";
			cout << setw(6) << p[i].surname << setw(7) << "|";
			cout << setw(6) << p[i].init << setw(7) << "|";
			cout << setw(5) << p[i].fiz << setw(6) << "|";
			cout << setw(7) << p[i].math << setw(8) << "|";
			cout << setw(9) << p[i].prog << setw(9) << "|";
			cout << setw(8) << p[i].web << setw(9) << "|";
			cout << setw(10) << p[i].elect << setw(10) << "|";
			cout << endl;
			k++;
		}
	}
	if (k == 0) {
		cout << endl;
		cout << "Схоже, що по заданому фільтру студентів не було знайдено." << endl << endl;
		return false;
	}
	cout << "=================================================================================================================="
		<< endl;
	cout << endl;
	return true;
}

void StudTwo(Rep* p, const int N) {
	cout << "=================================================================================================================="
		<< endl;
	cout << "|  №  |  Прізвище  |  Ініціали  |  Фізика  |  Математика  |  Програмування  |  Веб - дизайн  |  Електромеханіка  |"
		<< endl;
	cout << "------------------------------------------------------------------------------------------------------------------"
		<< endl;
	int k = 0; // оголошення лічильника двійок
	for (int i = 0; i < N; i++)
	{
		if (p[i].elect == 2.0) {
			k++;
		}
		if (p[i].web == 2.0) {
			k++;
		}
		if (p[i].prog == 2.0) {
			k++;
		}
		if (p[i].fiz == 2.0) {
			k++;
		}
		if (p[i].math == 2.0) {
			k++;
		}
		if (k == 1) { // перевірка на кількість двійок
			cout << "|" << setw(3) << i + 1 << setw(3) << "|";
			cout << setw(6) << p[i].surname << setw(7) << "|";
			cout << setw(6) << p[i].init << setw(7) << "|";
			cout << setw(5) << p[i].fiz << setw(6) << "|";
			cout << setw(7) << p[i].math << setw(8) << "|";
			cout << setw(9) << p[i].prog << setw(9) << "|";
			cout << setw(8) << p[i].web << setw(9) << "|";
			cout << setw(10) << p[i].elect << setw(10) << "|";
			cout << endl;
		}
		k = 0;
	}
		cout << "=================================================================================================================="
			<< endl;
		cout << endl;
}