#include <GL/glut.h>///(0)�ϥ�GLUT�~��
float vx[2000],vy[2000];///�ǳƤ@�ﳻ�I�A���@�U�n�e
#include <stdio.h>
int N=0; ///��N�ӳ��I

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///�M��
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<N;i++)
    {
        glVertex2f(vx[i],vy[i]);
    }
    glEnd();
    glutSwapBuffers();///�洫�⭿��Buffers
}

void motion(int x,int y)
{
    printf("%d %d\n",x,y);
    vx[N]=(x-150)/150.0;
    vy[N]=-(y-150)/150.0;
    N++;
    display();
}       ///��@�b�A�A���@�b�Ay�[�t��
int main(int argc, char**argv)///???�H�e�Oint main()
{
    glutInit(&argc,argv);///(1)GLUT��l�]�w
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///(2)��ܼҦ�
    glutCreateWindow("08160816������D");///(3)�}��

    glutDisplayFunc(display);///(4)���@�U�n��ܪ��禡(display��ܨ禡)
    //glutMouseFunc(mouse);///TODO:(1)mouse�ƹ����{��
    glutMotionFunc(motion);///TODO:(1)mouse�ƹ����{��
    glutMainLoop();///(5)�D�n�j��
}
