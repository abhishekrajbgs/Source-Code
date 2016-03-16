#include <stdio.h>
#include <math.h>
#include <graphics.h>

int main()
{
    int gd=DETECT,gm,i,j;
    initgraph(&gd,&gm,NULL);
    int x1,x2,y1,y2,steps;
    float delx,dely,dx,dy,tx1,ty1;

    printf("Enter the starting position of x co-ordinate :: ");
    scanf("%d",&x1);
    printf("Enter the ending position of x co-ordinate :: ");
    scanf("%d",&x2);
    printf("Enter the starting position of y co-ordinate :: ");
    scanf("%d",&y1);
    printf("Enter the ending position of y co-ordinate :: ");
    scanf("%d",&y2);

    delx = x2-x1;
    dely = y2-y1;

    if(delx < 0)
    {
        tx1 = -1 * delx;
    }
    else
        tx1 = delx;
    if(dely < 0)
    {
        ty1 = -1*dely;
    }
    else
        ty1 = dely;

    printf("tx1= %f,ty1 = %f\n",tx1,ty1);
    if(tx1 > ty1)
        steps = tx1;
    else
        steps = ty1;

    dx = delx/steps;
    dy = dely/steps;
    //printf("steps = %d,dx = %f,dy = %f\n",steps,dx,dy);
    putpixel(x1,y1,WHITE);
    int k;
    float x[500],y[500];
    x[0] = x1;
    y[0] = y1;

    for(k=1;k<=steps;k++)
    {
        x[k] = x[k-1]+dx;
        y[k] = y[k-1]+dy;
        putpixel(x[k-1],y[k-1],WHITE);
        printf("\n(%f,%f)",x[k],y[k]);
    }

    delay(30000);
    cleardevice();
    closegraph();


}

