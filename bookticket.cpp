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
	printf("��������Ҫ���ĵ�Ӱ|w`��: \n");
	scanf("%s", &str);														//�����뿴�ĵ�Ӱ���� 
	p = l->next;															// p ָ����Ĳ���ָ�� l ����һλ 
	while (p != NULL)														//����ָ�� p 
	{
		if(strcmp(p->data.movieName, str) == 0)								//�Ƚ�����ĵ�Ӱ����������ڵ������Ƿ�ƥ�� 
		{
			r[i] = p;														//�����������ļ�¼�������� r 
			i++;
		}
		p = p->next;
	}
	printf("\n\n�ܹ���%d����Ӱ��¼Ŷ��\n", i);
		printheader();														//�����ͷ 
	for (t = 0; t < i; t++)
		printdata(r[t]);													//ѭ����������еĵ�Ӱ��Ϣ 
	if (i == 0)
		printf("�ǳ���Ǹ��û���ҵ�����Ҫ�ĵ�ӰŶ|w`��\n");
	else
		{
			printf("������Ҫ����Ԥ����(y / n)\n");
			scanf("%s", ch);
			if(strcmp(ch, "y") == 0 || strcmp(ch, "Y") == 0)				//�ж��Ƿ�Ʊ 
			{
				h = (book*)malloc(sizeof(book));
				printf("�������������|w`��:\n");
				scanf("%s", &str1);											//���붩Ʊ�˵����� 
				strcpy(h->data.name, str1);									//��洢����Ϣ���бȽϣ����Ƿ����ظ��� 
				printf("���������ID|w`��:\n");
				scanf("%s", &str2);											//���붩Ʊ�˵� ID 
				strcpy(h->data.num, str2);									//��洢��Ϣ���бȽ� 
				printf("����������ҪԤ���ĵ�Ӱ�ı��:\n");
				scanf("%s", tnum);											//����ҪԤ���ĵ�Ӱ��� 
				for(t = 0; t < i; t++)
					if(strcmp(r[t]->data.num, tnum) == 0)					//�Ƚϱ�ţ����Ƿ���ڸñ�� 
					{
						if(r[t]->data.ticketnum < 1)						//�ж�ʣ��Ŀɹ�Ԥ����Ʊ���Ƿ�Ϊ 0 
						{
							printf("�ǳ���Ǹ���Ѿ�ȫ�����ˣ�|w`��");
							Sleep(1500);
							return;
						}
						printf("��ʣ��%d��ƱŶ|w`��\n", r[t]->data.ticketnum);
						flag = 1;
						break;
					}
					if (flag == 0)
					{
						printf("������󣡣����������룡��\n");
						Sleep(1500);
						return;
					}
					printf("��������ҪԤ����Ʊ��:\n");
					scanf("%d", &dnum);										//����ҪԤ����Ʊ�� 
					r[t]->data.ticketnum = r[t]->data.ticketnum - dnum;		//��Ʊ�ɹ���ɹ�Ԥ����Ʊ����Ӧ���� 
					h->data.bookNum = dnum;									//����Ʊ��������Ʊ����Ϣ 
					h->next = NULL;
					q->next = h;
					q = h;
					printf("��ϲ����Ԥ���ɹ�kira��~\n");
					getch();
					saveflag = 1;
			}
		}
}

