

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


	Matrix coef(1,2);
	Matrix coef2(10, 2);
	cin >> coef;
	cout << coef << endl;
	coef2=prepare_test_values(10, coef);
	cout << coef2<<endl;
	Linear_regression(coef2);
	system("pause");
	return 0;


}