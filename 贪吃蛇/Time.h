class Time
{
	public:
		Time();
		virtual void calculator_time()=0;					//计算时间
	protected:
		int time_all;										//一次游戏进行的时间
};

Time::Time()
{
	time_all=0;
}

class time1:public Time
{
	public:
		time1(int,int,control *c);
		virtual void calculator_time();
		int get_time();
	private:
		int level;											//调用control类中的start()函数的参数之一
		int which_kind;										//调用control类中的start()函数的参数之一
		control *con;
};

time1::time1(int a,int b,control *c)
{
	level=a;
	which_kind=b;
	con=c;
}

void time1::calculator_time()
{
	time_t time_Begin,time_End;
	time_Begin=time(NULL);
	con->start(level,which_kind);
	time_End=time(NULL);
	time_all=time_End-time_Begin;							//计算一次运行的时间
	con->show_score();
	setfontbkcolor(WHITE);
	setfont(20,0,"宋体");
	outtextxy(180,255,"您所用时间：");
	char t[5];
	sprintf(t,"%d",time_all);								//将时间从整型转换为字符串
	outtextxy(300,255,t);
	getch();
}