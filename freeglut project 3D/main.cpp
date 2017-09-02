#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <GL/freeglut.h>
//#include <GL/glut.h>
#include "Objeto3D.h"
#include "Ficha.h"
#include "Malla.h"
#include "Quesito.h"
#include "Esfera.h"
#include "Cilindro.h"
#include "Cubo.h"
#include "Coche.h"
#include "Autopista.h"
#include "Tablero.h"
#include "Farola.h"
#include "Escena.h"
#include "TextureLoader.h"

#include <iostream>
using namespace std;

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH= 1300, HEIGHT= 600;

// Viewing frustum parameters
GLdouble xRight=25, xLeft=-xRight, yTop=10, yBot=-yTop, N=1, F=1000;

// Camera parameters
GLdouble eyeX=100.0, eyeY=50.0, eyeZ=50.0;
GLdouble lookX=0.0, lookY=0.0, lookZ=0.0;
GLdouble upX=0, upY=1, upZ=0;
bool PERFIL = false, LUZ_AMBIENTE = true, LUZ_FAROS = true, LUZ_FAROLA = true, LUZ_DIRECCIONAL = false;

Objeto3D *escena;
unsigned int texturas;

void buildSceneObjects()
{
	escena = new Escena(texturas);
}

void cameraSetUp()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);
}

void zoom(GLdouble factor)
{
	xRight /= factor;
	xLeft /= factor;

	yTop /= factor;
	yBot /= factor;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(xLeft, xRight, yBot, yTop, N, F);
}

void initGL()
{	 		 
	glClearColor(0.6f,0.7f,0.8f,1.0);
    glEnable(GL_LIGHTING);    

	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.1f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);


	//glEnable(GL_TEXTURE_2D);

	unsigned int height, width;

	unsigned char *texture = loadBMPRaw("texturas/cocheTex.bmp", width, height, false);

	glGenTextures(1, &texturas);

	glBindTexture(GL_TEXTURE_2D, texturas);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture);

	delete texture;

	buildSceneObjects();


	// Camera set up
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);

	// Frustum set up
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();     
	glOrtho(xLeft, xRight, yBot, yTop, N, F);

	// Viewport set up
    glViewport(0, 0, WIDTH, HEIGHT);  

	 // Light0
    glEnable(GL_LIGHT0);
    GLfloat d[]={1.0,1.0,1.0,1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
    GLfloat a[]={0.3f,0.3f,0.3f,1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat p[]={50.0, 25.0, 0.0, 1.0};	 
	glLightfv(GL_LIGHT0, GL_POSITION, p);

	//Luz ambiente
	GLfloat amb[] = { 0.0, 0.0, 0.0, 1.0 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);

	GLfloat dd[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT4, GL_DIFFUSE, dd);
	GLfloat ad[] = { 0.3f, 0.3f, 0.3f, 1.0 };
	glLightfv(GL_LIGHT4, GL_AMBIENT, ad);
	GLfloat pd[] = { 1.0, 1.0, 0.0, 0.0 };
	glLightfv(GL_LIGHT4, GL_POSITION, pd);
	
 }

void pintarRejilla()
{
	glColor3f(1.0, 0.5, 0.5);

	glBegin(GL_LINES);

	for (int i = -6; i < 7; i++)
	{
		glVertex3f((GLfloat)i * 5, 0.0f, 30.0f);
		glVertex3f((GLfloat)i * 5, 0.0f, -30.0f);
	}

	for (int i = -6; i < 7; i++)
	{
		glVertex3f((GLfloat)30, 0.0f, (GLfloat)i * 5);
		glVertex3f((GLfloat)-30, 0.0f, (GLfloat)i * 5);
	}

	glEnd();
}

void pintarEjes()
{
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0, 0, 0);
	glVertex3f(20, 0, 0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 20, 0);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 20);
	glEnd();
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  

	//pintarEjes();
	//pintarRejilla();

	escena->dibuja();

	glFlush();
	glutSwapBuffers();
}

