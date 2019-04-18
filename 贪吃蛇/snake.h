class snake
{
	public:
		snake(const int,const int,Map *map);		//snake�๹�캯��������ʼ���ߵ�����
		void draw();								//��������״
		void move_left();							//�����ƶ�
		void move_right();							//�����ƶ�
		void move_up();								//�����ƶ�
		void move_down();							//�����ƶ�
		void move_forward();						//ֱ��
		int eat_food();								//�ж��Ƿ�Ե�ʳ��
		bool judge_life();							//�ж��Ƿ���ţ������߿��������������
		bool get_life();							//�õ��ߵ�ǰ����״̬
		char get_head_direction();					//�õ���ǰǰ������
		void change_head_direction(char);			//�ı�ǰ������
		Map *m;										//������ͼ
		void change_life(bool);						//�ı�������״̬
	private:
		int body_x[100];							//�����x����
		int body_y[100];							//�����y����
		int snake_length;							//�ߵĳ���
		bool life;									//������״̬
		char head_direction;						//ǰ������a,s,d,w��
};

snake::snake(const int length,const int width,Map *map)
{
	m=map;
	snake_length=3;									//��ʼ���ߵĳ���
	life=true;										//��ʼ���ߵ�����״̬
	head_direction='s';								//��ʼ���ߵ�ǰ������
	body_x[0]=length/2;								//�߳�ʼ��λ��x����
	body_y[0]=width/2;								//�߳�ʼ��λ��y����
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

void snake::move_left()								//˼·����һ�ڵ��������ǰһ�ڵ����꣬��һ�ڵ�x���������ƶ�10
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

void snake::move_right()							//˼·����һ�ڵ��������ǰһ�ڵ����꣬��һ�ڵ�x���������ƶ�10
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

void snake::move_up()								//˼·����һ�ڵ��������ǰһ�ڵ����꣬��һ�ڵ�y���������ƶ�10
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

void snake::move_down()								//˼·����һ�ڵ��������ǰһ�ڵ����꣬��һ�ڵ�y���������ƶ�10
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

double sqrt(double);								//�Ը��ź�����������

int snake::eat_food()								//��ʳ������ĺ���ͷ������֮��ľ���С��10��ʱ�����ж�Ϊ�Ե���ʳ��
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

bool snake::judge_life()							//����ͷ�����˱߽�����������ж�Ϊ����
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

bool snake::get_life()								//�����ߵ�����״̬
{
	return life;
}

void snake::change_head_direction(char k)			//�ı��ߵ�ǰǰ������
{
	head_direction=k;
}

char snake::get_head_direction()					//�õ��ߵ�ǰǰ������
{
	return head_direction;
}

void snake::move_forward()							//��û�ж��߷��������ı��ʱ���򱣳�ǰ��
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

void snake::change_life(bool b)						//�ı��ߵ�����״̬
{
	life=b;
}