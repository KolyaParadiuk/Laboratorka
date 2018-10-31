

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
		cout << "������ ��" << endl;
		cout << "1. ���������� ���� " << endl;
		cout << "2. ����������� ������� ������� ������� (����� ��������� ����) " << endl;
		cout << "3. ����������� ��������� ����� ��������� ����� �� ������� ������  " << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{	
			
			cout << "������ ��" << endl;
			cout<<"1.����� ������"<<endl;
			cout << "2.����� �������" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{

				cout << "������ ��" << endl;
				cout << "1.������ ��� �������" << endl;
				cout << "2.�������������� ������� ����������� �������" << endl;
				cin >> choice;
				cout << "������ ��������� �������  " << endl<<"N = "<<endl;
				cin >> N;
				switch (choice)
				{
				case 1:
				{
					Matrix coef(N, N, 0);
					cout << "������ ������� ����������� " << endl;
					cin >> coef;
					Matrix B(1, N, 0);
					cout << "������ ���� �����" << endl;
					cin >> B;
					cout << "x=";
					cout<<coef.method_gaussa(B);
					break;
				}
				case 2:
				{
					Matrix coef(N, N);
					cout<< "������� �����������"<<endl<<coef;
					Matrix B(1, N);
					cout<< "³��� ����� "<<endl<<B;
					cout << "x=";
					cout << coef.method_gaussa(B);
					break;
				}
				
				default:
					break;
				}
				break;
			}
			case 2:
			{
				cout << "������ ��" << endl;
				cout << "1.������ ��� �������" << endl;
				cout << "2.�������������� ������� ����������� �������" << endl;
				cout << "3.����������� ������� ó������� � ����������� ������� �������" << endl;
				cout << "4.����������� ������� ó������� � ��������� � ����� ������� �������" << endl;
				cin >> choice;
				cout << "������ ��������� �������  " << endl << "N = " << endl;
				cin >> N;
				switch (choice)
				{
				case 1:
				{
					Matrix coef(N, N, 0);
					cout << "������ ������� ����������� " << endl;
					cin >> coef;
					Matrix B(1, N, 0);
					cout << "������ ���� �����" << endl;
					cin >> B;
					cout << "x=";
					cout << coef.method_kachmaga(B);
					break;
				}
				case 2:
				{
					Matrix coef(N, N);
					cout << "������� ����������� " <<endl<<coef<< endl;
				
					Matrix B(1, N);
					cout << "³��� �����" <<endl<<B<< endl;
					
					cout << "x=";
					cout << coef.method_kachmaga(B);
					break;
				}
				case 3:
				{
					Matrix coef(N, N);
					coef.set_gilbert_matrix();
					cout << "������� ����������� " << endl << coef << endl;
					Matrix B(1, N);
					cout << "³��� �����" << endl << B << endl;
					

					cout << "x=";
					cout << coef.method_kachmaga(B);
					break;
				}
				case 4:
				{
					Matrix coef(N, N);
					coef.set_gilbert_matrix();
					cout << "������� ����������� " << endl << coef << endl;
					Matrix B(1, N);
					cout << "������ ���� �����" << endl;
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
			cout << "������ ��" << endl;
			cout << "1.������ ��� �������" << endl;
			cout << "2.�������������� ������� ����������� �������" << endl;
			cin >> choice;
			cout << "������ ��������� �������  " << endl << "N = " << endl;
			cin >> N;
			switch (choice)
			{
			case 1:
			{
				Matrix coef(N, N, 0);
				cout << "������ ������� ����������� " << endl;
				cin >> coef;
				cout << coef.method_yakoby();
				break;
			}
			case 2:
			{
				Matrix coef(N, N);
				coef.set_simetrial_matrix();
				cout << "������� ����������� " << endl << coef << endl;
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

		}
		default:
			break;


		}

	}
	system("pause");
	return 0;


}