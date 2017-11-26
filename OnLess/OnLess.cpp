// OnLess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "ctime"

using namespace std;

int main()
{
	srand(time(NULL));

	bool want = false;

	while (want == true)
	{

		int range;
		int Width;
		int Height;

		cout << "Range = ";
		cin >> range;
		cout << "Width = ";
		cin >> Width;
		cout << "Height = ";
		cin >> Height;

		// Динамические массивы
		int *arrX = new int[Width];
		int *count = new int[range + 1];

		for (int j = 0; j <= range; j++)
		{
			count[j] = 0;
		}

		for (int y = 0; y < Height; y++)
		{
			for (int i = 0; i < Width; i++)
			{
				arrX[i] = rand() % (range + 1);
				cout << arrX[i];

				// Можно   

				if (arrX[i] <= 9)
				{
					cout << "    ";
				}
				else if ((10 >= arrX[i]) || (arrX[i] <= 99))
				{
					cout << "   ";
				}
				else if ((100 >= arrX[i]) || (arrX[i] <= 999))
				{
					cout << "  ";
				}
				else if ((1000 >= arrX[i]) || (arrX[i] <= 9999))
				{
					cout << " ";
				}

				// Подсчёт кол-ва разных чи 
				for (int j = 0; j <= range; j++)
				{
					if (arrX[i] == j)
					{
						count[j] = count[j] + 1;
					}
				}
			}
			cout << endl;
		}

		// Вывод кол-ва разных чисел
		for (int j = 0; j <= range; j++)
		{
			cout << j << "_element = " << count[j] << endl;
		}

		// Переменные для поиска наиболшего и наименьшего числа
		int minValue = range + 1;
		int maxValue = 0;
		int j = 0;
		// Запись индексов чисел
		int maxj = 0;
		int minj = 0;

		// Нахождение наиболшего числа
		for (j; j <= range; j++)
		{
			if (count[j] > maxValue)
			{
				maxValue = count[j];
				maxj = j;
			}
		}

		// Обнуление j-элемента
		j = 0;

		// Нахождение наименьшего числа
		for (j; j <= range; j++)
		{
			if (count[j] < minValue)
			{
				minValue = count[j];
				minj = j;
			}
		}

		// Вывод наиболшего и наименьшего числа
		cout << "minValue = " << minj << "_element = " << minValue << endl;
		cout << "maxValue = " << maxj << "_element = " << maxValue << endl;

		// Рестарт
		cout << "Want else ? (0 or 1) \n";
		cin >> want;
		if (want == 1) system("CLS");
	}

	system("pause");
	return 0;
}


