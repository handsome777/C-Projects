#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#include"Position.h"
int main()
{
	void shuru();                                                   //ʵ�����뺯��
	void view();                                                    //���ȫ����Ա����
	void search();											        //��������
	void xiugai();													//�޸���Ա��Ϣ����
	void adjust();													//������н����
	int i;
	for(i=0;;i++)
	{																	//����
		cout<<"-------------------------------"<<'\n';
		cout<<"|                             |"<<'\n';
		cout<<"|    �ź���ҵ���¹���ϵͳ     |"<<'\n';
		cout<<"|          ��ӭʹ��           |"<<'\n';
		cout<<"|                             |"<<'\n';
		cout<<"-------------------------------"<<'\n';
		cout<<"          1.Ա������¼��"<<'\n';
		cout<<"          2.���ݿ�����"<<'\n';
		cout<<"          3.Ա����Ϣ��ѯ"<<'\n';
		cout<<"          4.Ա�������޸�"<<'\n';
		cout<<"          5.нˮ����"<<'\n';
		cout<<"          6.�˳�"<<'\n';
		cout<<"********************************"<<'\n';
		int choose;
		cout<<"����Ҫ���ʵ���ţ�"<<'\n';
		cin>>choose;
		switch(choose)													//Ŀ¼
			{case 1:shuru();break;
			 case 2:view();break;
			 case 3:search();break;
			 case 4:xiugai();break;
			 case 5:adjust();break;
			 case 6:cout<<"ллʹ�ã��ټ���"<<'\n';exit(0);}
	}
	return 0;
}

//�������뺯��
void shuru()
{
	ofstream ofile("���ݿ�.txt",ios::app);
	if(!ofile)
		{cout<<"���ļ�ʧ��"<<'\n';
		 abort();}
	else
		{
			for(int l=0;;++l)											//��ѭ��������ʵ�ֲ��ϵ���������
				{cout<<"����Ҫ����Ķ���CEO���������������ۡ����۾���������:"<<'\n';
				 char a[10];
				 int n;
				 cin>>a>>n;
			   	 if(strcmp(a,"����")==0)								//���о�������������
					{
						for(int j=0;j<n;++j)
							{
								manager *m;
								m=new manager;							//��̬����һ�����������
								cin>>*m;
								ofile<<*m;								//������ļ���
								cout<<"¼��ɹ�"<<'\n';
							}
					}
				 if(strcmp(a,"CEO")==0)									//����CEO����������
					{
						for(int j=0;j<n;++j)
							{
								CEO *c;
								c=new CEO;								//��̬����һ��CEO��Ķ���
								cin>>*c;
								ofile<<*c;
								cout<<"¼��ɹ�"<<'\n';
							}
				 	}
				 if(strcmp(a,"����")==0)								//���м�������������
					{
						for(int j=0;j<n;++j)
							{
								technician *t;
								t=new technician;
								cin>>*t;
								ofile<<*t;
								cout<<"¼��ɹ�"<<'\n';
							}
					}
				 if(strcmp(a,"����")==0)								//������������������
					{
							for(int j=0;j<n;++j)
							{
								sales *s;
								s=new sales;
								cin>>*s;
								ofile<<*s;
								cout<<"¼��ɹ�"<<'\n';
							}
					}
				 if(strcmp(a,"���۾���")==0)							//�������۾�����������
					{
						for(int j=0;j<n;++j)
							{
								sales_manager *s;
								s=new sales_manager;
								cin>>*s;
								ofile<<*s;
								cout<<"¼��ɹ�"<<'\n';
							}
					}
				 cout<<"�Ƿ�������루Y/N��:";							//�ж��Ƿ������Ĵ�ѭ��
				 char m;
				 cin>>m;
				 while(m!='Y'&&m!='N')									//�������Ĳ���Y/N����ѭ��ֱ��������ȷ
					{
						cout<<"�����������������Y/N:";
						cin>>m;
					}
				 if(m=='N') break;										//����񶨣����ѭ��������Ŀ¼
			}
		}	 
	ofile.close();
}

