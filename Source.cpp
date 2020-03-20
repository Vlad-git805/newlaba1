#include <iostream>
#include <Windows.h>
#include <ctime>
#include "Header.h"
using namespace std;

int main()
{
	srand(time(0));

	int arr[SIZE1] = { 0 };
	int numTask = 0;
	do
	{
		cout << "___________________________________________________________________________________" << endl;
		cout << TASK1 << " = the first task: fill the array with random numbers;" << endl;
		cout << TASK2 << " = the second task: display the array;" << endl;
		cout << TASK3 << " = the third task: find the element in the array;" << endl;
		cout << TASK4 << " = the fourth task: sort the array;" << endl;
		cout << TASK5 << " = the fifth task: average value of array elements;" << endl;
		cout << TASK6 << " = the sixth task: find the number of elements that are multiples of 5;" << endl;
		cout << TASK7 << " = the seventh task: move the array elements;" << endl;
		cout << EXIT << " = exit;" << endl;
		cin >> numTask;
		TASK NumTask = (TASK)numTask;
		switch (NumTask)
		{
		case TASK1:
		{
			int size1 = 0, size2;
			cout << "Fill the array with random numbers" << endl;
			cout << "Enter a range of random numbers: from ";
			cin >> size1;
			cout << " to ";
			cin >> size2;
			for (int i = 0; i < SIZE1; i++)
			{
				arr[i] = rand() % (size2 - size1 + 1) + size1;
			}
		}
		break;
		case TASK2:
		{
			cout << "Display the array" << endl;
			showArr(arr, SIZE1);
			cout << endl;
		}
		break;
		case TASK3:
		{
			cout << "Find the element in the array" << endl;
			int element = 0;
			int count1 = 0;
			bool error = true;
			cout << "Enter element" << endl;
			cin >> element;
			for (int i = 0; i < SIZE1; i++)
			{
				if (arr[i] == element)
				{
					count1 = i;
					cout << " Symbol " << element << " have " << count1 << " index" << endl;
					error = false;
				}
			}
			if (error == true)
			{
				cout << "There is no such element in array" << endl;
			}
		}
		break;
		case TASK4:
		{
			cout << "Sort the array" << endl;
			cout << "Sorting direction :" << ASC << " - ASC;" << DESC << "- DESC" << endl;
			int count = 0;
			cin >> count;
			switch (count)
			{
			case ASC:
			{
				int counter = 0;
				for (int i = 0; i < SIZE1; i++)
				{
					for (int j = SIZE1 - 1; j > i; j--)
					{
						if (arr[j] < arr[j - 1])
						{
							CLEAR
								showArr(arr, SIZE1);
							swap(arr[j], arr[j - 1]);
							SLEEP
								counter++;
						}
					}
				}
				CLEAR
					showArr(arr, SIZE1);
				cout << "number of steps = " << counter << endl;
			}
			break;
			case DESC:
			{
				int counter = 0;
				for (int i = 0; i < SIZE1; i++)
				{
					for (int j = SIZE1 - 1; j > i; j--)
					{
						if (arr[j] > arr[j - 1])
						{
							CLEAR
								showArr(arr, SIZE1);
							swap(arr[j], arr[j - 1]);
							SLEEP
								counter++;
						}
					}
				}
				CLEAR
					showArr(arr, SIZE1);
				cout << "number of steps = " << counter << endl;
			}
			break;
			default:
				cout << "error!" << endl;
				break;
			}
			cout << endl;
		}
		break;
		case TASK5:
		{
			double avanger = 0;
			cout << "Average value of array elements" << endl;
			for (int i = 0; i < SIZE1; i++)
			{
				avanger += arr[i];
			}
			cout << "Average value of array elements = " << avanger / SIZE1 << endl;
		}
		break;
		case TASK6:
		{
			int count2 = 0;
			cout << "Find the number of elements that are multiples of 5" << endl;
			for (int i = 0; i < SIZE1; i++)
			{
				if (arr[i] % 5 == 0)
				{
					++count2;
				}
			}
			cout << "Number of elements that are multiples of 5 = " << count2 << endl;
		}
		break;
		case TASK7:
		{
			cout << "Move the array elements" << endl;
			int arr2[SIZE1];
			int move = 0;
			int count3 = 0, f = 0;
			cout << "Move array 1 - left, 2 - right" << endl;
			cin >> move;
			cout << "Enter the offset value" << endl;
			cin >> count3;
			switch (move)
			{
			case 1:
				for (int i = 0; i < SIZE1; i++)
				{
					if (i + count3 <= SIZE1 - 1)
					{
						arr2[i] = arr[i + count3];
					}
					if (i + count3 >= SIZE1)
					{
						f = (i + count3) % 10;
						arr2[i] = arr[f];
					}
				}
				for (int i = 0; i < SIZE1; i++)
				{
					arr[i] = arr2[i];
				}
				break;
			case 2:
				for (int i = 0; i < SIZE1; i++)
				{
					if (i - count3 < 0)
					{
						f = (i - count3) + SIZE1;
						arr2[i] = arr[f];
					}
					if (i - count3 >= 0)
					{
						arr2[i] = arr[i - count3];
					}

				}
				for (int i = 0; i < SIZE1; i++)
				{
					arr[i] = arr2[i];
				}
				break;
			default:
				cout << "error" << endl;
				break;
			}
		}
		break;
		case EXIT:
			break;
		default:
			cout << "error" << endl;
			break;
		}
	} while (numTask != EXIT);
	system("pause");
	return 0;
}