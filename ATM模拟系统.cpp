#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
struct per           //定义结构体
{
	char name[20];
	char ID[20];    
	int money;
	char mima[6];
	struct per * next;
};
typedef struct person    //定义另一结构体
{
    struct per kehu;
    struct person *next;
}L;
void mainUI();                              //main首页UI
void FirstGuide();                          //操作首页UI
void gotoxy(int,int);                       //光标定位函数
void chaxun(struct per *head);              //查询
void kaihu(struct per *head);               //开户
void denglu(struct per *head);              //登录
void caidan(struct per *head);              //菜单
void qukuan(struct per *head);              //取款
void xgmm(struct per *head);                //修改密码
void cunkuan(struct per *head);             //存款
void zhuanzhang(struct per *head);          //转账
void chuangjian(struct person **Phead);     //创建
void shuchu(struct person *Phead);          //输出
void shanchu(struct person **Phead);        //删除
void zengjia(struct person **Phead);        //增加
void chaxun1(struct person *Phead);         //查询1
void chaxun2(struct person *Phead);         //查询2
void chaxun3(struct person *Phead);         //查询3
void tuichu();                              //退出
void menu();                                //后台菜单
void menuUI();                              //后台菜单UI
int lie,hang;

///首页UI
void mainUI()
{
	char ch;
	hang=8;
	lie=30;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	gotoxy(lie,hang);printf("       A             T T T T T T T           M       M");hang++;
	gotoxy(lie,hang);printf("      A A                  T                M M     M M");hang++;
	gotoxy(lie,hang);printf("     AAAAA                 T               M   M   M   M");hang++;
	gotoxy(lie,hang);printf("    A     A                T              M     M M     M");hang++;
	gotoxy(lie,hang);printf("   A       A               T             M       M       M");hang++;
	hang++;hang++;
	lie=60;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	gotoxy(lie,hang);printf("Simulator   By   C language");hang++;hang++;
	lie=30;
	hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(lie,hang);printf("按[Enter]继续");hang++;hang++;
	gotoxy(lie,hang);printf("按[Esc]退出");hang++;hang++;
	ch=getch();
	switch(ch)
	{
		case 13:system("cls");FirstGuide();break;
		case 27:exit(0);break;
		default:system("cls");mainUI();break;
	}
}

///业务导航UI
void FirstGuide()
{
	int lie,hang;
	char ch;
	struct per *head=NULL;        //head为定义一层头指针
	hang=6;
	lie=35;
	gotoxy(lie,hang);printf("**************************************************");hang++;hang++;
	gotoxy(lie,hang);printf(" 欢迎使用ATM模拟软件Welcome to use ATM Simulator ");hang++;hang++;
	gotoxy(lie,hang);printf("**************************************************");hang++;hang++;
	gotoxy(lie,hang);printf(" ————————————————————————");hang++;
	gotoxy(lie,hang);printf("|     请选择您的需求:                            |");hang++;
	gotoxy(lie,hang);printf(" ————————————————————————");hang++;
	gotoxy(lie,hang);printf("|     [1]  开户                                  |");hang++;
	gotoxy(lie,hang);printf(" ————————————————————————");hang++;
	gotoxy(lie,hang);printf("|     [2]  登陆                                  |");hang++;
	gotoxy(lie,hang);printf(" ————————————————————————");hang++;
	gotoxy(lie,hang);printf("|     [3]  后台信息查询                          |");hang++;
	gotoxy(lie,hang);printf(" ————————————————————————");hang++;
	ch=getch();
    switch(ch)
    {
		case 49:system("cls");                                    //1
             kaihu(head);   //调用开户函数
             break;

		case 50:system("cls");                                    //2
             denglu(head);   //调用登陆函数
             break;

		case 51:system("cls");                                    //3
             menu();   //调用后台菜单函数
             break;
	}
}

