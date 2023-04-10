#include "booking.h"

void
ShowMovie(Link l)							//自定义函数显示电影信息 
{
	Node *p;
	p = l->next;
	printheader();							//输出电影表头 
	if (l->next == NULL)					//判断有无可显示的信息 
		printf("没有记录哦|w`）\n") ;
	else
		while(p != NULL)					//遍历 p 
		{
			printdata(p);					//输出所有电影数据 
			p = p->next;					// p 指针后移一位 
		}
}

