#pragma once

#include<iostream>

using namespace std;
class Matrix
{

private:
	double **M ;
	int M_size;

public:
	Matrix(int);
	Matrix(int,int);
	Matrix operator =(const Matrix &M1);
	bool operator == (const Matrix &M1);
	Matrix operator + (const Matrix &that);
	Matrix operator - (const Matrix &that);
	Matrix operator * (const Matrix &that);
	Matrix operator * (const double &that);
	double* operator [](int);
	friend Matrix operator ~(Matrix that);
	friend ostream & operator<<(ostream & os, const Matrix & that);
	friend istream & operator>>(istream & os, const Matrix & that);



	int get_size();





};

