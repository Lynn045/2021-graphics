#include <GL/glut.h>///(0)使用GLUT外掛
float vx[2000],vy[2000];///準備一堆頂點，等一下要畫
#include <stdio.h>
int N=0; ///有N個頂點

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///清空
    glBegin(GL_LINE_LOOP);
    for(int i=0;i<N;i++)
    {
        glVertex2f(vx[i],vy[i]);
    }
    glEnd();
    glutSwapBuffers();///交換兩倍的Buffers
}

void motion(int x,int y)
{
    printf("%d %d\n",x,y);
    vx[N]=(x-150)/150.0;
    vy[N]=-(y-150)/150.0;
    N++;
    display();
}       ///減一半，再除一半，y加負號
int main(int argc, char**argv)///???以前是int main()
{
    glutInit(&argc,argv);///(1)GLUT初始設定
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///(2)顯示模式
    glutCreateWindow("08160816旋轉跳躍");///(3)開窗

    glutDisplayFunc(display);///(4)等一下要顯示的函式(display顯示函式)
    //glutMouseFunc(mouse);///TODO:(1)mouse滑鼠的程式
    glutMotionFunc(motion);///TODO:(1)mouse滑鼠的程式
    glutMainLoop();///(5)主要迴圈
}
