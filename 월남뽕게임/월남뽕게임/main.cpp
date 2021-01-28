#include <iostream>
#include <time.h>
void Suffle(int Deck[52]);

using namespace std;

int main(void)
{
	srand(time(NULL));

	int Deck[52];
	int Bet;
	int	Money = 10000;
	int i = 0;

	Suffle(Deck);

	cout << "월남뽕 게임" << endl;
	
	while (1)
	{
		cout << "내 소지금 : " << Money << endl;
		cout << Deck[i] << ' ' << Deck[i + 1] << ' ' << Deck[i + 2] << endl;
		cout << "베팅할 금액을 입력하세요(100 이상)" << endl;
		cin >> Bet;
		if (Deck[i] > Deck[i + 1])
		{
			int temp = Deck[i];
			Deck[i] = Deck[i + 1];
			Deck[i + 1] = temp;
		}
		if ((Deck[i + 2] > Deck[i]) && (Deck[i + 2] < Deck[i + 1]))
		{
			cout << "이겼다." << endl;
			Money += Bet * 2;
		}
		else
		{
			cout << "졌다." << endl;
			Money -= Bet;
		}
		i += 3;

		if (Money == 0)
		{
			cout << "파산" << endl;
			cout << "게임을 종료합니다." << endl;
			break;
		}
		if (i == 30)
		{
			cout << "덱을 다시 셔플합니다." << endl;
			Suffle(Deck);
			i = 0;
		}
	}


	return 0;
}

void Suffle(int Deck[52])
{
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			Deck[i * 4 + j] = i + 1;
		}
	}

	for (int i = 0; i < 1000; i++)
	{
		int src = rand() % 52;
		int dest = rand() % 52;

		int temp = Deck[src];
		Deck[src] = Deck[dest];
		Deck[dest] = temp;
	}
}