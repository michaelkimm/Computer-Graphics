#include "GameObject.h"
#include <math.h>

// size가 원의 반지름이라고 가정
bool GameObject::CheckCollision(GameObject* targetObj)
{
	float dist = powf(this->pose.x - targetObj->GetPose().x, 2) + powf(this->pose.y - targetObj->GetPose().y, 2);
	return powf(this->size + targetObj->size, 2) > dist;
}

void GameObject::SetDirection(float dirX, float dirY, float dirZ)
{
	if (isDead)
		return;
	float magnitude = sqrtf(powf(dirX, 2) + powf(dirY, 2) + powf(dirZ, 2));
	dir.x = dirX / magnitude;
	dir.y = dirY / magnitude;
	dir.z = dirZ / magnitude;
}

void GameObject::SizeUp(float plusValue)
{
	size += plusValue;
}