class snake
{
	public:
		snake(const int,const int,Map *map);		//snake类构造函数——初始化蛇的坐标
		void draw();								//绘制蛇形状
		void move_left();							//向左移动
		void move_right();							//向右移动
		void move_up();								//向上移动
		void move_down();							//向下移动
		void move_forward();						//直行
		int eat_food();								//判断是否吃到食物
		bool judge_life();							//判断是否活着（碰到边框或蛇身则死亡）
		bool get_life();							//得到蛇当前生命状态
		char get_head_direction();					//得到当前前进方向
		void change_head_direction(char);			//改变前进方向
		Map *m;										//所属地图
		void change_life(bool);						//改变蛇生命状态
	private:
		int body_x[100];							//蛇身的x坐标
		int body_y[100];							//蛇身的y坐标
		int snake_length;							//蛇的长度
		bool life;									//蛇生命状态
		char head_direction;						//前进方向（a,s,d,w）
};

snake::snake(const int length,const int width,Map *map)
{
	m=map;
	snake_length=3;									//初始化蛇的长度
	life=true;										//初始化蛇的生命状态
	head_direction='s';								//初始化蛇的前进方向
	body_x[0]=length/2;								//蛇初始化位置x坐标
	body_y[0]=width/2;								//蛇初始化位置y坐标
	for(int i=1;i<snake_length;++i)
		{
			body_x[i]=body_x[i-1];
			body_y[i]=body_y[i-1]-10;
		}
	draw();
}

void snake::draw()
{	
	setfillstyle(EMPTY_FILL,GREEN);
	fillellipse(body_x[0],body_y[0],5,5);
	setfillstyle(EMPTY_FILL,BROWN);
	for(int i=1;i<snake_length;++i)
		{
			fillellipse(body_x[i],body_y[i],5,5);
		}
}

void snake::move_left()								//思路：后一节的坐标等于前一节的坐标，第一节的x坐标向左移动10
{
	body_x[snake_length]=body_x[snake_length-1];
	body_y[snake_length]=body_y[snake_length-1];
	for(int i=snake_length-1;i>=1;--i)
	{
		body_x[i]=body_x[i-1];
		body_y[i]=body_y[i-1];
	}
	body_x[0]=body_x[0]-10;
	draw();
}

void snake::move_right()							//思路：后一节的坐标等于前一节的坐标，第一节的x坐标向右移动10
{
	body_x[snake_length]=body_x[snake_length-1];
	body_y[snake_length]=body_y[snake_length-1];
	for(int i=snake_length-1;i>=1;--i)
	{
		body_x[i]=body_x[i-1];
		body_y[i]=body_y[i-1];
	}
	body_x[0]=body_x[0]+10;
	draw();
}

void snake::move_up()								//思路：后一节的坐标等于前一节的坐标，第一节的y坐标向上移动10
{
	body_x[snake_length]=body_x[snake_length-1];
	body_y[snake_length]=body_y[snake_length-1];
	for(int i=snake_length-1;i>=1;--i)
	{
		body_x[i]=body_x[i-1];
		body_y[i]=body_y[i-1];
	}
	body_y[0]=body_y[0]-10;
	draw();
}

void snake::move_down()								//思路：后一节的坐标等于前一节的坐标，第一节的y坐标向下移动10
{
	body_x[snake_length]=body_x[snake_length-1];
	body_y[snake_length]=body_y[snake_length-1];
	for(int i=snake_length-1;i>=1;--i)
	{
		body_x[i]=body_x[i-1];
		body_y[i]=body_y[i-1];
	}
	body_y[0]=body_y[0]+10;
	draw();
}

double sqrt(double);								//对根号函数进行声明

int snake::eat_food()								//当食物的中心和蛇头的中心之间的距离小于10的时候，则判断为吃到了食物
{
	if(sqrt(double(body_x[0]-m->get_food_x())*(body_x[0]-m->get_food_x())+(body_y[0]-m->get_food_y())*(body_y[0]-m->get_food_y()))<(double)10)
		{
			snake_length=snake_length+1;
			draw();
			return 1;
		}
	else 
		return 0;
}

bool snake::judge_life()							//当蛇头碰到了边界或者蛇身，则判断为死亡
{
	int k=0;
	for(int i=1;i<snake_length-1;++i)
		{
			if(sqrt(double((body_x[0]-body_x[i])*(body_x[0]-body_x[i]))+(body_y[0]-body_y[i])*(body_y[0]-body_y[i]))<10)
				k=1;
		}
	if((body_x[0]-0)<5||((m->get_Map_length()-1)-body_x[0])<5
		||body_y[0]<5||((m->get_Map_width()-1)-body_y[0])<5||k)
		return false;
	else 
		return true;

}

bool snake::get_life()								//返回蛇的生命状态
{
	return life;
}

void snake::change_head_direction(char k)			//改变蛇当前前进方向
{
	head_direction=k;
}

char snake::get_head_direction()					//得到蛇当前前进方向
{
	return head_direction;
}

void snake::move_forward()							//当没有对蛇方向做出改变的时候，则保持前行
{
	if(head_direction=='a')
		{
			for(int i=snake_length-1;i>=1;--i)
				{
					body_x[i]=body_x[i-1];
					body_y[i]=body_y[i-1];
				}
			body_x[0]=body_x[0]-10;
		}
	if(head_direction=='s')
		{
			for(int i=snake_length-1;i>=1;--i)
				{
					body_x[i]=body_x[i-1];
					body_y[i]=body_y[i-1];
				}
			body_y[0]=body_y[0]+10;
		}
	if(head_direction=='d')
		{
			for(int i=snake_length-1;i>=1;--i)
				{
					body_x[i]=body_x[i-1];
					body_y[i]=body_y[i-1];
				}
			body_x[0]=body_x[0]+10;
		}
	if(head_direction=='w')
		{
			for(int i=snake_length-1;i>=1;--i)
				{
					body_x[i]=body_x[i-1];
					body_y[i]=body_y[i-1];
				}
			body_y[0]=body_y[0]-10;
		}
	draw();
}

void snake::change_life(bool b)						//改变蛇的生命状态
{
	life=b;
}