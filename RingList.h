#pragma once
#include <conio.h>
#include <stdio.h>

class Itm
{
public:
	int num; //Содержит целое число элемента списка
	Itm* next, * prev; //Экземпляры для перемещения по списку
	Itm(); //Конструктор по умолчанию
	Itm(int num); //Параметрический конструктор
};

class RingList
{
private:
	int size; //Содержит размер списка
	Itm* head, * cur; //Экземпляры, определяющие главный и выбранный элемент списка
public:
	RingList(); //Конструктор по умолчанию
	RingList(int num); //Параметрический конструктор, задающий число для главного элемента
	RingList(Itm* head); //Параметрический конструктор, задающий главный элемент
	~RingList(); //Деструктор
	int GetSize(); //Геттер размера списка
	void AddElement(int num, int pos); //Метод добавления элемента в любое место списка
	void DelElement(int pos); //Метод удаления указанного элемента списка
	void ViewList(); //Метод для просмотра содержимого структуры
	int GetElNum(int pos); //Метод для получения числа из элемента
};