#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#include"Position.h"
int main()
{
	void shuru();                                                   //实现输入函数
	void view();                                                    //输出全部人员数据
	void search();											        //搜索函数
	void xiugai();													//修改人员信息函数
	void adjust();													//调整月薪函数
	int i;
	for(i=0;;i++)
	{																	//封面
		cout<<"-------------------------------"<<'\n';
		cout<<"|                             |"<<'\n';
		cout<<"|    耘含企业人事管理系统     |"<<'\n';
		cout<<"|          欢迎使用           |"<<'\n';
		cout<<"|                             |"<<'\n';
		cout<<"-------------------------------"<<'\n';
		cout<<"          1.员工数据录入"<<'\n';
		cout<<"          2.数据库总览"<<'\n';
		cout<<"          3.员工信息查询"<<'\n';
		cout<<"          4.员工数据修改"<<'\n';
		cout<<"          5.薪水调整"<<'\n';
		cout<<"          6.退出"<<'\n';
		cout<<"********************************"<<'\n';
		int choose;
		cout<<"您想要访问的序号："<<'\n';
		cin>>choose;
		switch(choose)													//目录
			{case 1:shuru();break;
			 case 2:view();break;
			 case 3:search();break;
			 case 4:xiugai();break;
			 case 5:adjust();break;
			 case 6:cout<<"谢谢使用，再见！"<<'\n';exit(0);}
	}
	return 0;
}

//数据输入函数
void shuru()
{
	ofstream ofile("数据库.txt",ios::app);
	if(!ofile)
		{cout<<"打开文件失败"<<'\n';
		 abort();}
	else
		{
			for(int l=0;;++l)											//大循环，可以实现不断地输入数据
				{cout<<"您想要输入的对象（CEO、经理、技工、销售、销售经理）和数量:"<<'\n';
				 char a[10];
				 int n;
				 cin>>a>>n;
			   	 if(strcmp(a,"经理")==0)								//进行经理类的输入操作
					{
						for(int j=0;j<n;++j)
							{
								manager *m;
								m=new manager;							//动态构建一个经理类对象
								cin>>*m;
								ofile<<*m;								//输出到文件中
								cout<<"录入成功"<<'\n';
							}
					}
				 if(strcmp(a,"CEO")==0)									//进行CEO类的输入操作
					{
						for(int j=0;j<n;++j)
							{
								CEO *c;
								c=new CEO;								//动态申请一个CEO类的对象
								cin>>*c;
								ofile<<*c;
								cout<<"录入成功"<<'\n';
							}
				 	}
				 if(strcmp(a,"技工")==0)								//进行技工类的输入操作
					{
						for(int j=0;j<n;++j)
							{
								technician *t;
								t=new technician;
								cin>>*t;
								ofile<<*t;
								cout<<"录入成功"<<'\n';
							}
					}
				 if(strcmp(a,"销售")==0)								//进行销售类的输入操作
					{
							for(int j=0;j<n;++j)
							{
								sales *s;
								s=new sales;
								cin>>*s;
								ofile<<*s;
								cout<<"录入成功"<<'\n';
							}
					}
				 if(strcmp(a,"销售经理")==0)							//进行销售经理的输入操作
					{
						for(int j=0;j<n;++j)
							{
								sales_manager *s;
								s=new sales_manager;
								cin>>*s;
								ofile<<*s;
								cout<<"录入成功"<<'\n';
							}
					}
				 cout<<"是否继续输入（Y/N）:";							//判断是否出外面的大循环
				 char m;
				 cin>>m;
				 while(m!='Y'&&m!='N')									//如果输入的不是Y/N，就循环直到输入正确
					{
						cout<<"输入错误，请重新输入Y/N:";
						cin>>m;
					}
				 if(m=='N') break;										//如果否定，则出循环，返回目录
			}
		}	 
	ofile.close();
}

