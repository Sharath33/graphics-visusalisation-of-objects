#include<GL/glut.h>
#include<stdlib.h>
#include<stdio.h>
int cubeflag=0;
int flag=0;
int revolution;
int ringflag;
float rev[][3] = {{4,0,0}, {0,4.5,0}, {-2.8868,2.8868,2.8868}, {3.1755,3.1755,3.1755}, {6,0,0}, {0,6.5,0}, {-4.0415,4.0415,4.0415}, {4.3301,4.3301,4.3301}};
float rottor[][3] = {{1,0,0}, {0,1,0}, {-1,1,0}, {1,1,0}, {1,0,0}, {0,1,0}, {-1,1,0}, {1,1,0}};
float torsize[] = {4, 4.5, 5, 5.5, 6, 6.5, 7, 7.5};
float rot[][3] = {{0,1,0},{1,0,0},{1,1,0},{-1,1,0},{0,1,0},{1,0,0},{1,1,0},{-1,1,0}};
float axisa[] = {0.3,0.6,0.9,1.2,1.5,1.8,2.1,2.4};
float axisb[] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
GLfloat color[][3]={{0.0,0.5,0.0},{1.0,0.0,0.0},{1.0,1.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{1.0,0.0,1.0},{0.5,0.0,1.0},{0.0,1.0,1.0}};
int m=2;
int objrev=1;

int primitive=1;
int sub1,sub2,sub3,sub4,sub5,sub6,sub7,sub8,sub9,sub10,usub1,usub2,usub3,usub4,usub5,usub6,usub7,usub8;

GLfloat vertices[][3]={{-2.0,-2.0,-2.0},{2.0,-2.0,-2.0},{2.0,2.0,-2.0},{-2.0,2.0,-2.0},{-2.0,-2.0,2.0},{2.0,-2.0,2.0},{2.0,2.0,2.0},{-2.0,2.0,2.0}};

GLfloat normals[][3]={{-2.0,-2.0,-2.0},{2.0,-2.0,-2.0},{2.0,2.0,-2.0},{-2.0,2.0,-2.0},{-2.0,-2.0,2.0},
{2.0,-2.0,2.0},{2.0,2.0,2.0},{-2.0,2.0,2.0}};

GLfloat colors[][3]={{1.0,1.0,1.0},{1.0,0.0,0.0},{1.0,1.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0},{1.0,0.0,1.0},{1.0,1.0,1.0},{0.0,1.0,1.0}};

float rotX=0.0,rotY=0.0,rotZ=0.0;

float rotX1=0.0,rotY1=0.0,rotZ1=0.0,
rotX2=0.0,rotY2=0.0,rotZ2=0.0,
rotX3=0.0,rotY3=0.0,rotZ3=0.0,
rotX4=0.0,rotY4=0.0,rotZ4=0.0,
rotX5=0.0,rotY5=0.0,rotZ5=0.0,
rotX6=0.0,rotY6=0.0,rotZ6=0.0,
rotX7=0.0,rotY7=0.0,rotZ7=0.0,
rotX8=0.0,rotY8=0.0,rotZ8=0.0;

float array[16]={0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0,1.1,1.2,1.3,1.4,1.5,1.6};
float scale=0.1;
int scalemin=1;
int i=0;

typedef float point[3];
point v[]={{0.0,0.0,1.0},{0.0,1.5,-1.0},{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0}};

int n=2;

void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN && flag==0)
		flag=1;
}

void triangle(point a,point b,point c)
{
	glBegin(GL_POLYGON);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
}

void divide_triangle(point a,point b,point c,int m)
{
	point v3,v1,v2;
	int j;
	if(m>0)
	{
		for(j=0;j<3;j++) v1[j]=(a[j]+b[j])/2;
		for(j=0;j<3;j++) v2[j]=(a[j]+c[j])/2;
		for(j=0;j<3;j++) v3[j]=(b[j]+c[j])/2;

		divide_triangle(a,v1,v2,m-1);
		divide_triangle(b,v1,v3,m-1);
		divide_triangle(c,v2,v3,m-1);
	}
	else 
		triangle(a,b,c);
}

void tetra(int m)
{
	glColor3f(1.0,0.0,0.0);
	divide_triangle(v[0],v[1],v[2],m);
	glColor3f(0.0,1.0,0.0);
	divide_triangle(v[1],v[2],v[3],m);
	glColor3f(0.0,0.0,1.0);
	divide_triangle(v[2],v[3],v[0],m);
	glColor3f(1.0,1.0,0.0);
	divide_triangle(v[0],v[1],v[3],m);
}

void polygon(int a,int b,int c,int d)
{
	if(cubeflag)
		glBegin(GL_LINE_LOOP);
	else
		glBegin(GL_POLYGON);
		
	   glColor3fv(colors[a]);
	   glNormal3fv(normals[a]);
	   glVertex3fv(vertices[a]);

	   glColor3fv(colors[b]);
	   glNormal3fv(normals[b]);
	   glVertex3fv(vertices[b]);

	   glColor3fv(colors[c]);
	   glNormal3fv(normals[c]);
	   glVertex3fv(vertices[c]);

	   glColor3fv(colors[d]);
	   glNormal3fv(normals[d]);
	   glVertex3fv(vertices[d]);
	glEnd();
}

