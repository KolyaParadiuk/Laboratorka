#include "Matrix.h"
#include <iostream>


using namespace std;

Matrix::Matrix(int m,int n)
{

	M_size = m;
	N_size = n;
	M = new double*[M_size];
	for (int i = 0; i < M_size; i++)
		M[i] = new double[N_size];

	for (int i = 0; i < M_size; i++)
	{
		for (int j = 0; j < N_size; j++)
			M[i][j] = rand();
	}

}

Matrix::Matrix(int n,int m, double c)
{
	M_size = m;
	N_size = n;
	M = new double*[M_size];
	if (c == 0)		
	{
		for (int i = 0; i < M_size; i++)
			M[i] = new double[N_size] {};
	}
	else 
		for (int i = 0; i < M_size; i++)
		M[i] = new double[N_size];

	for (int i = 0; i < M_size; i++)
	{
		for (int j = 0; j < N_size; j++)
			M[i][j] = c;
	}
	
}

Matrix Matrix::operator=( Matrix &that)
{
	

	for (int i = 0; i < that.M_size; i++)
	{
		for (int j = 0; j < that.N_size; j++)
		*this[i][j] = that[i][j];
		
	}
	return *this;
}

bool Matrix::operator==( Matrix & that)
{
	for (int i = 0; i < that.M_size; i++)
	{
		for (int j = 0; j < that.N_size; j++)
			
			if (*this[i][j] != that[i][j])
			{
				return false;
			}

	}
	return true;
}

Matrix Matrix::operator +( Matrix & that)
{
	Matrix temp(that.M_size,that.N_size, 0);

	for (int i = 0; i < that.M_size; i++)
	{
		for (int j = 0; j < that.N_size; j++)

			temp[i][j] =	*this[i][j] + that[i][j];
			

	}
	return temp;
}

Matrix Matrix::operator-( Matrix & that)
{
	Matrix temp(that.M_size, that.N_size ,0);

	for (int i = 0; i < that.M_size; i++)
	{
		for (int j = 0; j < that.N_size; j++)

			temp[i][j] = *this[i][j] - that[i][j];

	}
	return temp;
}

Matrix Matrix::operator*( Matrix & that)
{
	Matrix temp(that.M_size, 0);

	for (int i = 0; i < that.M_size; i++)
	{
		for (int j = 0; j < that.M_size; j++)

			for (int k = 0; k < that.M_size; k++)
			{
				temp.M[i][j] += this->M[i][k] * that.M[k][j];
			}
			


	}
	return temp;
}

Matrix Matrix::operator*( double & that)
{
	Matrix temp(this->M_size, this->N_size, 0);

	for (int i = 0; i < this->M_size; i++)
	{
		for (int j = 0; j < this->N_size; j++)

			temp[i][j] = *this[i][j] * that;


	}
	return temp;
}

double* Matrix::operator[](int i)
{

	return M[i];
}

int Matrix::get_size()
{
	return this->M_size;
}

double Matrix::norma()
{
	double temp;
	for (int i = 0; i < M_size; i++)
		for (int j = 0; j < N_size; j++)
			temp += *this[i][j] * *this[i][j];
	return sqrt(temp);
}

double Matrix::skal_dob(Matrix that)
{
	double temp;
	for (int i = 0; i < M_size; i++)
		for (int j = 0; j < N_size; j++)
			temp += *this[i][j] * that[i][j];
	return temp;
}

void Matrix::method_gaussa()
{
}

void Matrix::method_kachmaga()
{

}

Matrix operator~(Matrix that)
{
	int k = 0, n=0;
	Matrix temp(that.M_size, that.N_size, 0);
	
	for (int i = 0; i < that.M_size; i++)
	{
		for (int j=0;j<that.N_size;j++)
			
		{
			temp [k][n]=that[i][j];
			k++;
		}
		n++;
		k = 0;

	}
	return temp;
}

ostream & operator<<(ostream & os, const Matrix & that)
{
	for (int i = 0; i < that.M_size; i++)
	{
		os << '|';
		for (int j = 0; j < that.N_size; j++)
			os << that.M[i][j] << ' ';
		os << '|' << endl;

	}

	return os;
}

istream & operator>>(istream & os, const Matrix & that)
{
	for (int i = 0; i < that.M_size; i++)
	{
	
		for (int j = 0; j < that.M_size; j++)
			os >> that.M[i][j];
		

	}

	return os;
}


