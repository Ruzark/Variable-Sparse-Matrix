#include "Matrix.h"

Matrix::Matrix()
{
	n_ = 3;
	m_ = 3;
	amount_ = 0;
	pHead = nullptr;
#ifdef DEBUG
	std::cout << yellow << "Вызвался конструктор " << blue << this << white << std::endl;
	std::cout << std::endl;
#endif

}

Matrix::~Matrix()
{
	clear();
#ifdef DEBUG
	std::cout << std::endl;
	std::cout << yellow << "Вызвался деструктор " << blue << this << white << std::endl;
	std::cout << std::endl;
#endif
}

Matrix::Matrix(int n, int m)
{
	n_ = n;
	m_ = m;
	amount_ = 0;
	pHead = nullptr;
}

Matrix::Matrix(const Matrix& other)
{
	pHead = nullptr;
	Node* first = pHead;
	Node* second = other.pHead;
	amount_ = 0;
	n_ = other.n_;
	m_ = other.m_;
	if (second == nullptr and first == nullptr)
	{
		pHead = other.pHead;
	}
	if (second != nullptr and first == nullptr)
	{
		int tmp_amount = other.amount_;
		do
		{
			push_back(second->x_, second->y_, second->v_);
			second = second->pNext;
			tmp_amount--;
		} while (tmp_amount != 0);
	}
#ifdef DEBUG
	std::cout << yellow << "Вызвался конструктор копирования " << blue << this << white << std::endl;
	std::cout << std::endl;
#endif
}

void Matrix::push_back(int x, int y, double value)
{
	if (value == 0.0)
	{
		return;
	}
	if (x >= n_ and y >= m_)
	{
		std::cout << red << "Ошибка при добавлении элемента " << "x: " << blue << x << red << " y: " << blue << y << red <<" value: "<< blue << value << red<< " в матрицу " << blue << this << red << "\nУказанные координаты больше, чем размерность вашей матрицы!" << white << std::endl;
		show_matrix_demension();
		std::cout << std::endl;
		return;
	}
	if (x >= n_)
	{
		std::cout << red << "Ошибка при добавлении элемента " << "x: " << blue << x << red << " y: " << blue << y << red << " value: " << blue << value << red << " в матрицу " << blue << this << red << "\nУказанная координата x больше, чем размерность вашей матрицы!" << white << std::endl;
		show_matrix_demension();
		std::cout << std::endl;
		return;
	}
	if (y >= m_)
	{
		std::cout << red << "Ошибка при добавлении элемента " << "x: " << blue << x << red << " y: " << blue << y << red << " value: " << blue << value << red << " в матрицу " << blue << this << red << "\nУказанная координата y больше, чем размерность вашей матрицы!" << white << std::endl;
		show_matrix_demension();
		std::cout << std::endl;
		return;
	}
	if (x < 0 and y < 0)
	{
		std::cout << red << "Ошибка при добавлении элемента " << "x: " << blue << x << red << " y: " << blue << y << red << " value: " << blue << value << red << " в матрицу " << blue << this << red << "\nУказанные координаты меньше, чем размерность вашей матрицы!" << white << std::endl;
		show_matrix_demension();
		std::cout << std::endl;
		return;
	}
	if (x < 0)
	{
		std::cout << red << "Ошибка при добавлении элемента " << "x: " << blue << x << red << " y: " << blue << y << red << " value: " << blue << value << red << " в матрицу "<<blue << this <<red << "\nУказанная координата x меньше, чем размерность вашей матрицы!" << white << std::endl;
		show_matrix_demension();
		std::cout << std::endl;
		return;
	}
	if (y < 0)
	{
		std::cout << red << "Ошибка при добавлении элемента " << "x: " << blue << x << red << " y: " << blue << y << red << " value: " << blue << value << red << " в матрицу "<<blue <<this<<red <<"\nУказанная координата y меньше, чем размерность вашей матрицы!" << white << std::endl;
		std::cout << std::endl;
		show_matrix_demension();
		std::cout << std::endl;
		return;
	}
	if (pHead == nullptr)
	{
		pHead = new Node(x, y, value);
		amount_++;
	}
	else
	{
		bool check = false;
		Node* temp = pHead;
		do
		{
			if (temp->x_ == x and temp->y_ == y)
			{
				check = true;
				break;
			}
			else
			{
				temp = temp->pNext;
			}
		} while (temp != nullptr);
		if (check == true)
		{
			temp->v_ = value;
		}
		else
		{
			Node* current = pHead;
			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new Node(x, y, value);
			amount_++;
		}
		
	}
	edit_matrix();
	
}