//输出所有的人员信息
void view()
{
	char position[100][20];												//根据输出到文件中的格式，来进行设置
	char name[100][20];
	char sex[100][10];
	char grade[100][20];
	char no[100][20];
	char accumpay[100][20];
	ifstream ifile("数据库.txt");										//打开文件
	if(!ifile)
		cout<<"打开文件失败"<<'\n';
	else
		{
			int k;
			for(int l=0;;l++)
				{
					ifile.getline(position[l],100,'\t');				//从文件中依次读出对应的内容
					ifile.getline(name[l],100,'\t');
					ifile.getline(sex[l],100,'\t');
					ifile.getline(no[l],100,'\t');
					ifile.getline(grade[l],100,'\t');
					ifile.getline(accumpay[l],100,'\n');
					if(ifile.peek()==EOF) 
						{k=l;break;}
				}
			cout<<"----------------------------------"<<'\n';			//打印人员信息表封面
			cout<<"|                                |"<<'\n';
			cout<<"|       耘含有限公司员工总览     |"<<'\n';
			cout<<"|                                |"<<'\n';
			cout<<"----------------------------------"<<'\n';
			for(int l=0;l<=k;++l)										//按照已经设置的格式输出
				{
					cout<<"职位:"<<position[l]<<'\n';
					cout<<"姓名:"<<name[l]<<'\n';
					cout<<"性别:"<<sex[l]<<'\n';
					cout<<"编号:"<<no[l]<<'\n';
					cout<<"等级:"<<grade[l]<<'\n';
					cout<<"月薪:"<<accumpay[l]<<'\n';
					cout<<'\n';
				}
		}
}

//查询人员个人信息函数
void search()
{
	char position[100][20];												//根据输出到文件中的格式，来进行设置
	char name[100][20];
	char sex[100][10];
	char grade[100][20];
	char no[100][20];
	char accumpay[100][20];
	ifstream ifile("数据库.txt");										//打开文件
	if(!ifile)
		cout<<"打开文件失败"<<'\n';
	else
		{
			for(int l=0;;++l)
				{
					ifile.getline(position[l],100,'\t');				//从文件中依次读出对应的内容
					ifile.getline(name[l],100,'\t');
					ifile.getline(sex[l],100,'\t');
					ifile.getline(no[l],100,'\t');
					ifile.getline(grade[l],100,'\t');
					ifile.getline(accumpay[l],100,'\n');
					if(ifile.peek()==EOF) break;
				}
			for(int o=0;;++o)											//大循环，可以重复查询
				{
					cout<<"请选择查询方式：(A)姓名/工号(B)"<<'\n';
					char p;
					cin>>p;
					while(p!='B'&&p!='A')								//防出错设置
						{
							cout<<"输入错误，请重新输入A/B:";
							cin>>p;
						}
					if(p=='A')											//姓名查询方式
						{
							char z[20];
							cout<<"请输入姓名:";
							cin>>z;
							for(int l=0;;++l)
								{
									if(strcmp(name[l],z)==0)			//搜索姓名一样的
										{
											cout<<"职位:"<<position[l]<<'\n';//进行输出
											cout<<"姓名:"<<name[l]<<'\n';
											cout<<"性别:"<<sex[l]<<'\n';
											cout<<"编号:"<<no[l]<<'\n';
											cout<<"等级:"<<grade[l]<<'\n';
											cout<<"月薪:"<<accumpay[l]<<'\n';
											break;
										}
									
								 }
						}
					else												//工号查询方式
						{
							char z[5];
							cout<<"请输入工号";
							cin>>z;
							for(int l=0;;++l)
								{
									if(strcmp(no[l],z)==0)				//查找工号相同的
										{
											cout<<"职位:"<<position[l]<<'\n';//进行输出
											cout<<"姓名:"<<name[l]<<'\n';
											cout<<"性别:"<<sex[l]<<'\n';
											cout<<"编号:"<<no[l]<<'\n';
											cout<<"等级:"<<grade[l]<<'\n';
											cout<<"月薪:"<<accumpay[l]<<'\n';
											break;
										}
								}
						}
					cout<<"是否继续查询（Y/N）";						//判断是否出循环
					char l;
					cin>>l;
					while(l!='Y'&&l!='N')								//防出错设置
						{
							cout<<"输入错误，请重新输入Y/N:";
							cin>>l;
						}
					if(l=='N') break;
				}
		}
	ifile.close();
}

