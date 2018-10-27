#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix()
{
	M = NULL;
	M_size = 0;
	N_size = 0;

}

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
			M[i][j] = (1 + rand() % 1000)*pow(-1,rand());
	}

}

Matrix::Matrix(int m,int n, double c)
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

Matrix::Matrix(Matrix & that )
{
	M_size = that.M_size;
	N_size = that.N_size;
	M = new double*[M_size];
	for (int i = 0; i < M_size; i++)
		M[i] = new double[N_size];

	for (int i = 0; i < M_size; i++)
	{
		for (int j = 0; j < N_size; j++)
			M[i][j] = that[i][j];
	}


}

Matrix::Matrix(Matrix & that , int k)
{
	M_size =1;
	N_size = that.N_size;
	M = new double*[M_size];
	
		M[0] = new double[N_size];

	
		for (int j = 0; j < N_size; j++)
			M[0][j] = that[k][j];
	


}

Matrix& Matrix::operator=( const Matrix& that)
{
	

	for (int i = 0; i < that.M_size; i++)
	{
		for (int j = 0; j < that.N_size; j++)
		this->M[i][j] = that.M[i][j];
		
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

			temp.M[i][j] =	this->M[i][j] + that.M[i][j];
			

	}
	return temp;
}

Matrix Matrix::operator-( Matrix & that)
{
	Matrix temp(that.M_size, that.N_size ,0);

	for (int i = 0; i < that.M_size; i++)
	{
		for (int j = 0; j < that.N_size; j++)

			temp.M[i][j] = this->M[i][j] - that.M[i][j];

	}
	return temp;
}

Matrix Matrix::operator*( Matrix & that)
{

	Matrix temp(that.M_size,that.N_size, 0);

	if (that.M_size == this->M_size && that.N_size == this->N_size)
	{
		for (int i = 0; i < that.M_size; i++)
			{
				for (int j = 0; j < that.N_size; j++)

					for (int k = 0; k < that.M_size; k++)
					{
						temp.M[i][j] += this->M[i][k] * that.M[k][j];
					}
			


			}
	}

	
	return temp;
}

Matrix Matrix::operator*( double & that)
{
	Matrix temp(this->M_size, this->N_size, 0);
	double k,m;
	for (int i = 0; i < this->M_size; i++)
	{
		for (int j = 0; j < this->N_size; j++)

		{
			m = this->M[i][j];
			k =  m* that;
			temp.M[i][j] = k;
		}

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
	double temp=0;
		for (int j = 0; j < N_size; j++)

			temp += this->M[0][j]* this->M[0][j];
	return sqrt(temp);
}

double Matrix::skal_dob(Matrix &that)
{
	double temp=0;
		for (int j = 0; j < N_size; j++)
			temp += this->M[0][j] * that.M[0][j];
	return temp;
}

Matrix Matrix::method_gaussa(Matrix b)
{
	double f;
	for (int k = 0; k < N_size-1; k++)
	{		
		for (int i = k; i < M_size-1; i++)
		{
			f = this->M[i+1][k] / this->M[k][k];
			for (int j = k; j < N_size; j++)
			{
				this->M[i+1][j] = this->M[i + 1][j] - this->M[k][j] * f;

			}
			b[0][i + 1] = b[0][i + 1]- b[0][i] * f;
		}
	}
	Matrix temp(1, N_size, 0);
	for (int i = M_size - 1; i > 0; i--)
	{
		temp[0][i] = b[0][i] / this->M[i][i];
		for (int j = N_size - 1; j >=i ; j--)
		{
			b.M[0][i - 1] = b[0][i-1]- this->M[i - 1][j] * temp[0][j];

		}
	}
	temp[0][0]=b[0][0]/ this->M[0][0];

	return temp;
}

Matrix Matrix::method_kachmaga(Matrix b)
{
	const double E = 0.00000000001;

	Matrix x(*this, 0);
	Matrix x1(1,N_size,0);
	
	
	Matrix sub(1, N_size, 1);
	int j=0;

	while (sub.norma() > E)
	{	
	
		Matrix ai(*this, j);
	
		double temp =  ((b.M[0][j] - ai.skal_dob(x)) / (ai.norma()*ai.norma()));
	
		ai=ai * temp;
		x1 = x + ai;
		sub = x1-x;
	
	//	cout << sub.norma()<<endl;
		x = x1;
		if (j < N_size-1)
			j++;
		else j = 0;

		
	}




	return x;

}

Matrix Matrix::chek_answer(Matrix b, Matrix x)
{
	Matrix res(1, this->N_size, 0);
	double temp=0;
	
	
	for (int i=0;i<M_size;i++)
	{
		
			
		for (int j = 0; j < N_size; j++)
		{

			temp += this->M[i][j] * x.M[0][j];
		
		}

		res.M[0][i] = temp - b[0][i];

		temp = 0;

	}

	return res;
	
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
		os << '|' <<endl;

	}

	return os;
}

istream & operator>>(istream & os, const Matrix & that)
{
	for (int i = 0; i < that.M_size; i++)
	{
	
		for (int j = 0; j < that.N_size; j++)
			os >> that.M[i][j];
		

	}

	return os;
}


