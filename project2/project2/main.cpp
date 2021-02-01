#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

int main(void)
{
	srand(time(NULL));

	int Arr[36] = { 0, };
	int Num[16];
	int Select;
	int idx = 7;

	for (int i = 0; i < 16; i++)
	{
		Num[i] = i;
	}
	for (int i = 0; i < 100; i++)
	{
		int dest = rand() % 15 + 1;
		int src = rand() % 15 + 1;

		int temp = Num[dest];
		Num[dest] = Num[src];
		Num[src] = temp;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Arr[(6 * (i + 1)) + (j + 1)] = Num[i*4 + j];
		}
	}

	/*for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << Arr[6 * i + j] << '\t';
		}
		cout << endl << endl;
	}*/

	while (1)
	{
		cout << "숫자퍼즐게임" << endl << endl;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << Arr[(6 * (i + 1)) + (j + 1)] << '\t';
			}
			cout << endl << endl;
		}
		cout << "2.아래 4.왼쪽 6.오른쪽 8.위" << endl;
		cin >> Select;

		if (Select == 2)
		{
			if (Arr[idx] == Arr[idx + 6])
			{
				cout << "아래쪽으로 갈 수 없습니다." << endl;
				Sleep(1000);
				system("cls");
				continue;
			}
			int temp = Arr[idx];
			Arr[idx] = Arr[idx + 6];
			Arr[idx + 6] = temp;
			idx += 6;
		}
		else if (Select == 4)
		{
			if (Arr[idx] == Arr[idx - 1])
			{
				cout << "왼쪽으로 갈 수 없습니다." << endl;
				Sleep(1000);
				system("cls");
				continue;
			}
			int temp = Arr[idx];
			Arr[idx] = Arr[idx - 1];
			Arr[idx - 1] = temp;
			idx -= 1;
		}
		else if (Select == 6)
		{
			if (Arr[idx] == Arr[idx + 1])
			{
				cout << "오른쪽으로 갈 수 없습니다." << endl;
				Sleep(1000);
				system("cls");
				continue;
			}
			int temp = Arr[idx];
			Arr[idx] = Arr[idx + 1];
			Arr[idx + 1] = temp;
			idx += 1;
		}
		else if (Select == 8)
		{
			if (Arr[idx] == Arr[idx - 6])
			{
				cout << "위쪽으로 갈 수 없습니다." << endl;
				Sleep(1000);
				system("cls");
				continue;
			}
			int temp = Arr[idx];
			Arr[idx] = Arr[idx - 6];
			Arr[idx - 6] = temp;
			idx -= 6;
		}
		system("cls");
	}

	return 0;
}