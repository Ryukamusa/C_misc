#include <stdio.h>

long rowSumOddNumbers(int n)
{   long number = 0;
    for(int i=0; i<=n; i++){
        number += i;
    }
    long cnt = 0;
    long val = number*2-1;
    for(int j = val ; j > val-(2*n); j-=2){
        cnt += j;
    }
    return cnt;
}


void main(void){
  int row = 10005;
  long sum = rowSumOddNumbers(row);
  printf("Soma da %d fila é %ld\n", row,sum);
}