///光标定位
void gotoxy(int x, int y)
{
   COORD coord = {x, y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

///main函数
void main()
{
	mainUI();
	system("cls");
	FirstGuide();
}

///开户函数
void kaihu(struct per *head)
{
    head=NULL;
    FILE *fp;   //定义文件指针
    struct per *p1=NULL,*p2=NULL;   //p1,p2为定义链表指针
    p1=(struct per*)malloc(sizeof(struct per));  //开辟内存单元
	hang=5;lie=30;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);   //little blue
    gotoxy(lie,hang);printf("请输入您的姓名:");hang++; //请数据输入链表中
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);   //yellow
    gotoxy(lie,hang);scanf("%s",p1->name);hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("请设置您的卡号:");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",p1->ID);hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("请设置您银行卡密码:");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",p1->mima);hang++;
          p1->money=0;
          p1->next=NULL;
		  system("cls");
		  hang=5;lie=30;
		  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
          gotoxy(lie,hang);printf("您的个人信息为");hang++;
          gotoxy(lie,hang);printf("姓名：%s",p1->name);hang++;
		  gotoxy(lie,hang);printf("卡号：%s",p1->ID);hang++;
		  gotoxy(lie,hang);printf("余额：%4d",p1->money);hang++;hang++;
          if(NULL==head)           //为新用户开辟内存单元
          {
              head=(struct per *)malloc(sizeof(struct per));
              head->next=p1;    //进行头插法，将其作为第一个节点
          }
          else    //为新增客户开辟内存单元
          {
              for(p2=head;p2->next!=NULL;p2=p2->next); //进行尾插
              p2->next=p1;
          }
          if((fp=fopen("save.txt","ab+"))==NULL) //打开文件
          {
              printf("cannot poen file\n");
              return;
          }
          if(fwrite(p1,sizeof(struct per),1,fp)!=1)  //将链表信息写入文件中
              printf("file write error\n");
              fclose(fp);
              printf("\n");
			  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
              gotoxy(lie,hang);printf("恭喜您开户成功，请登录");hang++;
              gotoxy(lie,hang);system("pause");
              system("cls");
              denglu(head);
}

