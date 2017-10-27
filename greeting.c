#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* greet(const char *name, const char *owner) {

  if( strcmp(name, owner) == 0 )
  {
    return "Hello boss";
  }
  else
  {
    return "Hello guest";
  }
}

int main(void){
  char nome[10] = "Miguel";
  char dono[10] = "José";
  const char *saudacao = greet(nome,dono);
  printf("%s\n", saudacao);
  return 0;
}

