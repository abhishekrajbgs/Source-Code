

#include<stdio.h>
#include<graphics.h>
#include<math.h>

int main()
{
    int gd=DETECT,gm;

    DWORD dwWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD dwHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(dwWidth,dwHeight);//initializing a window of given size
    int x0=dwWidth/2;
    int y0=dwHeight/2;
    int i,j;
    int x1,y1,x2,y2;
    int xxdel;
	//to put coordinate axis according to real coordinate system
	 for(i=0; i<dwHeight; i++)
        putpixel(x0,i,RED);

    for(j=0; j<dwWidth; j++)
        putpixel(j,y0,RED);
    printf("Center of the screen is :\n");
    printf("x0=%d\n",x0);
    printf("y0=%d\n",y0);
    printf("enter x-coordinate of starting point \n");
    scanf("%d",&x1);
    printf("enter y-coordinate of starting point\n");
    scanf("%d",&y1);
    printf("enter x-coordinate of ending point \n");
    scanf("%d",&x2);
    printf("enter y-coordinate of ending point\n");
    scanf("%d",&y2);
	
   

    int y3,k;
	//we want to draw the line only from  left to right direction
    if(x1>x2){
            int temp1,temp2;
            temp1=x1;
            x1=x2;
            x2=temp1;
            temp2=y1;
            y1=y2;
            y2=temp2;
        }
    float xdel=x2-x1;
    float ydel=y2-y1;
	//shift user defined point according to our system
    x1=x0+x1;
    x2=x0+x2;
    y1=y0-y1;
    y2=y0-y2;


    int p[500],x[500],y[500];
    x[0]=x1;
    y[0]=y1;
	//calculating slope
    float m=(ydel/xdel);
    putpixel(x1,y1,WHITE);

    if( m <=1 && m>0)
    {
	//decision parameter-initially
        p[0]=(-0.5*xdel-ydel);

        for(k=0; k<xdel; k++)
        {
		//according to decision parameter setting up pixels
            if(p[k]<0)
            {
                y3=y[k]+1-y[0];//this is just to visualize output as real coordinate system
                putpixel(x[k]+1,y[k]+1-2*y3,WHITE);
                x[k+1]=x[k]+1;
                y[k+1]=y[k]+1;
                p[k+1]=p[k]+xdel-ydel;
            }
            else
            {
                y3=y[k]-y[0];//this is just to visualize output as real coordinate system
                putpixel(x[k]+1,y[k]-2*y3,WHITE);
                x[k+1]=x[k]+1;
                y[k+1]=y[k];
                p[k+1]=p[k]-ydel;
            }

        }


    }


    else if(m>=-1 && m<=0)
    {
	//decision parameter-initially
        p[0]=(-0.5*xdel-ydel);
        for(k=0; k<xdel; k++)
        {
            if(p[k]<0)
            {
			//according to decision parameter setting up pixels
                y3=y[k]-y[0];//this is just to visualize output as real coordinate system
                putpixel(x[k]+1,y[k]-2*y3,WHITE);
                x[k+1]=x[k]+1;
                y[k+1]=y[k];
                p[k+1]=p[k]-ydel;
            }
            else
            {
                y3=y[k]-1-y[0];//this is just to visualize output as real coordinate system
                putpixel(x[k]+1,y[k]-1-2*y3,WHITE);
                x[k+1]=x[k]+1;
                y[k+1]=y[k]-1;
                p[k+1]=p[k]-xdel-ydel;
            }

        }
    }
    else if(m>1)
    {
	//decision parameter-initially
        p[0]=(xdel-(ydel*0.5));

        for(k=0; k<ydel; k++)
        {
            if(p[k]<0)
            {
			//according to decision parameter setting up pixels
                y3=y[k]+1-y[0];//this is just to visualize output as real coordinate system
                putpixel(x[k],y[k]+1-2*y3,WHITE);
                x[k+1]=x[k];
                y[k+1]=y[k]+1;
                p[k+1]=p[k]+xdel;
            }
            else
            {
                y3=y[k]+1-y[0];//this is just to visualize output as real coordinate system
                putpixel(x[k]+1,y[k]+1-2*y3,WHITE);
                x[k+1]=x[k]+1;
                y[k+1]=y[k]+1;
                p[k+1]=p[k]+xdel-ydel;
            }

        }
    }
    else if(m<-1)
    {
	//decision parameter-initially
        p[0]=(-xdel-(ydel*0.5));

        for(k=0; k<(-1)*ydel; k++)
        {
            if(p[k]<0)
            {
			//according to decision parameter setting up pixels
                y3=y[k]-1-y[0];//this is just to visualize output as real coordinate system
                putpixel(x[k]+1,y[k]-1-2*y3,WHITE);
                x[k+1]=x[k]+1;
                y[k+1]=y[k]-1;
                p[k+1]=p[k]-xdel-ydel;
            }
            else
            {
                y3=y[k]-1-y[0];//this is just to visualize output as real coordinate system
                putpixel(x[k],y[k]-1-2*y3,WHITE);
                x[k+1]=x[k];
                y[k+1]=y[k]-1;
                p[k+1]=p[k]-xdel;
            }

        }
    }
    delay(10000);//to maintain delay in showing output
    cleardevice();//to clear the output device
    closegraph();//to close the initiated graph
}


