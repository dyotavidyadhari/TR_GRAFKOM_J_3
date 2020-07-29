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


void ngon(int n, float cx, float cy, float radius, float rotAngle, float zzz){
    double angle, angleInc;
    int k;

    if(n<3) return;
    angle=rotAngle*3.14159265/180;
    angleInc=2*3.14159265/(n);

    glVertex3f(radius*cos(angle)+cx, cy, radius*sin(angle)+zzz);

    for(k=0;k<n;k++){
        angle+=angleInc;
        glVertex3f(radius*cos(angle)+cx,radius*sin(angle)+cy, zzz);
    }
}

void drawArc(float cx, float cy, float cz, float radius, float startAngle, float sweep)
{ // startAngle and sweep are in degrees
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


int main (int argc, char **argv)
{
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

void init(void) {

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_LIGHTING); // yg gelap
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(2.0);
	glLineWidth(1.5);
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
int garis(float banyak, float xa,float xb,float ya,float yb,float za,float zb){
	for(int a=0;a<banyak; a++){
	glBegin(GL_LINES);
	glVertex3f(xa,ya,za);
	glVertex3f(xb,yb,zb);
	xa+=0.2;
	xb-=0.2;
	ya-=1;
	yb-=1;
	za-=0.25;
	zb-=0.25;
	glEnd();
}}
int garisdua(float banyak, float xa,float xb,float ya,float yb,float za,float zb){
	for(int a=0;a<banyak; a++){
	glBegin(GL_LINES);
	glVertex3f(xa,ya,za);
	glVertex3f(xb,yb,zb);
	ya-=1;
	yb-=1;
	za-=0.2;
	zb-=0.2;
	glEnd();}
}
int garistiga(float banyak, float xa,float xb,float ya,float yb,float za,float zb){
	for(int a=0;a<banyak; a++){
	glBegin(GL_LINES);
	glVertex3f(xa,ya,za);
	glVertex3f(xb,yb,zb);
	ya-=1;
	yb-=1;
	za+=0.2;
	zb+=0.2;
	glEnd();}
}
int garisempat(float banyak, float xa,float xb,float ya,float yb,float za,float zb){
	for(int a=0;a<banyak; a++){
	glBegin(GL_LINES);
	glVertex3f(xa,ya,za);
	glVertex3f(xb,yb,zb);
	xa-=0.2;
	xb+=0.2;
	ya-=1;
	yb-=1;
	za+=0.3;
	zb+=0.3;
	glEnd();
}}
int garisbelakang(float banyak, float xa,float xb,float ya,float yb,float za,float zb){
	for(int a=0;a<banyak; a++){
	glBegin(GL_LINES);
	glVertex3f(xa,ya,za);
	glVertex3f(xb,yb,zb);
	xa+=0.2;
	xb-=0.2;
	ya-=1;
	yb-=1;
	za+=0.25;
	zb+=0.25;
	glEnd();
}}
int garisduabelakang(float banyak, float xa,float xb,float ya,float yb,float za,float zb){
	for(int a=0;a<banyak; a++){
	glBegin(GL_LINES);
	glVertex3f(xa,ya,za);
	glVertex3f(xb,yb,zb);
	ya-=1;
	yb-=1;
	za+=0.2;
	zb+=0.2;
	glEnd();}
}
int garistigabelakang(float banyak, float xa,float xb,float ya,float yb,float za,float zb){
	for(int a=0;a<banyak; a++){
	glBegin(GL_LINES);
	glVertex3f(xa,ya,za);
	glVertex3f(xb,yb,zb);
	ya-=1;
	yb-=1;
	za-=0.2;
	zb-=0.2;
	glEnd();}
}
int garisempatbelakang(float banyak, float xa,float xb,float ya,float yb,float za,float zb){
	for(int a=0;a<banyak; a++){
	glBegin(GL_LINES);
	glVertex3f(xa,ya,za);
	glVertex3f(xb,yb,zb);
	xa-=0.2;
	xb+=0.2;
	ya-=1;
	yb-=1;
	za-=0.3;
	zb-=0.3;
	glEnd();
}}
int garisan(float banyak,float xa,float xb,float ya,float yb,float za,float zb){
	for(int a=0;a<banyak; a++){
	glBegin(GL_LINES);
	glVertex3f(xa,ya,za);
	glVertex3f(xb,yb,zb);
	xa+=0.1;
	xb+=0.1;
	ya-=0.75;
	yb-=0.75;
	za-=0.2;
	zb-=0.2;
	glEnd();
}}
int garisandua(float banyak,float xa,float xb,float ya,float yb,float za,float zb){
	for(int a=0;a<banyak; a++){
	glBegin(GL_LINES);
	glVertex3f(xa,ya,za);
	glVertex3f(xb,yb,zb);
	ya-=0.75;
	yb-=0.75;
	za-=0.15;
	zb-=0.15;
	glEnd();
}}
int garisantiga(float banyak,float xa,float xb,float ya,float yb,float za,float zb){
	for(int a=0;a<banyak; a++){
	glBegin(GL_LINES);
	glVertex3f(xa,ya,za);
	glVertex3f(xb,yb,zb);
	ya-=0.75;
	yb-=0.75;
	za+=0.15;
	zb+=0.15;
	glEnd();
}}
int garisanempat(float banyak,float xa,float xb,float ya,float yb,float za,float zb){
	for(int a=0;a<banyak; a++){
	glBegin(GL_LINES);
	glVertex3f(xa,ya,za);
	glVertex3f(xb,yb,zb);
	xa-=0.12;
	xb-=0.12;
	ya-=0.75;
	yb-=0.75;
	za+=0.22;
	zb+=0.22;
	glEnd();
}}
int garisanlima(float banyak,float xa,float xb,float ya,float yb,float za,float zb){
	for(int a=0;a<banyak; a++){
	glBegin(GL_LINES);
	glVertex3f(xa,ya,za);
	glVertex3f(xb,yb,zb);
	xa-=0.1;
	xb-=0.1;
	ya-=0.75;
	yb-=0.75;
	za-=0.2;
	zb-=0.2;
	glEnd();
}}
int garisanenam(float banyak,float xa,float xb,float ya,float yb,float za,float zb){
	for(int a=0;a<banyak; a++){
	glBegin(GL_LINES);
	glVertex3f(xa,ya,za);
	glVertex3f(xb,yb,zb);
	xa+=0.12;
	xb+=0.12;
	ya-=0.75;
	yb-=0.75;
	za+=0.22;
	zb+=0.22;
	glEnd();
}}
int garisanbelakang(float banyak,float xa,float xb,float ya,float yb,float za,float zb){
	for(int a=0;a<banyak; a++){
	glBegin(GL_LINES);
	glVertex3f(xa,ya,za);
	glVertex3f(xb,yb,zb);
	xa+=0.1;
	xb+=0.1;
	ya-=0.75;
	yb-=0.75;
	za+=0.2;
	zb+=0.2;
	glEnd();
}}
int garisanduabelakang(float banyak,float xa,float xb,float ya,float yb,float za,float zb){
	for(int a=0;a<banyak; a++){
	glBegin(GL_LINES);
	glVertex3f(xa,ya,za);
	glVertex3f(xb,yb,zb);
	ya-=0.75;
	yb-=0.75;
	za+=0.15;
	zb+=0.15;
	glEnd();
}}
int garisantigabelakang(float banyak,float xa,float xb,float ya,float yb,float za,float zb){
	for(int a=0;a<banyak; a++){
	glBegin(GL_LINES);
	glVertex3f(xa,ya,za);
	glVertex3f(xb,yb,zb);
	ya-=0.75;
	yb-=0.75;
	za-=0.15;
	zb-=0.15;
	glEnd();
}}
int garisanempatbelakang(float banyak,float xa,float xb,float ya,float yb,float za,float zb){
	for(int a=0;a<banyak; a++){
	glBegin(GL_LINES);
	glVertex3f(xa,ya,za);
	glVertex3f(xb,yb,zb);
	xa-=0.12;
	xb-=0.12;
	ya-=0.75;
	yb-=0.75;
	za-=0.22;
	zb-=0.22;
	glEnd();
}}
int garisanlimabelakang(float banyak,float xa,float xb,float ya,float yb,float za,float zb){
	for(int a=0;a<banyak; a++){
	glBegin(GL_LINES);
	glVertex3f(xa,ya,za);
	glVertex3f(xb,yb,zb);
	xa-=0.1;
	xb-=0.1;
	ya-=0.75;
	yb-=0.75;
	za+=0.2;
	zb+=0.2;
	glEnd();
}}
int garisanenambelakang(float banyak,float xa,float xb,float ya,float yb,float za,float zb){
	for(int a=0;a<banyak; a++){
	glBegin(GL_LINES);
	glVertex3f(xa,ya,za);
	glVertex3f(xb,yb,zb);
	xa+=0.12;
	xb+=0.12;
	ya-=0.75;
	yb-=0.75;
	za-=0.22;
	zb-=0.22;
	glEnd();
}}




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
	glColor3f(0,0,0);
	garis(8,8,17,7,7,12,12);
	garisdua(5,8,17,12,12,13,13);
	garistiga(5,8,17,17,17,12,12);
	garisempat(8,9,16,24,24,10,10);
	
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
	glColor3f(0.5,0.5,0.5);
	garisan(10,8,0,7,7,14,12);
	garisandua(7,8,0,12,12,15,13);
	garisantiga(7,8,0,17,17,14,12);
	garisanempat(9,9,1,24,24,12,10);
	

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
	glColor3f(0.5,0.5,0.5);
	garisanlima(10,17,24,7,7,14,12);
	garisandua(7,17,24,12,12,15,13);
	garisantiga(7,17,24,17,17,14,12);
	garisanenam(9,23,16,24,24,10,12);
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
	glColor3f(0,1,0.5);
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
	glColor3f(0,0,0);
	garisbelakang(8,17,8,7,7,-12,-12);
	garisduabelakang(5,8,17,12,12,-13,-13);
	garistigabelakang(5,8,17,17,17,-12,-12);
	garisempatbelakang(8,9,16,24,24,-10,-10);
	

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
	glColor3f(0.5,0.5,0.5);
	garisanbelakang(10,8,0,7,7,-14,-12);
	garisanduabelakang(7,8,0,12,12,-15,-13);
	garisantigabelakang(7,8,0,17,17,-14,-12);
	garisanempatbelakang(9,9,1,24,24,-12,-10);
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
	glColor3f(0.5,0.5,0.5);
	garisanlimabelakang(10,17,24,7,7,-14,-12);
	garisanduabelakang(7,17,24,12,12,-15,-13);
	garisantigabelakang(7,17,24,17,17,-14,-12);
	garisanenambelakang(9,23,16,24,24,-10,-12);
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
	xa+=-1;
	xb+=1;
	ya+=-1;
	yb+=-1;
	za+=1;
	zb+=-1;
	}
}

