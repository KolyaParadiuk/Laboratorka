

#include<iostream>

#include"Matrix.h"

using namespace std;

int main()
{
	int N=3;
	Matrix data(N,N+1);
	Matrix data2(N,1);
	//cin >>data;

	cout << data<<endl;
	cout << ~data;


	system("pause");
	return 0;


}