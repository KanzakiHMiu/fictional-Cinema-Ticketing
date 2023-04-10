#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dos.h>
#include <windows.h>

#define HEADER1 "+-----------------------------Booking Ticket------------------------------+\n"
#define HEADER2 "|  number  |movie name|movie room|start time|finishTime|price|ticketnumber|\n"
#define HEADER3 "|----------|----------|----------|----------|----------|-----|------------|\n"
#define FORMAT  "|%-10s|%-10s|%-10s|%-10s|%-10s|%5.2f|   %6d   |\n"
#define DATA p->data.num, p->data.movieName, p->data.movieRoom, p->data.startTime, p->data.finishTime, p->data.price, p->data.ticketnum

int saveflag = 0;

struct movie					//定义储存电影票信息的结构体 
{
	char num[10];				//电影编号 
	char movieName[30];			//电影名称 
	char movieRoom[10];			//放映厅 
	char startTime[10];			//开始时间 
	char finishTime[10];		//结束时间 
	float price;				//票价 
	int ticketnum;				//票数 
};

struct man						//定义订票人的信息 
{
	char num[10];				//ID 
	char name[10];				//姓名 
	int bookNum;				//所订票数 
};

typedef struct node				//定义电影票信息链表的节点结构
{
	struct movie data;			//声明 movie 结构体类型的变量 data
	struct node *next;
}Node, *Link;

typedef struct Man				//定义订票人信息链表的节点结构
{
	struct man data;			//声明 man 结构体类型的变量 data
	struct Man *next;
}book, *bookLink;

void printheader();
void printdata(Node *q);
void BookTicket(Link l, bookLink k);
void MovieInfo(Link linkhead);
void menu();
void SearchMovie(Link l);
void Modify(Link l);
void ShowMovie(Link l);
void SaveMovieInfo(Link l);
void SaveBookInfo(bookLink k);
