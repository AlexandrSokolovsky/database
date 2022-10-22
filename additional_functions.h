/*
additional_functions.h
—околовский ј.¬.
22.10.2022

модуль со вспомогательными функци€ми
- вывод таблицы на экран
- сортировка по фамилии
- запись в файл
- считывание с файла
*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student_data.h"

int print_table(int, struct Student_data *);
int sort_by_secondery_name(int, struct Student_data *);
int write_to_file(int, struct Student_data &);
int read_from_file(struct Student_data &);


/*
вывод таблицы на экран, предварительно очищаетс€ весь экран
int in - количество строк в таблице,
struct Student_data *St_data - таблица с данными о студентах
*/
int print_table(int in, struct Student_data *St_data)
{
	int i = 0;
	system("cls");
	printf("|%29s|%9s|\n", "-----------------------------", "---------");
	printf("|%29s|%9s|\n", "FIO", "Stipa");
	printf("|%29s|%9s|\n", "-----------------------------", "---------");
	while (i < in)
	{
		printf("|%29s|%9d|\n", (St_data + i)->fio, (St_data + i)->stipa);
		printf("|%29s|%9s|\n", "-----------------------------", "---------");
		i++;
	}

	return 0;
}

/*
сортировка по фамилии по возрастанию
int in - количество строк в таблице,
struct Student_data *St_data - таблица с данными о студентах
*/
int sort_by_secondery_name(int in, struct Student_data *St_data)
{


	struct secondery_name_and_ptr
	{
		char secondery_name[n];
		Student_data *ptr;

	}f[N];



	for (int i = 0; i < in; i++)
	{
		int letters = 0;

		while (St_data->fio[letters++] != ' ' && St_data->fio[letters++] != '\0') {}

		strncpy(f[i].secondery_name, St_data->fio, letters);
		f[i].ptr = St_data;

		St_data++;
	}


	for (int i = 0; i < in; i++)
	{
		for (int j = 0; j < in; j++)
		{
			if (*(f[i].secondery_name) < *(f[j].secondery_name))
			{
				secondery_name_and_ptr ptr = f[i];
				strcpy(f[i].secondery_name, f[j].secondery_name);
				f[i].ptr = f[j].ptr;

				strcpy(f[j].secondery_name, ptr.secondery_name);
				f[j].ptr = ptr.ptr;
			}
		}
		St_data--;
	}

	struct Student_data St_data_temp[N];
	for (int i = 0; i < in; i++)
	{
		strcpy(St_data_temp[i].fio, f[i].ptr->fio);
		St_data_temp[i].stipa = f[i].ptr->stipa;
	}

	for (int i = 0; i < in; i++)
	{
		strcpy(St_data->fio, St_data_temp[i].fio);
		St_data->stipa = St_data_temp[i].stipa;
		St_data++;
	}
	St_data -= in;


	print_table(in, St_data);

	return 0;
}


/*
запись в файл в бинарном виде
int in - количество строк в таблице,
struct Student_data *St_data - таблица с данными о студентах
*/
int write_to_file(int in, struct Student_data &St_data)
{

	FILE *write_ptr;

	write_ptr = fopen("table.bin", "wb+");
	fwrite(&St_data, sizeof(struct Student_data) * in, 1, write_ptr);

	fclose(write_ptr);

	return 0;
}

/*
считывание с файла в бинарном виде
struct Student_data *St_data - таблица с данными о студентах
возвращает количество записей в файле
*/
int read_from_file(struct Student_data &St_data)
{
	int size = 0;

	FILE *ptr;

	
	ptr = fopen("table.bin", "rb+");
	if (ptr)
	{
		fseek(ptr, 0, SEEK_END);
		size = ftell(ptr);
		fseek(ptr, 0, SEEK_SET);

		fread(&St_data, size, 1, ptr);

		fclose(ptr);
		print_table(size/sizeof(struct Student_data), &St_data);
	}


	return (size / sizeof(struct Student_data));
}