// HelloGL.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include ".\include\GL\freeglut.h"

// 전역 변수
int Width = 600, Height = 600;

// 콜백 함수 선언
void Render();					// 그리기 용도로 사용할 콜백 함수
void Reshape(int w, int h);		// 윈도우 크기가 변경된 경우 호출되는 콜백 함수

// Event driven application
/*

*/

int main(int argc, char **argv)
{
	// Freeglut 초기화
	glutInit(&argc, argv);

	// 윈도우 크기 지정
	glutInitWindowSize(Width, Height);

	// 칼라 버퍼의 속성 지정
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);	// GLUT_DOUBLE: 버퍼를 두개 쓴다는 뜻

	// 윈도우 생성
	glutCreateWindow("Hello OpenGL");

	// 콜백 함수 등록
	glutDisplayFunc(Render);
	glutReshapeFunc(Reshape);

	// 메세지 처리 루프 진입
	glutMainLoop();
	
	return 0;
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
	gluOrtho2D(-10.0, 10.0, -10.0, 10.0);	// 무한히 넓은 공간 중에서 관측할 영역 지정

	// 모델링 좌표계 선택
	glMatrixMode(GL_MODELVIEW);

	// 빨간 삼각형 그리기
	glColor3d(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex2d(-2.0, -1.0);
	glVertex2d(2.0, -1.0);
	glVertex2d(0.0, 3.0);
	glEnd();

	// 파란 삼각형 그리기
	glColor3d(0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);
	glVertex2d(-2.0, 1.0);
	glVertex2d(2.0, -3.0);
	glVertex2d(2.0, 1.0);
	glEnd();

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

