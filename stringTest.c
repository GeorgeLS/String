#include <stdio.h>
#include <stdlib.h>
#include "String.h"

int main(void) {
  /* Testing String */
  String string = basicString("TESTING OUR STRING");
  String string2 = basicString("SMALL");

  printString(string, 1);

  printString(string2, 1);

  copy(string, string2);

  printString(string, 1);

  String string3 = defaultString();

  copy(string3, string);

  printString(string3, 1);

  clear(string);

  printf("String is %sempty\n", (empty(string)) ? "" : "not ");
  printString(string, 0);
  
  deleteString(string);
  deleteString(string2);
  deleteString(string3);
  
  return EXIT_SUCCESS;
}
