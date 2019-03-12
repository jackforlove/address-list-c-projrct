#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void save(char *area,int n); 
void show(char *area,int n); 
struct s_list
{
	char name[20];
	char tel[15];
	char adr[50]; 
}list[200];
int main()
{
	char *area,areas[30];
	int n; 
	FILE *f;
	if(fopen("D:\\list_xl","r")==NULL)
	{
		printf("欢迎第一次使用本通讯录\n请设置通讯录保存的绝对地址\n");
		scanf("%s",&areas);
		f=fopen("D:\\list_xl","w");
		fwrite(areas,strlen(areas),1,f); 
		fclose(f); 
	} 
	else
	{
		
		f=fopen("D:\\list_xl","r");
		fseek( f , 0 , SEEK_END );
        int file_size;
        file_size = ftell( f);
        fseek( f, 0 , SEEK_SET);
        area=  (char *)malloc( file_size * sizeof( char ) );
		fread(area,file_size,1,f); 
		fclose(f); 
		printf("已载入第一次创建的通讯录\n需要重新设置通讯录删除d盘目录下list_xl文件即可！\n"); 
	} 
label:
	printf("----刻骨铭心简易通讯录xl----\n1-存储\n2-显示\n");
	int choice;
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("\n输入存储联系人信息的数量\n");
	scanf("%d",&n);
	save(area,n);
	goto label;
	}
	else if(choice==2) 
	{
		printf("\n输入显示联系人信息的数量\n");
	scanf("%d",&n);
	show(area,n);
	goto label;}
	else
	{printf("\n功能暂未开发\n");
	goto label;}
	return 0;	 
} 
void save(char *area,int n)
{
	int i,p;
	FILE *f; 
	if((f=fopen(area,"a"))==NULL)
	{
		if((f=fopen(area,"w"))==NULL)
		{ 
		printf("\n文件创建失败！\n");
		exit(0);} 
	} 
	printf("--请输入联系人姓名，电话，地址--"); 
	for(i=0;i<n;i++)
	{
		printf("\n第%d个联系人\n",i+1);
		scanf("%s%s%s",&list[i].name,&list[i].tel,&list[i].adr); 
		p=fwrite(&list[i],sizeof(struct s_list),1,f);
		if(p!=1)
		{
			printf("文件写入失败!");
			exit(0); 
		}
		else
		{
			printf("文件写入成功！"); 
		} 
		 
	}
	fclose(f); 
	 
} 
void show(char *area,int n)
{
	FILE *f; 
	int i; 
	if((f=fopen(area,"r"))==NULL)
	{
		printf("\n文件读取失败！");
		exit(0); 
	} 
	
	for (i=0;i<n;i++)
	{ 
	fread(&list[i],sizeof(struct s_list),1,f);
	printf("\n姓名：%s\n电话：%s\n地址：%s\n-------\n",list[i].name,list[i].tel,list[i].adr);
	}
	fclose(f); 
	
}
 