/*
main.cpp
Соколовский А.В.
22.10.2022

основной файл с main()
база данных, состоящая из студентов и размера их стипендии
- при запуске программы данные считыаются с файла, если файл существует и он - не пустой
- предоставляется возможность ввести ФИО и размер стипендии студента
- данные сортируются по фамилии
- записываются в файл в бинарном виде
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