///登录函数
void denglu(struct per *head)
{
    char d[20];
    char mima[20];
    int i,j;
    FILE *fp;     //定义文件指针
    struct per *p,*q=NULL;
    if((fp=fopen("save.txt","rb+"))==NULL)   //打开一个二进制文件，为读方式
    {
        printf("不能打开文件\n");   //如不能打开，则结束程序
    }
    p=(struct per*)malloc(sizeof(struct per));   //申请空间
    head=p;
    while(!feof(fp))       //循环读数据直到文件尾结束

    {
        if(1!=fread(p,sizeof(struct per),1,fp))
            break;   //如果没读到数据，跳出循环
        p->next=(struct per *)malloc(sizeof(struct per));  //为下一个结点申请空间
        q=p;  //保存当前节点的指针，作为下一结点的前驱
        p=p->next;  //指针后移，新读入数据链到当前表尾

    }
    q->next=NULL;  //最后一个结点的后继指针为空
    fclose(fp);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	hang=5;lie=30;
    gotoxy(lie,hang);printf("*****************************************************");hang++;
    gotoxy(lie,hang);printf("***欢迎使用ATM模拟软件Welcome to use ATM Simulator***");hang++;
    gotoxy(lie,hang);printf("*****************************************************");hang++;
    for(j=1;j<4;j++)      //限制卡号输入的次数的循环
    {
		hang=8;lie=30;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
        gotoxy(lie,hang);printf("请输入您的卡号");hang++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
        gotoxy(lie,hang);scanf("%s",d);hang++;
        for(q=head;q!=NULL;q=q->next)   //遍历链表
        {
            if(strcmp(q->ID,d)!=0)  //核对账号
            {
				continue;   //跳出循环
            }
            else
			{
				for(i=1;i<4;i++)   //限制密码输入的次数的循环
				{
					hang=10;lie=30;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
					gotoxy(lie,hang);printf("请输入您的密码");hang++;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
					gotoxy(lie,hang);scanf("%s",mima);hang++;
					if(strcmp(q->mima,mima)!=0)      //核对密码
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
						gotoxy(lie,hang);printf("密码不正确。请重新输入密码");hang++;
						gotoxy(lie,hang);system("pause");
						system("cls");
						continue;    //若密码不对，跳出循环
					}
					else
					{
						system("cls");
						caidan(head);   //调用菜单函数
					}
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				gotoxy(lie,hang);printf("您输入密码三次错误，谢谢您的光临");hang++;
				gotoxy(lie,hang);system("pause");hang++;
				system("cls");
				mainUI();
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		gotoxy(lie,hang);printf("您输入的卡号有误，请重试");hang++;
		gotoxy(lie,hang);system("pause");hang++;
		system("cls");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	gotoxy(lie,hang);printf("您的卡号三次输入错误，谢谢使用");hang++;
	gotoxy(lie,hang);system("pause");system("cls");
	mainUI();
}

///用户菜单
void caidan(struct per *head)
{
    head=NULL;
    int i;      //i为客户选择输入
    while(1)
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		lie=30;hang=5;
		gotoxy(lie,hang);printf("**************************************");hang++;
        gotoxy(lie,hang);printf("*请选择您需要的业务:                 *");hang++;
        gotoxy(lie,hang);printf("**************************************");hang++;
        gotoxy(lie,hang);printf("**  [1] 取款   *****   [2] 查询     **");hang++;
        gotoxy(lie,hang);printf("**************************************");hang++;
        gotoxy(lie,hang);printf("**  [3] 转账   *****   [4] 修改密码 **");hang++;
        gotoxy(lie,hang);printf("**************************************");hang++;
        gotoxy(lie,hang);printf("**  [5] 存款   *****   [6] 退出系统 **");hang++;
        gotoxy(lie,hang);printf("**************************************");hang++;
        gotoxy(lie,hang);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		scanf("%d",&i);hang++;
		switch(i)
            {
            case 1:qukuan(head);       //调用银行取款函数
                   system("pause");
                   system("cls");
                   break;
            case 2:system("cls");
                   chaxun(head);  //调用银行查询函数
                   break;
            case 3:system("cls");
                   zhuanzhang(head);  //调用银行转账函数
                   break;
            case 4:system("cls");
                   xgmm(head);  //调用银行修改密码函数
                   break;
            case 5:system("cls");
                   cunkuan(head);  //调用银行存款函数
                   break;
            case 6:system("cls");
                   exit(0);          //退出系统
                   break;
			default:system("cls");   //其他保持这一页
					caidan(head);
					break;
            }
    }
}

///取款函数
void qukuan(struct per *head)
{
    head=NULL;   //head为链表头指针
    int i;
    FILE *fp;          //定义文件指针
    struct per *p,*q=NULL;
    if((fp=fopen("save.txt","rb+"))==NULL) //打开一个二进制文件，为读方式
    {
        printf("不能打开文件\n");  //如不能打开，则结束程序
    }
    p=(struct per*)malloc(sizeof(struct per));  //申请空间
    head=p;
    while(!feof(fp))   //循环读数据直到文件尾结束
    {
        if(1!=fread(p,sizeof(struct per),1,fp))
            break;   //如果没有读到数据，跳出循环
        p->next=(struct per *)malloc(sizeof(struct per));  //为下一个结点申请空间
        q=p;   //保存当前结点的指针，作为下一个结点的前驱
        p=p->next;  //指针后移，新读入数据链到当前表尾
    }
    q->next=NULL;  //最后一个结点的后继指针为空
    fclose(fp);
    system("cls");
	hang=5;lie=30;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("请选择您要取款的金额:");hang++;
	gotoxy(lie,hang);printf("****************************************");hang++;
    gotoxy(lie,hang);printf("**  [1]: 100元    *****    [2]:200元  **");hang++;
    gotoxy(lie,hang);printf("****************************************");hang++;
    gotoxy(lie,hang);printf("**  [3]: 300元    *****    [4]:400元  **");hang++;
    gotoxy(lie,hang);printf("****************************************");hang++;
    gotoxy(lie,hang);printf("**  [5]: 500元    *****    [6]:600元  **");hang++;
    gotoxy(lie,hang);printf("****************************************");hang++;
	gotoxy(lie,hang);printf("**  [0]: 返回业务选择页面             **");hang++;
	gotoxy(lie,hang);printf("****************************************");hang++;
    gotoxy(lie,hang);hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	scanf("%d",&i);
    if(i>6||i<0)                                                     //限制输入范围
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        gotoxy(lie,hang);printf("对不起，您只能选择对应金额");hang++;
		gotoxy(lie,hang);system("pause");
        qukuan(head);
    }
    else
    {
		if(i==0)
		{
			system("cls");
			caidan(head);
		}
		else
		{
			i=100*i;                          //对应选项乘以一百为取款金额
			if(i>q->money)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				gotoxy(lie,hang);printf("对不起，您的金额不足");hang++;
				gotoxy(lie,hang);system("pause");hang++;
				system("cls");
				qukuan(head);   //调用取款函数
			}
			else
			{
				q->money-=i;  //对金额进行处理
				if((fp=fopen("save.txt","wb+"))==NULL)  //打开文件
				{
					printf("cannot open file\n");
					return;
				}
				if(fwrite(q,sizeof(struct per),1,fp)!=1) //将修改的信息重新写入文件
                printf("file write error\n");
				printf("您已经成功取走%d元\n");
				q->next=NULL;
				fclose(fp);    //关闭文件
			}
		}
    }
}

