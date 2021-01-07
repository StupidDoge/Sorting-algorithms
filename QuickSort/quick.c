#include <stdio.h>
#include <stdlib.h>

int b, e, l, r, t, arr[] = { -6, 1, 0, 5, 7, 8, 4, 9, -17, 12 }; // ���������� � ������
int n = sizeof(arr) / sizeof(int); // ����������� �������

void qsort1(int* arr, int b, int e) // ���������� � ������� ������ � ������������ 
{
    if (b < e) // ������� ��������� ���������� - b >= e
    {
        int piv = arr[(b + e) / 2]; // ������� ������� �������
        int l = b; // ����� ������
        int r = e; // ������ ������
        while (l <= r) // ��� �� �������
        {
            while (arr[l] < piv) l++; // ���� ����� ������, ��� �� ��� �����
            while (arr[r] > piv) r--; // ���� ������ ������, ��� �� ��� �����
            if (l <= r) // ���� ����� ������ ������ ���� ����� �������
            {
                int t = arr[l]; // ������ 
                arr[l] = arr[r]; // �������� � �������� l � r
                arr[r] = t; // ������� 
                l++; // ����� ��� ������ �� ���
                r--; // ������ ��� ����� �� ���
            }
        }
        qsort1(arr, b, r); // �������� � b � r 
        qsort1(arr, l, e); // �������� � l � e
    }
}

void qsort2(int* arr, int b, int e) // ���������� � ������� ��������������� ������ 
{
    if (b < e) // ��� �� ����� ��������, ������ � ������� for
    {
        int piv = arr[(b + e) / 2];
        int r = e;
        for (l = b; l <= r; l++) // ��� �� b �� r �� �������
        {
            for (int i = l; i < n; i++)  // ��� �� l �� ����� ������� 
                if (arr[l] < piv) // ���� ����� ������� ������ ��������
                    l++; // ��� �����
                else
                    break; // ����� ������� �� �����

            for (int i = r; i > 0; i--) // ��� �� r � ������ ������� 
                if (arr[r] > piv) // ���� ������ ������ �������� 
                    r--; // ��� �����
                else
                    break; // ����� ������� �� �����

            if (l <= r) // ��� ��� �� ������ �������� �������, ���� ����� >= �������
            {
                int t = arr[l];
                arr[l] = arr[r];
                arr[r] = t;
                r--;
            }
        }
        qsort2(arr, b, r); // �������� � b � r 
        qsort2(arr, l, e); // �������� � l � e
    }
}

int main()
{
    /* ����� �������� ������� ���������� */
    printf("Choose sorting with parametric cycle or precondition loop. \n 1 - precondition loop; \n 2 - parametric cycle \n");
    int choice;
    scanf_s("%d", &choice);

    switch (choice)
    {
        case 1:
            qsort1(arr, 0, n - 1);
            break;

        case 2:
            qsort2(arr, 0, n - 1);
            break;

        default:
            printf("You should press only button 1 or 2. Please, try again.");
            break;
    }

    printf("[");
    for (int i = 0; i < n - 1; i++) // �������� ����� ������� 
        printf("%d, ", arr[i]);
    printf("%d", arr[n - 1]);
    printf("]");
}