lampumerah(){
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
	ngon(90,-34.75,2,0.5,180,80.51);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	ngon(90,-34.75,0.5,0.5,180,80.51);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	ngon(90,-34.75,-1,0.5,180,80.51);
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
	ngon(90,59.75,2,0.5,180,80.51);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	ngon(90,59.75,0.5,0.5,180,80.51);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(1,0,0);
	ngon(90,59.75,-1,0.5,180,80.51);
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
int kubus(float xa, float xb, float ya, float yb,float za,float zb){
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
}
int kursi(){
		// kursi 1
	glColor3f(0.5,0.2,0.2);
	kubus(50,50.5,-10,-9,75,73);
	kubus(45,45.5,-10,-9,75,73);
	kubus(45,50.5,-8,-9,75,73);
	kubus(45,50.5,-6,-8,73.5,73);
	//kursi 2
	glColor3f(0.5,0.2,0.2);
	kubus(40,40.5,-10,-9,75,73);
	kubus(35,35.5,-10,-9,75,73);
	kubus(35,40.5,-8,-9,75,73);
	kubus(35,40.5,-6,-8,73.5,73);
	//kursi 3
	glColor3f(0.5,0.2,0.2);
	kubus(-25,-25.5,-10,-9,75,73);
	kubus(-20,-20.5,-10,-9,75,73);
	kubus(-20,-25.5,-8,-9,75,73);
	kubus(-20,-25.5,-6,-8,73.5,73);
	//kursi 4
	glColor3f(0.5,0.2,0.2);
	kubus(-15,-15.5,-10,-9,75,73);
	kubus(-10,-10.5,-10,-9,75,73);
	kubus(-10,-15.5,-8,-9,75,73);
	kubus(-10,-15.5,-6,-8,73.5,73);
	//kursi 1 belakang
	glColor3f(0.5,0.2,0.2);
	kubus(50,50.5,-10,-9,-45,-43);
	kubus(45,45.5,-10,-9,-45,-43);
	kubus(45,50.5,-8,-9,-45,-43);
	kubus(45,50.5,-6,-8,-43.5,-43);
	//kursi 2 belakang
	glColor3f(0.5,0.2,0.2);
	kubus(40,40.5,-10,-9,-45,-43);
	kubus(35,35.5,-10,-9,-45,-43);
	kubus(35,40.5,-8,-9,-45,-43);
	kubus(35,40.5,-6,-8,-43.5,-43);
	//kursi 3 belakang
	glColor3f(0.5,0.2,0.2);
	kubus(-25,-25.5,-10,-9,-45,-43);
	kubus(-20,-20.5,-10,-9,-45,-43);
	kubus(-20,-25.5,-8,-9,-45,-43);
	kubus(-20,-25.5,-6,-8,-43.5,-43);
	//kursi 4 belakang
	glColor3f(0.5,0.2,0.2);
	kubus(-15,-15.5,-10,-9,-45,-43);
	kubus(-10,-10.5,-10,-9,-45,-43);
	kubus(-10,-15.5,-8,-9,-45,-43);
	kubus(-10,-15.5,-6,-8,-43.5,-43);
}
int satpam(){
	//pos satpam
	glColor3f(0.8,0.8,0.8);
	kubus(51,40,-10,3,46,45);
	kubus(50,51,-10,3,55,46);
	kubus(40,41,-10,3,55,46);
	kubus(50,44.5,-10,-5,55,54);
	kubus(50,44.5,1.5,3,55,54);
	kubus(41,44.5,0,3,55,54);
	glColor3f(0.5,0.2,0.2);
	kubus(51.5,39.5,3.5,3,57,45);
	kubus(50,44.5,-4.75,-5,55,56);
	glColor3f(0.5,0.3,0.3);
	glBegin(GL_POLYGON);
	glVertex3f(41,-10,55);
	glVertex3f(41,0,55);
	glVertex3f(44.5,0,55);
	glVertex3f(44.5,-10,55);
	glEnd();
	glColor4f(0,0,1,0.3);
	glBegin(GL_POLYGON);
	glVertex3f(50,-5,55);
	glVertex3f(50,1.5,55);
	glVertex3f(44.5,1.5,55);
	glVertex3f(44.5,-5,55);
	glEnd();
}
int kelas(){
	glColor3f(0,1,1);
	kubus(2,22,15,0,-5,-6);
	kubus(2,2,15,0,-5,5);
	glColor3f(0,0,1);
	kubus(22,22,15,0,-5,5);
	kubus(2,22,15,15,-5,5);
	kubus(2,8,15,0,5,5);
	kubus(22,16,15,0,5,5);
	kubus(8,16,15,8,5,5);
	glColor3f(0.5,0.2,0.2);
	kubus(8,16,8,0,5,5);
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex3f(12,0,5);
	glVertex3f(12,8,5);
	glEnd();
	glBegin(GL_POINTS);
	glVertex3f(11,3,5);
	glVertex3f(13,3,5);
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
	//kelas
	kelas();
	//tangga
	glColor3f(0.2,0.2,0.2);
	tangga(9,-10,35,0,-2,16,-16);
	//lampu merah
	lampumerah();
	//kursi
	kursi();
	//satpam
	satpam();
	
	//pager
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
        
          glPushMatrix();         //monumen globe
        glTranslated(-19,0,40);
        glRotated(90,1,1,0);
        glColor3f(0.5,0.5,0.5);
        glutWireSphere(8,16,14);
        glPopMatrix();

        glColor3f(0.6,0.6,0.6);
        balok(10,10,1.5,-24,-10,35);

        glColor3f(0.5,0,0.9);
        balok(17,7,10,-30,-9,80); //bus 1
        balok(17,7,10,26,-9,91);    //2

        float zzz=79.3, yyy=90.2;     //ban 1
        for (float ban=0;ban<10;ban++){
        glBegin(GL_POLYGON);
        glColor3f(0,0,0);
        ngon(50,-26,-8,2,0,zzz);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0,0,0);
        ngon(50,-26,-8,2,0,zzz+7);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0,0,0);
        ngon(50,-17,-8,2,0,zzz);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0,0,0);
        ngon(50,-17,-8,2,0,zzz+7);
        glEnd();

        //ban 2
        glBegin(GL_POLYGON);
        glColor3f(0,0,0);
        ngon(50,30,-8,2,0,yyy);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0,0,0);
        ngon(50,30,-8,2,0,yyy+7);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0,0,0);
        ngon(50,39,-8,2,0,yyy);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0,0,0);
        ngon(50,39,-8,2,0,yyy+7);
        glEnd();


        zzz+=0.2; yyy+=0.2;
        }
        glBegin(GL_POLYGON);
        glColor3f(0.74,0.74,0.74);
        ngon(50,-26,-8,1,0,79);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.74,0.74,0.74);
        ngon(50,-26,-8,1,0,88.2);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.74,0.74,0.74);
        ngon(50,-17,-8,1,0,79);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.74,0.74,0.74);
        ngon(50,-17,-8,1,0,88.2);
        glEnd();
            //ban 2
        glBegin(GL_POLYGON);
        glColor3f(0.74,0.74,0.74);
        ngon(50,30,-8,1,0,90);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.74,0.74,0.74);
        ngon(50,30,-8,1,0,99.2);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.74,0.74,0.74);
        ngon(50,39,-8,1,0,90);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.74,0.74,0.74);
        ngon(50,39,-8,1,0,99.2);
        glEnd();

        //jendela bis 1

        glColor3f(0.91,0.98,1);
        kotak(15,5,-29.2,-4.3,79.9);
        kotaksamping(5.5,4,-30.1,-3.7,80.7);
        kotak(15,5,-29.2,-4.3,87.1);
        kotaksamping(5.5,5.8,-12.9,-5.3,80.7);

        glColor3f(1,1,0.3);
        kotaksamping(1,1.6,-12.9,-7.6,80.2);
        kotaksamping(1,1.6,-12.9,-7.6,85.8);

        //jendela bus 2
        //balok(17,7,10,26,-9,91);    //2
        glColor3f(0.91,0.98,1);
        kotak(15,5,27,-4.3,90.9);
        kotaksamping(5.5,4,43.2,-3.7,91.6);
        kotak(15,5,27,-4.3,98.2);
        kotaksamping(5.5,5.8,25.9,-5.1,91.8);

        glColor3f(1,1,0.3);
        kotaksamping(1,1.6,25.9,-7.6,96.8);
        kotaksamping(1,1.6,25.9,-7.6,91.8);
        
	

	
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
	 glTranslatef(-10.0,-5.0,-400.0);
	 glMatrixMode(GL_MODELVIEW);	
}
















