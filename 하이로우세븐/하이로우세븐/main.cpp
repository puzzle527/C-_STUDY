#include <iostream>
#include <string>
#include <time.h>
#include <Windows.h>
#define CARD_MAX 52

using namespace std;

struct TRUMP_CARD
{
	int		CARD_NUM;
	string	CARD_SHAPE;
};

int main(void)
{
	srand(time(NULL));

	int MONEY = 100000;
	int index = 0;
	int Bet, Select;

	string shape[4] = { "♠", "♥", "♣", "◆" };



	TRUMP_CARD DECK[CARD_MAX];

	for (int i = 0; i < CARD_MAX/13; i++)
	{
		for (int j = 0; j < CARD_MAX/4; j++)
		{
			DECK[(i * 13) + j].CARD_NUM = j + 1;
			DECK[(i * 13) + j].CARD_SHAPE = shape[i];
		}
	}
	// 0 1 2 3 4 5 6 7 8 9 10 11 12

	for (int i = 0; i < 1000; i++)
	{
		int src = rand() % CARD_MAX;
		int dest = rand() % CARD_MAX;

		TRUMP_CARD temp = DECK[dest];
		DECK[dest] = DECK[src];
		DECK[src] = temp;
	}
	cout << "하이로우세븐 게임!" << endl;

	while (1)
	{
		for (int i = index; i < index + 5; i++)
		{
			if (DECK[i].CARD_NUM == 1)
				cout << 'A';
			else if (DECK[i].CARD_NUM == 11)
				cout << 'J';
			else if (DECK[i].CARD_NUM == 12)
				cout << 'Q';
			else if (DECK[i].CARD_NUM == 13)
				cout << 'K';
			else
				cout << DECK[i].CARD_NUM;
			cout << DECK[i].CARD_SHAPE << '\t';
		}
		cout << "???" << endl;
		cout << "베팅 선택 : 1.하이 2.로우 3.세븐 4.나가기" << endl;
		cout << "내 소지금 : " << MONEY << endl;

		cin >> Select;
		
		if (Select > 0 && Select < 4)
		{
			cout << "베팅할 금액을 입력하세요(10000 이상)." << endl;
			cin >> Bet;

			if (Bet < 10000)
			{
				cout << "금액이 너무 적습니다. 10000부터 베팅 가능!" << endl;
				continue;
			}
			if (Bet > MONEY)
			{
				cout << "소지금이 부족합니다." << endl;
				continue;
			}

			if (Select == 1)
			{
				if (DECK[index + 5].CARD_NUM > 7)
				{
					cout << "이겼다." << endl;
					MONEY += Bet * 2;
				}
				else
				{
					cout << "졌다." << endl;
					MONEY -= Bet;
				}
			}
			else if (Select == 2)
			{
				if (DECK[index + 5].CARD_NUM < 7)
				{
					cout << "이겼다." << endl;
					MONEY += Bet * 2;
				}
				else
				{
					cout << "졌다." << endl;
					MONEY -= Bet;
				}
			}
			else
			{
				if (DECK[index + 5].CARD_NUM == 7)
				{
					cout << "이겼다." << endl;
					MONEY += Bet * 4;
				}
				else
				{
					cout << "졌다." << endl;
					MONEY -= Bet;
				}
			}
		}
		else if (Select == 4)
		{
			cout << "게임을 종료합니다." << endl;
			return 0;
		}
		else
		{
			cout << "잘못 입력하셨습니다. 올바른 숫자를 입력하세요." << endl;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1, '\n');
			}
			continue;
		}
		cout << "카드 공개 : ";
		if (DECK[index + 5].CARD_NUM == 1)
			cout << 'A';
		else if (DECK[index + 5].CARD_NUM == 11)
			cout << 'J';
		else if (DECK[index + 5].CARD_NUM == 12)
			cout << 'Q';
		else if (DECK[index + 5].CARD_NUM == 13)
			cout << 'K';
		else
			cout << DECK[index + 5].CARD_NUM;
		cout << DECK[index + 5].CARD_SHAPE << endl;

		Sleep(1000);
		system("cls");
		index += 6;

		if (CARD_MAX - index <= 16)
		{
			cout << "카드를 다시 셔플합니다." << endl;
			for (int i = 0; i < 1000; i++)
			{
				int src = rand() % CARD_MAX;
				int dest = rand() % CARD_MAX;

				TRUMP_CARD temp = DECK[dest];
				DECK[dest] = DECK[src];
				DECK[src] = temp;
			}
			index == 0;
		}
		if (MONEY < 10000)
		{
			cout << "소지금이 최소 베팅금보다 적게 있습니다. 카지노에서 나가집니다." << endl;
			return 0;
		}

	}
	return 0;
}