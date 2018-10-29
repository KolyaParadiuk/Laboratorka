const double PI = 3.1415926536;

bool isSimmetrial(double **coefficients, int numberOfEquation)
{
	for (int i = 0; i < numberOfEquation; i++)
	{
		for (int j = i + 1; j < numberOfEquation; j++)
		{
			if (coefficients[i][j] != coefficients[j][i]) 		return false;
		}
	}
	return true;
}
int wrachenie(double **coefficients, int numberOfEquation, double **solution, double precision)
{
	
	int maxI, maxJ;
	double max, fi;
	double** temp;
	
	double fault = 0.0;
	for (i = 0; i < numberOfEquation; i++)
	{
		for (j = i + 1; j < numberOfEquation; j++)
		{
			fault = fault + coefficients[i][j] * coefficients[i][j];
		}
	}
	fault = sqrt(2 * fault);
	while (fault > precision)
	{
		max = 0.0;
		for (i = 0; i < numberOfEquation; i++)
		{
			for (j = i + 1; j < numberOfEquation; j++)
			{
				if (coefficients[i][j] > 0 && coefficients[i][j] > max)
				{
					max = coefficients[i][j];
					maxI = i;
					maxJ = j;
				}
				else if (coefficients[i][j] < 0 && -coefficients[i][j] > max)
				{
					max = -coefficients[i][j];
					maxI = i;
					maxJ = j;
				}
			}
		}
		for (i = 0; i < numberOfEquation; i++)
		{
			for (j = 0; j < numberOfEquation; j++)
			{
				matricaPoworota[i][j] = 0;
			}
			matricaPoworota[i][i] = 1;
		}
		if (coefficients[maxI][maxI] == coefficients[maxJ][maxJ])
		{
			matricaPoworota[maxI][maxI] = matricaPoworota[maxJ][maxJ] = matricaPoworota[maxJ][maxI] = sqrt(2.0) / 2.0;
			matricaPoworota[maxI][maxJ] = -sqrt(2.0) / 2.0;
		}
		else
		{
			fi = 0.5 * atan((2.0 * coefficients[maxI][maxJ]) / (coefficients[maxI][maxI] - coefficients[maxJ][maxJ]));
			matricaPoworota[maxI][maxI] = matricaPoworota[maxJ][maxJ] = cos(fi);
			matricaPoworota[maxI][maxJ] = -sin(fi);
			matricaPoworota[maxJ][maxI] = sin(fi);
		}
		for (i = 0; i < numberOfEquation; i++)
		{
			for (j = 0; j < numberOfEquation; j++)
			{
				temp[i][j] = 0.0;
			}
		}
		for (i = 0; i < numberOfEquation; i++)
		{
			for (j = 0; j < numberOfEquation; j++)
			{
				for (k = 0; k < numberOfEquation; k++)
				{
					temp[i][j] = temp[i][j] + matricaPoworota[k][i] * coefficients[k][j];
				}
			}
		}
		for (i = 0; i < numberOfEquation; i++)
		{
			for (j = 0; j < numberOfEquation; j++)
			{
				coefficients[i][j] = 0.0;
			}
		}
		for (i = 0; i < numberOfEquation; i++)
		{
			for (j = 0; j < numberOfEquation; j++)
			{
				for (k = 0; k < numberOfEquation; k++)
				{
					coefficients[i][j] = coefficients[i][j] + temp[i][k] * matricaPoworota[k][j];
				}
			}
		}
			fault = 0.0;
			for (i = 0; i < numberOfEquation; i++)
			{
				for (j = i + 1; j < numberOfEquation; j++)
				{
					fault = fault + coefficients[i][j] * coefficients[i][j];
				}
			}
			fault = sqrt(2 * fault);
			
		}
		return result;
	}

	using namespace std;

	void main()
	{
		

		
		double **coefficients, **solution, precision;
		
		
		
		
	}
	
	
	if (!isSimmetrial(coefficients, size))
	{
		cout << "Матрица не симметричная";
	}
	else
	{
		int steps = wrachenie(coefficients, size, solution, precision);
		cout << "Reshenie:\n";
		for (i = 0; i < size; i++)
		{
			cout << "Собственный вектор k " << i + 1 << ":\n";
			for (j = 0; j < size; j++)
			{
				cout << solution[j][i] << "\n";
			}
		}
		cout << "Собственные значения:\n";
		for (i = 0; i < size; i++)
		{
			cout << coefficients[i][i] << "\n";
		}
		cout << "Общее число шагов: " << steps;
	}
	cout << "\nPress \"Enter\" to continue..." << endl;
	getchar();
}