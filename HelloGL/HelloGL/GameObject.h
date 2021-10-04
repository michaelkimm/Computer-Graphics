#pragma once
#ifndef GAMEOBJECT
#define GAMEOBJECT

#include ".\include\GL\freeglut.h"
#include "MyHeaderSet.h"

class GameObject
{
protected:
	Vector3 pose;
	Vector3 dir; // -1 0
	bool isDead = false;

public:
	GameObject(float posX, float posY, float posZ, float dirX, float dirY, float dirZ)
	{
		pose = Vector3(posX, posY, posZ);
		dir = Vector3(dirX, dirY, dirZ);
	}
	GameObject(Vector3 pose, Vector3 dir)
		: pose(pose), dir(dir)
	{
	}

	Vector3 GetPose() { return pose; }
	Vector3 GetDirection() { return dir; }
	bool IsDead() { return isDead; }
	bool SetDead(bool value) { isDead = value; }

	virtual void Draw() = 0;
	virtual bool CheckCollision(GameObject* targetObj);
};

#endif