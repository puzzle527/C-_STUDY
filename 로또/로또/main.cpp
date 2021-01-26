#include <iostream>
#include <time.h>

using namespace std;

int main(void)
{
	int LottoNum[35];
	int Lucky[7] = { 3, 8, 17, 20, 27, 35, 26 };
	int Count = 0;

	srand(time(NULL));

	cout << "이번주 당첨 번호 : ";
	for (int i = 0; i < 6; i++)
	{
		cout << Lucky[i] << " ";
	}
	cout << "보너스 번호 : " << Lucky[6] << endl << endl;

	for (int i = 0; i < 35; i++)
	{
		LottoNum[i] = i + 1;
	}

		Count = 0;
		for (int i = 0; i < 1000; i++)
		{
			int nA = rand() % 35;
			int nB = rand() % 35;

			int temp = LottoNum[nA];
			LottoNum[nA] = LottoNum[nB];
			LottoNum[nB] = temp;
		}
		cout << "자신의 로또 번호 : ";
		for (int i = 0; i < 6; i++)
		{
			cout << LottoNum[i] << " ";
		}
		cout << "보너스 번호 : " << LottoNum[6] << endl << endl;
		cout << "당첨결과 : ";
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (Lucky[i] == LottoNum[j])
				{
					Count++;
					break;
				}
			}
		}

		switch (Count)
		{
		case 6:
		{
			cout << "축하 드립니다. 1등에 당첨되셨습니다!!" << endl;
			return 0;
		}
		case 5:
		{
			if (LottoNum[6] == Lucky[6])
				cout << "축하 드립니다. 2등에 당첨되셨습니다!!" << endl;
			else
				cout << "축하 드립니다. 3등에 당첨되셨습니다!!" << endl;
			break;
		}
		case 4:
		{
			cout << "축하 드립니다. 4등에 당첨되셨습니다!!" << endl;
			break;
		}
		case 3:
		{
			cout << "축하 드립니다. 5등에 당첨되셨습니다!!" << endl;
			break;
		}
		default:
		{
			cout << "낙첨되었습니다." << endl;
		}
	}

	return 0;
}