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
	Matrix(); // �����������, ������� ����� ����������� ������� �� ��������� (3 � 3) 
	~Matrix(); // ���������� 
	Matrix(int, int); // �����������, ������� ����� ����������� ������� (n x m)
	Matrix(const Matrix&); // ����������� ����������� 
	void push_back(int, int, double); // ��������� � ����� ������ ��������� ����������� �� ����������� x, y 
	void push_front(int, int, double); //��������� � ������ ������ ��������� ����������� �� ����������� x, y
	void pop_front(); // ������� ����� ������ ������� ������
	void remove(int, int); // ������� ������� �� ������� (x;y);
	void clear(); // ��������� ������� ��� ������ �� ������(� �������������� ������ pop_front)
	int get_amount(); // ������� �� ����� ���������� ��������� �������������, ���������� amount_
	void show_matrix(); // ������� ������� �� �����
	void show_list(); // ������ ������� ������������ 
	double get_element(int, int); // ����� �������� � ����� (x;y)
	void set_element(int, int, double); // ������������� �������� � ����� (x;y), ���� ����� ���, �� ��������� �
	void keyboard_input(Matrix &); // ���� �������� ��������� ������� � ���������� 
	void txt_input(std::string); // ���� �������� ��������� ������� �� ���������� �����
	void txt_output(std::string); // ����� ������� � ��������� ����
	void add_matrices(const Matrix &); // �����, ������� ���������� ��� ������� (��������� � ������� �������)
	void add_number(double); // �����, ������� ���������� � ������� ����� 
	void subtract(const Matrix&); // �����, ������� �������� ������� (��������� � ������� �������)
	void subtract(double); // �����, ������� �������� ����� �� �������
	void multiply(Matrix& const); // �����, ������� �������� ������� ���� �� ����� (��������� � ������� �������)
	void multiply(double); // �����, ������� �������� ������� �� �����
	void devide(double); // �����, ������� ����� ������ ������� ������� �� �����
	// ��� ��� ��� ����������� ����, ����� ���� ������� ������ ������, � ������ ������ �������� �� ����������� ������
	bool ComparisionMore(const Matrix &); // ��������� ���� ������ > 
	bool ComparisionLess(const Matrix&); // ��������� ���� ������ <
	double determinant(); // �����, ��� ���������� ������������ ������� 
	Matrix &operator = (const Matrix &); // �������� ������������
	bool operator ==(const Matrix&); // �������� �������� �� ���������
	bool operator !=(const Matrix&); // �������� �������� �� ����������� 
	bool operator >(const Matrix&); // �������� �������� �� >
	bool operator < (const Matrix&); // �������� �������� �� <
	bool operator >= (const Matrix&); // �������� �������� �� >=
	bool operator <= (const Matrix&); // �������� �������� �� <=
	friend std::ostream& operator <<(std::ostream&, Matrix & const); // ���������� ������ ������
	friend std::istream& operator >>(std::istream&, Matrix & const); // ���������� ������ �����
	Matrix operator + (const Matrix&); // �������� ����� ������ Matrix + Matrix
	Matrix operator + (const double); // �������� ���������� ������ ������ � ������� Matrix+number
	friend Matrix operator + (const double, const Matrix &); // �������� ���������� ����� � ������� number + Matrix 
	Matrix operator * (Matrix& const); // �������� ��������� ������� �� ������� Matrix * Matrix
	Matrix operator * (const double); // �������� ��������� �� ����� Matrix * number
	friend Matrix operator* (const double, const Matrix&); // �������� ��������� ����� �� ������� number * Matrix
	Matrix operator - (const Matrix&); // ��������, ������� �������� ���� �������, �� ������ Matrix - Matrix
	Matrix operator - (const double); // ��������, ������� �������� ����� �� ������� Matrix - number
	Matrix operator /(const double); // �������� ������� �� �����
private:
	class Node // ����� ���������� � ������� 
	{
	public:
		Node* pNext; // ��������� �� ��������� ���������
		int x_, y_; // x- ������, � - �������;
		double v_; // �������� �� ���������� (x,y);
		Node(int x, int y, double value, Node* next = nullptr) // �����������, ������� ����� � ���������� ���������� x,y � �������� value , � ����� ��������� �� ��������� (null �� ���������)
		{
			x_ = x;
			y_ = y;
			v_ = value;
			pNext = next;
		}
	};
	Node* pHead; // ��������� �� ������ ������ 
	int amount_; // ���������� ��������� ������������� 
	int n_, m_; // ����������� �������
	void show_matrix_demension(); // ������� �� ����� ����������� �������
	void edit_matrix(); // ������� ������� ������������ ����� ������ push_back � pop_front
	void cut_matrix(int, int); // �������� ������� �� ������ �������� ����� ��������� 
	void expand_matrix(Matrix & const, int, int);  // �����, ����� ��� ���������� ������������ ������� (��������� �������)

};
#endif

