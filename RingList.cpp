#include "RingList.h"
#include <conio.h>
#include <stdio.h>

Itm::Itm()
{
	num = 0;
	next = prev = NULL;
}
Itm::Itm(int num)
{
	this->num = num;
	next = prev = NULL;
}


RingList::RingList()
{
	size = 0;
	head = cur = NULL;
}

RingList::RingList(int num)
{
	size = 1;
	Itm* temp = new Itm(num);
	head = temp;
	head->next = head;
	head->prev = head;
	cur = head;
}

RingList::RingList(Itm* head)
{
	size = 1;
	this->head = head;
	this->head->next = this->head;
	this->head->prev = this->head;
	cur = this->head;
}

RingList::~RingList()
{
	while (size != 0)
	{
		Itm* temp = head->next;
		delete head;
		head = temp;
		size--;
	}
}

int RingList::GetSize()
{
	return size;
}

void RingList::AddElement(int num, int pos)
{
	if (pos < 1 || pos > size + 1)
	{
		printf("Wrong position!\n");
		return;
	}

	Itm* elem = new Itm(num);

	if (pos == 1 && size == 0)
	{
		head = elem;
		head->next = head;
		head->prev = head;
		size++;
		return;
	}

	if (pos == 1 && size != 0)
	{
		elem->next = head;
		elem->prev = head->prev;
		head = elem;
		head->next->prev = head;
		size++;
		return;
	}

	cur = head;
	for (int i = 1; i < pos - 1; i++)
	{
		cur = cur->next;
	}
	if (pos == size + 1)
	{
		elem->next = head;
		elem->prev = cur;
		head->prev = elem;
	}
	else
	{
		elem->next = cur->next;
		elem->prev = cur;
	}
	cur->next = elem;
	size++;
}

void RingList::DelElement(int pos)
{
	if (pos < 1 || pos > size)
	{
		printf("Wrong position!\n");
		return;
	}

	Itm* dltd = head;
	if (pos == 1)
	{
		head->prev->next = head->next;
		head->next->prev = head->prev;
		head = head->next;
		delete dltd;
		size--;
		return;
	}
	for (int i = 1; i < pos; i++)
	{
		dltd = dltd->next;
	}
	dltd->prev->next = dltd->next;
	dltd->next->prev = dltd->prev;
	delete dltd;
	size--;
}

void RingList::ViewList()
{
	printf("ViewList: ");
	cur = head;
	for(int i = 0; i < size; i++)
	{
		printf("%i ", cur->num);
		cur = cur->next;
	}
	printf("\n");
}

int RingList::GetElNum(int pos)
{
	cur = head;
	for (int i = 1; i < pos; i++)
	{
		cur = cur->next;
	}
	return cur->num;
}