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
	while (1)											//������ѭ�� 
	{
		printf("�������Ӱ�ı��|w`��: \n");
		scanf("%s", num);
		if(strcmp(num, "0") == 0)						//�Ƚ��ַ�
			break;
		while(s)										//�ж��Ƿ��Ѿ����� 
		{
			if(strcmp(s->data.num, num) == 0)
			{
				printf("��Ӱ���'%s'�Ѿ������ˣ������С �� �ϡ�\n", num);
				return;
			}
			s = s->next;
		}
		p = (struct node*)malloc(sizeof(struct node));
		strcpy(p->data.num, num);						//���Ʊ��
		printf("�������Ӱ������|w`��: \n");
		scanf("%s", p->data.movieName);	 				//�����Ӱ����
		printf("�������Ӱ���ڵķ�ӳ��|w`��: \n");
		scanf("%s", p->data.movieRoom);	 				//�������ڷ�ӳ��
		printf("�������Ӱ��ʼ��ʱ��|w`��: \n");
		scanf("%s", p->data.startTime);	 				//���뿪ʼʱ��
		printf("�������Ӱ������ʱ��|w`��: \n");
		scanf("%s", p->data.finishTime);	 			//�������ʱ��
		printf("�������ӰƱ�ļ�Ǯ|w`��: \n");
		scanf("%f", p->data.price);	 					//����Ʊ��
		printf("������Ԥ����Ʊ��|w`��: \n");
		scanf("%d", p->data.ticketnum);	 				//����Ԥ��Ʊ��
		p->next = NULL;
		r->next = p;									//����������
		r = p;
		saveflag = 1;									//�����־ 
	}
}

