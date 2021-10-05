#include "GameManager.h"
#include "Player.h"

GameManager* GameManager::instance = nullptr;

GameManager* GameManager::Instance()
{
	if (instance == nullptr)
	{
		instance = new GameManager();
	}
	return instance;
}

void GameManager::GameStart()
{
	time(&start);
}

void GameManager::GameEnd()
{
	time(&end);
}

bool GameManager::DoesTimePassed()
{
	time(&end);
	printf("time: %f\n", (float)(end - start));

	if (end - start > MaxLabTime)
		return true;

	return false;
}

void GameManager::printResult(bool isWin)
{
	ptPlayer->SetDead(true);

	if (isWin)
		printf("You Win!!\n");
	else
		printf("You Lose...\n");
	printf("Collected fruit : %d\n", ptPlayer->GetCollectedFruit());
	printf("Time Later : %.2f\n", (float)(end - start));
}

void GameManager::SetViewPort(int left_, int right_, int top_, int bottom_)
{
	left = left_;
	right = right_;
	top = top_;
	bottom = bottom_;
}