#include <iostream.h>
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

/*global variables declaration*/

int 	ch;
int	grid[9];

void menu1()             //menu for the game
{
	cleardevice();
	setbkcolor(7);
	setcolor(9);
	settextstyle(0,0,5);
	outtextxy(120,50,"TIC TAC TOE");
	setcolor(6);
	settextstyle(0,0,4);
	outtextxy(250,200,"PLAY");
	setcolor(12);
	outtextxy(100,300,"HELP");
	setcolor(14);
	outtextxy(400,300,"EXIT");
}
void help1()                    //to display help page
{
		setbkcolor(0);
		setcolor(15);
		settextstyle(0,0,5);
		outtextxy(250,20,"HELP");
		setcolor(4);
		settextstyle(0,0,1);
		outtextxy(5,140,"THERE WILL BE TWO PLAYERS TAKING PART IN THIS GAME.");
		outtextxy(5,170,"ONE WILL REPRESENT THE SYMBOL O AND OTHER WITH X.");
		outtextxy(5,200,"YOU HAVE TO PLACE YOUR SYMBOL IN ANY GRID OF YOUR CHOICE,");
		outtextxy(5,230,"PROVIDED THAT THE GRID IS NOT USED.IF ANY PLAYER PLACES");
		outtextxy(5,260,"HIS SYMBOL THRICE HORIZONTALLY,VERTICALLY,DIAGONALLY HE");
		outtextxy(5,290,"IS ADJUDGED THE WINNNER OR ELSE THE GAME ENDS IN DRAW.");
		settextstyle(0,0,3);
		setcolor(6);
		outtextxy(530,430,"BACK");
}
void board()                      //draw the board
{
	rectangle(150,50,570,470);
	line(290,50,290,470);
	line(430,50,430,470);
	line(150,190,570,190);
	line(150,330,570,330);

}
void odraw(int i,int j)                   //draw a 0
{
	setcolor(BLUE);
	circle(i,j,70);
}
void xdraw(int i,int j)                  //draw a X
{
	setcolor(RED);
	line(i-70,j-70,i+70,j+70);
	line(i+70,j-70,i-70,j+70);
}
void drawshape(int s,int block)           //draw where user points to
{
	switch(block)
	{
		case 1:if(s==1)
			{
				xdraw(220,120);
			}
			else
			{
				odraw(220,120);
			}break;
		case 2:if(s==1)
			{
				xdraw(360,120);
			}
			else
			{
				odraw(360,120);
			}break;
		case 3:if(s==1)
			{
				xdraw(500,120);
			}
			else
			{
				odraw(500,120);
			}break;
		case 4:if(s==1)
			{
				xdraw(220,260);
			}
			else
			{
				odraw(220,260);
			}break;
		case 5:if(s==1)
			{
				xdraw(360,260);
			}
			else
			{
				odraw(360,260);
			}break;
		case 6:if(s==1)
			{
				xdraw(500,260);
			}
			else
			{
				odraw(500,260);
			}break;
		case 7:if(s==1)
			{
				xdraw(220,400);
			}
			else
			{
				odraw(220,400);
			}break;
		case 8:if(s==1)
			{
				xdraw(360,400);
			}
			else
			{
				odraw(360,400);
			}break;
		case 9:if(s==1)
			{
				xdraw(500,400);
			}
			else
			{
				odraw(500,400);
			}break;
	}
}
int checkwinner()          //check whether game is over or not
{
	if((grid[0]==1)&&(grid[1]==1)&&(grid[2]==1)||
	   (grid[3]==1)&&(grid[4]==1)&&(grid[5]==1)||
	   (grid[6]==1)&&(grid[7]==1)&&(grid[8]==1)||
	   (grid[0]==1)&&(grid[3]==1)&&(grid[6]==1)||
	   (grid[1]==1)&&(grid[4]==1)&&(grid[7]==1)||
	   (grid[2]==1)&&(grid[5]==1)&&(grid[8]==1)||
	   (grid[0]==1)&&(grid[4]==1)&&(grid[8]==1)||
	   (grid[2]==1)&&(grid[4]==1)&&(grid[6]==1)||
	   (grid[0]==0)&&(grid[1]==0)&&(grid[2]==0)||
	   (grid[3]==0)&&(grid[4]==0)&&(grid[5]==0)||
	   (grid[6]==0)&&(grid[7]==0)&&(grid[8]==0)||
	   (grid[0]==0)&&(grid[3]==0)&&(grid[6]==0)||
	   (grid[1]==0)&&(grid[4]==0)&&(grid[7]==0)||
	   (grid[2]==0)&&(grid[5]==0)&&(grid[8]==0)||
	   (grid[0]==0)&&(grid[4]==0)&&(grid[8]==0)||
	   (grid[2]==0)&&(grid[4]==0)&&(grid[6]==0))
	   return 1;
	   else return 0;
}
void play()               //to play the game
{
	int 	g=0,t=0,gc=0;
	int	cm=0;
	settextstyle(0,0,1);
	cout<<"Player1 enter your choice X || O<1 for X and 0 for O>:-\n";
	cin>>cm;
	cleardevice();
	board();
	for(int i=0;i<9;i++)
		grid[i]=-1;
	while(g==0)
	{
		cout<<"Player "<<t+1<<" turn\n";
		cin>>ch;
		if(grid[ch-1]!=-1)
		{
			while(grid[ch-1]!=-1)
			{
					cout<<"illegal choice\n enter again:";
					cin>>ch;
			}
		}
		grid[ch-1]=cm;
		gc++;
		if(checkwinner())
		{
			g=1;
			cout<<"Player "<<t+1<<"wins";
			delay(200);
		}
		if((gc==9)&&(g==0))
		{
			g=1;
			cout<<"Draw";
			delay(200);
		}
		drawshape(cm,ch);
		cm=1-cm;
		t=1-t;
	}
}



