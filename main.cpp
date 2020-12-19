#include "Matrix.h"
int main()
{
	setlocale(LC_ALL, "rus");
	Matrix a;
	a.txt_input("matrix.txt");
    a.show_matrix();
	Matrix b;
	b.txt_input("matrix2.txt");
	b.show_matrix();
	Matrix c(4, 4);
	c.push_back(0, 0, 2);
	CycledList<Matrix> z;
	std::cin >> z;
	z.push(c);
	z.show();
	std::cout << a + b << std::endl;
	system("pause");
	return 0;
}