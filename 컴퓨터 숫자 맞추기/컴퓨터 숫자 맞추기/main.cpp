#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

int main(void)
{
	int nPlayerNum;
	int nComNum, nCmax, nCmin;
	int nTimes;
	char chYN;
	//bool Playing = true;

	while (1)
	{
		srand(time(NULL));
		rand();

		nTimes = 10;
		nComNum = rand() % 900 + 100;
		nCmax = nComNum + (rand() % 100 + 300);
		if (nCmax > 1000)
			nCmax = 1000;
		nCmin = nComNum - (rand() % 100 + 300);
		if (nCmin < 100)
			nCmin = 100;

		while (1)
		{
			cout << "컴퓨터가 가지고 있는 숫자를 맞춰 봅시다." << endl;
			cout << "컴퓨터의 수는 세자리 숫자 입니다." << endl << endl;
			cout << "컴퓨터의 수의 범위 : " << nCmin << '~' << nCmax << "\t도전 가능 횟수 : " << nTimes << endl;
			cout << "맞힐 숫자를 입력하세요" << endl;
			cout << nComNum << endl;
			cin >> nPlayerNum;

			if (nPlayerNum > nComNum)
			{
				cout << "입력하신 숫자보다 작습니다." << endl;
				nCmax = nPlayerNum;
			}
			else if (nPlayerNum < nComNum)
			{
				cout << "입력하신 숫자보다 큽니다." << endl;
				nCmin = nPlayerNum;
			}
			else
			{
				cout << nComNum << " : 정답입니다." << endl;
				cout << (11 - nTimes) << "번째만에 성공하셨습니다!" << endl;
				break;
			}
			nTimes--;
			if (nTimes == 0)
			{
				cout << "실패" << endl;
				break;
			}
			Sleep(500);
			system("cls");
		}

		cout << "새 게임(y, n)" << endl;
		cin >> chYN;
		if (chYN == 'n')
			break;
		else
			system("cls");
	}
	system("pause");

	return 0;
}