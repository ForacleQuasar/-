#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>		
#include <time.h>
void main() {
    setlocale(LC_CTYPE, "RUS");
    int size;
    srand((unsigned)time(NULL));
    printf("������� ������ ������� > ");
    scanf("%d", &size);
    int** array = (int**)malloc(size * sizeof(int*));
    if (array == NULL) {
        puts("error");
        return -1;
    }
    for (int i = 0; i < size; i++) {
        array[i] = (int*)malloc(size * sizeof(int));
        if (array[i] == NULL) {
            puts("error");
            return -1;
            for (int i1 = 0; i1 < i; i1++) free(array[i1]);
            free(array);
            return -1;
        }
    }
    printf("�������� ������ �������������:\n");
    printf("1. � �������\n");
    printf("2. ��������� �������\n");
    printf("�������� ������: ");
    int option;
    scanf("%d", &option);
    if (option == 1) {
        printf("������� �������� �������:\n");
        for (int i = 0; i < size; i++) {
            for (int i1 = 0; i1 < size; i1++) {
                printf("������� [%d][%d]: ", i + 1, i1 + 1);
                scanf("%d", &array[i][i1]);
            }
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            for (int i1 = 0; i1 < size; i1++) {
                array[i][i1] = rand() % 100 - 50;
            }
        }
    }
    printf("\n������:\n");
    for (int i = 0; i < size; i++) {
        for (int i1 = 0; i1 < size; i1++) {
            printf("%4d ", array[i][i1]);
        }
        printf("\n");
    }
    int sum = 0;
    int kvadr = 0;
    for (int i = 0; i < size; i++)sum += array[0][i];
    for (int i = 1; i < size; i++) {
        int summastrok = 0;
        for (int i1 = 0; i1 < size; i1++) {
            summastrok += array[i][i1];
        }
        if (summastrok != sum) kvadr = 1;
    }
    for (int i = 0; i < size; i++) {
        int summastolb = 0;
        for (int i1 = 0; i1 < size; i1++) {
            summastolb += array[i1][i];
        }
        if (summastolb != sum) kvadr = 1;
    }
    int diagonsum = 0;
    int diagonsum1 = 0;
    for (int i = 0; i < size; i++) {
        diagonsum += array[i][i];
    }
    if (diagonsum != sum) kvadr = 1;
    for (int i = 0; i < size; i++) {
        diagonsum1 += array[i][size - 1 - i];
    }
    if (diagonsum1 != sum) kvadr = 1;
    if (kvadr == 0) {
        printf("\n��� ���������� �������\n");
    }
    else {
        printf("\n��� �� ���������� �������\n");
    }
}