#include "booking.h"

void
Modify(Link l)
{
	Node *p;
	char tnum[10], ch;
	p = l->next;
	if (!p)
	{
		printf("\n没有记录啦！!快去添加一点吧☆\n");
		return;
	}
	else
	{
		printf("\n你确定要修改它吗|w`）？(y / n)\n");
		getchar();
		scanf("%c", &ch);										//输入是否想要修改的字符 
		if(ch == 'y' || ch == 'Y')								//判断字符 
		{
			printf("\n请输入想要修改的电影编号|w`）:\n");
			scanf("%s", tnum);									//输入需要修改的电影编号 
			while(p != NULL)
				if(strcmp(p->data.num, tnum) == 0)				//查找与输入的电影编号相匹配的记录 
					break;
				else
					p = p->next;
			if (p)												//遍历 p ，如果 p 不指向空则执行 if 语句 
			{
				printf("请输入新的编号|w`）:\n");
				scanf("%s", &p->data.num);
				printf("请输入新的名称|w`）:\n");
				scanf("%s", &p->data.movieName);
				printf("请输入新的放映厅|w`）:\n");
				scanf("%s", &p->data.movieRoom);
				printf("请输入新的开始时间|w`）:\n");
				scanf("%s", &p->data.startTime);
				printf("请输入新的结束时间|w`）:\n");
				scanf("%s", &p->data.finishTime);
				printf("请输入新的票价|w`）:\n");
				scanf("%f", &p->data.price);
				printf("请输入新的票数|w`）:\n");
				scanf("%d", &p->data.ticketnum);
				printf("\n修改记录大成功kira☆~\n");
				saveflag = 1;									//保存标志 
			}
			else
				printf("\t没有记录啦！!快去添加一点吧☆\n");
		}
	}
}

