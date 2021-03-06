#include <stdio.h>
#include <stdlib.h>

typedef int elementD;

typedef struct DlistNode
{
	elementD data;
	struct DlistNode* next;
	struct DlistNode* prev;
}DlistNodeM;



typedef struct DLHeader
{
	struct DlistNode* head;
	int size;
}DLHeader;


DLHeader* init()
{
	DLHeader* header = (DLHeader*)malloc(sizeof(DLHeader));
	header->size = 0;
	header->head = NULL;
	return header;
}


DLHeader* insert_first(DLHeader* header, elementD data)
{
	DlistNodeM* input = (DlistNodeM*)malloc(sizeof(DlistNodeM));
	input->data = data;
	if (header->head == NULL)
	{
		input->next = input;
		input->prev = input;
	}
	else
	{
		input->next = header->head;
		input->prev = header->head->prev;
		header->head->prev->next = input;
		header->head->prev = input;
	}
	header->head = input;
	header->size++;
	return header;
}

DLHeader* insert_last(DLHeader* header, elementD data)
{
	DlistNodeM* input = (DlistNodeM*)malloc(sizeof(DlistNodeM));
	input->data = data;

	if (header == NULL)
	{
		input->next = input;
		input->prev = input;
	}
	else
	{
		input->next = header->head;
		input->prev = header->head->prev;
		header->head->prev->next = input;
		header->head->prev = input;
	}

	header->size++;
	return header;
}

DLHeader* insert_middle(DLHeader* header, int pos, elementD data)
{
	if (!(pos >= 0 || pos <= header->size))
		return header;
	if (pos == 0)
	{
		DLHeader* res = insert_first(header, data);
		return res;
	}
	else if (pos == header->size)
	{
		DLHeader* res = insert_last(header, data);
		return res;
	}
	DlistNodeM* input = (DlistNodeM*)malloc(sizeof(DlistNodeM));
	if (input == NULL)
		fprintf(stderr, "메모리 할당 실패");
	input->data = data;

	DlistNodeM* p = header->head;
	for (int i = 0; i < pos - 1; i++)
	{
		p = p->next;
	}
	DlistNodeM* q = p->next;
	p->next = input;
	q->prev = input;
	input->prev = p;
	input->next = q;

	header->size++;
}

DlistNodeM deleteFirst(DLHeader* header)
{
	DlistNodeM dat = { header->head->data,NULL,NULL };
	DlistNodeM* p = header->head;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	header->head = p->next;
	free(p);
	header->size--;
	return dat;
}

DlistNodeM deleteLast(DLHeader* header)
{
	DlistNodeM dat = { header->head->prev->data,NULL,NULL };
	DlistNodeM* p = header->head->prev;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
	header->size--;
	return dat;
}

DlistNodeM deleteMiddle(DLHeader* header, int pos)
{
	if (!(pos >= 0 || pos < header->size))
		return;
	if (pos == 0)
		return deleteFirst(header);
	else if (pos == header->size-1)
		return deleteLast(header);
	
	DlistNodeM* p = header->head;
	for (int i = 0; i < pos; i++)
	{
		p = header->head->next;
	}
	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
}

void print_listD(DLHeader* header)
{
	DlistNodeM* p = header->head;
	for (; p != header->head->prev; p = p->next)
	{
		printf("%d |", p->data);
	}
	printf("%d |", p->data);
	printf("\n");
}

void freeAll(DLHeader* header)
{
	DlistNodeM* p = header->head;
	DlistNodeM* q;
	while (p != header->head->prev)
	{
		q = p;
		p = p->next;
		free(q);
	}
	free(header);
}

/*
int main()
{
	DLHeader* header = init();
	insert_first(header, 6);
	print_listD(header);
	insert_last(header, 8);
	print_listD(header);
	insert_middle(header, 2, 7);
	print_listD(header);
	insert_middle(header, 2, 9);
	print_listD(header);


	deleteFirst(header);
	print_listD(header);
	deleteLast(header);
	print_listD(header);
	deleteMiddle(header,1);
	print_listD(header);

	freeAll(header);
	return 0;
}
*/