///转账函数
void zhuanzhang(struct per *head)
{
    head=NULL;
    FILE *fp;  //定义文件指针
    struct per *p,*q=NULL;
    if((fp=fopen("save.txt","rb+"))==NULL)  //打开一个二进制文件，为读方式
    {
        printf("不能打开文件\n");  //如不能打开，则结束程序
    }
    p=(struct per*)malloc(sizeof(struct per));   //申请空间
    head=p;
    while(!feof(fp))    //循环读数据直到文件尾结束
    {
        if(1!=fread(p,sizeof(struct per),1,fp))
            break;    //如果没读到数据，跳出循环
        p->next=(struct per *)malloc(sizeof(struct per));  //为下一个结点申请空间
        q=p;   //保存当前结点的指针，作为下一个结点的前驱
        p=p->next;   //指针后移，新读入数据链到当前表尾
    }
    q->next=NULL;   //最后一个结点的后继指针为空
    fclose(fp);
    int i,j,k;
	hang=5;lie=30;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(lie,hang);printf("*****************************");hang++;hang++;
	gotoxy(lie,hang);printf("您正在使用的是转账业务");hang++;hang++;
	gotoxy(lie,hang);printf("*****************************");hang++;hang++;
    gotoxy(lie,hang);printf("请输入目标账户");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%d",&i);hang--;
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("请再次输入目标账户");hang++;   //核对卡号
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%d",&j);hang++;
    if(i!=j)
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        gotoxy(lie,hang);printf("两次账号不同，请重新输入");system("cls");
        zhuanzhang(head);
    }
    else
    {
        system("cls");
		hang=5;lie=30;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		gotoxy(lie,hang);printf("请输入转账金额");hang++;
		gotoxy(lie,hang);printf("************************************");hang++;
		gotoxy(lie,hang);printf("**  1: 100元    *****    2:200元  **");hang++;
		gotoxy(lie,hang);printf("************************************");hang++;
		gotoxy(lie,hang);printf("**  3: 300元    *****    4:400元  **");hang++;
		gotoxy(lie,hang);printf("************************************");hang++;
		gotoxy(lie,hang);printf("**  5: 500元    *****    6:600元  **");hang++;
		gotoxy(lie,hang);printf("************************************");hang++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		gotoxy(lie,hang);scanf("%d",&k);hang++;
		if(k>6||k<=0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			gotoxy(lie,hang);printf("对不起，您的输入有误");system("cls");
			zhuanzhang(head);
		}
		else
		{	
			k=k*100;
			if(k>q->money)    //对余额进行判断
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				gotoxy(lie,hang);printf("对不起，您的余额不足");hang++;
				gotoxy(lie,hang);system("pause");
				system("cls");
				zhuanzhang(head);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				gotoxy(lie,hang);printf("您已成功转账%d元",k);hang++;
				q->money-=k;
				if((fp=fopen("save.txt","wb+"))==NULL)
				{
                printf("cannot open file\n");
                return;
				}
            q->next=NULL;
            fclose(fp);
            gotoxy(lie,hang);system("pause");
            system("cls");
        }
    }
    }
}

