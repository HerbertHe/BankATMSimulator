#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
struct per           //����ṹ��
{
	char name[20];
	char ID[20];    
	int money;
	char mima[6];
	struct per * next;
};
typedef struct person    //������һ�ṹ��
{
    struct per kehu;
    struct person *next;
}L;
void mainUI();                              //main��ҳUI
void FirstGuide();                          //������ҳUI
void gotoxy(int,int);                       //��궨λ����
void chaxun(struct per *head);              //��ѯ
void kaihu(struct per *head);               //����
void denglu(struct per *head);              //��¼
void caidan(struct per *head);              //�˵�
void qukuan(struct per *head);              //ȡ��
void xgmm(struct per *head);                //�޸�����
void cunkuan(struct per *head);             //���
void zhuanzhang(struct per *head);          //ת��
void chuangjian(struct person **Phead);     //����
void shuchu(struct person *Phead);          //���
void shanchu(struct person **Phead);        //ɾ��
void zengjia(struct person **Phead);        //����
void chaxun1(struct person *Phead);         //��ѯ1
void chaxun2(struct person *Phead);         //��ѯ2
void chaxun3(struct person *Phead);         //��ѯ3
void tuichu();                              //�˳�
void menu();                                //��̨�˵�
void menuUI();                              //��̨�˵�UI
int lie,hang;

///��ҳUI
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
	gotoxy(lie,hang);printf("��[Enter]����");hang++;hang++;
	gotoxy(lie,hang);printf("��[Esc]�˳�");hang++;hang++;
	ch=getch();
	switch(ch)
	{
		case 13:system("cls");FirstGuide();break;
		case 27:exit(0);break;
		default:system("cls");mainUI();break;
	}
}

///ҵ�񵼺�UI
void FirstGuide()
{
	int lie,hang;
	char ch;
	struct per *head=NULL;        //headΪ����һ��ͷָ��
	hang=6;
	lie=35;
	gotoxy(lie,hang);printf("**************************************************");hang++;hang++;
	gotoxy(lie,hang);printf(" ��ӭʹ��ATMģ�����Welcome to use ATM Simulator ");hang++;hang++;
	gotoxy(lie,hang);printf("**************************************************");hang++;hang++;
	gotoxy(lie,hang);printf(" ������������������������������������������������");hang++;
	gotoxy(lie,hang);printf("|     ��ѡ����������:                            |");hang++;
	gotoxy(lie,hang);printf(" ������������������������������������������������");hang++;
	gotoxy(lie,hang);printf("|     [1]  ����                                  |");hang++;
	gotoxy(lie,hang);printf(" ������������������������������������������������");hang++;
	gotoxy(lie,hang);printf("|     [2]  ��½                                  |");hang++;
	gotoxy(lie,hang);printf(" ������������������������������������������������");hang++;
	gotoxy(lie,hang);printf("|     [3]  ��̨��Ϣ��ѯ                          |");hang++;
	gotoxy(lie,hang);printf(" ������������������������������������������������");hang++;
	ch=getch();
    switch(ch)
    {
		case 49:system("cls");                                    //1
             kaihu(head);   //���ÿ�������
             break;

		case 50:system("cls");                                    //2
             denglu(head);   //���õ�½����
             break;

		case 51:system("cls");                                    //3
             menu();   //���ú�̨�˵�����
             break;
	}
}

