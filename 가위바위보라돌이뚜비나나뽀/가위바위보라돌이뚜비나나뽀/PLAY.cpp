#include "stdafx.h"
#include "PLAY.h"

void PLAY::PlayGame()
{
	cout << "���� ���� �� ����" << endl << endl;
	cout << "�����ο� ���� �Է��ϼ���." << endl;
	cin >> Playernum;
	User = new PLAYER[Playernum];
	cout << "�����ڵ��� �̸��� �Է��ϼ���." << endl;
	for (int i = 0; i < Playernum; i++)
	{
		cin >> User[i].name;
		HandShape.push_back(User[i]);
	}

	while (1)
	{
		/*cout << "���������� ����(1.YES, 2.NO)" << endl;
		cin >> YN;
		if (YN == 2)
			break;*/

		Scnt = 0;
		Pcnt = 0;
		Rcnt = 0;

		//������ �ո�� Ȯ�� �� ���
		for (iter = HandShape.begin(); iter != HandShape.end(); iter++)
		{
			(*iter).num = rand() % 3 + 1;
			cout << (*iter).name << " : ";

			if ((*iter).num == 1)
			{
				cout << "����" << endl;
				Scnt++;
			}
			else if ((*iter).num == 2)
			{
				cout << "����" << endl;
				Rcnt++;
			}
			else if ((*iter).num == 3)
			{
				cout << "��" << endl;
				Pcnt++;
			}
		}
		//��� Ȯ��
		if ((Scnt > 0 && Rcnt > 0 && Pcnt > 0)|| (Scnt == HandShape.size()) 
			|| (Pcnt == HandShape.size()) || (Rcnt == HandShape.size()))
		{
			cout << "����." << endl;
			continue;
		}
		else if (Scnt == 0)
		{
			for (iter = HandShape.begin(); iter != HandShape.end(); iter++)
			{
				if ((*iter).num == 3)
					cout << "�̱� ��� : " << (*iter).name << endl;
				else
					(*iter).isLose = true;
			}
		}
		else if (Rcnt == 0)
		{
			for (iter = HandShape.begin(); iter != HandShape.end(); iter++)
			{
				if ((*iter).num == 1)
						cout << "�̱� ��� : " << (*iter).name << endl;
					else
						(*iter).isLose = true;
			}
		}
		else if (Pcnt == 0)
		{
			for (iter = HandShape.begin(); iter != HandShape.end(); iter++)
			{
					if ((*iter).num == 2)
						cout << "�̱� ��� : " << (*iter).name << endl;
					else
						(*iter).isLose = true;
			}
		}
		for (iter = HandShape.begin(); iter != HandShape.end();)
		{
			if ((*iter).isLose == true)
				iter = HandShape.erase(iter);
			else
				iter++;
		}
		cout << endl;
		if (HandShape.size() == 1)
		{
			iter = HandShape.begin();
			cout << "�������� : " << (*iter).name << endl;
			break;
		}
		
	}
	HandShape.clear();
	HandShape.shrink_to_fit();
	delete[] User;
}
