#pragma once

#include<iostream>

using namespace std;
class Matrix
{

private:
	double **M ;
	int M_size;
	int N_size;

public: 
	Matrix(int,int);
	Matrix(int,int ,double);
	Matrix operator =( Matrix &M1);
	bool operator == ( Matrix &M1);
	Matrix operator + ( Matrix &that);
	Matrix operator - ( Matrix &that);
	Matrix operator * ( Matrix &that);
	Matrix operator * ( double &that);
	double* operator [](int);
	friend Matrix operator ~(Matrix that);
	friend ostream & operator<<(ostream & os, const Matrix & that);
	friend istream & operator>>(istream & os, const Matrix & that);
	int get_size();

	double norma();
	double skal_dob(Matrix);

	void method_gaussa();
	void method_kachmaga();



};

