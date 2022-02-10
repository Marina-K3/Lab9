/*
������������ �������� ���� �� ���������, �������� � 
�������� ���������, ����������� ��� ����������, ��������� 
���������� ��������� � ������������ �� ����� ��������� � 
����� �� ������ �� ���������� (��������, �� �������, �� 
���������������� ������, �� ���� �������� � �.�.). 
������������, ������, ����������, ����� ��������� 
�������� � ����� ��������� �������� �������� � ���� �������. 
������������� ��������� �� ������� ��� �������� ����� � ���������� �������� �����/������.
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
	printf("      ����\n ������������ - 1\n ����������� - 2\n �������� - 3\n ����� - 4\n ��������� - 5\n");
	scanf("%d", &choice);
	return choice;
}
void form() {
	setlocale(LC_ALL, "Rus");
	
	printf("\n    ������������ ���������:\n������� ���������� ������ ������� ?\n");
	scanf("%d", &count);
	ar = (air*)malloc(sizeof(air)*count);
		N = fopen("file.dat", "wb");
		if (N == 0) printf("�� ������� ������� ����");
			for (int i = 0; i < count; i++) {
				printf("   ������� ����� ����� - ");
				scanf("%d", &ar[i].number);
				
				printf("   ����� ���������� - ");
				getchar();
				fgets(ar[i].dest, 25, stdin);
			
				printf("   ����� ������ - ");
				
				fgets(ar[i].time, 10, stdin);
				
				printf("   ���� ������ - ");
				
				fgets(ar[i].date, 12, stdin);
				
				printf("   ���� - ");
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
		printf("  ����� ����� - %d\n  ����� ���������� - %s\  ����� ������ - %s\  ���� ������ - %s\  ���� - %f\n\n   -****-\n\n", buf.number, buf.dest, buf.time, buf.date, buf.price);
	
	}
	fclose(N);
	return 0;
}

int add() {
	setlocale(LC_ALL, "Rus");
	int n;
	printf("������� ���������� ������ �������� ? - ");
	scanf("%d", &n);
	
	ar = (air*)realloc(ar, sizeof(air)*(n+count));
	N = fopen("file.dat", "ab+");
	if (N == 0) printf("�� ������� ������� ����");
	for (int i = count; i < n+count; i++) {
		printf("   ������� ����� ����� - ");
		scanf("%d", &ar[i].number);

		printf("   ����� ���������� - ");
		getchar();
		fgets(ar[i].dest, 25, stdin);

		printf("   ����� ������ - ");

		fgets(ar[i].time, 10, stdin);

		printf("   ���� ������ - ");

		fgets(ar[i].date, 12, stdin);

		printf("   ���� - ");
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
	printf("������� �������� ������ (����� ����������): ");
	getchar();
	fgets(mas, 20, stdin);

	N = fopen("file.dat", "ab+");
	char mas1[25];
	air buf;
	while (fread(&buf, sizeof(buf), 1, N)){

		if (strcmp(buf.dest, mas) == 0) {
			
			printf("  ����� ����� - %d\n  ����� ���������� - %s\  ����� ������ - %s\  ���� ������ - %s\  ���� - %f\n\n   -****-\n\n", buf.number, buf.dest, buf.time, buf.date, buf.price);
		}
	}
	fclose(N);
	return 0;
}