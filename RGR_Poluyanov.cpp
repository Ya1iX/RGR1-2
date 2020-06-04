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