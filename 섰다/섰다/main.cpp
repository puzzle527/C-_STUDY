#include <iostream>
#include <time.h>
#include <string>
#include <Windows.h>
#define Size 20

using namespace std;

struct CARD
{
	int		Number;
	string	Shape;
};

void InitDeck(CARD* DECK);
void Shuffle(CARD* DECK);
void ft_Delete(string* Player, CARD* DECK);
string CheckCard(CARD one, CARD two);
void Print(CARD* DECK, string* Player, int PlayerNum);
void VicPrint(CARD* DECK, string* Player, int PlayerNum);

int main(void)
{
	srand(time(NULL));

	CARD*		DECK;
	string*		Player;
	int			PlayerNum;

	cout << "����" << endl << endl;

	while (1)
	{
		DECK = new CARD[Size];

		cout << "�÷��̾� ���� �Է��ϼ��� : ";
		cin >> PlayerNum;
		if (PlayerNum > 10 || cin.fail())
		{
			cin.clear();
			cin.ignore(1, '\n');
			cout << "10�� ���Ϸ� �Է��ϼ���" << endl;
			Sleep(500);
			system("cls");
			continue;
		}

		Player = new string[PlayerNum];

		for (int i = 0; i < PlayerNum; i++)
		{
			cout << i + 1 << "��° �÷��̾� �̸��� �Է��ϼ��� : ";
			cin >> *(Player + i);
		}

		system("cls");

		InitDeck(DECK);
		Shuffle(DECK);
		Print(DECK, Player, PlayerNum);
		VicPrint(DECK, Player, PlayerNum);

		ft_Delete(Player, DECK);
	}

	return 0;
}

void InitDeck(CARD* DECK)
{
	for (int i = 0; i < Size; i++)
	{
		(DECK + i)->Number = i % 10 + 1;
		(DECK + i)->Shape = " ";
	}
	DECK->Shape = "��";
	(DECK + 2)->Shape = "��";
	(DECK + 7)->Shape = "��";
}

void Shuffle(CARD* DECK)
{
	for (int i = 0; i < 1000; i++)
	{
		int src = rand() % Size;
		int dest = rand() % Size;

		CARD temp = *(DECK + src);
		*(DECK + src) = *(DECK + dest);
		*(DECK + dest) = temp;
	}
}

string CheckCard(CARD one, CARD two)
{
	string str;

	if (one.Shape == "��" && two.Shape == "��")
	{
		if ((one.Number == 3 && two.Number == 8) || (one.Number == 8 && two.Number == 3))
			str = "3.8����";
		else if ((one.Number == 1 && two.Number == 8) || (one.Number == 8 && two.Number == 1))
			str = "1.8����";
		else if ((one.Number == 3 && two.Number == 1) || (one.Number == 1 && two.Number == 3))
			str = "1.3����";
	}
	else if (one.Number == two.Number)
	{
		if (one.Number == 10)
			str = "10��";
		else if (one.Number == 9)
			str = "9��";
		else if (one.Number == 8)
			str = "8��";
		else if (one.Number == 7)
			str = "7��";
		else if (one.Number == 6)
			str = "6��";
		else if (one.Number == 5)
			str = "5��";
		else if (one.Number == 4)
			str = "4��";
		else if (one.Number == 3)
			str = "3��";
		else if (one.Number == 2)
			str = "2��";
		else if (one.Number == 1)
			str = "1��";
	}
	else
	{
		if ((one.Number + two.Number) % 10 == 9)
			str = "9��";
		if ((one.Number + two.Number) % 10 == 8)
			str = "8��";
		if ((one.Number + two.Number) % 10 == 7)
			str = "7��";
		if ((one.Number + two.Number) % 10 == 6)
			str = "6��";
		if ((one.Number + two.Number) % 10 == 5)
			str = "5��";
		if ((one.Number + two.Number) % 10 == 4)
			str = "4��";
		if ((one.Number + two.Number) % 10 == 3)
			str = "3��";
		if ((one.Number + two.Number) % 10 == 2)
			str = "2��";
		if ((one.Number + two.Number) % 10 == 1)
			str = "1��";
		if ((one.Number + two.Number) % 10 == 0)
			str = "0��";
	}
	return str;
}

void Print(CARD* DECK, string* Player, int PlayerNum)
{
	cout << "\t\t\t" << "ù��° ī��\t" << "�ι�° ī��\t" << "ī�� ���" << endl << endl;
	for (int i = 0; i < PlayerNum * 2; i += 2)
	{
		cout << "�÷��̾� �̸� : " << *(Player + i / 2) << "\t   "
			<< (DECK + i)->Number << (DECK + i)->Shape << "\t\t"
			<< (DECK + i + 1)->Number << (DECK + i + 1)->Shape << "  \t\t"
			<< CheckCard(*(DECK + i), *(DECK + i + 1)) << endl << endl;
	}
}

void VicPrint(CARD* DECK, string* Player, int PlayerNum)
{
	string* PlayerResult = new string[PlayerNum];
	string Result[23] = { "3.8����", "1.8����", "1.3����", "10��", "9��", "8��", "7��", "6��", "5��", "4��", "3��", "2��", "1��",
							"9��", "8��", "7��", "6��", "5��", "4��", "3��", "2��", "1��", "0��" };

	for (int i = 0; i < PlayerNum * 2; i += 2)
	{
		PlayerResult[i / 2] = CheckCard(*(DECK + i), *(DECK + i + 1));
	}
	int index = 22;
	for (int i = 0; i < PlayerNum; i++)
	{
		for (int j = 0; j < 23; j++)
		{
			if ((PlayerResult[i] == Result[j]) && (j < index))
				index = j;
		}
	}
	for (int i = 0; i < PlayerNum; i++)
	{
		if (PlayerResult[i] == Result[index])
			cout << "�¸� �÷��̾� : " << *(Player + i) << endl;
	}
	cout << endl;
	delete[] PlayerResult;
}

void ft_Delete(string* Player, CARD* DECK)
{
	delete[] DECK;
	delete[] Player;
}