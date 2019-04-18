//employee基类
class employee														//抽象基类
{
	public:
		employee(){};
		virtual double pay_calculate()=0;							//月薪计算函数（纯虚函数）
		virtual void  adjust_accumpay(){};							//调整薪水函数
		static int num;												//自动编号+1
	protected:
		char name[10];												//姓名
		char sex[3];												//性别
		int NO;														//员工编号
		char grade;													//等级
		double accumpay;											//月薪
		
};

//编号自动加1
int employee::num=1;

//CEO类
class CEO:public employee
{
	public:
		CEO();														//缺省构造函数
		CEO(char n[],char s[],char g);								//含参构造函数
		virtual double pay_calculate();
		friend ostream & operator<<(ostream & output,CEO & C);		//输出重载
		friend istream & operator>>(istream & input,CEO & C);		//输入重载
		virtual void adjust_accumpay();								//调整月薪函数
		double static get_accumpay_c();								//返回月薪（静态函数）
	private:
		static double accumpay_CEO;									//CEO固定工资
};

//CEO初始工资
double CEO::accumpay_CEO=20000;										

//CEO缺省构造函数
CEO::CEO()															
{
	NO=num;
	num=num+1;
}

//有参数的构造函数
CEO::CEO(char n[],char s[],char g)									
{
	strcpy(name,n);
	strcpy(sex,s);
	grade=g;
	NO=num;
	num=num+1;
}

//工资计算函数
double CEO::pay_calculate()
{
	accumpay=accumpay_CEO;
	return accumpay;
}

ostream & operator<<(ostream & output,CEO & C)
{
	output<<"CEO"<<'\t'<<C.name<<'\t'<<C.sex<<'\t'<<C.NO<<'\t'<<C.grade<<'\t'<<C.accumpay_CEO<<'\n';
	return output;
}

istream & operator>>(istream & input,CEO & C)
{
	cout<<"请依次输入姓名、性别、等级:"<<'\n';
	input>>C.name>>C.sex>>C.grade;
	return input;
}

//调整工资函数
void CEO::adjust_accumpay()
{
	cout<<"输入CEO工资:";
	double a;
	cin>>a;
	accumpay_CEO=a;
}

//得到工资函数
double CEO::get_accumpay_c()
{
	return accumpay_CEO;
}

//经理类
class manager:virtual public employee
{
	public:
		manager();
		manager(char n[],char s[],char g);
		virtual double pay_calculate();
		friend ostream & operator<<(ostream & output,manager & m);				//输出重载
		friend istream & operator>>(istream & input,manager & m);				//输入重载
		virtual void adjust_accumpay();											//月薪调整函数
		double static get_accumpay_m();											//得到现在的月薪静态函数
		double static get_accumpay_mpre();										//得到之前的月薪静态函数
	protected:
		static double accumpay_manager;											//当前经理月薪
		static double accumpay_manager_pre;										//上一次修改时的月薪
};

//月薪初始化
double manager::accumpay_manager=15000;

//月薪初始化
double manager::accumpay_manager_pre=15000;

//缺省构造函数
manager::manager()
{
	NO=num;
	num=num+1;
}

//含参的构造函数
manager::manager(char n[],char s[],char g)
{
	strcpy(name,n);
	strcpy(sex,s);
	grade=g;
	NO=num;
	num=num+1;
}

//工资计算函数
double manager::pay_calculate()
{
	accumpay=accumpay_manager;
	return accumpay;
}

ostream & operator<<(ostream & output,manager & m)
{
	output<<"经理"<<'\t'<<m.name<<'\t'<<m.sex<<'\t'<<m.NO<<'\t'<<m.grade<<'\t'<<m.accumpay_manager<<'\n';
	return output;
}

istream & operator>>(istream & input,manager & m)
{
	cout<<"请依次输入姓名、性别、等级:"<<'\n';
	input>>m.name>>m.sex>>m.grade;
	return input;
}

//调整工资函数
void manager::adjust_accumpay()
{
	cout<<"输入经理工资:";
	double a;
	cin>>a;
	accumpay_manager_pre=accumpay_manager;									//保留修改之前的月薪
	accumpay_manager=a;														//给现在月薪赋值
}

//得到现在月薪静态函数
double manager::get_accumpay_m()
{
	return accumpay_manager;
}

//得到之前月薪静态函数
double manager::get_accumpay_mpre()
{
	return accumpay_manager_pre;
}

//技工类
class technician:virtual public employee
{
	public:
		technician();														//技工类缺省构造函数
		technician(char n[],char s[],char g,int w);							//含参构造函数
		virtual double pay_calculate();										//计算工资函数
		friend ostream & operator<<(ostream & output,technician & t);		//输出重载
		friend istream & operator>>(istream & input,technician & t);		//输入重载
		virtual void adjust_accumpay();										//调整工资函数
		double static get_accumpay_t();										//得到现在每小时工资函数
		double static get_accumpay_tpre();									//得到之前每小时工资函数
	private:
		int work_hour;														//工作小时
		static double accumpay_per_hour;									//当前每小时工资
		static double accumpay_per_hour_pre;								//之前每小时工资
};

//每小时工资初始化
double technician::accumpay_per_hour=30;

//每小时工资初始化
double technician::accumpay_per_hour_pre=30;

//缺省构造函数
technician::technician()
{
	NO=num;
	num=num+1;
}

//含参构造函数
technician::technician(char n[],char s[],char g,int w)
{
	strcpy(name,n);
	strcpy(sex,s);
	grade=g;
	NO=num;
	num=num+1;
	work_hour=w;
	accumpay=pay_calculate();
}

//计算工资函数
double technician::pay_calculate()
{
	double a;
	a=accumpay_per_hour*work_hour;
	return a;
}

