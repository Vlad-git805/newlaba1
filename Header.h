#pragma once
#include <iostream>
#include <Windows.h>
#include <ctime>

#define CLEAR system("cls");
#define SLEEP Sleep(1000);

using namespace std;

enum TASK
{
	TASK1 = 1, TASK2, TASK3, TASK4, TASK5, TASK6, TASK7, EXIT = 0,
};
enum SIZ
{
	SIZE1 = 10,
};
enum ZAVD
{
	ASC = 1, DESC = 2,
};

void showArr(int *arr, int size);
