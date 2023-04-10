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

struct movie					//���崢���ӰƱ��Ϣ�Ľṹ�� 
{
	char num[10];				//��Ӱ��� 
	char movieName[30];			//��Ӱ���� 
	char movieRoom[10];			//��ӳ�� 
	char startTime[10];			//��ʼʱ�� 
	char finishTime[10];		//����ʱ�� 
	float price;				//Ʊ�� 
	int ticketnum;				//Ʊ�� 
};

struct man						//���嶩Ʊ�˵���Ϣ 
{
	char num[10];				//ID 
	char name[10];				//���� 
	int bookNum;				//����Ʊ�� 
};

typedef struct node				//�����ӰƱ��Ϣ����Ľڵ�ṹ
{
	struct movie data;			//���� movie �ṹ�����͵ı��� data
	struct node *next;
}Node, *Link;

typedef struct Man				//���嶩Ʊ����Ϣ����Ľڵ�ṹ
{
	struct man data;			//���� man �ṹ�����͵ı��� data
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
