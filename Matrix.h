#pragma once

#include<iostream>

using namespace std;
class Matrix
{

private:
	double **M ;
	int M_size;
	int N_size;
	int nomber;

	static int counter;
	static int nomber_of_existing_items;
	bool isSimmetrial();

public: 
	Matrix();
	Matrix(int,int);
	Matrix(int,int ,double);
	Matrix(Matrix&);
	Matrix(Matrix&,int);
	~Matrix();

	void dispose();

	void set_simetrial_matrix();
	void set_one_matrix();

	void set_gilbert_matrix();
	
	Matrix& operator =( const Matrix& M1);
	Matrix & operator=(const double & that);
	bool operator == ( Matrix &M1);
	Matrix operator + ( Matrix &that);
	Matrix operator - ( Matrix &that);
	Matrix operator * ( Matrix &that);
	Matrix operator * ( double &that);
	double* operator [](int);
	friend Matrix operator ~(Matrix that);
	friend ostream & operator<<(ostream & os, const Matrix & that);
	friend istream & operator>>(istream & os, const Matrix & that);

	Matrix multiplication(Matrix&);
	Matrix multiplication(double&);
	Matrix substaction(const Matrix&);
	Matrix addition( Matrix&);

	double norma();
	double skal_dob(Matrix&);
	Matrix chek_answer(Matrix,Matrix);

	int get_X_size();
	int get_Y_size();

	void method_gaussa(Matrix ,Matrix, Matrix&);
	Matrix method_kachmaga(Matrix);
	double find_fault(double &);
	void find_max(int &, int &);
	void prepare_turn_matrix(const int & Imax, const int & Jmax,Matrix& );
	Matrix method_yakoby();
	

};

Matrix prepare_test_values(int number_of_values, Matrix &coefficients);
void Linear_regression(Matrix test_values);