#pragma once
#ifndef FRUIT
#define FRUIT

#include "StaticObj.h"
#include "MoveObj.h"

class Fruit : public StaticObj
{
private:
	float upValue = 1;

public:
	Fruit(float posX, float posY, float posZ, float dirX, float dirY, float dirZ, float size, float upValue)
		: StaticObj(posX, posY, posZ, dirX, dirY, dirZ, size), upValue(upValue)
	{
	}
	Fruit(Vector3 pose, Vector3 dir, float size, float upValue)
		: StaticObj(pose, dir, size), upValue(upValue)
	{
	}

	virtual void Draw() override;
	virtual bool CheckCollision(GameObject* targetObj) override;

	void SpeedUp(MoveObj* obj);
	void SizeUp(GameObject* obj);
};

#endif
