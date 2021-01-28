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

	cout << "������ ����" << endl;
	
	while (1)
	{
		cout << "�� ������ : " << Money << endl;
		cout << Deck[i] << ' ' << Deck[i + 1] << ' ' << Deck[i + 2] << endl;
		cout << "������ �ݾ��� �Է��ϼ���(100 �̻�)" << endl;
		cin >> Bet;
		if (Deck[i] > Deck[i + 1])
		{
			int temp = Deck[i];
			Deck[i] = Deck[i + 1];
			Deck[i + 1] = temp;
		}
		if ((Deck[i + 2] > Deck[i]) && (Deck[i + 2] < Deck[i + 1]))
		{
			cout << "�̰��." << endl;
			Money += Bet * 2;
		}
		else
		{
			cout << "����." << endl;
			Money -= Bet;
		}
		i += 3;

		if (Money == 0)
		{
			cout << "�Ļ�" << endl;
			cout << "������ �����մϴ�." << endl;
			break;
		}
		if (i == 30)
		{
			cout << "���� �ٽ� �����մϴ�." << endl;
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