//������е���Ա��Ϣ
void view()
{
	char position[100][20];												//����������ļ��еĸ�ʽ������������
	char name[100][20];
	char sex[100][10];
	char grade[100][20];
	char no[100][20];
	char accumpay[100][20];
	ifstream ifile("���ݿ�.txt");										//���ļ�
	if(!ifile)
		cout<<"���ļ�ʧ��"<<'\n';
	else
		{
			int k;
			for(int l=0;;l++)
				{
					ifile.getline(position[l],100,'\t');				//���ļ������ζ�����Ӧ������
					ifile.getline(name[l],100,'\t');
					ifile.getline(sex[l],100,'\t');
					ifile.getline(no[l],100,'\t');
					ifile.getline(grade[l],100,'\t');
					ifile.getline(accumpay[l],100,'\n');
					if(ifile.peek()==EOF) 
						{k=l;break;}
				}
			cout<<"----------------------------------"<<'\n';			//��ӡ��Ա��Ϣ�����
			cout<<"|                                |"<<'\n';
			cout<<"|       �ź����޹�˾Ա������     |"<<'\n';
			cout<<"|                                |"<<'\n';
			cout<<"----------------------------------"<<'\n';
			for(int l=0;l<=k;++l)										//�����Ѿ����õĸ�ʽ���
				{
					cout<<"ְλ:"<<position[l]<<'\n';
					cout<<"����:"<<name[l]<<'\n';
					cout<<"�Ա�:"<<sex[l]<<'\n';
					cout<<"���:"<<no[l]<<'\n';
					cout<<"�ȼ�:"<<grade[l]<<'\n';
					cout<<"��н:"<<accumpay[l]<<'\n';
					cout<<'\n';
				}
		}
}

//��ѯ��Ա������Ϣ����
void search()
{
	char position[100][20];												//����������ļ��еĸ�ʽ������������
	char name[100][20];
	char sex[100][10];
	char grade[100][20];
	char no[100][20];
	char accumpay[100][20];
	ifstream ifile("���ݿ�.txt");										//���ļ�
	if(!ifile)
		cout<<"���ļ�ʧ��"<<'\n';
	else
		{
			for(int l=0;;++l)
				{
					ifile.getline(position[l],100,'\t');				//���ļ������ζ�����Ӧ������
					ifile.getline(name[l],100,'\t');
					ifile.getline(sex[l],100,'\t');
					ifile.getline(no[l],100,'\t');
					ifile.getline(grade[l],100,'\t');
					ifile.getline(accumpay[l],100,'\n');
					if(ifile.peek()==EOF) break;
				}
			for(int o=0;;++o)											//��ѭ���������ظ���ѯ
				{
					cout<<"��ѡ���ѯ��ʽ��(A)����/����(B)"<<'\n';
					char p;
					cin>>p;
					while(p!='B'&&p!='A')								//����������
						{
							cout<<"�����������������A/B:";
							cin>>p;
						}
					if(p=='A')											//������ѯ��ʽ
						{
							char z[20];
							cout<<"����������:";
							cin>>z;
							for(int l=0;;++l)
								{
									if(strcmp(name[l],z)==0)			//��������һ����
										{
											cout<<"ְλ:"<<position[l]<<'\n';//�������
											cout<<"����:"<<name[l]<<'\n';
											cout<<"�Ա�:"<<sex[l]<<'\n';
											cout<<"���:"<<no[l]<<'\n';
											cout<<"�ȼ�:"<<grade[l]<<'\n';
											cout<<"��н:"<<accumpay[l]<<'\n';
											break;
										}
									
								 }
						}
					else												//���Ų�ѯ��ʽ
						{
							char z[5];
							cout<<"�����빤��";
							cin>>z;
							for(int l=0;;++l)
								{
									if(strcmp(no[l],z)==0)				//���ҹ�����ͬ��
										{
											cout<<"ְλ:"<<position[l]<<'\n';//�������
											cout<<"����:"<<name[l]<<'\n';
											cout<<"�Ա�:"<<sex[l]<<'\n';
											cout<<"���:"<<no[l]<<'\n';
											cout<<"�ȼ�:"<<grade[l]<<'\n';
											cout<<"��н:"<<accumpay[l]<<'\n';
											break;
										}
								}
						}
					cout<<"�Ƿ������ѯ��Y/N��";						//�ж��Ƿ��ѭ��
					char l;
					cin>>l;
					while(l!='Y'&&l!='N')								//����������
						{
							cout<<"�����������������Y/N:";
							cin>>l;
						}
					if(l=='N') break;
				}
		}
	ifile.close();
}

