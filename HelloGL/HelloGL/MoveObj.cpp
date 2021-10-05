#include "MoveObj.h"
#include "Fruit.h"
#include "GameManager.h"

void MoveObj::Move()
{
	if (isDead)
		return;
	pose.x += speed * GetDirection().x;
	pose.y += speed * GetDirection().y;
	pose.z += speed * GetDirection().z;

	if (pose.x + size > GameManager::Instance()->GetRight() || pose.x - size < GameManager::Instance()->GetLeft())
	{
		pose.x -= speed * GetDirection().x;
	}
	if (pose.y + size > GameManager::Instance()->GetTop() || pose.y - size < GameManager::Instance()->GetBottom())
	{
		pose.y -= speed * GetDirection().y;
	}
}

bool MoveObj::CheckCollision(GameObject* targetObj)
{
	return GameObject::CheckCollision(targetObj);
}

void MoveObj::Use(Fruit* ptFruit)
{
	ptFruit->SpeedUp(this);
}

void MoveObj::SpeedUp(float plusVaule)
{
	speed += plusVaule;
}