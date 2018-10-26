

#include<iostream>

#include"Matrix.h"

using namespace std;

int main()
{
	int N=5;
	

	Matrix A(N,N);
	Matrix B(1,N);
	Matrix result(1, N);
	cout << A<<endl;
	cout << B<<endl;

	result=A.method_kachmaga(B);
	cout << result;
	cout<<	A.chek_answer(B, result).norma();


	system("pause");
	return 0;


}