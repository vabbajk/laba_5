#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <math.h>

struct pair {
	int x;
	int y;
};


void Input_matrix(int matrix[100][100], int n, int m)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	for (int i = 0; i < n; i++)
	{
		int kol = 0, isnt_correct;
		do
		{
			isnt_correct = 0;
			kol = 0;

			char c[3000], temp[10] = { '\0' };
			int d = 0;

			if (!fgets(c, sizeof(c), stdin)) {
				printf("Ошибка при вводе строки.\n");
				isnt_correct = 1;
				continue;
			}

			int j = 0;
			while (c[j] != '\n' && c[j] != '\0')
			{
				if ((c[j] >= '0' && c[j] <= '9') || (c[j] == '-' && d == 0)) {
					temp[d++] = c[j];
				}
				else if (c[j] == ' ') {
					if (d > 0) {
						temp[d] = '\0';
						if (kol < m) {
							sscanf_s(temp, "%d", &matrix[i][kol++]);
						}
						else {
							isnt_correct = 1;
							printf("Превышено количество элементов!\n");
							break;
						}
						d = 0;
						temp[0] = '\0';
					}
				}
				else {
					isnt_correct = 1;
					printf("Некорректный ввод. Попробуйте снова.\n");
					break;
				}
				j++;
			}

			if (!isnt_correct && d > 0) {
				temp[d] = '\0';
				if (kol < m) {
					sscanf_s(temp, "%d", &matrix[i][kol++]);
				}
				else {
					isnt_correct = 1;
					printf("Превышено количество элементов!\n");
				}
			}

			if (!isnt_correct && kol != m) {
				isnt_correct = 1;
				printf("Количество элементов в строке не соответствует %d!\n", m);
			}
		} while (isnt_correct);
	}
}

void Input_matrix_new(int matrix[100][100], int n, int m)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	int j, kol = 0, isnt_correct = 0, d = 0;
	for (int i = 0; i < n; i++)
	{
		int error = 0;
		do
		{
			char c[3000], temp[10];
			int pointer = 0, kol = 0, d = 0;
			fgets(c, sizeof(c), stdin);

			while (c[pointer - 1] != '\n')
			{
				if (c[pointer] != ' ')
				{
					temp[d++] = c[pointer];
				}
				else
				{
					if (d > 10) { error = 1; printf("Вы ввели слишком длинный элемент строки! Попробуйте еще раз\n\n"); break; } // проверяем длину введенных значений

					if ((temp[0] < '0' || temp[0] > '9') && temp[0] != '-' && temp[0]!='+')
					{
						printf("Вы ввли некорректный элемент строки! Попробуйте еще раз\n\n"); error = 1; break;
					}
					for (int j = 1; j < d; j++)
					{
						if ((temp[i] < '0' || temp[i] > '9') && temp[i] != '-' && temp[i] != '+')
						{
							printf("Вы ввли некорректный элемент строки! Попробуйте еще раз\n\n"); error = 1; break;
						}
					}
					if (error) { break; }
					else {
						if (sscanf_s(c, "%d", matrix[i][kol]) != 1)
						{
							printf("Что то вызвало ошибку считывания!!! Попробуйте еще раз\n\n");
							error = 1;
						}
					}
				}
			}

		} while (error);
		
	}
}

void Input_matrix_dynamic(int** matrix, int n, int m)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	for (int i = 0; i < n; i++)
	{
		int kol = 0, isnt_correct;
		do
		{
			isnt_correct = 0;
			kol = 0;

			char c[3000], temp[10] = { '\0' };
			int d = 0;

			if (!fgets(c, sizeof(c), stdin)) {
				printf("Ошибка при вводе строки.\n");
				isnt_correct = 1;
				continue;
			}

			int j = 0;
			while (c[j] != '\n' && c[j] != '\0')
			{
				if ((c[j] >= '0' && c[j] <= '9') || (c[j] == '-' && d == 0)) {
					temp[d++] = c[j];
				}
				else if (c[j] == ' ') {
					if (d > 0) {
						temp[d] = '\0';
						if (kol < m) {
							sscanf_s(temp, "%d", &matrix[i][kol++]);
						}
						else {
							isnt_correct = 1;
							printf("Превышено количество элементов!\n");
							break;
						}
						d = 0;
						temp[0] = '\0';
					}
				}
				else {
					isnt_correct = 1;
					printf("Некорректный ввод. Попробуйте снова.\n");
					break;
				}
				j++;
			}

			if (!isnt_correct && d > 0) {
				temp[d] = '\0';
				if (kol < m) {
					sscanf_s(temp, "%d", &matrix[i][kol++]);
				}
				else {
					isnt_correct = 1;
					printf("Превышено количество элементов!\n");
				}
			}

			if (!isnt_correct && kol != m) {
				isnt_correct = 1;
				printf("Количество элементов в строке не соответствует %d!\n", m);
			}
		} while (isnt_correct);
	}
}