void Matrix::push_front(int x, int y, double value)
{
	if (value == 0)
	{
		return;
	}
	if (x >= n_ and y >= m_)
	{
		std::cout << red << "Ошибка при добавлении элемента " << "x: " << blue << x << red << " y: " << blue << y << red << " value: " << blue << value << red << " в матрицу " << blue << this << red << "\nУказанные координаты больше, чем размерность вашей матрицы!" << white << std::endl;
		show_matrix_demension();
		std::cout << std::endl;
		return;
	}
	if (x >= n_)
	{
		std::cout << red << "Ошибка при добавлении элемента " << "x: " << blue << x << red << " y: " << blue << y << red << " value: " << blue << value << red << " в матрицу " << blue << this << red << "\nУказанная координата x больше, чем размерность вашей матрицы!" << white << std::endl;
		show_matrix_demension();
		std::cout << std::endl;
		return;
	}
	if (y >= m_)
	{
		std::cout << red << "Ошибка при добавлении элемента " << "x: " << blue << x << red << " y: " << blue << y << red << " value: " << blue << value << red << " в матрицу " << blue << this << red << "\nУказанная координата y больше, чем размерность вашей матрицы!" << white << std::endl;
		show_matrix_demension();
		std::cout << std::endl;
		return;
	}
	if (x < 0 and y < 0)
	{
		std::cout << red << "Ошибка при добавлении элемента " << "x: " << blue << x << red << " y: " << blue << y << red << " value: " << blue << value << red << " в матрицу " << blue << this << red << "\nУказанные координаты меньше, чем размерность вашей матрицы!" << white << std::endl;
		show_matrix_demension();
		std::cout << std::endl;
		return;
	}
	if (x < 0)
	{
		std::cout << red << "Ошибка при добавлении элемента " << "x: " << blue << x << red << " y: " << blue << y << red << " value: " << blue << value << red << " в матрицу " << blue << this << red << "\nУказанная координата x меньше, чем размерность вашей матрицы!" << white << std::endl;
		show_matrix_demension();
		std::cout << std::endl;
		return;
	}
	if (y < 0)
	{
		std::cout << red << "Ошибка при добавлении элемента " << "x: " << blue << x << red << " y: " << blue << y << red << " value: " << blue << value << red << " в матрицу " << blue << this << red << "\nУказанная координата y меньше, чем размерность вашей матрицы!" << white << std::endl;
		std::cout << std::endl;
		show_matrix_demension();
		std::cout << std::endl;
		return;
	}
	pHead = new Node(x, y, value,pHead);
	amount_++;
    edit_matrix();
}

void Matrix::pop_front()
{
	Node* temp = pHead;
	if (pHead == nullptr)
	{
		std::cout << red << "В матрице " << blue << this << red << " ещё нет ненулевых коэффициентов, удалять нечего" << white << std::endl;
		std::cout << std::endl;
		return;
	}
	else
	{
		pHead = pHead->pNext;
		delete temp;
		amount_--;
	}
}

void Matrix::remove(int x, int y)
{
	if (pHead == nullptr)
	{
		std::cout << red << "В списке нет ненулевых коэффициентов, удалять нечего" << white << std::endl;
		std::cout << std::endl;
		return;
	}
	Node* temp = pHead;
	if (temp->x_ == x and temp->y_ == y)
	{
		pop_front();
	}
	else
	{
		int index_counter = -1;
		bool check = false;
        do
		{
			if (temp->x_ == x and temp->y_ == y)
			{
				check = true;
				index_counter++;
				break;
			}
			else
			{
				check = false;
				index_counter++;
				temp = temp->pNext;
			}
		} while (temp != nullptr);
		if (check == false)
		{
			std::cout << red << "Не найдено заданных координат " << blue << x << ";" << y <<red << " ,удалять нечего" <<white << std::endl;
			std::cout << std::endl;
		}
		else
		{
			Node* previous = pHead;
			for (int i = 0; i < index_counter - 1; ++i)
			{
				previous = previous->pNext;
			}
			Node* fordel = previous->pNext;
			previous->pNext = fordel->pNext;
			delete fordel;
			amount_--;
		}
	}


}

void Matrix::clear()
{
	while (amount_)
	{
		pop_front();
    }
}

int Matrix::get_amount()
{
	std::cout << red << "Количество ненулевых коэффициентов в разреженной матрице " << blue << this <<red<<" равно: " << blue << amount_ << white << std::endl;
	std::cout << std::endl;
	return amount_;
}

