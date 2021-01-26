#include <iostream>
#include <time.h>

using namespace std;

int main(void)
{
	int LottoNum[35];
	int Lucky[7] = { 3, 8, 17, 20, 27, 35, 26 };
	int Count = 0;

	srand(time(NULL));

	cout << "�̹��� ��÷ ��ȣ : ";
	for (int i = 0; i < 6; i++)
	{
		cout << Lucky[i] << " ";
	}
	cout << "���ʽ� ��ȣ : " << Lucky[6] << endl << endl;

	for (int i = 0; i < 35; i++)
	{
		LottoNum[i] = i + 1;
	}

		Count = 0;
		for (int i = 0; i < 1000; i++)
		{
			int nA = rand() % 35;
			int nB = rand() % 35;

			int temp = LottoNum[nA];
			LottoNum[nA] = LottoNum[nB];
			LottoNum[nB] = temp;
		}
		cout << "�ڽ��� �ζ� ��ȣ : ";
		for (int i = 0; i < 6; i++)
		{
			cout << LottoNum[i] << " ";
		}
		cout << "���ʽ� ��ȣ : " << LottoNum[6] << endl << endl;
		cout << "��÷��� : ";
		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (Lucky[i] == LottoNum[j])
				{
					Count++;
					break;
				}
			}
		}

		switch (Count)
		{
		case 6:
		{
			cout << "���� �帳�ϴ�. 1� ��÷�Ǽ̽��ϴ�!!" << endl;
			return 0;
		}
		case 5:
		{
			if (LottoNum[6] == Lucky[6])
				cout << "���� �帳�ϴ�. 2� ��÷�Ǽ̽��ϴ�!!" << endl;
			else
				cout << "���� �帳�ϴ�. 3� ��÷�Ǽ̽��ϴ�!!" << endl;
			break;
		}
		case 4:
		{
			cout << "���� �帳�ϴ�. 4� ��÷�Ǽ̽��ϴ�!!" << endl;
			break;
		}
		case 3:
		{
			cout << "���� �帳�ϴ�. 5� ��÷�Ǽ̽��ϴ�!!" << endl;
			break;
		}
		default:
		{
			cout << "��÷�Ǿ����ϴ�." << endl;
		}
	}

	return 0;
}