///银行查询函数
void chaxun(struct per *head)
{
    head=NULL;  //链表头指针
    FILE *fp;  //定义文件指针
    struct per *p,*q=NULL;
    if((fp=fopen("save.txt","rb+"))==NULL)  //打开一个二进制文件，为读方式
    {
        printf("不能打开文件\n");  //如不能打开，则结束程序
    }
    p=(struct per*)malloc(sizeof(struct per));   //申请空间
    head=p;
    while(!feof(fp))    //循环读数据直到文件尾结束
    {
        if(1!=fread(p,sizeof(struct per),1,fp))
            break;    //如果没读到数据，跳出循环
        p->next=(struct per *)malloc(sizeof(struct per));  //为下一个结点申请空间
        q=p;   //保存当前结点的指针，作为下一个结点的前驱
        p=p->next;   //指针后移，新读入数据链到当前表尾
    }
    q->next=NULL;   //最后一个结点的后继指针为空
    fclose(fp);
	hang=5;lie=30;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("您卡上原有余额");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	gotoxy(lie,hang);printf("%d元",q->money);hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    gotoxy(lie,hang);system("pause");
    system("cls");
}

///修改密码函数
void xgmm(struct per *head)
{
    head=NULL;          //链表头指针
    char mima[20];
    FILE *fp;  //定义文件指针
    struct per *p,*q=NULL;
    if((fp=fopen("save.txt","rb+"))==NULL)  //打开一个二进制文件，为读方式
    {
        printf("不能打开文件\n");  //如不能打开，则结束程序
    }
    p=(struct per*)malloc(sizeof(struct per));   //申请空间
    head=p;
    while(!feof(fp))    //循环读数据直到文件尾结束
    {
        if(1!=fread(p,sizeof(struct per),1,fp))
            break;    //如果没读到数据，跳出循环
        p->next=(struct per *)malloc(sizeof(struct per));  //为下一个结点申请空间
        q=p;   //保存当前结点的指针，作为下一个结点的前驱
        p=p->next;   //指针后移，新读入数据链到当前表尾
    }
    q->next=NULL;   //最后一个结点的后继指针为空
    fclose(fp);
	lie=30;hang=5;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("请输入您的原密码");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",mima);hang++;
    if(strcmp(q->mima,mima)==0)   //核对密码
    {
        {
			hang=7;lie=30;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
            gotoxy(lie,hang);printf("密码正确");hang++;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
            gotoxy(lie,hang);printf("请输入您的新密码:");hang++;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
            gotoxy(lie,hang);scanf("%s",q->mima);hang++;
            if((fp=fopen("save.txt","wb+"))==NULL)  //文件头指针
            {
                printf("cannot open file\n");
            }
            if(fwrite(q,sizeof(struct per),1,fp)!=1)    //将修改的密码重新写入文件
                printf("file write error\n");
            fclose(fp);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
            gotoxy(lie,hang);printf("修改密码成功");
        }
    }
    else
    {
		hang=7;lie=30;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        gotoxy(lie,hang);printf("您输入的密码与原密码不同");hang++;
		gotoxy(lie,hang);system("pause");
        caidan(head);
    }
    q->next=NULL;
}

///存款函数
void cunkuan(struct per *head)
{
    int i;
    head=NULL;   //链表头指针
    FILE *fp;  //定义文件指针
    struct per *p,*q=NULL;
    if((fp=fopen("save.txt","rb+"))==NULL)  //打开一个二进制文件，为读方式
    {
        printf("不能打开文件\n");  //如不能打开，则结束程序
    }
    p=(struct per*)malloc(sizeof(struct per));   //申请空间
    head=p;
    while(!feof(fp))    //循环读数据直到文件尾结束
    {
        if(1!=fread(p,sizeof(struct per),1,fp))
            break;    //如果没读到数据，跳出循环
        p->next=(struct per *)malloc(sizeof(struct per));  //为下一个结点申请空间
        q=p;   //保存当前结点的指针，作为下一个结点的前驱
        p=p->next;   //指针后移，新读入数据链到当前表尾
    }
    q->next=NULL;   //最后一个结点的后继指针为空
    fclose(fp);
    system("cls");
	hang=5;lie=30;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("您卡上原有余额%d元",q->money);hang++;
	gotoxy(lie,hang);printf("请选择您要存入的余额");hang++;
    gotoxy(lie,hang);printf("****************************************");hang++;
    gotoxy(lie,hang);printf("**  [1]: 100元    *****    [2]:200元  **");hang++;
    gotoxy(lie,hang);printf("****************************************");hang++;
    gotoxy(lie,hang);printf("**  [3]: 300元    *****    [4]:400元  **");hang++;
    gotoxy(lie,hang);printf("****************************************");hang++;
    gotoxy(lie,hang);printf("**  [5]: 500元    *****    [6]:600元  **");hang++;
    gotoxy(lie,hang);printf("****************************************");hang++;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%d",&i);hang++;
    if(i>6||i<=0)
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        gotoxy(lie,hang);printf("对不起，您的输入有误");
		system("cls");
        cunkuan(head);
    }
    else
    {
        i=100*i;
        q->money+=i;
        if((fp=fopen("save.txt","wb+"))==NULL)   //打开文件
        {
            printf("cannot open file\n");
        }
        if(fwrite(q,sizeof(struct per),1,fp)!=1)  //将修改的密码重新写入文件
            printf("file write error\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
            gotoxy(lie,hang);printf("您已经成功存取%d元",i);hang++;
            q->next=NULL;
            fclose(fp);
            gotoxy(lie,hang);system("pause");
            system("cls");
    }
}

