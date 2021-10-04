#include "Enemy.h"

#include <math.h>

void Enemy::Draw()
{
	glPushMatrix();
	{
		glTranslatef(pose.x, pose.y, pose.z);

		// 몸통 그리기
		glColor3f(128.f / 255, 65.f / 255, 217.f / 255);

		DrawFan(0, 0, 0, size, 360);

		// 눈 그리기
		glColor3f(1, 1, 1);
		glPointSize(size * 0.2f);
		
		float eye1[] = { size * 0.4f, size * 0.4f, 0 };
		float eye2[] = { -size * 0.4f, size * 0.4f, 0 };

		glBegin(GL_POINTS);
		glVertex3fv(eye1);
		glVertex3fv(eye2);
		glEnd();

		//// 입 그리기
		
		glColor3f(1, 0, 0);
		DrawTriangle(0, -size * 0.4f * sqrt(3) * 0.5 * 2 / 3, 0, size * 0.4f);
	}
	glPopMatrix();
}

bool Enemy::CheckCollision(GameObject* targetObj)
{

}

void Enemy::Chase()
{
	if (chaseTarget->IsDead() || chaseTarget == NULL)
		return;

	Vector3 chasePose = chaseTarget->GetPose();
	float chaseDirX = (chasePose.x - pose.x) > 0 ? 1 : -1;
	float chaseDirY = (chasePose.y - pose.y) > 0 ? 1 : -1;

	Move(chaseDirX, chaseDirY, 0);
}

void Enemy::SetChaseTarget(GameObject* target)
{
	chaseTarget = target;
}