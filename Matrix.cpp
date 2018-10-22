#include "Matrix.h"
#include <iostream>


using namespace std;

Matrix::Matrix(int n)
{

	M_size = n;
	M = new double*[M_size];
	for (int i = 0; i < M_size; i++)
		M[i] = new double[n];

	for (int i = 0; i < M_size; i++)
	{
		for (int j = 0; j < M_size; j++)
			M[i][j] = rand();
	}

}

Matrix::Matrix(int n, int c)
{
	M_size = n;
	M = new double*[M_size];
	if (c == 0)		
	{
		for (int i = 0; i < M_size; i++)
			M[i] = new double[n] {};
	}
	else 
		for (int i = 0; i < M_size; i++)
		M[i] = new double[n];

	for (int i = 0; i < M_size; i++)
	{
		for (int j = 0; j < M_size; j++)
			M[i][j] = c;
	}
	
}

Matrix Matrix::operator=(const Matrix &that)
{

	for (int i = 0; i < that.M_size; i++)
	{
		for (int j = 0; j < that.M_size; j++)
		this->M[i][j] = that.M[i][j];
		
	}
	return *this;
}

bool Matrix::operator==(const Matrix & that)
{
	for (int i = 0; i < that.M_size; i++)
	{
		for (int j = 0; j < that.M_size; j++)
			
			if (this->M[i][j] != that.M[i][j])
			{
				return false;
			}

	}
	return true;
}

Matrix Matrix::operator +(const Matrix & that)
{
	Matrix temp(that.M_size, 0);

	for (int i = 0; i < that.M_size; i++)
	{
		for (int j = 0; j < that.M_size; j++)

			temp.M[i][j] =	this->M[i][j] + that.M[i][j];
			

	}
	return temp;
}

Matrix Matrix::operator-(const Matrix & that)
{
	Matrix temp(that.M_size, 0);

	for (int i = 0; i < that.M_size; i++)
	{
		for (int j = 0; j < that.M_size; j++)

			temp.M[i][j] = this->M[i][j] - that.M[i][j];


	}
	return temp;
}

Matrix Matrix::operator*(const Matrix & that)
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

Matrix Matrix::operator*(const double & that)
{
	Matrix temp(this->M_size, 0);

	for (int i = 0; i < this->M_size; i++)
	{
		for (int j = 0; j < this->M_size; j++)

			temp.M[i][j] = this->M[i][j] * that;


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

Matrix operator~(Matrix that)
{
	int k = that.M_size -1, n=0;
	Matrix temp(that.M_size, 0);
	temp = that;
	for (int i = 0; i < that.M_size; i++)
	{
		for (int j=0;j<that.M_size;j++)
			
		{
			that[i][j] = temp[k][n];
			k--;
		}
		n++;
		k = that.M_size-1;

	}
	return that;
}

ostream & operator<<(ostream & os, const Matrix & that)
{
	for (int i = 0; i < that.M_size; i++)
	{
		os << '|';
		for (int j = 0; j < that.M_size; j++)
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
