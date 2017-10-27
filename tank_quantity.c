#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M_PI 3.14159265358979323846

double calcArea(double r, double rest){
  double c = 2*r*sqrt(1-pow(rest/(r),2));
  double theta = 2*asin(c/(2*r));
  double newA = pow(r,2)*(theta - sin(theta))/2;
  return newA;
}

int tankVol(int h, int d, int vt) {
  double newA;
  double r = d/(double)2;
  double l = vt/(M_PI*pow(r,2));
  double rest = r-h;
  int result;
  if (rest == 0){
    newA = M_PI*pow(r,2)*1/2;
    result = newA*l;
  } else if(rest < 0){
    rest = h -r ;
    double new = calcArea(r, rest);
    result = vt - new*l;
  } else{
    newA = calcArea(r, rest);
    result = newA*l;
  }
  return result;
}

void dotest(int h, int d, int vt, int expected){
  int result = tankVol(h,d,vt);
  printf("Expected: %d\nResult: %d\n",expected,result);
}
int main() {
  dotest(5, 7, 3848, 2940);
  dotest(2, 7, 3848, 907);
  dotest(3, 6, 3500, 1750);
  dotest(3, 6, 3501, 1750);
  return 0;
}

