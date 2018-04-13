//////////////////////////////////////////////////////////////////////////////
//  Computación Gráfica                                                   ////
//  Tarea # 05                                                            ////
//  Nombre: Pacheco Franco Jesús Enrique                                  ////
//  Grupo: 05                                                             ////
//  Semestre: 2018-2                                                      ////
//  Fecha: 12/Abril/2018                                                  ////
//////////////////////////////////////////////////////////////////////////////

#include "Main.h"

#define PI 3.14159265359

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;

float angleZ = 0.0f;

GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

float degreesToRadians(float degrees) {
	return (float)(degrees*PI) / 180;
}

void conicalCylinder(int snippets, float topRadius,float bottomRadius, float height, int wired) {
	int i; // Para los ciclos
	float snippet = 360.0 / snippets; // Retazo de círculo
	float *topX, *topZ, *bottomX, *bottomZ; // Arreglos para guardar vértices
	float currentAngle = 0.0f; // Acumulador de angulos
	float halfHeight = height/2; // La mitad de la altura

	topX = (float *)malloc((snippets + 1) * sizeof(float));
	topZ = (float *)malloc((snippets + 1) * sizeof(float));
	bottomX = (float *)malloc((snippets + 1) * sizeof(float));
	bottomZ = (float *)malloc((snippets + 1) * sizeof(float));


	if (topX != NULL && topZ != NULL && bottomX != NULL && bottomZ != NULL) {
		for (i = 0; i<snippets; i++) {
			topX[i] = topRadius * cos(degreesToRadians(currentAngle));
			topZ[i] = topRadius * sin(degreesToRadians(currentAngle));
			bottomX[i] = bottomRadius * cos(degreesToRadians(currentAngle));
			bottomZ[i] = bottomRadius * sin(degreesToRadians(currentAngle));
			
			currentAngle += snippet;
		}
		
		topX[snippets] = topX[0];
		topZ[snippets] = topZ[0];
		bottomX[snippets] = bottomX[0];
		bottomZ[snippets] = bottomZ[0];

		if (wired == 0)
			glBegin(GL_QUADS);
		else
			glBegin(GL_LINE_STRIP);
		for (i = 0; i<snippets; i++) {
			glVertex3f(topX[i], halfHeight, topZ[i]);
			glVertex3f(0.0, halfHeight, 0.0);
			glVertex3f(0.0, halfHeight, 0.0);
			glVertex3f(topX[i+1], halfHeight, topZ[i+1]);

			glVertex3f(bottomX[i], -halfHeight, bottomZ[i]);
			glVertex3f(topX[i], halfHeight, topZ[i]);
			glVertex3f(topX[i+1], halfHeight, topZ[i+1]);
			glVertex3f(bottomX[i+1], -halfHeight, bottomZ[i+1]);

			glVertex3f(bottomX[i], -halfHeight, bottomZ[i]);
			glVertex3f(0.0, -halfHeight, 0.0);
			glVertex3f(0.0, -halfHeight, 0.0);
			glVertex3f(bottomX[i + 1], -halfHeight, bottomZ[i + 1]);
		}
		glEnd();
		free(topX);
		free(topZ);
		free(bottomX);
		free(bottomZ);
	}
}

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
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glColor3f(1.0, 0.0, 0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glColor3f(0.0, 1.0, 0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glColor3f(0.0, 0.0, 1.0);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glColor3f(1.0, 0.0, 1.0);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glColor3f(1.0,1.0,0.0);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glColor3f(0.0, 1.0, 0.0);
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

	/*glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);*/
	
	//Poner Código Aquí.

	glTranslatef(0, 0, -10);

	conicalCylinder(10,2.5,5.0,5,1);
	
							
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
		case 'z':
		case 'Z':
			angleZ += 0.5f;
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
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Tarea 05 JEPF"); // Nombre de la Ventana
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



