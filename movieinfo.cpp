#include "booking.h"

void
MovieInfo(Link linkhead)
{
	struct node *p, *r, *s;
	char num[10];
	r = linkhead;
	s = linkhead->next;
	while (r->next != NULL)
		r = r->next;
	while (1)											//进入死循环 
	{
		printf("请输入电影的编号|w`）: \n");
		scanf("%s", num);
		if(strcmp(num, "0") == 0)						//比较字符
			break;
		while(s)										//判断是否已经存在 
		{
			if(strcmp(s->data.num, num) == 0)
			{
				printf("电影编号'%s'已经存在了！你这个小 呆 瓜☆\n", num);
				return;
			}
			s = s->next;
		}
		p = (struct node*)malloc(sizeof(struct node));
		strcpy(p->data.num, num);						//复制编号
		printf("请输入电影的名称|w`）: \n");
		scanf("%s", p->data.movieName);	 				//输入电影名称
		printf("请输入电影所在的放映厅|w`）: \n");
		scanf("%s", p->data.movieRoom);	 				//输入所在放映厅
		printf("请输入电影开始的时间|w`）: \n");
		scanf("%s", p->data.startTime);	 				//输入开始时间
		printf("请输入电影结束的时间|w`）: \n");
		scanf("%s", p->data.finishTime);	 			//输入结束时间
		printf("请输入电影票的价钱|w`）: \n");
		scanf("%f", p->data.price);	 					//输入票价
		printf("请输入预订的票数|w`）: \n");
		scanf("%d", p->data.ticketnum);	 				//输入预订票数
		p->next = NULL;
		r->next = p;									//插入链表中
		r = p;
		saveflag = 1;									//保存标志 
	}
}