void colorcube(void)
{
	polygon(0,3,2,1);
	polygon(2,3,7,6);
	polygon(0,4,7,3);
	polygon(1,2,6,5);
	polygon(4,5,6,7);
	polygon(0,1,5,4);
}

static GLfloat theta[]= {0.0,0.0,0.0};
static GLint axis=2;

void revobj(float rev[],int i)
{
	glColor3f(0.5,0.5,0.5);
	if(ringflag)
	{
		glPushMatrix();
		glRotatef(90,rottor[i][0],rottor[i][1],rottor[i][2]);
		glutSolidTorus(0.03,torsize[i] + 0.03,10,100);
		glPopMatrix();
	}
	glColor3fv(color[i]);
	glTranslatef(rev[0],rev[1],rev[2]);
	if(objrev==1)
		glutWireSphere(0.4,10,10);
	else if(objrev==2)
		glutWireCube(0.7);
	else if(objrev==3)
	{
		glScalef(0.5,0.5,0.5);
		glutWireOctahedron();
	}
}

void centrecube()
{
	int i;
	glLineWidth(1.0);
	for(i = 0;i < m;i++)
	{
		glPushMatrix();
			glRotatef((axisb[i] += axisa[i]),rot[i][0], rot[i][1], rot[i][2]);		
			revobj(rev[i],i);
		glPopMatrix();
		if(axisb[i] >= 360) axisb[i] -= 360.0;	
	}
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

      	glRotatef(theta[0],1.0,0.0,0.0);
	glRotatef(theta[1],0.0,1.0,0.0);
	glRotatef(theta[2],0.0,0.0,1.0);
    	colorcube();
    	
    	if(revolution)
    	{
    		glRotatef(0.0,1.0,0.0,0.0);
		glRotatef(0.0,0.0,1.0,0.0);
		glRotatef(0.0,0.0,0.0,1.0);		
		centrecube();
	}
	
	glColor3f(1.0,1.0,0.0);
	glPushMatrix();
		glTranslatef(2.0,2.0,2.0);
		glRotatef(rotY, 0.0,1.0,0.0);
        	glRotatef(rotX, 1.0,0.0,0.0);
		glRotatef(rotZ,0.0,0.0,1.0);
		if(primitive==1)
			glutWireTorus(0.15,1.0,12,12);
		else if(primitive==2)
			glutWireSphere(1.0,40,40);
		else if(primitive==3)
			glutWireCone(1.0,1.0,15,15);
		else if(primitive==4)
			glutWireCube(1.0);
		else
		{
			glScalef(1.0,1.0,1.0);
			glutWireOctahedron();
		}
	glPopMatrix();

	glColor3f(0.0,1.0,1.0);
	glPushMatrix();
		glTranslatef(-2.0,-2.0,-2.0);
	 	glRotatef(rotY, 0.0,1.0,0.0);
        	glRotatef(rotX, 1.0,0.0,0.0);
	    	glRotatef(rotZ,0.0,0.0,1.0);
		if(primitive==1)
			glutWireTorus(0.15,1.0,12,12);
		else if(primitive==2)
			glutWireSphere(1.0,40,40);
		else if(primitive==3)
			glutWireCone(1.0,1.0,15,15);
		else if(primitive==4)
			glutWireCube(1.0);
		else
		{
			glScalef(1.0,1.0,1.0);
			glutWireOctahedron();
		}
	glPopMatrix();

	glColor3f(0.0,0.5,0.0);
	glPushMatrix();
		glTranslatef(2.0,2.0,-2.0);
		glRotatef(rotY, 0.0,1.0,0.0);
        	glRotatef(rotX, 1.0,0.0,0.0);
	    	glRotatef(rotZ,0.0,0.0,1.0);
		if(primitive==1)
			glutWireTorus(0.15,1.0,12,12);
		else if(primitive==2)
			glutWireSphere(1.0,40,40);
		else if(primitive==3)
			glutWireCone(1.0,1.0,15,15);
		else if(primitive==4)
			glutWireCube(1.0);
		else
		{
			glScalef(1.0,1.0,1.0);
			glutWireOctahedron();
		}
	glPopMatrix();

	glColor3f(1.0,0.0,0.0);
	glPushMatrix();
		glTranslatef(2.0,-2.0,2.0);
		glRotatef(rotY, 0.0,1.0,0.0);
        	glRotatef(rotX, 1.0,0.0,0.0);
	    	glRotatef(rotZ,0.0,0.0,1.0);
		if(primitive==1)
			glutWireTorus(0.15,1.0,12,12);
		else if(primitive==2)
			glutWireSphere(1.0,40,40);
		else if(primitive==3)
			glutWireCone(1.0,1.0,15,15);
		else if(primitive==4)
			glutWireCube(1.0);
		else
		{
			glScalef(1.0,1.0,1.0);
			glutWireOctahedron();
		}
	glPopMatrix();

	glColor3f(0.5,0.0,1.0);
	glPushMatrix();
	   	glTranslatef(2.0,-2.0,-2.0);
	   	glRotatef(rotY, 0.0,1.0,0.0);
       		glRotatef(rotX, 1.0,0.0,0.0);
	   	glRotatef(rotZ,0.0,0.0,1.0);
 		if(primitive==1)
			glutWireTorus(0.15,1.0,12,12);
		else if(primitive==2)
			glutWireSphere(1.0,40,40);
		else if(primitive==3)
			glutWireCone(1.0,1.0,15,15);
		else if(primitive==4)
			glutWireCube(1.0);
		else
		{
			glScalef(1.0,1.0,1.0);
			glutWireOctahedron();
		}
	glPopMatrix();

	glColor3f(0.0,0.0,1.0);
	glPushMatrix();
		glTranslatef(-2.0,2.0,2.0);
		glRotatef(rotY, 0.0,1.0,0.0);
        	glRotatef(rotX,1.0,0.0,0.0);
	    	glRotatef(rotZ,0.0,0.0,1.0);
		if(primitive==1)
			glutWireTorus(0.15,1.0,12,12);
		else if(primitive==2)
			glutWireSphere(1.0,40,40);
		else if(primitive==3)
			glutWireCone(1.0,1.0,15,15);
		else if(primitive==4)
			glutWireCube(1.0);
		else
		{
			glScalef(1.0,1.0,1.0);
			glutWireOctahedron();
		}
	glPopMatrix();

	glColor3f(1.0,0.0,1.0);
	glPushMatrix();
		glTranslatef(-2.0,2.0,-2.0);
	   	glRotatef(rotY, 0.0,1.0,0.0);
        	glRotatef(rotX, 1.0,0.0,0.0);
		glRotatef(rotZ,0.0,0.0,1.0);
		if(primitive==1)
			glutWireTorus(0.15,1.0,12,12);
		else if(primitive==2)
			glutWireSphere(1.0,40,40);
		else if(primitive==3)
			glutWireCone(1.0,1.0,15,15);
		else if(primitive==4)
			glutWireCube(1.0);
		else
		{
			glScalef(1.0,1.0,1.0);
			glutWireOctahedron();
		}
	glPopMatrix();

	glColor3f(0.0,1.0,0.0);
	glPushMatrix();
		glTranslatef(-2.0,-2.0,2.0);
		glRotatef(rotY, 0.0,1.0,0.0);
        	glRotatef(rotX, 1.0,0.0,0.0);
	    	glRotatef(rotZ,0.0,0.0,1.0);
		if(primitive==1)
			glutWireTorus(0.15,1.0,12,12);
		else if(primitive==2)
			glutWireSphere(1.0,40,40);
		else if(primitive==3)
			glutWireCone(1.0,1.0,15,15);
		else if(primitive==4)
			glutWireCube(1.0);
		else
		{
			glScalef(1.0,1.0,1.0);
			glutWireOctahedron();
		}
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.0,2.0,0.0);
		glRotatef(0.0,0.0,1.0,0.0);
        	glRotatef(-90.0,1.0,0.0,0.0);
		glRotatef(0.0,0.0,0.0,1.0);
		glScalef(scale,scale,scale);
		tetra(n);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0,0.0,-2.0);
	 	glRotatef(0.0, 0.0,1.0,0.0);
        	glRotatef(180.0, 1.0,0.0,0.0);
	    	glRotatef(180.0,0.0,0.0,1.0);
		glScalef(scale,scale,scale);
		tetra(n);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(2.0,0.0,0.0);
		glRotatef(90.0, 0.0,1.0,0.0);
        	glRotatef(0.0, 1.0,0.0,0.0);
	    	glRotatef(0.0,0.0,0.0,1.0);
		glScalef(scale,scale,scale);
		tetra(n);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0,-2.0,0.0);
		glRotatef(0.0, 0.0,1.0,0.0);
        	glRotatef(90.0, 1.0,0.0,0.0);
	    	glRotatef(0.0,0.0,0.0,1.0);
		glScalef(scale,scale,scale);
		tetra(n);
	glPopMatrix();

	glPushMatrix();
	   	glTranslatef(0.0,0.0,2.0);
	   	glRotatef(0.0, 0.0,1.0,0.0);
       		glRotatef(0.0, 1.0,0.0,0.0);
	   	glRotatef(0.0,0.0,0.0,1.0);
 		glScalef(scale,scale,scale);
		tetra(n);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-2.0,0.0,0.0);
		glRotatef(-90.0, 0.0,1.0,0.0);
        	glRotatef(0.0,1.0,0.0,0.0);
	    	glRotatef(0.0,0.0,0.0,1.0);
	    	glScalef(scale,scale,scale);
		tetra(n);
	glPopMatrix();

	glFlush();
	glutSwapBuffers();
}

