#include "Player.h"

void Player::Draw()
{
	

	glPushMatrix();
	{
		glTranslatef(pose.x, pose.y, pose.z);
		if (dir.x == -1)
		{
			glScalef(-1, 1, 1);
		}
		else if (dir.y == 1)
		{
			glRotatef(90, 0, 0, 1);
		}
		else if (dir.y == -1)
		{
			glRotatef(-90, 0, 0, 1);
		}

		// 몸통 그리기
		glPointSize(size);
		glColor3f(1.0f, 1.0f, 0);
		
		DrawFan(0, 0, 0, size, 360);

		// 눈 그리기
		glPointSize(size * 0.2f);
		glColor3f(0, 0, 0);
		
		glBegin(GL_POINTS);
		glVertex3f(size * 0.4f, size * 0.5f, 0);
		glEnd();

		//// 입 그리기
		float  mouseSizeAngle = 35;
		glRotatef(-mouseSizeAngle * 0.5, 0, 0, 1);
		glColor3f(1, 0, 0);

		DrawFan(0, 0, 0, size, mouseSizeAngle);
	}
	glPopMatrix();
}

bool Player::CheckCollision(GameObject* targetObj)
{
}