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
			cout << "��ǻ�Ͱ� ������ �ִ� ���ڸ� ���� ���ô�." << endl;
			cout << "��ǻ���� ���� ���ڸ� ���� �Դϴ�." << endl << endl;
			cout << "��ǻ���� ���� ���� : " << nCmin << '~' << nCmax << "\t���� ���� Ƚ�� : " << nTimes << endl;
			cout << "���� ���ڸ� �Է��ϼ���" << endl;
			cout << nComNum << endl;
			cin >> nPlayerNum;

			if (nPlayerNum > nComNum)
			{
				cout << "�Է��Ͻ� ���ں��� �۽��ϴ�." << endl;
				nCmax = nPlayerNum;
			}
			else if (nPlayerNum < nComNum)
			{
				cout << "�Է��Ͻ� ���ں��� Ů�ϴ�." << endl;
				nCmin = nPlayerNum;
			}
			else
			{
				cout << nComNum << " : �����Դϴ�." << endl;
				cout << (11 - nTimes) << "��°���� �����ϼ̽��ϴ�!" << endl;
				break;
			}
			nTimes--;
			if (nTimes == 0)
			{
				cout << "����" << endl;
				break;
			}
			Sleep(500);
			system("cls");
		}

		cout << "�� ����(y, n)" << endl;
		cin >> chYN;
		if (chYN == 'n')
			break;
		else
			system("cls");
	}
	system("pause");

	return 0;
}