#include <iostream>
#define Size 4
using namespace std;

int main(void)
{
	int Input;
	int arrA[Size][Size];
	int arrB[Size][Size];

	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			arrA[i][j] = Size * i + j;
		}
	}
	while (1)
	{
		for (int i = 0; i < Size; i++)
		{
			for (int j = 0; j < Size; j++)
			{
				cout << arrA[i][j] << "\t";
			}
			cout << endl << endl;
		}
		cout << "1.왼쪽  2.오른쪽" << endl;
		cin >> Input;
		if (Input == 1)
		{
			for (int i = 0; i < Size; i++)
			{
				for (int j = 0; j < Size; j++)
				{
					arrB[i][j] = arrA[j][Size - 1 - i];
				}
			}
			for (int i = 0; i < Size; i++)
			{
				for (int j = 0; j < Size; j++)
				{
					arrA[i][j] = arrB[i][j];
				}
			}
		}
		else if (Input == 2)
		{
			for (int i = 0; i < Size; i++)
			{
				for (int j = 0; j < Size; j++)
				{
					arrB[i][j] = arrA[Size - 1 - j][i];
				}
			}
			for (int i = 0; i < Size; i++)
			{
				for (int j = 0; j < Size; j++)
				{
					arrA[i][j] = arrB[i][j];
				}
			}
		}
	}

	return 0;
}