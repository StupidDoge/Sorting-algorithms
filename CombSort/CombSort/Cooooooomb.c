#include <stdio.h>
#include <math.h>

int main() {

    comb1(); // �������� ������� � ������ ��������� ���������� ���������
    printf("%s \n", "------");
    comb2(); // ������ ������� ����������

    return 0;
}

int comb1() { // � ���� ����� ������ �������������� ���������� � �������������� ��������������� ������

    int i, t, step; // ��������� �������, ��������������� ����������, ���
    int array[] = { 7, -2, 0, 383, 6, 56, 15, -94 };
    int n = sizeof(array) / sizeof(int); // ������ ������� 
    float k = 1.247; // ������ ���������� 

    for (step = n - 1; step >= 1; step /= k) // ������� ���� �������� �� ����������� �������� ���� �� �����������, ������� ������� 
        for (i = 0; i < n - step; i++) // ���������� ���� ��� �� ������ ������� � �� �������� ��� ������� n - step
            if (array[i] > array[i + step]) { // ���������� i-��� ������� � ������� c �������� i + step
                t = array[i]; // ��� ���������� ��������������� ����������
                array[i] = array[i + step]; // ���� a[i] > a[i + step], ������ �� ������� 
                array[i + step] = t; // � ��� ���� ���������� ��������������� ����������
            }

    for (i = 0; i < n; i++) { // ������� ��������������� ������
        printf("%d \n", array[i]);
    }
}

int comb2() { // ��������� ������� ���������� � ������� ������ � ������������ 

    int i, t; 
    int array[] = { 7, -2, 0, 383, 6, 56, 15, -94 };
    int n = sizeof(array) / sizeof(int);
    float k = 1.247;
    int step = n - 1;

    while (step >= 1) { // ��� ��� ���������� ���� � ������������ 
        i = 0; // �������� i
        while (i < n - step) { // ������ �� ���������� ����
            if (array[i] > array[i + step]) { // �������� ����������� ���������� ����������� � ������ comb1()
                t = array[i];
                array[i] = array[i + step]; 
                array[i + step] = t;
            }
            i++; // �������������� �������� ����������� ����� 
        }
        step /= k; // ��������� ��� �������� �� k
    }

    for (i = 0; i < n; i++) { // ������ ��� ������� ������, ��������� ��� ��
        printf("%d \n", array[i]);
    }
}