///��궨λ
void gotoxy(int x, int y)
{
   COORD coord = {x, y};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

///main����
void main()
{
	mainUI();
	system("cls");
	FirstGuide();
}

///��������
void kaihu(struct per *head)
{
    head=NULL;
    FILE *fp;   //�����ļ�ָ��
    struct per *p1=NULL,*p2=NULL;   //p1,p2Ϊ��������ָ��
    p1=(struct per*)malloc(sizeof(struct per));  //�����ڴ浥Ԫ
	hang=5;lie=30;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);   //little blue
    gotoxy(lie,hang);printf("��������������:");hang++; //����������������
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);   //yellow
    gotoxy(lie,hang);scanf("%s",p1->name);hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("���������Ŀ���:");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",p1->ID);hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("�����������п�����:");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",p1->mima);hang++;
          p1->money=0;
          p1->next=NULL;
		  system("cls");
		  hang=5;lie=30;
		  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
          gotoxy(lie,hang);printf("���ĸ�����ϢΪ");hang++;
          gotoxy(lie,hang);printf("������%s",p1->name);hang++;
		  gotoxy(lie,hang);printf("���ţ�%s",p1->ID);hang++;
		  gotoxy(lie,hang);printf("��%4d",p1->money);hang++;hang++;
          if(NULL==head)           //Ϊ���û������ڴ浥Ԫ
          {
              head=(struct per *)malloc(sizeof(struct per));
              head->next=p1;    //����ͷ�巨��������Ϊ��һ���ڵ�
          }
          else    //Ϊ�����ͻ������ڴ浥Ԫ
          {
              for(p2=head;p2->next!=NULL;p2=p2->next); //����β��
              p2->next=p1;
          }
          if((fp=fopen("save.txt","ab+"))==NULL) //���ļ�
          {
              printf("cannot poen file\n");
              return;
          }
          if(fwrite(p1,sizeof(struct per),1,fp)!=1)  //��������Ϣд���ļ���
              printf("file write error\n");
              fclose(fp);
              printf("\n");
			  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
              gotoxy(lie,hang);printf("��ϲ�������ɹ������¼");hang++;
              gotoxy(lie,hang);system("pause");
              system("cls");
              denglu(head);
}

