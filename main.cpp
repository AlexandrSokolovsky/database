/*
main.cpp
����������� �.�.
22.10.2022

�������� ���� � main()
���� ������, ��������� �� ��������� � ������� �� ���������
- ��� ������� ��������� ������ ���������� � �����, ���� ���� ���������� � �� - �� ������
- ��������������� ����������� ������ ��� � ������ ��������� ��������
- ������ ����������� �� �������
- ������������ � ���� � �������� ����
*/

#include "additional_functions.h"

int main()
{
	struct Student_data St_data[N];
	int i = read_from_file(*St_data);

	while (i < N)
	{
		char fio[n];
		char stipa[10];

		printf("Enter the student's FIO  (29 digits - max): ");
		if (gets_s(fio)[0] != '\0')
		{
			printf("Enter the %s's scholarship (9 digits - max): ", fio);
			gets_s(stipa);

			strcpy(St_data[i].fio, fio);
			St_data[i].stipa = atoi(stipa);

			i++;
		}
		else
			break;

		system("cls");
	}


	print_table(i, St_data);
	sort_by_secondery_name(i, St_data);
	write_to_file(i, *St_data);

	system("pause");
	return 0;
}


