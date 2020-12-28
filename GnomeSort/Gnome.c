#include <stdio.h>
#include <stdlib.h>

int n; // размерность массива
int* arr = NULL; // cам массив
int i = 1, j = 2, buf; // счётчики и буфер

void gnome1() { // сортировка с помощью цикла с предусловием 

	while (i < n) { // идём до конца массива 
		if (arr[i - 1] > arr[i]) { // если левый больше правого 
			buf = arr[i]; 
			arr[i] = arr[i - 1]; // меняем их местами 
			arr[i - 1] = buf;
			i--; // и делаем шаг назад 
			if (i > 0) continue; // если это первый элемент с конца, то переходим к началу цикла 
		}
		i = j++; // иначе присваиваем ему следующий элемент, а потом инкрементируем j 
	}
}

void gnome2() { // сортировка с помощью параметрического цикла

	for (i = 1; i < n; i++) { // внешний цикл, идём по элементам
		if (arr[i - 1] > arr[i]) { // если предыдущий элемент больше текущего
			buf = arr[i];
			arr[i] = arr[i - 1]; // меняем их местами 
			arr[i - 1] = buf;
			if (i != 1) // а потом, если i не равен 1,
				i -= 2; // делаем 2 шага назад. Так будет происходить, пока элемент не встанет на своё место
		}
	}
}

void main() {

	/* вводим массив с клавиатуры */
	printf("Array size: ");
	scanf_s("%u", &n);

	arr = (size_t)calloc(n, sizeof(int));

	printf("Array: \n");
	for (int j = 0; j < n; j++)
		scanf_s("%d", &(arr[j]));

	/* выбираем метод гномьей сортировки */
	printf("Choose sorting with parametric cycle or precondition loop. \n 1 - precondition loop; \n 2 - parametric cycle \n");
	int choice;
	scanf_s("%d", &choice);

	if (choice == 1)
		gnome1();
	else if (choice == 2)
		gnome2();
	else
		printf("You should press only button 1 or 2. Please, try again.");

	/* выводим отсортированный массив, если пользователь выбрал один из двух вариантов*/
	if (choice == 1 || choice == 2) {
		printf("Result: ");
		for (int j = 0; j < n; j++)
			printf("%d ", arr[j]);

		printf("\n");
	}
}