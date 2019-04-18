#include<iostream>
#include<Windows.h>
#include<graphics.h>
#include<cmath>
#include<fstream>
#include<time.h>
using namespace std; 
#include"map.h"
#include"snake.h"
#include"control.h"
#include"Time.h"

int score_all;															//所有玩家总得分数

int main()
{
	void creat_account();												//创建账户
	void read_rule();													//阅读规则
	void greedy_snake1();												//贪吃蛇1——匀速不可穿墙
	void greedy_snake2();												//贪吃蛇2——变速不可穿墙
	void hero_ordor();													//根据得分排名
	void log_out();
	for(int i=0;;++i)
		{
			initgraph(500,500);
			setfillstyle(EMPTY_FILL,WHITE);
			bar(0,0,500,500);
			setcolor(BLACK);
			setfontbkcolor(WHITE);
			setfont(16,0,"宋体");
			outtextxy(100,100,"   ------------------------");
			outtextxy(100,116,"   |                      |");
			outtextxy(100,132,"   |     贪吃蛇大作战     |");
			outtextxy(100,148,"   |                      |");
			outtextxy(100,164,"   ------------------------");
			outtextxy(100,180,"*********************************");
			outtextxy(100,196,"     1.创建游戏账号");
			outtextxy(100,212,"     2.阅读游戏规则");
			outtextxy(100,228,"     3.贪吃蛇1——匀速");
			outtextxy(100,244,"     4.贪吃蛇2——变速");
			outtextxy(100,260,"     5.英雄榜");
			outtextxy(100,276,"     6.退出游戏");
			outtextxy(100,292,"*********************************");
			outtextxy(100,308,"      请输入序号");
			setfont(14,0,"宋体");
			setcolor(RED);
			outtextxy(50,400,"注：必须先创建账户！！！创建三个账户之后才能进行英雄榜功能！！");
			outtextxy(100,450,"在进行游戏之前必须创建一个游戏账户");
			char a;
			a=getch();
			switch(a)
				{
					 case '1':creat_account();break;
					 case '2':read_rule();break;
					 case '3':greedy_snake1();break;
					 case '4':greedy_snake2();break;
					 case '5':hero_ordor();break;
					 case '6':log_out();break;
					 default:break;
				}
		}
}

void creat_account()
{
	ofstream ofile("数据库.txt",ios::app);
	char a[20];
	int i;
	cleardevice();
	setfillstyle(EMPTY_FILL,WHITE);
	bar(0,0,500,500);
	setcolor(BLACK);
	setfontbkcolor(WHITE);
	setfont(16,0,"宋体");
	inputbox_getline("请输入您的名字：","请输入您的游戏昵称(回车确认)",a,20);
	ofile<<a<<'\t'<<"0"<<'\n';
	ofile.close();
}

void read_rule()
{
	cleardevice();
	setfillstyle(EMPTY_FILL,WHITE);
	bar(0,0,500,500);
	setcolor(BLACK);
	setfontbkcolor(WHITE);
	setfont(14,0,"宋体");
	outtextxy(80,100,"游戏规则：");
	outtextxy(80,116,"1.贪吃蛇控制：a(左),s(下),d(右),w(上)");
	outtextxy(80,132,"2.当贪吃蛇碰到自己身体或者边界的时候，死亡");
	outtextxy(80,148,"3.选择匀速时,等级从1-4,速度呈梯度上升");
	outtextxy(80,164,"4.选择变速,得分越多，速度越快，当速度足够快的时候,会匀速");
	outtextxy(80,180,"5.绿色为蛇头，棕色为蛇身");
	outtextxy(80,196,"6.初始方向竖直向下");
	outtextxy(80,212,"按任意键回到菜单");
	char a;
	a=getch();
}		

void greedy_snake1()
{
	int length=500;
	int width=500;
	int i=0;
	cleardevice();
	setfillstyle(EMPTY_FILL,WHITE);
	bar(0,0,500,500);
	setcolor(BLACK);
	setfontbkcolor(WHITE);
	setfont(20,0,"宋体");
	outtextxy(170,200,"请选择难度");
	outtextxy(170,220,"1.简单");
	outtextxy(170,240,"2.一般");
	outtextxy(170,260,"3.困难");
	outtextxy(170,280,"4.绝望");
	char a;
	a=getch();
	switch(a)
	{
		case '1':i=1;break;
		case '2':i=2;break;
		case '3':i=3;break;
		case '4':i=4;break;
	}
	Map m(length,width);
	snake s(length,width,&m);
	control c(&s);
	time1 t(i,1,&c);
	getch();
	t.calculator_time();
	score_all=c+score_all;
}

void greedy_snake2()
{
	int length=500;
	int width=500;
	Map m(length,width);
	snake s(length,width,&m);
	control c(&s);
	time1 t(0,0,&c);
	getch();
	t.calculator_time();
	score_all=c+score_all;
}

void hero_ordor()
{
	char name[10][20];
	char score[10][5];
	int sc[10];
	ifstream ifile("数据库.txt");
	int k;
	for(int i=0;;++i)
		{
			ifile.getline(name[i],100,'\t');
			ifile.getline(score[i],100,'\n');
			k=i;
			if(ifile.peek()==EOF) break;
		}
	ifile.close();
	for(int i=0;i<=k;++i)
	{
		sc[i]=atoi(score[i]);
	}
	for(int i=0;i<=k;++i)
	{
		for(int j=i+1;j<=k;++j)
		{
			if(sc[j]>sc[i])
			{
				int t;
				char n[20];
				t=sc[j];sc[j]=sc[i];sc[i]=t;
				strcpy(n,name[i]);
				strcpy(name[i],name[j]);
				strcpy(name[j],n);
			}
		}
	}
	char a[3][5];
	sprintf(a[0],"%d",sc[0]);
	sprintf(a[1],"%d",sc[1]);
	sprintf(a[2],"%d",sc[2]);
	cleardevice();
	setfillstyle(EMPTY_FILL,WHITE);
	bar(0,0,500,500);
	setcolor(BLACK);
	setfontbkcolor(WHITE);
	setfont(20,0,"宋体");
	outtextxy(150,100,"英雄榜");
	outtextxy(150,125,"第一名：");
	outtextxy(230,125,name[0]);
	outtextxy(300,125,a[0]);
	outtextxy(150,150,"第二名：");
	outtextxy(230,150,name[1]);
	outtextxy(300,150,a[1]);
	outtextxy(150,175,"第三名：");
	outtextxy(230,175,name[2]);
	outtextxy(300,175,a[2]);
	outtextxy(150,200,"所有玩家总得分数：");
	char sco[5];
	sprintf(sco,"%d",score_all);
	outtextxy(350,200,sco);
	getch();
}

void log_out()
{
	cleardevice();
	setfillstyle(EMPTY_FILL,WHITE);
	bar(0,0,500,500);
	setcolor(BLACK);
	setfontbkcolor(WHITE);
	setfont(30,0,"宋体");
	outtextxy(130,100," 谢 谢 使 用！");
	setfont(15,0,"宋体");
	outtextxy(130,130,"**************************");
	outtextxy(130,145,"      出品人：漆耘含");
	outtextxy(130,160,"       监制：漆耘含");
	outtextxy(130,175,"    创作时间：2017.7.2");
	getch();
	exit(0);
}