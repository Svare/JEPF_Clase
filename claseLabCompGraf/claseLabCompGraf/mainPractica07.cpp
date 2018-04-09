//////////////////////////////////////////////////////////////////////////////
//  Laboratorio de Computación Gráfica                                    ////
//  Practica # 07 Modelos de Iluminación                                  ////
//  Nombre: Pacheco Franco Jesús Enrique                                  ////
//  Version Visual Studio: Visual Studio Community 2017 15.5.27130.2027   ////
//  Grupo: 02                                                             ////
//  Semestre: 2018-2                                                      ////
//  Fecha: 09/Abril/2018                                                  ////
//////////////////////////////////////////////////////////////////////////////

/*
	Modelos de Iluminacion

	Difuso: Tiene que ver con las sombras
	Especular: Tiene que ver con las luces
	Ambiental: Tiene que ver con el color de la luz

	Una vez que activamos la iluminacion glColor ya no funciona ahora
	vamos a hacer uso de materiales, los cuales van a tener cada una
	de las componentes anteriormente mencionadas.

	Fuentes de Luz

	~ Direccional: Analogía de como funciona el sol, luces con la misma direccion en todos lados.
	Posicional: Importa la poscion de nuestra fuente de luz 
	Reflector: Funciona como una lampara de luz solo una determinada zona.

*/

#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = 0.0f;

float LightAngle = 30.0f;

bool	light = false;		// Luz ON/OFF
bool	positional = true;

static int spin = 0;


GLfloat LightAmbient[]= { 0.0f, 0.0f, 0.0f, 1.0f }; 			// Ambient Light Values
GLfloat LightDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat LightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat LightPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position
GLfloat LightPosition1[]= { 0.0f, 0.0f, 1.0f, 0.0f };			// Light Position
GLfloat LightDirection[]= { 0.0f, 0.0f, -2.0f };				// Light Position

GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };					// Color background
GLfloat mat_diffuse[] = { 0.0, 1.0, 0.0, 1.0 };					// Object Color main
GLfloat mat_specular[] = { 0.0, 0.0, 1.0, 1.0 };				// Specular color
GLfloat mat_shininess[] = { 100.0 };							// 1 to greatest

GLfloat mat_ambient1[] = { 1.0, 1.0, 1.0, 1.0 };				// Color background
GLfloat mat_diffuse1[] = { 0.0, 0.0, 1.0, 1.0 };				// Object Color main
GLfloat mat_specular1[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular color
GLfloat mat_shininess1[] = { 100.0 };							// 1 to greatest

void InitGL ( GLvoid )     // Inicializamos parametros
{
	glShadeModel(GL_FLAT);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	//glEnable (GL_COLOR_MATERIAL);
	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);				// Setup The Ambient Light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);				// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular);			// Setup The Diffuse Light
	//glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);			// Position The Light
	//glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION,LightDirection);			// Direction Of The Light

	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);							// Enable Light One
	//glEnable(GL_LIGHT0);

}

void prisma (void)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},		//Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, 0.5},		//Coordenadas Vértice 2 V2
				{-0.5 ,-0.5, -0.5},		//Coordenadas Vértice 3 V3
				{0.5 ,-0.5, -0.5},		//Coordenadas Vértice 4 V4
				{0.5 ,0.5, 0.5},		//Coordenadas Vértice 5 V5
				{0.5 ,0.5, -0.5},		//Coordenadas Vértice 6 V6
				{-0.5 ,0.5, -0.5},		//Coordenadas Vértice 7 V7
				{-0.5 ,0.5, 0.5},		//Coordenadas Vértice 8 V8
				};

		glBegin(GL_POLYGON);	//Front
			//glColor3f(0.5,0.0,0.0);
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			//glColor3f(0.0,0.0,1.0);
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			//glColor3f(0.0,1.0,0.0);
			glNormal3f( 0.0f, 0.0f,-1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			//glColor3f(1.0,1.0,1.0);
			glNormal3f(-1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			//glColor3f(0.4,0.2,0.6);
			glNormal3f( 0.0f,-1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			//glColor3f(0.8,0.2,0.4);
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if(positional)
		glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, LightAngle);			// Position The Light
	

	glPushMatrix ();

		glTranslatef (0.0, 0.0, -5.0);
	
		glPushMatrix(); //Esfera que representa a nuestra fuente de Luz
						//Este código es para que la fuente de luz gire
			glRotatef (spin, 1.0, 0.0, 0.0);
			glTranslatef (0.0, 0.0, 4.5);
			if(positional)
			{
				glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
				glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION,LightDirection);			
			}
			else
				glLightfv(GL_LIGHT1, GL_POSITION, LightPosition1);

			glPushMatrix();
				glDisable(GL_LIGHTING);
				glColor3f (1.0, 1.0, 0.0);
				
				glutSolidSphere(0.07,10,10);
				if (!light)
				{
					glDisable(GL_LIGHTING);
				}
				else
				{
					glEnable(GL_LIGHTING);
				}
			glPopMatrix();
		glPopMatrix();

		glPushMatrix();
				glTranslatef (transX, transY, transZ);
				glRotatef(angleX, 1.0f, 0.0f, 0.0f);
				glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
				glRotatef(angleY, 0.0f, 1.0f, 0.0f);
				glColor3f(1.0, 0.0, 0.0);
				glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
				glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
				glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
				glutSolidSphere(2.0, 20, 20);
				glTranslatef(3,0,0);
				glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient1);
				glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
				glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
				glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);
				prisma();
				
		glPopMatrix();


	glPopMatrix ();
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
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix						
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			transZ +=0.5f;
			break;
		case 's':
		case 'S':
			transZ -=0.5f;
			break;
		case 'a':
		case 'A':
			transX -=0.5f;
			break;
		case 'd':
		case 'D':
			transX +=0.5f;
			break;

		//Agregar aquí teclas para movimiento de luz
		case 'i':		//Movimientos de Luz
		case 'I':
			spin = (spin - 20) % 360;
			break;
		case 'k':
		case 'K':
			spin = (spin + 20) % 360;
			break;;


		case 'l':   //Activamos/desactivamos luz
		case 'L':
			light=!light;
			break;

		case 'p':   //Activamos/desactivamos luz
		case 'P':
			positional=!positional;
			break;

		case 'c':
			LightAngle += 2.0f;
			printf("Angulo = %f\n", LightAngle);
			break;
		case 'v':
			LightAngle -= 2.0f;
			printf("Angulo = %f\n", LightAngle);
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
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 2.0f;
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY -= 2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY += 2.0f;
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
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 7"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}

