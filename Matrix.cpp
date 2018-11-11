#include "Matrix.h"
#include <iostream>
#include <time.h>

using namespace std;

int Matrix :: counter = 0;
int Matrix::nomber_of_existing_items = 0;
bool Matrix::isSimmetrial()
{

	for (int i = 0; i < M_size; i++)
	{
		for (int j = i + 1; j < N_size; j++)
		{
			if (this->M[i][j] != this->M[j][i])  return false;
		}
	}
	return true;
	
}

Matrix::Matrix()
{
	M = nullptr;
	M_size = 0;
	N_size = 0;
	nomber = counter;
	counter++;
	nomber_of_existing_items++;
	//cout << "Matrix created "<<nomber << endl; 

}

Matrix::Matrix(int m,int n)
{

	M_size = m;
	N_size = n;
	nomber = counter;
	counter++;
	nomber_of_existing_items++;
	M = new double*[M_size];
	for (int i = 0; i < M_size; i++)
		M[i] = new double[N_size];
	srand(time(0));
	for (int i = 0; i < M_size; i++)
	{
		for (int j = 0; j < N_size; j++)
			M[i][j] = (1 + rand() % 100)*pow(-1, rand());
	}
//	cout << "Matrix created " << nomber << endl;
}

Matrix::Matrix(int m,int n, double c)
{
	M_size = m;
	N_size = n;
	nomber = counter;
	counter++; 
	nomber_of_existing_items++;
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
	//cout << "Matrix created " << nomber << endl;
}

Matrix::Matrix(Matrix & that )
{
	M_size = that.M_size;
	N_size = that.N_size;
	nomber = counter;
	counter++;
	nomber_of_existing_items++;
	M = new double*[M_size];
	for (int i = 0; i < M_size; i++)
		M[i] = new double[N_size];

	for (int i = 0; i < M_size; i++)
	{
		for (int j = 0; j < N_size; j++)
			M[i][j] = that.M[i][j];
	}

//cout << "Matrix created " << nomber << endl;
}

Matrix::Matrix(Matrix & that , int k)
{
	M_size =1;
	N_size = that.N_size;
	nomber = counter;
	counter++;
	nomber_of_existing_items++;
	M = new double*[M_size];
	
		M[0] = new double[N_size];

	
		for (int j = 0; j < N_size; j++)
			M[0][j] = that[k][j];
	

	//	cout << "Matrix created " << nomber << endl;
}

Matrix::~Matrix()
{

	if (M != nullptr)
	{	
		for (int i = 0; i < M_size; i++)
		{
			
			if (M[i] != nullptr)
			delete[] M[i];
			M[i] = nullptr;
		}
		
		delete[] M;
		M = nullptr;
	}
	
	nomber_of_existing_items--;
	//cout << "Matrix deleted " << nomber << endl;

	//cout << "nomber_of_existing_items=  " << nomber_of_existing_items<<endl;
}


void Matrix::dispose()
{

	for (int i = 0; i < M_size; i++)
	{
		delete[] M[i];
		M[i] = nullptr;
	}
		

	delete[] M;
	M = nullptr;
	nomber_of_existing_items--;
	cout << "Matrix deleted " << nomber << endl;

	cout << "nomber_of_existing_items=  " << nomber_of_existing_items << endl;
}

void Matrix::set_simetrial_matrix()
{
	for (int i = 0; i < M_size; i++)
	{
		for (int j = i; j < N_size; j++)
			M[i][j] =M[j][i]=  (1 + rand() % 1000)*pow(-1, rand());
	}
}

void Matrix::set_one_matrix()
{
	for (int i = 0; i < M_size; i++)
	{

		for (int j = i; j < N_size; j++)
		{
			
			 M[i][j] = 0;
			 M[j][i] = 0;
		}
		M[i][i] = 1;
	}
}

