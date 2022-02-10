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

    // 1-ый файл
    char s[100];
    int a[100];
    FILE* f;
    if (!(f = fopen("test.txt", "w+t")))
    {
        printf("Невозможно создать файл\n");    return 0;
    }
    for (int i = 0; i < 60; i++)
    {
        a[i] = 10 + rand() % 40;
        fprintf(f, "%d ", a[i]);
    }
    printf("Данные записаны в файл\n");

    fclose(f);
    if (!(f = fopen("test.txt", "r")))
    {
        printf("Невозможно прочесть файл\n");    return 0;
    }
    while (fgets(s, 100, f) != NULL)
        puts(s);
    fclose(f);
    printf("\n");
    printf("\n");




    // 2-ой файл
    char s1[100];
    int d[100];
    FILE* f1;
    if (!(f1 = fopen("test1.txt", "w+t")))
    {
        printf("Невозможно создать файл\n");    return 0;
    }
    for (int i = 0; i < 60; i++)
    {
        d[i] = 10 + rand() % 67;
        fprintf(f1, "%d ", d[i]);
    }
    printf("Данные записаны в файл\n");
    fclose(f1);
    if (!(f1 = fopen("test1.txt", "r")))
    {
        printf("Невозможно прочесть файл\n");    return 0;
    }
    while (fgets(s1, 100, f1) != NULL)
        puts(s1);
    fclose(f1);
    printf("\n");
    printf("\n");


    // 3-ий файл
    char s2[100];
    int r[100];
    FILE* f2;
    if (!(f2 = fopen("test2.txt", "w+t")))
    {
        printf("Невозможно создать файл\n");    return 0;
    }
    for (int i = 0; i < 60; i++)
    {
        r[i] = 10 + rand() % 59;
        fprintf(f2, "%d ", r[i]);
    }
    printf("Данные записаны в файл\n");
    fclose(f2);
    if (!(f2 = fopen("test2.txt", "r")))
    {
        printf("Невозможно прочесть файл\n");    return 0;
    }
    while (fgets(s2, 100, f2) != NULL)
        puts(s2);
    fclose(f2);



    //запись max в файл
    FILE* D;
    D = fopen("test3.txt", "w+t");
    if (D == 0) {
        printf("Не удалось открыть файл");
    }
    for (int i = 0; i < 60; i++) {
        max = a[i];
        if (max < d[i]) max = d[i];
        if (max < r[i]) max = r[i];
        fprintf(D, "%d ", max);
    }
    fclose(D);
    printf("\n\n");

    // вывод файла с max элементами
    char y[100];
    D = fopen("test3.txt", "r");
    if (D == 0) {
        printf("Не удалось открыть файл для чтения");
    }
    printf("Максимальные элементы, записанные в D - файл:\n");
    while (fgets(y, 100, D) != NULL)
        puts(y);
    fclose(D);
    return 0;
}
