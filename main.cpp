#include "Matrix.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Matrix a;
	a.txt_input("matrix.txt");
    a.show_matrix();
	Matrix b;
	b.txt_input("matrix2.txt");
	int z = 10;
	int f = 20;
	std::cout << a + b << std::endl;
	system("pause");
	return 0;
}