enum Direction{a,s,d,w,q};

class control
{
	public:
		control(snake *S);				//control��Ĺ��캯��
		void start(int,int);					//̰���߿�ʼ����
		void game_over();				//��Ϸ���������DEAD��
		bool left();					//��ת���ж��Ƿ��Ƿ�����
		bool right();					//��ת���ж��Ƿ�������
		bool up();						//���ϣ��ж��Ƿ����£�
		bool down();					//���£��ж��Ƕ����ϣ�
		void show_score();				//��ʾ�÷�
		void forward();					//û�з���仯��ֱ��
		int operator +(int);			//��+��������
	private:
		char direction;					//��������ǰ������
		Direction D;					//�����
		snake *sna;						
	    int score;						//�÷ּ���
};

control::control(snake *S)				
{
	sna=S;
	direction='q';
	score=0;							//ÿһ�ο�ʼ��ʱ�����÷���
}

void control::start(int p,int o)
{
	while(1)
		{
			if(sna->get_life())					//�����ǻ��ŵ�ʱ��ִ�У�ÿһ��ѭ��ִ��һ�Σ�
				{
					if(kbhit())
					{
						direction=getch();		//�Ӽ�������
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
				if(sna->get_life())				//���߻��ŵ�ʱ���ж�һ���ߵ�����״̬
					sna->change_life(sna->judge_life());
				if(o)							
			        Sleep(750-150*p);			//�����˶�����ͬ�ȼ���
				else							//�����˶����ȼ��٣������٣�
					{
						if(score<=13)
							Sleep(750-50*score);
						else
							Sleep(100);
					}
				cleardevice();					//ÿһ��ѭ��ˢ��һ�Σ������»�����Ӧ������
				setfillstyle(EMPTY_FILL,WHITE); //���Ƶ�ͼ����
				bar(0,0,sna->m->get_Map_length(),sna->m->get_Map_width());
				if(sna->eat_food())				//���߳Ե�ʳ���ʱ��
					{
						score++;				//����+1
						sna->m->set_food();		//ˢ��ʳ��
					}
				else 
					sna->m->draw_food();		//������ʾԭʳ��
			}
	else										//��������״̬������ʱ��
		{
			game_over();						//��Ϸ����
			break;
		}
	}
}

bool control::left()							//�ж϶��߷���ı��Ƿ��ǵ�ǰǰ������ķ�����
{
	if(sna->get_head_direction()!='d')
		{
			sna->move_left();
			sna->change_head_direction('a');
			return true;
		}
	else										//���Ƿ������ʱ��������
		return false;
}

bool control::right()							//�ж϶��߷���ı��Ƿ��ǵ�ǰǰ������ķ�����
{
	if(sna->get_head_direction()!='a')
		{
			sna->move_right();
			sna->change_head_direction('d');
			return true;
		}
	else										//���Ƿ������ʱ��������
		return false;
}

bool control::up()								//�ж϶��߷���ı��Ƿ��ǵ�ǰǰ������ķ�����
{
	if(sna->get_head_direction()!='s')
		{
			sna->move_up();
			sna->change_head_direction('w');
			return true;
		}
	else										//���Ƿ������ʱ��������
		return false;
}

bool control::down()							//�ж϶��߷���ı��Ƿ��ǵ�ǰǰ������ķ�����
{
	if(sna->get_head_direction()!='w')
		{
			sna->move_down();
			sna->change_head_direction('s');
			return true;
		}
	else										//���Ƿ������ʱ��������
		return false;
}

void control::forward()							//û����������ı�ʱ���ص�ǰǰ������ǰ����
{
	sna->move_forward();
}

void control::game_over()						//����Ϸ������ʱ�򣬴�ӡDEAD�����÷���������ʱ��
{
	char a[]="DEAD";
	cleardevice();
	setfillstyle(EMPTY_FILL,WHITE);
	bar(0,0,500,500);
	setcolor(RED);
	setfontbkcolor(WHITE);
	setfont(35,0,"����");
	outtextxy(200,200,a);
	char name[10][20];
	char scor[10][5];
	ifstream ifile("���ݿ�.txt");
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
	ofstream ofile("���ݿ�.txt",ios::trunc);
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
	setfont(20,0,"����");
	outtextxy(180,235,"���ĵ÷��ǣ�");
	outtextxy(300,235,a);
}

int control::operator+(int k)
{
	return score+k;
}