///��¼����
void denglu(struct per *head)
{
    char d[20];
    char mima[20];
    int i,j;
    FILE *fp;     //�����ļ�ָ��
    struct per *p,*q=NULL;
    if((fp=fopen("save.txt","rb+"))==NULL)   //��һ���������ļ���Ϊ����ʽ
    {
        printf("���ܴ��ļ�\n");   //�粻�ܴ򿪣����������
    }
    p=(struct per*)malloc(sizeof(struct per));   //����ռ�
    head=p;
    while(!feof(fp))       //ѭ��������ֱ���ļ�β����

    {
        if(1!=fread(p,sizeof(struct per),1,fp))
            break;   //���û�������ݣ�����ѭ��
        p->next=(struct per *)malloc(sizeof(struct per));  //Ϊ��һ���������ռ�
        q=p;  //���浱ǰ�ڵ��ָ�룬��Ϊ��һ����ǰ��
        p=p->next;  //ָ����ƣ��¶�������������ǰ��β

    }
    q->next=NULL;  //���һ�����ĺ��ָ��Ϊ��
    fclose(fp);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	hang=5;lie=30;
    gotoxy(lie,hang);printf("*****************************************************");hang++;
    gotoxy(lie,hang);printf("***��ӭʹ��ATMģ�����Welcome to use ATM Simulator***");hang++;
    gotoxy(lie,hang);printf("*****************************************************");hang++;
    for(j=1;j<4;j++)      //���ƿ�������Ĵ�����ѭ��
    {
		hang=8;lie=30;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
        gotoxy(lie,hang);printf("���������Ŀ���");hang++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
        gotoxy(lie,hang);scanf("%s",d);hang++;
        for(q=head;q!=NULL;q=q->next)   //��������
        {
            if(strcmp(q->ID,d)!=0)  //�˶��˺�
            {
				continue;   //����ѭ��
            }
            else
			{
				for(i=1;i<4;i++)   //������������Ĵ�����ѭ��
				{
					hang=10;lie=30;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
					gotoxy(lie,hang);printf("��������������");hang++;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
					gotoxy(lie,hang);scanf("%s",mima);hang++;
					if(strcmp(q->mima,mima)!=0)      //�˶�����
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
						gotoxy(lie,hang);printf("���벻��ȷ����������������");hang++;
						gotoxy(lie,hang);system("pause");
						system("cls");
						continue;    //�����벻�ԣ�����ѭ��
					}
					else
					{
						system("cls");
						caidan(head);   //���ò˵�����
					}
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				gotoxy(lie,hang);printf("�������������δ���лл���Ĺ���");hang++;
				gotoxy(lie,hang);system("pause");hang++;
				system("cls");
				mainUI();
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		gotoxy(lie,hang);printf("������Ŀ�������������");hang++;
		gotoxy(lie,hang);system("pause");hang++;
		system("cls");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	gotoxy(lie,hang);printf("���Ŀ��������������ллʹ��");hang++;
	gotoxy(lie,hang);system("pause");system("cls");
	mainUI();
}

///�û��˵�
void caidan(struct per *head)
{
    head=NULL;
    int i;      //iΪ�ͻ�ѡ������
    while(1)
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		lie=30;hang=5;
		gotoxy(lie,hang);printf("**************************************");hang++;
        gotoxy(lie,hang);printf("*��ѡ������Ҫ��ҵ��:                 *");hang++;
        gotoxy(lie,hang);printf("**************************************");hang++;
        gotoxy(lie,hang);printf("**  [1] ȡ��   *****   [2] ��ѯ     **");hang++;
        gotoxy(lie,hang);printf("**************************************");hang++;
        gotoxy(lie,hang);printf("**  [3] ת��   *****   [4] �޸����� **");hang++;
        gotoxy(lie,hang);printf("**************************************");hang++;
        gotoxy(lie,hang);printf("**  [5] ���   *****   [6] �˳�ϵͳ **");hang++;
        gotoxy(lie,hang);printf("**************************************");hang++;
        gotoxy(lie,hang);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		scanf("%d",&i);hang++;
		switch(i)
            {
            case 1:qukuan(head);       //��������ȡ���
                   system("pause");
                   system("cls");
                   break;
            case 2:system("cls");
                   chaxun(head);  //�������в�ѯ����
                   break;
            case 3:system("cls");
                   zhuanzhang(head);  //��������ת�˺���
                   break;
            case 4:system("cls");
                   xgmm(head);  //���������޸����뺯��
                   break;
            case 5:system("cls");
                   cunkuan(head);  //�������д���
                   break;
            case 6:system("cls");
                   exit(0);          //�˳�ϵͳ
                   break;
			default:system("cls");   //����������һҳ
					caidan(head);
					break;
            }
    }
}

///ȡ���
void qukuan(struct per *head)
{
    head=NULL;   //headΪ����ͷָ��
    int i;
    FILE *fp;          //�����ļ�ָ��
    struct per *p,*q=NULL;
    if((fp=fopen("save.txt","rb+"))==NULL) //��һ���������ļ���Ϊ����ʽ
    {
        printf("���ܴ��ļ�\n");  //�粻�ܴ򿪣����������
    }
    p=(struct per*)malloc(sizeof(struct per));  //����ռ�
    head=p;
    while(!feof(fp))   //ѭ��������ֱ���ļ�β����
    {
        if(1!=fread(p,sizeof(struct per),1,fp))
            break;   //���û�ж������ݣ�����ѭ��
        p->next=(struct per *)malloc(sizeof(struct per));  //Ϊ��һ���������ռ�
        q=p;   //���浱ǰ����ָ�룬��Ϊ��һ������ǰ��
        p=p->next;  //ָ����ƣ��¶�������������ǰ��β
    }
    q->next=NULL;  //���һ�����ĺ��ָ��Ϊ��
    fclose(fp);
    system("cls");
	hang=5;lie=30;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("��ѡ����Ҫȡ��Ľ��:");hang++;
	gotoxy(lie,hang);printf("****************************************");hang++;
    gotoxy(lie,hang);printf("**  [1]: 100Ԫ    *****    [2]:200Ԫ  **");hang++;
    gotoxy(lie,hang);printf("****************************************");hang++;
    gotoxy(lie,hang);printf("**  [3]: 300Ԫ    *****    [4]:400Ԫ  **");hang++;
    gotoxy(lie,hang);printf("****************************************");hang++;
    gotoxy(lie,hang);printf("**  [5]: 500Ԫ    *****    [6]:600Ԫ  **");hang++;
    gotoxy(lie,hang);printf("****************************************");hang++;
	gotoxy(lie,hang);printf("**  [0]: ����ҵ��ѡ��ҳ��             **");hang++;
	gotoxy(lie,hang);printf("****************************************");hang++;
    gotoxy(lie,hang);hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	scanf("%d",&i);
    if(i>6||i<0)                                                     //�������뷶Χ
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        gotoxy(lie,hang);printf("�Բ�����ֻ��ѡ���Ӧ���");hang++;
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
			i=100*i;                          //��Ӧѡ�����һ��Ϊȡ����
			if(i>q->money)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				gotoxy(lie,hang);printf("�Բ������Ľ���");hang++;
				gotoxy(lie,hang);system("pause");hang++;
				system("cls");
				qukuan(head);   //����ȡ���
			}
			else
			{
				q->money-=i;  //�Խ����д���
				if((fp=fopen("save.txt","wb+"))==NULL)  //���ļ�
				{
					printf("cannot open file\n");
					return;
				}
				if(fwrite(q,sizeof(struct per),1,fp)!=1) //���޸ĵ���Ϣ����д���ļ�
                printf("file write error\n");
				printf("���Ѿ��ɹ�ȡ��%dԪ\n");
				q->next=NULL;
				fclose(fp);    //�ر��ļ�
			}
		}
    }
}

