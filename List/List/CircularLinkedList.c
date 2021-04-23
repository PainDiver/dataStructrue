#include <stdio.h>
#include <stdlib.h>

typedef char elementC[100];

typedef struct ListNodeC
{
	elementC data;
	struct ListNodeC* link;								//���׽��� ������ ����� ��� ���
}ListNodeC;

typedef struct ListTypeC
{
	int size;
	ListNodeC* head;									// ���׽ĳ�带 ����ų ��������� ���� ���
}ListTypeC;

void errorC(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}


ListTypeC* createC()
{																// �����Ҵ��ּҸ� ����� �ʱ�ȭ �ϰ� ��ȯ�ϴ� ���丮�Լ�
	ListTypeC* plist = (ListTypeC*)malloc(sizeof(ListTypeC));
	plist->size = 0;
	plist->head = NULL;
	return plist;
}

ListTypeC* insert_firstC(ListTypeC* header, elementC data)
{
	ListNodeC* node = (ListNodeC*)malloc(sizeof(ListNodeC));
	strcpy(node->data, data);
	if (header->head == NULL)
	{
		header->head = node;
		node->link = header->head;
	}
	else
	{
		node->link = header->head->link;
		header->head->link = node;
	}
	header->size++;
	return header;
}

ListTypeC* insert_lastC(ListTypeC* header, elementC data)
{
	ListNodeC* node = (ListNodeC*)malloc(sizeof(ListNodeC));
	strcpy(node->data, data);
	if (header->head == NULL)
	{
		header->head = node;
		node->link = header->head;
	}
	else
	{
		node->link = header->head->link;
		header->head->link = node;
		header->head = node;
	}
	header->size++;
	return header;
}

ListTypeC* insert_middleC(ListTypeC* header, int pos, elementC data)
{
	if (!(pos >= 0 || pos <= header->size))
		return header;
	if (pos == header->size)
	{
		insert_lastC(header, data);
		return header;
	}
	else if (pos == 0)
	{
		insert_firstC(header, data);
		return header;
	}

	ListNodeC* node = (ListNodeC*)malloc(sizeof(ListNodeC));
	strcpy(node->data, data);
	ListNodeC* temp = header->head;

	for (int i = 0; i < pos; i++)
	{
		temp = temp->link;
	}
	node->link = temp->link;
	temp->link = node;
	header->size++;
	return header;

}

void print_ListC(ListTypeC* header)
{
	ListNodeC* itr = header->head->link;
	for (; itr != header->head; itr = itr->link)
		printf("%s | ", itr->data);
	printf("%s", itr->data);

	printf("\n");
}

ListNodeC delete_first(ListTypeC* header)
{
	ListNodeC* p = header->head->link;
	ListNodeC dat = {p->data,NULL};
	header->head->link = p->link;
	free(p);
	header->size--;
	return dat;
}

ListNodeC delete_last(ListTypeC* header)
{
	ListNodeC* p = header->head;
	ListNodeC data = {p->data,NULL};
	
	ListNodeC* q = header->head->link;
	while (q->link != p)
	{
		q = q->link;
	}
	header->head = q;
	q->link = p->link;
	free(p); 
	header->size--;
	return data;
}

ListNodeC delete_Middle(ListTypeC* header,int pos)
{
	if(pos>=0 || pos< header->size)


	if (pos == 0)
	{
		ListNodeC res = delete_first(header);
		return res;
	}
	else if (pos == header->size-1)
	{
		ListNodeC res = delete_last(header);
		return res;
	}

	ListNodeC* p = header->head->link;
	ListNodeC data = { p->data,NULL };
	for (int i = 0; i < pos-1; i++)
	{
		p = p->link;
	}
	ListNodeC* q = p->link;
	ListNodeC dat = { q->data,NULL };
	p->link = q->link;
	
	free(q);
	header->size--;
	return dat;
}


/*
int main()
{
	ListTypeC* box;
	box = createC();

	
	insert_firstC(box, "�������");
	print_ListC(box);
	insert_lastC(box, "�ߵǴ�");
	print_ListC(box);
	insert_lastC(box, "����");
	print_ListC(box);
	insert_firstC(box, "����");
	print_ListC(box);

	insert_middleC(box, 4, "������");
	print_ListC(box);
	insert_middleC(box, 0, "��");
	print_ListC(box);
	
	delete_first(box);
	print_ListC(box);
	delete_last(box);
	print_ListC(box);
	delete_Middle(box, 3);
	print_ListC(box);

	
	insert_firstC(box, "Kim");
	insert_firstC(box, "Park");
	insert_firstC(box, "Choi");

	ListNodeC* p = box->head;
	for (int i = 0; i < 10; i++)
	{
		printf("���� ���� = %s\n", p->data);
		p = p->link;
	}
	
	return 0;
}
*/