#include <windows.h>
#include <GL/glut.h>
#include <math.h>



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


void segienam(int sudut, float smbx, float smby,float smbz, float radius, float perputaran){
    double angle, angleInc;
    int k;

    if(sudut<3) return;
    angle=perputaran*3.14159265/180;
    angleInc=2*3.14159265/sudut;


    for(k=0;k<=sudut;k++){
        angle+=angleInc;
        glVertex3f(radius*cos(angle)+smbx, radius*sin(angle)+smby, smbz);}
}

int main (int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(900, 700);
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

void init(void){

	glClearColor(1.0, 1.0, 1.0, 1.0);
	//glEnable(GL_LIGHTING); // yg gelap
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

int halaman(){
	//dasar dan jalan raya (bagian warna 0.2)
	glBegin(GL_POLYGON);
	glColor3f(0.5,1,0.5);
	glVertex3f(-35,-10,80);
	glVertex3f(60,-10,80);
	glVertex3f(60,-10,-50);
	glVertex3f(-35,-10,-50);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.2,0.2,0.2);
	glVertex3f(-35,-10,80);
	glVertex3f(-50,-10,80);
	glVertex3f(-50,-10,-50);
	glVertex3f(-35,-10,-50);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.2,0.2,0.2);
	glVertex3f(60,-10,80);
	glVertex3f(75,-10,80);
	glVertex3f(75,-10,-50);
	glVertex3f(60,-10,-50);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.2,0.2,0.2);
	glVertex3f(-50,-10,80);
	glVertex3f(75,-10,80);
	glVertex3f(75,-10,100);
	glVertex3f(-50,-10,100);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.2,0.2,0.2);
	glVertex3f(-50,-10,-60);
	glVertex3f(75,-10,-60);
	glVertex3f(75,-10,-50);
	glVertex3f(-50,-10,-50);
	glEnd();
}

int dasar(){
	//dasar
	glBegin(GL_POLYGON);
	glColor3f(0.5,1,0.5);
	glVertex3f(-50,-12,100);
	glVertex3f(75,-12,100);
	glVertex3f(75,-10,100);
	glVertex3f(-50,-10,100);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5,1,0.5);
	glVertex3f(-50,-12,-60);
	glVertex3f(75,-12,-60);
	glVertex3f(75,-10,-60);
	glVertex3f(-50,-10,-60);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5,1,0.5);
	glVertex3f(75,-12,100);
	glVertex3f(75,-12,-60);
	glVertex3f(75,-10,-60);
	glVertex3f(75,-10,100);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5,1,0.5);
	glVertex3f(-50,-12,100);
	glVertex3f(-50,-12,-60);
	glVertex3f(-50,-10,-60);
	glVertex3f(-50,-10,100);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.5,1,0.5);
	glVertex3f(-50,-12,100);
	glVertex3f(75,-12,100);
	glVertex3f(75,-10,-60);
	glVertex3f(-50,-10,-60);
	glEnd();
}

