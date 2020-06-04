#pragma once
#include <conio.h>
#include <stdio.h>

class Itm
{
public:
	int num; //�������� ����� ����� �������� ������
	Itm* next, * prev; //���������� ��� ����������� �� ������
	Itm(); //����������� �� ���������
	Itm(int num); //��������������� �����������
};

class RingList
{
private:
	int size; //�������� ������ ������
	Itm* head, * cur; //����������, ������������ ������� � ��������� ������� ������
public:
	RingList(); //����������� �� ���������
	RingList(int num); //��������������� �����������, �������� ����� ��� �������� ��������
	RingList(Itm* head); //��������������� �����������, �������� ������� �������
	~RingList(); //����������
	int GetSize(); //������ ������� ������
	void AddElement(int num, int pos); //����� ���������� �������� � ����� ����� ������
	void DelElement(int pos); //����� �������� ���������� �������� ������
	void ViewList(); //����� ��� ��������� ����������� ���������
	int GetElNum(int pos); //����� ��� ��������� ����� �� ��������
};