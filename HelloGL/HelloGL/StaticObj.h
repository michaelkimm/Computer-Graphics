#pragma once
#ifndef STATICOBJ
#define STATICOBJ

#include "GameObject.h"

class StaticObj : public GameObject
{
private:


public:
	StaticObj(float posX, float posY, float posZ, float dirX, float dirY, float dirZ)
		: GameObject(posX, posY, posZ, dirX, dirY, dirZ)
	{
	}
	StaticObj(Vector3 pose, Vector3 dir)
		: GameObject(pose, dir)
	{
	}

	virtual void Draw() = 0;
	virtual bool CheckCollision(GameObject* targetObj);
};

#endif