void Matrix::show_matrix()
{
	std::cout << red << "Матрица: " << blue << this << std::endl;
	std::cout << std::endl;
	Node* temp = pHead;
	if (temp == nullptr)
	{
		for (int i = 0; i < n_; ++i)
		{
			for (int j = 0; j < n_; ++j)
			{
				std::cout << blue << "0\t" << white;
			}
			std::cout << white<< std::endl;
		}
	}
	else
	{
		for (int i = 0; i < n_; ++i)
		{
			for (int j = 0; j < m_; ++j)
			{
				bool check = false;
				Node* current = pHead;
				do
				{
					if (current->x_ == i and current->y_ == j)
					{
						check = true;
						break;
					}
					else
					{
						current = current->pNext;
					}
				} while (current != nullptr);
				if (check == false)
				{
					std::cout << blue << "0\t" << white;
				}
				if (check == true)
				{
					std::cout << green << current->v_ << "\t" << white;
				}
			}
			std::cout << white << std::endl;
		}
	}
	std::cout << std::endl;
}

void Matrix::show_list()
{
	std::cout << "Список " << this << std::endl;
	std::cout << std::endl;
	Node* temp = pHead;
	do
	{
		std::cout << temp->v_ << std::endl;
		temp = temp->pNext;
	} while (temp!= nullptr);
}

double Matrix::get_element(int x, int y)
{
	if (x < 0 or x >= n_)
	{
		std::cout << red << "Ошибка при взятии элемента, проверьте координату x " << std::endl;
	}
	if (y < 0 or y >= m_)
	{
		std::cout << red << "Ошибка при взятии элемента, проверьте координату x " << std::endl;
	}
	bool check = false;
	Node* temp = pHead;
	do
	{
		if (temp->x_ == x and temp->y_ == y)
		{
			check = true;
			break;
		}
		else
		{
			check = false;
			temp = temp->pNext;
		}
	} while (temp != nullptr);
	if (check == true)
	{
		return temp->v_;
	}
	else
	{
		return 0.0;
	}
}

void Matrix::set_element(int x, int y, double value)
{
	bool check = false;
	Node* temp = pHead;
	do
	{
		if (temp->x_ == x and temp->y_ == y)
		{
			check = true;
			break;
		}
		else
		{
			check = false;
			temp = temp->pNext;
		}
	} while (temp != nullptr);
	if(check == true)
	{
		temp->v_ = value;
	}
	else
	{
		push_back(x, y, value);
	}
}

void Matrix::keyboard_input(Matrix &_new )
{
	_new.clear();
	std::cout << yellow << "Введите количество строк вашей матрицы: " << white;
	do
	{
		std::cin >> _new.n_;
	}while (_new.n_ < 1); 
	std::cout << std::endl;
	std::cout << yellow << "Введите колчество столбцов вашей матрицы: " << white;
	do {
		std::cin >> _new.m_;
	}while (_new.m_ < 1);
	for (int i = 0; i < _new.n_; ++i)
	{
		for (int j = 0; j < _new.m_; ++j)
		{
			double data;
			std::cout << "Введите элемент на " << i << " строке " << j << " столбца" << std::endl;
			std::cin >> data;
			std::cout << std::endl;
			push_back(i, j, data);
		}
	}
	edit_matrix();
}

void Matrix::txt_input(std::string _path)
{
	std::string path = _path;
	std::ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		std::cout << red << "Ошибка при открытии файла" << white <<std::endl;
	}
	else
	{
		std::cout << green << "Файл " << blue << path << green << " успешно открыт " << white << std::endl;
		for (int i = 0; i < n_; ++i)
		{
			for (int j = 0; j < m_; ++j)
			{
				double data;
				fin >> data;
				push_back(i, j, data);
			}
		}
		edit_matrix();
	}
	fin.close();
	std::cout << std::endl;
}

