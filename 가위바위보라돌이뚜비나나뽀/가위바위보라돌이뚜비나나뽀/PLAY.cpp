#include "stdafx.h"
#include "PLAY.h"

void PLAY::PlayGame()
{
	cout << "가위 바위 보 게임" << endl << endl;
	cout << "참가인원 수를 입력하세요." << endl;
	cin >> Playernum;
	User = new PLAYER[Playernum];
	cout << "참가자들의 이름을 입력하세요." << endl;
	for (int i = 0; i < Playernum; i++)
	{
		cin >> User[i].name;
		HandShape.push_back(User[i]);
	}

	while (1)
	{
		/*cout << "가위바위보 시작(1.YES, 2.NO)" << endl;
		cin >> YN;
		if (YN == 2)
			break;*/

		Scnt = 0;
		Pcnt = 0;
		Rcnt = 0;

		//참가자 손모양 확인 및 출력
		for (iter = HandShape.begin(); iter != HandShape.end(); iter++)
		{
			(*iter).num = rand() % 3 + 1;
			cout << (*iter).name << " : ";

			if ((*iter).num == 1)
			{
				cout << "가위" << endl;
				Scnt++;
			}
			else if ((*iter).num == 2)
			{
				cout << "바위" << endl;
				Rcnt++;
			}
			else if ((*iter).num == 3)
			{
				cout << "보" << endl;
				Pcnt++;
			}
		}
		//결과 확인
		if ((Scnt > 0 && Rcnt > 0 && Pcnt > 0)|| (Scnt == HandShape.size()) 
			|| (Pcnt == HandShape.size()) || (Rcnt == HandShape.size()))
		{
			cout << "비겼다." << endl;
			continue;
		}
		else if (Scnt == 0)
		{
			for (iter = HandShape.begin(); iter != HandShape.end(); iter++)
			{
				if ((*iter).num == 3)
					cout << "이긴 사람 : " << (*iter).name << endl;
				else
					(*iter).isLose = true;
			}
		}
		else if (Rcnt == 0)
		{
			for (iter = HandShape.begin(); iter != HandShape.end(); iter++)
			{
				if ((*iter).num == 1)
						cout << "이긴 사람 : " << (*iter).name << endl;
					else
						(*iter).isLose = true;
			}
		}
		else if (Pcnt == 0)
		{
			for (iter = HandShape.begin(); iter != HandShape.end(); iter++)
			{
					if ((*iter).num == 2)
						cout << "이긴 사람 : " << (*iter).name << endl;
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
			cout << "최종승자 : " << (*iter).name << endl;
			break;
		}
		
	}
	HandShape.clear();
	HandShape.shrink_to_fit();
	delete[] User;
}
