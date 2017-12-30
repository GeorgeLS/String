/* String.h --- 
 * 
 * Filename: String.h
 * Description: Header of string type
 * Author: George Liontos
 * Maintainer: George Liontos (cprogrammer98@gmail.com)
 * Created: Sat Dec 30 02:17:32 2017 (+0200)
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

#if !defined(__STRING_HEADER__)
#define __STRING_HEADER__

#include <stdio.h>
#include <stdlib.h>

typedef struct string* String;

/* Creates an empty string */
String defaultString(void);

/* Creates a string from an existing one */
String basicString(const char* source);

/* Deletes the string */
void deleteString(String string);

/* Returns the size of the string */
size_t size(const String string);

/* Clears the string */
void clear(String string);

/* Copies the source to the target and returns 1 if the copy succeded, 0 otherwise */
int copy(String target, const String source); 

/* Prints the string. If endlFlag is not 0 then newline is printed */
void printString(String string, int endlFlag);

/* Returns 1 if the string is empty, 0 otherwise */
int empty(String string);

#endif

/* String.h ends here */