///ת�˺���
void zhuanzhang(struct per *head)
{
    head=NULL;
    FILE *fp;  //�����ļ�ָ��
    struct per *p,*q=NULL;
    if((fp=fopen("save.txt","rb+"))==NULL)  //��һ���������ļ���Ϊ����ʽ
    {
        printf("���ܴ��ļ�\n");  //�粻�ܴ򿪣����������
    }
    p=(struct per*)malloc(sizeof(struct per));   //����ռ�
    head=p;
    while(!feof(fp))    //ѭ��������ֱ���ļ�β����
    {
        if(1!=fread(p,sizeof(struct per),1,fp))
            break;    //���û�������ݣ�����ѭ��
        p->next=(struct per *)malloc(sizeof(struct per));  //Ϊ��һ���������ռ�
        q=p;   //���浱ǰ����ָ�룬��Ϊ��һ������ǰ��
        p=p->next;   //ָ����ƣ��¶�������������ǰ��β
    }
    q->next=NULL;   //���һ�����ĺ��ָ��Ϊ��
    fclose(fp);
    int i,j,k;
	hang=5;lie=30;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(lie,hang);printf("*****************************");hang++;hang++;
	gotoxy(lie,hang);printf("������ʹ�õ���ת��ҵ��");hang++;hang++;
	gotoxy(lie,hang);printf("*****************************");hang++;hang++;
    gotoxy(lie,hang);printf("������Ŀ���˻�");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%d",&i);hang--;
	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("���ٴ�����Ŀ���˻�");hang++;   //�˶Կ���
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%d",&j);hang++;
    if(i!=j)
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        gotoxy(lie,hang);printf("�����˺Ų�ͬ������������");system("cls");
        zhuanzhang(head);
    }
    else
    {
        system("cls");
		hang=5;lie=30;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		gotoxy(lie,hang);printf("������ת�˽��");hang++;
		gotoxy(lie,hang);printf("************************************");hang++;
		gotoxy(lie,hang);printf("**  1: 100Ԫ    *****    2:200Ԫ  **");hang++;
		gotoxy(lie,hang);printf("************************************");hang++;
		gotoxy(lie,hang);printf("**  3: 300Ԫ    *****    4:400Ԫ  **");hang++;
		gotoxy(lie,hang);printf("************************************");hang++;
		gotoxy(lie,hang);printf("**  5: 500Ԫ    *****    6:600Ԫ  **");hang++;
		gotoxy(lie,hang);printf("************************************");hang++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		gotoxy(lie,hang);scanf("%d",&k);hang++;
		if(k>6||k<=0)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			gotoxy(lie,hang);printf("�Բ���������������");system("cls");
			zhuanzhang(head);
		}
		else
		{	
			k=k*100;
			if(k>q->money)    //���������ж�
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				gotoxy(lie,hang);printf("�Բ�����������");hang++;
				gotoxy(lie,hang);system("pause");
				system("cls");
				zhuanzhang(head);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
				gotoxy(lie,hang);printf("���ѳɹ�ת��%dԪ",k);hang++;
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

///���в�ѯ����
void chaxun(struct per *head)
{
    head=NULL;  //����ͷָ��
    FILE *fp;  //�����ļ�ָ��
    struct per *p,*q=NULL;
    if((fp=fopen("save.txt","rb+"))==NULL)  //��һ���������ļ���Ϊ����ʽ
    {
        printf("���ܴ��ļ�\n");  //�粻�ܴ򿪣����������
    }
    p=(struct per*)malloc(sizeof(struct per));   //����ռ�
    head=p;
    while(!feof(fp))    //ѭ��������ֱ���ļ�β����
    {
        if(1!=fread(p,sizeof(struct per),1,fp))
            break;    //���û�������ݣ�����ѭ��
        p->next=(struct per *)malloc(sizeof(struct per));  //Ϊ��һ���������ռ�
        q=p;   //���浱ǰ����ָ�룬��Ϊ��һ������ǰ��
        p=p->next;   //ָ����ƣ��¶�������������ǰ��β
    }
    q->next=NULL;   //���һ�����ĺ��ָ��Ϊ��
    fclose(fp);
	hang=5;lie=30;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("������ԭ�����");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	gotoxy(lie,hang);printf("%dԪ",q->money);hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
    gotoxy(lie,hang);system("pause");
    system("cls");
}

///�޸����뺯��
void xgmm(struct per *head)
{
    head=NULL;          //����ͷָ��
    char mima[20];
    FILE *fp;  //�����ļ�ָ��
    struct per *p,*q=NULL;
    if((fp=fopen("save.txt","rb+"))==NULL)  //��һ���������ļ���Ϊ����ʽ
    {
        printf("���ܴ��ļ�\n");  //�粻�ܴ򿪣����������
    }
    p=(struct per*)malloc(sizeof(struct per));   //����ռ�
    head=p;
    while(!feof(fp))    //ѭ��������ֱ���ļ�β����
    {
        if(1!=fread(p,sizeof(struct per),1,fp))
            break;    //���û�������ݣ�����ѭ��
        p->next=(struct per *)malloc(sizeof(struct per));  //Ϊ��һ���������ռ�
        q=p;   //���浱ǰ����ָ�룬��Ϊ��һ������ǰ��
        p=p->next;   //ָ����ƣ��¶�������������ǰ��β
    }
    q->next=NULL;   //���һ�����ĺ��ָ��Ϊ��
    fclose(fp);
	lie=30;hang=5;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("����������ԭ����");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",mima);hang++;
    if(strcmp(q->mima,mima)==0)   //�˶�����
    {
        {
			hang=7;lie=30;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
            gotoxy(lie,hang);printf("������ȷ");hang++;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
            gotoxy(lie,hang);printf("����������������:");hang++;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
            gotoxy(lie,hang);scanf("%s",q->mima);hang++;
            if((fp=fopen("save.txt","wb+"))==NULL)  //�ļ�ͷָ��
            {
                printf("cannot open file\n");
            }
            if(fwrite(q,sizeof(struct per),1,fp)!=1)    //���޸ĵ���������д���ļ�
                printf("file write error\n");
            fclose(fp);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
            gotoxy(lie,hang);printf("�޸�����ɹ�");
        }
    }
    else
    {
		hang=7;lie=30;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        gotoxy(lie,hang);printf("�������������ԭ���벻ͬ");hang++;
		gotoxy(lie,hang);system("pause");
        caidan(head);
    }
    q->next=NULL;
}

///����
void cunkuan(struct per *head)
{
    int i;
    head=NULL;   //����ͷָ��
    FILE *fp;  //�����ļ�ָ��
    struct per *p,*q=NULL;
    if((fp=fopen("save.txt","rb+"))==NULL)  //��һ���������ļ���Ϊ����ʽ
    {
        printf("���ܴ��ļ�\n");  //�粻�ܴ򿪣����������
    }
    p=(struct per*)malloc(sizeof(struct per));   //����ռ�
    head=p;
    while(!feof(fp))    //ѭ��������ֱ���ļ�β����
    {
        if(1!=fread(p,sizeof(struct per),1,fp))
            break;    //���û�������ݣ�����ѭ��
        p->next=(struct per *)malloc(sizeof(struct per));  //Ϊ��һ���������ռ�
        q=p;   //���浱ǰ����ָ�룬��Ϊ��һ������ǰ��
        p=p->next;   //ָ����ƣ��¶�������������ǰ��β
    }
    q->next=NULL;   //���һ�����ĺ��ָ��Ϊ��
    fclose(fp);
    system("cls");
	hang=5;lie=30;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("������ԭ�����%dԪ",q->money);hang++;
	gotoxy(lie,hang);printf("��ѡ����Ҫ��������");hang++;
    gotoxy(lie,hang);printf("****************************************");hang++;
    gotoxy(lie,hang);printf("**  [1]: 100Ԫ    *****    [2]:200Ԫ  **");hang++;
    gotoxy(lie,hang);printf("****************************************");hang++;
    gotoxy(lie,hang);printf("**  [3]: 300Ԫ    *****    [4]:400Ԫ  **");hang++;
    gotoxy(lie,hang);printf("****************************************");hang++;
    gotoxy(lie,hang);printf("**  [5]: 500Ԫ    *****    [6]:600Ԫ  **");hang++;
    gotoxy(lie,hang);printf("****************************************");hang++;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%d",&i);hang++;
    if(i>6||i<=0)
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        gotoxy(lie,hang);printf("�Բ���������������");
		system("cls");
        cunkuan(head);
    }
    else
    {
        i=100*i;
        q->money+=i;
        if((fp=fopen("save.txt","wb+"))==NULL)   //���ļ�
        {
            printf("cannot open file\n");
        }
        if(fwrite(q,sizeof(struct per),1,fp)!=1)  //���޸ĵ���������д���ļ�
            printf("file write error\n");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
            gotoxy(lie,hang);printf("���Ѿ��ɹ���ȡ%dԪ",i);hang++;
            q->next=NULL;
            fclose(fp);
            gotoxy(lie,hang);system("pause");
            system("cls");
    }
}