void display1(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

      	glRotatef(theta[0],1.0,0.0,0.0);
	glRotatef(theta[1],0.0,1.0,0.0);
	glRotatef(theta[2],0.0,0.0,1.0);
    	colorcube();
	
	if(revolution)
    	{
    		glRotatef(0.0,1.0,0.0,0.0);
		glRotatef(0.0,0.0,1.0,0.0);
		glRotatef(0.0,0.0,0.0,1.0);		
		centrecube();
	}
	
	glColor3f(1.0,1.0,0.0);
	glPushMatrix();
		glTranslatef(2.0,2.0,2.0);
		glRotatef(rotY1, 0.0,1.0,0.0);
        	glRotatef(rotX1, 1.0,0.0,0.0);
		glRotatef(rotZ1,0.0,0.0,1.0);
		if(primitive==1)
			glutWireTorus(0.15,1.0,12,12);
		else if(primitive==2)
			glutWireSphere(1.0,40,40);
		else if(primitive==3)
			glutWireCone(1.0,1.0,15,15);
		else if(primitive==4)
			glutWireCube(1.0);
		else
		{
			glScalef(1.0,1.0,1.0);
			glutWireOctahedron();
		}
	glPopMatrix();

	glColor3f(0.0,1.0,1.0);
	glPushMatrix();
		glTranslatef(-2.0,-2.0,-2.0);
	 	glRotatef(rotY2, 0.0,1.0,0.0);
        	glRotatef(rotX2, 1.0,0.0,0.0);
	    	glRotatef(rotZ2,0.0,0.0,1.0);
		if(primitive==1)
			glutWireTorus(0.15,1.0,12,12);
		else if(primitive==2)
			glutWireSphere(1.0,40,40);
		else if(primitive==3)
			glutWireCone(1.0,1.0,15,15);
		else if(primitive==4)
			glutWireCube(1.0);
		else
		{
			glScalef(1.0,1.0,1.0);
			glutWireOctahedron();
		}
	glPopMatrix();

	glColor3f(0.0,0.5,0.0);
	glPushMatrix();
		glTranslatef(2.0,2.0,-2.0);
		glRotatef(rotY3, 0.0,1.0,0.0);
        	glRotatef(rotX3, 1.0,0.0,0.0);
	    	glRotatef(rotZ3,0.0,0.0,1.0);
		if(primitive==1)
			glutWireTorus(0.15,1.0,12,12);
		else if(primitive==2)
			glutWireSphere(1.0,40,40);
		else if(primitive==3)
			glutWireCone(1.0,1.0,15,15);
		else if(primitive==4)
			glutWireCube(1.0);
		else
		{
			glScalef(1.0,1.0,1.0);
			glutWireOctahedron();
		}
	glPopMatrix();

	glColor3f(1.0,0.0,0.0);
	glPushMatrix();
		glTranslatef(2.0,-2.0,2.0);
		glRotatef(rotY4, 0.0,1.0,0.0);
        	glRotatef(rotX4, 1.0,0.0,0.0);
	    	glRotatef(rotZ4,0.0,0.0,1.0);
		if(primitive==1)
			glutWireTorus(0.15,1.0,12,12);
		else if(primitive==2)
			glutWireSphere(1.0,40,40);
		else if(primitive==3)
			glutWireCone(1.0,1.0,15,15);
		else if(primitive==4)
			glutWireCube(1.0);
		else
		{
			glScalef(1.0,1.0,1.0);
			glutWireOctahedron();
		}
	glPopMatrix();

	glColor3f(0.5,0.0,1.0);
	glPushMatrix();
	   	glTranslatef(2.0,-2.0,-2.0);
	   	glRotatef(rotY5, 0.0,1.0,0.0);
       		glRotatef(rotX5, 1.0,0.0,0.0);
	   	glRotatef(rotZ5,0.0,0.0,1.0);
 		if(primitive==1)
			glutWireTorus(0.15,1.0,12,12);
		else if(primitive==2)
			glutWireSphere(1.0,40,40);
		else if(primitive==3)
			glutWireCone(1.0,1.0,15,15);
		else if(primitive==4)
			glutWireCube(1.0);
		else
		{
			glScalef(1.0,1.0,1.0);
			glutWireOctahedron();
		}
	glPopMatrix();

	glColor3f(0.0,0.0,1.0);
	glPushMatrix();
		glTranslatef(-2.0,2.0,2.0);
		glRotatef(rotY6, 0.0,1.0,0.0);
        	glRotatef(rotX6,1.0,0.0,0.0);
	    	glRotatef(rotZ6,0.0,0.0,1.0);
		if(primitive==1)
			glutWireTorus(0.15,1.0,12,12);
		else if(primitive==2)
			glutWireSphere(1.0,40,40);
		else if(primitive==3)
			glutWireCone(1.0,1.0,15,15);
		else if(primitive==4)
			glutWireCube(1.0);
		else
		{
			glScalef(1.0,1.0,1.0);
			glutWireOctahedron();
		}
	glPopMatrix();

	glColor3f(1.0,0.0,1.0);
	glPushMatrix();
		glTranslatef(-2.0,2.0,-2.0);
	   	glRotatef(rotY7, 0.0,1.0,0.0);
        	glRotatef(rotX7, 1.0,0.0,0.0);
		glRotatef(rotZ7,0.0,0.0,1.0);
		if(primitive==1)
			glutWireTorus(0.15,1.0,12,12);
		else if(primitive==2)
			glutWireSphere(1.0,40,40);
		else if(primitive==3)
			glutWireCone(1.0,1.0,15,15);
		else if(primitive==4)
			glutWireCube(1.0);
		else
		{
			glScalef(1.0,1.0,1.0);
			glutWireOctahedron();
		}
	glPopMatrix();

	glColor3f(0.0,1.0,0.0);
	glPushMatrix();
		glTranslatef(-2.0,-2.0,2.0);
		glRotatef(rotY8, 0.0,1.0,0.0);
        	glRotatef(rotX8, 1.0,0.0,0.0);
	    	glRotatef(rotZ8,0.0,0.0,1.0);
		if(primitive==1)
			glutWireTorus(0.15,1.0,12,12);
		else if(primitive==2)
			glutWireSphere(1.0,40,40);
		else if(primitive==3)
			glutWireCone(1.0,1.0,15,15);
		else if(primitive==4)
			glutWireCube(1.0);
		else
		{
			glScalef(1.0,1.0,1.0);
			glutWireOctahedron();
		}
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.0,2.0,0.0);
		glRotatef(0.0,0.0,1.0,0.0);
        	glRotatef(-90.0,1.0,0.0,0.0);
		glRotatef(0.0,0.0,0.0,1.0);
		glScalef(scale,scale,scale);
		tetra(n);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0,0.0,-2.0);
	 	glRotatef(0.0, 0.0,1.0,0.0);
        	glRotatef(180.0, 1.0,0.0,0.0);
	    	glRotatef(180.0,0.0,0.0,1.0);
		glScalef(scale,scale,scale);
		tetra(n);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(2.0,0.0,0.0);
		glRotatef(90.0, 0.0,1.0,0.0);
        	glRotatef(0.0, 1.0,0.0,0.0);
	    	glRotatef(0.0,0.0,0.0,1.0);
		glScalef(scale,scale,scale);
		tetra(n);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0,-2.0,0.0);
		glRotatef(0.0, 0.0,1.0,0.0);
        	glRotatef(90.0, 1.0,0.0,0.0);
	    	glRotatef(0.0,0.0,0.0,1.0);
		glScalef(scale,scale,scale);
		tetra(n);
	glPopMatrix();

	glPushMatrix();
	   	glTranslatef(0.0,0.0,2.0);
	   	glRotatef(0.0, 0.0,1.0,0.0);
       		glRotatef(0.0, 1.0,0.0,0.0);
	   	glRotatef(0.0,0.0,0.0,1.0);
 		glScalef(scale,scale,scale);
		tetra(n);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-2.0,0.0,0.0);
		glRotatef(-90.0, 0.0,1.0,0.0);
        	glRotatef(0.0,1.0,0.0,0.0);
	    	glRotatef(0.0,0.0,0.0,1.0);
	    	glScalef(scale,scale,scale);
		tetra(n);
	glPopMatrix();
	
	glFlush();
	glutSwapBuffers();
}

