#include "booking.h"

int main()
{
	FILE *fp1, *fp2;
	Node *p, *r;
	char ch1, ch2;
	Link l;
	bookLink k;
	book *t, *h;
	int sel;
	
	l = (Node*)malloc(sizeof(Node));
	l->next = NULL;
	r = l;
	
	k = (book*)malloc(sizeof(book));
	k->next = NULL;
	h = k;
	
	fp1 = fopen("movie.txt", "ab+");				//打开储存电影票信息的文件
	if ((fp1 == NULL))
	{
		printf("打不开(*￣;(￣ *)！怎么想都打不开吧！\n");
		return 0;
	}
	while (!feof(fp1))
	{
		p = (Node*)malloc(sizeof(Node));
		if(fread(p, sizeof(Node), 1, fp1) == 1)		//从指定文件读取记录 
		{
			p->next = NULL;
			r->next = p;							//构造链表 
			r = p;
		}
	}
	fclose(fp1);
	
	fp2 = fopen("man.txt", "ab+");
	if ((fp2 == NULL))
	{
		printf("打不开(*￣;(￣ *)！怎么想都打不开吧！\n");
		return 0;
	}
	while (!feof(fp2))
	{
		t = (book*)malloc(sizeof(book));
		if (fread(t, sizeof(book), 1, fp2) == 1)
		{
			t->next == NULL;
			h->next = t;
			h = t;
		}
	}
	fclose(fp2);
	
	while (1)
	{
		system("cls");
		menu();
		printf("\t请从(0 ~ 6)中选择输入|w`）: \n");
		scanf("%d", &sel);
		system("cls");
		if(sel == 0)
		{
			if(saveflag == 1)						//当退出时判断信息是否保存
			{
				getchar();
				printf("\n文档已经被改变了哦o(=w＜=)☆请问意图保存吗?(y/n)\n");
				scanf("%c", &ch1);
				if(ch1 == 'y' || ch1 == 'Y')
				{
			SaveBookInfo(k);
					SaveMovieInfo(l);
				}
			}
			printf("\n谢谢你☆欢迎下次光临kira☆~\n");
			break;
		}
		switch(sel)									//根据所输入的sel值来选择相应的操作
		{
			case 1:
				MovieInfo(l);break;
			case 2:
				SearchMovie(l);break;
			case 3:
				BookTicket(l, k);break;
			case 4:
				Modify(l);break;
			case 5:
				ShowMovie(l);break;
			case 6:
				SaveMovieInfo(l);SaveBookInfo(k);break;
			case 0:
				return 0;
		}
		printf("\n你不按点啥的话会一直卡这里哦......\n");
		getch();
	}
}

