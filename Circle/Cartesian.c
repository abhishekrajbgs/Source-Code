#include <stdio.h>
#include <math.h>
#include <graphics.h>


int main()
{
    int gd=DETECT,gm,i,j;
    //initgraph(&gd,&gm,NULL);
    DWORD dwWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD dwHeight = GetSystemMetrics(SM_CYSCREEN);
    //int dwWidth = 300;
    //int dwHeight = 400;
    initwindow(dwWidth,dwHeight);
    printf("width = %d\n",dwWidth);
    printf("height = %d\n",dwHeight);

    int xc,yc,r,x,x1,x2,y1,y2;
    float ys,yr;
    printf("Enter the x co-ordinate of circle :: ");
    scanf("%d",&xc);
    printf("Enter the y co-ordinate of circle :: ");
    scanf("%d",&yc);
    printf("Enter the radius of circle :: ");
    scanf("%d",&r);
    x1 = dwWidth/2;
    y1 = dwHeight/2;
    xc = x1 + xc;
    yc = y1 - yc;

    for(i=0;i<=dwHeight;i++)
        putpixel(x1,i,RED);
    for(i=0;i<=dwWidth;i++)
        putpixel(i,y1,RED);

    x1 = xc - r + 0.5;
    y1 = yc + 0.5;
    putpixel(x1,y1,WHITE);
    x2 = xc + r + 0.5;
    y2 = yc + 0.5;
    putpixel(x2,y2,WHITE);

    for(x = x1;x<=x2;x++)
    {
        ys = r*r - (x - xc)*(x - xc);
        yr = yc + sqrt(ys);
        y1 = yr+0.5;
        putpixel(x,y1,WHITE);
        yr = yc - sqrt(ys);
        y1 = yr+0.5;
        putpixel(x,y1,WHITE);
    }


    delay(30000);
    cleardevice();
    closegraph();
}

