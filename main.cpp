

#include<iostream>

#include"Matrix.h"

using namespace std;

int main()
{
	int N=3;
	Matrix data(N,1);
	Matrix data2(N,1);
	//cin >>data;

	cout << data*data2;

	system("pause");
	return 0;


}