#include <GL/glut.h>///(0)使用GLUT外掛
float vx[2000],vy[2000];///準備一堆頂點，等一下要畫
#include <stdio.h>
int N=0; ///有N個頂點
float angle=0;
void hand()
{
    glPushMatrix();///備份矩陣
        glScalef(0.5,0.1,0.1);///調成細長
        glutSolidCube(1);///方塊
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///清空
    glPushMatrix();///備份矩陣
        glTranslatef(-0.25,0,0);
        glRotatef(angle,0,0,1);///旋轉
        glTranslatef(-0.25,0,0);
        hand();///手臂
        glPushMatrix();///備份矩陣
            glTranslatef(-0.25,0,0);
            glRotatef(angle,0,0,1);///旋轉
            glTranslatef(-0.25,0,0);
            hand();///手肘
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///備份矩陣
        glTranslatef(0.25,0,0);
        glRotatef(-angle,0,0,1);///旋轉
        glTranslatef(0.25,0,0);
        hand();
        glPushMatrix();///備份矩陣
            glTranslatef(+0.25,0,0);
            glRotatef(-angle,0,0,1);///旋轉
            glTranslatef(+0.25,0,0);
            hand();
        glPopMatrix();
    glPopMatrix();

    glutSwapBuffers();///交換兩倍的Buffers
    angle++;
}
void motion(int x,int y)
{
    angle++;
    display();
}

int main(int argc, char**argv)///???以前是int main()
{
    glutInit(&argc,argv);///(1)GLUT初始設定
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);///(2)顯示模式
    glutCreateWindow("08160816旋轉跳躍");///(3)開窗
    glutIdleFunc(display);///idle很閒的時候，一直做
    glutDisplayFunc(display);///(4)等一下要顯示的函式(display顯示函式)

    glutMotionFunc(motion);///TODO:(1)mouse滑鼠的程式
    glutMainLoop();///(5)主要迴圈
}
