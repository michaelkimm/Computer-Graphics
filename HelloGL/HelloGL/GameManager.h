#pragma once
#include <time.h>
#include <stdio.h>

class Player;

class GameManager
{
private:
	static GameManager* instance;
	
private:
	Player* ptPlayer;
	time_t start, end;
	time_t MaxLabTime = 30;

	int left;
	int right;
	int top;
	int bottom;

public:
	static GameManager* Instance();

	void GameStart();
	void GameEnd();
	bool DoesTimePassed();
	void printResult(bool isWin);
	void SetViewPort(int left, int right, int top, int bottom);

	int GetLeft() { return left; }
	int GetRight() { return right; }
	int GetTop() { return top; }
	int GetBottom() { return bottom; }

};