void scaletetra()
{
	if(scalemin==1)
	{
		scale=array[i];
		i++;
		if(i==15)
			scalemin=0;			
	}
	else
	{
		scale=array[i];
		i--;
		if(i==0)
			scalemin=1;

	}
	//sleep(1);
	glutPostRedisplay();
}

void spinscale()
{
	theta[axis]+=1.0;
	if(theta[axis]>360.0)theta[axis]-=360.0;
	scaletetra();
	glutPostRedisplay();
}

void spinCube()
{
	theta[axis]+=0.1;
	if(theta[axis]>360.0)theta[axis]-=360.0;
	glutPostRedisplay();
}

void myReshape(int w,int h)
{
	glClearColor(0.0,0.0,0.0,1.0);
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(flag==0)
		glOrtho(0,1000,0,1000,-1,1);
	else
	{
		if(w<=h)
			glOrtho(-8.0,8.0,-8.0*(GLfloat)h/(GLfloat)w,8.0*(GLfloat)h/(GLfloat)w,-8.0,16.0);
		else
			glOrtho(-8.0*(GLfloat)w/(GLfloat)h,8.0*(GLfloat)w/(GLfloat)h,-8.0,8.0,-8.0,16.0);
	}
	glMatrixMode(GL_MODELVIEW);
}

