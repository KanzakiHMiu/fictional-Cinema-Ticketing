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
	
	fp1 = fopen("movie.txt", "ab+");				//�򿪴����ӰƱ��Ϣ���ļ�
	if ((fp1 == NULL))
	{
		printf("�򲻿�(*��;(�� *)����ô�붼�򲻿��ɣ�\n");
		return 0;
	}
	while (!feof(fp1))
	{
		p = (Node*)malloc(sizeof(Node));
		if(fread(p, sizeof(Node), 1, fp1) == 1)		//��ָ���ļ���ȡ��¼ 
		{
			p->next = NULL;
			r->next = p;							//�������� 
			r = p;
		}
	}
	fclose(fp1);
	
	fp2 = fopen("man.txt", "ab+");
	if ((fp2 == NULL))
	{
		printf("�򲻿�(*��;(�� *)����ô�붼�򲻿��ɣ�\n");
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
		printf("\t���(0 ~ 6)��ѡ������|w`��: \n");
		scanf("%d", &sel);
		system("cls");
		if(sel == 0)
		{
			if(saveflag == 1)						//���˳�ʱ�ж���Ϣ�Ƿ񱣴�
			{
				getchar();
				printf("\n�ĵ��Ѿ����ı���Ŷo(=w��=)��������ͼ������?(y/n)\n");
				scanf("%c", &ch1);
				if(ch1 == 'y' || ch1 == 'Y')
				{
			SaveBookInfo(k);
					SaveMovieInfo(l);
				}
			}
			printf("\nлл��ӭ�´ι���kira��~\n");
			break;
		}
		switch(sel)									//�����������selֵ��ѡ����Ӧ�Ĳ���
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
		printf("\n�㲻����ɶ�Ļ���һֱ������Ŷ......\n");
		getch();
	}
}

