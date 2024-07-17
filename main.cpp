#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

const float PI =3.141592653;

int xcloud = 0;


void rock();
void display1();
void display2();
void display3();
void ship();
void water();
void water2();
void sun();
void moon();
void cloud();
void DrawCircle(float cx, float cy, float r, int num_segments);
void print();
struct timespec jmp, jmp2;

GLint a=0,b=0,c=0,d=0,e=0,f=0,g=500,h=600,x=0,i=0;
int slide=0;
GLfloat theta=0.0;
float xc=0.0,yc=0.0,x1c=5.0;
void update(int value)
{
a+=20.0;
xcloud=xcloud+5;
glutPostRedisplay(); //which display must be displayed for second loop
glutTimerFunc(80,update,0); //200
}



void display1()
{
glClear(GL_COLOR_BUFFER_BIT);
sun();
    cloud();
    water2();
glPushMatrix();  // Set current matrix on the stack
glTranslated(a,75,0.0); //glTranslatef(someX=a, someY=75, someZ=0); transformation 1
ship(); //build a ship DrawObject(ONE);
glPopMatrix();  // Pop the old matrix without the transformations.
water(); //u need water to float
glFlush();
glutSwapBuffers();

}

void display2()
{

glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0f, 0.0f, 0.0f, 0.0f); //ext
moon();
cloud();
water2();
rock();
glPushMatrix();
glTranslated(b,75,0.0);
ship();
glPopMatrix();
water();
glFlush();
glutSwapBuffers();

       

}

void display3()
{
glClear(GL_COLOR_BUFFER_BIT);
moon();
cloud();
water2();
glPopMatrix();
x-=1;
rock();
glPushMatrix();
glTranslated(c,100+x*5,0.0);
glRotated(-15,0,0,1);
ship();
glPopMatrix();
water();
//print();
glFlush();
glutSwapBuffers();
}

void sun()
{
 float angle;
    int xp=170;
    int y=620;
    int radius=70;
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    for (int i = 0;i < 100;i++)
    {
        angle = i * 2 * (PI / 100);
        glVertex2f(xp + (cos(angle) * radius), y + (sin(angle) * radius)); //-400
    }
    glEnd();
//ext ends
}

void moon()
{
float angle;
    int xp=650;
    int y=640;
    int radius=50;
    glColor3f(0.96, 0.96, 0.8);
    glBegin(GL_POLYGON);
    for (int i = 0;i < 100;i++)
    {
        angle = i * 2 * (PI / 100);
        glVertex2f(xp + (cos(angle) * radius), y + (sin(angle) * radius)); //-400
    }
    glEnd();
//ext ends
}
void water2()
{


glColor3f(0.196078,0.6,0.8);
glBegin(GL_POLYGON);
glVertex2f(0,100);
glVertex2f(1000,0);
glVertex2f(1000,200);
glVertex2f(0,200);
glEnd();
}

void water()
{


glColor3f(0.196078,0.6,0.8);
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(1000,0);
glVertex2f(1000,100);
glVertex2f(0,100);
glEnd();
}


void cloud()
{
glColor3f(1.0, 1.0, 1.0);
DrawCircle(30 + xcloud, 500, 60, 2000);//1
DrawCircle(50 + xcloud,500, 80, 2000);//2
DrawCircle(100 + xcloud, 500, 55, 2000);//3


DrawCircle(130 + xcloud, 500, 60, 2000);//1
DrawCircle(140 + xcloud,500, 80, 2000);//2
DrawCircle(150 + xcloud,500, 55, 2000);//3

DrawCircle(170 + xcloud, 500, 60, 2000);//1
DrawCircle(200 + xcloud,500, 80, 2000);//2
DrawCircle(300 + xcloud, 500, 55, 2000);//3

DrawCircle(700 + xcloud, 500, 60, 2000);//1
DrawCircle(800 + xcloud,500, 80, 2000);//2
DrawCircle(900 + xcloud, 500, 55, 2000);//3
glFlush();

}
void DrawCircle(float cx, float cy, float r, int num_segments){
float x;
float y;
glBegin(GL_TRIANGLE_FAN);
for (int i = 0; i < num_segments; i++)
{
float theta = (2.0f * 3.1415926f *i)/(num_segments);//get the current angle

x = r * cosf(theta);//calculate the x component
y = r * sinf(theta);//calculate the y component

glVertex2f(x + cx, y + cy);//output vertex

}
glEnd();
}

