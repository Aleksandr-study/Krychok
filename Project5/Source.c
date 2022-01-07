#include <stdio.h>//Додаемо бібліотеку
#include <conio.h>//Додаемо бібліотеку
#include <string.h>//Додаемо бібліотеку
#include <stdlib.h>//Додаемо бібліотеку
#include <locale.h>//Додаемо бібліотеку
void print_array(int arr[20], int size)//Додаемо функцію для виводу масиву
{
	printf("\n");//Додаємо абзац
	for (int i = 0; i < size; i++)//вводимо масив
		printf("%d", arr[i]);//Вивід елементу
	printf("\n");//Додаємо абзац
};
int main()//Тіло функції
{
	setlocale(LC_ALL, "rus");//вводимо кирилицю
	int n, i, j, k, temp, x;//Додаємо змінні
	int count_step;//Додаємо змінну
	int a[10], b[10];//Числовi масиви, довжиною 10 елементiв
	char buffer[2];	// Буфер для вводу користувачем кiлькостi елементiв

	system("cls");//Додаємо колір фону
	printf("Лабораторна робота №2: Сортування масивiв\n");//Назва роботи
	printf("Введiть кiлькiсть елементiв масиву:\n");//Вводимо кількість елементів 
	gets(buffer);// Зчитуемо введену
	n = atoi(buffer);// Переводимо в числове значения

	if (n > 10)// Перевiряемо, якщо кiлькiсть бiльша 10, то присвоюeмо 10
		n = 10;//Присвоюемо 10
	
	for (i = 0; i - n; i++)//цикл
	{
		printf("arr[%d]=", i);//Вводимо довільний порядок чисел 
		gets(buffer);//Зчитуемо введенуу
		a[i] = atoi(buffer);//Переводимо в числове значення
	}
	for (i = 0; i < n; i++)//Довільний порядок
		printf("%d", a[i]);//Виводимо довільний порядок

	//Сортування методом бульбашки:

	memcpy(b, a, n * sizeof(int));//сортування визначеним методом
	count_step = 0;//Ініціалізація змінної
	for (i = 0; i < n; i++)//цикл
		for (j = 0; j < n - i - 1; j++)//цикл
		{
			count_step++;                  // Лiчильник iтерацiй
			if (b[j] > b[j + 1]) // Якщо наступний элемент бiльший за попередний, то мiняемо ix мiсцями
			{
				temp = b[j];//Беремо перший елемент з 2
				b[j] = b[j + 1];//міняемо 1 і 2 
				b[j + 1] = temp;//Виводимо 2 елемент на 1 місце
			}
		}
	printf("Метод бульбашки\n");//Виводимо назву методу
	printf("Kiлькiсть iтерацiй - %d", count_step);//Виводимо кількість ітерацій
	print_array(b, n);//Виводимо правильний масив

	//Сортування масиву методом вставки:

	memcpy(b, a, n * sizeof(int));//сортування визначеним методом
	count_step = 0;//Ініціалізація змінної
	for (i = 0; i < n; i++)// Цикл iтерацiй, i - номер
	{
		x = b[i]; // Пошук элемента в готовiй послiдовностi
		for (j = i - 1; j >= 0 && b[j] > x; j--) //Цикл ітерацій для j
		{
			b[j + 1] = b[j];                            // Рухаемо элемент праворуч, поки не дiйшли
			count_step++;//Ініціалізація змінної
		}                   
		b[j + 1] = x; // знайдено, вставити элемент
	}
	printf("\nМетод вставки\n");//Виводимо назву методу
	printf("Kiлькiсть iтерацiй - %d", count_step);//Виводимо кількість ітерацій
	print_array(b, n);//Виводимо правильний масив

	//Сортування масиву методом вибором:
	
	memcpy(b, a, n * sizeof(int));//сортування визначеним методом
	count_step = 0;//Ініціалізація змінної
	for (i = 0; i < n; i++) //цикл // i- номер поточного кроку
	{  
		k = i; x = b[i];//Номер поточного кроку
		for (j = i + 1; j < n; j++) // цикл вибору найменшого элемента
		{            
			count_step++;//Ініціалізація змінної
			if (b[j] < x)//Якщо b[j] менше х, то присвоюємо k j, a x b[j]
			{
				k = j; x = b[j];
			}
		}
		b[k] = b[i]; b[i] = x;//Міняємо місцями найменший з a[i]
	}
	printf("\nМетод вибором\n");//Виводимо назву методу
	printf("Кiлькiсть iтерацiй- %d\n", count_step);//Виводимо кількість ітерацій
	print_array(b, n);//Виводимо правильний масив
	system("pause");//зупинка консолі 
	return 0;//вихід з консолі
}