void smallx()
{
	 rotX+=5.0;
	 rotY=0.0;
	 rotZ=0.0;
    glutPostRedisplay();
}

void smally()
{
	rotY+=5.0;
	rotX=0.0;
	rotZ=0.0;
	glutPostRedisplay();
}

void smallz()
{
	rotZ+=5.0;
	rotX=0.0;
	rotY=0.0;
	glutPostRedisplay();
}

void smallx1()
{
	 rotX1+=5.0;
	 rotY1=0.0;
	 rotZ1=0.0;
    glutPostRedisplay();
}

void smally1()
{
	rotY1+=5.0;
	rotX1=0.0;
	rotZ1=0.0;
	glutPostRedisplay();
}

void smallz1()
{
	rotZ1+=5.0;
	rotX1=0.0;
	rotY1=0.0;
	glutPostRedisplay();
}

void smallx2()
{
	 rotX2+=5.0;
	 rotY2=0.0;
	 rotZ2=0.0;
    glutPostRedisplay();
}

void smally2()
{
	rotY2+=5.0;
	rotX2=0.0;
	rotZ2=0.0;
	glutPostRedisplay();
}

void smallz2()
{
	rotZ2+=5.0;
	rotX2=0.0;
	rotY2=0.0;
	glutPostRedisplay();
}

void smallx3()
{
	 rotX3+=5.0;
	 rotY3=0.0;
	 rotZ3=0.0;
    glutPostRedisplay();
}

void smally3()
{
	rotY3+=5.0;
	rotX3=0.0;
	rotZ3=0.0;
	glutPostRedisplay();
}

void smallz3()
{
	rotZ3+=5.0;
	rotX3=0.0;
	rotY3=0.0;
	glutPostRedisplay();
}

void smallx4()
{
	 rotX4+=5.0;
	 rotY4=0.0;
	 rotZ4=0.0;
    glutPostRedisplay();
}

void smally4()
{
	rotY4+=5.0;
	rotX4=0.0;
	rotZ4=0.0;
	glutPostRedisplay();
}

void smallz4()
{
	rotZ4+=5.0;
	rotX4=0.0;
	rotY4=0.0;
	glutPostRedisplay();
}

void smallx5()
{
	 rotX5+=5.0;
	 rotY5=0.0;
	 rotZ5=0.0;
    glutPostRedisplay();
}