ostream & operator<<(ostream & output,technician & t)
{
	output<<"技工"<<'\t'<<t.name<<'\t'<<t.sex<<'\t'<<t.NO<<'\t'<<t.grade<<'\t'<<t.accumpay<<'\n';
	return output;
}

istream & operator>>(istream & input,technician & t)
{
	cout<<"请依次输入姓名、性别、等级、工作时间:"<<'\n';
	input>>t.name>>t.sex>>t.grade>>t.work_hour;
	t.accumpay=t.pay_calculate();
	return input;
}

//调整工资函数
void technician::adjust_accumpay()
{
	cout<<"请输入技工每小时的工资:";
	double a;
	cin>>a;
	accumpay_per_hour_pre=accumpay_per_hour;
	accumpay_per_hour=a;
}

//得到现在每小时工资函数
double technician::get_accumpay_t()
{
	return accumpay_per_hour;
}

//得到之前每小时工资函数
double technician::get_accumpay_tpre()
{
	return accumpay_per_hour_pre;
}

//销售类
class sales:virtual public employee
{
	public:
		sales();
		sales(char n[],char s[],char g,double a);
		virtual double pay_calculate();											//工资计算函数
		friend ostream & operator<<(ostream & output,sales & s);				//输出重载
		friend istream & operator>>(istream & input,sales & s);					//输入重载
		virtual void adjust_accumpay();											//工资调整函数
		double static get_propotion_S();										//得到当前提成比例函数
		double static get_propotion_Spre();										//得到修改之前的比例函数
	protected:
		double amount;															//月总销量
		double static propotion_sales;											//当前销售提成
		double static propotion_sales_pre;										//修改之前销售提成
};

//月销售提成比例初始化
double sales::propotion_sales=0.05;

//月销售提成比例初始化
double sales::propotion_sales_pre=0.05;

//缺省构造函数
sales::sales()
{
	NO=num;
	num=num+1;
}

//含参构造函数
sales::sales(char n[],char s[],char g,double a)
{
	strcpy(name,n);
	strcpy(sex,s);
	grade=g;
	NO=num;
	num=num+1;
	amount=a;
	accumpay=pay_calculate();
}

//工资计算函数
double sales::pay_calculate()
{
	double a;
	a=amount*propotion_sales;
	return a;
}

ostream & operator<<(ostream & output,sales & s)
{
	output<<"销售"<<'\t'<<s.name<<'\t'<<s.sex<<'\t'<<s.NO<<'\t'<<s.grade<<'\t'<<s.accumpay<<'\n';
	return output;
}

istream & operator>>(istream & input,sales & s)
{
	cout<<"请依次输入姓名、性别、等级、销售总量:"<<'\n';
	input>>s.name>>s.sex>>s.grade>>s.amount;
	s.accumpay=s.pay_calculate();
	return input;
}

//工资调整函数
void sales::adjust_accumpay()
{
	cout<<"请输入销售提成比例:";
	double p;
	cin>>p;
	propotion_sales_pre=propotion_sales;
	propotion_sales=p;
}

//得到当前提成比例函数
double sales::get_propotion_S()
{
	return propotion_sales;
}

//得到修改之前的比例函数
double sales::get_propotion_Spre()
{
	return propotion_sales_pre;
}

//销售经理
class sales_manager:public manager,public sales
{
	public:
		sales_manager();
		sales_manager(char n[],char s[],char g,double a);
		virtual double pay_calculate();												//工资计算函数
		friend ostream & operator<<(ostream & output,sales_manager & s);			//输出重载
		friend istream & operator>>(istream & input,sales_manager & s);				//输入重载
		virtual void adjust_accumpay();												//月薪调整工资
		double static get_propotion_SM();											//得到当前提成比例
		double static get_propotion_SMpre();										//得到修改之前提成比例
	private:
		double static propotion_sales_manager;										//销售经理当前提成比例
		double static propotion_sales_manager_pre;									//销售经理修改之前提成比例
};

//提成比例初始化
double sales_manager::propotion_sales_manager=0.08;

//提成比例初始化
double sales_manager::propotion_sales_manager_pre=0.08;

//缺省构造函数
sales_manager::sales_manager()
{
	NO=num-2;
	num=num-1;
}

//含参构造函数
sales_manager::sales_manager(char n[],char s[],char g,double a):manager(n,s,g),sales(n,s,g,a)
{
	strcpy(name,n);
	strcpy(sex,s);
	grade=g;
	NO=num-2;
	num=num-1;
	amount=a;
	accumpay=pay_calculate();
}

//工资计算函数
double sales_manager::pay_calculate()
{
	double a;
	a=accumpay_manager+amount*propotion_sales_manager;
	return a;
}

ostream & operator<<(ostream & output,sales_manager & s)
{
	output<<"销售经理"<<'\t'<<s.name<<'\t'<<s.sex<<'\t'<<s.NO<<'\t'<<s.grade<<'\t'<<s.accumpay<<'\n';
	return output;
}

istream & operator>>(istream & input,sales_manager & s)
{
	cout<<"请依次输入姓名、性别、等级、销售总量:"<<'\n';
	input>>s.name>>s.sex>>s.grade>>s.amount;
	s.accumpay=s.pay_calculate();
	return input;
}

//月薪调整工资
void sales_manager::adjust_accumpay()
{
	cout<<"输入提成比例:";
	double b;
	cin>>b;
	propotion_sales_manager_pre=propotion_sales_manager;
	propotion_sales_manager=b;
}

//得到当前提成比例
double sales_manager::get_propotion_SM()
{
	return propotion_sales_manager;
}

//销售经理修改之前提成比例
double sales_manager::get_propotion_SMpre()
{
	return propotion_sales_manager_pre;
}