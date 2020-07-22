#include <windows.h>
#include <GL/glut.h>



void init(void);
void tampil(void);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char,int,int); 
void ukuran (int,int);
void mouseMotion(int x, int y);
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

int main (int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1000, 800);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("672018342 672018370 672018378");
	init();
	glutIdleFunc(tampil);
	glutDisplayFunc(tampil);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(ukuran);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutMainLoop();
	return 0;
}

void init(void) {

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_LIGHTING); // yg gelap
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(5.0);
	glLineWidth(2.0);
	glDisable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

}
int gedung(){
		//depan
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex3f(8,7,12);
	glVertex3f(9,0,10);
	glVertex3f(16,0,10);
	glVertex3f(17,7,12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(8,12,13);
	glVertex3f(8,7,12);
	glVertex3f(17,7,12);
	glVertex3f(17,12,13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(8,17,12);
	glVertex3f(8,12,13);
	glVertex3f(17,12,13);
	glVertex3f(17,17,12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(8,17,12);
	glVertex3f(9,24,10);
	glVertex3f(16,24,10);
	glVertex3f(17,17,12);
	glEnd();
	//kiri samping
	glColor3f(1,1,0);
	glBegin(GL_POLYGON);
	glVertex3f(8,7,14);
	glVertex3f(9,0,12);
	glVertex3f(9,0,10);
	glVertex3f(8,7,12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(8,12,15);
	glVertex3f(8,7,14);
	glVertex3f(8,7,12);
	glVertex3f(8,12,13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(8,17,12);
	glVertex3f(8,12,13);
	glVertex3f(8,12,15);
	glVertex3f(8,17,14);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(8,17,12);
	glVertex3f(9,24,10);
	glVertex3f(9,24,12);
	glVertex3f(8,17,14);
	glEnd();
	//kanan samping
	glColor3f(1,1,0);
	glBegin(GL_POLYGON);
	glVertex3f(17,7,14);
	glVertex3f(16,0,12);
	glVertex3f(16,0,10);
	glVertex3f(17,7,12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(17,12,15);
	glVertex3f(17,7,14);
	glVertex3f(17,7,12);
	glVertex3f(17,12,13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(17,17,12);
	glVertex3f(17,12,13);
	glVertex3f(17,12,15);
	glVertex3f(17,17,14);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(17,17,12);
	glVertex3f(16,24,10);
	glVertex3f(16,24,12);
	glVertex3f(17,17,14);
	glEnd();
	//kiri
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
	glVertex3f(8,7,14);
	glVertex3f(9,0,12);
	glVertex3f(1,0,10);
	glVertex3f(0,7,12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(8,12,15);
	glVertex3f(8,7,14);
	glVertex3f(0,7,12);
	glVertex3f(0,12,13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0,17,12);
	glVertex3f(0,12,13);
	glVertex3f(8,12,15);
	glVertex3f(8,17,14);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0,17,12);
	glVertex3f(1,24,10);
	glVertex3f(9,24,12);
	glVertex3f(8,17,14);
	glEnd();
	//kanan
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
	glVertex3f(24,7,12);
	glVertex3f(23,0,10);
	glVertex3f(16,0,12);
	glVertex3f(17,7,14);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(17,12,15);
	glVertex3f(17,7,14);
	glVertex3f(24,7,12);
	glVertex3f(24,12,13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(24,17,12);
	glVertex3f(24,12,13);
	glVertex3f(17,12,15);
	glVertex3f(17,17,14);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(24,17,12);
	glVertex3f(23,24,10);
	glVertex3f(16,24,12);
	glVertex3f(17,17,14);
	glEnd();
	//kiri samping2
	glColor3f(0,0,1);
	glBegin(GL_POLYGON);
	glVertex3f(-2,7,16);
	glVertex3f(-1,0,12);
	glVertex3f(1,0,10);
	glVertex3f(0,7,12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-2,12,17);
	glVertex3f(-2,7,16);
	glVertex3f(0,7,12);
	glVertex3f(0,12,13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0,17,12);
	glVertex3f(0,12,13);
	glVertex3f(-2,12,17);
	glVertex3f(-2,17,16);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0,17,12);
	glVertex3f(1,24,10);
	glVertex3f(-1,24,14);
	glVertex3f(-2,17,16);
	glEnd();
	//kiri kiri 
	glColor3f(1,0,1);
	glBegin(GL_POLYGON);
	glVertex3f(-2,7,16);
	glVertex3f(-1,0,12);
	glVertex3f(-3,0,10);
	glVertex3f(-6,7,12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-2,12,17);
	glVertex3f(-2,7,16);
	glVertex3f(-6,7,12);
	glVertex3f(-6,12,13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-6,17,12);
	glVertex3f(-6,12,13);
	glVertex3f(-2,12,17);
	glVertex3f(-2,17,16);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-6,17,12);
	glVertex3f(-5,24,10);
	glVertex3f(-1,24,14);
	glVertex3f(-2,17,16);
	glEnd();
	//kanan kanan
	glColor3f(1,0,1);
	glBegin(GL_POLYGON);
	glVertex3f(26,7,16);
	glVertex3f(25,0,12);
	glVertex3f(27,0,10);
	glVertex3f(30,7,12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(26,12,17);
	glVertex3f(26,7,16);
	glVertex3f(30,7,12);
	glVertex3f(30,12,13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(30,17,12);
	glVertex3f(30,12,13);
	glVertex3f(26,12,17);
	glVertex3f(26,17,16);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(30,17,12);
	glVertex3f(29,24,10);
	glVertex3f(25,24,14);
	glVertex3f(26,17,16);
	glEnd();
	//kanan samping2
	glColor3f(0,0,1);
	glBegin(GL_POLYGON);
	glVertex3f(26,7,16);
	glVertex3f(25,0,12);
	glVertex3f(23,0,10);
	glVertex3f(24,7,12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(26,12,17);
	glVertex3f(26,7,16);
	glVertex3f(24,7,12);
	glVertex3f(24,12,13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(24,17,12);
	glVertex3f(24,12,13);
	glVertex3f(26,12,17);
	glVertex3f(26,17,16);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(24,17,12);
	glVertex3f(23,24,10);
	glVertex3f(25,24,14);
	glVertex3f(26,17,16);
	glEnd();
	//kiri kiri kiri
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex3f(-7,7,5);
	glVertex3f(-4,0,5);
	glVertex3f(-3,0,10);
	glVertex3f(-6,7,12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-8,12,5);
	glVertex3f(-7,7,5);
	glVertex3f(-6,7,12);
	glVertex3f(-6,12,13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-6,17,12);
	glVertex3f(-6,12,13);
	glVertex3f(-8,12,5);
	glVertex3f(-7,17,5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-7,17,5);
	glVertex3f(-5,24,5);
	glVertex3f(-5,24,10);
	glVertex3f(-6,17,12);
	glEnd();
	//kiri kiri kiri kiri
	glColor3f(1,0.5,0);
	glBegin(GL_POLYGON);
	glVertex3f(-7,7,5);
	glVertex3f(-4,0,5);
	glVertex3f(-4,0,-5);
	glVertex3f(-7,7,-5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-8,12,5);
	glVertex3f(-7,7,5);
	glVertex3f(-7,7,-5);
	glVertex3f(-8,12,-5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-7,17,-5);
	glVertex3f(-8,12,-5);
	glVertex3f(-8,12,5);
	glVertex3f(-7,17,5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-7,17,5);
	glVertex3f(-5,24,5);
	glVertex3f(-5,24,-5);
	glVertex3f(-7,17,-5);
	glEnd();
	//kiri kiri kiri kiri kiri kiri
	glColor3f(1,1,0);
	glBegin(GL_POLYGON);
	glVertex3f(-7,7,-5);
	glVertex3f(-4,0,-5);
	glVertex3f(-3,0,-10);
	glVertex3f(-6,7,-12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-8,12,-5);
	glVertex3f(-7,7,-5);
	glVertex3f(-6,7,-12);
	glVertex3f(-6,12,-13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-6,17,-12);
	glVertex3f(-6,12,-13);
	glVertex3f(-8,12,-5);
	glVertex3f(-7,17,-5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-7,17,-5);
	glVertex3f(-5,24,-5);
	glVertex3f(-5,24,-10);
	glVertex3f(-6,17,-12);
	glEnd();
	//kanan kanan kanan
	glColor3f(1,1,0);
	glBegin(GL_POLYGON);
	glVertex3f(31,7,5);
	glVertex3f(28,0,5);
	glVertex3f(27,0,10);
	glVertex3f(30,7,12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(32,12,5);
	glVertex3f(31,7,5);
	glVertex3f(30,7,12);
	glVertex3f(30,12,13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(30,17,12);
	glVertex3f(30,12,13);
	glVertex3f(32,12,5);
	glVertex3f(31,17,5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(31,17,5);
	glVertex3f(29,24,5);
	glVertex3f(29,24,10);
	glVertex3f(30,17,12);
	glEnd();
	//kanan kanan kanan kanan
	glColor3f(1,0.5,0);
	glBegin(GL_POLYGON);
	glVertex3f(31,7,5);
	glVertex3f(28,0,5);
	glVertex3f(28,0,-5);
	glVertex3f(31,7,-5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(32,12,5);
	glVertex3f(31,7,5);
	glVertex3f(31,7,-5);
	glVertex3f(32,12,-5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(31,17,-5);
	glVertex3f(32,12,-5);
	glVertex3f(32,12,5);
	glVertex3f(31,17,5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(31,17,5);
	glVertex3f(29,24,5);
	glVertex3f(29,24,-5);
	glVertex3f(31,17,-5);
	glEnd();
	//kanan kanan kanan kanan kanan
	glColor3f(1,1,0);
	glBegin(GL_POLYGON);
	glVertex3f(31,7,-5);
	glVertex3f(28,0,-5);
	glVertex3f(27,0,-10);
	glVertex3f(30,7,-12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(32,12,-5);
	glVertex3f(31,7,-5);
	glVertex3f(30,7,-12);
	glVertex3f(30,12,-13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(30,17,-12);
	glVertex3f(30,12,-13);
	glVertex3f(32,12,-5);
	glVertex3f(31,17,-5);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(31,17,-5);
	glVertex3f(29,24,-5);
	glVertex3f(29,24,-10);
	glVertex3f(30,17,-12);
	glEnd();
	//kanan kanan belakang
	glColor3f(1,0,1);
	glColor3f(1,0,1);
	glBegin(GL_POLYGON);
	glVertex3f(26,7,-16);
	glVertex3f(25,0,-12);
	glVertex3f(27,0,-10);
	glVertex3f(30,7,-12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(26,12,-17);
	glVertex3f(26,7,-16);
	glVertex3f(30,7,-12);
	glVertex3f(30,12,-13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(30,17,-12);
	glVertex3f(30,12,-13);
	glVertex3f(26,12,-17);
	glVertex3f(26,17,-16);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(30,17,-12);
	glVertex3f(29,24,-10);
	glVertex3f(25,24,-14);
	glVertex3f(26,17,-16);
	glEnd();
	//kanan samping2 belakang
	glColor3f(0,0,1);
	glBegin(GL_POLYGON);
	glVertex3f(26,7,-16);
	glVertex3f(25,0,-12);
	glVertex3f(23,0,-10);
	glVertex3f(24,7,-12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(26,12,-17);
	glVertex3f(26,7,-16);
	glVertex3f(24,7,-12);
	glVertex3f(24,12,-13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(24,17,-12);
	glVertex3f(24,12,-13);
	glVertex3f(26,12,-17);
	glVertex3f(26,17,-16);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(24,17,-12);
	glVertex3f(23,24,-10);
	glVertex3f(25,24,-14);
	glVertex3f(26,17,-16);
	glEnd();
	//belakang
	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex3f(8,7,-12);
	glVertex3f(9,0,-10);
	glVertex3f(16,0,-10);
	glVertex3f(17,7,-12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(8,12,-13);
	glVertex3f(8,7,-12);
	glVertex3f(17,7,-12);
	glVertex3f(17,12,-13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(8,17,-12);
	glVertex3f(8,12,-13);
	glVertex3f(17,12,-13);
	glVertex3f(17,17,-12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(8,17,-12);
	glVertex3f(9,24,-10);
	glVertex3f(16,24,-10);
	glVertex3f(17,17,-12);
	glEnd();
	//kiri samping belakang
	glColor3f(1,1,0);
	glBegin(GL_POLYGON);
	glVertex3f(8,7,-14);
	glVertex3f(9,0,-12);
	glVertex3f(9,0,-10);
	glVertex3f(8,7,-12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(8,12,-15);
	glVertex3f(8,7,-14);
	glVertex3f(8,7,-12);
	glVertex3f(8,12,-13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(8,17,-12);
	glVertex3f(8,12,-13);
	glVertex3f(8,12,-15);
	glVertex3f(8,17,-14);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(8,17,-12);
	glVertex3f(9,24,-10);
	glVertex3f(9,24,-12);
	glVertex3f(8,17,-14);
	glEnd();
	//kanan samping belakang
	glColor3f(1,1,0);
	glBegin(GL_POLYGON);
	glVertex3f(17,7,-14);
	glVertex3f(16,0,-12);
	glVertex3f(16,0,-10);
	glVertex3f(17,7,-12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(17,12,-15);
	glVertex3f(17,7,-14);
	glVertex3f(17,7,-12);
	glVertex3f(17,12,-13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(17,17,-12);
	glVertex3f(17,12,-13);
	glVertex3f(17,12,-15);
	glVertex3f(17,17,-14);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(17,17,-12);
	glVertex3f(16,24,-10);
	glVertex3f(16,24,-12);
	glVertex3f(17,17,-14);
	glEnd();
	//kiri belakang
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
	glVertex3f(8,7,-14);
	glVertex3f(9,0,-12);
	glVertex3f(1,0,-10);
	glVertex3f(0,7,-12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(8,12,-15);
	glVertex3f(8,7,-14);
	glVertex3f(0,7,-12);
	glVertex3f(0,12,-13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0,17,-12);
	glVertex3f(0,12,-13);
	glVertex3f(8,12,-15);
	glVertex3f(8,17,-14);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0,17,-12);
	glVertex3f(1,24,-10);
	glVertex3f(9,24,-12);
	glVertex3f(8,17,-14);
	glEnd();
	//kanan belakang
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);
	glVertex3f(24,7,-12);
	glVertex3f(23,0,-10);
	glVertex3f(16,0,-12);
	glVertex3f(17,7,-14);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(17,12,-15);
	glVertex3f(17,7,-14);
	glVertex3f(24,7,-12);
	glVertex3f(24,12,-13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(24,17,-12);
	glVertex3f(24,12,-13);
	glVertex3f(17,12,-15);
	glVertex3f(17,17,-14);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(24,17,-12);
	glVertex3f(23,24,-10);
	glVertex3f(16,24,-12);
	glVertex3f(17,17,-14);
	glEnd();
	//kiri samping2 belakang
	glColor3f(0,0,1);
	glBegin(GL_POLYGON);
	glVertex3f(-2,7,-16);
	glVertex3f(-1,0,-12);
	glVertex3f(1,0,-10);
	glVertex3f(0,7,-12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-2,12,-17);
	glVertex3f(-2,7,-16);
	glVertex3f(0,7,-12);
	glVertex3f(0,12,-13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0,17,-12);
	glVertex3f(0,12,-13);
	glVertex3f(-2,12,-17);
	glVertex3f(-2,17,-16);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(0,17,-12);
	glVertex3f(1,24,-10);
	glVertex3f(-1,24,-14);
	glVertex3f(-2,17,-16);
	glEnd();
	//kiri kiri belakang
	glColor3f(1,0,1);
	glBegin(GL_POLYGON);
	glVertex3f(-2,7,-16);
	glVertex3f(-1,0,-12);
	glVertex3f(-3,0,-10);
	glVertex3f(-6,7,-12);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-2,12,-17);
	glVertex3f(-2,7,-16);
	glVertex3f(-6,7,-12);
	glVertex3f(-6,12,-13);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-6,17,-12);
	glVertex3f(-6,12,-13);
	glVertex3f(-2,12,-17);
	glVertex3f(-2,17,-16);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-6,17,-12);
	glVertex3f(-5,24,-10);
	glVertex3f(-1,24,-14);
	glVertex3f(-2,17,-16);
	glEnd();
	
	//atap
	glBegin(GL_POLYGON);
	glVertex3f(16,24,10);
	glVertex3f(9,24,10);
	glVertex3f(9,24,-10);
	glVertex3f(16,24,-10);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(9,24,10);
	glVertex3f(9,24,12);
	glVertex3f(1,24,10);
	glVertex3f(1,24,-10);
	glVertex3f(9,24,-12);
	glVertex3f(9,24,-10);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(1,24,10);
	glVertex3f(-1,24,14);
	glVertex3f(-5,24,10);
	glVertex3f(-5,24,-10);
	glVertex3f(-1,24,-14);
	glVertex3f(1,24,-10);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(16,24,10);
	glVertex3f(16,24,12);
	glVertex3f(23,24,10);
	glVertex3f(23,24,-10);
	glVertex3f(16,24,-12);
	glVertex3f(16,24,-10);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(23,24,10);
	glVertex3f(25,24,14);
	glVertex3f(29,24,10);
	glVertex3f(29,24,-10);
	glVertex3f(25,24,-14);
	glVertex3f(23,24,-10);
	glEnd();
}

int tangga(float banyak, float xa,float xb, float ya, float yb,float za,float zb){
	for (int a=0;a<banyak;a++){
	
	glBegin(GL_POLYGON);
	glVertex3f(xa,yb,za);
	glVertex3f(xa,ya,za);
	glVertex3f(xb,ya,za);
	glVertex3f(xb,yb,za);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(xa,yb,zb);
	glVertex3f(xa,ya,zb);
	glVertex3f(xa,ya,za);
	glVertex3f(xa,yb,za);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(xa,yb,zb);
	glVertex3f(xa,ya,zb);
	glVertex3f(xb,ya,zb);
	glVertex3f(xb,yb,zb);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(xb,yb,zb);
	glVertex3f(xb,ya,zb);
	glVertex3f(xb,ya,za);
	glVertex3f(xb,yb,za);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(xa,ya,za);
	glVertex3f(xa,ya,zb);
	glVertex3f(xb,ya,zb);
	glVertex3f(xb,ya,za);
	glEnd();
	xa+=-2;
	xb+=2;
	ya+=-2;
	yb+=-2;
	za+=2;
	zb+=-2;
	}
}

int Lampu(){
//lampu merah
	glBegin(GL_POLYGON);
	glColor3f(0.3,0.3,0.3);
	glVertex3f(-35,-2,80);
	glVertex3f(-34.5,-2,80);
	glVertex3f(-34.5,-10,80);
	glVertex3f(-35,-10,80);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3,0.3,0.3);
	glVertex3f(-35,-2,80);
	glVertex3f(-35,-2,79.5);
	glVertex3f(-35,-10,79.5);
	glVertex3f(-35,-10,80);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3,0.3,0.3);
	glVertex3f(-34.5,-2,80);
	glVertex3f(-34.5,-2,79.5);
	glVertex3f(-34.5,-10,79.5);
	glVertex3f(-34.5,-10,80);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3,0.3,0.3);
	glVertex3f(-35,-2,79.5);
	glVertex3f(-34.5,-2,79.5);
	glVertex3f(-34.5,-10,79.5);
	glVertex3f(-35,-10,79.5);
	glEnd();
	//
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f(-35.5,-2,80.5);
	glVertex3f(-34,-2,80.5);
	glVertex3f(-34,3,80.5);
	glVertex3f(-35.5,3,80.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0,1,0);
	segienam(90,-34.75,2,80.51,0.5,180);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	segienam(90,-34.75,0.5,80.51,0.5,180);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	segienam(90,-34.75,-1,80.51,0.5,180);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f(-35.5,-2,79);
	glVertex3f(-34,-2,79);
	glVertex3f(-34,3,79);
	glVertex3f(-35.5,3,79);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f(-35.5,-2,79);
	glVertex3f(-35.5,-2,80.5);
	glVertex3f(-35.5,3,80.5);
	glVertex3f(-35.5,3,79);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f(-34,-2,79);
	glVertex3f(-34,-2,80.5);
	glVertex3f(-34,3,80.5);
	glVertex3f(-34,3,79);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f(-35.5,3,80.5);
	glVertex3f(-34,3,80.5);
	glVertex3f(-34,3,79);
	glVertex3f(-35.5,3,79);
	glEnd();
	//tiang kanan
	glBegin(GL_POLYGON);
	glColor3f(0.3,0.3,0.3);
	glVertex3f(60,-2,80);
	glVertex3f(59.5,-2,80);
	glVertex3f(59.5,-10,80);
	glVertex3f(60,-10,80);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3,0.3,0.3);
	glVertex3f(60,-2,80);
	glVertex3f(60,-2,79.5);
	glVertex3f(60,-10,79.5);
	glVertex3f(60,-10,80);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3,0.3,0.3);
	glVertex3f(59.5,-2,80);
	glVertex3f(59.5,-2,79.5);
	glVertex3f(59.5,-10,79.5);
	glVertex3f(59.5,-10,80);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.3,0.3,0.3);
	glVertex3f(60,-2,79.5);
	glVertex3f(59.5,-2,79.5);
	glVertex3f(59.5,-10,79.5);
	glVertex3f(60,-10,79.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f(60.5,-2,80.5);
	glVertex3f(59,-2,80.5);
	glVertex3f(59,3,80.5);
	glVertex3f(60.5,3,80.5);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0,1,0);
	segienam(90,59.75,2,80.51,0.5,180);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	segienam(90,59.75,0.5,80.51,0.5,180);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	segienam(90,59.75,-1,80.51,0.5,180);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f(60.5,-2,79);
	glVertex3f(59,-2,79);
	glVertex3f(59,3,79);
	glVertex3f(60.5,3,79);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f(60.5,-2,79);
	glVertex3f(60.5,-2,80.5);
	glVertex3f(60.5,3,80.5);
	glVertex3f(60.5,3,79);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f(59,-2,79);
	glVertex3f(59,-2,80.5);
	glVertex3f(59,3,80.5);
	glVertex3f(59,3,79);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f(60.5,3,80.5);
	glVertex3f(59,3,80.5);
	glVertex3f(59,3,79);
	glVertex3f(60.5,3,79);
	glEnd();
}
void tampil (void){
	glPushMatrix();
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
	glRotatef(xrot,1.0f,0.0f,0.0f);
	glRotatef(yrot,0.0f,1.0f,0.0f);
	//gedung
	gedung();
	//tangga
	glColor3f(0.2,0.2,0.2);
	tangga(5,-10,35,0,-2,16,-16);
	
	glPopMatrix();
	glutSwapBuffers();
	
		
}

void idle()
{
	if (!mouseDown)
	{
		xrot +=0.3f;
		yrot +=0.4f;
	}
	glutPostRedisplay();
}
void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else{
	mouseDown = false;}
	glutPostRedisplay();
}
void mouseMotion(int x, int y)
{
	if (mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;
		
		glutPostRedisplay();
	}
}

void keyboard(unsigned char key, int a, int b){
	switch (key){
	case 'w':
	case 'W':
		glTranslatef(0.0,0.0,3.0);
		break;
	case 'd':
	case 'D':
		glTranslatef(3.0,0.0,0.0);
		break;
	case 's':
	case 'S':
		glTranslatef(0.0,0.0,-3.0);
		break;
	case 'a':
	case 'A':
		glTranslatef(-3.0,0.0,0.0);
		break;
	case '7':
		glTranslatef(0.0,3.0,0.0);
		break;
	case '9':
		glTranslatef(0.0,-3.0,0.0);
		break;
	case '2':
		glRotatef(2.0,1.0,0.0,0.0);
		break;
	case '8':
		glRotatef(-2.0,1.0,0.0,0.0);
		break;
	case '6':
		glRotatef(2.0,0.0,1.0,0.0);
		break;
	case '4':
		glRotatef(-2.0,0.0,1.0,0.0);
		break;	
	case '3':
		glRotatef(-2.0,0.0,0.0,1.0);
		break;	
	case '5':
		if (is_depth)
		{
			is_depth = 0;
			glDisable(GL_DEPTH_TEST);
		}
		else
		{
			is_depth = 1;
			glEnable(GL_DEPTH_TEST);
		}
		
	}
	tampil();
}

void ukuran(int lebar, int tinggi)
{
 	if (tinggi == 0) tinggi = 1;
	 glMatrixMode(GL_PROJECTION);
	 gluPerspective(30.0,lebar / tinggi, 70.0, 500.0);
	 glTranslatef(-10.0,-5.0,-150.0);
	 glMatrixMode(GL_MODELVIEW);	
}















