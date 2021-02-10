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

	cout << "섯다" << endl << endl;

	while (1)
	{
		DECK = new CARD[Size];

		cout << "플레이어 수를 입력하세요 : ";
		cin >> PlayerNum;
		if (PlayerNum > 10 || cin.fail())
		{
			cin.clear();
			cin.ignore(1, '\n');
			cout << "10명 이하로 입력하세요" << endl;
			Sleep(500);
			system("cls");
			continue;
		}

		Player = new string[PlayerNum];

		for (int i = 0; i < PlayerNum; i++)
		{
			cout << i + 1 << "번째 플레이어 이름을 입력하세요 : ";
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
	DECK->Shape = "광";
	(DECK + 2)->Shape = "광";
	(DECK + 7)->Shape = "광";
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

	if (one.Shape == "광" && two.Shape == "광")
	{
		if ((one.Number == 3 && two.Number == 8) || (one.Number == 8 && two.Number == 3))
			str = "3.8광땡";
		else if ((one.Number == 1 && two.Number == 8) || (one.Number == 8 && two.Number == 1))
			str = "1.8광땡";
		else if ((one.Number == 3 && two.Number == 1) || (one.Number == 1 && two.Number == 3))
			str = "1.3광땡";
	}
	else if (one.Number == two.Number)
	{
		if (one.Number == 10)
			str = "10땡";
		else if (one.Number == 9)
			str = "9땡";
		else if (one.Number == 8)
			str = "8땡";
		else if (one.Number == 7)
			str = "7땡";
		else if (one.Number == 6)
			str = "6땡";
		else if (one.Number == 5)
			str = "5땡";
		else if (one.Number == 4)
			str = "4땡";
		else if (one.Number == 3)
			str = "3땡";
		else if (one.Number == 2)
			str = "2땡";
		else if (one.Number == 1)
			str = "1땡";
	}
	else
	{
		if ((one.Number + two.Number) % 10 == 9)
			str = "9끗";
		if ((one.Number + two.Number) % 10 == 8)
			str = "8끗";
		if ((one.Number + two.Number) % 10 == 7)
			str = "7끗";
		if ((one.Number + two.Number) % 10 == 6)
			str = "6끗";
		if ((one.Number + two.Number) % 10 == 5)
			str = "5끗";
		if ((one.Number + two.Number) % 10 == 4)
			str = "4끗";
		if ((one.Number + two.Number) % 10 == 3)
			str = "3끗";
		if ((one.Number + two.Number) % 10 == 2)
			str = "2끗";
		if ((one.Number + two.Number) % 10 == 1)
			str = "1끗";
		if ((one.Number + two.Number) % 10 == 0)
			str = "0끗";
	}
	return str;
}

void Print(CARD* DECK, string* Player, int PlayerNum)
{
	cout << "\t\t\t" << "첫번째 카드\t" << "두번째 카드\t" << "카드 결과" << endl << endl;
	for (int i = 0; i < PlayerNum * 2; i += 2)
	{
		cout << "플레이어 이름 : " << *(Player + i / 2) << "\t   "
			<< (DECK + i)->Number << (DECK + i)->Shape << "\t\t"
			<< (DECK + i + 1)->Number << (DECK + i + 1)->Shape << "  \t\t"
			<< CheckCard(*(DECK + i), *(DECK + i + 1)) << endl << endl;
	}
}

void VicPrint(CARD* DECK, string* Player, int PlayerNum)
{
	string* PlayerResult = new string[PlayerNum];
	string Result[23] = { "3.8광땡", "1.8광땡", "1.3광땡", "10땡", "9땡", "8땡", "7땡", "6땡", "5땡", "4땡", "3땡", "2땡", "1땡",
							"9끗", "8끗", "7끗", "6끗", "5끗", "4끗", "3끗", "2끗", "1끗", "0끗" };

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
			cout << "승리 플레이어 : " << *(Player + i) << endl;
	}
	cout << endl;
	delete[] PlayerResult;
}

void ft_Delete(string* Player, CARD* DECK)
{
	delete[] DECK;
	delete[] Player;
}