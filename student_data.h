/*
student_data.h
����������� �.�.
22.10.2022

���� �� ���������� Student_data
*/
#pragma once


const int n = 30;
const int N = 64;

/*
n = 30 - ����� ���;
N = 64 - ������������ ���������� ���������;

��������� ������ � ���������
������� ��:
	char fio[n] - ��� ��������;
	int stipa - ������� ���������
*/
struct Student_data
{
	char fio[n];
	int stipa;
};

