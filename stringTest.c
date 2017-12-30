#include <stdio.h>
#include <stdlib.h>
#include "String.h"

int main(void) {
  /* Testing String */
  String string = basicString("TESTING OUR STRING");
  String string2 = basicString("SMALL");

  printString(string);
  putchar('\n');

  printString(string2);
  putchar('\n');

  copy(string, string2);

  printString(string);
  putchar('\n');

  String string3 = defaultString();

  copy(string3, string);

  printString(string3);
  putchar('\n');

  clear(string);
  printf("String is %sempty\n", (empty(string)) ? "" : "not ");
  printString(string);
  
  deleteString(string);
  deleteString(string2);
  deleteString(string3);
  
  return EXIT_SUCCESS;
}