//�޸���Ա������Ϣ����
void xiugai()
{
	char position[100][20];
	char name[100][20];
	char sex[100][10];
	char grade[100][20];
	char no[100][20];
	char accumpay[100][20];
	ifstream ifile("���ݿ�.txt");
	if(!ifile)
		cout<<"���ļ�ʧ��"<<'\n';
	else
		{
			for(int l=0;;++l)
				{
					ifile.getline(position[l],100,'\t');				//���ļ��ж�����Ӧ������
					ifile.getline(name[l],100,'\t');
					ifile.getline(sex[l],100,'\t');
					ifile.getline(no[l],100,'\t');
					ifile.getline(grade[l],100,'\t');
					ifile.getline(accumpay[l],100,'\n');
					if(ifile.peek()==EOF) break;
				}
		}
	ifile.close();
	cout<<"��������Ҫ�޸ĵı��";										//���ݹ������޸�
	char i[5];
	cin>>i;
	for(int l=0;;++l)
		{
			if(strcmp(no[l],i)==0)										//�жϹ���
				{
					cout<<"����������ְλ���������Ա𡢵ȼ�����н:"<<'\n';
					cin>>position[l]>>name[l]>>sex[l]>>grade[l]>>accumpay[l];
					cout<<"�޸ĳɹ�"<<'\n';
					break;
				}
		}
	ofstream ofile("���ݿ�.txt",ios::out);								//���ļ���ʽ�Ȱ��ļ��ڶ�����գ��ٰѸ��µ��������ȥ
	if(!ofile)
		cout<<"�޷����ļ�"<<'\n';
	else
		{
			for(int l=0;l<employee::num;++l)
				{
					ofile<<position[l]<<'\t'<<name[l]<<'\t'<<sex[l]<<'\t'<<no[l]<<'\t'<<grade[l]<<'\t'<<accumpay[l]<<'\n';
				}
		}
	ofile.close();														//�ر��ļ�
}

//н�ʵ�������
void adjust()
{
	enum Pos {C,M,T,S,S_M};												//ö������
	void adjust_manager();												//�����������
	void adjust_CEO();													//CEO��������
	void adjust_tech();													//������������
	void adjust_sales();												//���۵�������
	void adjust_sales_m();												//���۾����������
	void update();														//���µ����ݿ�
	Pos x;
	for(int j=0;;j++)
		{
			cout<<"����Ҫ�޸���һ��ְλ��н��(CEO���������������ۡ����۾���):"<<'\n';
			string p;
			cin>>p;
			if(p=="����") x=M;											//�ж�����һ������
			if(p=="CEO") x=C;
			if(p=="����") x=T;
			if(p=="����") x=S;
			if(p=="���۾���") x=S_M;
			switch(x)													//��ѡ�����������
				{														//���������������ʵ��
					case 0:adjust_CEO();break;
					case 1:adjust_manager();break;
					case 2:adjust_tech();break;
					case 3:adjust_sales();break;
					case 4:adjust_sales_m();break;
				}
			cout<<"�Ƿ�����޸�нˮ(Y/N):";								//�ж��Ƿ��ѭ��
			char a;
			cin>>a;
			while(a!='Y'&&a!='N')										//����������
				{
					cout<<"�����������������:";
					cin>>a;
				}
			if(a=='N') break;
		}
	cout<<"�Ƿ��޸ĵ�нˮ���������ݿ��У�(Y/N)";
	char a;
	cin>>a;
	while(a!='Y'&&a!='N')
		{
			cout<<"�����������������:";
			cin>>a;
		}
	if(a=='Y')  update();												//���޸Ĺ����н�ʸ��µ����ݿ���
}

//�޸�CEO����
void adjust_CEO()
{																		
	cout<<"�����޸ĵ���CEO�̶�нˮ,CEOԭнˮΪ:"<<CEO::get_accumpay_c()<<'\n';
	CEO *c;
	c=new CEO;
	c->adjust_accumpay();												//��Ϊ��̬������һ������num��+1�������������ʱû�õģ������Ҫ�ֶ���num-1
	CEO::num=CEO::num-1;
	cout<<"�޸ĳɹ�"<<'\n';
//	cout<<CEO::get_accumpay_c()<<'\n';
}

//�޸ľ�����
void adjust_manager()
{
	cout<<"�����޸ĵ��Ǿ���Ĺ̶�нˮ������ԭнˮΪ:"<<manager::get_accumpay_m()<<'\n';
	manager *m;
	m=new manager;
	m->adjust_accumpay();												//��Ϊ��̬������һ������num��+1�������������ʱû�õģ������Ҫ�ֶ���num-1
	manager::num=manager::num-1;
	cout<<"�޸ĳɹ�"<<'\n';
//	cout<<manager::get_accumpay_m()<<'\n';
}