void Matrix::set_gilbert_matrix() 
{
	for (int i = 0; i < M_size; i++)
	{

		for (int j = 0; j < N_size; j++)
		{

			M[i][j] = 1.0 / (i + j + 1);
		
		}
	
	}
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

Matrix& Matrix::operator=(const double& that)
{

	for (int i = 0; i < this->M_size; i++)
	{
		for (int j = 0; j < this->N_size; j++)
			this->M[i][j] = that;
	
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
	Matrix *temp=new Matrix(that.M_size,that.N_size, 0);

	for (int i = 0; i < that.M_size; i++)
	{
		for (int j = 0; j < that.N_size; j++)

			temp->M[i][j] =	this->M[i][j] + that.M[i][j];
			

	}
	return *temp;
}

Matrix Matrix::operator-( Matrix & that)
{
	Matrix *temp=new Matrix(that.M_size, that.N_size ,0);

	for (int i = 0; i < that.M_size; i++)
	{
		for (int j = 0; j < that.N_size; j++)

			temp->M[i][j] = this->M[i][j] - that.M[i][j];

	}
	return *temp;
}

Matrix Matrix::operator*( Matrix & that)
{
	Matrix *temp;

	if (this->M_size>1 && this->N_size>1&& that.M_size>1 && that.N_size>1)
	{
		temp = new Matrix(this->M_size,that.N_size, 0);

		for (int i = 0; i < temp->M_size; i++)
			{
				for (int j = 0; j < temp->N_size; j++)

					for (int k = 0; k < that.M_size; k++)
					{
						temp->M[i][j] += this->M[i][k] * that.M[k][j];
					}
			


			}

	}
	else
	{
		temp = new Matrix(1, that.N_size, 0);
		for (int i = 0; i < M_size; i++)
		for (int j = 0; j < N_size; j++)
		{

			temp->M[0][i] += this->M[i][j] * that.M[0][j];

		}

	}
	return *temp;
}

Matrix Matrix::operator*( double & that)
{
	Matrix *temp =new Matrix(this->M_size, this->N_size, 0);
	double k,m;
	for (int i = 0; i < this->M_size; i++)
	{
		for (int j = 0; j < this->N_size; j++)

		{
			m = this->M[i][j];
			k =  m* that;
			temp->M[i][j] = k;
		}

	}
	return *temp;
}

double* Matrix::operator[](int i)
{

	return M[i];
}

Matrix Matrix::multiplication(Matrix &that )
{
	Matrix *temp = new Matrix(that.M_size,that.N_size, 0);

	if (that.M_size == this->M_size && that.N_size == this->N_size)
	{
		for (int i = 0; i < that.M_size; i++)
			{
				for (int j = 0; j < that.N_size; j++)

					for (int k = 0; k < that.M_size; k++)
					{
						temp->M[i][j] += this->M[i][k] * that.M[k][j];
					}
			


			}
	}
	*this = *temp;
	delete temp;
	return *this;
}

Matrix Matrix::multiplication(double & that)
{

	for (int i = 0; i < this->M_size; i++)
	{
		for (int j = 0; j < this->N_size; j++)

		{
			this->M[i][j] *= that;
		}

	}
	return *this;
}

Matrix Matrix::substaction(const Matrix & that)
{

	for (int i = 0; i < that.M_size; i++)
	{
		for (int j = 0; j < that.N_size; j++)

			this->M[i][j] -= that.M[i][j];

	}
	return *this;
}

Matrix Matrix::addition( Matrix &that)
{
	for (int i = 0; i < that.M_size; i++)
	{
		for (int j = 0; j < that.N_size; j++)

			this->M[i][j] += that.M[i][j];

	}
	return *this;
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

void Matrix::method_gaussa(Matrix that,Matrix b,Matrix &result)
{
	double f;

	for (int k = 0; k < N_size-1; k++)
	{		
		for (int i = k+1; i < M_size; i++)
		{
			f = that.M[k][k] / that.M[i][k];
			for (int j = 0; j < N_size; j++)
			{
				that.M[i][j] = that.M[i][j]*f - that.M[k][j];
			
			}
			b[0][i] = b[0][i ]*f- b[0][k] ;
			
	
		}
	
	}
	Matrix temp(1, N_size, 0);
	for (int i = M_size - 1; i > 0; i--)
	{
		temp[0][i] = b[0][i] / that.M[i][i];
		for (int j = N_size - 1; j >=i ; j--)
		{
			b.M[0][i - 1] = b[0][i-1]- that.M[i - 1][j] * temp[0][j];

		}
	}
	temp[0][0]=b[0][0]/ that.M[0][0];
	result = temp;
}

Matrix Matrix::method_kachmaga(Matrix b)
{
	const double E = 0.00001;//точность 

	Matrix x(*this, 0);//задаю вектор решения х по 0 строке матрицы коэфициэнтов
	Matrix x1(1,N_size,0);//вспомогательный векор в для временного хранения х 
	
	
	Matrix sub(1, N_size, 1);//разница между поточным х и  следующим, должна быть меньше Е чтоб цикл закончился 
	int j=0;

	while (sub.norma() > E)
	{	
	
		Matrix *ai= new Matrix(*this, j);//в этом векторе хранится j тая строка матрицы коэфициэнтов 
	
		double temp =  ((b.M[0][j] - ai->skal_dob(x)) / (ai->norma()*ai->norma()));//множтель считается по формуле 
		
		ai->multiplication(temp);
		x1 = ai->addition(x );
		sub = x1;
		sub.substaction(x);
		
		x = x1;
		if (j < N_size-1)
			j++;
		else j = 0;

		delete ai;
		//cout<<(this->chek_answer(b,x)).norma()<<endl;

	}
	// << this->chek_answer(b, x).norma();
	return x;

}

double Matrix::find_fault(double &fault)
{
	fault = 0;
	for (int i = 0; i < M_size; i++)
	{
		for (int j = i + 1; j < N_size; j++)
		{

			fault +=  M[i][j] * M[i][j];
		}
	}
	fault = sqrt(2 * fault);
	return fault;
}

void  Matrix::find_max(int & maxI, int& maxJ)
{
	double max=0.0;
	for (int i = 0; i < M_size; i++)
	{
		for (int j = i + 1; j < N_size; j++)
		{
			if (this->M[i][j] > 0 && this->M[i][j] > max)
			{
				max = this->M[i][j];
				maxI = i;
				maxJ = j;
			}
			else if (this->M[i][j] < 0 && -this->M[i][j] > max)
			{
				max = -this->M[i][j];
				maxI = i;
				maxJ = j;
			}
		}
	}
}

void Matrix::prepare_turn_matrix(const int& maxI, const int& maxJ,Matrix &turn_matr)
{
	turn_matr.set_one_matrix();
	if (this->M[maxI][maxI] == this->M[maxJ][maxJ])
	{
		turn_matr.M[maxI][maxI] = turn_matr.M[maxJ][maxJ] = turn_matr.M[maxJ][maxI] = sqrt(2.0) / 2.0;
		turn_matr.M[maxI][maxJ] = -sqrt(2.0) / 2.0;
	}
	else
	{
		double  fi = 0.5 * atan((2.0 * this->M[maxI][maxJ]) / (this->M[maxI][maxI] - this->M[maxJ][maxJ]));
		turn_matr.M[maxI][maxI] = turn_matr.M[maxJ][maxJ] = cos(fi);
		turn_matr.M[maxI][maxJ] = -sin(fi);
		turn_matr.M[maxJ][maxI] = sin(fi);
	}
}

Matrix Matrix::method_yakoby()
{
	int maxI = 0, maxJ = 0;
	double fault=0.0;
	Matrix turn_matr(M_size,N_size,0);
	Matrix temp(M_size, N_size, 0);
	double precision = 0.0001;

	if (!isSimmetrial())
	{
		cout << "Матрица не симметричная";
	}
	else
	{
		this->find_fault(fault);
		while (fault > precision)
		{
			this->find_max(maxI, maxJ);
			this->prepare_turn_matrix(maxI,maxJ,turn_matr);
			temp = 0.0;
			temp = (~turn_matr)*(*this);
			*this = 0;
			*this = temp * turn_matr;
		
			this->find_fault(fault);
		}
	}
	
	for (int i = 0; i < M_size; i++)
	{
		for (int j = 0; j < N_size; j++)
		{
			if (abs(this->M[i][j]) < precision)
				this->M[i][j] = 0;
			
		}
	}

	return *this;
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

int Matrix::get_X_size()
{
	return N_size;
}

int Matrix::get_Y_size()
{
	return M_size;
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

Matrix prepare_test_values(int number_of_values,Matrix &coefficients)
{

	Matrix test_values(number_of_values,coefficients.get_X_size(),0);
	for (int i = 0; i < number_of_values; i++)
	{
		for (int j = 1; j < coefficients.get_X_size(); j++)
		{
			test_values[i][j] = (1 + rand() % 1000)*pow(-1, rand());
			test_values[i][0] += test_values[i][j] * coefficients[0][j];

		}
		test_values[i][0] += coefficients[0][0] ;
		test_values[i][0] += ((rand()%5))*pow(-1, rand());
		

	}

	return test_values;
}

void Linear_regression(Matrix test_values) 
{
	Matrix A(test_values.get_X_size(), test_values.get_X_size(), 0);
	Matrix F(1, test_values.get_X_size(), 0.0);
	A[0][0] = test_values.get_Y_size();
	for (int i = 1; i < test_values.get_X_size(); i++)
	{
		for (int j=0; j < test_values.get_Y_size(); j++)
		{
			A[0][i] += test_values[j][i];
		}
		A[i][0] = A[0][i];
	}	
		
	for (int i = 1; i < test_values.get_X_size(); i++)

	{
		for (int k = 1; k < test_values.get_X_size(); k++)
		{
			for (int j=0; j < test_values.get_Y_size(); j++)
			{
				A[i][k] += test_values[j][i] * test_values[j][k];
			}
		}
		
		
	}

	//cout <<"matrix A "<<endl<< A;
	
	for (int j = 0; j < test_values.get_Y_size(); j++)
	{
		F[0][0] += test_values[j][0];
	}

	for (int i = 1; i < test_values.get_X_size(); i++)
	{
		for (int j = 0; j < test_values.get_Y_size(); j++)
		{
			
			F[0][i] += test_values[j][0]*test_values[j][i];
		}
	}
	//cout << "f=  "<<F;
	
	Matrix result(1, A.get_X_size(),0);
    A.method_gaussa(A,F,result);
    cout <<"result=  " << result;
 //   cout << "chek answer=  "<<A.chek_answer(F,result).norma();

}
