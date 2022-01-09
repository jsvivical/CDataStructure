#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}NODE;

NODE* createNode(int num)
{
	NODE* cur = (NODE*)malloc(sizeof(NODE));
	cur->data = num;
	cur->next = NULL;

	return cur;
}


void appendNode(NODE** head, NODE** tail,NODE* cur) //�տ� ��� �ٿ�����
{
	NODE* temp;
	if (*head == NULL) // head�� NULL�� ���(����Ʈ�� ����� ���)
	{
		(*head) = cur;
		(*tail) = (*head);
	}

	else
	{
		(*tail)->next = cur;
		(*tail) = (*tail)->next;
	}
}
void printList(NODE* head)
{
	NODE* cur = head;
	while (cur)
	{
		printf("%5d", cur->data);
		cur = cur->next;
	}
}


void insert(NODE** head,NODE * prev ,NODE* cur) // cur : �����Ϸ��� ��� ¦���� ��� ������ ��ġ�� ���ԵǾ�� ��
{
	NODE* temp;
	if (prev == NULL)
	{
		temp = (*head);
		*head = cur;
		cur->next = temp;
	}

	else
	{
		printf("check\n");
		temp = prev->next;
		prev->next = cur;
		cur->next = temp;
	}
	
}


void delete(NODE** head, NODE* trail) //trail�� ������� �ϴ� ����� ������
{
	NODE* temp;
	if (trail == (*head))
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	else
	{
		temp = trail->next; //temp�� ����� ���
		trail->next = temp->next;
		free(temp);
	}
	
}

int main()
{
	int x, num;
	NODE* head = NULL, * tail = NULL, * cur, *p = NULL;
	FILE* f;
	f = fopen("list.txt", "r");
	if (!f) {
		fprintf(stderr, "error01 : file open\n");
		exit(1);
	}
	while (!feof(f))
	{
		fscanf(f, "%d", &num);
		cur = createNode(num);
		appendNode(&head, &tail, cur);
	}
	printf("���� ����Ʈ : \n");
	printList(head);


	do {
		printf("\ninput number : ");
		scanf("%d", &x);
		cur = createNode(x);
		p = head;
		switch (x % 2)
		{
		case 0: //even
			if (head->data >= x) insert(&head, NULL, cur);

			else
			{
				while (p->next->data <= x)
				{
					p = p->next;
				}
				insert(&head, p, cur);
			}
			printList(head);
			break;

		case 1: // odd

			if (head->data == x)
			{
				delete(&head, head);
				printList(head);
			}
			else
			{	
				while (p->next)
				{
					if (p->next->data == x) 
					{
						delete(&head, p);
						break;
					}
					p = p->next;
				}
				if (p ->data != x) printf("no key!\n %d", x);
				printList(head);
			}

			break;
		}
	} while (x != -1);
}