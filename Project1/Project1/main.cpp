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
		cout << "��ȣ�� �����ϼ��� : 1.���� 2.���� 3.��" << endl;

		cin >> nPlayer;
		nComputer = (rand() % 3) + 1;

		if (nPlayer == 1)
		{
			cout << "Player\t : ����" << endl;
			if (nComputer == 1)
				cout << "Computer : ����" << endl << "���\t : ���º�" << endl;
			else if (nComputer == 2)
				cout << "Computer : ����" << endl << "���\t : ��" << endl;
			else
				cout << "Computer : ��" << endl << "���\t : ��" << endl;
		}
		else if (nPlayer == 2)
		{
			cout << "Player\t : ����" << endl;
			if (nComputer == 1)
				cout << "Computer : ����" << endl << "���\t : ��" << endl;
			else if (nComputer == 2)
				cout << "Computer : ����" << endl << "���\t : ���º�" << endl;
			else
				cout << "Computer : ��" << endl << "���\t : ��" << endl;
		}
		else if (nPlayer == 3)
		{
			cout << "Player\t : ��" << endl;
			if (nComputer == 1)
				cout << "Computer : ����" << endl << "���\t : ��" << endl;
			else if (nComputer == 2)
				cout << "Computer : ����" << endl << "���\t : ��" << endl;
			else
				cout << "Computer : ��" << endl << "���\t : ���º�" << endl;
		}
		else
		{
			cout << "�߸� �Է��ϼ̽��ϴ�. �ùٸ� ���� �Է��ϼ���!" << endl;
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1, '\n');
			}
			continue;
		}


		cout << "������ ��� �Ͻðڽ��ϱ�?(y, n)" << endl;
		cin >> chPlay;
		if (chPlay == 'n')
			break;
		else
			system("cls");
	}

	system("puase");

	return 0;

}