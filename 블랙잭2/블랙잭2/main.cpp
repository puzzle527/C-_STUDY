#include <time.h>
#include <iostream>
#include <string> 
#include <vector>
#define PLAYERNUM 3

using namespace std;

enum TRUMPNUM
{
	A = 1, J = 11, Q, K
};

struct CARD
{
	string shape;
	int number;

	void Print()
	{
		switch (number)
		{
		case A:
			cout << shape << 'A' << '\t';
			break;
		case J:
			cout << shape << 'J' << '\t';
			break;
		case Q:
			cout << shape << 'Q' << '\t';
			break;
		case K:
			cout << shape << 'K' << '\t';
			break;
		default:
			cout << shape << number << '\t';
			break;

		}
	}
};

struct PLAYER
{
	vector<CARD> hand;
	int sum;
	bool isLose = false;
	void PrintHandSum()
	{
		cout << "카드:";
		sum = 0;
		for (int i = 0; i < hand.size(); i++)
		{
			hand[i].Print();
			if (hand[i].number > 10)
			{
				sum += 10;
			}
			else
			{
				sum += hand[i].number;
			}
		}
		cout << "합:" << sum << endl;
	}
};

void Shuffle(CARD* deck, int size)
{
	for (int i = 0; i < 1000; i++)
	{
		int sour = rand() % size;
		int dest = rand() % size;

		CARD temp = deck[sour];
		deck[sour] = deck[dest];
		deck[dest] = temp;
	}


};

int main()
{
	srand((unsigned int)time(NULL));

	CARD deck[52];
	PLAYER pl[PLAYERNUM];
	PLAYER dl;

	for (int i = 0; i < PLAYERNUM; i++)
	{
		pl[i].sum = NULL;
	}
	dl.sum = NULL;

	for (int i = 0; i < 52; i++)
	{
		switch ((int)(i / 13))
		{
		case 0:
			deck[i].shape = "◆";
			break;
		case 1:
			deck[i].shape = "♠";
			break;
		case 2:
			deck[i].shape = "♥";
			break;
		case 3:
			deck[i].shape = "♣";
			break;
		}
		deck[i].number = i % 13 + 1;
	}

	Shuffle(deck, 52);

	int CardCount = 0;
	int Input = NULL;

	while (1)
	{
		cout << "블랙잭 게임 " << endl << endl;
		for (int i = 0; i < PLAYERNUM; i++)
		{
			pl[i].hand.push_back(deck[CardCount]);
			CardCount++;
			pl[i].hand.push_back(deck[CardCount]);
			CardCount++;

			while (1)
			{
				cout << "플레이어" << i + 1 << endl;
				pl[i].PrintHandSum();

				if (pl[i].sum > 21)
				{
					cout << "플레이어" << i + 1 << "패배" << endl;
					pl[i].isLose = true;
					pl[i].hand.clear();
					break;
				}

				cout << "더받기 1.y 2.n" << endl;
				cin >> Input;
				if (Input == 1)
				{
					pl[i].hand.push_back(deck[CardCount]);
					CardCount++;
				}
				else
				{
					//pl[i].hand.clear();
					pl[i].isLose = false;
					break;
				}
			}
			cout << endl;

		}
		cout << "딜러차례" << endl << endl;
		for (int i = 0; i < PLAYERNUM; i++)
		{
			if (pl[i].isLose == true)
				continue;

			dl.hand.push_back(deck[CardCount]);
			CardCount++;
			dl.hand.push_back(deck[CardCount]);
			CardCount++;

			cout << "딜러 vs 플레이어" << i + 1 << endl;
			while (1)
			{
				dl.PrintHandSum();

				if (dl.sum > 21)
				{
					cout << "딜러 패배" << endl;
					dl.hand.clear();
					break;
				}

				if (dl.sum < 17)
				{
					dl.hand.push_back(deck[CardCount]);
					CardCount++;
				}
				else
				{
					cout << "플레이어" << i + 1 << " 합 : " << pl[i].sum << endl;
					cout << "딜러 합 : " << dl.sum << endl;

					if (pl[i].sum > dl.sum)
						cout << "플레이어" << i + 1 << " 승리" << endl;

					else if (pl[i].sum < dl.sum)
						cout << "딜러 승리" << endl;

					else
						cout << "무승부" << endl;
					dl.hand.clear();
					break;
				}
			}
			pl[i].hand.clear();
			pl[i].hand.shrink_to_fit();
			cout << endl;
		}
		dl.hand.shrink_to_fit();
		Shuffle(deck, 52);
		CardCount = 0;
	}

	return 0;
}
