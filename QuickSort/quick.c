#include <stdio.h>
#include <stdlib.h>

int b, e, l, r, t, arr[] = { -6, 1, 0, 5, 7, 8, 4, 9, -17, 12 }; // переменные и массив
int n = sizeof(arr) / sizeof(int); // размерность массива

void qsort1(int* arr, int b, int e) // сортировка с помощью циклов с предусловием 
{
    if (b < e) // условие окончания сортировки - b >= e
    {
        int piv = arr[(b + e) / 2]; // находим опорный элемент
        int l = b; // левый индекс
        int r = e; // правый индекс
        while (l <= r) // идём по массиву
        {
            while (arr[l] < piv) l++; // пока слева меньше, идём на шаг вперёд
            while (arr[r] > piv) r--; // пока справа больше, идём на шаг вперёд
            if (l <= r) // если левый индекс меньше либо равен правому
            {
                int t = arr[l]; // меняем 
                arr[l] = arr[r]; // элементы с номерами l и r
                arr[r] = t; // местами 
                l++; // левый идёт вправо на шаг
                r--; // правый идёт влево на шаг
            }
        }
        qsort1(arr, b, r); // рекурсия с b и r 
        qsort1(arr, l, e); // рекурсия с l и e
    }
}

void qsort2(int* arr, int b, int e) // сортировка с помощью параметрических циклов 
{
    if (b < e) // тот же самый алгоритм, только с циклами for
    {
        int piv = arr[(b + e) / 2];
        int r = e;
        for (l = b; l <= r; l++) // идём от b до r по массиву
        {
            for (int i = l; i < n; i++)  // идём от l до конца массива 
                if (arr[l] < piv) // если левый элемент меньше опорного
                    l++; // шаг вперёд
                else
                    break; // иначе выходим из цикла

            for (int i = r; i > 0; i--) // идём от r к началу массива 
                if (arr[r] > piv) // если правый больше опорного 
                    r--; // шаг вперёд
                else
                    break; // иначе выходим из цикла

            if (l <= r) // тут так же меняем элементы местами, если левый >= правому
            {
                int t = arr[l];
                arr[l] = arr[r];
                arr[r] = t;
                r--;
            }
        }
        qsort2(arr, b, r); // рекурсия с b и r 
        qsort2(arr, l, e); // рекурсия с l и e
    }
}

int main()
{
    /* выбор варианта быстрой сортировки */
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
    for (int i = 0; i < n - 1; i++) // красивый вывод массива 
        printf("%d, ", arr[i]);
    printf("%d", arr[n - 1]);
    printf("]");
}

