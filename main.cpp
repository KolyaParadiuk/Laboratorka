

#include<iostream>
#include"Matrix.h"

using namespace std;

int main()
{
	/*int N = 4;
	Matrix test(N, N);
	Matrix test1(test);
	Matrix B(1, N);
	Matrix B1(B);
	Matrix result(1, N);*/
	
	//cin >> test;
	//cin >> B;
	//cout << test<<endl;
	//cout << B<<endl;
	//result = test.method_gaussa(B);
	//cout << result;
	//cout << test1.chek_answer(B1, result).norma() << endl << " +++++++++++++++++++++++++++ " << endl;

	int N=20;
	int M = 5;
	Matrix coef(1,M);
	Matrix coef2(N, M,0);
	cout<< coef;
	coef2=prepare_test_values(N, coef);
	cout << coef2<<endl;
	Linear_regression(coef2);
	system("pause");
	return 0;


}