void ship()
{

glScaled(24,24,0);

glColor3f(0.329412,0.329412,0.329412); //base
glBegin(GL_POLYGON);
glVertex2f(0.5,5.0);
glVertex2f(3,1);
glVertex2f(22,1);
glVertex2f(24.0,5.0);
glEnd();

glColor3f(1.0,1.0,1.0); //ring
glBegin(GL_POLYGON);
glVertex2f(1.35,3.5);
glVertex2f(1.6,3.2);
glVertex2f(23.2,3.2);
glVertex2f(23.35,3.5);
glEnd();

glColor3f(0.329412,0.329412,0.329412); //base
glBegin(GL_POLYGON);
glVertex2f(21.0,5.0);
glVertex2f(21.0,6.0);
glVertex2f(24.5,6.0);
glVertex2f(24.0,5.0);
glEnd();

glColor3f(0.74902,0.847059,0.847059); //top-mid
glBegin(GL_POLYGON);
glVertex2f(2.0,5.0);
glVertex2f(2.0,12.0);
glVertex2f(15.0,12.0);
glVertex2f(19.5,5.0);
glEnd();

glColor3f(0.137255,0.137255,0.556863); //ring
glBegin(GL_POLYGON);
glVertex2f(2.0,8.2);
glVertex2f(2.0,8.8);
glVertex2f(17.1,8.8);
glVertex2f(17.5,8.2);
glEnd();

glColor3f(0.90,0.91,0.98); //window
glBegin(GL_POLYGON);
glVertex2f(3.0,6.0);
glVertex2f(3.0,7.2);
glVertex2f(4.0,7.2);
glVertex2f(4.0,6.0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(4.7,6.0);
glVertex2f(4.7,7.2);
glVertex2f(5.7,7.2);
glVertex2f(5.7,6.0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(8.1,6.0);
glVertex2f(8.1,7.2);
glVertex2f(9.1,7.2);
glVertex2f(9.1,6.0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(9.8,6.0);
glVertex2f(9.8,7.2);
glVertex2f(10.8,7.2);
glVertex2f(10.8,6.0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(6.4,6.0);
glVertex2f(6.4,7.2);
glVertex2f(7.4,7.2);
glVertex2f(7.4,6.0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(11.5,6.0);
glVertex2f(11.5,7.2);
glVertex2f(12.5,7.2);
glVertex2f(12.5,6.0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(13.3,6.0);
glVertex2f(13.3,7.2);
glVertex2f(14.3,7.2);
glVertex2f(14.3,6.0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(15.1,6.0);
glVertex2f(15.1,7.2);
glVertex2f(16.1,7.2);
glVertex2f(16.1,6.0);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(16.9,6.0);
glVertex2f(16.9,7.2);
glVertex2f(17.9,7.2);
glVertex2f(17.9,6.0);
glEnd();




glColor3f(0.90,0.91,0.98); //window
glBegin(GL_POLYGON);
glVertex2f(3.0,9.8);
glVertex2f(3.0,11.0);
glVertex2f(4.0,11.0);
glVertex2f(4.0,9.8);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(4.7,9.8);
glVertex2f(4.7,11.0);
glVertex2f(5.7,11.0);
glVertex2f(5.7,9.8);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(8.1,9.8);
glVertex2f(8.1,11.0);
glVertex2f(9.1,11.0);
glVertex2f(9.1,9.8);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(9.8,9.8);
glVertex2f(9.8,11.0);
glVertex2f(10.8,11.0);
glVertex2f(10.8,9.8);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(6.4,9.8);
glVertex2f(6.4,11.0);
glVertex2f(7.4,11.0);
glVertex2f(7.4,9.8);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(11.5,9.8);
glVertex2f(11.5,11.0);
glVertex2f(12.5,11.0);
glVertex2f(12.5,9.8);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(13.3,9.8);
glVertex2f(13.3,11.0);
glVertex2f(14.3,11.0);
glVertex2f(14.3,9.8);
glEnd();

glColor3f(0.329412,0.329412,0.329412); //top-cover
glBegin(GL_POLYGON);
glVertex2f(1.5,12.0);
glVertex2f(1.5,12.5);
glVertex2f(16.0,12.5);
glVertex2f(16.0,12.0);
glEnd();

glColor3f(0.0,0.0,0.0); //chim
glBegin(GL_POLYGON);
glVertex2f(2.5,12.5);
glVertex2f(2.5,16.0);
glVertex2f(5.0,16.0);
glVertex2f(5.0,12.5);
glEnd();

glColor3f(1.0,0.25,0.0); //ring
glBegin(GL_POLYGON);
glVertex2f(2.5,12.5);
glVertex2f(2.5,13.5);
glVertex2f(5.0,13.5);
glVertex2f(5.0,12.5);
glEnd();

glColor3f(1.0,0.25,0.0); //ring
glBegin(GL_POLYGON);
glVertex2f(2.5,14.5);
glVertex2f(2.5,15.5);
glVertex2f(5.0,15.5);
glVertex2f(5.0,14.5);
glEnd();

glColor3f(0.0,0.0,0.0); //chim
glBegin(GL_POLYGON);
glVertex2f(6.0,12.5);
glVertex2f(6.0,16.0);
glVertex2f(8.5,16.0);
glVertex2f(8.5,12.5);
glEnd();

glColor3f(1.0,0.25,0.0); //ring
glBegin(GL_POLYGON);
glVertex2f(6.0,14.5);
glVertex2f(6.0,15.5);
glVertex2f(8.5,15.5);
glVertex2f(8.5,14.5);
glEnd();

glColor3f(1.0,0.25,0.0); //ring
glBegin(GL_POLYGON);
glVertex2f(6.0,12.5);
glVertex2f(6.0,13.5);
glVertex2f(8.5,13.5);
glVertex2f(8.5,12.5);
glEnd();
}

void rock()
{
//ext

        //ext
glPushMatrix();
glTranslated(450,50,0.0);
glScaled(10,10,0);
glColor3f(255,255,255);  //glColor3f(0.36,0.25,0.20);

if(c>0) //break the rock as c is inc in display 3
{
glPushMatrix();
glTranslated(0,x,0);
glPushMatrix();
glTranslated(7,2,0.0);
glRotated(-x,0,0,1);
glTranslated(-7,-2,0.0);

glBegin(GL_POLYGON);
glVertex2f(8.1,1);
glVertex2f(7.89,1.23);
glVertex2f(11.26,18);
glVertex2f(13.23,21.33);
glVertex2f(14.23,2.53);
glEnd();

glPopMatrix();
glPushMatrix();

glTranslated(12,3,0.0);
glRotated(x,0,0,1);
glTranslated(-12,-3,0.0);

glBegin(GL_POLYGON);
glVertex2f(11.1,3.5);
glVertex2f(13.2,18.7);
glVertex2f(16.4,18.5);
glVertex2f(18.12,3.65);
glVertex2f(19.21,1.25);
glEnd();

glPopMatrix();
glPopMatrix();
}
else  //static rock
{
glBegin(GL_POLYGON);
glVertex2f(8.1,1);
glVertex2f(7.89,1.23);
glVertex2f(11.26,18);
glVertex2f(13.23,21.33);
glVertex2f(14.23,2.53);
glEnd();
glBegin(GL_POLYGON);
glVertex2f(11.1,3.5);
glVertex2f(13.2,18.7);
glVertex2f(16.4,18.5);
glVertex2f(18.12,3.65);
glVertex2f(19.21,1.25);
glEnd();
}


glPopMatrix();

}

void background(){
glBegin(GL_POLYGON);
glColor3f(0.6980,0.8588,0.9137);
glVertex2f(0.0,0.0);
glVertex2f(1400.0,0.0);
glColor3f(0.0,0.4431,0.7098);
glVertex2f(1400.0,680.0);
glVertex2f(0.0,680.0);
glEnd();
}

void *currentfont;
void setFont(void *font)
{
currentfont=font;
}
void drawString(float x,float y,float z,char *string)
{
char *c;
glRasterPos3f(x,y,1);
 
for(c=string;*c!='\0';c++)
{
glutBitmapCharacter(currentfont,*c);
}
}

void firstpage(void)
{

    glLineWidth(1.0);
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.0, 0.0, 1.0);
    drawString(140.0, 720.0, 0.0, "MANGALORE INSTITUTE OF TECHNOLOGY & ENGINEERING");
    drawString(300.0, 680.0, 0.0, "MOODABIDRI, MANGALORE");
    setFont(GLUT_BITMAP_HELVETICA_18);
    drawString(240.0, 640.0, 0.0, "DEPARTMENT OF COMPUTER SCIENCE & ENGINEERING");
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.0, 0.0, 0.0);
    drawString(230.0, 560.0, 0.0, "COMPUTER GRAPHICS AND VISUALIZATION");
    glColor3f(0.7, 0.0, 0.0);
    drawString(380.0, 470.0, 0.0, "MINI PROJECT ON");
    drawString(410.0, 430.0, 0.0, "THE TITANIC");
    setFont(GLUT_BITMAP_HELVETICA_18);
    glColor3f(1.0, 0.0, 0.0);
    drawString(350.0, 330.0, 0.0, "Dhanush A                       4MT21CS046");
    drawString(350.0, 290.0, 0.0, "Dhanush S Shetty           4MT21CS047");
    drawString(350.0, 250.0, 0.0, "Karthik U Shettigar          4MT21CS064");
    glColor3f(0.0, 0.0, 0.0);
    drawString(390.0, 150.0, 0.0, "UNDER THE GUIDANCE OF");
    glColor3f(1.0, 0.0, 0.0);
    drawString(440.0, 130.0, 0.0, "SUNITHA N V");
    drawString(400.0, 110.0, 0.0, "ASSISTANT PROFESSOR");
    drawString(440.0, 90.0, 0.0, "DEPT OF CSE");

}

void thanku(){
glColor3f(1.0f, 1.0f, 1.0f); // Set the text color to white
setFont(GLUT_BITMAP_TIMES_ROMAN_24);
drawString(220,260.0,0.0,"THANK YOU");

}



void myinit()
{
glClearColor(0.63f, 0.94f, 1.0f,1.0f);
glColor3f(1.0,0.0,01.0);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,999.0,0.0,799.0);
}

void scene1()
{
myinit();
glPushMatrix();

glTranslatef(-100.0,-100.0,0.0);
//background();
glPopMatrix();
   //Plane_Body();

  glPushMatrix();
  glTranslatef(150.0,100.0,0.0);
firstpage();
glPopMatrix();

   
    glFlush();
glutSwapBuffers();
}

void scene6()
{
myinit();
glPushMatrix();
glTranslatef(-100.0,-100.0,0.0);
//background();
glPopMatrix();

glPushMatrix();
thanku();
glPopMatrix();
glFlush();
glutSwapBuffers();
}
 





void key(unsigned char key,int x,int y)
{

if(key=='1'){
slide=0;
}
else if(key=='2'){
a=0;
slide=1;
}
else if(key=='3'){
a=0,b=20;
slide=2;
}
else if(key=='4'){
a=0,b=20,c=10;
slide=3;
}
else if(key=='5'){
slide=4;
}
}




void display(){
if(slide==0)
{
scene1();
}
else if(slide==1)
{
display1();
}
else if(slide==2)
{
display2();
}
else if(slide==3)
{
display3();
}
else if(slide==4)
{
scene6();
}


}


int main(int argc, char* argv[])
{
int chs;
printf("Type Any Key and Hit Enter\n");
printf("\n******************************************************************\n\n");
scanf("%d",&chs);

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

glutInitWindowSize(1024.0,768.0);
glutInitWindowPosition(0,0);
glutCreateWindow("TITANIC");
glutFullScreen();
glutDisplayFunc(display);
myinit();
glutTimerFunc(50,update,0);
glutKeyboardFunc(key);
glutMainLoop();
return 0;
}