///�˳�����ҳ��
void tuichu()
{
	system("cls");
    mainUI();
}

///��̨UI
void menuUI()
{
	int lie,hang;
	hang=5;lie=30;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(lie,hang);printf("****************��ӭʹ��ATMģ��ϵͳ*******************");hang++;
    gotoxy(lie,hang);printf("******************************************************");hang++;
	gotoxy(lie,hang);printf("*��ѡ������Ҫ��ҵ��:                              ****");hang++;
	gotoxy(lie,hang);printf("******************************************************");hang++;
    gotoxy(lie,hang);printf("**** [1] ������Ϣ����ʾ  ******  [2] ���Ų�ѯ��Ϣ ****");hang++;
    gotoxy(lie,hang);printf("******************************************************");hang++;
    gotoxy(lie,hang);printf("**** [3] ������ѯ��Ϣ    ******  [4] ����ѯ��Ϣ ****");hang++;
    gotoxy(lie,hang);printf("******************************************************");hang++;
    gotoxy(lie,hang);printf("**** [5] ɾ��ĳ������Ϣ  ******  [6] �����µ��û� ****");hang++;
    gotoxy(lie,hang);printf("******************************************************");hang++;
    gotoxy(lie,hang);printf("**** [7] ���������  ******  [8] ���         ****");hang++;
    gotoxy(lie,hang);printf("******************************************************");hang++;
    gotoxy(lie,hang);printf("**** [0] �˳�                                     ****");hang++;
    gotoxy(lie,hang);printf("******************************************************");hang++;
}

