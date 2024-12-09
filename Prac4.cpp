#include <stdio.h>
#include <stdlib.h>

void printMat(int** mat, int size_x, int size_y) {
  for (int i = 0; i < size_y; i++) {
    for (int j = 0; j < size_x; j++) {
      printf("%i ", mat[i][j]);
    }
    printf("\n");
  }
}

void printArr(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%i ", arr[i]);
  }
  printf("\n");
}



int** transpos(int** mat, int size_x, int size_y){
  int** new_mat = (int**)malloc(size_x * sizeof(int*)); 
  for (int y = 0; y <= size_x; y++) {
    new_mat[y] = (int*)malloc(size_y * sizeof(int));
  }
  for (int y = 0; y < size_y; y++) {
    for (int x = 0; x < size_x; x++) {
      new_mat[x][y] = mat[y][x];
    }
  }
  return new_mat;
}

void first() {
  int size_x = 3;
  int size_y = 3;
  int** mat =  (int**)malloc(size_y * sizeof(int*));
  for (int y = 0; y <= size_y; y++) {
    mat[y] = (int*)malloc(size_x * sizeof(int));
    for (int x = 0; x <= size_x; x++) {
      mat[y][x] = 1 + x + size_x * y;
    }
  }
  
  printMat(transpos(mat, size_x, size_y), size_y, size_x);
}

int isalphanum(char c){
  if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')){
    return 1;
  }
  return 0;
}

void second(){
  const int size = 100;
  char str[size + 1];
  gets_s(str, size);
  int counter = 0;
  for (int i = 0; !isalphanum(str[i]) && str[i] != '\0'; i++) {
    counter++;
  }
  for (int i = counter; isalphanum(str[i]) && str[i] != '\0'; i++) {
    counter++;
  }
  for (int i = counter;!isalphanum(str[i]) && str[i] != '\0'; i++) {
    counter++;
  }
  int end = 0;
  for (int i = counter; str[i] != '\0'; i++) {
    str[i - counter] = str[i];
    end++;
  }
  str[end] = '\0';
  puts(str);
}

void insert_str(char* word, char* str){
  int len_word = 0, len_str = 0;
  for (;word[len_word] != '\0'; len_word++);
  for (;str[len_str] != '\0'; len_str++);
  for (int i = len_str + len_word; i >= len_word; i--){
    str[i + 1] = str[i - len_word];
  }
  for (int i = 0; i < len_word; i++) {
    str[i] = word[i];
  }
  str[len_word] = ' ';
}

int word_in_str(char* word, char* str) {
  int i = 0;
  while (str[i] != '\0') {
    if (str[i] == word[0]) {
      int j = 0;
      while (str[i] == word[j]) {
        j++;
        i++;
      }
      if (word[j] == '\0') {
        return 1;
      }
    }
    i++;
  }
  return 0;
}

void third() {
  const int size = 100;
  char str[size * 2 + 1];
  char words[size + 1];
  gets_s(str, size * 2);
  gets_s(words, size);
  int i = 0;
  for (;!isalphanum(words[i]);i++);
  while (words[i] != '\0') {
    char temp[size + 1];
    int j = 0;
    while (isalphanum(words[i])) {
      temp[j++] = words[i++];
    }
    temp[j] = '\0';
    if (!word_in_str(temp, str)) {
      insert_str(temp, str);
    }
    for (;!isalphanum(words[i]) && words[i] != '\0'; i++);
  }
  puts(str);
}


void fourth() {
  const int size = 10;
  int temp;
  int arr[size] = {5, 2, 3, 6, 1, 0, 4, 9, 7, 8};
  for (int i=1; i < size; i++) {
    temp = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > temp){
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
  printArr(arr, size);
}


int main() {
  //first();
  //second();
  third();
  //fourth();
}
