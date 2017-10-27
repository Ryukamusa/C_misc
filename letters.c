#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>

char *accum(const char *source){
  int s = strlen(source);
  int sz = 0;
  for(int i = 0; i<=s; i++){
    sz += i;
  }
  sz += s;
  char* world;
  world = malloc(sizeof(char*)*sz);
  int cnt = 0;
  for (int i = 0; i < s; i++) {
    for(int j = 0; j <= i+1; j++){
      if(j == 0){
        world[cnt] = toupper(source[i]);
      } else if((j == i+1)&&(i<s-1)){
        world[cnt] = '-';
      } else if((j == i+1)&&(i==s-1)){
        break;
      } else{
        world[cnt] = tolower(source[i]);
      }
      cnt++;
    }
  }
  world[cnt] = '\0';
  return world;
}

void testeValues(const char *value,const char *expected){
  char *actual =accum(value);
  printf("Source: %s\nExpected: %s\nActual  : %s\n", value, expected, actual);
  free(actual);
}

void main(void){
  const char *source = "mHixDSsnDLP";
  const char *expected = "M-Hh-Iii-Xxxx-Ddddd-Ssssss-Sssssss-Nnnnnnnn-Ddddddddd-Llllllllll-Ppppppppppp";
  testeValues(source,expected);
  const char *source2 = "AbCdi";
  const char *expected2 = "A-Bb-Ccc-Dddd-Iiiii";
  testeValues(source2,expected2);
}