///��̨
void menu()                                       //���޸�
{
	int flag=1;
	char ch;
	struct person *Phead=NULL;    //PheadΪ�������ͷָ��
	menuUI();
	while(flag)
    {
        system("cls");
        menuUI();                 //���ú�̨�˵�����
        ch=getch();
        switch(ch)
        {
        case '1':
			    system("cls");
				chuangjian(&Phead);
				shuchu(Phead); //���ú�̨�������
				system("pause");
				system("cls");
				flag=1;
                break;
        case '2':
				system("cls");
				chaxun1(Phead); //���ú�̨���Ų�ѯ����
				system("pause");
				system("cls");
				flag=1;
				break;
        case '3':
				system("cls");
				chaxun2(Phead); //���ú�̨������ѯ����
				system("pause");
				system("cls");
				flag=1;
				break;
        case '4':
				system("cls");
				chaxun3(Phead); //���ú�̨����ѯ����
				system("pause");
				system("cls");
				flag=1;
				break;
        case '5':
				system("cls");
				shanchu(&Phead); //���ú�̨ɾ���û�����
				system("pause");
				system("cls");
				flag=1;
				break;
        case '6':
				system("cls");
				zengjia(&Phead); //���ú�̨�����û�����
				system("pause");
				system("cls");
				flag=1;
				break;
        case '7':
				system("cls");
				shuchu(Phead); //���ú�̨�����������
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

///��̨���д���������                              //bug bug
void chuangjian(struct person **Phead)  //*(*Phead)Ϊָ��ṹ��ָ��ĵ�ַ       
{
    struct person *p,*t;    //�������ָ��
    char n[20];
    char a[20];
    int s;
    if(*Phead) *Phead=NULL;
	hang=5;lie=30;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("�����뿨�� ���� ���");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	gotoxy(lie,hang);printf("(��Ԥ����Ϊ0ʱ�˳�,��������밴�س�)");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("�����뿨��");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",n);hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("����������");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",a);hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("������Ԥ����");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%d",&s);hang++;
    if(s==0) return;
    p=(L *)malloc(sizeof(L));           //����Ϣ����������
    strcpy(p->kehu.ID,n);
    strcpy(p->kehu.name,a);
    *Phead=p;                           //��ָ������ָ��ͷָ��
	system("cls");
	hang=6;lie=30;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	gotoxy(lie,hang);printf("(��Ԥ����Ϊ0ʱ�˳�,��������밴�س�)");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("�����뿨��");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",n);hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("����������");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",a); hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("������Ԥ����");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%d",&s);hang++;
    while(s)
    {
        t=p;                        //��p��ֵ����t,p�ֿ��Դ�����һ�����
        p=(L *)malloc(sizeof(L));   //Ϊ�½�㿪���µ��ڴ�
        strcpy(p->kehu.ID,n);
        strcpy(p->kehu.name,a);
        p->kehu.money=s;
        p->next=NULL;
        t->next=p;                   //��p��ֵ����t(����һ�����ĺ���)
		system("cls");
		hang=6;lie=30;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		gotoxy(lie,hang);printf("(��Ԥ����Ϊ0ʱ�˳�,��������밴�س�)");hang++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
        gotoxy(lie,hang);printf("�����뿨��");hang++;  //β�巨
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
        gotoxy(lie,hang);scanf("%s",n);hang++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
        gotoxy(lie,hang);printf("����������");hang++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
        gotoxy(lie,hang);scanf("%s",a);hang++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		gotoxy(lie,hang); printf("������Ԥ����");hang++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
        gotoxy(lie,hang);scanf("%d",&s);hang++;
    }
}

///��̨�������������
void shuchu(struct person *Phead)
{
	hang=5;lie=30;
	system("cls");
    if(NULL==Phead)
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        gotoxy(lie,hang);printf("û�пͻ���Ϣ�������");  //��ͷָ��ָ��գ���û�пͻ���Ϣ
        return;
    }
    while(Phead)  //����������������пͻ���Ϣ
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        gotoxy(lie,hang);printf("����:%s",Phead->kehu.ID);hang++;
		gotoxy(lie,hang);printf("����:%s",Phead->kehu.name);hang++;
		gotoxy(lie,hang);printf("���:%d",Phead->kehu.money);hang++;hang++;
        Phead=Phead->next;
    }
	gotoxy(lie,hang);
}