///退出到主页面
void tuichu()
{
	system("cls");
    mainUI();
}

///后台UI
void menuUI()
{
	int lie,hang;
	hang=5;lie=30;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(lie,hang);printf("****************欢迎使用ATM模拟系统*******************");hang++;
    gotoxy(lie,hang);printf("******************************************************");hang++;
	gotoxy(lie,hang);printf("*请选择您需要的业务:                              ****");hang++;
	gotoxy(lie,hang);printf("******************************************************");hang++;
    gotoxy(lie,hang);printf("**** [1] 建立信息并显示  ******  [2] 卡号查询信息 ****");hang++;
    gotoxy(lie,hang);printf("******************************************************");hang++;
    gotoxy(lie,hang);printf("**** [3] 姓名查询信息    ******  [4] 余额查询信息 ****");hang++;
    gotoxy(lie,hang);printf("******************************************************");hang++;
    gotoxy(lie,hang);printf("**** [5] 删除某卡号信息  ******  [6] 增加新的用户 ****");hang++;
    gotoxy(lie,hang);printf("******************************************************");hang++;
    gotoxy(lie,hang);printf("**** [7] 按余额降序输出  ******  [8] 输出         ****");hang++;
    gotoxy(lie,hang);printf("******************************************************");hang++;
    gotoxy(lie,hang);printf("**** [0] 退出                                     ****");hang++;
    gotoxy(lie,hang);printf("******************************************************");hang++;
}

///后台
void menu()                                       //已修改
{
	int flag=1;
	char ch;
	struct person *Phead=NULL;    //Phead为定义二层头指针
	menuUI();
	while(flag)
    {
        system("cls");
        menuUI();                 //调用后台菜单函数
        ch=getch();
        switch(ch)
        {
        case '1':
			    system("cls");
				chuangjian(&Phead);
				shuchu(Phead); //调用后台输出函数
				system("pause");
				system("cls");
				flag=1;
                break;
        case '2':
				system("cls");
				chaxun1(Phead); //调用后台卡号查询函数
				system("pause");
				system("cls");
				flag=1;
				break;
        case '3':
				system("cls");
				chaxun2(Phead); //调用后台姓名查询函数
				system("pause");
				system("cls");
				flag=1;
				break;
        case '4':
				system("cls");
				chaxun3(Phead); //调用后台余额查询函数
				system("pause");
				system("cls");
				flag=1;
				break;
        case '5':
				system("cls");
				shanchu(&Phead); //调用后台删除用户函数
				system("pause");
				system("cls");
				flag=1;
				break;
        case '6':
				system("cls");
				zengjia(&Phead); //调用后台增加用户函数
				system("pause");
				system("cls");
				flag=1;
				break;
        case '7':
				system("cls");
				shuchu(Phead); //调用后台输出函数函数
				system("pause");
				system("cls");
				flag=1;
                break;
        case '8':
				system("cls");
				shuchu(Phead);
                system("pause");
                system("cls");
				flag=1;
                break;
        case '0':
				flag=0;
                printf("The end.\n");
                break;
        }
    }
}

