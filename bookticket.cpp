#include "booking.h"

void
BookTicket(Link l, bookLink k)
{
	Node *r[10], *p;
	char ch[2], tnum[10], str[30], str1[10], str2[10];
	book *q, *h;
	int i = 0, t = 0, flag = 0, dnum = 0;
	q = k;
	while (q->next != NULL)
		q = q->next;
	printf("请输入想要看的电影|w`）: \n");
	scanf("%s", &str);														//输入想看的电影名称 
	p = l->next;															// p 指向传入的参数指针 l 的下一位 
	while (p != NULL)														//遍历指针 p 
	{
		if(strcmp(p->data.movieName, str) == 0)								//比较输入的电影名称与存已在的名称是否匹配 
		{
			r[i] = p;														//将满足条件的记录存至数组 r 
			i++;
		}
		p = p->next;
	}
	printf("\n\n总共有%d条电影记录哦☆\n", i);
		printheader();														//输出表头 
	for (t = 0; t < i; t++)
		printdata(r[t]);													//循环输出数组中的电影信息 
	if (i == 0)
		printf("非常抱歉！没有找到你需要的电影哦|w`）\n");
	else
		{
			printf("请问需要进行预订吗？(y / n)\n");
			scanf("%s", ch);
			if(strcmp(ch, "y") == 0 || strcmp(ch, "Y") == 0)				//判断是否订票 
			{
				h = (book*)malloc(sizeof(book));
				printf("请输入你的名字|w`）:\n");
				scanf("%s", &str1);											//输入订票人的名字 
				strcpy(h->data.name, str1);									//与存储的信息进行比较，看是否有重复的 
				printf("请输入你的ID|w`）:\n");
				scanf("%s", &str2);											//输入订票人的 ID 
				strcpy(h->data.num, str2);									//与存储信息进行比较 
				printf("请输入你想要预订的电影的编号:\n");
				scanf("%s", tnum);											//输入要预订的电影编号 
				for(t = 0; t < i; t++)
					if(strcmp(r[t]->data.num, tnum) == 0)					//比较编号，看是否存在该编号 
					{
						if(r[t]->data.ticketnum < 1)						//判断剩余的可供预订的票数是否为 0 
						{
							printf("非常抱歉！已经全卖光了！|w`）");
							Sleep(1500);
							return;
						}
						printf("还剩下%d张票哦|w`）\n", r[t]->data.ticketnum);
						flag = 1;
						break;
					}
					if (flag == 0)
					{
						printf("错误错误！！请重新输入！！\n");
						Sleep(1500);
						return;
					}
					printf("请输入你要预订的票数:\n");
					scanf("%d", &dnum);										//输入要预订的票数 
					r[t]->data.ticketnum = r[t]->data.ticketnum - dnum;		//订票成功则可供预订的票数相应减少 
					h->data.bookNum = dnum;									//将订票数赋给订票人信息 
					h->next = NULL;
					q->next = h;
					q = h;
					printf("恭喜！！预订成功kira☆~\n");
					getch();
					saveflag = 1;
			}
		}
}