void smally5()
{
	rotY5+=5.0;
	rotX5=0.0;
	rotZ5=0.0;
	glutPostRedisplay();
}

void smallz5()
{
	rotZ5+=5.0;
	rotX5=0.0;
	rotY5=0.0;
	glutPostRedisplay();
}

void smallx6()
{
	 rotX6+=5.0;
	 rotY6=0.0;
	 rotZ6=0.0;
    glutPostRedisplay();
}

void smally6()
{
	rotY6+=5.0;
	rotX6=0.0;
	rotZ6=0.0;
	glutPostRedisplay();
}

void smallz6()
{
	rotZ6+=5.0;
	rotX6=0.0;
	rotY6=0.0;
	glutPostRedisplay();
}

void smallx7()
{
	 rotX7+=5.0;
	 rotY7=0.0;
	 rotZ7=0.0;
    glutPostRedisplay();
}

void smally7()
{
	rotY7+=5.0;
	rotX7=0.0;
	rotZ7=0.0;
	glutPostRedisplay();
}

void smallz7()
{
	rotZ7+=5.0;
	rotX7=0.0;
	rotY7=0.0;
	glutPostRedisplay();
}

void smallx8()
{
	 rotX8+=5.0;
	 rotY8=0.0;
	 rotZ8=0.0;
    glutPostRedisplay();
}

void smally8()
{
	rotY8+=5.0;
	rotX8=0.0;
	rotZ8=0.0;
	glutPostRedisplay();
}

void smallz8()
{
	rotZ8+=5.0;
	rotX8=0.0;
	rotY8=0.0;
	glutPostRedisplay();
}

void spincube1()
{
	 rotX+=5.0;
	 	theta[axis]+=0.1;
	if(theta[axis]>360.0)theta[axis]-=360.0;
	glutPostRedisplay();
}

void spincube2()
{
	 rotY+=5.0;
	 	theta[axis]+=0.1;
	if(theta[axis]>360.0)theta[axis]-=360.0;

	glutPostRedisplay();
}

void spincube3()
{
	 rotZ+=5.0;
	 	theta[axis]+=0.1;
	if(theta[axis]>360.0)theta[axis]-=360.0;
	glutPostRedisplay();
}

void keys(unsigned char key,int x,int y)
{
	if(key == '1')
		objrev=1;
	if(key == '2')
		objrev=2;
	if(key == '3')
		objrev=3;
}

void main_menu(int id)				//Main Menu definition.
{
	glutDisplayFunc(display);

	switch(id)
	{
		 case 1:glutIdleFunc(spinCube);
		 	break;
		 case 2:glutIdleFunc(scaletetra);
			break;
		 case 3:glutIdleFunc(spinscale);
			break;
		 case 4:glutIdleFunc(NULL);
		 	break;
		 case 5:exit(0);
		 	break;

	}
}

void sub_menu1(int id)					//back Menu definition.
{
	switch(id)
	{
		case 1:axis=0;
			break;
		case 2:axis=1;
			break;
		case 3:axis=2;
			break;

	}
}

void sub_menu2(int id)					//back Menu definition.
{

	switch(id)
	{
		case 1:
		    glutIdleFunc(smallx);
			break;
		case 2:
			glutIdleFunc(smally);
			break;
		case 3:
			glutIdleFunc(smallz);
			break;

	}
}

void sub_menu3(int id)					//track Menu definition.
{

	switch(id)
	{
	    case 1:
			axis=0;
			glutIdleFunc(spincube1);
			break;
		case 2:
			axis=1;
			glutIdleFunc(spincube2);
			break;
		case 3:
			axis=2;
			glutIdleFunc(spincube3);
			break;
	}
}

void sub_menu4(int id)					//Sub Menu definition.
{
	glutDisplayFunc(display);
	switch(id)
	{
		case 1: primitive=1;
			break;
		case 2: primitive=2;
			break;
		case 3: primitive=3;
			break;
		case 4: primitive=4;
			break;
		case 5: primitive=5;
			break;
	}
}
void sub_menu5(int id)					//Sub Menu definition.
{
	switch(id)
	{
		case 1:revolution=1;
			glutIdleFunc(display);
			break;
		case 2:revolution=0;
			glutIdleFunc(display);
			break;
	}
}

void sub_menu6(int id)					//Sub Menu definition.
{
	glutDisplayFunc(display);
	switch(id)
	{
		case 1: ringflag=1;
			break;
		case 2: ringflag=0;
			break;
	}
}

void sub_menu7(int id)					//Sub Menu definition.
{
	glutDisplayFunc(display);
	switch(id)
	{
		case 1: m=1;
			break;
		case 2: m=2;
			break;
		case 3: m=3;
			break;
		case 4: m=4;
			break;
		case 5: m=5;
			break;
		case 6: m=6;
			break;
		case 7: m=7;
			break;
		case 8: m=8;
			break;
	}
}

void sub_menu8(int id)					//track Menu definition.
{

	switch(id)
	{
	    	case 1:glClearColor(1.0,1.0,1.0,1.0);
			break;
		case 2:glClearColor( 0.91,0.76,0.65,1.0);
			break;
		case 3:glClearColor(0.439216,0.858824,0.576471,1.0);
			break;
		case 4:glClearColor(0.678431,0.917647,0.917647,1.0);
			break;
		case 5:glClearColor(0.9,0.6,0.6,1);
			break;
		case 6:glClearColor(0.0,0.0,0.0,0.0);
			break;
	}
}

