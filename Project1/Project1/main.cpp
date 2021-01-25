#include <iostream>
#include <time.h>

using namespace std;

int main(void)
{
	srand(time(NULL));
	rand();

	int nPlayer;
	int nComputer;
	char chPlay;

	while (true)
	{
		cout << "번호를 선택하세요 : 1.가위 2.바위 3.보" << endl;

		cin >> nPlayer;
		nComputer = (rand() % 3) + 1;

		if (nPlayer == 1)
		{
			cout << "Player\t : 가위" << endl;
			if (nComputer == 1)
				cout << "Computer : 가위" << endl << "결과\t : 무승부" << endl;
			else if (nComputer == 2)
				cout << "Computer : 바위" << endl << "결과\t : 패" << endl;
			else
				cout << "Computer : 보" << endl << "결과\t : 승" << endl;
		}
		else if (nPlayer == 2)
		{
			cout << "Player\t : 바위" << endl;
			if (nComputer == 1)
				cout << "Computer : 가위" << endl << "결과\t : 승" << endl;
			else if (nComputer == 2)
				cout << "Computer : 바위" << endl << "결과\t : 무승부" << endl;
			else
				cout << "Computer : 보" << endl << "결과\t : 패" << endl;
		}
		else if (nPlayer == 3)
		{
			cout << "Player\t : 보" << endl;
			if (nComputer == 1)
				cout << "Computer : 가위" << endl << "결과\t : 패" << endl;
			else if (nComputer == 2)
				cout << "Computer : 바위" << endl << "결과\t : 승" << endl;
			else
				cout << "Computer : 보" << endl << "결과\t : 무승부" << endl;
		}
		else
		{
			cout << "잘못 입력하셨습니다. 올바른 수를 입력하세요!" << endl;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1, '\n');
			}
			continue;
		}


		cout << "게임을 계속 하시겠습니까?(y, n)" << endl;
		cin >> chPlay;
		if (chPlay == 'n')
			break;
		else
			system("cls");
	}

	system("puase");

	return 0;

}