void Input_matrix_dynamic_solution_3(int** matrix, int n, int m)
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	for (int i = 0; i < n; i++)
	{
		int kol = 0, isnt_correct;
		do
		{
			isnt_correct = 0;
			kol = 0;

			char c[3000], temp[10] = { '\0' };
			int d = 0;

			if (!fgets(c, sizeof(c), stdin)) {
				printf("Ошибка при вводе строки.\n");
				isnt_correct = 1;
				continue;
			}

			int j = 0;
			while (c[j] != '\n' && c[j] != '\0')
			{
				if ((c[j] >= '0' && c[j] <= '9') || (c[j] == '-' && d == 0)) {
					temp[d++] = c[j];
				}
				else if (c[j] == ' ') {
					if (d > 0) {
						temp[d] = '\0';
						if (kol < m) {

							sscanf_s(temp, "%d", &matrix[i][kol++]);
						}
						else {
							isnt_correct = 1;
							printf("Превышено количество элементов!\n");
							break;
						}
						d = 0;
						temp[0] = '\0';
					}
				}
				else {
					isnt_correct = 1;
					printf("Некорректный ввод. Попробуйте снова.\n");
					break;
				}
				j++;
			}

			if (!isnt_correct && d > 0) {
				temp[d] = '\0';
				if (kol < m) {
					sscanf_s(temp, "%d", &matrix[i][kol++]);
				}
				else {
					isnt_correct = 1;
					printf("Превышено количество элементов!\n");
				}
			}

			if (!isnt_correct && kol != m) {
				isnt_correct = 1;
				printf("Количество элементов в строке не соответствует %d!\n", m);
			}
		} while (isnt_correct);
	}
}

void Generate_matrix(int matrix[100][100], int n, int m)
{
	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{

		int znak = 0;


		for (int j = 0; j < m; j++)
		{
			znak = rand() % 3;

			znak = znak == 0 ? -1 : 1;

			(matrix[i][j]) = (rand() % 50) * znak;
		}
	}
}

void Generate_matrix_dynamic(int** matrix, int n, int m)
{
	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{

		int znak = 0;


		for (int j = 0; j < m; j++)
		{
			znak = rand() % 3;

			znak = znak == 0 ? -1 : 1;

			(matrix[i][j]) = (rand() % 50) * znak;
		}
	}
}

void Generate_matrix_by_order(int matrix[100][100], int n, int m)
{

	int k = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			(matrix[i][j]) = k++;
		}
	}
}

void Generate_matrix_by_order_dynamic(int** matrix, int n, int m)
{

	int k = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			(matrix[i][j]) = k++;
		}
	}
}

void Print_matrix(int matrix[100][100], int n, int m)
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", matrix[i][j]);
			//printf("%d ", i * (*m) + j);
		}
		printf("\n");
	}
}

void Print_matrix_dynamic(int** matrix, int n, int m)
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", (matrix[i][j]));
			//printf("%d ", i * (*m) + j);
		}
		printf("\n");
	}
}

