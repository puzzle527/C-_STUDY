#include <iostream>
#include <time.h> 
#include <Windows.h>
#define CHECK -1

using namespace std;

const int Row = 5;
const int Col = 5;

int PBingo[Row][Col];
int CBingo[Row][Col];
int PCnt = 0;
int CCnt = 0;

void PShuffle();
void PBingoInit();
void PPrint();
void CShuffle();
void CBingoInit();
void CPrint();
void PInputCheck(int Input);
void CInputCheck(int Input);
void PBINGO();
void CBINGO();


int main(void)
{
	srand(time(NULL));

	int PInput;
	int CInput;
	int i = 0;

	PBingoInit();
	CBingoInit();

	PShuffle();
	CShuffle();

	while(1)
	{
		cout << "플레이어 빙고" << endl << endl;
		cout << "플레이어 빙고 갯수 : " << PCnt << endl;
		cout << "숫자를 입력하세요." << endl << endl;
		PPrint();

		cout << "컴퓨터 빙고" << endl << endl;
		cout << "컴퓨터 빙고 갯수 : " << CCnt << endl << endl;
		CPrint();

		PCnt = 0;
		CCnt = 0;
		
		cin >> PInput;

		PInputCheck(PInput);
		CInputCheck(PInput);
		system("cls");

		while (1)
		{
			CInput = CBingo[rand() % Row][rand() % Col];
			if (CInput != CHECK)
				break;
		}
		cout << "컴퓨터 숫자 : " << CInput << endl;
		Sleep(500);
		PInputCheck(CInput);
		CInputCheck(CInput);
		system("cls");

		PBINGO();
		CBINGO();
	}


	return 0;
}

void PShuffle()
{
	for (int i = 0; i < 1000; i++)
	{
		int sourrow = rand() % Row;
		int destrow = rand() % Row;

		int sourcol = rand() % Col;
		int destcol = rand() % Col;

		int temp = PBingo[sourrow][sourcol];
		PBingo[sourrow][sourcol] =
			PBingo[destrow][destcol];
		PBingo[destrow][destcol] = temp;
	}
}

void PBingoInit()
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
			PBingo[i][j] = Num[i * Col + j];
		}
	}
}

void PPrint()
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (PBingo[i][j] == CHECK)
				cout << 'X' << '\t';
			else
				cout << PBingo[i][j] << '\t';
		}
		cout << endl << endl << endl;
	}
}
void CShuffle()
{
	for (int i = 0; i < 1000; i++)
	{
		int sourrow = rand() % Row;
		int destrow = rand() % Row;

		int sourcol = rand() % Col;
		int destcol = rand() % Col;

		int temp = CBingo[sourrow][sourcol];
		CBingo[sourrow][sourcol] =
			CBingo[destrow][destcol];
		CBingo[destrow][destcol] = temp;
	}
}

void CBingoInit()
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
			CBingo[i][j] = Num[i * Col + j];
		}
	}
}

void CPrint()
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (CBingo[i][j] == CHECK)
				cout << 'X' << '\t';
			else
				cout << CBingo[i][j] << '\t';
		}
		cout << endl << endl << endl;
	}
}

void PInputCheck(int Input)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Input == PBingo[i][j])
			{
				PBingo[i][j] = CHECK;
				return;
			}
		}
	}
}

void CInputCheck(int Input)
{
	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Col; j++)
		{
			if (Input == CBingo[i][j])
			{
				CBingo[i][j] = CHECK;
				return;
			}
		}
	}
}
void PBINGO()
{
	int CalCro1 = 0;
	int CalCro2 = 0;

	for (int i = 0; i < Row; i++)
	{
		int CalRow = 0;
		int CalCol = 0;

		for (int j = 0; j < Col; j++)
		{
			if (PBingo[i][j] == CHECK)
				CalRow++;
			if (PBingo[j][i] == CHECK)
				CalCol++;
			if ((i == j) && (PBingo[i][j]) == CHECK)
				CalCro1++;
			if ((i + j == Row - 1) && (PBingo[i][j]) == CHECK)
				CalCro2++;
		}
		if (CalRow == Row)
			PCnt++;
		if (CalCol == Col)
			PCnt++;
	}
	if (CalCro1 == Row)
		PCnt++;
	if (CalCro2 == Row)
		PCnt++;
}
void CBINGO()
{
	int CalCro1 = 0;
	int CalCro2 = 0;

	for (int i = 0; i < Row; i++)
	{
		int CalRow = 0;
		int CalCol = 0;

		for (int j = 0; j < Col; j++)
		{
			if (CBingo[i][j] == CHECK)
				CalRow++;
			if (CBingo[j][i] == CHECK)
				CalCol++;
			if ((i == j) && (CBingo[i][j]) == CHECK)
				CalCro1++;
			if ((i + j == Row - 1) && (CBingo[i][j]) == CHECK)
				CalCro2++;
		}
		if (CalRow == Row)
			CCnt++;
		if (CalCol == Col)
			CCnt++;
	}
	if (CalCro1 == Row)
		CCnt++;
	if (CalCro2 == Row)
		CCnt++;
}