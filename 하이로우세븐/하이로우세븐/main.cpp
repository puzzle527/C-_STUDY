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

	string shape[4] = { "��", "��", "��", "��" };



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
	cout << "���̷ο켼�� ����!" << endl;

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
		cout << "���� ���� : 1.���� 2.�ο� 3.���� 4.������" << endl;
		cout << "�� ������ : " << MONEY << endl;

		cin >> Select;
		
		if (Select > 0 && Select < 4)
		{
			cout << "������ �ݾ��� �Է��ϼ���(10000 �̻�)." << endl;
			cin >> Bet;

			if (Bet < 10000)
			{
				cout << "�ݾ��� �ʹ� �����ϴ�. 10000���� ���� ����!" << endl;
				continue;
			}
			if (Bet > MONEY)
			{
				cout << "�������� �����մϴ�." << endl;
				continue;
			}

			if (Select == 1)
			{
				if (DECK[index + 5].CARD_NUM > 7)
				{
					cout << "�̰��." << endl;
					MONEY += Bet * 2;
				}
				else
				{
					cout << "����." << endl;
					MONEY -= Bet;
				}
			}
			else if (Select == 2)
			{
				if (DECK[index + 5].CARD_NUM < 7)
				{
					cout << "�̰��." << endl;
					MONEY += Bet * 2;
				}
				else
				{
					cout << "����." << endl;
					MONEY -= Bet;
				}
			}
			else
			{
				if (DECK[index + 5].CARD_NUM == 7)
				{
					cout << "�̰��." << endl;
					MONEY += Bet * 4;
				}
				else
				{
					cout << "����." << endl;
					MONEY -= Bet;
				}
			}
		}
		else if (Select == 4)
		{
			cout << "������ �����մϴ�." << endl;
			return 0;
		}
		else
		{
			cout << "�߸� �Է��ϼ̽��ϴ�. �ùٸ� ���ڸ� �Է��ϼ���." << endl;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1, '\n');
			}
			continue;
		}
		cout << "ī�� ���� : ";
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
			cout << "ī�带 �ٽ� �����մϴ�." << endl;
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
			cout << "�������� �ּ� ���ñݺ��� ���� �ֽ��ϴ�. ī���뿡�� �������ϴ�." << endl;
			return 0;
		}

	}
	return 0;
}