void Input_one_digit(int* ptr) {
	short isnt_correct;

	do {
		isnt_correct = 0;
		char c[100]; 
		if (fgets(c, sizeof(c), stdin) == NULL) {
			printf("Ошибка ввода. Попробуйте снова: ");
			isnt_correct = 1;
			continue;
		}

		int l = 0, r = strlen(c) - 1;


		if (c[r] == '\n') r--;


		while (l <= r && c[l] == ' ') l++;


		while (r >= l && c[r] == ' ') r--;

		if (l > r) {
			printf("Введите одно число! - ");
			isnt_correct = 1;
			continue;
		}


		if (c[l] == '-') l++;
		for (int i = l; i <= r; i++) {
			if (c[i] < '0' || c[i] > '9') {
				isnt_correct = 1;
				break;
			}
		}

		if (!isnt_correct) {
			if (sscanf_s(c, "%d", ptr) == 1) {
				return;
			}
			else {
				printf("Введите одно число! - ");
			}
		}
		else {
			printf("Введите корректное значение! : ");
		}
	} while (isnt_correct);

	return;
}

void Input_one_digit_in_string(char* ptr)
{

	char c[33];
	short isnt_correct = 0;

	do {

		isnt_correct = 0;
		fgets(c, sizeof(c), stdin);

		if (c[0] < '0' || c[0] > '9') {
			if (c[0] != '-') {
				isnt_correct = 1;
			}
		}

		for (int i = 1; c[i] != '\n'; i++)
		{
			if (c[i] < '0' || c[i] > '9') {
				isnt_correct = 1;
				break;
			}
		}

		if (!isnt_correct)
		{
			for (int i = 0; c[i - 1] != '\n'; i++)
			{
				ptr[i] = c[i];
			}
		}
		else { printf("Введите корректное значение! : "); while (getchar() != '\n') {} }

	} while (isnt_correct);

	return;
}

void Input_one_double(double* ptr) {
	char c[100];
	short isnt_correct;

	do {
		isnt_correct = 0;
		int has_point = 0;

		printf("Введите одно число: ");
		fgets(c, sizeof(c), stdin);


		int i = 0;
		if (c[i] == '-') {
			i++;
		}


		for (; c[i] != '\n' && c[i] != '\0'; i++) {
			if (c[i] == '.') {
				has_point++;
				if (has_point > 1) { 
					isnt_correct = 1;
					break;
				}
			}
			else if (c[i] < '0' || c[i] > '9') {
				isnt_correct = 1;
				break;
			}
		}

		if (!isnt_correct && sscanf_s(c, "%lf", ptr) == 1) {
			return;
		}
		else {
			printf("Введите корректное значение!\n");
			isnt_correct = 1;
		}
	} while (isnt_correct);
}

void Input_double_array_by_hand(double* ptr, int* size)
{
	int b = 0;
	for (int i = 0; i < *size; i++)
	{
		printf("Введите элемент %d : ", i + 1);
		Input_one_double(&ptr[i]);
	}
	return;
}

void Input_double_array_rand(double* ptr, int* size)
{
	int znak = 0;

	srand(time(NULL));

	for (int i = 0; i < *size; i++)
	{
		znak = rand() % 3;

		znak = znak == 0 ? -1 : 1;

		ptr[i] = (double)((rand() % 50) * znak);
	}
	return;
}

void Input_int_array_by_hand(int* ptr, int* size)
{
	int b = 0;
	for (int i = 0; i < *size; i++)
	{
		printf("Введите элемент %d : ", i + 1);
		Input_one_digit(&ptr[i]);
	}
	return;
}

void Input_int_array_rand(int* ptr, int* size)
{
	int znak = 0;


	DWORD milliseconds = GetTickCount();

	srand(milliseconds);

	for (int i = 1; i <= *size; i++)
	{


		znak = rand() % 3;

		znak = znak == 0 ? -1 : 1;

		ptr[i] = ((rand() % 50) * znak);
	}
	return;
}

void Input_int_natural_array_rand(int* ptr, int size) {
	for (int i = 0; i < size; i++) {
		ptr[i] = rand() % 50; 
	}
}

void check_na_prostotu(int num, int* res)
{
	*res = 1;
	int k = 0;
	if (num == 1) { *res = 0; return; }
	for (int i = 1; i <= num; i++)
	{
		if (num % i == 0) { k++; }
	}
	if (k > 2) { *res = 0; }
	
	return;
}