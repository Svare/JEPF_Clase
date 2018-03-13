//////////////////////////////////////////////////////////////////////////////
//  Laboratorio de Computaci�n Gr�fica                                    ////
//  Practica # 05                                                         ////
//  Nombre: Pacheco Franco Jes�s Enrique                                  ////
//  Version Visual Studio: Visual Studio Community 2017 15.5.27130.2027   ////
//  Grupo: 02                                                             ////
//  Semestre: 2018-2                                                      ////
//  Fecha: 12/Marzo/2018                                                  ////
//////////////////////////////////////////////////////////////////////////////

/* 

	TECLAS
		
		i/I: Cerrar Dedos
		o/O: Abrir Dedos
		y/Y: Bajar Codo
		u/U: Subir Codo
		k/K: Adelante Mu�eca
		l/L: Atras Mu�eca
		j/J: Subir Hombro
		h/H: Bajar Hombro
		s/S: Alejar
		w/W: Acercar
		a/A: Moverse a la Izquierda
		d/D: Moverse a la Derecha

*/

#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;

float anguloHombro = 0.0f;
float anguloCodo = 0.0f;
float anguloMuneca = 0.0f;
float anguloDedos = 0.0f;


GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas V�rtice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas V�rtice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas V�rtice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas V�rtice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas V�rtice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas V�rtice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas V�rtice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas V�rtice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
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

	glTranslatef(transX -5.5, 0.0f, transZ -3.0);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	
	//Poner C�digo Aqu�.

	glBegin(GL_LINES);
		glColor3f(1.0, 0.0, 0.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(100.0, 0.0, 0.0);
		glColor3f(0.0, 1.0, 0.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 100.0, 0.0);
		glColor3f(0.0, 0.0, 1.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(0.0, 0.0, 100.0);
	glEnd();

	glRotatef(anguloHombro, 0.0, 0.0, 1.0);

	glPushMatrix(); // Hombro
		glColor3f(1.0f, 0.0f, 0.0f);
			glScalef(1.0f, 2.0f, 0.5f);
			prisma();
	glPopMatrix();

	glPushMatrix(); // Bicep
		glColor3f(0.0f, 1.0f, 0.0f);
			glTranslatef(2.0f, 0.0f, 0.0f);
			glScalef(3.0f, 2.0f, 0.5f);
			prisma();
	glPopMatrix();

	glTranslatef(3.75f, 0.0f, 0.0f); // Muevo mi pivote a donde quiero
	glRotatef(anguloCodo, 0.0f, 0.0f, 1.0f); // Rotacion Codo
	glTranslatef(-3.75f, 0.0f, 0.0f); // Regreso el pivote para que no afecte las demas transformaciones

	glPushMatrix(); // Codo
		glColor3f(0.0f, 0.0f, 1.0f);
			glTranslatef(3.75f, 0.0f, 0.0f);
			glScalef(0.5f, 2.0f, 0.5f);
			prisma();
	glPopMatrix();

	glPushMatrix(); // Antebrazo
		glColor3f(1.0f, 1.0f, 0.0f);
			glTranslatef(6.0f, 0.0f, 0.0f);
			glScalef(4.0f, 2.0f, 0.5f);
			prisma();
	glPopMatrix();

	glTranslatef(8.25f, 0.0f, 0.0f);
	glRotatef(anguloMuneca, 0.0f, 1.0f, 0.0f); // Rotacion Mu�eca
	glTranslatef(-8.25f, 0.0f, 0.0f);

	glPushMatrix(); // Mu�eca
		glColor3f(1.0f, 0.0f, 1.0f);
			glTranslatef(8.25f, 0.0f, 0.0f);
			glScalef(0.5f, 2.0f, 0.5f);
			prisma();
	glPopMatrix();

	glTranslatef(9.5f, 0.0f, 0.0f); // Centro de la Palma

	glPushMatrix(); // Palma
		glColor3f(0.0f, 1.0f, 1.0f);
			glScalef(2.0f, 2.0f, 0.5f);
			prisma();
	glPopMatrix();

	glPushMatrix(); // Rotaciones Dedo Pulgar

		glTranslatef(-0.5f, 1.0f, 0.0f);
		glRotatef(anguloDedos, 1.0, 0.0, 0.0); // Rotacion Pulgar 01
		glTranslatef(0.5f, -1.0f, 0.0f);

		glPushMatrix(); // Pulgar 01
			glColor3f(1.0f, 0.0f, 0.0f);
				glTranslatef(-0.5f, 1.25f, 0.0f);
				glScalef(0.4f, 0.5f, 0.5f);
				prisma();
		glPopMatrix();

		glTranslatef(-0.5f, 1.5f, 0.0f);
		glRotatef(anguloDedos - anguloDedos*0.5, 1.0, 0.0, 0.0); // Rotacion Pulgar 02
		glTranslatef(0.5f, -1.5f, 0.0f);

		glPushMatrix(); // Pulgar 02
			glColor3f(0.0f, 1.0f, 0.0f);
				glTranslatef(-0.5f, 1.75f, 0.0f);
				glScalef(0.4f, 0.5f, 0.5f);
				prisma();
		glPopMatrix();

	glPopMatrix(); // Fin Rotaciones Dedo Pulgar

	glPushMatrix(); // Rotaciones Dedo Indice

		glTranslatef(1.0f, 1.25f, 0.0f);
		glRotatef(anguloDedos, 0.0, -1.0, 0.0); // Rotacion Indice 01
		glTranslatef(-1.0f, -1.25f, 0.0f);

		glPushMatrix(); // Indice 01
			glColor3f(1.0f, 0.0f, 0.0f);
				glTranslatef(1.25f, 0.75f, 0.0f);
				glScalef(0.5f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();

		glTranslatef(1.5f, 1.25f, 0.0f);
		glRotatef(anguloDedos - anguloDedos*0.5, 0.0, -1.0, 0.0); // Rotacion Indice 02
		glTranslatef(-1.5f, -1.25f, 0.0f);

		glPushMatrix(); // Indice 02
			glColor3f(0.0f, 1.0f, 0.0f);
				glTranslatef(1.75f, 0.75f, 0.0f);
				glScalef(0.5f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();

		glTranslatef(2.0f, 1.25f, 0.0f);
		glRotatef(anguloDedos - anguloDedos*0.75, 0.0, -1.0, 0.0); // Rotacion Indice 03
		glTranslatef(-2.0f, -1.25f, 0.0f);

		glPushMatrix(); // Indice 03
			glColor3f(0.0f, 0.0f, 1.0f);
				glTranslatef(2.25f, 0.75f, 0.0f);
				glScalef(0.5f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();

	glPopMatrix(); // Fin Rotaciones Dedo Indice

	glPushMatrix(); // Rotaciones Medio

		glTranslatef(1.0f, 0.25f, 0.0f);
		glRotatef(anguloDedos, 0.0, -1.0, 0.0); // Rotacion Medio 01
		glTranslatef(-1.0f, -0.25f, 0.0f);

		glPushMatrix(); // Medio 01
			glColor3f(1.0f, 0.0f, 0.0f);
				glTranslatef(1.25f, 0.25f, 0.0f);
				glScalef(0.5f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();

		glTranslatef(1.5f, 0.25f, 0.0f);
		glRotatef(anguloDedos - anguloDedos * 0.5, 0.0, -1.0, 0.0); // Rotacion Medio 02
		glTranslatef(-1.5f, -0.25f, 0.0f);

		glPushMatrix(); // Medio 02
			glColor3f(0.0f, 1.0f, 0.0f);
				glTranslatef(1.75f, 0.25f, 0.0f);
				glScalef(0.5f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();

		glTranslatef(2.0f, 0.25f, 0.0f);
		glRotatef(anguloDedos - anguloDedos * 0.75, 0.0, -1.0, 0.0); // Rotacion Medio 03
		glTranslatef(-2.0f, -0.25f, 0.0f);

		glPushMatrix(); // Medio 03
			glColor3f(0.0f, 0.0f, 1.0f);
				glTranslatef(2.25f, 0.25f, 0.0f);
				glScalef(0.5f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();
	
	glPopMatrix(); // Fin Rotaciones Medio

	glPushMatrix(); // Rotaciones Anular

		glTranslatef(1.0f, -0.25f, 0.0f);
		glRotatef(anguloDedos, 0.0, -1.0, 0.0); // Rotacion Anular 01
		glTranslatef(-1.0f, 0.25f, 0.0f);

		glPushMatrix(); // Anular 01
			glColor3f(1.0f, 0.0f, 0.0f);
				glTranslatef(1.25f, -0.25f, 0.0f);
				glScalef(0.5f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();

		glTranslatef(1.5f, -0.25f, 0.0f);
		glRotatef(anguloDedos - anguloDedos * 0.5, 0.0, -1.0, 0.0); // Rotacion Anular 02
		glTranslatef(-1.5f, 0.25f, 0.0f);

		glPushMatrix(); // Anular 02
			glColor3f(0.0f, 1.0f, 0.0f);
				glTranslatef(1.75f, -0.25f, 0.0f);
				glScalef(0.5f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();

		glTranslatef(2.0f, -0.25f, 0.0f);
		glRotatef(anguloDedos - anguloDedos * 0.75, 0.0, -1.0, 0.0); // Rotacion Anular 03
		glTranslatef(-2.0f, 0.25f, 0.0f);

		glPushMatrix(); // Anular 03
			glColor3f(0.0f, 0.0f, 1.0f);
				glTranslatef(2.25f, -0.25f, 0.0f);
				glScalef(0.5f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();

	glPopMatrix(); // Fin Rotaciones Anular
	
	glPushMatrix(); // Rotaciones Me�ique

		glTranslatef(1.0f, -0.75f, 0.0f);
		glRotatef(anguloDedos, 0.0, -1.0, 0.0); // Rotacion Me�ique 01
		glTranslatef(-1.0f, 0.75f, 0.0f);

		glPushMatrix(); // Me�ique 01
			glColor3f(1.0f, 0.0f, 0.0f);
				glTranslatef(1.25f, -0.75f, 0.0f);
				glScalef(0.5f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();

		glTranslatef(1.5f, -0.75f, 0.0f);
		glRotatef(anguloDedos - anguloDedos * 0.5, 0.0, -1.0, 0.0); // Rotacion Me�ique 02
		glTranslatef(-1.5f, 0.75f, 0.0f);

		glPushMatrix(); // Me�ique 02
			glColor3f(0.0f, 1.0f, 0.0f);
				glTranslatef(1.65f, -0.75f, 0.0f);
				glScalef(0.3f, 0.4f, 0.5f);
				prisma();
		glPopMatrix();

		glTranslatef(1.8f, -0.75f, 0.0f);
		glRotatef(anguloDedos - anguloDedos * 0.75, 0.0, -1.0, 0.0); // Rotacion Me�ique 03
		glTranslatef(-1.8f, 0.75f, 0.0f);

		glPushMatrix(); // Me�ique 03
			glColor3f(0.0f, 0.0f, 1.0f);
				glTranslatef(1.9f, -0.75f, 0.0f);
				glScalef(0.2f, 0.4f, 0.5f);
				prisma();
		glPopMatrix(); 

	glPopMatrix(); // Fin Rotaciones Me�ique
							
	glutSwapBuffers ( );
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
	//glOrtho(-20,20,-20,20,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX +=0.2f;
			break;
		case 'd':
		case 'D':
			transX -=0.2f;
			break;
		case 'j':
		case 'J':
			if(anguloHombro <= 80.0)
				anguloHombro += 1.0;
			break;
		case 'h':
		case 'H':
			if (anguloHombro >= -80.0)
				anguloHombro -= 1.0;
			break;
		case 'k':
		case 'K':
			if (anguloMuneca >= -45.0)
				anguloMuneca -= 1.0;
			break;
		case 'l':
		case 'L':
			if (anguloMuneca <= 45.0)
				anguloMuneca += 1.0;
			break;
		case 'u':
		case 'U':
			if (anguloCodo <= 80.0)
				anguloCodo += 1.0;
			break;
		case 'y':
		case 'Y':
			if (anguloCodo >= 0.0)
				anguloCodo -= 1.0;
			break;
		case 'i':
		case 'I':
			if (anguloDedos <= 90.0)
				anguloDedos += 1.0;
			break;
		case 'o':
		case 'O':
			if (anguloDedos >= 0.0)
				anguloDedos -= 1.0;
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
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tama�o de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut funci�n de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut funci�n en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut funci�n de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}



