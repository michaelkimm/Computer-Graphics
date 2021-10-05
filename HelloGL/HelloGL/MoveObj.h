#pragma once

#ifndef MOVEOBJ
#define MOVEOBJ

#include "GameObject.h"
class Fruit;

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

	void Move();
	virtual void Draw() = 0;
	virtual bool CheckCollision(GameObject* targetObj);
	virtual void Use(Fruit* ptFruit);
	void SpeedUp(float plusVaule);

};

#endif