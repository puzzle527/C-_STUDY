#include <iostream>
#include <time.h>
#include <string>
#include <vector>
#define CARD_MAX 52

using namespace std;

struct TRUMP_CARD
{
	int		CARD_NUM;
	string	CARD_SHAPE;
};

void InitDeck(TRUMP_CARD* DECK);
void Shuffle(TRUMP_CARD* DECK);


int main(void)
{
	srand(time(NULL));

	vector<TRUMP_CARD> Player;
	vector<TRUMP_CARD> Dealer;

	int index = 0;
	int Input, cnt;
	int Psum, Dsum;
	char YN;

	TRUMP_CARD* DECK = new TRUMP_CARD[CARD_MAX];

	InitDeck(DECK);
	Shuffle(DECK);

	/*for (int i = 0; i < 52; i++)
	{
		cout << DECK[i].CARD_NUM << DECK[i].CARD_SHAPE << "\t";
	}
	cout << endl;*/
	cout << "블랙잭 게임" << endl << endl;

	while (1)
	{
		Player.clear();
		Dealer.clear();

		Player.push_back(DECK[index]);
		Player.push_back(DECK[index + 1]);
		Dealer.push_back(DECK[index + 2]);
		Dealer.push_back(DECK[index + 3]);

		cnt = 0;

		while (1)
		{
			Psum = 0;
			Dsum = 0;

			//플레이어 패 
			cout << "내가 받은 카드 " << Player.size() << "장 : ";
			for (int i = 0; i < Player.size(); i++)
			{
				if (Player[i].CARD_NUM == 1)
					cout << "A";
				else
					cout << Player[i].CARD_NUM;
				cout << Player[i].CARD_SHAPE << "   ";

				Psum += Player[i].CARD_NUM;
			}
			cout << endl;
			cout << "플레이어 카드 총합 : " << Psum << endl << endl;

			//딜러 패
			cout << "딜러가 받은 카드 " << Dealer.size() << "장 : ";
			for (int i = 0; i < Dealer.size(); i++)
			{
				if (Dealer[i].CARD_NUM == 1)
					cout << "A";
				else
					cout << Dealer[i].CARD_NUM;
				cout << Dealer[i].CARD_SHAPE << "   ";
			}
			cout << endl << endl;

			if (Psum > 21)
			{
				cout << "플레이어 패배" << endl;
				break;
			}
			else
			{
				cout << "카드를 더 받으시겠습니까? 1.예 2.아니오" << endl;
				cin >> Input;
				if (Input == 1)
				{
					Player.push_back(DECK[index + cnt + 4]);
					cnt++;
				}
				else if (Input == 2)
				{
					while (1)
					{
						Dsum = 0;
						for (int i = 0; i < Dealer.size(); i++)
						{
							Dsum += Dealer[i].CARD_NUM;
						}
						if (Dsum < 17)
						{
							cout << "딜러 카드 더 뽑기" << endl;
							Dealer.push_back(DECK[index + cnt + 4]);
							cnt++;
							Dsum = 0;
						}
						else
							break;
					}
					Dsum = 0;
					cout << "딜러가 받은 카드 " << Dealer.size() << "장 : ";
					for (int i = 0; i < Dealer.size(); i++)
					{
						if (Dealer[i].CARD_NUM == 1)
							cout << "A";
						else
							cout << Dealer[i].CARD_NUM;
						cout << Dealer[i].CARD_SHAPE << "   ";

						Dsum += Dealer[i].CARD_NUM;
					}
					cout << endl;
					cout << "딜러 카드 총합 : " << Dsum << endl << endl;

					if (Dsum > 21)
					{
						cout << "플레이어 승리" << endl;
						break;
					}
					else if (Psum > Dsum)
					{
						cout << "플레이어 승리" << endl;
						break;
					}
					else if (Psum < Dsum)
					{
						cout << "플레이어 패배" << endl;
						break;
					}
					else
					{
						cout << "무승부" << endl;
						break;
					}
				}
			}
		}
		index = index + cnt + 4;
		//cout << index << endl;
		cout << "게임을 계속 하시겠습니까? 1.계속 2.나가기" << endl;
		cin >> YN;
		if (YN == '2')
		{
			cout << "게임을 종료합니다." << endl;
			break;
		}
		if (index > 42)
		{
			cout << "카드가 부족합니다. 카드를 다시 섞습니다." << endl;
			Shuffle(DECK);
			index = 0;
		}

	}

	Player.clear();
	Dealer.clear();
	Player.shrink_to_fit();
	Dealer.shrink_to_fit();
	delete[] DECK;
	return 0;
}

void InitDeck(TRUMP_CARD* DECK)
{
	string shape[4] = { "♠", "♥", "♣", "◆" };
	for (int i = 0; i < CARD_MAX / 13; i++)
	{
		for (int j = 0; j < CARD_MAX / 4; j++)
		{
			DECK[(i * 13) + j].CARD_NUM = j + 1;
			DECK[(i * 13) + j].CARD_SHAPE = shape[i];
		}
	}
	for (int i = 10; i < 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			DECK[13 * j + i].CARD_NUM = 10;
		}
	}
}

void Shuffle(TRUMP_CARD* DECK)
{
	for (int i = 0; i < 1000; i++)
	{
		int src = rand() % CARD_MAX;
		int dest = rand() % CARD_MAX;

		TRUMP_CARD temp = DECK[dest];
		DECK[dest] = DECK[src];
		DECK[src] = temp;
	}
}
