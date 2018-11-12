

#include<iostream>
#include"Matrix.h"
#include <locale>
#include "windows.h"


using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice=1,N;
	while (choice !=0)
	{
		cout << "Оберіть дію" << endl;
		cout << "1. розв’язання СЛАР " << endl;
		cout << "2. знаходження власних значень матриці (метод обертання Якобі) " << endl;
		cout << "3. Знаходження параметрів лінійної регресійної моделі по заданим точкам  " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{	
			
			cout << "Оберіть дію" << endl;
			cout<<"1.Метод Гаусса"<<endl;
			cout << "2.Метод Качмажа" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{

				cout << "Оберіть дію" << endl;
				cout << "1.Ручний ввід матриці" << endl;
				cout << "2.Автозаповнення матриці випадковими числами" << endl;
				cin >> choice;
				cout << "Введіть розмірність матриці  " << endl<<"N = "<<endl;
				cin >> N;
				switch (choice)
				{
				case 1:
				{
					Matrix coef(N, N,0);
					cout << "Введіть матрицю коефіцієнтів " << endl;
					cin >> coef;
					Matrix B(1, N, 0);
					Matrix result(1, N, 0);
					cout << "Введіть вільні члени" << endl;
					cin >> B;
					cout << "x=";
					coef.method_gaussa(coef,B,result);
					cout << result;
					break;

				}
				case 2:
				{
					Matrix coef(N, N);
					Matrix result(1, N);
					cout<< "Матриця коефіцієнтів"<<endl<<coef;
					Matrix B(1, N);
					cout<< "Вільні члени "<<endl<<B;
					
					coef.method_gaussa(coef,B,result);
				
					cout <<endl<< "x=";
					cout << result << endl;


					cout << coef.chek_answer(B, result).norma();
				
					
					break;
				}

				

				default:
					break;
				}
				break;
			}
			case 2:
			{
				cout << "Оберіть дію" << endl;
				cout << "1.Ручний ввід матриці" << endl;
				cout << "2.Автозаповнення матриці випадковими числами" << endl;
				cout << "3.Використати матрицю Гільберта з випадковими вільними членами" << endl;
				cout << "4.Використати матрицю Гільберта з введеними в ручну вільними членами" << endl;
				cin >> choice;
				cout << "Введіть розмірність матриці  " << endl << "N = " << endl;
				cin >> N;
				switch (choice)
				{
				case 1:
				{
					Matrix coef(N, N, 0);
					cout << "Введіть матрицю коефіцієнтів " << endl;
					cin >> coef;
					Matrix B(1, N, 0);
					cout << "Введіть вільні члени" << endl;
					cin >> B;
					cout << "x=";
					cout << coef.method_kachmaga(B);
					break;
				}
				case 2:
				{
					Matrix coef(N, N);
					cout << "Матриця коефіцієнтів " <<endl<<coef<< endl;
				
					Matrix B(1, N);
					Matrix result(1, N);
					cout << "Вільні члени" <<endl<<B<< endl;
					
					cout << "x=";
					result=coef.method_kachmaga(B);
					cout << result;
					cout << "a*x-b   " <<((result*coef-B).norma())<<endl;

					cout <<"chekanswer   " <<coef.chek_answer(B,result).norma();
					break;
				}
				case 3:
				{
					Matrix coef(N, N);
					coef.set_gilbert_matrix();
					Matrix result(1, N);
					cout << "Матриця коефіцієнтів " << endl << coef << endl;
					Matrix B(1, N);
					for (int i = 0; i < N; i++)
					{
						B[0][i] = i+1;
					}
					cout << "Вільні члени" << endl << B << endl;
					cout << "x=";
					result = coef.method_kachmaga(B);
					cout << result;
					cout << "a*x-b   " << ((result*coef - B).norma()) << endl;

				
					break;
				}
				case 4:
				{
					Matrix coef(N, N);
					coef.set_gilbert_matrix();
					cout << "Матриця коефіцієнтів " << endl << coef << endl;
					Matrix B(1, N);
					cout << "Введіть вільні члени" << endl;
					cin >> B;
					

					cout << "x=";
					cout << coef.method_kachmaga(B);
					break;
				}
				default:
					break;
				}
				break;
			}
			default:
				break;
			}
			break;
		}
		case 2:
		{
			cout << "Оберіть дію" << endl;
			cout << "1.Ручний ввід матриці" << endl;
			cout << "2.Автозаповнення матриці випадковими числами" << endl;
			cin >> choice;
			cout << "Введіть розмірність матриці  " << endl << "N = " << endl;
			cin >> N;
			switch (choice)
			{
			case 1:
			{
				Matrix coef(N, N, 0);
				cout << "Введіть матрицю коефіцієнтів " << endl;
				cin >> coef;
				cout << coef.method_yakoby();
				break;
			}
			case 2:
			{
				Matrix coef(N, N);
				coef.set_simetrial_matrix();
				cout << "Матриця коефіцієнтів " << endl << coef << endl;
				cout << coef.method_yakoby();
				break;
			}
			default:
				break;
			}
			
			break;
		}
		case 3:
		{
			int N;
		 	int M;
			cout << "введіть кількість параметрів n"<<endl;
			cin >> N;

			cout << "введіть коефіцієни b0,b1,...,bn";
			Matrix B(1,N);
			cin >> B;
			cout << "Введіть кількість точок";
			cin >> M;
			Matrix A(M, N, 0);
			A=prepare_test_values(M, B);
			Linear_regression(A);

		}
		default:
			break;


		}

	}



system("pause");
	return 0;


}