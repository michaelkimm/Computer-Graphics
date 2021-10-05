#pragma once

#ifndef MOVEOBJ
#define MOVEOBJ

#include "GameObject.h"

class MoveObj : public GameObject
{
protected:
	float speed;

public:
	MoveObj(float posX, float posY, float posZ, float dirX, float dirY, float dirZ, float speed, float size)
		: GameObject(posX, posY, posZ, dirX, dirY, dirZ, size), speed(speed)
	{
	}
	MoveObj(Vector3 pose, Vector3 dir, float speed, float size)
		: GameObject(pose, dir, size), speed(speed)
	{
	}

	void Move()
	{
		pose.x += speed * GetDirection().x;
		pose.y += speed * GetDirection().y;
		pose.z += speed * GetDirection().z;
	}

	virtual void Draw() = 0;
	virtual bool CheckCollision(GameObject* targetObj);
};

#endif