///后台运行创建链表函数                              //bug bug
void chuangjian(struct person **Phead)  //*(*Phead)为指向结构体指针的地址       
{
    struct person *p,*t;    //定义操作指针
    char n[20];
    char a[20];
    int s;
    if(*Phead) *Phead=NULL;
	hang=5;lie=30;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("请输入卡号 姓名 余额");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	gotoxy(lie,hang);printf("(当预存金额为0时退出,输完此项请按回车)");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("请输入卡号");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",n);hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("请输入姓名");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",a);hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("请输入预存金额");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%d",&s);hang++;
    if(s==0) return;
    p=(L *)malloc(sizeof(L));           //将信息输入链表中
    strcpy(p->kehu.ID,n);
    strcpy(p->kehu.name,a);
    *Phead=p;                           //将指针重新指向头指针
	system("cls");
	hang=6;lie=30;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	gotoxy(lie,hang);printf("(当预存金额为0时退出,输完此项请按回车)");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("请输入卡号");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",n);hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("请输入姓名");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",a); hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("请输入预存金额");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%d",&s);hang++;
    while(s)
    {
        t=p;                        //将p的值赋给t,p又可以储存下一个结点
        p=(L *)malloc(sizeof(L));   //为新结点开辟新的内存
        strcpy(p->kehu.ID,n);
        strcpy(p->kehu.name,a);
        p->kehu.money=s;
        p->next=NULL;
        t->next=p;                   //将p的值接在t(即上一个结点的后面)
		system("cls");
		hang=6;lie=30;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		gotoxy(lie,hang);printf("(当预存金额为0时退出,输完此项请按回车)");hang++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
        gotoxy(lie,hang);printf("请输入卡号");hang++;  //尾插法
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
        gotoxy(lie,hang);scanf("%s",n);hang++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
        gotoxy(lie,hang);printf("请输入姓名");hang++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
        gotoxy(lie,hang);scanf("%s",a);hang++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		gotoxy(lie,hang); printf("请输入预存金额");hang++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
        gotoxy(lie,hang);scanf("%d",&s);hang++;
    }
}

///后台运行输出链表函数
void shuchu(struct person *Phead)
{
	hang=5;lie=30;
	system("cls");
    if(NULL==Phead)
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        gotoxy(lie,hang);printf("没有客户信息可输出！");  //若头指针指向空，则没有客户信息
        return;
    }
    while(Phead)  //遍历输出链表中所有客户信息
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        gotoxy(lie,hang);printf("卡号:%s",Phead->kehu.ID);hang++;
		gotoxy(lie,hang);printf("姓名:%s",Phead->kehu.name);hang++;
		gotoxy(lie,hang);printf("余额:%d",Phead->kehu.money);hang++;hang++;
        Phead=Phead->next;
    }
	gotoxy(lie,hang);
}

///后台运行卡号查询函数
void chaxun1(struct person*Phead)
{
    char m[20];   //定义输入查找客户卡号的变量
	hang=5;lie=30;
    if(NULL==Phead)   //若头指针向空，则没有客户信息
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		gotoxy(lie,hang);printf("没有客户信息可查询！");
		return;
    }
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(lie,hang);printf("请输入要查询的客户卡号：");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	gotoxy(lie,hang);scanf("%s",m);hang++;
    while(NULL!=Phead&&strcmp(Phead->kehu.ID,m)!=0)  //在链表中遍历寻找中，直到链表存在并且卡号核对无误
        Phead=Phead->next;
    if(Phead==NULL)  //若指针指最后指向空，则没有客户信息
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		gotoxy(lie,hang);printf("对不起，没有该用户！");
	}   
    else
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
		gotoxy(lie,hang);printf("您所查询的用户信息如下：");hang++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		gotoxy(lie,hang);printf("卡号:%s",Phead->kehu.ID);hang++;
		gotoxy(lie,hang);printf("姓名:%s",Phead->kehu.name);hang++;
		gotoxy(lie,hang);printf("余额:%d",Phead->kehu.money);hang++;
		gotoxy(lie,hang);
	}

}    //若找到，则输出客户信息

