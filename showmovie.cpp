#include "booking.h"

void
ShowMovie(Link l)							//�Զ��庯����ʾ��Ӱ��Ϣ 
{
	Node *p;
	p = l->next;
	printheader();							//�����Ӱ��ͷ 
	if (l->next == NULL)					//�ж����޿���ʾ����Ϣ 
		printf("û�м�¼Ŷ|w`��\n") ;
	else
		while(p != NULL)					//���� p 
		{
			printdata(p);					//������е�Ӱ���� 
			p = p->next;					// p ָ�����һλ 
		}
}

