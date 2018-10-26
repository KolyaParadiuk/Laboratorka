

#include<iostream>

#include"Matrix.h"

using namespace std;

int main()
{
	int N=5;
	double k = 0.2;

	Matrix data(N,N);
	Matrix data2(1,N);
	
	
	
	
	cout<<endl<<data.method_kachmaga(data2);



	system("pause");
	return 0;


}