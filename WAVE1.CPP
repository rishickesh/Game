#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
float 	h;
void 	menu()                  //display menu
{
		settextstyle(0,0,6);
		setcolor(15);
		outtextxy(180,40,"CIRCLE");
		settextstyle(0,0,4);
		setbkcolor(12);
		setcolor(5);
		outtextxy(80,170,"PLAY");
		setcolor(9);
		outtextxy(80,240,"HELP");
		setcolor(14);
		outtextxy(80,380,"EXIT");
		setcolor(10);
		outtextxy(80,310,"BESTSCORE");

}
void 	load()                                //display loading screen
{
		settextstyle(4,0,2);
		setbkcolor(15);
	int 	i=100,xi=100,x=0;
	char 	s[20];
		rectangle(100,300,500,330);
		setcolor(8);
		outtextxy(100,340,"LOADING");
		while(i<=500)
		{
			outtextxy(120,200,"DO NOT PRESS ANY KEY");
			setcolor(10);
			line(xi,300,xi,330);
			rectangle(100,300,500,330);
			setcolor(8);
			outtextxy(100,340,"LOADING");
			setcolor(4);
			rectangle(100,300,i,330);
			setfillstyle(1,4);
			floodfill((100+i)/2,310,4);
			itoa(x,s,10);
			if(x<10)
			{
				s[1]='%';
				s[2]='\0';
			}
			else if(x<100)
			{
				s[2]='%';
				s[3]='\0';
			}
			else
			{
				s[3]='%';
				s[4]='\0';
			}
			setcolor(8);
			outtextxy(400,340,s);
			xi++;
			i++;
			if(i%4==0) x++;
			if(i%10==0) delay(40);
			else if(i==250) delay(50);
			else delay(60);
			if(i%2==0) cleardevice();
		}
}
void 	load1()
{
		settextstyle(4,0,2);
		setbkcolor(15);
	int 	i=100,xi=100;
	char 	s[20];
		rectangle(100,300,500,330);
		setcolor(8);
		outtextxy(100,340,"LOADING");
		while(i<=500)
		{
			setcolor(4);
			line(xi,300,xi,330);
			setcolor(10);
			rectangle(100,300,500,330);
			setcolor(8);
			outtextxy(100,340,"LOADING");
			xi++;
			i++;
			if(i%10==0) delay(10);
			else if(i==250) delay(30);
			else delay(5);
		}
}
void help()                    //to display help page
{
		setcolor(15);
		settextstyle(0,0,5);
		outtextxy(250,20,"HELP");
		setcolor(4);
		settextstyle(0,0,1);
		outtextxy(5,140,"THERE WILL BE A CIRCLE ON A WAVE WHICH IS MOVING.YOUR AIM IS TO MAKE");
		outtextxy(5,170,"SURE THAT THE CIRCLE'S TOP AND BOTTOM MOST PART DO NOT TOUCH THE WAVE.");
		outtextxy(5,200,"USE UP ARROW KEY TO MOVE THE CIRCLE UP.");

}
void best()                                 //to display best score page
{
		setbkcolor(8);
		settextstyle(0,0,5);
		outtextxy(150,30,"BESTSCORE");
		setcolor(2);
		settextstyle(0,0,3);
		outtextxy(50,150,"BEST SCORE IS:");
}
/*void main()
{
	int gdriver = DETECT,gmode;
	int x,y,i,a=0;
	float h;
	initgraph(&gdriver,&gmode,"C:\\tc\\BGI");
	load();
	getch();
	closegraph();
}*/