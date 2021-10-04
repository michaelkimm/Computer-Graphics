#pragma once
#ifndef PLAYER
#define PLAYER

#include "MoveObj.h"

class Player : public MoveObj
{
private:
	int collectedFruit = 0;
	float size = 20.0f;

public:
	Player(float posX, float posY, float posZ, float dirX, float dirY, float dirZ, float speed, float size)
		: MoveObj(posX, posY, posZ, dirX, dirY, dirZ, speed), size(size)
	{
	}
	Player(Vector3 pose, Vector3 dir, float speed, float size)
		: MoveObj(pose, dir, speed)
	{
	}

	int GetCollectedFruit() { return collectedFruit; }
	int SetCollectedFruit(int plusValue) { collectedFruit += plusValue; }

	virtual void Draw() override;
};

#endif