/*
Задание 1. Разработать класс для работы с динамической структурой «За-кольцованный список», содержащей целочисленные значения. 
Реализовать:
1.	конструктор по умолчанию,
2.	параметрический конструктор,
3.	деструктор,
4.	метод добавления элемента в любое место списка,
5.	метод удаления указанного элемента списка,
6.	просмотр содержимого структуры.

Задание 2. Решить задачу с использованием разработанного класса: За-мкнутый многоугольник задан двумя наборами чисел – коор-динатами вершин по оси ОХ и OY. Вычислить периметр фигу-ры.

*/﻿

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include "RingList.h"

int main()
{
	RingList ox;
	ox.AddElement(2, 1);
	ox.AddElement(4, 2);
	ox.AddElement(4, 3);
	ox.AddElement(3, 4);
	ox.AddElement(2, 5);

	RingList oy;
	oy.AddElement(2, 1);
	oy.AddElement(2, 2);
	oy.AddElement(6, 3);
	oy.AddElement(7, 4);
	oy.AddElement(6, 5);

	double sideLength, result = 0; //Переменные для хранения длин сторон и результата

	for (int i = 1; i < ox.GetSize(); i++)
	{
		sideLength = sqrt(pow(ox.GetElNum(i + 1) - ox.GetElNum(i), 2) + pow(oy.GetElNum(i + 1) - oy.GetElNum(i), 2));
		result += sideLength;
	}
	result += sqrt(pow(ox.GetElNum(ox.GetSize()) - ox.GetElNum(1), 2) + pow(oy.GetElNum(oy.GetSize()) - oy.GetElNum(1), 2));

	printf("result: %f", result);
}
