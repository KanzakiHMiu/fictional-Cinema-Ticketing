#include "booking.h"

void
SaveMovieInfo(Link l)										//保存电影信息 
{
	FILE *fp;
	Node *p;
	int count = 0, flag = 1;
	fp = fopen("movie.txt", "wb");							//打开只写的二进制文件 
	if (fp == NULL)
	{
		printf("打不开(*￣;(￣ *)！怎么想都打不开吧！\n"); 
		return;
	}
	p = l->next;
	while (p)												//遍历 p 指针 
	{
		if(fwrite(p, sizeof(Node), 1, fp) == 1)				//向磁盘文件写入数据块 
		{
			p = p->next;									//指针指向下一位 
			count++;
		}
		else
		{
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		printf("保存了%d条电影记录哦☆\n", count);
		saveflag = 0;										//保存结束，保存标志清零 
	}
	fclose(fp);												//关闭文件 
}

void
SaveBookInfo(bookLink k)									//保存订票人的信息 
{
	FILE *fp;
	book *p;
	int count = 0, flag = 1;
	fp = fopen("man.txt", "wb");
	if (fp == NULL)
	{
		printf("打不开(*￣;(￣ *)！怎么想都打不开吧！\n");
		return;
	}
	p = k->next;
	while (p)
	{
		if(fwrite(p, sizeof(book), 1, fp) == 1)
		{
			p = p->next;
			count++;
		}
		else
		{
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		printf("保存了%d条订票记录哦☆\n", count);
		saveflag = 0;
	}
	fclose(fp);
}

