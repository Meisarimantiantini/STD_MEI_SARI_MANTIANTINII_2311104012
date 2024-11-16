#include <stdio.h>

// Fungsi untuk menampilkan isi array 2D
void tampilArray(int arr[][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

// Fungsi untuk menukarkan isi dua array 2D pada posisi tertentu
void tukarArray(int arr1[][3], int arr2[][3], int row, int col) {
  int temp = arr1[row][col];
  arr1[row][col] = arr2[row][col];
  arr2[row][col] = temp;
}

// Fungsi untuk menukarkan isi dua variabel yang ditunjuk oleh pointer
void tukarVariabel(int *ptr1, int *ptr2) {
  int temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;
}

int main() {
  // Deklarasi dua buah array 2D
  int arr1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int arr2[3][3] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};

  // Deklarasi dua buah pointer integer
  int *ptr1, *ptr2;

  // Menampilkan isi array 2D
  printf("Isi array 1:\n");
  tampilArray(arr1);
  printf("Isi array 2:\n");
  tampilArray(arr2);

  // Menukarkan isi dua array 2D pada posisi [1][1]
  printf("\nMenukarkan isi array 1 dan array 2 pada posisi [1][1]\n");
  tukarArray(arr1, arr2, 1, 1);

  // Menampilkan isi array 2D setelah ditukar
  printf("Isi array 1 setelah ditukar:\n");
  tampilArray(arr1);
}
  