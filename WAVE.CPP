#include<fstream.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<math.h>
#include<bios.h>
#include "wave1.cpp"


/*global array and structure declaration*/

int 	b[10000],c[10000],hi=0,scr[1000];
char 	sc[20];
void 	wave()        //to produce the coordinates for the wave of given amplitude and frequency
{
		randomize();
	int 	y,i=0,j=0,a=0,amp=10;
	float 	f;
	double 	x=0;
	int 	fre;
		fre=20+random(20);
		while(x<=10000)
		{
			y=sin((x+a)/fre)*amp+230;
			b[i]=x;
			c[j]=y;
			i++;
			j++;
			x++;
			a++;
		}
}
int   game()             //game play for the following game
{
	char 	s[20];
	int 	i=0,j=0,a=0,l,m=30,n=0,k=0,x,flag=1;
		l=215;
	float 	h=0;
	int 	e=0;
		setbkcolor(15);
		settextstyle(4,0,2);
		while (flag==1)
		{
			    n=0;
			if  (h==0)
			{
				while(!kbhit())
				{

					setbkcolor(13);
					setcolor(4);
					settextstyle(0,0,2);
					outtextxy(200,240,"PRESS ENTER KEY");
					delay(10);
				}

			}
			cleardevice();
			if	((int(h)%10==0)&&(e!=5)&&(e!=4)) setbkcolor(e++);   //to produce colourful background
			else if((e==5)||(e==4)) e++;
			else if(e>=15) e=0;
				i=0,j=0;
			if(kbhit())
			{
				char 	ch=getch();
				if(ch==72)                         //to move the circle up
				{
					setcolor(4);
					l-=8;
					ellipse(50,l,0,360,5,m);
				}
			}
			itoa(k,s,10);
			while(n<=2)
			{
				setcolor(4);                   //to display the current score on the screen
				settextstyle(1,0,3);
				outtextxy(530,30,"SCORE:");
				outtextxy(550,40,s);
				n++;
			}
			setcolor(4);
			ellipse(50,l,0,360,5,m);
			while(i<=10000)
			{
				setcolor(0);
				putpixel(b[i]-a,c[j],4);          //to display the wave on the screen
				i++;
				j++;
			  if((b[i]-a>=45)&&(b[i]-a<=55))
			   {
				if((c[j]==l+m)||(c[j]==l-m))            //to check whether the following circle had touched the wave or not!!
				{
						cleardevice();
						setbkcolor(12);
						settextstyle(4,0,2);
						outtextxy(270,240,"GAMEOVER");
						flag=-1;
						return  k;

				}

			  }
		       }
			a++;
			l++;
		int 	c=h;
		if(c%10==0) k++;
			h++;
			delay(2);
		if((c%20==0)&&(m>=10)) m--;
       }
       return k;
}
void gameover(int h)        //to display gameover page
{
		cleardevice();
		setbkcolor(7);
		setcolor(15);
		settextstyle(0,0,3);
		outtextxy(180,100,"GAME OVER!!");
		outtextxy(180,140,"your score is:");
	char 	s[20];
		itoa(h,s,10);
		outtextxy(250,180,s);
		setcolor(10);
		rectangle(100,300,300,350);
		setfillstyle(1,10);
		floodfill(180,325,10);
		settextstyle(0,0,3);
		setcolor(4);
		outtextxy(140,315,"RETRY");
		setcolor(10);
		rectangle(400,300,600,350);
		setfillstyle(1,10);
		floodfill(480,325,10);
		settextstyle(0,0,3);
		setcolor(4);
		outtextxy(450,315,"MENU");
}
void sort_arr(int i)
{
	for(int j=0;j<i-1;j++)
	{
		for(int k=0;k<i-j-1;k++)
		{
			if(scr[k]>scr[k+1])
			{
				int 	temp=scr[k];
					scr[k]=scr[k+1];
					scr[k+1]=temp;
			}
		}
	}
}
void sort_score(char fn[20])
{
	ifstream f(fn,ios::binary);
	int 	 i=0,n;
	while(f.read((char*)&n,sizeof(n)))
	{
		scr[i]=n;
		i++;
	}
	f.close();
	sort_arr(i);
	ofstream g(fn,ios::binary);
	int j=0;
	while(j<i)
	{
		g.write((char*)&scr[j],sizeof(scr[j]));
		j++;
	}
	g.close();
}
void bestscore(int h)                        //to store the best score in a file
{
	char fn[20]="ab.doc";
	ifstream f(fn,ios::binary);
	     while(f.read((char*)&hi,sizeof(hi)));
		 f.close();
	sort_score(fn);
	ofstream g(fn,ios::binary|ios::app);
	if(h>hi)
	{
		hi=h;
		g.write((char*)&hi,sizeof(hi));
	}
	g.close();
}
