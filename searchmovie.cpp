#include "booking.h"

void
SearchMovie(Link l)
{
	Node *s[10], *r;
	int sel, k, i = 0;
	char str1[5], str2[10], str3[30];
	if (!l->next)
	{
		printf("�Ҳ���(*��;(�� *)����ô�붼�Ҳ�������\n");
		return;
	}
	printf("��ѡ����в�ѯ�ķ�ʽ|w`��:\n1:���ݵ�Ӱ��Ž��в�ѯ\n2:�������ڷ�ӳ����ѯ\n3:���ݵ�Ӱ���Ʋ�ѯ\n");
	scanf("%d", &sel);									//����ѡ������ 
	
	if (sel == 1)										//����Ž��в�ѯ 
	{
		printf("�������Ӱ�ı��|w`��:\n");
		scanf("%s", str1);								//������  
		r = l->next;
		while(r != NULL)								//����ָ�� r����Ϊ��������ѭ�� 
			if(strcmp(r->data.num, str1) == 0)			//�����Ƿ�������������ƥ��ĵ�Ӱ 
			{
				s[i] = r;
				i++;									//��������ƥ��ĵ�Ӱ��Ϣ��ִ��i++ 
				break;
			}
			else
				r = r->next;							//û�в��ҵ���Ӱ��ָ�� r ����һλ 
	}
	
	else if (sel == 2)									//����ӳ����ѯ
	{
		printf("�������Ӱ���ڵķ�ӳ��|w`��:\n");
		scanf("%s", str2);								//�������ڷ�ӳ�� 
		r = l->next;
		while(r != NULL)								//����ָ�� r 
			if(strcmp(r->data.movieRoom, str2) == 0)	//�����Ƿ���������ķ�ӳ����ƥ��ĵ�Ӱ 
			{
				s[i] = r;
				i++;									
				r = r->next;
			}
			else
				r = r->next;
	}
	
	else if (sel == 3)
	{
		printf("�������Ӱ����|w`��:\n");
		scanf("%s", str3);
		r = l->next;
		while(r != NULL)
			if(strcmp(r->data.movieName, str3) == 0)
			{
				s[i] = r;
				i++;
				r = r->next;
			}
			else
				r = r->next;
	}
	
	if (i == 0)
		printf("�Ҳ�����(*��;(�� *)���������Ի�����ѯ��ʽ�ɡ�\n");
	else
	{
		printheader();									//�����ͷ 
		for (k = 0; k < i; k++)
			printdata(s[k]);							//�����Ӱ��Ϣ 
	}
}

