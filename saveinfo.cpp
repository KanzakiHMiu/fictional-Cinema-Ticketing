#include "booking.h"

void
SaveMovieInfo(Link l)										//�����Ӱ��Ϣ 
{
	FILE *fp;
	Node *p;
	int count = 0, flag = 1;
	fp = fopen("movie.txt", "wb");							//��ֻд�Ķ������ļ� 
	if (fp == NULL)
	{
		printf("�򲻿�(*��;(�� *)����ô�붼�򲻿��ɣ�\n"); 
		return;
	}
	p = l->next;
	while (p)												//���� p ָ�� 
	{
		if(fwrite(p, sizeof(Node), 1, fp) == 1)				//������ļ�д�����ݿ� 
		{
			p = p->next;									//ָ��ָ����һλ 
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
		printf("������%d����Ӱ��¼Ŷ��\n", count);
		saveflag = 0;										//��������������־���� 
	}
	fclose(fp);												//�ر��ļ� 
}

void
SaveBookInfo(bookLink k)									//���涩Ʊ�˵���Ϣ 
{
	FILE *fp;
	book *p;
	int count = 0, flag = 1;
	fp = fopen("man.txt", "wb");
	if (fp == NULL)
	{
		printf("�򲻿�(*��;(�� *)����ô�붼�򲻿��ɣ�\n");
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
		printf("������%d����Ʊ��¼Ŷ��\n", count);
		saveflag = 0;
	}
	fclose(fp);
}

