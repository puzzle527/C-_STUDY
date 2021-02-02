#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

const int Row = 5;
const int Col = 5;
int Bingo[Row][Col];

int main(void)
{
	srand(time(NULL));

	int Input;
	int Cnt = 0;

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			Bingo[i][j] = (Row * i + j) + 1;
		}
	}
	for (int i = 0; i < 1000; i++)
	{
		int Rdest = rand() % Row;
		int Rsrc = rand() % Row;
		int Cdest = rand() % Col;
		int Csrc = rand() % Col;

		int temp = Bingo[Rdest][Cdest];
		Bingo[Rdest][Cdest] = Bingo[Rsrc][Csrc];
		Bingo[Rsrc][Csrc] = temp;
	}
	while (1)
	{
		cout << "빙고 게임" << endl << endl;
		cout << "빙고 카운트 : " << Cnt << endl << endl;

		if (Cnt >= 3)
		{
			cout << "빙고" << endl;
			break;
		}
		else
			Cnt = 0;

		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				if(Bingo[i][j] == 35)
					cout << static_cast<char>(Bingo[i][j]) << '\t';
				else
					cout << Bingo[i][j] << '\t';
			}
			cout << endl << endl << endl;
		}

		cout << "숫자를 입력하세요" << endl;
		cin >> Input;

		for (int i = 0; i < Row; i++)
		{
			for (int j = 0; j < Col; j++)
			{
				if (Input == Bingo[i][j])
				{
					Bingo[i][j] = 35;
					system("cls");
				}
			}
		}
		int CalCro1 = 0;
		int CalCro2 = 0;

		for (int i = 0; i < Row; i++)
		{
			int CalRow = 0;
			int CalCol = 0;

			for (int j = 0; j < Col; j++)
			{
				if (Bingo[i][j] == 35)
					CalRow++;
				if (Bingo[j][i] == 35)
					CalCol++;
				if ((i == j) && (Bingo[i][j]) == 35)
					CalCro1++;
				if ((i + j == Row - 1) && (Bingo[i][j]) == 35)
					CalCro2++;
			}
			if (CalRow == Row)
				Cnt++;
			if(CalCol == Col)
				Cnt++;
		}
		if (CalCro1 == Row)
			Cnt++;
		if (CalCro2 == Row)
			Cnt++;
	}
	return 0;
}