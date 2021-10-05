#pragma once
#ifndef STATICOBJ
#define STATICOBJ

#include "GameObject.h"

class StaticObj : public GameObject
{
private:


public:
	StaticObj(float posX, float posY, float posZ, float dirX, float dirY, float dirZ, float size)
		: GameObject(posX, posY, posZ, dirX, dirY, dirZ, size)
	{
	}
	StaticObj(Vector3 pose, Vector3 dir, float size)
		: GameObject(pose, dir, size)
	{
	}

	virtual void Draw() = 0;
	virtual bool CheckCollision(GameObject* targetObj);
};

#endif