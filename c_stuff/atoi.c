/**
 * C implementation of atoi.
 * Compile with -lm to include the math package.
 */

// Declare a boolean type (overkill, just practice).
typedef int bool;
#define true 1
#define false 0

#include<math.h>
#include<stdio.h>
#include<string.h>


int atoi(char *string) {
  int result = 0;
  bool positive = true;
  
  // Skip any leading whitespace.
  while (isspace(*string)) {
    ++string;
  }

  // Determine if it is positive or negative. In C, single quotes indicate a
  // character literal and double quotes are a string literal.
  if (*string == '-') {
    positive = false;
    ++string;
  }

  // Based on the length of the string, determine the proper power of 10 by
  // which to multiply the character value. To coerce the character into a
  // string, subtract '0'.
  int len = strlen(string) - 1;
  while (*string) {
    int num = *string - '0';
    result += pow(10, len) * num;
    ++string;
    --len;
  }

  return positive ? result : result * -1;
}


int main(int argc, char *argv[]) {
  char* input = "  -12345";
  int val = atoi(input);
  printf("String: %s\nInteger: %d\n", input, val);
  return 0;
}
