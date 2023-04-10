#include "booking.h"

void
SearchMovie(Link l)
{
	Node *s[10], *r;
	int sel, k, i = 0;
	char str1[5], str2[10], str3[30];
	if (!l->next)
	{
		printf("找不到(*￣;(￣ *)！怎么想都找不到啊！\n");
		return;
	}
	printf("请选择进行查询的方式|w`）:\n1:根据电影编号进行查询\n2:根据所在放映厅查询\n3:根据电影名称查询\n");
	scanf("%d", &sel);									//输入选择的序号 
	
	if (sel == 1)										//按编号进行查询 
	{
		printf("请输入电影的编号|w`）:\n");
		scanf("%s", str1);								//输入编号  
		r = l->next;
		while(r != NULL)								//遍历指针 r，若为空则跳出循环 
			if(strcmp(r->data.num, str1) == 0)			//检索是否有与输入编号相匹配的电影 
			{
				s[i] = r;
				i++;									//检索到有匹配的电影信息，执行i++ 
				break;
			}
			else
				r = r->next;							//没有查找到电影则指针 r 后移一位 
	}
	
	else if (sel == 2)									//按放映厅查询
	{
		printf("请输入电影所在的放映厅|w`）:\n");
		scanf("%s", str2);								//输入所在放映厅 
		r = l->next;
		while(r != NULL)								//遍历指针 r 
			if(strcmp(r->data.movieRoom, str2) == 0)	//检索是否有与输入的放映厅相匹配的电影 
			{
				s[i] = r;
				i++;									
				r = r->next;
			}
			else
				r = r->next;
	}
	
	else if (sel == 3)
	{
		printf("请输入电影名称|w`）:\n");
		scanf("%s", str3);
		r = l->next;
		while(r != NULL)
			if(strcmp(r->data.movieName, str3) == 0)
			{
				s[i] = r;
				i++;
				r = r->next;
			}
			else
				r = r->next;
	}
	
	if (i == 0)
		printf("找不到捏(*￣;(￣ *)！不如试试换个查询方式吧☆\n");
	else
	{
		printheader();									//输出表头 
		for (k = 0; k < i; k++)
			printdata(s[k]);							//输出电影信息 
	}
}