void Matrix::txt_output(std::string _path)
{
	std::string path = _path;
	std::ofstream fout;
	fout.open(path);
	if (!fout.is_open())
	{
		std::cout << red << "Ошибка при открытии файла " << blue << path << white << std::endl;
		return;
	}
	else
	{
		fout << red << "Матрица: " << blue << this << std::endl;
		std::cout << std::endl;
		Node* temp = pHead;
		if (temp == nullptr)
		{
			for (int i = 0; i < n_; ++i)
			{
				for (int j = 0; j < n_; ++j)
				{
					fout << blue << "0\t" << white;
				}
				fout << white << std::endl;
			}
		}
		else
		{
			for (int i = 0; i < n_; ++i)
			{
				for (int j = 0; j < m_; ++j)
				{
					bool check = false;
					Node* current = pHead;
					do
					{
						if (current->x_ == i and current->y_ == j)
						{
							check = true;
							break;
						}
						else
						{
							current = current->pNext;
						}
					} while (current != nullptr);
					if (check == false)
					{
						fout << blue << "0\t" << white;
					}
					if (check == true)
					{
						fout << green << current->v_ << "\t" << white;
					}
				}
				fout << white << std::endl;
			}
		}
	}
	fout.close();
}

void Matrix::add_matrices(const Matrix &other)
{
	Node* first = pHead;
	Node* second = other.pHead;
	if (n_ == other.n_ and m_ == other.m_)
	{

		if (first == nullptr and second == nullptr)
		{
			std::cout << red <<"В обеих матрицах нет коэффициентов, складывать нечего" <<white << std::endl;
			std::cout << std::endl;
		}
		if (first == nullptr and second != nullptr)
		{
			do
			{
				push_back(second->x_, second->y_, second->v_);
				second = second->pNext;
			} while (second != nullptr);
			edit_matrix();
		}
		if (first != nullptr and second == nullptr)
		{
			std::cout << red <<"В добавляемой матрице нет коэффициентов, прибавлять нечего " <<white << std::endl;
			std::cout << std::endl;
		}
		if (first != nullptr and second != nullptr)
		{
			do
			{
				bool flag = false;
				first = pHead;
				do
				{
					if (second->x_ == first->x_ and second->y_ == first->y_)
					{
						flag = true;
						first->v_ += second->v_;
						first = first->pNext;
					}
					else
					{
						first = first->pNext;
					}

				} while (first != nullptr);
				if (flag == false)
				{
					push_back(second->x_, second->y_, second->v_);
				}
				second = second->pNext;
			} while (second != nullptr);
		}
	}
	else
	{
		std::cout << red << "Матрицы разных размеров нельзя складывать " <<white<< std::endl;
		std::cout<< std::endl;
	}
	edit_matrix();
}

void Matrix::add_number(double number)
{
	Node* first = pHead;
	if (number == 0)
	{
		return;
	}
	if (first == nullptr)
	{
		for (int i = 0; i < n_; ++i)
		{
			for (int j = 0; j < m_; ++j)
			{
				push_back(i, j, number);
			}
		}
		return;
	}
	else
	{
		do
		{
			first->v_ += number;
			first = first->pNext;
		} while (first != nullptr);
		return;
	}
}

void Matrix::subtract(const Matrix& other)
{
	if (n_ == other.n_ and m_ == other.m_)
	{
		Node* first = pHead;
		Node* second = other.pHead;
		if (first == nullptr and second == nullptr)
		{
			std::cout<<red << "В обеих матрицах нет коэффициентов, отнимать нечего" << white<< std::endl;
			std::cout << std::endl;
			return;
		}
		if (first == nullptr and second != nullptr)
		{
			do
			{
				push_back(second->x_, second->y_, -second->v_);
				second = second->pNext;
			} while (second != nullptr);
		}
		if (first != nullptr and second == nullptr)
		{
			std::cout<<red << "В вычитаемой матрице нет коэффициентов, отнимать нечего " << white<<std::endl;
			std::cout << std::endl;
			return;
		}
		if (first != nullptr and second != nullptr)
		{
			do
			{
				bool flag = false;
				first = pHead;
				do
				{
					if (second->x_ == first->x_ and second->y_ == first->y_)
					{
						flag = true;
						first->v_ -= second->v_;
						first = first->pNext;
					}
					else
					{
						first = first->pNext;
					}

				} while (first != nullptr);
				if (flag == false)
				{
					push_back(second->x_, second->y_, -second->v_);
				}
				second = second->pNext;
			} while (second != nullptr);
		}
	}
	else
	{
		std::cout << red<< "Нельзя вычитать матрицы разного размера" <<white<< std::endl;
		std::cout << std::endl;
		return;
	}
	edit_matrix();
}

void Matrix::subtract(double number)
{
	if (number == 0)
	{
		return;
	}
	else
	{
		Node* first = pHead;
		if (first == nullptr)
		{
			for (int i = 0; i < n_; ++i)
			{
				for (int j = 0; j < m_; ++j)
				{
					push_back(i, j, -number);
				}
			}
		}
		else
		{
			do
			{
				first->v_ -= number;
				first = first->pNext;
			} while (first != nullptr);
		}
	}
}