int gedung(){
		//depan
	glColor3f(0.4,0.4,1);
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
	glColor3f(1,1,0.5);
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
	glColor3f(1,1,0.5);
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
	glColor3f(1,1,1);
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
	glColor3f(1,1,1);
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
	glColor3f(1,1,0.5);
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
	glColor3f(0.9,0.9,0.9);
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
	glColor3f(0.9,0.9,0.9);
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
	glColor3f(1,1,0.5);
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
	glColor3f(0.9,0.9,0.9);
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
	glColor3f(0.4,0.4,1);
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
	glColor3f(0.9,0.9,0.9);
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
	glColor3f(0.9,0.9,0.9);
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
	glColor3f(0.4,0.4,1);
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
	glColor3f(0.9,0.9,0.9);
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
	glColor3f(0.9,0.9,0.9);
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
	glColor3f(1,1,0.5);
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
	glColor3f(0.4,0.4,1);
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
	glColor3f(1,1,0.5);
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
	glColor3f(1,1,0.5);
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
	glColor3f(1,1,1);
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
	glColor3f(1,1,1);
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
	glColor3f(1,1,0.5);
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
	glColor3f(0.9,0.9,1);
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
	glColor3f(0.9,0.9,0.9);
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

int lampu(){
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

void balok(float p, float l, float t, float x, float y, float z){ //dari depan pojok kiri bawah
    glBegin(GL_QUADS); //depan
    //glColor3f(1.0,1.0,1.0);
    glVertex3f(x,y,z);
    glVertex3f(x,y+t,z);
    glVertex3f(x+p,y+t,z);
    glVertex3f(x+p,y,z);
    glEnd();

    glBegin(GL_QUADS); //belakang
    glVertex3f(x,y,z+l);
    glVertex3f(x,y+t,z+l);
    glVertex3f(x+p,y+t,z+l);
    glVertex3f(x+p,y,z+l);
    glEnd();

    glBegin(GL_QUADS); //kanan
    glVertex3f(x+p,y+t,z);
    glVertex3f(x+p,y,z);
    glVertex3f(x+p,y,z+l);
    glVertex3f(x+p,y+t,z+l);
    glEnd();

    glBegin(GL_QUADS); //kiri
    glVertex3f(x,y+t,z);
    glVertex3f(x,y,z);
    glVertex3f(x,y,z+l);
    glVertex3f(x,y+t,z+l);

    glBegin(GL_QUADS); //bawah
    //glColor3f(0,1,0);
    glVertex3f(x,y,z);
    glVertex3f(x+p,y,z);
    glVertex3f(x+p,y,z+l);
    glVertex3f(x,y,z+l);
    glEnd();

    glBegin(GL_QUADS); //atas
    //glColor3f(0,1,0);
    glVertex3f(x,y+t,z);
    glVertex3f(x+p,y+t,z);
    glVertex3f(x+p,y+t,z+l);
    glVertex3f(x,y+t,z+l);
    glEnd();
}

void ngon(int n, float cx, float cy, float radius, float rotAngle, float zzz){  //sejajar sumbu y
    double angle, angleInc;
    int k;

    if(n<3) return;
    angle=rotAngle*3.14159265/180;
    angleInc=2*3.14159265/(n);

    glVertex3f(radius*cos(angle)+cx, radius*sin(angle)+cy,zzz);

    for(k=0;k<n;k++){
        angle+=angleInc;
        glVertex3f(radius*cos(angle)+cx, radius*sin(angle)+cy,zzz);
    }
}

void drawArc(float cx, float cy, float cz, float radius, float startAngle, float sweep){ // startAngle and sweep are in degrees
  const int n = 30; // number of intermediate segments in arc
  float angle = startAngle * 3.14159265 / 180; // initial angle in radians
  float angleInc = sweep * 3.14159265 /(180 * n); // angle increment
  glVertex3f(cx + radius * cos(angle), cy, cz + radius * sin(angle));
  for(int k = 1; k < n; k++, angle += angleInc)
    glVertex3f(cx + radius * cos(angle), cy, cz + radius * sin(angle));
}

void kotaksamping(float l, float t, float x, float y, float z){ //dari depan pojok kiri bawah
    glBegin(GL_QUADS); //depan
    //glColor3f(1.0,1.0,1.0);
    glVertex3f(x,y,z);
    glVertex3f(x,y,z+l);
    glVertex3f(x,y+t,z+l);
    glVertex3f(x,y+t,z);
    glEnd();
}

void kotak(float p, float t, float x, float y, float z){ //dari depan pojok kiri bawah
    glBegin(GL_QUADS); //depan
    //glColor3f(1.0,1.0,1.0);
    glVertex3f(x,y,z);
    glVertex3f(x,y+t,z);
    glVertex3f(x+p,y+t,z);
    glVertex3f(x+p,y,z);
    glEnd();
}

void tampil (void){
	glPushMatrix();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gluLookAt(0.0f,0.0f,3.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
	glRotatef(xrot,1.0f,0.0f,0.0f);
	glRotatef(yrot,0.0f,1.0f,0.0f);

	//dasar
	dasar();
	//halaman dan jalan raya
	halaman();
	//gedung
	gedung();
	//tangga
	lampu();
	glColor3f(0.2,0.2,0.2);
	tangga(5,-10,35,0,-2,16,-16);

        int cc=16;
        float y_nya=-10;
        for (int f=0;f<cc;f++){
        glBegin(GL_LINE_STRIP);      //pager bunder
        glColor3f(1,0.9,0.8);
        drawArc(12.5,y_nya,0,40,117,327 );
        y_nya+=0.15;
        glEnd();
        }
        glColor3f(1,0.9,0.8);
        balok(0.5,40,2.4,-6,-10,35.5);
        balok(0.5,40,2.4,31,-10,35.3);

        glBegin(GL_POLYGON);
        float ysatu=-10, ydua=0;
               //tangga turun
            glColor3f(0.35,0.35,0.35);
            glVertex3f(24.9,ysatu,75.5);
            glVertex3f(24.9,ydua,14);
            glVertex3f(0,ydua,14);
            glVertex3f(0,ysatu,75.5);
        glEnd();

        glBegin(GL_POLYGON);
               //pager di atas tangga turun kanan
            glColor3f(1,0.9,0.8);

            glVertex3f(21.9,-9,75.5);
            glVertex3f(21.9,-7,75.5);
            glVertex3f(21.9,-1,34);
            glVertex3f(21.9,-3,34);
        glEnd();

        glBegin(GL_POLYGON);
               //pager di atas tangga turun kiri
            glColor3f(1,0.9,0.8);

            glVertex3f(3,-9,75.5);
            glVertex3f(3,-7,75.5);
            glVertex3f(3,-1,34);
            glVertex3f(3,-3,34);
        glEnd();

        glBegin(GL_POLYGON);
               //tangga turun kanan
            glColor3f(0.35,0.35,0.35);
            glVertex3f(24.9,-10,75.5);
            glVertex3f(24.9,-12,75.5);
            glVertex3f(24.9,0,14);
            glVertex3f(24.9,-3,14);
        glEnd();

        glBegin(GL_POLYGON);
               //tangga turun kiri
            glColor3f(0.35,0.35,0.35);
            glVertex3f(0,-10,75.5);
            glVertex3f(0,-12,75.5);
            glVertex3f(0,0,14);
            glVertex3f(0,-3,14);
        glEnd();

        glColor3f(1,0.8,0.8);
        balok(8,4,2.5,8.45,-9.6,64);    //pot tanaman 1
        balok(8,4,2.5,8.45,-8.5,56);    // pot tanaman 2
        balok(8,4,2.5,8.45,-7,48);    //pot tanaman 3
        balok(8,4,2.5,8.45,-5.5,40);    //pot tanaman 4

        glColor3f(0,0.38,0.1);
        balok(6,2.5,1.5,9.45,-7.6,65);    // tanaman 1
        balok(6,2.5,1.5,9.45,-6.5,57);    //  tanaman 2
        balok(6,2.5,1.5,9.45,-5,49);    // tanaman 3
        balok(6,2.5,1.5,9.45,-3.5,41);    // tanaman 4

        //atas gedung
        float y_nya1=24;
        for (int ff=0;ff<10;ff++){
        glBegin(GL_LINE_STRIP);
        glColor3f(1,0.9,0.8);
        drawArc(12.5,y_nya1,0,10,117,327);
        y_nya1+=0.15;
        glEnd();
        }

        glPushMatrix();
        glRotated(5,0,1,0);
        glColor3f(1,0.7,0.6);
        balok(5,5,5,14.5,22,5.5);
        glPopMatrix();

        glPushMatrix();
        glRotated(5,0,-1,0);
        glColor3f(1,0.7,0.6);
        balok(5,5,5,6,22,3.5);
        glPopMatrix();

        glColor3f(1,0.9,0.7);
        balok(5,3.5,10,10,22,-2);

	glPopMatrix();
	glutSwapBuffers();


}

void idle(){
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

void mouseMotion(int x, int y){
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

void ukuran(int lebar, int tinggi){
 	if (tinggi == 0) tinggi = 1;
	 glMatrixMode(GL_PROJECTION);
	 gluPerspective(30.0,lebar / tinggi, 70.0, 500.0);
	 glTranslatef(-10.0,-5.0,-400.0);
	 glMatrixMode(GL_MODELVIEW);
}
