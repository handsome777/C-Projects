class Map
{
	public:
		Map(const int,const int);
		void draw();				//���Ƶ�ͼ
		void set_food();			//ˢ��ʳ��
		void draw_food();			//����ʳ��
		int get_food_x();			//�õ�ʳ���x����
		int get_food_y();			//�õ�ʳ���y����
		int get_Map_length();		//�õ���ͼ�ĳ���
		int get_Map_width();		//�õ���ͼ�Ŀ��
	private:
		int Map_length;				//��ͼ����
		int Map_width;				//��ͼ���
		int food_x;					//ʳ��x����
		int food_y;					//ʳ��y����
};

Map::Map(const int length,const int width)
{
	initgraph(length,width);						//��һ������
	Map_length=length;				
	Map_width=width;
	draw();											//���ƴ����ڵı���
	set_food();										//����ʳ��
}

void Map::draw()
{
	cleardevice();
	setfillstyle(EMPTY_FILL,WHITE);
	bar(0,0,get_Map_length(),get_Map_width());
}

void Map::set_food()
{
	food_x=rand()%(Map_length-40)+20;
	food_y=rand()%(Map_width-40)+20;
	setfillstyle(EMPTY_FILL,BLACK);
	fillellipse(food_x,food_y,5,5);
}

int Map::get_food_x()
{
	return food_x;
}

int Map::get_food_y()
{
	return food_y;
}

int Map::get_Map_length()
{
	return Map_length;
}

int Map::get_Map_width()
{
	return Map_width;
}

void Map::draw_food()
{
	setfillstyle(EMPTY_FILL,BLACK);
	fillellipse(food_x,food_y,5,5);
}