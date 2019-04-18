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

int score_all;															//��������ܵ÷���

int main()
{
	void creat_account();												//�����˻�
	void read_rule();													//�Ķ�����
	void greedy_snake1();												//̰����1�������ٲ��ɴ�ǽ
	void greedy_snake2();												//̰����2�������ٲ��ɴ�ǽ
	void hero_ordor();													//���ݵ÷�����
	void log_out();
	for(int i=0;;++i)
		{
			initgraph(500,500);
			setfillstyle(EMPTY_FILL,WHITE);
			bar(0,0,500,500);
			setcolor(BLACK);
			setfontbkcolor(WHITE);
			setfont(16,0,"����");
			outtextxy(100,100,"   ------------------------");
			outtextxy(100,116,"   |                      |");
			outtextxy(100,132,"   |     ̰���ߴ���ս     |");
			outtextxy(100,148,"   |                      |");
			outtextxy(100,164,"   ------------------------");
			outtextxy(100,180,"*********************************");
			outtextxy(100,196,"     1.������Ϸ�˺�");
			outtextxy(100,212,"     2.�Ķ���Ϸ����");
			outtextxy(100,228,"     3.̰����1��������");
			outtextxy(100,244,"     4.̰����2��������");
			outtextxy(100,260,"     5.Ӣ�۰�");
			outtextxy(100,276,"     6.�˳���Ϸ");
			outtextxy(100,292,"*********************************");
			outtextxy(100,308,"      ���������");
			setfont(14,0,"����");
			setcolor(RED);
			outtextxy(50,400,"ע�������ȴ����˻����������������˻�֮����ܽ���Ӣ�۰��ܣ���");
			outtextxy(100,450,"�ڽ�����Ϸ֮ǰ���봴��һ����Ϸ�˻�");
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
	ofstream ofile("���ݿ�.txt",ios::app);
	char a[20];
	int i;
	cleardevice();
	setfillstyle(EMPTY_FILL,WHITE);
	bar(0,0,500,500);
	setcolor(BLACK);
	setfontbkcolor(WHITE);
	setfont(16,0,"����");
	inputbox_getline("�������������֣�","������������Ϸ�ǳ�(�س�ȷ��)",a,20);
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
	setfont(14,0,"����");
	outtextxy(80,100,"��Ϸ����");
	outtextxy(80,116,"1.̰���߿��ƣ�a(��),s(��),d(��),w(��)");
	outtextxy(80,132,"2.��̰���������Լ�������߽߱��ʱ������");
	outtextxy(80,148,"3.ѡ������ʱ,�ȼ���1-4,�ٶȳ��ݶ�����");
	outtextxy(80,164,"4.ѡ�����,�÷�Խ�࣬�ٶ�Խ�죬���ٶ��㹻���ʱ��,������");
	outtextxy(80,180,"5.��ɫΪ��ͷ����ɫΪ����");
	outtextxy(80,196,"6.��ʼ������ֱ����");
	outtextxy(80,212,"��������ص��˵�");
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
	setfont(20,0,"����");
	outtextxy(170,200,"��ѡ���Ѷ�");
	outtextxy(170,220,"1.��");
	outtextxy(170,240,"2.һ��");
	outtextxy(170,260,"3.����");
	outtextxy(170,280,"4.����");
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
	ifstream ifile("���ݿ�.txt");
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
	setfont(20,0,"����");
	outtextxy(150,100,"Ӣ�۰�");
	outtextxy(150,125,"��һ����");
	outtextxy(230,125,name[0]);
	outtextxy(300,125,a[0]);
	outtextxy(150,150,"�ڶ�����");
	outtextxy(230,150,name[1]);
	outtextxy(300,150,a[1]);
	outtextxy(150,175,"��������");
	outtextxy(230,175,name[2]);
	outtextxy(300,175,a[2]);
	outtextxy(150,200,"��������ܵ÷�����");
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
	setfont(30,0,"����");
	outtextxy(130,100," л л ʹ �ã�");
	setfont(15,0,"����");
	outtextxy(130,130,"**************************");
	outtextxy(130,145,"      ��Ʒ�ˣ����ź�");
	outtextxy(130,160,"       ���ƣ����ź�");
	outtextxy(130,175,"    ����ʱ�䣺2017.7.2");
	getch();
	exit(0);
}