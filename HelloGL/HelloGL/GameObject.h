#pragma once
#ifndef GAMEOBJECT
#define GAMEOBJECT

#include ".\include\GL\freeglut.h"
#include "MyHeaderSet.h"

class GameObject
{
private:
	Vector3 dir; // -1 0

protected:
	Vector3 pose;
	float size;
	bool isDead = false;

public:
	GameObject(float posX, float posY, float posZ, float dirX, float dirY, float dirZ, float size)
		: size(size)
	{
		pose = Vector3(posX, posY, posZ);
		dir = Vector3(dirX, dirY, dirZ);
	}
	GameObject(Vector3 pose, Vector3 dir, float size)
		: pose(pose), dir(dir), size(size)
	{
	}

	Vector3 GetPose() { return pose; }
	Vector3 GetDirection() { return dir; }
	void SetDirection(float dirX, float dirY, float dirZ);
	bool IsDead() { return isDead; }
	void SetDead(bool value) { isDead = value; }

	virtual void Draw() = 0;
	virtual bool CheckCollision(GameObject* targetObj);
};

#endif