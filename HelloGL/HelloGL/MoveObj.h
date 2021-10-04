#pragma once

#ifndef MOVEOBJ
#define MOVEOBJ

#include "GameObject.h"

class MoveObj : public GameObject
{
protected:
	float speed;

public:
	MoveObj(float posX, float posY, float posZ, float dirX, float dirY, float dirZ, float speed)
		: GameObject(posX, posY, posZ, dirX, dirY, dirZ), speed(speed)
	{
	}
	MoveObj(Vector3 pose, Vector3 dir, float speed)
		: GameObject(pose, dir), speed(speed)
	{
	}

	void Move(float dirX, float dirY, float dirZ)
	{
		pose.x += speed * dirX;
		pose.y += speed * dirY;
		pose.z += speed * dirZ;

		dir.x = dirX;
		dir.y = dirY;
		dir.z = dirZ;
	}

	virtual void Draw() = 0;
	virtual bool CheckCollision(GameObject* targetObj);
};

#endif