void Matrix::multiply(Matrix& const other)
{
	if (m_ != other.n_)
	{
		std::cout<<red << "Умножение невозможно" << white<<std::endl;
		return;
	}
	if (m_ < other.m_)
	{
		m_ = other.m_;
	}
	double sum = 0;
	int new_counter_ = 0;
	for (int i = 0; i < n_; i++)
	{
		for (int j = 0; j < other.m_; j++)
		{
			sum = 0;
			for (int k = 0; k < other.n_; k++)
				sum += get_element(i, k) * other.get_element(k, j);
			if (sum)
			{
				++new_counter_;
			}
			set_element(i, j, sum);
		}
	}
	if (m_ > other.m_)
	{
		cut_matrix(n_, other.m_);
	}
	else
	{
		edit_matrix();
	}
	amount_ = new_counter_;
}

void Matrix::multiply(double number)
{
	Node* first = pHead;
	if (number == 0)
	{
		clear();
	}
	else
	{
		do
		{
			first->v_ *= number;
			first = first->pNext;
		} while (first != nullptr);
	}
}
void Matrix::devide(double number)
{
	Node* first = pHead;
	if (number == 0)
	{
		std::cout << red << "Ну куда на ноль делишь, нельзя :)" << white << std::endl;
		std::cout << std::endl;
		return;
	}
	if (first == nullptr)
	{
		std::cout << red << "В матрице " << blue << this << red << " ещё нет ненулевых коэффициенов, матрица не изменилась " << white << std::endl;
		std::cout << std::endl;
		return;
	}
	else
	{
		do
		{
			first->v_ /= number;
			first = first->pNext;
		} while (first != nullptr);
	}
}
bool Matrix::ComparisionMore(const Matrix& other)
{
	if (n_ > other.n_ and m_ > other.m_)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Matrix::ComparisionLess(const Matrix& other)
{
	if (other.n_ > n_ and other.m_ > m_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

double Matrix::determinant()
{
	if (n_ != m_)
	{
		std::cout << "Для этой матрицы нельзя найти определитель" << std::endl;
		return 0;
	}
	if (this->n_ == 1)
	{
		return get_element(0, 0);
	}
	if (this->n_ == 2)
	{
		return (get_element(0, 0) * get_element(1, 1) - get_element(0, 1) * get_element(1, 0));
	}
	double d = 0;
	int p = 1;
	for (int j = 0; j != n_; ++j)
	{
		Matrix temp;
		temp.expand_matrix(*this, 0, j);
		temp.show_matrix();		
		if (get_element(0, j))
		{
			d += double(p) * get_element(0, j) * temp.determinant();
		}
		p *= -1;
	}
	return d;
}

Matrix & Matrix::operator =(const Matrix& other)
{
	pHead = nullptr;
	Node* first = pHead;
	Node* second = other.pHead;
	amount_ = 0;
	n_ = other.n_;
	m_ = other.m_;
	if (second == nullptr and first == nullptr)
	{
		pHead = other.pHead;
	}
	if (second != nullptr and first == nullptr)
	{
		int tmp_amount = other.amount_;
		do
		{
			push_back(second->x_, second->y_, second->v_);
			second = second->pNext;
			tmp_amount--;
		} while (tmp_amount != 0);
	}
	return *this;
}

bool Matrix::operator==(const Matrix& other)
{
	bool check = false;
	if (n_ == other.n_ and m_ == other.m_)
	{
		if (amount_ == other.amount_)
		{
			check = true;
			Node* first = pHead;
			Node* second = other.pHead;
			if (first == nullptr and second == nullptr)
			{
				return true;
			}
			if (first == nullptr and second != nullptr)
			{
				return false;
			}
			if (first != nullptr and second == nullptr)
			{
				return false;
			}
			else
			{
				do
				{
					do
					{
						second = other.pHead;
						if (first->x_ == second->x_ and first->y_ == second->y_ and first->v_ == second->v_)
						{
							check = true;
							break;
						}
						else
						{
							check = false;
							second = second->pNext;
						}
					} while (second != nullptr);
					first = first->pNext;
					if (check == false)
					{
						return false;
					}
					else
					{
						return true;
					}

				} while (first != nullptr);
			}
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Matrix::operator!=(const Matrix& other)
{
	bool check = false;
	if (n_ == other.n_ and m_ == other.m_)
	{
		if (amount_ == other.amount_)
		{
			check = false;
			Node* first = pHead;
			Node* second = other.pHead;
			if (first == nullptr and second == nullptr)
			{
				return false;
			}
			if (first == nullptr and second != nullptr)
			{
				return true;
			}
			if (first != nullptr and second == nullptr)
			{
				return true;
			}
			else
			{
				do
				{
					do
					{
						second = other.pHead;
						if (first->x_ == second->x_ and first->y_ == second->y_ and first->v_ == second->v_)
						{
							check = false;
							break;
						}
						else
						{
							check = true;
							second = second->pNext;
						}
					} while (second != nullptr);
					first = first->pNext;
					if (check == true)
					{
						return true;
					}
					else
					{
						return false;
					}

				} while (first != nullptr);
			}
		}
		else
		{
			return true;
		}
	}
	else
	{
		return true;
	}
}

bool Matrix::operator>(const Matrix& other)
{
	bool result =this->ComparisionMore(other);

	return result;
}

bool Matrix::operator<(const Matrix& other)
{
	bool result = this->ComparisionLess(other);
	return result;
}

bool Matrix::operator>=(const Matrix& other)
{
	if (n_ >= other.n_ and m_ >= other.n_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Matrix::operator<=(const Matrix& other)
{
	if (other.n_ >= n_ and other.m_ >= m_)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Matrix Matrix::operator+(const Matrix& other)
{
	Matrix temp = *this;
	temp.add_matrices(other);
	return temp;
}

Matrix Matrix::operator+(const double number)
{
	Matrix temp = *this;
	temp.add_number(number);
	return temp;
}

Matrix Matrix::operator*(Matrix& const other)
{
	Matrix temp = *this;
	temp.multiply(other);
	return temp;
}

Matrix Matrix::operator*(const double number)
{
	Matrix temp = *this;
	if (number == 0)
	{
		temp.clear();
		return temp;
	}
	else
	{
		temp.multiply(number);
		return temp;
	}
}

Matrix Matrix::operator-(const Matrix& other)
{
	Matrix temp = *this;
	temp.subtract(other);
	return temp;
}

Matrix Matrix::operator-(const double number)
{
	Matrix temp = *this;
	temp.subtract(number);
	return temp;

}

Matrix Matrix::operator/(const double number)
{
	Matrix temp = *this;
	temp.devide(number);
	return temp;
}

void Matrix::show_matrix_demension()
{
	std::cout << red << "Размерность вашей матрицы:" << " (" << blue << n_ << "x" << blue << m_ << red << ")" << white << std::endl;
	std::cout << std::endl;
}

void Matrix::edit_matrix()
{
	Node* temp = pHead;
	bool check = true;
	if (temp == nullptr)
	{
		return;
	}
	do
	{
		if (temp->v_ == 0)
		{
			check = true;
			break;
		}
		else
		{
			check = false;
			temp = temp->pNext;
		}
	} while (temp != nullptr);
	if (check)
	{
		remove(temp->x_, temp->y_);
	}
	else
	{
		return;
	}
}

void Matrix::cut_matrix(int m , int n)
{
	if ((m > m_) or (n > n_))
	{
		return;
	}
	for (int i = n_ - 1; i != n; ++i)
	{
		for (int j = m_ - 1; j != m; ++j)
		{
			if (double a = get_element(i, j))
			{
				remove(i, j);
			}
		}
	}
	n_ = n;
	m_ = m;
	edit_matrix();
}

void Matrix::expand_matrix(Matrix & const other, int ia, int ja)
{
	int i0 = 0, j0 = 0;
	for (int i = 0; i != other.n_; ++i)
		for (int j = 0; j != other.m_; ++j)
		{
			if ((i != ia) and (j != ja))
			{
				double b = other.get_element(i, j);
				push_back(i0, j0, b);
				i0++;
				if (i0 == other.n_ - 1)
				{
					i0 = 0;
					j0++;
				}
			}
		}
	m_ = other.m_ - 1;
	n_ = other.n_ - 1;

}

std::ostream& operator<<(std::ostream& os, Matrix other)
{
	other.show_matrix();	
	return os;
}

std::istream& operator>>(std::istream& is,  Matrix &other)
{
	other.keyboard_input(other);
	return is;
}

Matrix operator+(const double number, const Matrix &other)
{
	Matrix temp = other;
	if (number == 0)
	{
		return temp;
	}
	else
	{
		temp.add_number(number);
		return temp;
	}
}

Matrix operator*(const double number, const Matrix& other)
{
	Matrix temp = other;
	temp.multiply(number);
	return temp;
}

