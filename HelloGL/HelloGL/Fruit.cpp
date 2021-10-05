#include "Fruit.h"

void Fruit::Draw()
{
	glPushMatrix();
	{
		glColor3f(1, 0, 0);
		DrawFan(pose.x, pose.y, pose.z, size, 360, 20);

		glColor3f(0, 1, 0);
		DrawCube(pose.x, pose.y + size, pose.z, size * 0.3, size * 0.5, 0);
	}
	glPopMatrix();
}
bool Fruit::CheckCollision(GameObject* targetObj)
{
	return StaticObj::CheckCollision(targetObj);
}

void Fruit::SpeedUp(MoveObj* obj)
{
	obj->SpeedUp(upValue);
	delete(this);
}
void Fruit::SizeUp(GameObject* obj)
{
	obj->SizeUp(upValue);
	delete(this);
}