void resize(int newWidth, int newHeight) {
	WIDTH= newWidth;
	HEIGHT= newHeight;
	GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
	glViewport (0, 0, WIDTH, HEIGHT) ;
   
	GLdouble SVAWidth= xRight-xLeft;
	GLdouble SVAHeight= yTop-yBot;
	GLdouble SVARatio= SVAWidth/SVAHeight;
	if (SVARatio >= RatioViewPort) {		 
		GLdouble newHeight= SVAWidth/RatioViewPort;
		GLdouble yMiddle= ( yBot+yTop )/2.0;
		yTop= yMiddle + newHeight/2.0;
		yBot= yMiddle - newHeight/2.0;
    }
	else {      
		GLdouble newWidth= SVAHeight*RatioViewPort;
		GLdouble xMiddle= ( xLeft+xRight )/2.0;
		xRight= xMiddle + newWidth/2.0;
		xLeft=  xMiddle - newWidth/2.0;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();   
	glOrtho(xLeft, xRight, yBot, yTop, N, F);
}

void moverCamara(GLdouble tmpX, GLdouble tmpY, GLdouble tmpZ)
{
	if (lookX > tmpX)
		eyeX += (lookX - tmpX);
	else
		if (lookX < tmpX)
			eyeX -= (tmpX - lookX);

	if (lookZ > tmpZ)
		eyeZ += (lookZ - tmpZ);
	else
		if (lookZ < tmpZ)
			eyeZ -= (tmpZ - lookZ);

	if (lookY > tmpY)
		eyeY += (lookY - tmpY);
	else
		if (lookY < tmpY)
			eyeY -= (tmpY - lookY);
}

void key(unsigned char key, int x, int y){
	bool need_redisplay = true;
	PV3D *p;
	GLdouble tmpX = lookX, tmpY = lookY, tmpZ = lookZ; //Guardar los valores antiguos de la cámara.

	switch (key) {
		case 27:  /* Escape key */
			//continue_in_main_loop = false; // (**)
			//Freeglut's sentence for stopping glut's main loop (*)
			glutLeaveMainLoop (); 
			break;
		case 'w':
			((Escena *)escena)->avanzarCoche();

			p = ((Escena *)escena)->getPosCoche();

			lookX = p->getX();
			lookY = p->getY();
			lookZ = p->getZ();
			
			moverCamara(tmpX, tmpY, tmpZ);

			delete p;
			cameraSetUp();

			break;
		case 's':
			((Escena *)escena)->retrocederCoche();

			p = ((Escena *)escena)->getPosCoche();

			lookX = p->getX();
			lookY = p->getY();
			lookZ = p->getZ();

			moverCamara(tmpX, tmpY, tmpZ);

			delete p;
			cameraSetUp();

			break;
		case 'a':
			((Escena *)escena)->girarCocheIzq();
			break;
		case 'd':
			((Escena *)escena)->girarCocheDch();
			break;
		case 'p':
			if (PERFIL)
			{
				p = ((Escena *)escena)->getPosCoche();

				eyeX = p->getX() + 100;
				eyeY = 50.0;
				eyeZ = p->getZ() + 50;

				lookX = p->getX();
				lookY = p->getY();
				lookZ = p->getZ();

				delete p;
				PERFIL = false;
			}
			else
			{
				p = ((Escena *)escena)->getPosCoche();

				eyeX = p->getX();
				eyeY = 1.6;
				eyeZ = 50.0;

				lookX = p->getX();
				lookY = p->getY();
				lookZ = p->getZ();

				delete p;
				PERFIL = true;
			}

			cameraSetUp();
			break;
		case 'o':
			if (LUZ_AMBIENTE)
			{
				glDisable(GL_LIGHT0);
				LUZ_AMBIENTE = false;
			}
			else
			{
				glEnable(GL_LIGHT0);
				LUZ_AMBIENTE = true;
			}
			break;
		case 'g':
		{
			if (LUZ_FAROLA)
			{
				glDisable(GL_LIGHT3);
				LUZ_FAROLA = false;
			}
			else
			{
				glEnable(GL_LIGHT3);
				LUZ_FAROLA = true;
			}
			break;
		}
		case 'f':
			if (LUZ_FAROS)
			{
				((Escena *)escena)->apagarFaros();
				LUZ_FAROS = false;
			}
			else
			{
				((Escena *)escena)->encenderFaros();
				LUZ_FAROS = true;
			}
			break;
		case 'h':
			if (LUZ_DIRECCIONAL)
			{
				glDisable(GL_LIGHT4);
				LUZ_DIRECCIONAL = false;
			}
			else
			{
				glEnable(GL_LIGHT4);
				LUZ_DIRECCIONAL = true;
			}
			break;
		case 't':
			zoom(0.9f);
			break;
		case 'y':
			zoom(1.1f);
			break;
		default:
			need_redisplay = false;
			break;
	}

	if (need_redisplay)
		glutPostRedisplay();
}

int main(int argc, char *argv[]){
	cout<< "Starting console..." << endl;

	int my_window; // my window's identifier

	// Initialization
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition (40, 40);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);

	// Window construction
	my_window = glutCreateWindow("Práctica 3");
    
	// Callback registration
	glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutDisplayFunc(display);

	// OpenGL basic setting
	initGL();

	// Freeglut's main loop can be stopped executing (**)
	// while (continue_in_main_loop) glutMainLoopEvent();

	// Classic glut's main loop can be stopped after X-closing the window,
	// using the following freeglut's setting (*)
	glutSetOption (GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION) ;
    
	// Classic glut's main loop can be stopped in freeglut using (*)
	glutMainLoop(); 
  
	// We would never reach this point using classic glut
	//system("PAUSE"); 
	delete escena;
   
	return 0;
}