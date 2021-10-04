#pragma once
#ifndef ENEMY
#define ENEMY

#include "MoveObj.h"

class Enemy : public MoveObj
{
private:
	float size = 15;
	GameObject* chaseTarget = NULL;

public:
	Enemy(float posX, float posY, float posZ, float dirX, float dirY, float dirZ, float speed, float size)
		: MoveObj(posX, posY, posZ, dirX, dirY, dirZ, speed), size(size)
	{
	}
	Enemy(Vector3 pose, Vector3 dir, float speed, float size)
		: MoveObj(pose, dir, speed)
	{
	}

	virtual void Draw() override;
	virtual bool CheckCollision(GameObject* targetObj) override;
	void Chase();
	void SetChaseTarget(GameObject* target);
};

#endif