void sub_menu9(int id)					//Sub Menu definition.
{
	switch(id)
	{
		case 1:cubeflag=1;
			glutDisplayFunc(display);
			break;
		case 2:cubeflag=0;
			glutDisplayFunc(display);
			break;
	}
}

void under_sub_menu1(int id)					
{
	glutDisplayFunc(display1);

	switch(id)
	{
		case 1:
		    glutIdleFunc(smallx1);
			break;
		case 2:
			glutIdleFunc(smally1);
			break;
		case 3:
			glutIdleFunc(smallz1);
			break;

	}
}

void under_sub_menu2(int id)					
{
    glutDisplayFunc(display1);

	switch(id)
	{
		case 1:
		    glutIdleFunc(smallx2);
			break;
		case 2:
			glutIdleFunc(smally2);
			break;
		case 3:
			glutIdleFunc(smallz2);
			break;

	}
}

void under_sub_menu3(int id)					
{
	glutDisplayFunc(display1);

	switch(id)
	{
		case 1:
		    glutIdleFunc(smallx3);
			break;
		case 2:
			glutIdleFunc(smally3);
			break;
		case 3:
			glutIdleFunc(smallz3);
			break;

	}
}

void under_sub_menu4(int id)					
{
	glutDisplayFunc(display1);

	switch(id)
	{
		case 1:
		    glutIdleFunc(smallx4);
			break;
		case 2:
			glutIdleFunc(smally4);
			break;
		case 3:
			glutIdleFunc(smallz4);
			break;

	}
}

void under_sub_menu5(int id)					
{
	glutDisplayFunc(display1);

	switch(id)
	{
		case 1:
		    glutIdleFunc(smallx5);
			break;
		case 2:
			glutIdleFunc(smally5);
			break;
		case 3:
			glutIdleFunc(smallz5);
			break;

	}
}

void under_sub_menu6(int id)					
{
	glutDisplayFunc(display1);

	switch(id)
	{
		case 1:
		    glutIdleFunc(smallx6);
			break;
		case 2:
			glutIdleFunc(smally6);
			break;
		case 3:
			glutIdleFunc(smallz6);
			break;

	}
}

void under_sub_menu7(int id)					
{
	glutDisplayFunc(display1);

	switch(id)
	{
		case 1:
		    glutIdleFunc(smallx7);
			break;
		case 2:
			glutIdleFunc(smally7);
			break;
		case 3:
			glutIdleFunc(smallz7);
			break;

	}
}

void under_sub_menu8(int id)					
{
	glutDisplayFunc(display1);

	switch(id)
	{
		case 1:
		    glutIdleFunc(smallx8);
			break;
		case 2:
			glutIdleFunc(smally8);
			break;
		case 3:
			glutIdleFunc(smallz8);
			break;

	}
}

void strokeString(float x,float y,float sx,float sy,char *string,int width)
{
	char *c;
	glLineWidth(width);
	glPushMatrix();
	glTranslatef(x,y,0);
	glScalef(sx,sy,0);
	for (c=string; *c != '\0'; c++) 
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
	}
	glPopMatrix();
}

void display3()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glClearColor(0.439216,0.858824,0.576471,1.0);
	glColor3f(0.6,0.6,0);
	strokeString(270,870,0.18,0.18,"BANGALORE INSTITUTE OF TECHNOLOGY",2);
	glColor3f(1,0,0);
	strokeString(130,750,0.3,0.3,"DEPARTMENT OF COMPUTER SCIENCE",4);
	strokeString(330,670,0.3,0.3,"AND ENGINEERING",4);
	strokeString(200,500,0.3,0.3,"AN OPENGL MINI PROJECT ON",2);
	glColor3f(0,0.5,1);
	strokeString(50,420,0.43,0.4,"Transformation of objects around",6);
	strokeString(320,350,0.43,0.4,"a color cube",6);
	glColor3f(0,0.5,0);
	strokeString(150,280,0.23,0.23,"Press (Left Click and Maximize the window) to",2);
	strokeString(350,240,0.23,0.23,"start the simulation",2);
	glColor3f(0,0.5,1);
	strokeString(50,120,0.18,0.18,"LAKSHMIKANTH C K",2);
	strokeString(50,80,0.18,0.18,"1BI14CS069",2);
	strokeString(750,120,0.2,0.2,"Banushree.K.J",2);
	strokeString(750,80,0.2,0.2,"Gunavathi.H.S",2);
	strokeString(750,40,0.2,0.2,"Shruthibha.A",2);
	glColor3f(1,0,0);
	strokeString(50,160,0.15,0.15,"By:",2);
	strokeString(750,160,0.15,0.15,"Under the guidance of ",2);
	glPopMatrix();	
	glutSwapBuffers();
}

void display2()
{
	if(flag==0)
		display3();
	else if(flag==1)
	{
		display();
		glEnable(GL_DEPTH_TEST);
	}
	glutPostRedisplay();
}

