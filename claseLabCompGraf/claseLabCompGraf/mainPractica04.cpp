//////////////////////////////////////////////////////////////////////////////
//  Laboratorio de Computación Gráfica                                    ////
//  Practica # 04                                                         ////
//  Nombre: Pacheco Franco Jesús Enrique                                  ////
//  Version Visual Studio: Visual Studio Community 2017 15.5.27130.2027   ////
//  Grupo: 02                                                             ////
//  Semestre: 2018-2                                                      ////
//  Fecha: 05/Marzo/2018                                                  ////
//////////////////////////////////////////////////////////////////////////////

#include "Main.h"

float transZ = -5.0f;
float rotY = 0.0;
int screenW = 0.0;
int screenH = 0.0;


void InitGL ( void )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			/*glColor3f(1.0,0.0,0.0);*/
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			/*glColor3f(0.0,0.0,1.0);*/
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			/*glColor3f(0.0,1.0,0.0);*/
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			/*glColor3f(1.0,1.0,1.0);*/
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			/*glColor3f(0.4,0.2,0.6);*/
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			/*glColor3f(0.8,0.2,0.4);*/
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

		glTranslatef(0.0f, 0.0f, transZ);
		glRotatef(0.0 + rotY, 0.0, 1.0, 0.0);

		//Poner Código Aquí.

		glBegin(GL_LINES);
			glColor3f(1.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, -1.0f);
			glVertex3f(100.0f, 0.0f, -1.0f);

			glColor3f(0.0f, 1.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, -1.0f);
			glVertex3f(0.0f, 100.0f, -1.0f);

			glColor3f(0.0f, 0.0f, 1.0f);
			glVertex3f(0.0f, 0.0f, -1.0f);
			glVertex3f(0.0f, 0.0f, -1.0f);
		glEnd();
		
		// HEAD
		glPushMatrix();
			glColor3f(1.0f, 0.0f, 0.0f);
			glScalef(4.0f, 4.0f, 3.0f);
			prisma();
		glPopMatrix();

		// NECK
		glTranslatef(0.0f, -3.0f, 0.0f);

		glPushMatrix();
			glColor3f(0.0f, 1.0f, 0.0f);
			glScalef(3.0f, 2.0f, 3.0f);
			prisma();
		glPopMatrix();

		// Back
		glTranslatef(0.0f, -6.0f, 0.0f);

		glPushMatrix();
			glColor3f(0.0f, 0.0f, 1.0f);
			glScalef(10.0f, 10.0f, 3.0f);
			prisma();
		glPopMatrix();

		// Right Shoulder

		glTranslatef(-5.5f,4.0f,0.0f);

		glPushMatrix();
			glColor3f(1.0f, 1.0f, 0.0f);
			glScalef(1.0f, 2.0f, 3.0f);
			prisma();
		glPopMatrix();

		// Right Arm 1

		glTranslatef(-2.0f, 0.0f, 0.0f);

		glPushMatrix();
			glColor3f(1.0f, 0.0f, 1.0f);
			glScalef(3.0f, 2.0f, 3.0f);
			prisma();
		glPopMatrix();

		// Right Elbow

		glTranslatef(-1.75f, 0.0f, 0.0f);

		glPushMatrix();
			glColor3f(0.0f, 0.0f, 1.0f);
			glScalef(0.5f, 2.0f, 3.0f);
			prisma();
		glPopMatrix();

		// Right Arm 2

		glTranslatef(-2.25f, 0.0f, 0.0f);

		glPushMatrix();
			glColor3f(1.0f, 0.0f, 0.0f);
			glScalef(4.0f, 2.0f, 3.0f);
			prisma();
		glPopMatrix();

		// Right Wrist

		glTranslatef(-2.25f, 0.0f, 0.0f);

		glPushMatrix();
			glColor3f(0.0f, 1.0f, 0.0f);
			glScalef(0.5f, 2.0f, 3.0f);
			prisma();
		glPopMatrix();

		// Right Palm

		glTranslatef(-0.75f, 0.0f, 0.0f);

		glPushMatrix();
			glColor3f(0.0f, 0.0f, 1.0f);
			glScalef(1.0f, 2.0f, 3.0f);
			prisma();
		glPopMatrix();

		// Left Arm

		// Left Shoulder

		glTranslatef(20.0f,0.0f,0.0f);

		glPushMatrix();
			glColor3f(1.0f, 1.0f, 0.0f);
			glScalef(1.0f, 2.0f, 3.0f);
			prisma();
		glPopMatrix();

		// Left Arm 1

		glTranslatef(2.0f, 0.0f, 0.0f);

		glPushMatrix();
			glColor3f(1.0f, 0.0f, 1.0f);
			glScalef(3.0f, 2.0f, 3.0f);
			prisma();
		glPopMatrix();

		// Left Elbow

		glTranslatef(1.75f, 0.0f, 0.0f);

		glPushMatrix();
			glColor3f(0.0f, 0.0f, 1.0f);
			glScalef(0.5f, 2.0f, 3.0f);
			prisma();
		glPopMatrix();

		// Left Arm 2

		glTranslatef(2.25f, 0.0f, 0.0f);

		glPushMatrix();
			glColor3f(1.0f, 0.0f, 0.0f);
			glScalef(4.0f, 2.0f, 3.0f);
			prisma();
		glPopMatrix();

		// Left Wrist

		glTranslatef(2.25f, 0.0f, 0.0f);

		glPushMatrix();
			glColor3f(0.0f, 1.0f, 0.0f);
			glScalef(0.5f, 2.0f, 3.0f);
			prisma();
		glPopMatrix();

		// Left Palm

		glTranslatef(0.75f, 0.0f, 0.0f);

		glPushMatrix();
			glColor3f(0.0f, 0.0f, 1.0f);
			glScalef(1.0f, 2.0f, 3.0f);
			prisma();
		glPopMatrix();

		// Right Foot

		// Right Leg 1

		glTranslatef(-18.5f, -11.5f, 0.0f);

		glPushMatrix();
			glColor3f(1.0f, 0.0f, 0.0f);
			glScalef(2.0f, 5.0f, 3.0f);
			prisma();
		glPopMatrix();

		// Right Knee

		glTranslatef(0.0f, -3.0f, 0.0f);

		glPushMatrix();
			glColor3f(0.0f, 1.0f, 0.0f);
			glScalef(2.0f, 1.0f, 3.0f);
			prisma();
		glPopMatrix();

		// Right Leg 2

		glTranslatef(0.0f, -3.0f, 0.0f);

		glPushMatrix();
			glColor3f(0.0f, 0.0f, 1.0f);
			glScalef(2.0f, 5.0f, 3.0f);
			prisma();
		glPopMatrix();

		// Right Leg 3

		glTranslatef(0.0f, -2.75f, 0.0f);

		glPushMatrix();
			glColor3f(1.0f, 1.0f, 0.0f);
			glScalef(2.0f, 0.5f, 3.0f);
			prisma();
		glPopMatrix();

		// Right Leg 3

		glTranslatef(0.0f, -1.25f, 0.0f);

		glPushMatrix();
			glColor3f(1.0f, 0.0f, 1.0f);
			glScalef(2.0f, 2.0f, 3.0f);
			prisma();
		glPopMatrix();

		// Left Foot

		// Right Leg 1

		glTranslatef(8.0f, 10.0f, 0.0f);

		glPushMatrix();
			glColor3f(1.0f, 0.0f, 0.0f);
			glScalef(2.0f, 5.0f, 3.0f);
			prisma();
		glPopMatrix();

		// Right Knee

		glTranslatef(0.0f, -3.0f, 0.0f);

		glPushMatrix();
			glColor3f(0.0f, 1.0f, 0.0f);
			glScalef(2.0f, 1.0f, 3.0f);
			prisma();
		glPopMatrix();

		// Right Leg 2

		glTranslatef(0.0f, -3.0f, 0.0f);

		glPushMatrix();
			glColor3f(0.0f, 0.0f, 1.0f);
			glScalef(2.0f, 5.0f, 3.0f);
			prisma();
		glPopMatrix();

		// Right Leg 3

		glTranslatef(0.0f, -2.75f, 0.0f);

		glPushMatrix();
			glColor3f(1.0f, 1.0f, 0.0f);
			glScalef(2.0f, 0.5f, 3.0f);
			prisma();
		glPopMatrix();

		// Right Leg 3

		glTranslatef(0.0f, -1.25f, 0.0f);

		glPushMatrix();
			glColor3f(1.0f, 0.0f, 1.0f);
			glScalef(2.0f, 2.0f, 3.0f);
			prisma();
		glPopMatrix();




		
		
  											
  glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.3f;
			break;
		case 's':
		case 'S':
			transZ -= 0.3f;
			break;
		case 'a':
		case 'A':
			rotY += 1.0;		
			break;
		case 'd':
		case 'D':
	
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		break;
	case GLUT_KEY_LEFT:
		break;
	case GLUT_KEY_RIGHT:
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