///后台运行姓名查询函数
void chaxun2(struct person *Phead)
{
    char m[20];   //定义输入查找客户卡号的变量
	hang=5;lie=30;
    if(NULL==Phead)   //若头指针向空，则没有客户信息
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		gotoxy(lie,hang);printf("没有客户信息可查询！");
		return;
    }
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("请输入要查询的客户姓名：");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",m);hang++;
    while(NULL!=Phead&&strcmp(Phead->kehu.name,m)!=0)  //在链表中遍历寻找中，直到链表存在并且姓名核对无误
    Phead=Phead->next;
    if(Phead==NULL)  //若指针指最后指向空，则没有客户信息
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		gotoxy(lie,hang);printf("对不起，没有该用户！");
	}   
    else
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
		gotoxy(lie,hang);printf("您所查询的用户信息如下：");hang++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		gotoxy(lie,hang);printf("卡号:%s",Phead->kehu.ID);hang++;
		gotoxy(lie,hang);printf("姓名:%s",Phead->kehu.name);hang++;
		gotoxy(lie,hang);printf("余额:%d",Phead->kehu.money);hang++;
		gotoxy(lie,hang);
	}
}    //若找到，则输出客户信息

///后台运行余额查询函数
void chaxun3(struct person *Phead)
{
    long x;   //定义输入查找客户余额的变量
	hang=5;lie=30;
    if(NULL==Phead)   //若头指针向空，则没有客户信息
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		gotoxy(lie,hang);printf("没有客户信息可查询！");
		return;
    }
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("请输入要查询的客户信息的余额：");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%ld",&x);hang++;
    while(NULL!=Phead&&Phead->kehu.money!=x)  //在链表中遍历寻找中，直到链表存在并且余额核对无误，继续寻找
        Phead=Phead->next;
    if(Phead==NULL)  //若指针指最后指向空，则没有客户信息
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		gotoxy(lie,hang);printf("对不起，没有该客户！");
	}  
    else
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
		gotoxy(lie,hang);printf("您所查询的用户信息如下：");hang++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		gotoxy(lie,hang);printf("卡号:%s",Phead->kehu.ID);hang++;
		gotoxy(lie,hang);printf("姓名:%s",Phead->kehu.name);hang++;
		gotoxy(lie,hang);printf("余额:%d",Phead->kehu.money);hang++;
		gotoxy(lie,hang);
	}
}    //若找到，则输出客户信息

///后台运行删除客户信息函数                        //bug bug bug
void shanchu(struct person **Phead)   //*(*Phead)为指向结构体指针的地址
{
    char k[20];    //定义输入查找客户姓名卡号的变量
    struct person *p=*Phead,*t;
	lie=30;hang=5;
    if(NULL==(*Phead))     //若指针最后指向空，则没有客户信息
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        gotoxy(lie,hang);printf("没有客户信息可删除！");
        return;
    }
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("请输入要删除的客户卡号：");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",k);hang++;
    if(p->kehu.ID==k)  //若第一个客户就是，则让头指针指向下一个结点
        *Phead=(*Phead)->next,free(p);
    else
    {
        while(NULL==p->next&&p->next->kehu.ID!=k)   //遍历寻找，核对客户卡号
            p=p->next;                              //当p->next没指向空，并且客户的卡号还没找到，则继续寻找
        if(p->next==NULL)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			gotoxy(lie,hang);printf("对不起，没有该客户！");hang++;
			gotoxy(lie,hang);
		}
        else
        {
            t=p->next;  //如果找到，则把p->next的值赋给t
            p->next=p->next->next;
        }
    }
}

///后台运行增加用户信息函数
void zengjia(struct person **Phead)  //*(*Phead) 为指向结构体指针的地址
{
    char n[20];   //定义输入增加客户卡号的变量
    char a[20];   //定义输入增加客户姓名的变量
    int s;
    L *p,*t,*k;   //定义操作指针变量
	hang=5;lie=30;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(lie,hang);printf("请输入要插入的客户信息");hang++;
    gotoxy(lie,hang);printf("请输入卡号");hang++;  //尾插法
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",&n);hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("请输入姓名");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",a);hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("请输入预存金额");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%d",&s);hang++;
	gotoxy(lie,hang);
    p=(L *)malloc(sizeof(L));    //开辟空间
        strcpy(p->kehu.ID,a);   //将新的客户信息写入链表
        p->kehu.money=s;
        strcpy(p->kehu.name,n);
        if(NULL==(*Phead))   //如果是空链表，则把新客户信息作为第一个结点
        {
            *Phead=p;   //头插法
            (*Phead)->next=NULL;
            return ;
        }
        else
        {
            p->next=(*Phead);   //头插法
            (*Phead)=p;
        }
}
