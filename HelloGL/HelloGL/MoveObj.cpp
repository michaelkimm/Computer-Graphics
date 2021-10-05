#include "MoveObj.h"

bool MoveObj::CheckCollision(GameObject* targetObj)
{
	return GameObject::CheckCollision(targetObj);
}