///��̨���п��Ų�ѯ����
void chaxun1(struct person*Phead)
{
    char m[20];   //����������ҿͻ����ŵı���
	hang=5;lie=30;
    if(NULL==Phead)   //��ͷָ����գ���û�пͻ���Ϣ
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		gotoxy(lie,hang);printf("û�пͻ���Ϣ�ɲ�ѯ��");
		return;
    }
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(lie,hang);printf("������Ҫ��ѯ�Ŀͻ����ţ�");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	gotoxy(lie,hang);scanf("%s",m);hang++;
    while(NULL!=Phead&&strcmp(Phead->kehu.ID,m)!=0)  //�������б���Ѱ���У�ֱ��������ڲ��ҿ��ź˶�����
        Phead=Phead->next;
    if(Phead==NULL)  //��ָ��ָ���ָ��գ���û�пͻ���Ϣ
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		gotoxy(lie,hang);printf("�Բ���û�и��û���");
	}   
    else
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
		gotoxy(lie,hang);printf("������ѯ���û���Ϣ���£�");hang++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		gotoxy(lie,hang);printf("����:%s",Phead->kehu.ID);hang++;
		gotoxy(lie,hang);printf("����:%s",Phead->kehu.name);hang++;
		gotoxy(lie,hang);printf("���:%d",Phead->kehu.money);hang++;
		gotoxy(lie,hang);
	}

}    //���ҵ���������ͻ���Ϣ

///��̨����������ѯ����
void chaxun2(struct person *Phead)
{
    char m[20];   //����������ҿͻ����ŵı���
	hang=5;lie=30;
    if(NULL==Phead)   //��ͷָ����գ���û�пͻ���Ϣ
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		gotoxy(lie,hang);printf("û�пͻ���Ϣ�ɲ�ѯ��");
		return;
    }
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("������Ҫ��ѯ�Ŀͻ�������");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",m);hang++;
    while(NULL!=Phead&&strcmp(Phead->kehu.name,m)!=0)  //�������б���Ѱ���У�ֱ��������ڲ��������˶�����
    Phead=Phead->next;
    if(Phead==NULL)  //��ָ��ָ���ָ��գ���û�пͻ���Ϣ
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		gotoxy(lie,hang);printf("�Բ���û�и��û���");
	}   
    else
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
		gotoxy(lie,hang);printf("������ѯ���û���Ϣ���£�");hang++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		gotoxy(lie,hang);printf("����:%s",Phead->kehu.ID);hang++;
		gotoxy(lie,hang);printf("����:%s",Phead->kehu.name);hang++;
		gotoxy(lie,hang);printf("���:%d",Phead->kehu.money);hang++;
		gotoxy(lie,hang);
	}
}    //���ҵ���������ͻ���Ϣ

