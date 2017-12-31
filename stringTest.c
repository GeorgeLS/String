#include <stdio.h>
#include <stdlib.h>
#include "String.h"

int main(void) {
  /* Testing String */
  String string = basicString("TESTING OUR STRING");
  String string2 = basicString("SMALL");

  printStringEndl(string);

  printStringEndl(string2);

  concatenateString(string, string2);

  printStringEndl(string);
  
  copy(string, string2);

  printStringEndl(string);

  String string3 = defaultString();

  copy(string3, string);

  printStringEndl(string3);

  clear(string);

  printf("String is %sempty\n", (empty(string)) ? "" : "not ");
  printString(string);
  
  deleteString(string);
  deleteString(string2);
  deleteString(string3);
  
  return EXIT_SUCCESS;
}
