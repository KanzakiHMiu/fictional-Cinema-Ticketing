#include "booking.h"

void
Modify(Link l)
{
	Node *p;
	char tnum[10], ch;
	p = l->next;
	if (!p)
	{
		printf("\nû�м�¼����!��ȥ���һ��ɡ�\n");
		return;
	}
	else
	{
		printf("\n��ȷ��Ҫ�޸�����|w`����(y / n)\n");
		getchar();
		scanf("%c", &ch);										//�����Ƿ���Ҫ�޸ĵ��ַ� 
		if(ch == 'y' || ch == 'Y')								//�ж��ַ� 
		{
			printf("\n��������Ҫ�޸ĵĵ�Ӱ���|w`��:\n");
			scanf("%s", tnum);									//������Ҫ�޸ĵĵ�Ӱ��� 
			while(p != NULL)
				if(strcmp(p->data.num, tnum) == 0)				//����������ĵ�Ӱ�����ƥ��ļ�¼ 
					break;
				else
					p = p->next;
			if (p)												//���� p ����� p ��ָ�����ִ�� if ��� 
			{
				printf("�������µı��|w`��:\n");
				scanf("%s", &p->data.num);
				printf("�������µ�����|w`��:\n");
				scanf("%s", &p->data.movieName);
				printf("�������µķ�ӳ��|w`��:\n");
				scanf("%s", &p->data.movieRoom);
				printf("�������µĿ�ʼʱ��|w`��:\n");
				scanf("%s", &p->data.startTime);
				printf("�������µĽ���ʱ��|w`��:\n");
				scanf("%s", &p->data.finishTime);
				printf("�������µ�Ʊ��|w`��:\n");
				scanf("%f", &p->data.price);
				printf("�������µ�Ʊ��|w`��:\n");
				scanf("%d", &p->data.ticketnum);
				printf("\n�޸ļ�¼��ɹ�kira��~\n");
				saveflag = 1;									//�����־ 
			}
			else
				printf("\tû�м�¼����!��ȥ���һ��ɡ�\n");
		}
	}
}

