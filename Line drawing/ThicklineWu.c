//This program is only for slope<1
#include <stdio.h>
#include <math.h>
#include <graphics.h>

int main()
{
    int gd=DETECT,gm,i,j;
    initgraph(&gd,&gm,NULL);//initializing a window 
    int x1,x2,y1,y2,temp,xs;
    float delx,dely,dx,dy,m,ys,yinter,xsgap,xfgap,yf;
    float p[500],x[500],y[500];
	//asking the end user for certain parameters
    printf("Enter the starting position of x co-ordinate :: ");
    scanf("%d",&x1);
    printf("Enter the ending position of x co-ordinate :: ");
    scanf("%d",&x2);
    printf("Enter the starting position of y co-ordinate :: ");
    scanf("%d",&y1);
    printf("Enter the ending position of y co-ordinate :: ");
    scanf("%d",&y2);
	//we want to draw the line only from left to right
    if(x1>x2)
    {
        temp = x1;
        x1 = x2;
        x2 = temp;

        temp = y1;
        y1 = y2;
        y2 = temp;
    }

    delx = x2-x1;
    dely = y2-y1;
	//calculating slope
    m = dely/delx;

    if (m < 1)
    {
        xs = x1 + 0.5;
        ys = y1 + m * (xs - x1);
        yinter = ys + m;
        xsgap = xs + 0.5 - x1;

        int ysf = ys;
        float col = (ysf+1-ys)*xsgap;
        putpixel(xs,ysf,col);
        col = (ys - ysf) * xsgap;//xsgap is gap between pixels from the line's mid part
        putpixel(xs,ysf+1,col);//col deciding the intensity 

        int xf = x2+0.5;
        yf = y2 + m * (xf - x2);
        int x2f = x2+0.5;
        xfgap = x2 + 0.5 - x2f;
        int yff = yf;
        col = (yff + 1 - yf)*xfgap;
        putpixel(xf,yff,col);
        col = (yf - yff)*xfgap;
        putpixel(xf,yff+1,col);

        int k;
        int yinterf;
        for(k=x1+1;k<=x2-1;k++)
        {
            yinterf = yinter;
            col = yinterf+1-yinter;
            putpixel(k,yinterf,col);
            col = yinter - yinterf;
            putpixel(k,yinterf+1,col);
            yinter = yinter + m;

        }


    }





    delay(10000);//To show the designed graphic for a certain period of time
    cleardevice();//To clear the device
    closegraph();//To close the initiated graphic system
}
