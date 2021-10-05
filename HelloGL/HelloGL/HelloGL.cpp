// HelloGL.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>

#include ".\include\GL\freeglut.h"
#include "Player.h"
#include "Enemy.h"
#include "Fruit.h"
#include "GameManager.h"


// 전역 변수
int Width = 600, Height = 600;

Player* ptPlayer = NULL;
Enemy** dptEnemys = NULL;
Fruit** dptFruits = NULL;
int enemyCount = 3;
int fruitCount = 8;

// 콜백 함수 선언
void Render();					// 그리기 용도로 사용할 콜백 함수
void Reshape(int w, int h);		// 윈도우 크기가 변경된 경우 호출되는 콜백 함수

// Event driven application
/*

*/

void Initialize();
void KeyboardCallback(int key, int x, int y);
void Timer(int id);
Vector3 GetRandomPose(float left, float right, float top, float bottom);
void CheckCollision();

int main(int argc, char **argv)
{
	srand(time(NULL));

	// Freeglut 초기화
	glutInit(&argc, argv);

	// 윈도우 크기 지정
	glutInitWindowSize(Width, Height);
	GameManager::Instance()->SetViewPort(0, Width, Height, 0);

	// 칼라 버퍼의 속성 지정
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);	// GLUT_DOUBLE: 버퍼를 두개 쓴다는 뜻

	// 윈도우 생성
	glutCreateWindow("Hello OpenGL");

	// 콜백 함수 등록
	glutDisplayFunc(Render);
	glutReshapeFunc(Reshape);

	// 객체 생성
	Initialize();

	// 타이머 생성
	glutTimerFunc(100, Timer, 1);	// 이동 함수
	glutTimerFunc(100, Timer, 2);	// 충돌 판정

	// 키보드 함수
	glutSpecialFunc(KeyboardCallback);
	
	GameManager::Instance()->GameStart();

	// 메세지 처리 루프 진입
	glutMainLoop();
	
	return 0;
}

void KeyboardCallback(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		ptPlayer->SetDirection(-1, 0, 0);
		ptPlayer->Move();
		break;
	case GLUT_KEY_RIGHT:
		ptPlayer->SetDirection(1, 0, 0);
		ptPlayer->Move();
		break;
	case GLUT_KEY_DOWN:
		ptPlayer->SetDirection(0, -1, 0);
		ptPlayer->Move();
		break;
	case GLUT_KEY_UP:
		ptPlayer->SetDirection(0, 1, 0);
		ptPlayer->Move();
		break;
	}
	glutPostRedisplay();

}

void Timer(int id)
{
	switch (id)
	{
	case 1:
		for (int i = 0; i < enemyCount; i++)
		{
			dptEnemys[i]->Chase();
		}
		glutPostRedisplay();
		glutTimerFunc(100, Timer, 1);
		break;
	case 2:
		CheckCollision();
		glutTimerFunc(100, Timer, 2);
		break;
	default:
		break;
	}
}

void CheckCollision()
{
	for (int i = 0; i < enemyCount; i++)
	{
		if (dptEnemys[i]->CheckCollision(ptPlayer))
		{
			// 플레이어 죽음!
			ptPlayer->SetDead(true);
			GameManager::Instance()->GameEnd();
			GameManager::Instance()->printResult(false);
		}

		for (int j = 0; j < fruitCount; j++)
		{
			if (dptFruits[j] == NULL)
				continue;

			if (dptEnemys[i]->CheckCollision(dptFruits[j]))
			{
				dptEnemys[i]->Use(dptFruits[j]);
				dptFruits[j] = NULL;
			}
		}
	}

	for (int i = 0; i < fruitCount; i++)
	{
		if (dptFruits[i] == NULL)
			continue;

		if (dptFruits[i]->CheckCollision(ptPlayer))
		{
			ptPlayer->Use(dptFruits[i]);
			dptFruits[i] = NULL;
		}
	}
}

void Initialize()
{
	float playerSpeed = 5.0f;
	float playerSize = 20.0f;
	ptPlayer = new Player(Width * 0.5f, Height * 0.5f, 0, 1, 0, 0, playerSpeed, playerSize);

	float enemySpeed = 3.0f;
	float enemySize = 15.0f;
	dptEnemys = new Enemy*[enemyCount];
	for (int i = 0; i < enemyCount; i++)
	{
		dptEnemys[i] = new Enemy(GetRandomPose(0, Width, Height, 0), Vector3(1, 0, 0), enemySpeed, enemySize);
		dptEnemys[i]->SetChaseTarget(ptPlayer);
	}

	float fruitSize = 7.5f;
	dptFruits = new Fruit*[fruitCount];
	for (int i = 0; i < fruitCount; i++)
	{
		dptFruits[i] = new Fruit(GetRandomPose(0, Width, Height, 0), GetRandomPose(0, Width, Height, 0), fruitSize, 2);
	}
}

Vector3 GetRandomPose(float left, float right, float top, float bottom)
{
	return Vector3(rand() % Width, rand() % Height, 0);
}

void Render()
{
	// : >> 컬라 버퍼 초기화
	// 윈도우의 배경색 지정
	// 사이트 : 칼라 버퍼의 Clear color를 지정
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);	

	// 칼라 버퍼를 배경 색으로 초기화
	// 사이트 : 버퍼를 기존에 지정한 값으로 초기화
	glClear(GL_COLOR_BUFFER_BIT);			

	// <<

	// 관측 공간 지정
	glMatrixMode(GL_PROJECTION);			// 관측 공간을 지정하기 위해 projection 행렬을 선택
	glLoadIdentity();						// Projection 행렬에 단위행렬 지정
	gluOrtho2D(0, Width, 0, Height);	// 무한히 넓은 공간 중에서 관측할 영역 지정

	// 모델링 좌표계 선택
	glMatrixMode(GL_MODELVIEW);

	ptPlayer->Draw();
	for (int i = 0; i < enemyCount; i++)
	{
		dptEnemys[i]->Draw();
	}
	for (int i = 0; i < fruitCount; i++)
	{
		if (dptFruits[i] == NULL)
			continue;
		dptFruits[i]->Draw();
	}

	if (GameManager::Instance()->DoesTimePassed())
	{
		GameManager::Instance()->printResult(true);
	}

	// 칼라 버퍼 교환
	glutSwapBuffers();
}

// 윈도우 처음 생성 되거나 크기가 변경되면 자동으로 호출되는 콜백 함수
void Reshape(int w, int h)
{
	// 관측 공간을 윈도우에 매핑
	//glViewport(0, 0, w, h);		// 그림을 윈도우 화면에 어떻게 매핑할 것인가
	glViewport(0, 0, w, h);
	
	Width = w;
	Height = h;
}