int main(int argc,char **argv)
{
	printf("Choose Revolution objects by pressing following on Keyboard \n");
	printf("1.Sphere\n2.Cube\n3.Octahedron\n");
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	
	glutInitWindowSize(1000,650);
	glutCreateWindow("Rotating a color cube");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display2);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keys);
	
	sub1=glutCreateMenu(sub_menu1);

	glutAddMenuEntry("X rotation",1);
	glutAddMenuEntry("Y rotation",2);
	glutAddMenuEntry("Z rotation",3);
	
	sub2=glutCreateMenu(sub_menu2);

	glutAddMenuEntry("X rotation",1);
	glutAddMenuEntry("Y rotation",2);
	glutAddMenuEntry("Z rotation",3);
	
	sub3=glutCreateMenu(sub_menu3);

	glutAddMenuEntry("X rotation",1);
	glutAddMenuEntry("Y rotation",2);
	glutAddMenuEntry("Z rotation",3);
	
	sub4=glutCreateMenu(sub_menu4);

	glutAddMenuEntry("Torus",1);
	glutAddMenuEntry("Sphere",2);
	glutAddMenuEntry("Cone",3);
	glutAddMenuEntry("Cube",4);
	glutAddMenuEntry("Octahedron",5);
	
	sub5=glutCreateMenu(sub_menu5);

	glutAddMenuEntry("Yes",1);
	glutAddMenuEntry("No",2);
	
	sub6=glutCreateMenu(sub_menu6);

	glutAddMenuEntry("On",1);
	glutAddMenuEntry("Off",2);
	
	sub7=glutCreateMenu(sub_menu7);

	glutAddMenuEntry("One",1);
	glutAddMenuEntry("Two",2);
	glutAddMenuEntry("Three",3);
	glutAddMenuEntry("Four",4);
	glutAddMenuEntry("Five",5);
	glutAddMenuEntry("Six",6);
	glutAddMenuEntry("Seven",7);
	glutAddMenuEntry("Eight",8);
	
	sub8=glutCreateMenu(sub_menu8);

	glutAddMenuEntry("White",1);
	glutAddMenuEntry("Light wood",2);
	glutAddMenuEntry("Aquamarine",3);
	glutAddMenuEntry("Turquoise",4);
	glutAddMenuEntry("Salmon",5);
	glutAddMenuEntry("Black",6);
	
	sub9=glutCreateMenu(sub_menu9);

	glutAddMenuEntry("Wire Cube",1);
	glutAddMenuEntry("Solid Cube",2);

	usub1=glutCreateMenu(under_sub_menu1);

	glutAddMenuEntry("X axis",1);
	glutAddMenuEntry("Y axis",2);
	glutAddMenuEntry("Z axis",3);

	usub2=glutCreateMenu(under_sub_menu2);

	glutAddMenuEntry("X axis",1);
	glutAddMenuEntry("Y axis",2);
	glutAddMenuEntry("Z axis",3);

	usub3=glutCreateMenu(under_sub_menu3);

	glutAddMenuEntry("X axis",1);
	glutAddMenuEntry("Y axis",2);
	glutAddMenuEntry("Z axis",3);

	usub4=glutCreateMenu(under_sub_menu4);

	glutAddMenuEntry("X axis",1);
	glutAddMenuEntry("Y axis",2);
	glutAddMenuEntry("Z axis",3);

	usub5=glutCreateMenu(under_sub_menu5);

	glutAddMenuEntry("X axis",1);
	glutAddMenuEntry("Y axis",2);
	glutAddMenuEntry("Z axis",3);

	usub6=glutCreateMenu(under_sub_menu6);

	glutAddMenuEntry("X axis",1);
	glutAddMenuEntry("Y axis",2);
	glutAddMenuEntry("Z axis",3);

	usub7=glutCreateMenu(under_sub_menu7);

	glutAddMenuEntry("X axis",1);
	glutAddMenuEntry("Y axis",2);
	glutAddMenuEntry("Z axis",3);

	usub8=glutCreateMenu(under_sub_menu8);

	glutAddMenuEntry("X axis",1);
	glutAddMenuEntry("Y axis",2);
	glutAddMenuEntry("Z axis",3);
	
	sub10=glutCreateMenu(NULL);

   	glutAddSubMenu("Yellow Obj",usub1);
	glutAddSubMenu("Sky Blue Obj",usub2);
	glutAddSubMenu("Dark Green Obj",usub3);
	glutAddSubMenu("Red Obj",usub4);
    	glutAddSubMenu("Violet Obj",usub5);
	glutAddSubMenu("Blue Obj",usub6);
	glutAddSubMenu("Pink Obj",usub7);
	glutAddSubMenu("Parrot Green Obj",usub8);
    
	glutCreateMenu(main_menu);
	glutAddMenuEntry("Rotation",1);
	glutAddSubMenu("Cube Rotation Axis",sub1);
    	glutAddSubMenu("Corner Objects Rotation",sub2);
    	glutAddSubMenu("Cube & Corner Objects Rotation",sub3);
    	glutAddSubMenu("Individual Corner Object Rotation",sub10);
    	glutAddSubMenu("Choose Corner Object",sub4);
    	glutAddMenuEntry("Scaling",2);
    	glutAddMenuEntry("Rotate & Scale",3);
	glutAddSubMenu("Revolution",sub5);
 	glutAddSubMenu("Rings of Revolution",sub6);
 	glutAddSubMenu("No. of Revolving Objects",sub7);
 	glutAddSubMenu("Background Color",sub8);
 	glutAddSubMenu("Cube Type",sub9);   
	glutAddMenuEntry("Stop Motion",4);
	glutAddMenuEntry("Quit",5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	//glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}
