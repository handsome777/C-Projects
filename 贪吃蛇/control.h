enum Direction{a,s,d,w,q};

class control
{
	public:
		control(snake *S);				//control类的构造函数
		void start(int,int);					//贪吃蛇开始函数
		void game_over();				//游戏结束（输出DEAD）
		bool left();					//左转（判断是否是反方向）
		bool right();					//右转（判断是否是左方向）
		bool up();						//向上（判断是否向下）
		bool down();					//向下（判断是都向上）
		void show_score();				//显示得分
		void forward();					//没有方向变化，直行
		int operator +(int);			//对+进行重载
	private:
		char direction;					//键盘输入前进方向
		Direction D;					//方向键
		snake *sna;						
	    int score;						//得分计数
};

control::control(snake *S)				
{
	sna=S;
	direction='q';
	score=0;							//每一次开始的时候，重置分数
}

void control::start(int p,int o)
{
	while(1)
		{
			if(sna->get_life())					//当蛇是活着的时候执行（每一个循环执行一次）
				{
					if(kbhit())
					{
						direction=getch();		//从键盘输入
					}
					if(direction!='a'&&direction!='s'&&direction!='d'&&direction!='w')
					D=q;
					if(direction=='a')
						D=a;
					if(direction=='s')
						D=s;
					if(direction=='d')
						D=d;
					if(direction=='w')
						D=w;
				switch (D)
					{
						case 0:sna->change_life(left());break;
						case 1:sna->change_life(down());break;
						case 2:sna->change_life(right());break;
						case 3:sna->change_life(up());break;
						case 4:forward();break;
					}
				if(sna->get_life())				//当蛇活着的时候判断一次蛇的生命状态
					sna->change_life(sna->judge_life());
				if(o)							
			        Sleep(750-150*p);			//匀速运动（不同等级）
				else							//变速运动（先加速，后匀速）
					{
						if(score<=13)
							Sleep(750-50*score);
						else
							Sleep(100);
					}
				cleardevice();					//每一个循环刷新一次，并重新绘制相应的内容
				setfillstyle(EMPTY_FILL,WHITE); //绘制地图背景
				bar(0,0,sna->m->get_Map_length(),sna->m->get_Map_width());
				if(sna->eat_food())				//当蛇吃到食物的时候
					{
						score++;				//分数+1
						sna->m->set_food();		//刷新食物
					}
				else 
					sna->m->draw_food();		//否则，显示原食物
			}
	else										//当蛇生命状态是死的时候
		{
			game_over();						//游戏结束
			break;
		}
	}
}

bool control::left()							//判断对蛇方向改变是否是当前前进方向的反方向
{
	if(sna->get_head_direction()!='d')
		{
			sna->move_left();
			sna->change_head_direction('a');
			return true;
		}
	else										//当是反方向的时候，蛇死亡
		return false;
}

bool control::right()							//判断对蛇方向改变是否是当前前进方向的反方向
{
	if(sna->get_head_direction()!='a')
		{
			sna->move_right();
			sna->change_head_direction('d');
			return true;
		}
	else										//当是反方向的时候，蛇死亡
		return false;
}

bool control::up()								//判断对蛇方向改变是否是当前前进方向的反方向
{
	if(sna->get_head_direction()!='s')
		{
			sna->move_up();
			sna->change_head_direction('w');
			return true;
		}
	else										//当是反方向的时候，蛇死亡
		return false;
}

bool control::down()							//判断对蛇方向改变是否是当前前进方向的反方向
{
	if(sna->get_head_direction()!='w')
		{
			sna->move_down();
			sna->change_head_direction('s');
			return true;
		}
	else										//当是反方向的时候，蛇死亡
		return false;
}

void control::forward()							//没有做出方向改变时候，沿当前前进方向前进。
{
	sna->move_forward();
}

void control::game_over()						//当游戏结束的时候，打印DEAD、所得分数、所用时间
{
	char a[]="DEAD";
	cleardevice();
	setfillstyle(EMPTY_FILL,WHITE);
	bar(0,0,500,500);
	setcolor(RED);
	setfontbkcolor(WHITE);
	setfont(35,0,"宋体");
	outtextxy(200,200,a);
	char name[10][20];
	char scor[10][5];
	ifstream ifile("数据库.txt");
	int k;
	for(int i=0;;++i)
		{
			ifile.getline(name[i],100,'\t');
			ifile.getline(scor[i],100,'\n');
			k=i;
			if(ifile.peek()==EOF) break;
		}
	ifile.close();
	char s[5];
	sprintf(s,"%d",score);
	strcpy(scor[k],s);
	ofstream ofile("数据库.txt",ios::trunc);
	for(int i=0;i<=k;++i)
	{
		ofile<<name[i]<<'\t'<<scor[i]<<'\n';
	}
	ofile.close();
}

void control::show_score()
{
	char a[5];
	sprintf(a,"%d",score);
	setcolor(BLACK);
	setfontbkcolor(WHITE);
	setfont(20,0,"宋体");
	outtextxy(180,235,"您的得分是：");
	outtextxy(300,235,a);
}

int control::operator+(int k)
{
	return score+k;
}