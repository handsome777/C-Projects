//employee����
class employee														//�������
{
	public:
		employee(){};
		virtual double pay_calculate()=0;							//��н���㺯�������麯����
		virtual void  adjust_accumpay(){};							//����нˮ����
		static int num;												//�Զ����+1
	protected:
		char name[10];												//����
		char sex[3];												//�Ա�
		int NO;														//Ա�����
		char grade;													//�ȼ�
		double accumpay;											//��н
		
};

//����Զ���1
int employee::num=1;

//CEO��
class CEO:public employee
{
	public:
		CEO();														//ȱʡ���캯��
		CEO(char n[],char s[],char g);								//���ι��캯��
		virtual double pay_calculate();
		friend ostream & operator<<(ostream & output,CEO & C);		//�������
		friend istream & operator>>(istream & input,CEO & C);		//��������
		virtual void adjust_accumpay();								//������н����
		double static get_accumpay_c();								//������н����̬������
	private:
		static double accumpay_CEO;									//CEO�̶�����
};

//CEO��ʼ����
double CEO::accumpay_CEO=20000;										

//CEOȱʡ���캯��
CEO::CEO()															
{
	NO=num;
	num=num+1;
}

//�в����Ĺ��캯��
CEO::CEO(char n[],char s[],char g)									
{
	strcpy(name,n);
	strcpy(sex,s);
	grade=g;
	NO=num;
	num=num+1;
}

//���ʼ��㺯��
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
	cout<<"�����������������Ա𡢵ȼ�:"<<'\n';
	input>>C.name>>C.sex>>C.grade;
	return input;
}

//�������ʺ���
void CEO::adjust_accumpay()
{
	cout<<"����CEO����:";
	double a;
	cin>>a;
	accumpay_CEO=a;
}

//�õ����ʺ���
double CEO::get_accumpay_c()
{
	return accumpay_CEO;
}

//������
class manager:virtual public employee
{
	public:
		manager();
		manager(char n[],char s[],char g);
		virtual double pay_calculate();
		friend ostream & operator<<(ostream & output,manager & m);				//�������
		friend istream & operator>>(istream & input,manager & m);				//��������
		virtual void adjust_accumpay();											//��н��������
		double static get_accumpay_m();											//�õ����ڵ���н��̬����
		double static get_accumpay_mpre();										//�õ�֮ǰ����н��̬����
	protected:
		static double accumpay_manager;											//��ǰ������н
		static double accumpay_manager_pre;										//��һ���޸�ʱ����н
};

//��н��ʼ��
double manager::accumpay_manager=15000;

//��н��ʼ��
double manager::accumpay_manager_pre=15000;

//ȱʡ���캯��
manager::manager()
{
	NO=num;
	num=num+1;
}

//���εĹ��캯��
manager::manager(char n[],char s[],char g)
{
	strcpy(name,n);
	strcpy(sex,s);
	grade=g;
	NO=num;
	num=num+1;
}

//���ʼ��㺯��
double manager::pay_calculate()
{
	accumpay=accumpay_manager;
	return accumpay;
}

ostream & operator<<(ostream & output,manager & m)
{
	output<<"����"<<'\t'<<m.name<<'\t'<<m.sex<<'\t'<<m.NO<<'\t'<<m.grade<<'\t'<<m.accumpay_manager<<'\n';
	return output;
}

istream & operator>>(istream & input,manager & m)
{
	cout<<"�����������������Ա𡢵ȼ�:"<<'\n';
	input>>m.name>>m.sex>>m.grade;
	return input;
}

//�������ʺ���
void manager::adjust_accumpay()
{
	cout<<"���뾭����:";
	double a;
	cin>>a;
	accumpay_manager_pre=accumpay_manager;									//�����޸�֮ǰ����н
	accumpay_manager=a;														//��������н��ֵ
}

//�õ�������н��̬����
double manager::get_accumpay_m()
{
	return accumpay_manager;
}

//�õ�֮ǰ��н��̬����
double manager::get_accumpay_mpre()
{
	return accumpay_manager_pre;
}

//������
class technician:virtual public employee
{
	public:
		technician();														//������ȱʡ���캯��
		technician(char n[],char s[],char g,int w);							//���ι��캯��
		virtual double pay_calculate();										//���㹤�ʺ���
		friend ostream & operator<<(ostream & output,technician & t);		//�������
		friend istream & operator>>(istream & input,technician & t);		//��������
		virtual void adjust_accumpay();										//�������ʺ���
		double static get_accumpay_t();										//�õ�����ÿСʱ���ʺ���
		double static get_accumpay_tpre();									//�õ�֮ǰÿСʱ���ʺ���
	private:
		int work_hour;														//����Сʱ
		static double accumpay_per_hour;									//��ǰÿСʱ����
		static double accumpay_per_hour_pre;								//֮ǰÿСʱ����
};

//ÿСʱ���ʳ�ʼ��
double technician::accumpay_per_hour=30;

//ÿСʱ���ʳ�ʼ��
double technician::accumpay_per_hour_pre=30;

//ȱʡ���캯��
technician::technician()
{
	NO=num;
	num=num+1;
}

//���ι��캯��
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

//���㹤�ʺ���
double technician::pay_calculate()
{
	double a;
	a=accumpay_per_hour*work_hour;
	return a;
}

