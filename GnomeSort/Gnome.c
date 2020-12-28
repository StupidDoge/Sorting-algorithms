#include <stdio.h>
#include <stdlib.h>

int n; // ����������� �������
int* arr = NULL; // c�� ������
int i = 1, j = 2, buf; // �������� � �����

void gnome1() { // ���������� � ������� ����� � ������������ 

	while (i < n) { // ��� �� ����� ������� 
		if (arr[i - 1] > arr[i]) { // ���� ����� ������ ������� 
			buf = arr[i]; 
			arr[i] = arr[i - 1]; // ������ �� ������� 
			arr[i - 1] = buf;
			i--; // � ������ ��� ����� 
			if (i > 0) continue; // ���� ��� ������ ������� � �����, �� ��������� � ������ ����� 
		}
		i = j++; // ����� ����������� ��� ��������� �������, � ����� �������������� j 
	}
}

void gnome2() { // ���������� � ������� ���������������� �����

	for (i = 1; i < n; i++) { // ������� ����, ��� �� ���������
		if (arr[i - 1] > arr[i]) { // ���� ���������� ������� ������ ��������
			buf = arr[i];
			arr[i] = arr[i - 1]; // ������ �� ������� 
			arr[i - 1] = buf;
			if (i != 1) // � �����, ���� i �� ����� 1,
				i -= 2; // ������ 2 ���� �����. ��� ����� �����������, ���� ������� �� ������� �� ��� �����
		}
	}
}

void main() {

	/* ������ ������ � ���������� */
	printf("Array size: ");
	scanf_s("%u", &n);

	arr = (size_t)calloc(n, sizeof(int));

	printf("Array: \n");
	for (int j = 0; j < n; j++)
		scanf_s("%d", &(arr[j]));

	/* �������� ����� ������� ���������� */
	printf("Choose sorting with parametric cycle or precondition loop. \n 1 - precondition loop; \n 2 - parametric cycle \n");
	int choice;
	scanf_s("%d", &choice);

	if (choice == 1)
		gnome1();
	else if (choice == 2)
		gnome2();
	else
		printf("You should press only button 1 or 2. Please, try again.");

	/* ������� ��������������� ������, ���� ������������ ������ ���� �� ���� ���������*/
	if (choice == 1 || choice == 2) {
		printf("Result: ");
		for (int j = 0; j < n; j++)
			printf("%d ", arr[j]);

		printf("\n");
	}
}