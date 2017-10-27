#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14159265358979323846

int integersNumber(int the_integer){
  if(the_integer == 0){
    return 0;
  } else{
   return floor(log10(abs(the_integer)))+1;
  }
}

char *iterPi(double epsilon) {
  double pi = 1;
  double cnt = 3;
  int i = 1;
  double val = 0;
  int dif = 1;
  do {
    val = 1/cnt;
    if(i%2 != 0){
      pi -= val;
    } else {
      pi += val;
    }
    cnt += 2;
    dif = fabs(M_PI-(pi*4))>epsilon;
    i++;
  } while(dif);
  int number = integersNumber(i);
  char *ret = malloc(sizeof(char)*50);
  sprintf(ret,"[%d %.10f]",i,pi*4);
  return ret;
}

int main() {
  char *ret = iterPi(0.01);
  printf("%s\n", ret);
  free(ret);
  return 0;
}