ostream & operator<<(ostream & output,technician & t)
{
	output<<"����"<<'\t'<<t.name<<'\t'<<t.sex<<'\t'<<t.NO<<'\t'<<t.grade<<'\t'<<t.accumpay<<'\n';
	return output;
}

istream & operator>>(istream & input,technician & t)
{
	cout<<"�����������������Ա𡢵ȼ�������ʱ��:"<<'\n';
	input>>t.name>>t.sex>>t.grade>>t.work_hour;
	t.accumpay=t.pay_calculate();
	return input;
}

//�������ʺ���
void technician::adjust_accumpay()
{
	cout<<"�����뼼��ÿСʱ�Ĺ���:";
	double a;
	cin>>a;
	accumpay_per_hour_pre=accumpay_per_hour;
	accumpay_per_hour=a;
}

//�õ�����ÿСʱ���ʺ���
double technician::get_accumpay_t()
{
	return accumpay_per_hour;
}

//�õ�֮ǰÿСʱ���ʺ���
double technician::get_accumpay_tpre()
{
	return accumpay_per_hour_pre;
}

//������
class sales:virtual public employee
{
	public:
		sales();
		sales(char n[],char s[],char g,double a);
		virtual double pay_calculate();											//���ʼ��㺯��
		friend ostream & operator<<(ostream & output,sales & s);				//�������
		friend istream & operator>>(istream & input,sales & s);					//��������
		virtual void adjust_accumpay();											//���ʵ�������
		double static get_propotion_S();										//�õ���ǰ��ɱ�������
		double static get_propotion_Spre();										//�õ��޸�֮ǰ�ı�������
	protected:
		double amount;															//��������
		double static propotion_sales;											//��ǰ�������
		double static propotion_sales_pre;										//�޸�֮ǰ�������
};

//��������ɱ�����ʼ��
double sales::propotion_sales=0.05;

//��������ɱ�����ʼ��
double sales::propotion_sales_pre=0.05;

//ȱʡ���캯��
sales::sales()
{
	NO=num;
	num=num+1;
}

//���ι��캯��
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

//���ʼ��㺯��
double sales::pay_calculate()
{
	double a;
	a=amount*propotion_sales;
	return a;
}

ostream & operator<<(ostream & output,sales & s)
{
	output<<"����"<<'\t'<<s.name<<'\t'<<s.sex<<'\t'<<s.NO<<'\t'<<s.grade<<'\t'<<s.accumpay<<'\n';
	return output;
}

istream & operator>>(istream & input,sales & s)
{
	cout<<"�����������������Ա𡢵ȼ�����������:"<<'\n';
	input>>s.name>>s.sex>>s.grade>>s.amount;
	s.accumpay=s.pay_calculate();
	return input;
}

//���ʵ�������
void sales::adjust_accumpay()
{
	cout<<"������������ɱ���:";
	double p;
	cin>>p;
	propotion_sales_pre=propotion_sales;
	propotion_sales=p;
}

//�õ���ǰ��ɱ�������
double sales::get_propotion_S()
{
	return propotion_sales;
}

//�õ��޸�֮ǰ�ı�������
double sales::get_propotion_Spre()
{
	return propotion_sales_pre;
}

//���۾���
class sales_manager:public manager,public sales
{
	public:
		sales_manager();
		sales_manager(char n[],char s[],char g,double a);
		virtual double pay_calculate();												//���ʼ��㺯��
		friend ostream & operator<<(ostream & output,sales_manager & s);			//�������
		friend istream & operator>>(istream & input,sales_manager & s);				//��������
		virtual void adjust_accumpay();												//��н��������
		double static get_propotion_SM();											//�õ���ǰ��ɱ���
		double static get_propotion_SMpre();										//�õ��޸�֮ǰ��ɱ���
	private:
		double static propotion_sales_manager;										//���۾���ǰ��ɱ���
		double static propotion_sales_manager_pre;									//���۾����޸�֮ǰ��ɱ���
};

//��ɱ�����ʼ��
double sales_manager::propotion_sales_manager=0.08;

//��ɱ�����ʼ��
double sales_manager::propotion_sales_manager_pre=0.08;

//ȱʡ���캯��
sales_manager::sales_manager()
{
	NO=num-2;
	num=num-1;
}

//���ι��캯��
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

//���ʼ��㺯��
double sales_manager::pay_calculate()
{
	double a;
	a=accumpay_manager+amount*propotion_sales_manager;
	return a;
}

ostream & operator<<(ostream & output,sales_manager & s)
{
	output<<"���۾���"<<'\t'<<s.name<<'\t'<<s.sex<<'\t'<<s.NO<<'\t'<<s.grade<<'\t'<<s.accumpay<<'\n';
	return output;
}

istream & operator>>(istream & input,sales_manager & s)
{
	cout<<"�����������������Ա𡢵ȼ�����������:"<<'\n';
	input>>s.name>>s.sex>>s.grade>>s.amount;
	s.accumpay=s.pay_calculate();
	return input;
}

//��н��������
void sales_manager::adjust_accumpay()
{
	cout<<"������ɱ���:";
	double b;
	cin>>b;
	propotion_sales_manager_pre=propotion_sales_manager;
	propotion_sales_manager=b;
}

//�õ���ǰ��ɱ���
double sales_manager::get_propotion_SM()
{
	return propotion_sales_manager;
}

//���۾����޸�֮ǰ��ɱ���
double sales_manager::get_propotion_SMpre()
{
	return propotion_sales_manager_pre;
}