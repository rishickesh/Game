#include<fstream.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
#include<bios.h>
#include "wave.cpp"
#include "ttt.cpp"
#include <bmplib.h>

/* global array,structures,variables and prototypes declaration*/

int	cx,cy,q,left;
class mouse
{
	public:
		union 	REGS  regs;
		int 	no_buttons;
		void 	show_mouse();
		void 	get_status();
		void 	hide_mouse();
		int 	left_click();
		int 	right_click();
		int 	mousehide();
		mouse()
		{
				regs.x.ax=0;
				int86(0x33,&regs,&regs);
			if(regs.x.ax==0xfff) no_buttons=regs.x.bx;

		}
};

void mouse::show_mouse()
{
	regs.x.ax=0x01;
	int86(0x33,&regs,&regs);
}
void mouse::hide_mouse()
{
	regs.x.ax=0x02;
	int86(0x33,&regs,&regs);
}
void mouse::get_status()
{
		regs.x.ax=3;
		int86(51,&regs,&regs);
	while(q!=1)
	{
		regs.x.ax=3;
		int86(51,&regs,&regs);
		q=regs.x.bx;
		cx=regs.x.cx;
		cy=regs.x.dx;
	}
		q=0;
}
int mouse::left_click()
{
	if(regs.x.bx == 1) return 1;
	else return 0;
}
int mouse::right_click()
{
	if(regs.x.bx == 2) return 1;
	else return 0;
}
void mainmenu();
void disp();
void circle()             //game play of circle
{
	int 	flag=1;
	mouse 	m;
		m.show_mouse();
		m.get_status();
		delay(200);
	while(flag==1)
	{
		wave();
		menu();
		int	 j=1;
		while(j==1)
		{
				m.get_status();
				delay(200);
				cx=m.regs.x.cx;
				cy=m.regs.x.dx;
			if(m.regs.x.bx)
			{
				if((cx>=70)&&(cx<=210)&&(cy>=150)&&(cy<=210))
				{
						cleardevice();
						load();
						cleardevice();
					int 	flag1=1;
					while(flag1==1)
					{
							h=game();
							bestscore(h);
							cleardevice();
							gameover(h);
						int 	a=1;
						while(a==1)
						{
								m.get_status();
								delay(200);
								cx=m.regs.x.cx;
								cy=m.regs.x.dx;
							if(m.regs.x.bx)
							{
								if((cx>=100)&&(cx<=300)&&(cy>=300)&&(cy<=350))
								{
										cleardevice();
										flag1=1;
										wave();
										a=-1;
								}
								else if((cx>=400)&&(cx<=600)&&(cy>=300)&&(cy<=350))
								{
										cleardevice();
										flag1=-1;
										a=-1;
										menu();
								}
							}
						}
					  }
				 }
				 else if((cx>=70)&&(cx<=210)&&(cy>=360)&&(cy<=420))
				 {
					cleardevice();
					mainmenu();
				 }
				else if((cx>=70)&&(cx<=210)&&(cy>=220)&&(cy<=280))
				{
						cleardevice();
						setbkcolor(0);
						settextstyle(0,0,3);
						outtextxy(530,430,"BACK");
						help();
					int 	b=1;
					while(b==1)
					{
							m.get_status();
							delay(200);
							cx=m.regs.x.cx;
							cy=m.regs.x.dx;
						if(m.regs.x.bx)
						{
							if((cx>=520)&&(cx<=620)&&(cy>=425)&&(cy<=465))
							{
								cleardevice();
								b=-1;
								menu();
							}
						}
					}
				}
				else if((cx>=60)&&(cx<=350)&&(cy>=290)&&(cy<=350))
				{
						cleardevice();
						setcolor(12);
						settextstyle(0,0,3);
						outtextxy(530,430,"BACK");
						setcolor(10);
						itoa(hi,sc,10);
						best();
						setcolor(14);
						outtextxy(200,190,sc);
				     int 	c=1;
					while(c==1)
					{
							m.get_status();
							delay(200);
							cx=m.regs.x.cx;
							cy=m.regs.x.dx;
						if(m.regs.x.bx)
						{
							if((cx>=520)&&(cx<=620)&&(cy>=425)&&(cy<=465))
							{
								cleardevice();
								c=-1;
								menu();
							}
						}
					}
				}
			}
		j=-1;
		}
	}
}
void ttt()                //game play tic tac toe
{
	int flag=1;
	mouse 	p;
	p.show_mouse();
	p.get_status();
	delay(200);
	while(flag==1)
	{
		 cleardevice();
		 menu1();
		 int 	j=1;
		 while(j==1)
		 {
			p.get_status();
			delay(200);
			cx=p.regs.x.cx;
			cy=p.regs.x.dx;
			if(p.regs.x.bx)
			{
				if((cx>=250)&&(cx<=380)&&(cy>=170)&&(cy<=220))
				{
					cleardevice();
					setbkcolor(0);
					play();
					cleardevice();
					j=-1;
				}
				else if((cx>=100)&&(cx<=220)&&(cy>=270)&&(cy<=320))
				{
					cleardevice();
					help1();
				int 	b=1;
					while(b==1)
					{
							p.get_status();
							delay(200);
							cx=p.regs.x.cx;
							cy=p.regs.x.dx;
						if(p.regs.x.bx)
						{
							if((cx>=520)&&(cx<=620)&&(cy>=425)&&(cy<=465))
							{
								cleardevice();
								b=-1;
								menu1();
							}
						}
					}
					j=-1;
				}
				else if((cx>=400)&&(cx<=500)&&(cy>=270)&&(cy<=320))
				{
					cleardevice();
					mainmenu();
				}
			}
		}
	}
}
void pro()                       //to display the production house
{
	setbkcolor(0);
	setcolor(13);
	settextstyle(0,0,4);
	outtextxy(100,200,"R.A.ONE games");
	settextstyle(0,0,3);
	setcolor(4);
	outtextxy(200,250,"presents");
}
void mainmenu()           //display main menu
{
	cleardevice();
	LoadBmp(400,200,"c:\\tc\\bin\\tt.bmp");
	LoadBmp(70,200,"c:\\tc\\bin\\circ.bmp");
	settextstyle(0,0,6);
	setcolor(7);
	outtextxy(120,20,"R.A.ONE");
	setcolor(9);
	outtextxy(200,90,"GAMES");
	setbkcolor(13);
	setcolor(4);
	rectangle(69,199,270,400);
	setcolor(2);
	rectangle(399,199,600,400);
	setcolor(4);
	settextstyle(0,0,2);
	outtextxy(120,410,"CIRCLE");
	setcolor(2);
	outtextxy(420,410,"TIC TAC TOE");
	settextstyle(0,0,2);
	setcolor(10);
	outtextxy(290,450,"EXIT");
	disp();
}
void disp()     //to give user control over main menu
{
	mouse   m;
		m.show_mouse();
		m.get_status();
		delay(200);
	int 	flag=1;
	while(flag==1)
	{
		m.get_status();
		delay(200);
		cx=m.regs.x.cx;
		cy=m.regs.x.dx;
		if(m.regs.x.bx)
		{
			if((cx>=70)&&(cx<=270)&&(cy>=200)&&(cy<=400))
			{
				cleardevice();
				circle();
			}
			else if((cx>=400)&&(cx<=600)&&(cy>=200)&&(cy<=400))
			{
				cleardevice();
				ttt();

		       }
		       else if((cx>=270)&&(cx<=350)&&(cy>=450)&&(cy<=500))
		       {
				exit(0);
		       }
	       }
	}
}
void main()
{
		clrscr();
	int 	gdriver = DETECT,gmode;
		initgraph(&gdriver,&gmode,"C:\\tc\\BGI");
		for(int i=0;i<100;i++)
		{
			pro();
			delay(50);
		}
		cleardevice();
		mainmenu();
		getch();
		closegraph();
}
