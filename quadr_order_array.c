#include <stdio.h>
#include <stdbool.h>
#include "misc_code.h"
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a > *(int *)b) - (*(int *)a < *(int *)b);
}

void sort(int *arr, size_t len) {
    qsort(arr, len, sizeof(int), compare);
}

bool comp(int* a, int* b, size_t sizeArray){
  bool res = true;
  sort(a,sizeArray);
  sort(b,sizeArray);
  for (int i = 0; i < sizeArray; i++) {
    double val1 = a[i]*a[i];
    double val2 = b[i];
    if (val2 != val1){
      res = false;
      break;
    }
  }
  return res;
}
void test(int *d1, int *d2, int k, bool expect,int n){
  bool real = comp(d1, d2, k);
  if(real != expect){
    printf("Error. Expected %d but got %d\n", expect, real);
  } else {
    printf("Everythin ok with test nº: %d\n",n);
  }
}

int main(void) {
  int a[8] = {121, 144, 19, 161, 19, 144, 19, 11};
  int b[8] = {14641, 20736, 361, 25921, 361, 20736, 361, 121};
  test(a, b, 8, true,1);


  int a2[8] = {121, 144, 19, 161, 19, 144, 19, 11};
  int b2[8] = {14641, 20736, 361, 25921, 361, 20736, 362, 121};
  test(a2, b2, 8, false,2);


  int a3[9] = {121, 144, 19, 161, 19, 144, 19, 11, 1008};
  int b3[9] = {14641, 20736, 361, 25921, 361, 20736, 362, 121, 12340};
  test(a3, b3, 9, false,3);

  return 0;
}


