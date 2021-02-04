#include <iostream>
#include <time.h> 
#include <Windows.h>
#define CHECK -1

using namespace std;

void BingoInit(int (*Bingo)[5], int Row, int Col);
void Shuffle(int (*Bingo)[5], int Row, int Col);
void Print(int (*Bingo)[5], int Row, int Col);
void InputCheck(int (*Bingo)[5], int Row, int Col, int Input);
int BINGO(int (*Bingo)[5], int Row, int Col);


int main(void)
{
	const int Row = 5;
	const int Col = 5;
	int PBingo[Row][Col];
	int CBingo[Row][Col];
	int PCnt = 0;
	int CCnt = 0;

	srand(time(NULL));

	int PInput;
	int CInput;
	int i = 0;

	BingoInit(PBingo, Row, Col);
	BingoInit(CBingo, Row, Col);

	Shuffle(PBingo, Row, Col);
	Shuffle(CBingo, Row, Col);

	while (1)
	{
		cout << "플레이어 빙고" << endl << endl;
		cout << "플레이어 빙고 갯수 : " << PCnt << endl;
		cout << "숫자를 입력하세요." << endl << endl;
		Print(PBingo, Row, Col);

		cout << "컴퓨터 빙고" << endl << endl;
		cout << "컴퓨터 빙고 갯수 : " << CCnt << endl << endl;
		Print(CBingo, Row, Col);

		PCnt = 0;
		CCnt = 0;

		cin >> PInput;

		InputCheck(PBingo, Row, Col, PInput);
		InputCheck(CBingo, Row, Col, PInput);
		system("cls");

		while (1)
		{
			CInput = CBingo[rand() % Row][rand() % Col];
			if (CInput != CHECK)
				break;
		}
		cout << "컴퓨터 숫자 : " << CInput << endl;
		Sleep(500);
		InputCheck(PBingo, Row, Col, PInput);
		InputCheck(CBingo, Row, Col, PInput);
		system("cls");

		PCnt = BINGO(PBingo, Row, Col);
		CCnt = BINGO(CBingo, Row, Col);
	}


	return 0;
}

void Shuffle(int(*Bingo)[5], int Row, int Col)
{
	for (int i = 0; i < 1000; i++)
	{
		int sourrow = rand() % Row;
		int destrow = rand() % Row;

		int sourcol = rand() % Col;
		int destcol = rand() % Col;

		int temp = Bingo[sourrow][sourcol];
		Bingo[sourrow][sourcol] =
			Bingo[destrow][destcol];
		Bingo[destrow][destcol] = temp;
	}
}

void BingoInit(int (*Bingo)[5], int Row, int Col)
{
	int Num[50];

	for (int i = 0; i < 50; i++)
	{
		Num[i] = i + 1;
	}
	for (int i = 0; i < 1000; i++)
	{
		int dest = rand() % 50;
		int src = rand() % 50;

		int temp = Num[dest];
		Num[dest] = Num[src];
		Num[src] = temp;
	}

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			Bingo[i][j] = Num[i * Col + j];
		}
	}
}

void Print(int (*Bingo)[5], int Row, int Col)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Bingo[i][j] == CHECK)
				cout << 'X' << '\t';
			else
				cout << Bingo[i][j] << '\t';
		}
		cout << endl << endl << endl;
	}
}

void InputCheck(int(*Bingo)[5], int Row, int Col, int Input)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Input == Bingo[i][j])
			{
				Bingo[i][j] = CHECK;
				return;
			}
		}
	}
}

int BINGO(int(*Bingo)[5], int Row, int Col)
{
	int CalCro1 = 0;
	int CalCro2 = 0;
	int Cnt = 0;

	for (int i = 0; i < Row; i++)
	{
		int CalRow = 0;
		int CalCol = 0;

		for (int j = 0; j < Col; j++)
		{
			if (Bingo[i][j] == CHECK)
				CalRow++;
			if (Bingo[j][i] == CHECK)
				CalCol++;
			if ((i == j) && (Bingo[i][j]) == CHECK)
				CalCro1++;
			if ((i + j == Row - 1) && (Bingo[i][j]) == CHECK)
				CalCro2++;
		}
		if (CalRow == Row)
			Cnt++;
		if (CalCol == Col)
			Cnt++;
	}
	if (CalCro1 == Row)
		Cnt++;
	if (CalCro2 == Row)
		Cnt++;

	return Cnt;
}