//�޸ļ�������
void adjust_tech()
{
	cout<<"�����޸ĵ��Ǽ�����ÿСʱнˮ��ԭÿСʱнˮΪ:"<<technician::get_accumpay_t()<<'\n';
	technician *t;
	t=new technician;
	t->adjust_accumpay();												//��Ϊ��̬������һ������num��+1�������������ʱû�õģ������Ҫ�ֶ���num-1
	technician::num=technician::num-1;
	cout<<"�޸ĳɹ�"<<'\n';
//	cout<<technician::get_accumpay_t()<<'\n';
}

//�޸����۹���
void adjust_sales()
{
	cout<<"�����޸ĵ������۵���ɱ�����ԭ����Ϊ:"<<sales::get_propotion_S()<<'\n';
	sales *s;
	s=new sales;
	s->adjust_accumpay();												//��Ϊ��̬������һ������num��+1�������������ʱû�õģ������Ҫ�ֶ���num-1
	sales::num=sales::num-1;
	cout<<"�޸ĳɹ�"<<'\n';
//	cout<<sales::get_propotion_S()<<'\n';
}

//�޸����۾�����
void adjust_sales_m()
{
	cout<<"�����޸ĵ������۾������ɱ�����ԭ����Ϊ:"<<sales_manager::get_propotion_SM()<<'\n';
	sales_manager *s;
	s=new sales_manager;
	s->adjust_accumpay();												//��Ϊ��̬������һ������num��+1�������������ʱû�õģ������Ҫ�ֶ���num-1
	sales_manager::num=sales_manager::num-1;
	cout<<"�޸ĳɹ�"<<'\n';
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
	double calculate_t(char a[]);										//���㼼���ı�н��֮��Ĺ���
	double calculate_s(char a[]);										//�������۸ı�н��֮��Ĺ���
	double calculate_sm(char a[]);										//�������۾���ı�н��֮��Ĺ���
	ifstream ifile("���ݿ�.txt");
	if(!ifile)
		cout<<"���ļ�ʧ��"<<'\n';
	else
		{
			int k;
			for(int l=0;;++l)
				{
					ifile.getline(position[l],100,'\t');				//���ļ��ж�������
					ifile.getline(name[l],100,'\t');
					ifile.getline(sex[l],100,'\t');
					ifile.getline(no[l],100,'\t');
					ifile.getline(grade[l],100,'\t');
					ifile.getline(accumpay[l],100,'\n');
					if(ifile.peek()==EOF) 
						{k=l;break;}
				}
			cout<<k<<'\n';
			ofstream ofile("���ݿ�.txt",ios::trunc);
			if(!ofile) 
				cout<<"���ļ�ʧ��"<<'\n';
			else
				{
					for(int l=0;l<=k;++l)
						{
							ofile<<position[l]<<'\t'<<name[l]<<'\t'<<sex[l]<<'\t'<<no[l]<<'\t'<<grade[l]<<'\t';
							if(strcmp(position[l],"CEO")==0) ofile<<CEO::get_accumpay_c()<<'\n';
							if(strcmp(position[l],"����")==0) ofile<<manager::get_accumpay_m()<<'\n';
							if(strcmp(position[l],"����")==0) ofile<<calculate_t(accumpay[l])<<'\n';
							if(strcmp(position[l],"����")==0) ofile<<calculate_s(accumpay[l])<<'\n';
							if(strcmp(position[l],"���۾���")==0)  ofile<<calculate_sm(accumpay[l])<<'\n';
						}
				}
			ofile.close();
		}
	ifile.close();
}

double calculate_t(char a[])
{
	double m=atoi(a);												//���ַ�������ת��Ϊ������
	return m/technician::get_accumpay_tpre()*technician::get_accumpay_t();
}

double calculate_s(char a[])
{
	double m=atoi(a);												//���ַ�������ת��Ϊ������
	return m/sales::get_propotion_Spre()*sales::get_propotion_S();
}

double calculate_sm(char a[])
{
	double m=atoi(a);												//���ַ�������ת��Ϊ������
	return (m-manager::get_accumpay_mpre())/sales_manager::get_propotion_SMpre()*sales_manager::get_propotion_SM()+manager::get_accumpay_m();
}