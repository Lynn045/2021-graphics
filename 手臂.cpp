#include <GL/glut.h>///(0)�ϥ�GLUT�~��
float vx[2000],vy[2000];///�ǳƤ@�ﳻ�I�A���@�U�n�e
#include <stdio.h>
int N=0; ///��N�ӳ��I
float angle=0;
void hand()
{
    glPushMatrix();///�ƥ��x�}
        glScalef(0.5,0.1,0.1);///�զ��Ӫ�
        glutSolidCube(1);///���
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///�M��
    glPushMatrix();///�ƥ��x�}
        glTranslatef(-0.25,0,0);
        glRotatef(angle,0,0,1);///����
        glTranslatef(-0.25,0,0);
        hand();///���u
        glPushMatrix();///�ƥ��x�}
            glTranslatef(-0.25,0,0);
            glRotatef(angle,0,0,1);///����
            glTranslatef(-0.25,0,0);
            hand();///��y
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///�ƥ��x�}
        glTranslatef(0.25,0,0);
        glRotatef(-angle,0,0,1);///����
        glTranslatef(0.25,0,0);
        hand();
        glPushMatrix();///�ƥ��x�}
            glTranslatef(+0.25,0,0);
            glRotatef(-angle,0,0,1);///����
            glTranslatef(+0.25,0,0);
            hand();
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();///�洫�⭿��Buffers
    angle++;
}
void motion(int x,int y)
{
    angle++;
    display();
}

int main(int argc, char**argv)///???�H�e�Oint main()
{
    glutInit(&argc,argv);///(1)GLUT��l�]�w
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///(2)��ܼҦ�
    glutCreateWindow("08160816������D");///(3)�}��
    glutIdleFunc(display);///idle�ܶ����ɭԡA�@����
    glutDisplayFunc(display);///(4)���@�U�n��ܪ��禡(display��ܨ禡)

    glutMotionFunc(motion);///TODO:(1)mouse�ƹ����{��
    glutMainLoop();///(5)�D�n�j��
}