///��̨��������ѯ����
void chaxun3(struct person *Phead)
{
    long x;   //����������ҿͻ����ı���
	hang=5;lie=30;
    if(NULL==Phead)   //��ͷָ����գ���û�пͻ���Ϣ
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		gotoxy(lie,hang);printf("û�пͻ���Ϣ�ɲ�ѯ��");
		return;
    }
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("������Ҫ��ѯ�Ŀͻ���Ϣ����");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%ld",&x);hang++;
    while(NULL!=Phead&&Phead->kehu.money!=x)  //�������б���Ѱ���У�ֱ��������ڲ������˶����󣬼���Ѱ��
        Phead=Phead->next;
    if(Phead==NULL)  //��ָ��ָ���ָ��գ���û�пͻ���Ϣ
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		gotoxy(lie,hang);printf("�Բ���û�иÿͻ���");
	}  
    else
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
		gotoxy(lie,hang);printf("������ѯ���û���Ϣ���£�");hang++;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY |FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		gotoxy(lie,hang);printf("����:%s",Phead->kehu.ID);hang++;
		gotoxy(lie,hang);printf("����:%s",Phead->kehu.name);hang++;
		gotoxy(lie,hang);printf("���:%d",Phead->kehu.money);hang++;
		gotoxy(lie,hang);
	}
}    //���ҵ���������ͻ���Ϣ

///��̨����ɾ���ͻ���Ϣ����                        //bug bug bug
void shanchu(struct person **Phead)   //*(*Phead)Ϊָ��ṹ��ָ��ĵ�ַ
{
    char k[20];    //����������ҿͻ��������ŵı���
    struct person *p=*Phead,*t;
	lie=30;hang=5;
    if(NULL==(*Phead))     //��ָ�����ָ��գ���û�пͻ���Ϣ
    {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
        gotoxy(lie,hang);printf("û�пͻ���Ϣ��ɾ����");
        return;
    }
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("������Ҫɾ���Ŀͻ����ţ�");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",k);hang++;
    if(p->kehu.ID==k)  //����һ���ͻ����ǣ�����ͷָ��ָ����һ�����
        *Phead=(*Phead)->next,free(p);
    else
    {
        while(NULL==p->next&&p->next->kehu.ID!=k)   //����Ѱ�ң��˶Կͻ�����
            p=p->next;                              //��p->nextûָ��գ����ҿͻ��Ŀ��Ż�û�ҵ��������Ѱ��
        if(p->next==NULL)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
			gotoxy(lie,hang);printf("�Բ���û�иÿͻ���");hang++;
			gotoxy(lie,hang);
		}
        else
        {
            t=p->next;  //����ҵ������p->next��ֵ����t
            p->next=p->next->next;
        }
    }
}

///��̨���������û���Ϣ����
void zengjia(struct person **Phead)  //*(*Phead) Ϊָ��ṹ��ָ��ĵ�ַ
{
    char n[20];   //�����������ӿͻ����ŵı���
    char a[20];   //�����������ӿͻ������ı���
    int s;
    L *p,*t,*k;   //�������ָ�����
	hang=5;lie=30;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	gotoxy(lie,hang);printf("������Ҫ����Ŀͻ���Ϣ");hang++;
    gotoxy(lie,hang);printf("�����뿨��");hang++;  //β�巨
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",&n);hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("����������");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%s",a);hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    gotoxy(lie,hang);printf("������Ԥ����");hang++;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    gotoxy(lie,hang);scanf("%d",&s);hang++;
	gotoxy(lie,hang);
    p=(L *)malloc(sizeof(L));    //���ٿռ�
        strcpy(p->kehu.ID,a);   //���µĿͻ���Ϣд������
        p->kehu.money=s;
        strcpy(p->kehu.name,n);
        if(NULL==(*Phead))   //����ǿ���������¿ͻ���Ϣ��Ϊ��һ�����
        {
            *Phead=p;   //ͷ�巨
            (*Phead)->next=NULL;
            return ;
        }
        else
        {
            p->next=(*Phead);   //ͷ�巨
            (*Phead)=p;
        }
}
