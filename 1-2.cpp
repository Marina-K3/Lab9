#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<locale.h>
#include <time.h>
#include <stdlib.h>
int main()
{
    setlocale(LC_ALL, "Rus");
    srand(unsigned(time(NULL)));
    int max;

    // 1-�� ����
    char s[100];
    int a[100];
    FILE* f;
    if (!(f = fopen("test.txt", "w+t")))
    {
        printf("���������� ������� ����\n");    return 0;
    }
    for (int i = 0; i < 60; i++)
    {
        a[i] = 10 + rand() % 40;
        fprintf(f, "%d ", a[i]);
    }
    printf("������ �������� � ����\n");

    fclose(f);
    if (!(f = fopen("test.txt", "r")))
    {
        printf("���������� �������� ����\n");    return 0;
    }
    while (fgets(s, 100, f) != NULL)
        puts(s);
    fclose(f);
    printf("\n");
    printf("\n");




    // 2-�� ����
    char s1[100];
    int d[100];
    FILE* f1;
    if (!(f1 = fopen("test1.txt", "w+t")))
    {
        printf("���������� ������� ����\n");    return 0;
    }
    for (int i = 0; i < 60; i++)
    {
        d[i] = 10 + rand() % 67;
        fprintf(f1, "%d ", d[i]);
    }
    printf("������ �������� � ����\n");
    fclose(f1);
    if (!(f1 = fopen("test1.txt", "r")))
    {
        printf("���������� �������� ����\n");    return 0;
    }
    while (fgets(s1, 100, f1) != NULL)
        puts(s1);
    fclose(f1);
    printf("\n");
    printf("\n");


    // 3-�� ����
    char s2[100];
    int r[100];
    FILE* f2;
    if (!(f2 = fopen("test2.txt", "w+t")))
    {
        printf("���������� ������� ����\n");    return 0;
    }
    for (int i = 0; i < 60; i++)
    {
        r[i] = 10 + rand() % 59;
        fprintf(f2, "%d ", r[i]);
    }
    printf("������ �������� � ����\n");
    fclose(f2);
    if (!(f2 = fopen("test2.txt", "r")))
    {
        printf("���������� �������� ����\n");    return 0;
    }
    while (fgets(s2, 100, f2) != NULL)
        puts(s2);
    fclose(f2);



    //������ max � ����
    FILE* D;
    D = fopen("test3.txt", "w+t");
    if (D == 0) {
        printf("�� ������� ������� ����");
    }
    for (int i = 0; i < 60; i++) {
        max = a[i];
        if (max < d[i]) max = d[i];
        if (max < r[i]) max = r[i];
        fprintf(D, "%d ", max);
    }
    fclose(D);
    printf("\n\n");

    // ����� ����� � max ����������
    char y[100];
    D = fopen("test3.txt", "r");
    if (D == 0) {
        printf("�� ������� ������� ���� ��� ������");
    }
    printf("������������ ��������, ���������� � D - ����:\n");
    while (fgets(y, 100, D) != NULL)
        puts(y);
    fclose(D);
    return 0;
}
