#include <stdio.h>
#include <stdlib.h>


char *series_sum(const size_t n){
  char *palavra;
  palavra = malloc(sizeof(char)*100);
  float sum = 0;
  for(float i = 1; i <= n; i++){
    sum += 1/i;
  }
  sprintf(palavra,"%.2f",sum);
  return palavra;

}

void main(void){
  int n = 10;
  char *valor = series_sum(n);
  printf("%s\n", valor);
  free(valor);
  // printf("Soma até %d é %s\n", n,valor);
}