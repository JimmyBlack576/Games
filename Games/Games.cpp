#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

const int SIZE = 8;//Размер сетки
int arrx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int arry[8] = { 2,1,-1,-2,-2,-1,1,2 };
//Функция отображения доски
void print_arr(int arr[][SIZE]);
//Рекурсивная функция хода коня
void Knight(int arr[][SIZE], int num, int i0, int j0);



int main()
{
	int x, y;
	cout << "Specify the cell in which the horse should be (1-8): \n";
	cout << "X: ";
	cin >> x;
	cout << "Y: ";
	cin >> y;
	int deck[SIZE][SIZE] = {};
	Knight(deck, 1, y-1 ,x-1);
}

void print_arr(int arr[][SIZE]) {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			cout << setw(3) << arr[i][j];
		}
		cout << endl;
	}
}

void Knight(int arr[][SIZE], int num, int i0, int j0) {
	arr[i0][j0] = num++;
	//print_arr(arr);
	//system("pause");    // для просмотра хода пошагово, раскомментировать 
	for (int i = 0; i < 8; i++) {
		int inew = i0 + arry[i];
		int jnew = j0 + arrx[i];

		if (num > SIZE * SIZE) {
			print_arr(arr);
			exit(0);
		}
		if (inew<0 || inew>SIZE - 1 || jnew<0 || jnew>SIZE - 1 || arr[inew][jnew] != 0)
			continue;
		Knight(arr, num, inew, jnew);
		arr[inew][jnew] = 0;
	}
}