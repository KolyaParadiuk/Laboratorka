

#include<iostream>
#include"Matrix.h"

using namespace std;

int main()
{
	int N=50;
	

	Matrix A(N,N);
	Matrix result(1, N);
	A.set_simetrial_matrix();
	cout<<A;
	A.method_yakoby();
	cout << A << endl;
		


	system("pause");
	return 0;


}