//修改人员个人信息函数
void xiugai()
{
	char position[100][20];
	char name[100][20];
	char sex[100][10];
	char grade[100][20];
	char no[100][20];
	char accumpay[100][20];
	ifstream ifile("数据库.txt");
	if(!ifile)
		cout<<"打开文件失败"<<'\n';
	else
		{
			for(int l=0;;++l)
				{
					ifile.getline(position[l],100,'\t');				//从文件中读出相应的内容
					ifile.getline(name[l],100,'\t');
					ifile.getline(sex[l],100,'\t');
					ifile.getline(no[l],100,'\t');
					ifile.getline(grade[l],100,'\t');
					ifile.getline(accumpay[l],100,'\n');
					if(ifile.peek()==EOF) break;
				}
		}
	ifile.close();
	cout<<"请输入您要修改的编号";										//根据工号来修改
	char i[5];
	cin>>i;
	for(int l=0;;++l)
		{
			if(strcmp(no[l],i)==0)										//判断工号
				{
					cout<<"请依次输入职位、姓名、性别、等级、月薪:"<<'\n';
					cin>>position[l]>>name[l]>>sex[l]>>grade[l]>>accumpay[l];
					cout<<"修改成功"<<'\n';
					break;
				}
		}
	ofstream ofile("数据库.txt",ios::out);								//打开文件方式先把文件内东西清空，再把更新的内容输进去
	if(!ofile)
		cout<<"无法打开文件"<<'\n';
	else
		{
			for(int l=0;l<employee::num;++l)
				{
					ofile<<position[l]<<'\t'<<name[l]<<'\t'<<sex[l]<<'\t'<<no[l]<<'\t'<<grade[l]<<'\t'<<accumpay[l]<<'\n';
				}
		}
	ofile.close();														//关闭文件
}

//薪资调整函数
void adjust()
{
	enum Pos {C,M,T,S,S_M};												//枚举类型
	void adjust_manager();												//经理调整函数
	void adjust_CEO();													//CEO调整函数
	void adjust_tech();													//技工调整函数
	void adjust_sales();												//销售调整函数
	void adjust_sales_m();												//销售经理调整函数
	void update();														//更新到数据库
	Pos x;
	for(int j=0;;j++)
		{
			cout<<"您需要修改哪一个职位的薪资(CEO、经理、技工、销售、销售经理):"<<'\n';
			string p;
			cin>>p;
			if(p=="经理") x=M;											//判断是哪一个类型
			if(p=="CEO") x=C;
			if(p=="技工") x=T;
			if(p=="销售") x=S;
			if(p=="销售经理") x=S_M;
			switch(x)													//用选择语句来进行
				{														//调用了五个函数来实现
					case 0:adjust_CEO();break;
					case 1:adjust_manager();break;
					case 2:adjust_tech();break;
					case 3:adjust_sales();break;
					case 4:adjust_sales_m();break;
				}
			cout<<"是否继续修改薪水(Y/N):";								//判断是否出循环
			char a;
			cin>>a;
			while(a!='Y'&&a!='N')										//防出错设置
				{
					cout<<"输入错误，请重新输入:";
					cin>>a;
				}
			if(a=='N') break;
		}
	cout<<"是否将修改的薪水调整到数据库中？(Y/N)";
	char a;
	cin>>a;
	while(a!='Y'&&a!='N')
		{
			cout<<"输入错误，请重新输入:";
			cin>>a;
		}
	if(a=='Y')  update();												//将修改过后的薪资更新到数据库中
}

//修改CEO工资
void adjust_CEO()
{																		
	cout<<"您能修改的是CEO固定薪水,CEO原薪水为:"<<CEO::get_accumpay_c()<<'\n';
	CEO *c;
	c=new CEO;
	c->adjust_accumpay();												//因为动态建立了一个对象，num会+1，但是这个对象时没用的，因此需要手动把num-1
	CEO::num=CEO::num-1;
	cout<<"修改成功"<<'\n';
//	cout<<CEO::get_accumpay_c()<<'\n';
}

//修改经理工资
void adjust_manager()
{
	cout<<"您能修改的是经理的固定薪水，经理原薪水为:"<<manager::get_accumpay_m()<<'\n';
	manager *m;
	m=new manager;
	m->adjust_accumpay();												//因为动态建立了一个对象，num会+1，但是这个对象时没用的，因此需要手动把num-1
	manager::num=manager::num-1;
	cout<<"修改成功"<<'\n';
//	cout<<manager::get_accumpay_m()<<'\n';
}

