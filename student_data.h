/*
student_data.h
Соколовский А.В.
22.10.2022

файл со структурой Student_data
*/
#pragma once


const int n = 30;
const int N = 64;

/*
n = 30 - длина ФИО;
N = 64 - максимальное количесвто студентов;

структура данных о студентах
состоит из:
	char fio[n] - ФИО студента;
	int stipa - размера стипендии
*/
struct Student_data
{
	char fio[n];
	int stipa;
};

