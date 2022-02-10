/*
Сформировать бинарный файл из элементов, заданной в 
варианте структуры, распечатать его содержимое, выполнить 
добавление элементов в соответствии со своим вариантом и 
поиск по одному из параметров (например, по фамилии, по 
государственному номеру, по году рождения и т.д.). 
Формирование, печать, добавление, поиск элементов 
оформить и выбор желаемого действия оформить в виде функций. 
Предусмотреть сообщения об ошибках при открытии файла и выполнении операций ввода/вывода.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<locale.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
struct air {
	long int number;
	char dest[25];
	char time[10];
	char date[12];
	float price;
}*ar;
int count;
FILE *N;

int menu();

void form();

int print();

int add();

int scan();

int main()
{
	setlocale(LC_ALL, "Rus");
	int d = 1;
	while (d) {
		switch (menu()) {
		case 1: 
			form();
			break;
		case 2: 
			print();
			break;
		case 3: 
			add();
			break;
		case 4:
			scan();
			break;
		case 5:
			return 0;
			break;
		}
	}
	free(ar);
}
int menu() {
	setlocale(LC_ALL, "Rus");
	int choice;
	printf("      МЕНЮ\n Сформировать - 1\n Распечатать - 2\n Добавить - 3\n Найти - 4\n Завершить - 5\n");
	scanf("%d", &choice);
	return choice;
}
void form() {
	setlocale(LC_ALL, "Rus");
	
	printf("\n    Формирование структуры:\nСколько авиарейсов хотите описать ?\n");
	scanf("%d", &count);
	ar = (air*)malloc(sizeof(air)*count);
		N = fopen("file.dat", "wb");
		if (N == 0) printf("Не удалось открыть файл");
			for (int i = 0; i < count; i++) {
				printf("   Введите номер рейса - ");
				scanf("%d", &ar[i].number);
				
				printf("   Пункт назначения - ");
				getchar();
				fgets(ar[i].dest, 25, stdin);
			
				printf("   Время вылета - ");
				
				fgets(ar[i].time, 10, stdin);
				
				printf("   Дата вылета - ");
				
				fgets(ar[i].date, 12, stdin);
				
				printf("   Цена - ");
				scanf("%f", &ar[i].price);
				
				fwrite(&ar[i],sizeof(ar[0]),1, N);
				printf("\n   -******-\n\n");
				getchar();
				
		    }
			fclose(N);

}

int print() {

	N = fopen("file.dat", "rb");
	air buf;

	while (fread(&buf, sizeof(buf), 1, N)){
		printf("  Номер рейса - %d\n  Пункт назначения - %s\  Время вылета - %s\  Дата вылета - %s\  Цена - %f\n\n   -****-\n\n", buf.number, buf.dest, buf.time, buf.date, buf.price);
	
	}
	fclose(N);
	return 0;
}

int add() {
	setlocale(LC_ALL, "Rus");
	int n;
	printf("Сколько авиарейсов хотите добавить ? - ");
	scanf("%d", &n);
	
	ar = (air*)realloc(ar, sizeof(air)*(n+count));
	N = fopen("file.dat", "ab+");
	if (N == 0) printf("Не удалось открыть файл");
	for (int i = count; i < n+count; i++) {
		printf("   Введите номер рейса - ");
		scanf("%d", &ar[i].number);

		printf("   Пункт назначения - ");
		getchar();
		fgets(ar[i].dest, 25, stdin);

		printf("   Время вылета - ");

		fgets(ar[i].time, 10, stdin);

		printf("   Дата вылета - ");

		fgets(ar[i].date, 12, stdin);

		printf("   Цена - ");
		scanf("%f", &ar[i].price);

		fwrite(&ar[i], sizeof(ar[0]), 1, N);
		printf("\n   -******-\n\n");
		getchar();

	}
	fclose(N);
	return 0;
}

int scan() {
	setlocale(LC_ALL, "Rus");
	char mas[25];
	printf("Введите параметр поиска (пункт назначения): ");
	getchar();
	fgets(mas, 20, stdin);

	N = fopen("file.dat", "ab+");
	char mas1[25];
	air buf;
	while (fread(&buf, sizeof(buf), 1, N)){

		if (strcmp(buf.dest, mas) == 0) {
			
			printf("  Номер рейса - %d\n  Пункт назначения - %s\  Время вылета - %s\  Дата вылета - %s\  Цена - %f\n\n   -****-\n\n", buf.number, buf.dest, buf.time, buf.date, buf.price);
		}
	}
	fclose(N);
	return 0;
}