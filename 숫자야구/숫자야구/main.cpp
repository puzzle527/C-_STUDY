#include <iostream>
#include <time.h>

using namespace std;

int main(void)
{
	srand(time(NULL));

	int Strike;
	int Ball;
	int Out;
	int Count;
	char Com[3];
	char Player[4];
	char Num[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	char YN;

	while (1)
	{
		Count = 1;

		for (int i = 0; i < 100; i++)
		{
			int src = rand() % 9;
			int dest = rand() % 9;

			char temp;
			temp = Num[dest];
			Num[dest] = Num[src];
			Num[src] = temp;
		}

		for (int i = 0; i < 3; i++)
		{
			Com[i] = Num[i];
		}

		cout << "���� �߱� ����" << endl;
		cout << "���δٸ� ���� 3���� �Է��ϼ���." << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << Com[i];
		}
		cout << endl;
		while (1)
		{
			Strike = 0;
			Ball = 0;
			Out = 3;

			cin >> Player;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (Player[j] == Com[i])
					{
						if (j == i)
							Strike++;
						else
							Ball++;
					}
				}
			}
			if (Strike == 3)
			{
				cout << "�����Դϴ�!" << endl;
				cout << Count << "ȸ ���� ����" << endl;
				break;
			}
			else
			{
				cout << "��Ʈ����ũ : " << Strike << endl
					<< "��\t   : " << Ball << endl
					<< "�ƿ�\t   : " << Out - (Strike + Ball) << endl
					<< "���ο� ���ڸ� �Է��ϼ���" << endl;
				Count++;
			}
		}

		cout << "�� ����(y, n)" << endl;
		cin >> YN;
		if (YN == 'n')
			break;
		else
			system("cls");
	}

	system("pause");

	return 0;
}