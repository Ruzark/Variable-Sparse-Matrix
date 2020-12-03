#pragma once
#ifndef _MATRIX_H_
#define _MATRIX_H_
#define DEBUG
#include <iostream>
#include <locale.h>
#include <string>
#include <fstream>
#include "ConsoleColor.h"

class Matrix
{
public:
	Matrix(); // Конструктор, который задаёт размерность матрицы по умолчанию (3 х 3) 
	~Matrix(); // Деструктор 
	Matrix(int, int); // Конструктор, который задаёт размерность матрицы (n x m)
	Matrix(const Matrix&); // Конструктор копирования 
	void push_back(int, int, double); // Добавляет в конец списка ненулевой коэффициент по координатам x, y 
	void push_front(int, int, double); //Добавляет в начало списка ненулевой коэффициент по координатам x, y
	void pop_front(); // Удаляет самый первый элемент списка
	void remove(int, int); // Удаляет элемент по индексу (x;y);
	void clear(); // Полностью удаляет все данные из списка(с использованием метода pop_front)
	int get_amount(); // Выводит на экран количество ненулевых коэффициентов, возвращает amount_
	void show_matrix(); // Вывести матрицу на экран
	void show_list(); // Просто выводит коэффициенты 
	double get_element(int, int); // берет значение в точке (x;y)
	void set_element(int, int, double); // устанавливает значение в точке (x;y), если такой нет, то добавляет её
	void keyboard_input(Matrix &); // Ввод значений элементов матрицы с клавиатуры 
	void txt_input(std::string); // Ввод значений элементов матрицы из текстового файла
	void txt_output(std::string); // Вывод матрицы в текстовый файл
	void add_matrices(const Matrix &); // Метод, который складывает две матрицы (результат в текущей матрице)
	void add_number(double); // Метод, который прибавляет к матрице число 
	void subtract(const Matrix&); // Метод, которые вычитает матрицы (результат в текущей матрице)
	void subtract(double); // Метод, который вычитает число из матрицы
	void multiply(Matrix& const); // Метод, который умножает матрицы друг на друга (результат в текущей матрице)
	void multiply(double); // Метод, который умножает матрицу на число
	void devide(double); // Метод, который делит каждый элемент матрицы на число
	// Так как нет определения того, когда одна матрица больше другой, я сделал просто проверку по размерности матриц
	bool ComparisionMore(const Matrix &); // Сравнение двух матриц > 
	bool ComparisionLess(const Matrix&); // Сравнение двух матриц <
	double determinant(); // Метод, для нахождения детерминанта матрицы 
	Matrix &operator = (const Matrix &); // Оператор присваивания
	bool operator ==(const Matrix&); // Оператор проверки на равенство
	bool operator !=(const Matrix&); // Оператор проверки на неравенство 
	bool operator >(const Matrix&); // Оператор проверки на >
	bool operator < (const Matrix&); // Оператор проверки на <
	bool operator >= (const Matrix&); // Оператор проверка на >=
	bool operator <= (const Matrix&); // Оператор проверка на <=
	friend std::ostream& operator <<(std::ostream&, Matrix & const); // Перегрузка потока вывода
	friend std::istream& operator >>(std::istream&, Matrix & const); // Перегрузка потока ввода
	Matrix operator + (const Matrix&); // Оператор сложх матриц Matrix + Matrix
	Matrix operator + (const double); // Оператор добавления чиения двусла к матрице Matrix+number
	friend Matrix operator + (const double, const Matrix &); // Оператор добавления числа к матрице number + Matrix 
	Matrix operator * (Matrix& const); // Оператор умножения матрицы на матрицу Matrix * Matrix
	Matrix operator * (const double); // Оператор умножения на число Matrix * number
	friend Matrix operator* (const double, const Matrix&); // Оператор умножения числа на матрицу number * Matrix
	Matrix operator - (const Matrix&); // Оператор, который отнимает одну матрицу, от другой Matrix - Matrix
	Matrix operator - (const double); // Оператор, который отнимает число от матрицы Matrix - number
	Matrix operator /(const double); // Оператор деления на число
private:
	class Node // класс контейнера с данными 
	{
	public:
		Node* pNext; // указатель на следующий контейнер
		int x_, y_; // x- строка, у - столбец;
		double v_; // значение по коориднате (x,y);
		Node(int x, int y, double value, Node* next = nullptr) // Конструктор, который задаёт в контейнере координаты x,y и значение value , а также указатель на следующий (null по умолчанию)
		{
			x_ = x;
			y_ = y;
			v_ = value;
			pNext = next;
		}
	};
	Node* pHead; // Указатель на голову списка 
	int amount_; // Количество ненулевых коэффициентов 
	int n_, m_; // Размерность матрицы
	void show_matrix_demension(); // Вывести на экран размерность матрицы
	void edit_matrix(); // Удаляет нулевые коэффициенты после метода push_back и pop_front
	void cut_matrix(int, int); // Обрезает матрицу до нужных размеров после умножения 
	void expand_matrix(Matrix & const, int, int);  // Метод, нужен для нахождения детерминанта матрицы (разлагает матрицу)

};
#endif

