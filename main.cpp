

#include<iostream>

#include"Matrix.h"

using namespace std;

int main()
{
	int N=8;
	

	Matrix A(N,N);
	
	Matrix B(1,N);
	Matrix result(1, N);
	cout << A<<endl;
	cout << B<<endl;
	
	Matrix A1(A);
	result=A.method_gaussa(B);
	cout << result<<endl;
	cout<<	A1.chek_answer(B, result).norma()<<endl;


	system("pause");
	return 0;


}