//修改技工工资
void adjust_tech()
{
	cout<<"您能修改的是技工的每小时薪水，原每小时薪水为:"<<technician::get_accumpay_t()<<'\n';
	technician *t;
	t=new technician;
	t->adjust_accumpay();												//因为动态建立了一个对象，num会+1，但是这个对象时没用的，因此需要手动把num-1
	technician::num=technician::num-1;
	cout<<"修改成功"<<'\n';
//	cout<<technician::get_accumpay_t()<<'\n';
}

//修改销售工资
void adjust_sales()
{
	cout<<"你能修改的是销售的提成比例，原比例为:"<<sales::get_propotion_S()<<'\n';
	sales *s;
	s=new sales;
	s->adjust_accumpay();												//因为动态建立了一个对象，num会+1，但是这个对象时没用的，因此需要手动把num-1
	sales::num=sales::num-1;
	cout<<"修改成功"<<'\n';
//	cout<<sales::get_propotion_S()<<'\n';
}

//修改销售经理工资
void adjust_sales_m()
{
	cout<<"你能修改的是销售经理的提成比例，原比例为:"<<sales_manager::get_propotion_SM()<<'\n';
	sales_manager *s;
	s=new sales_manager;
	s->adjust_accumpay();												//因为动态建立了一个对象，num会+1，但是这个对象时没用的，因此需要手动把num-1
	sales_manager::num=sales_manager::num-1;
	cout<<"修改成功"<<'\n';
//	cout<<sales_manager::get_propotion_SM()<<'\n';
}

void update()
{
	char position[100][20];
	char name[100][20];
	char sex[100][10];
	char grade[100][20];
	char no[100][20];
	char accumpay[100][20];
	double calculate_t(char a[]);										//计算技工改变薪资之后的工资
	double calculate_s(char a[]);										//计算销售改变薪资之后的工资
	double calculate_sm(char a[]);										//计算销售经理改变薪资之后的工资
	ifstream ifile("数据库.txt");
	if(!ifile)
		cout<<"打开文件失败"<<'\n';
	else
		{
			int k;
			for(int l=0;;++l)
				{
					ifile.getline(position[l],100,'\t');				//从文件中读入数据
					ifile.getline(name[l],100,'\t');
					ifile.getline(sex[l],100,'\t');
					ifile.getline(no[l],100,'\t');
					ifile.getline(grade[l],100,'\t');
					ifile.getline(accumpay[l],100,'\n');
					if(ifile.peek()==EOF) 
						{k=l;break;}
				}
			cout<<k<<'\n';
			ofstream ofile("数据库.txt",ios::trunc);
			if(!ofile) 
				cout<<"打开文件失败"<<'\n';
			else
				{
					for(int l=0;l<=k;++l)
						{
							ofile<<position[l]<<'\t'<<name[l]<<'\t'<<sex[l]<<'\t'<<no[l]<<'\t'<<grade[l]<<'\t';
							if(strcmp(position[l],"CEO")==0) ofile<<CEO::get_accumpay_c()<<'\n';
							if(strcmp(position[l],"经理")==0) ofile<<manager::get_accumpay_m()<<'\n';
							if(strcmp(position[l],"技工")==0) ofile<<calculate_t(accumpay[l])<<'\n';
							if(strcmp(position[l],"销售")==0) ofile<<calculate_s(accumpay[l])<<'\n';
							if(strcmp(position[l],"销售经理")==0)  ofile<<calculate_sm(accumpay[l])<<'\n';
						}
				}
			ofile.close();
		}
	ifile.close();
}

double calculate_t(char a[])
{
	double m=atoi(a);												//将字符串数字转换为整型数
	return m/technician::get_accumpay_tpre()*technician::get_accumpay_t();
}

double calculate_s(char a[])
{
	double m=atoi(a);												//将字符串数字转换为整型数
	return m/sales::get_propotion_Spre()*sales::get_propotion_S();
}

double calculate_sm(char a[])
{
	double m=atoi(a);												//将字符串数字转换为整型数
	return (m-manager::get_accumpay_mpre())/sales_manager::get_propotion_SMpre()*sales_manager::get_propotion_SM()+manager::get_accumpay_m();
}