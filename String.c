/* String.c --- 
 * 
 * Filename: String.c
 * Description: Implemenation of string type
 * Author: George Liontos
 * Maintainer: George Liontos (cprogrammer98@gmail.com)
 * Created: Sat Dec 30 03:20:13 2017 (+0200)
 */

/* This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Emacs.  If not, see <http://www.gnu.org/licenses/>.
 */

/* Code: */

#include <stdio.h>
#include <stdlib.h>
#include "String.h"

#define MALLOC(size, type) ((type*) malloc((size) * sizeof(type)))
#define CALLOC(size, type) ((type*) calloc(size, sizeof(type)))

#define FREE_AND_SET_NULL(pointer) { free(pointer); pointer = NULL; }

struct string {
  char* container;
  size_t size;
  size_t allocatedSize;
};

/* Auxiliary function */
size_t length(const char* string) {
  size_t length = 0U;

  while(*string++ != '\0') {
    ++length;
  }

  return length;
}

/* Auxiliary function */
int copyFromCharPtr(String target, const char* source) {
  size_t targetAllocated = target->allocatedSize;
  size_t sourceSize = length(source);
  target->size = sourceSize;
  
  if (targetAllocated < (sourceSize + 1)) {
    /* I do this because I don't trust realloc completely */
    FREE_AND_SET_NULL(target->container);

    target->container = MALLOC(sourceSize + 1, char);
    target->allocatedSize = sourceSize + 1;
    targetAllocated = sourceSize + 1;
    
    if (target->container == NULL) {
      return 0;
    }
  }

  for (size_t i = 0U; i != sourceSize; ++i) {
    target->container[i] = source[i];
  }

  for (size_t i = sourceSize; i != targetAllocated; ++i) {
    target->container[i] = '\0';
  }

  return 1;
}

String defaultString(void) {
  String newString = CALLOC(1, struct string);

  return newString;
}

String basicString(const char* source) {
  String newString = MALLOC(1, struct string);
  size_t sourceLength = length(source);

  if (newString == NULL) {
    return NULL;
  }

  newString->container = MALLOC(sourceLength + 1, char);
  newString->size = sourceLength;
  newString->allocatedSize = sourceLength + 1;

  if (copyFromCharPtr(newString, source) == 0) {
    return NULL;
  }
  
  return newString;
}

void deleteString(String string) {
  free(string->container);
  free(string);
}

void clear(String string) {
  /* NOTE (George): We don't deallocate the space and we
   * do not set to zero the allocatedSize so we can put a new
   * string in the cleared string later
   */

  for (size_t i = 0U; i != string->size; ++i) {
    string->container[i] = '\0';
  }

  string->size = 0U;
}

size_t size(String string) {
  return string->size;
}

int copy(String target, const String source) {
  size_t targetAllocated = target->allocatedSize;
  size_t sourceSize = source->size;
  target->size = sourceSize;
  
  if (targetAllocated < (sourceSize + 1)) {
    /* I do this because I don't trust realloc completely */
    FREE_AND_SET_NULL(target->container);
  
    target->container = MALLOC(sourceSize + 1, char);
    target->allocatedSize = sourceSize + 1;
    targetAllocated = sourceSize + 1;
    
    if (target->container == NULL) {
      return 0;
    }
  }

  for (size_t i = 0U; i != sourceSize; ++i) {
    target->container[i] = source->container[i];
  }

  for (size_t i = sourceSize; i != targetAllocated; ++i) {
    target->container[i] = '\0';
  }

  return 1;
}

void printString(String string, int endlFlag) {
  printf("%s%s", string->container, (endlFlag) ? "\n" : "");
}

int empty(String string) {
  return (string->size == 0);
}

/* String.c ends here */

