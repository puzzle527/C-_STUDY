#pragma once
class PLAY
{
public:
	PLAYER*	User;
	int		Playernum = 0;
	int		YN = 0;
	int		Scnt = 0;
	int		Rcnt = 0;
	int		Pcnt = 0;
	vector<PLAYER> HandShape;
	vector<PLAYER>::iterator iter;

	void PlayGame();
};

