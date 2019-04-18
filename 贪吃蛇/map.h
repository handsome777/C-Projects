class Map
{
	public:
		Map(const int,const int);
		void draw();				//绘制地图
		void set_food();			//刷新食物
		void draw_food();			//绘制食物
		int get_food_x();			//得到食物的x坐标
		int get_food_y();			//得到食物的y坐标
		int get_Map_length();		//得到地图的长度
		int get_Map_width();		//得到地图的宽度
	private:
		int Map_length;				//地图长度
		int Map_width;				//地图宽度
		int food_x;					//食物x坐标
		int food_y;					//食物y坐标
};

Map::Map(const int length,const int width)
{
	initgraph(length,width);						//打开一个窗口
	Map_length=length;				
	Map_width=width;
	draw();											//绘制窗口内的背景
	set_food();										//绘制食物
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