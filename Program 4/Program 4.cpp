// Program 4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

GLfloat angle = 0.0;

///////////////////////////////////////////////////////////
// Wywo³ywana w celu przerysowania sceny
void RenderScene(void) {
	// Wyczyszczenie okna aktualnym kolorem czyszczcym   
	glClear(GL_COLOR_BUFFER_BIT);
	// Aktualny kolor rysujcy - czerwony  
	//           R     G     B  
	glColor3f(0.0f, 1.0f, 0.0f);
	// Narysowanie prostokta wype³nionego aktualnym kolorem  
	//glRectf(-25.0f, 25.0f, 25.0f, -25.0f);

	glLoadIdentity();
	glRotatef(angle, 0.5f, 0.5f, 0.5f);

	glBegin(GL_TRIANGLES);
	glVertex2f(0.0f, 0.0f);
	glVertex2f(13.0f, 40.0f);
	glVertex2f(-26.0f, 12.0f);

	glVertex2f(0.0f, 0.0f);
	glVertex2f(13.0f, 40.0f);
	glVertex2f(36.0f, 12.0f);

	glVertex2f(0.0f, 0.0f);
	glVertex2f(36.0f, 12.0f);
	glVertex2f(15.0f, -27.0f);

	glVertex2f(0.0f, 0.0f);
	glVertex2f(15.0f, -27.0f);
	glVertex2f(-23.0f, -22.0f);

	glVertex2f(0.0f, 0.0f);
	glVertex2f(-23.0f, -22.0f);
	glVertex2f(-26.0f, 12.0f);

	glEnd();

	angle += 0.1;
	glutPostRedisplay();
	// Wys³anie polece do wykonania     
	glFlush();
}
///////////////////////////////////////////////////////////
// Konfiguracja stanu renderowania  
void SetupRC(void) {
	// Ustalenie niebieskiego koloru czyszczcego     
	glClearColor(0.5f, 0.0f, 0.5f, 1.0f);
}
///////////////////////////////////////////////////////////
// Wywo³ywana przez bibliotek GLUT w przypadku zmiany rozmiaru okna
void ChangeSize(int w, int h) {
	GLfloat aspectRatio;
	// Zabezpieczenie przed dzieleniem przez zero  
	if (h == 0)   h = 1;
	// Ustawienie wielkoœci widoku na równ¹ wielkoœci okna     
	glViewport(0, 0, w, h);
	// Ustalenie uk³adu wspó³rzêdnych  
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Wyznaczenie przestrzeni ograniczaj¹cej (lewy, prawy, dolny, górny, bliski, odleg³y)  
	aspectRatio = (GLfloat)w / (GLfloat)h;
	if (w <= h)    glOrtho(-100.0, 100.0, -100 / aspectRatio, 100.0 / aspectRatio, 100.0, -100.0);
	else    glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio, -100.0, 100.0, 100.0, -100.0);
	glMatrixMode(GL_MODELVIEW);  glLoadIdentity();
}
///////////////////////////////////////////////////////////
// G³ówny punkt wejcia programu
int main(int argc, char* argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutCreateWindow("GLRect");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	glutMainLoop();
	return 0;
}


