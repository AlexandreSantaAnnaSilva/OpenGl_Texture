#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
#include "image.h"
#define TEXTURA_DO_PLANO "camuflagem.sgi"


static int rot = 0;
static int port = 0;
static int shoulder = 0, elbow = 0, elbow2 = 0;
GLuint  textura_plano;


GLfloat planotext[4][2]={
  {0,0},
  {+1,0},
  {+1,+1},
  {0,+1}
};

void display(void){
//  glClear (GL_COLOR_BUFFER_BIT);
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glPushMatrix();
glRotatef((GLfloat) rot, 0.0, 1.0, 0.0);

  glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
  glBindTexture(GL_TEXTURE_2D,textura_plano);
  
/*chão com textura*/
glEnable(GL_TEXTURE_2D);
glBegin(GL_QUADS);
	glTexCoord2fv(planotext[0]); glVertex3f(-10.0, 0.2, 5.0);
	glTexCoord2fv(planotext[1]); glVertex3f(10.0, 0.2, 5.0);
	glTexCoord2fv(planotext[2]); glVertex3f(10.0, 0.2, -5.0);
	glTexCoord2fv(planotext[3]); glVertex3f(-10.0, 0.2, -5.0);
glEnd();  
glDisable(GL_TEXTURE_2D);


glColor3f(0.0, 0.4, 0.0);

/*gramado */
glPushMatrix();
glScalef(20.0, 0.2, 10.0);
glutSolidCube(1.0);
glPopMatrix();


glColor3f(0.66, 0.66, 0.66);
//Casa
glPushMatrix();
glScalef(1.6 , 1.6 , 2.0);
glTranslatef(2.5, 0.6 , -0.1);
glutSolidCube(1.0);
glPopMatrix();

glColor3f(0.66, 0.66, 0.66);
//Casa 2 
glPushMatrix();
glScalef(1.6 , 1.6 , 2.0);
glTranslatef(-2.5, 0.6 , -0.1);
glutSolidCube(1.0);
glPopMatrix();


glColor3f(0.41, 0.41, 0.41);
//estacas teto casa
glPushMatrix();
glScalef(0.1, 1.6, 0.1);
glTranslatef(18.0 , 0.6 , 0.0);
glutSolidCube(1.0);
glPopMatrix();

glColor3f(0.41, 0.41, 0.41);
//estacas teto casa 2
glPushMatrix();
glScalef(0.1, 1.6, 0.1);
glTranslatef(-18.0 , 0.6 , 0.0);
glutSolidCube(1.0);
glPopMatrix();


glColor3f(0.7, 0.13, 0.13);
//Teto 2
glPushMatrix();
glScalef(3.2 , 0.1 , 4.0);
glTranslatef(-1.0, 18.0 , 0.0);
glutSolidCube(1.0);
glPopMatrix();

glColor3f(0.7, 0.13, 0.13);
//Teto
glPushMatrix();
glScalef(3.2 , 0.1 , 4.0);
glTranslatef(1.0, 18.0 , 0.0);
glutSolidCube(1.0);
glPopMatrix();

/*estaca lado esquerdo frente*/
glColor3f(0.18, 0.31, 0.31);
glPushMatrix();
glTranslatef(-4.0, 0.9, 2.75);
glScalef(0.1, 1.6, 0.1);
glutSolidCube(1.0);
glPopMatrix();
  

/*estaca lado direito frente*/
glPushMatrix();
glTranslatef(4.0, 0.9, 2.75);
glScalef(0.1, 1.6, 0.1);
glutSolidCube(1.0);
glPopMatrix();

/*estacas porteira*/
//esquerda
glPushMatrix();
glTranslatef(-1.0, 0.8, 2.5);
glScalef(0.1, 1.6, 0.1);
glutSolidCube(1.0);
glPopMatrix();

//direita
glPushMatrix();
glTranslatef(1.0, 0.8, 2.5);
glScalef(0.1, 1.6, 0.1);
glutSolidCube(1.0);
glPopMatrix();

/*estacas horizontais cerca*/
//esquerda
glPushMatrix();
glTranslatef(-2.5, 0.5, 2.7);
glScalef(3.4, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(-2.5, 1.0, 2.7);
glScalef(3.4, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();


//direita
glPushMatrix();
glTranslatef(2.5, 0.5, 2.7);
glScalef(3.4, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(2.5, 1.0, 2.7);
glScalef(3.4, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

//abre e fecha a porteira

/*estacas horizontais porteira*/
glColor3f(0.96, 0.96, 0.96);

glPushMatrix();
glTranslatef(-1.1, 0.3, 2.7);
glRotatef((GLfloat) port, 0.0, 1.0, 0.0);
glTranslatef(1.1, -0.3, -2.7);

glPushMatrix();
glTranslatef(0.0, 0.3, 2.7);
glScalef(2.2, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 0.8, 2.7);
glScalef(2.2, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPushMatrix();
glTranslatef(0.0, 1.3, 2.7);
glScalef(2.2, 0.1, 0.1);
glutSolidCube(1.0);
glPopMatrix();

//vertical direita
glPushMatrix();
glTranslatef(1.0, 0.8, 2.5);
glScalef(0.1, 1.6, 0.1);
glutSolidCube(1.0);
glPopMatrix();

glPopMatrix();


  glPopMatrix();
  glutSwapBuffers();
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 40.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
glTranslatef(0.0, -2.0, -8.0);
}

void keyboard(unsigned char key, int x, int y){
  switch (key) {
case 'r':
rot = (rot+5) % 360;
glutPostRedisplay();
break;
case 'R':
rot = (rot-5) % 360;
glutPostRedisplay();
break;
case 'a':
port = (port+5) % 360;
glutPostRedisplay();
break;
case 'A':
port = (port-5) % 360;
glutPostRedisplay();
break;

  case 27:                                         // tecla Esc (encerra o programa)
	exit(0);
	break;
  }
}

void carregar_texturas(void){
  IMAGE *img;
  GLenum gluerr;

  /* textura do plano*/ 
  glGenTextures(1, &textura_plano);
  glBindTexture(GL_TEXTURE_2D, textura_plano);
  
  if(!(img=ImageLoad(TEXTURA_DO_PLANO))) {
    fprintf(stderr,"Error reading a texture.\n");
    exit(-1);
  }

  gluerr=gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 
			   img->sizeX, img->sizeY, 
			   GL_RGB, GL_UNSIGNED_BYTE, 
			   (GLvoid *)(img->data));
  if(gluerr){
    fprintf(stderr,"GLULib%s\n",gluErrorString(gluerr));
    exit(-1);
  }

  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);

}


void init(void){
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glEnable(GL_DEPTH_TEST);
  carregar_texturas();
  glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_BLEND);
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
//  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (500, 500); 
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Condominio");
  init ();
  glutDisplayFunc(display); 
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
