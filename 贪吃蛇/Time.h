class Time
{
	public:
		Time();
		virtual void calculator_time()=0;					//����ʱ��
	protected:
		int time_all;										//һ����Ϸ���е�ʱ��
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
		int level;											//����control���е�start()�����Ĳ���֮һ
		int which_kind;										//����control���е�start()�����Ĳ���֮һ
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
	time_all=time_End-time_Begin;							//����һ�����е�ʱ��
	con->show_score();
	setfontbkcolor(WHITE);
	setfont(20,0,"����");
	outtextxy(180,255,"������ʱ�䣺");
	char t[5];
	sprintf(t,"%d",time_all);								//��ʱ�������ת��Ϊ�ַ���
	outtextxy(300,255,t);
	getch();
}